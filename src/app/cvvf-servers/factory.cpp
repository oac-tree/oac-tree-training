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

#include <signal-generator/cvvf_functions.h>

#include <sequencer/training/utils.h>

#include <sup/cvvf/function_executor.h>

namespace sequencer
{
namespace training
{
using namespace sup::cvvf;

std::unique_ptr<IServerStack>
CreateSignalGeneratorCvvfServer(const std::string& service_name)
{
  std::unique_ptr<FunctionExecutor> function_executor{};
  // register functions
  std::unique_ptr<UserFunction> shape_validator{new SignalGeneratorShapeValidator()};
  function_executor->RegisterFunction("ValidateShape", std::move(shape_validator));
  std::unique_ptr<IServerStack> server{
    new EPICSCVVFServerStack{service_name, std::move(function_executor)}};
  return server;
}

}  // namespace training

}  // namespace sequencer
