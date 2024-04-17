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

#ifndef SEQUENCER_TRAINING_CONFIG_SERVERS_UTILS_H_
#define SEQUENCER_TRAINING_CONFIG_SERVERS_UTILS_H_

#include "i_server_stack.h"

#include <sup/config/configuration_interface.h>
#include <sup/config/configuration_protocol_server.h>
#include <sup/protocol/protocol_rpc_server.h>
#include <sup/epics/pv_access_rpc_server.h>

#include <memory>
#include <string>

namespace sequencer
{
namespace training
{
class EPICSConfigServerStack : public IServerStack
{
public:
  explicit EPICSConfigServerStack(const std::string& service_name,
                                  std::unique_ptr<sup::config::ConfigurationInterface> config_handler);

  virtual ~EPICSConfigServerStack();
private:
  std::unique_ptr<sup::config::ConfigurationInterface> m_config_handler;
  sup::config::ConfigurationProtocolServer m_config_protocol_server;
  sup::protocol::ProtocolRPCServer m_protocol_rpc_server;
  sup::epics::PvAccessRPCServer m_epics_server;
};

}  // namespace training

}  // namespace sequencer

#endif  // SEQUENCER_TRAINING_CONFIG_SERVERS_UTILS_H_
