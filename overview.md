# Sequencer training overview

## Preparation

* Ensure participants have a working container with sequencer, plugins and exercise material

## Core (non-GUI) sequencer introduction

* Goals, characteristics
* Behavior trees in general: history, basic logic
* Behavior trees in the sequencer: instruction trees, ticking, workspace, main composite instructions, inclusion of trees
* Plugins

## GUI introduction

## Exercises

Overview:

* Basic configuration of plant system: choice of config, cvvf and config
* Monitoring of plant system
* High-level control of plant systems

### PvAccess ping pong

#### Prerequisites

None

#### Task description

Write a first procedure that:

* Hosts two PvAccess server variables of integer type and initializes them to zero
* Listens to changes of these variables and increments the first one when it is less than or equal to the second one
* Exits when the second variable becomes 1000

Write a second procedure that:

* Has two PvAccess client variables, corresponding to the above server variables
* Listens to changes of these variables and increments the second one when it is less than the first
* Exits when the second variable becomes 1000

### Basic SUP configuration

#### Prerequisites

* Configuration server
* Multiple CVVF servers
* Different configuration sets (json files)

#### Task description

Write a procedure that:

* Provides the user with a choice of different configurations sets to use for configuring a system;
* Applies the necessary CVVF functions for transformation and validation;
* Uploads the configuration to the system.

Extra:

* Upon failure of CVVF or system configuration, provide a clear error message of which step failed.

### Monitoring of plant system

#### Prerequisites

#### Task description

Write a procedure that:

Extra:

### High-level control of plant systems

#### Prerequisites

#### Task description

Write a procedure that:

Extra:
