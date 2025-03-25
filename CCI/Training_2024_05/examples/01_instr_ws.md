# Instruction trees, workspace variables and ticking

Instruction statuses:

* Not started: initial state, i.e. instruction has never been ticked
* Not finished: instruction was ticked, but requires more ticks to finish
* Success: instruction has finished successfully
* Failure: instruction has finished with failure
* Running: instruction has asynchronously executing child instruction(s)
