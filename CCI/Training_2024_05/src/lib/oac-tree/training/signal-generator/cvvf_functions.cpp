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

#include "cvvf_functions.h"
#include "types.h"

#include <sup/dto/anyvalue_helper.h>

#include <algorithm>
#include <exception>
#include <map>

namespace
{

}  // unnamed namespace

namespace oac_tree
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
  // Only specific shapes are allowed
  auto shape = input["shape"].As<std::string>();
  if (std::find(kGeneratorValidShapes.begin(), kGeneratorValidShapes.end(), shape)
      == kGeneratorValidShapes.end())
  {
    return false;
  }
  // Frequency should be between 10 Hz to 20kHz
  auto frequency = input["freq"].As<sup::dto::float64>();
  if (frequency < 10.0 || frequency > 1e4)
  {
    return false;
  }
  return true;
}

SignalGeneratorReferenceSignalValidator::SignalGeneratorReferenceSignalValidator() = default;

SignalGeneratorReferenceSignalValidator::~SignalGeneratorReferenceSignalValidator() = default;

bool SignalGeneratorReferenceSignalValidator::GetInputType(sup::dto::AnyType& input_type) const
{
  input_type = reference_signal_config_t;
  return true;
}

bool SignalGeneratorReferenceSignalValidator::GetOutputType(sup::dto::AnyType& output_type) const
{
  output_type = sup::dto::EmptyType;
  return true;
}

bool SignalGeneratorReferenceSignalValidator::Process(const sup::dto::AnyValue& input,
                                                      sup::dto::AnyValue& output)
{
  (void)output;  // validation function doesn't produce output
  auto shape_ref = input["shape_ref"].As<sup::dto::uint32>();
  return shape_ref < static_cast<sup::dto::uint32>(kInvalidRef);
}

SignalGeneratorReferenceSignalTransformer::SignalGeneratorReferenceSignalTransformer() = default;

SignalGeneratorReferenceSignalTransformer::~SignalGeneratorReferenceSignalTransformer() = default;

bool SignalGeneratorReferenceSignalTransformer::GetInputType(sup::dto::AnyType& input_type) const
{
  input_type = reference_signal_config_t;
  return true;
}

bool SignalGeneratorReferenceSignalTransformer::GetOutputType(sup::dto::AnyType& output_type) const
{
  output_type = signal_config_t;
  return true;
}

bool SignalGeneratorReferenceSignalTransformer::Process(const sup::dto::AnyValue& input,
                                                        sup::dto::AnyValue& output)
{
  static const std::map<sup::dto::uint32, std::string> shape_map = {
    { static_cast<sup::dto::uint32>(kSineRef), "sine" },
    { static_cast<sup::dto::uint32>(kTriangleRef), "triangle" },
    { static_cast<sup::dto::uint32>(kSawRef), "sawtooth" },
    { static_cast<sup::dto::uint32>(kSquareRef), "square" },
  };
  sup::dto::AnyValue result{signal_config_t};
  auto shape_ref = input["shape_ref"].As<sup::dto::uint32>();
  auto iter = shape_map.find(shape_ref);
  if (iter == shape_map.end())
  {
    return false;
  }
  result["shape"] = iter->second;
  result["freq"].ConvertFrom(440);
  if (!sup::dto::TryAssignIfEmptyOrConvert(output, result))
  {
    return false;
  }
  return true;
}

}  // namespace training

}  // namespace oac_tree

namespace
{

}  // unnamed namespace

