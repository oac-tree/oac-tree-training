#include "fail_instruction.h"

#include <sup/sequencer/constants.h>
#include <sup/sequencer/instruction_registry.h>
#include <sup/sequencer/user_interface.h>
#include <sup/sequencer/workspace.h>

const std::string FailInstruction::Type = "Fail";
static bool _fail_instruction_initialised_flag = RegisterGlobalInstruction<FailInstruction>();

FailInstruction::FailInstruction()
  : Instruction(FailInstruction::Type)
{
  AddAttributeDefinition(Constants::TEXT_ATTRIBUTE_NAME).SetMandatory();
}

FailInstruction::~FailInstruction() = default;

ExecutionStatus FailInstruction::ExecuteSingleImpl(UserInterface& ui, Workspace& ws)
{
  std::string message;
  if (!GetAttributeValueAs(Constants::TEXT_ATTRIBUTE_NAME, ws, ui, message))
  {
    return ExecutionStatus::FAILURE;
  }
  ui.Message(message);
  return ExecutionStatus::FAILURE;
}
