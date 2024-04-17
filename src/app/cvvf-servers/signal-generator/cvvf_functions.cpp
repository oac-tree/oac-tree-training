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

#include <sup/dto/anyvalue_helper.h>

#include <algorithm>
#include <exception>

const std::string kOutput_1 = "out1";
const std::string kOutput_2 = "out2";

const sup::dto::AnyType signal_config_t = {{
  { "shape", sup::dto::StringType },
  { "freq", sup::dto::Float64Type },
  { "phase", sup::dto::Float64Type }
}, "Signal_t"};

const sup::dto::AnyType generator_config_t = {{
  { kOutput_1, signal_config_t },
  { kOutput_2, signal_config_t },
  { "active", sup::dto::BooleanType }
}, "SignalGenerator_t" };

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
  static const std::vector<std::string> valid_shapes = {"sine", "triangle", "sawtooth", "square"};
  auto shape = input["shape"].As<std::string>();
  return std::find(valid_shapes.begin(), valid_shapes.end(), shape) != valid_shapes.end();
}

}  // namespace training

}  // namespace sequencer

namespace
{

}  // unnamed namespace

