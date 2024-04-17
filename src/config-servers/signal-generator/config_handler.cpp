/******************************************************************************
 * $HeadURL: $
 * $Id: $
 *
 * Project       : Sequencer training
 *
 * Description   : Training materials for the Sequencer.
 *
 * Author        : Walter Van Herck (IO)
 *
 * Copyright (c) : 2010-2024 ITER Organization,
 *                 CS 90 046
 *                 13067 St. Paul-lez-Durance Cedex
 *                 France
 *
 * This file is part of ITER CODAC software.
 * For the terms and conditions of redistribution or use of this software
 * refer to the file ITER-LICENSE.TXT located in the top level directory
 * of the distribution package.
 ******************************************************************************/

#include "config_handler.h"

#include <sup/dto/anyvalue_helper.h>

#include <algorithm>
#include <exception>

const std::string kOutput_1 = "out1";
const std::string kOutput_2 = "out2";

const sup::dto::AnyType signal_config_t = {{
  { "shape", sup::dto::StringType },
  { "freq", sup::dto::Float64Type },
  { "phase", sup::dto::Float64Type }
}, "Signal_t"};

const sup::dto::AnyType generator_config_t = {{
  { kOutput_1, signal_config_t },
  { kOutput_2, signal_config_t },
  { "active", sup::dto::BooleanType }
}, "SignalGenerator_t" };

namespace
{
bool IsKnownDatasetName(const std::string& dataset_name);
sup::dto::AnyValue& GetDataset(sup::dto::AnyValue& config, const std::string& name);
const sup::dto::AnyValue& GetDataset(const sup::dto::AnyValue& config, const std::string& name);
bool IsValidConfiguration(const sup::dto::AnyValue& config);
bool IsValidSignalConfig(const sup::dto::AnyValue& signal_config, bool active);
}  // unnamed namespace

namespace sequencer
{
namespace training
{
using sup::protocol::Success;

SignalGeneratorConfigHandler::SignalGeneratorConfigHandler()
  : m_config{generator_config_t}
{}

SignalGeneratorConfigHandler::~SignalGeneratorConfigHandler() = default;

ProtocolResult SignalGeneratorConfigHandler::IsDynamicDataset(
  const std::string& name, bool& dynamic) const
{
  if (!IsKnownDatasetName(name))
  {
    return sup::config::DatasetUnknown;
  }
  dynamic = false;
  return Success;
}

ProtocolResult SignalGeneratorConfigHandler::ConfigurationStructure(
  const std::string& name, sup::dto::AnyType& anytype) const
{
  if (!IsKnownDatasetName(name))
  {
    return sup::config::DatasetUnknown;
  }
  anytype = GetDataset(m_config, name).GetType();
  return Success;
}

ProtocolResult SignalGeneratorConfigHandler::GetDatasets(
  std::vector<std::string>& dataset_names) const
{
  static const std::vector<std::string> supported_names = { "", kOutput_1, kOutput_2 };
  dataset_names = supported_names;
  return Success;
}

ProtocolResult SignalGeneratorConfigHandler::ReadConfiguration(
  const std::string& name, sup::dto::AnyValue& value) const
{
  if (!IsKnownDatasetName(name))
  {
    return sup::config::DatasetUnknown;
  }
  if (!sup::dto::TryAssignIfEmptyOrConvert(value, GetDataset(m_config, name)))
  {
    return sup::config::ConfigurationMismatch;
  }
  return Success;
}

ProtocolResult SignalGeneratorConfigHandler::WriteConfiguration(
  const std::string& name, const sup::dto::AnyValue& value)
{
  if (!IsKnownDatasetName(name))
  {
    return sup::config::DatasetUnknown;
  }
  sup::dto::AnyValue config_cache = m_config;
  if (!sup::dto::TryConvert(GetDataset(config_cache, name), value))
  {
    return sup::config::ConfigurationMismatch;
  }
  if (!IsValidConfiguration(config_cache))
  {
    return sup::config::ReadWriteError;
  }
  m_config = config_cache;
  return Success;
}

}  // namespace training

}  // namespace sequencer

namespace
{
bool IsKnownDatasetName(const std::string& dataset_name)
{
  if (dataset_name.empty())
  {
    return true;
  }
  if (dataset_name == kOutput_1 || dataset_name == kOutput_2)
  {
    return true;
  }
  return false;
}

sup::dto::AnyValue& GetDataset(sup::dto::AnyValue& config, const std::string& name)
{
  return const_cast<sup::dto::AnyValue&>(
    GetDataset(static_cast<const sup::dto::AnyValue&>(config), name));
}

const sup::dto::AnyValue& GetDataset(const sup::dto::AnyValue& config, const std::string& name)
{
  if (name.empty())
  {
    return config;
  }
  if (name == kOutput_1 || name == kOutput_2)
  {
    return config[name];
  }
  const std::string error =
    "SignalGeneratorConfigHandler::Dataset: trying to get reference to unknown dataset";
  throw std::runtime_error(error);
}

bool IsValidConfiguration(const sup::dto::AnyValue& config)
{
  auto active = config["active"].As<sup::dto::boolean>();
  return IsValidSignalConfig(config[kOutput_1], active)
      && IsValidSignalConfig(config[kOutput_2], active);
}

bool IsValidSignalConfig(const sup::dto::AnyValue& signal_config, bool active)
{
  // The default initialized configuration is allowed when not active
  const sup::dto::AnyValue zero_config{signal_config_t};
  if (signal_config == zero_config && !active)
  {
    return true;
  }
  // Only specific shapes are allowed
  const std::vector<std::string> allowed_shapes = {"sine", "triangle", "sawtooth", "square"};
  auto shape = signal_config["shape"].As<std::string>();
  if (std::find(allowed_shapes.begin(), allowed_shapes.end(), shape) == allowed_shapes.end())
  {
    return false;
  }
  // Frequency should be between 10 Hz to 20kHz
  auto frequency = signal_config["freq"].As<sup::dto::float64>();
  if (frequency < 10.0 || frequency > 1e4)
  {
    return false;
  }
  return true;
}

}  // unnamed namespace

