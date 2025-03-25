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

#ifndef OAC_TREE_TRAINING_FACTORY_H_
#define OAC_TREE_TRAINING_FACTORY_H_

#include <oac-tree/training/i_server_stack.h>

#include <memory>
#include <string>

namespace oac_tree
{
namespace training
{

const std::string kSignalGeneratorValidateShapeFunction = "ValidateShape";
const std::string kSignalGeneratorValidateSignalRefFunction = "ValidateSignalRef";
const std::string kSignalGeneratorTransformSignalRefFunction = "TransformSignalRef";

std::unique_ptr<IServerStack>
CreateSignalGeneratorConfigServer(const std::string& service_name);

std::unique_ptr<IServerStack>
CreateSignalGeneratorCvvfServer(const std::string& service_name);

}  // namespace training

}  // namespace oac_tree

#endif  // OAC_TREE_TRAINING_FACTORY_H_
