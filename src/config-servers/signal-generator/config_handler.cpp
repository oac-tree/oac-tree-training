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
  { "enabled", sup::dto::BooleanType }
}, "SignalGenerator_t" };

namespace
{
bool IsKnownDatasetName(const std::string& dataset_name);
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
  anytype = Dataset(name).GetType();
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
  if (!sup::dto::TryAssignIfEmptyOrConvert(value, Dataset(name)))
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
  if (!sup::dto::TryConvert(Dataset(name), value))
  {
    return sup::config::ConfigurationMismatch;
  }
  return Success;
}

sup::dto::AnyValue& SignalGeneratorConfigHandler::Dataset(const std::string& name)
{
  return const_cast<sup::dto::AnyValue&>(
    static_cast<const SignalGeneratorConfigHandler&>(*this).Dataset(name));
}

const sup::dto::AnyValue& SignalGeneratorConfigHandler::Dataset(const std::string& name) const
{
  if (name.empty())
  {
    return m_config;
  }
  if (name == kOutput_1 || name == kOutput_2)
  {
    return m_config[name];
  }
  const std::string error =
    "SignalGeneratorConfigHandler::Dataset: trying to get reference to unknown dataset";
  throw std::runtime_error(error);
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
}  // unnamed namespace

