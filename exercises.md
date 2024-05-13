# Sequencer training exercises

Overview:

* EPICS ping/pong
* Basic configuration of plant system: choice of config, cvvf and config
* Monitoring of plant system

## PvAccess ping pong

Write a first procedure that:

* Hosts two PvAccess server variables of integer type and initializes them to zero
* Listens to changes of these variables and increments the first one when it is less than or equal to the second one
* Exits when the second variable becomes 1000

Write a second procedure that:

* Has two PvAccess client variables, corresponding to the above server variables
* Listens to changes of these variables and increments the second one when it is less than the first
* Exits when the second variable becomes 1000

## Basic SUP configuration

### Prerequisites

* Build servers
* Launch them using `scripts/launch_servers.sh <BUILD-DIR>`

### Config server

The configuration server is hosted with server name `<USER>:SignalGeneratorConfigServer` and serves the following configuration structure:

```txt
struct SignalGenerator_t
    out1: struct Signal_t
        shape: string ""
        freq: float64 0.0
        phase: float64 0.0
    out2: struct Signal_t
        shape: string ""
        freq: float64 0.0
        phase: float64 0.0
    active: bool false
```

The full structure is accessible using the default empty dataset name, while the two main substructures can be addressed using the dataset names `out1` and `out2`.

The configuration server does some internal validation on itself. The constraints are as follows:

* When `active` is false, an empty default structure is accepted (all zero's or empty strings)
* Otherwise:
  * `shape` has to be one of `sine`, `triangle`, `sawtooth` or `square`
  * `freq` should be between 10 and 10000 (10Hz to 10kHz)

### CVVF server

The CVVF server is hosted with server name `<USER>:SignalGeneratorCVVFServer` and serves the following CVVF functions:

* `ValidateShape`: validates a structure with type `Signal_t` (the two substructures of the full configuration) according to the constraints of `shape` and `freq` mentioned in the configuration server; note that this validation function will not succeed when given an default structure (zeros);
* `ValidateSignalRef`: validates a structure with type `ReferenceSignal_t` (see below); it only accepts `shape_ref` values from 0 to 3 (corresponding to the four different supported shapes);
* `TransformSignalRef`: transforms a valid structure with type `ReferenceSignal_t` into a structure of type `Signal_t`, with the provided shape, a frequency of 440Hz and zero phase.

The `ReferenceSignal_t` type is defined as follows:

```txt
struct ReferenceSignal_t
    shape_ref: uint32 0
```

### Tasks

#### CVVF

Write a procedure that:

* Provides the user with a choice of different shapes (sine, triangle, sawtooth and square) for a signal generator output and create the appropriate `ReferenceSignal_t` structure;
* Validate and transform this structure using the CVVF client calls `ValidateSignalRef` and `TransformSignalRef`;
* Output the result using the `Output` instruction.
* Validate the output of the previous transformation using the CVVF client call `ValidateShape`;

#### Configure

Using the result from the previous task, create a procedure that:

* Reads the current configuration into a local variable
* Asks the user to select one of the different shapes, validate, transform and validate again (see previous task)
* Write this output into the first output of the configuration `out1`
* Idem for `out2`.
* Set the `active` flag to `true` locally;
* Upon success, write this configuration to the SUP config server.
* (optional) Store this configuration to a file variable.

#### Extra

How would you create a daemon procedure that listens for the two reference inputs (shapes of output 1 and 2) and automatically performs all the validation, transformation and final configuration? How can we get the result of this operation?

Can you also create a separate procedure that resets the configuration to its default (all zeros)?

## Monitoring of system statuses

There are four different subsystems that publish their overall health status as a boolean. The PvAccess variables are:

* `training::system01::status`
* `training::system02::status`
* `training::system03::status`
* `training::system04::status`

Create a procedure that monitors (listens to) these four statuses and publishes its own global status. The global status is a boolean that is true only when all four system statuses are true.
