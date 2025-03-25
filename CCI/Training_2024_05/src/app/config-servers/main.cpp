/******************************************************************************
 * $HeadURL: $
 * $Id: $
 *
 * Project       : oac-tree training
 *
 * Description   : Training materials for the oac-tree.
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

#include <oac-tree/training/factory.h>

#include <sup/cli/command_line_parser.h>

#include <chrono>
#include <iostream>
#include <thread>

using namespace oac_tree::training;

int main(int argc, char* argv[])
{
  sup::cli::CommandLineParser parser;
  parser.SetDescription(
      /*header*/ "",
      "The program instantiates the configuration servers for the oac-tree training.");
  parser.AddHelpOption();

  parser.AddOption({"-s", "--service-prefix"}, "Prefix to use for all configuration service names")
      .SetParameter(true)
      .SetValueName("prefix")
      .SetRequired(true);

  if (!parser.Parse(argc, argv))
  {
    std::cout << parser.GetUsageString();
    return 0;
  }
  auto service_prefix = parser.GetValue<std::string>("--service-prefix");

  std::string signal_generator_service_name = service_prefix + ":SignalGeneratorConfigServer";
  auto signal_generator_config_server = CreateSignalGeneratorConfigServer(
    signal_generator_service_name);
  std::cout << "Signal generator configuration service listening on: "
            << signal_generator_service_name << std::endl;

  // Wait for interrupt signal
  while (true)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
