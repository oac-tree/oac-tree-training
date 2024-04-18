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

#include "cvvf_functions.h"
#include "types.h"

#include <sup/dto/anyvalue_helper.h>

#include <algorithm>
#include <exception>

namespace
{

}  // unnamed namespace

namespace sequencer
{
namespace training
{
SignalGeneratorShapeValidator::SignalGeneratorShapeValidator() = default;

SignalGeneratorShapeValidator::~SignalGeneratorShapeValidator() = default;

bool SignalGeneratorShapeValidator::GetInputType(sup::dto::AnyType& input_type) const
{
  input_type = signal_config_t;
  return true;
}

bool SignalGeneratorShapeValidator::GetOutputType(sup::dto::AnyType& output_type) const
{
  output_type = sup::dto::EmptyType;
  return true;
}

bool SignalGeneratorShapeValidator::Process(const sup::dto::AnyValue& input,
                                            sup::dto::AnyValue& output)
{
  (void)output;  // validation function doesn't produce output
  auto shape = input["shape"].As<std::string>();
  return std::find(kGeneratorValidShapes.begin(), kGeneratorValidShapes.end(), shape)
         != kGeneratorValidShapes.end();
}

}  // namespace training

}  // namespace sequencer

namespace
{

}  // unnamed namespace

