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

#include <sup/config/configuration_protocol_server.h>

#include <sup/protocol/protocol_rpc_server.h>

#include <sup/epics/pv_access_rpc_server.h>

#include <chrono>
#include <iostream>
#include <thread>

const std::string SERVICE_NAME = "SUP-EXAMPLES::ConfigMemoryServer";

using namespace sequencer::training;
using namespace sup::config;

int main(int argc, char* argv[])
{
  (void)argc;
  (void)argv;

  SignalGeneratorConfigHandler signal_generator_handler{};

  // Protocol stack
  ConfigurationProtocolServer config_protocol_server{signal_generator_handler};
  sup::protocol::ProtocolRPCServer generic_protocol_server{config_protocol_server};

  // EPICS server
  auto service_name = SERVICE_NAME;
  auto server_config = sup::epics::GetDefaultRPCServerConfig(service_name);
  sup::epics::PvAccessRPCServer server{server_config, generic_protocol_server};

  std::cout << "Signal generator configuration service listening on: " << service_name << std::endl;

  // Wait for interrupt signal
  while (true)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
