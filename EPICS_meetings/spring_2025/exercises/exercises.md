# oac-tree training exercises

## learn the basics

* Implement the fibbonacci algorithm with just the core instructions of oac-tree
* Implement a procedure to read data from a ChannelAccessClient variable and write it to a PVAccessServer variable.
* Create a procedure that waits for a specific condition on a ChannelAccessClient variable before proceeding.
* Develop two scripts, one that increments a PV every second, another one that resets PV if it is bigger than 10
* Develop a sequence to start a timer and log a message when it
* Develop a parallel_sequence instruction to perform two actions simultaneously with PVAccessClient variables.
* Develop a procedure to start a timer when a specific condition is met on a PVAccessClient variable.

## Greenhouse simulation

### Temperature

* launch the CA database with softIOC:
  /opt/codac/epics/bin/linux-x86_64/softIoc -d greenhouse_records.db &
* launch oac-tree-gui and load the following scripts:
  * compute_inside_temperature.xml
  * compute_outside_temperature.xml
  * Manage_pumps.xml
  * timer.xml
* develop a script to change the values of the PUMP modes
* develop a script to reset the pumps when they are in failure mode
* develop a script that changes the mode of the Pumps depeding in the current inside temperature and defines limits to that temperature

### Humidity

* launch RPC server with:
  python greenhouse_humidiity_control.py &
* develop a script that calls the RPC server in path greenhouse:get_out_humidity and copies it to a PvAccessServer variable called Humidity
* Extend that same script to update the inner humidity of the greenhouse in time (use a listen for time and call the RPC in greenhouse:get_in_humidity)
* Extend again the script to maintain the humidity between 85 and 95%, use the RPC greenhouse:activate_sprinklers to raise the humidity and greenhouse:activate_ventilation to lower it
