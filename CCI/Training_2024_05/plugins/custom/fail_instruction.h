#include <sup/oac-tree/execution_status.h>
#include <sup/oac-tree/instruction.h>

using namespace sup::oac_tree;

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
