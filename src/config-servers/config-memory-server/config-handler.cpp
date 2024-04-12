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

#include "config-handler.h"

namespace sequencer
{
namespace training
{
using sup::protocol::Success;

SignalGeneratorConfigHandler::SignalGeneratorConfigHandler() = default;

SignalGeneratorConfigHandler::~SignalGeneratorConfigHandler() = default;

ProtocolResult SignalGeneratorConfigHandler::IsDynamicDataset(
  const std::string& name, bool& dynamic) const
{
  return Success;
}

ProtocolResult SignalGeneratorConfigHandler::ConfigurationStructure(
  const std::string& name, sup::dto::AnyType& anytype) const
{
  return Success;
}

ProtocolResult SignalGeneratorConfigHandler::GetDatasets(
  std::vector<std::string>& dataset_names) const
{
  return Success;
}

ProtocolResult SignalGeneratorConfigHandler::ReadConfiguration(
  const std::string& name, sup::dto::AnyValue& value) const
{
  return Success;
}

ProtocolResult SignalGeneratorConfigHandler::WriteConfiguration(
  const std::string& name, const sup::dto::AnyValue& value)
{
  return Success;
}

}  // namespace training

}  // namespace sequencer
