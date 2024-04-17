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

#include "factory.h"
#include "utils.h"

#include <signal-generator/config_handler.h>

namespace sequencer
{
namespace training
{
using namespace sup::config;

std::unique_ptr<IServerStack>
CreateSignalGeneratorConfigServer(const std::string& service_name)
{
  std::unique_ptr<ConfigurationInterface>
    signal_generator_handler{new SignalGeneratorConfigHandler()};
  std::unique_ptr<IServerStack> server{
    new EPICSConfigServerStack{service_name, std::move(signal_generator_handler)}};
  return server;
}

}  // namespace training

}  // namespace sequencer
