# Basic examples

This folder contains some basic examples of oac-tree procedures that demonstrate a specific feature:

* `fibonacci.xml`: calculation of Fibonacci numbers using the `mathexpr` plugin
* `counter.xml` and `reset.xml`: exposing an increasing counter with a PvAccess server PV and resetting it when it exceeds a given threshold
* `ca_to_pva.xml`: read a ChannelAccess PV, double it and write the result to PvAccess Server PV

To be able to run the procedures that connect to a ChannelAccess PV successfully, launch a softIOC:

```bash
softIoc -d db/examples.db
```
