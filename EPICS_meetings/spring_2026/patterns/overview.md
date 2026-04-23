# Overview

This folder contains examples showcasing the behavior tree patterns from `Behavior Trees in Robotics and AI: An Introduction` by Colledanchise & Oegren.

Most of these make use of three states that are exposed over the network by the `sim/room_sim.xml` procedure:

| Channel name         | Type | Description                                  |
| -------------------- | ---- | -------------------------------------------- |
| sim-room:door-locked | bool | Indicates if the door is locked              |
| sim-room:door-open   | bool | Indicates if the door is open                |
| sim-room:is-in-room  | bool | Indicates if the person has entered the room |

The procedure just serves these variables over PvAccess using an encoded payload (`PvAccessEncodedServer`).

`01_explicit_success_conditions.xml` and `02_implicit_sequences.xml` use two different approaches to achieve the goal of getting the person in the room.

The first uses explicit success conditions to achieve all partial goals (unlocked door - open door - room entered). The steps in this procedure are ordered in a very natural way, making it easy to understand the logic. The downside of this approach is that it tries to fulfill all partial goals, which can be unnecessary. In this concrete example, it may be enough to achieve the single goal of having entered the room.

The second procedure use implicit sequences, meaning it will try to achieve the final goal (room entered) and will only take steps to achieve partial goals if those are needed. For example, when the person is already in the room, the procedure will not try to make sure that the door is open or unlocked.

`03_decision_tree.xml` and `04_improving_safety.xml` demonstrate two alternatives of switching between two different execution paths, based on a condition to be true or false. The main difference is that, in the second case, it is fairly straightforward to add supplementary failure conditions with their own specific handlers.

`05_ppa_1.xml`, `06_ppa_2.xml` and `07_ppa_3.xml` demonstrate the usage of the Postcondition-Precondition-Action (PPA) pattern to achieve the same goal as the first two procedures. They start from a single-level PPA and then use backchaining to gradually include more intermediate steps. The final logic (in `07_ppa_3.xml`) is equivalent to the one in `02_implicit_sequences.xml`, in that it tries to achieve partial goals only when required. The main difference is that the PPA pattern leads to deeper nesting levels of the resulting instruction trees. The advantage of the backchaining approach is that it provides the designer of the procedure a very structured way of composing the instruction tree from basic components.

`08_ppa_4.xml` also uses backchaining of PPA blocks to achieve the goal of having entered the room, but in the partial goal of having an open door, it uses different alternatives, with different preconditions. This example can be seen as a mix between the backchaining of PPAs without alternatives and the pattern of implicit sequences. Also note that the second precondition, which would be a locked door, is not explicitly stated. The reason is that this branch (called 'Unlock door') will only be executed if the door is locked. If the door is unlocked, the branch preceding it will take over control.
