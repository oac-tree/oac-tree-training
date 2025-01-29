# oac-tree training

## Get a working CCS7.2 environment

* CCS container
* Shared VM: `ccs720-2`

## Install necessary packages

Install the packages required for SUP configuration and CVVF (only for container):

```bash
sudo dnf install codac-core-7.2-sup-config codac-core-7.2-sup-epics
```

Install the packages related to the oac-tree:

```bash
sudo dnf install codac-core-7.2-oac-tree codac-core-7.2-oac-tree-gui codac-core-7.2-oac-tree-plugin-control codac-core-7.2-oac-tree-plugin-epics codac-core-7.2-oac-tree-plugin-math codac-core-7.2-oac-tree-plugin-sup
```

Install the GUI:

```bash
sudo dnf install codac-core-7.2-oac-tree-gui
```

## Build the test servers

```bash
mkdir <BUILD_PATH>
cd <BUILD_PATH>
cmake <SOURCE_PATH>
make
```

In the end, there should be two executables in `<BUILD_PATH>/bin`.
