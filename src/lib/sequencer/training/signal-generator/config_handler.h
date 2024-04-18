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

#ifndef SEQUENCER_TRAINING_SIGNAL_GENERATOR_CONFIG_HANDLER_H_
#define SEQUENCER_TRAINING_SIGNAL_GENERATOR_CONFIG_HANDLER_H_

#include <sup/config/configuration_interface.h>

namespace sequencer
{
namespace training
{
using sup::protocol::ProtocolResult;

/**
 * @brief Configuration handler for the signal generator.
 */
class SignalGeneratorConfigHandler : public sup::config::ConfigurationInterface
{
public:
  SignalGeneratorConfigHandler();

  ~SignalGeneratorConfigHandler();

  ProtocolResult IsDynamicDataset(const std::string& name, bool& dynamic) const override;

  ProtocolResult ConfigurationStructure(
    const std::string& name, sup::dto::AnyType& anytype) const override;

  ProtocolResult GetDatasets(std::vector<std::string>& dataset_names) const override;

  ProtocolResult ReadConfiguration(const std::string& name,
                                   sup::dto::AnyValue& value) const override;

  ProtocolResult WriteConfiguration(const std::string& name,
                                    const sup::dto::AnyValue& value) override;
private:
  sup::dto::AnyValue m_config;
};

}  // namespace training

}  // namespace sequencer

#endif  // SEQUENCER_TRAINING_SIGNAL_GENERATOR_CONFIG_HANDLER_H_
