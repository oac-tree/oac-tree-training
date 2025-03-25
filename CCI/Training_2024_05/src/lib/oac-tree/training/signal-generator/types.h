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

#ifndef OAC_TREE_TRAINING_SIGNAL_GENERATOR_TYPES_H_
#define OAC_TREE_TRAINING_SIGNAL_GENERATOR_TYPES_H_

#include <sup/dto/anytype.h>

#include <string>
#include <vector>

namespace oac_tree
{
namespace training
{

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

const std::vector<std::string> kGeneratorValidShapes = {"sine", "triangle", "sawtooth", "square"};

enum ReferenceSignal : sup::dto::uint32
{
  kSineRef = 0,
  kTriangleRef,
  kSawRef,
  kSquareRef,
  kInvalidRef
};

const sup::dto::AnyType reference_signal_config_t = {{
  { "shape_ref", sup::dto::UnsignedInteger32Type }
}, "ReferenceSignal_t"};

}  // namespace training

}  // namespace oac_tree

#endif  // OAC_TREE_TRAINING_SIGNAL_GENERATOR_TYPES_H_
