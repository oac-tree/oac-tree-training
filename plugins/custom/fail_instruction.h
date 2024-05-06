#include <sup/sequencer/execution_status.h>
#include <sup/sequencer/instruction.h>

using namespace sup::sequencer;

/**
 * @brief Instruction that always fails with a message
 */
class FailInstruction : public Instruction
{
public:
  FailInstruction();
  ~FailInstruction() override;
  static const std::string Type;
private:
  ExecutionStatus ExecuteSingleImpl(UserInterface& ui, Workspace& ws) override;
};
