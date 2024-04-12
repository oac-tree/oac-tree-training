# Configuration server (in memory)

This example shows how to instantiate a SUP configuration server. It uses multiple TestConfigurationHandler objects to handle the separate datasets in the configuration structure. These dataset handlers only keep their dataset structures in memory and are provided only for testing purposes. A real configuration server would depend on custom implementation(s) of the ConfigurationInterface.

The server is launched by running the generated executable `config-memory-server`. It takes no command line parameters. When launched, the server will server a nested configuration structure as follows:

```
<EMPTY>                : Empty dataset name refers to the complete structure
  Metadata             : Simple metadata substructure
  SubSystem01          : Simple subsystem structure
  SubSystem02          : Simple subsystem structure
```

In `src/python/sup-config`, there is a configuration test client `config_client.py` that can be used to test this server. This script will connect to the server, query its available datasets and read the current configuration of the whole dataset and a subsection of it (`SubSystem01`). For each of these operations, the client will output the server's reply to the terminal.

The following is a sample output from the configuration client script:

```txt
Get Datasets
sup::protocolReply/v1.0
    uint result 0
    ulong timestamp 1677225757470287998
    string reason
    structure reply
        string[] dataset_names [, Metadata, SubSystem01, SubSystem02]


******************************************

Read Configuration: full set
sup::protocolReply/v1.0
    uint result 0
    ulong timestamp 1677225757470751798
    string reason
    structure reply
        structure value
            structure Metadata
                string desciption "Main system configuration structure"
                string version 1.0
            structure SubSystem01
                boolean enabled true
                double setpoint 0
            structure SubSystem02
                boolean enabled true
                double setpoint 0


******************************************

Read Configuration: subsystem01
sup::protocolReply/v1.0
    uint result 0
    ulong timestamp 1677225757471322798
    string reason
    structure reply
        structure value
            boolean enabled true
            double setpoint 0
```