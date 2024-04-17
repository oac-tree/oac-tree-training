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

#ifndef SEQUENCER_TRAINING_CONFIG_SERVERS_I_SERVER_STACK_H_
#define SEQUENCER_TRAINING_CONFIG_SERVERS_I_SERVER_STACK_H_

namespace sequencer
{
namespace training
{
class IServerStack
{
public:
  virtual ~IServerStack();
};

}  // namespace training

}  // namespace sequencer

#endif  // SEQUENCER_TRAINING_CONFIG_SERVERS_I_SERVER_STACK_H_
