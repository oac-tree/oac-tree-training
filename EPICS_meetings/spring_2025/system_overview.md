# Overview of example systems

As an example system, we will use a simplified control system for a greenhouse. The example focuses on temperature and humidity control of the greenhouse.

## Subsystems of the control system

### Temperature control

Temperature is controlled by a pair of geothermal heat pumps.

Each pump has the following process variables:

| PV name            | Type | Description                                 |
| ------------------ | ---- | ------------------------------------------- |
| TEMP:PUMPX:MODE    | mbbi | Pump mode (0: Idle, 1: Heating, 2: Cooling) |
| TEMP:PUMPX:FAILURE | mbbi | Failure indication (0: OK, 1: FAILURE)      |

where `X` is `1` or `2`.

#### Monitoring procedures

A monitoring procedure will be created to publish the following PVs:

| PV name      | Type   | Description                 |
| ------------ | ------ | --------------------------- |
| TEMP:N-PUMPS | longin | Number of operational pumps |
| TEMP:OPSTATE | mbbi   | Temperature control state   |

The number of operational pumps just counts the number of pumps that are not indicating FAILURE.

The TEMP:OPSTATE enumeration is as follows:

* 0: Idle: no pumps running
* 1: Reduced heating: one pump running in heating mode
* 2: Max heating: two pumps running in heating mode
* 3: Reduced cooling: one pump running in cooling mode
* 4: Max cooling: two pumps running in cooling mode
* 5: Fault mode: when one pump is cooling while the other one is heating

When a pump exhibits a failure, it is assumed to be idle.

This state deduction will also be implemented as part of the exercise.

#### Control procedures

A low-level control procedure will be implemented that tries to put the TEMP:OPSTATE in the desired state: idle or reduced/max heating/cooling.

As a next step, a more automatic control procedure could use the current temperature readings (inside/outside) and the desired setpoint to send an appropriate command to the low-level control procedure (use PvAccess for this communication between procedures).

### Humidity control

Humidity is controlled by sprinklers (increase humidity) and ventilation (decrease humidity).
