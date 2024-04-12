/******************************************************************************
 * $HeadURL: $
 * $Id: $
 *
 * Project       : Supervision and Automation - Examples
 *
 * Description   : Examples to demonstrate how to use SUP framework libraries and tools.
 *
 * Author        : Walter Van Herck (IO)
 *
 * Copyright (c) : 2010-2023 ITER Organization,
 *                 CS 90 046
 *                 13067 St. Paul-lez-Durance Cedex
 *                 France
 *
 * This file is part of ITER CODAC software.
 * For the terms and conditions of redistribution or use of this software
 * refer to the file ITER-LICENSE.TXT located in the top level directory
 * of the distribution package.
 ******************************************************************************/

#include <sup/dto/anyvalue.h>

#include <sup/config-test/test_configuration_handler.h>
#include <sup/config/composite_configuration_handler.h>
#include <sup/config/configuration_protocol_server.h>

#include <sup/protocol/protocol_rpc_server.h>

#include <sup/epics/pv_access_rpc_server.h>

#include <chrono>
#include <thread>
#include <iostream>

const std::string SYSTEM_META_NAME = "Metadata";
const std::string SUBSYSTEM01_NAME = "SubSystem01";
const std::string SUBSYSTEM02_NAME = "SubSystem02";

const sup::dto::AnyValue SYSTEM_META_STRUCTURE = {
  { "desciption", { sup::dto::StringType, "Main system configuration structure" }},
  { "version", { sup::dto::StringType, "1.0" }}
};

const sup::dto::AnyValue SUBSYSTEM_STRUCTURE = {
  { "enabled", { sup::dto::BooleanType, true }},
  { "setpoint", { sup::dto::Float64Type, 0.0 }}
};

const std::string SERVICE_NAME = "SUP-EXAMPLES::ConfigMemoryServer";

using namespace sup::config;

int main(int argc, char* argv[])
{
  (void)argc;
  (void)argv;

  // Configuration handler composed of a metadata set and two subsystem sets
  test::TestConfigurationHandler system_meta_handler{SYSTEM_META_STRUCTURE};
  test::TestConfigurationHandler subsystem01_handler{SUBSYSTEM_STRUCTURE};
  test::TestConfigurationHandler subsystem02_handler{SUBSYSTEM_STRUCTURE};
  CompositeConfigurationHandler system_handler{};
  system_handler.AddConfiguration(SYSTEM_META_NAME, system_meta_handler);
  system_handler.AddConfiguration(SUBSYSTEM01_NAME, subsystem01_handler);
  system_handler.AddConfiguration(SUBSYSTEM02_NAME, subsystem02_handler);

  // Protocol stack
  ConfigurationProtocolServer config_protocol_server{system_handler};
  sup::protocol::ProtocolRPCServer generic_protocol_server{config_protocol_server};

  // EPICS server
  auto service_name = SERVICE_NAME;
  auto server_config = sup::epics::GetDefaultRPCServerConfig(service_name);
  sup::epics::PvAccessRPCServer server{server_config, generic_protocol_server};

  std::cout << "Service listening on: " << service_name << std::endl;

  // Wait for interrupt signal
  while (true)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
