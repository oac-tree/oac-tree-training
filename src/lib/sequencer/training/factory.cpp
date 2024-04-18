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

#include <sequencer/training/factory.h>

#include <sequencer/training/signal-generator/config_handler.h>
#include <sequencer/training/signal-generator/cvvf_functions.h>

#include <sequencer/training/utils.h>

#include <sup/cvvf/function_executor.h>

namespace sequencer
{
namespace training
{
using namespace sup::config;
using namespace sup::cvvf;

std::unique_ptr<IServerStack>
CreateSignalGeneratorConfigServer(const std::string& service_name)
{
  std::unique_ptr<ConfigurationInterface>
    signal_generator_handler{new SignalGeneratorConfigHandler()};
  std::unique_ptr<IServerStack> server{
    new EPICSConfigServerStack{service_name, std::move(signal_generator_handler)}};
  return server;
}

std::unique_ptr<IServerStack>
CreateSignalGeneratorCvvfServer(const std::string& service_name)
{
  std::unique_ptr<FunctionExecutor> function_executor{new FunctionExecutor()};
  // register functions
  std::unique_ptr<UserFunction> shape_validator{new SignalGeneratorShapeValidator()};
  function_executor->RegisterFunction(kSignalGeneratorValidateShapeFunction,
                                      std::move(shape_validator));
  std::unique_ptr<UserFunction> signal_ref_validator{new SignalGeneratorReferenceSignalValidator()};
  function_executor->RegisterFunction(kSignalGeneratorValidateSignalRefFunction,
                                      std::move(signal_ref_validator));
  std::unique_ptr<UserFunction> signal_ref_transform{new SignalGeneratorReferenceSignalTransformer()};
  function_executor->RegisterFunction(kSignalGeneratorTransformSignalRefFunction,
                                      std::move(signal_ref_transform));
  std::unique_ptr<IServerStack> server{
    new EPICSCVVFServerStack{service_name, std::move(function_executor)}};
  return server;
}

}  // namespace training

}  // namespace sequencer
