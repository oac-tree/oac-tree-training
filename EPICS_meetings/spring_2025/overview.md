# EPICS Collaboration Spring Meeting oac-tree workshop

This folder contains the basic examples and a set of exercises used during the oac-tree workshop.

## Prerequisites

These examples and exercises assume the correct installation of oac-tree, its GUI and the following plugins:

* oac-tree-epics
* oac-tree-mathexpr
* (oac-tree-control)

## No longer required, but may be reactivated in future workshops

Some exercises will require running Python scripts that expose some services on the network. For the required Python packages, a virtual environment is advised:

```bash
python -m venv --system-site-packages .venv
source .venv/bin/activate
pip install --upgrade pip
pip install -r pip_reqs.txt
```

## Workshop overview

* Basic intro to GUI: file explorer, editor and execution
* oac-tree-server and client
* Basic control nodes and their use: e.g. Listen for monitoring procedures, Fallback for regular operational tasks, etc.
* Optional exercises using Greenhouse example
  * explain construction of the simplest exercises
* Discussion
