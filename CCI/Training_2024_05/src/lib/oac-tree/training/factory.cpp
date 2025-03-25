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

#include <oac-tree/training/signal-generator/config_handler.h>
#include <oac-tree/training/signal-generator/cvvf_functions.h>

#include <oac-tree/training/utils.h>

#include <sup/cvvf/function_executor.h>

namespace oac_tree
{
namespace training
{
using namespace sup::config;
using namespace sup::cvvf;

std::unique_ptr<IServerStack>
CreateSignalGeneratorConfigServer(const std::string& service_name)
{
  auto signal_generator_handler = std::make_unique<SignalGeneratorConfigHandler>();
  auto server =
      std::make_unique<EPICSConfigServerStack>(service_name, std::move(signal_generator_handler));
  return server;
}

std::unique_ptr<IServerStack>
CreateSignalGeneratorCvvfServer(const std::string& service_name)
{
  auto function_executor = std::make_unique<FunctionExecutor>();
  // register functions
  auto shape_validator = std::make_unique<SignalGeneratorShapeValidator>();
  function_executor->RegisterFunction(kSignalGeneratorValidateShapeFunction,
                                      std::move(shape_validator));
  auto signal_ref_validator = std::make_unique<SignalGeneratorReferenceSignalValidator>();
  function_executor->RegisterFunction(kSignalGeneratorValidateSignalRefFunction,
                                      std::move(signal_ref_validator));
  auto signal_ref_transform = std::make_unique<SignalGeneratorReferenceSignalTransformer>();
  function_executor->RegisterFunction(kSignalGeneratorTransformSignalRefFunction,
                                      std::move(signal_ref_transform));
  auto server = std::make_unique<EPICSCVVFServerStack>(service_name, std::move(function_executor));
  return server;
}

}  // namespace training

}  // namespace oac_tree
