#!/usr/bin/env bash

SERVER_PREFIX=$(whoami)

if [ $# -ne 1 ]; then
  echo "Please provide build directory as command line parameter"
  exit 1
fi

if [ ! -d $1 ]; then
  echo "Command line parameter must be a path to the build directory"
  exit 1
fi

CONFIG_SERVERS_EXE="$1/bin/config-servers"
CVVF_SERVERS_EXE="$1/bin/cvvf-servers"

if [ ! -x "${CONFIG_SERVERS_EXE}" -o ! -x "${CVVF_SERVERS_EXE}" ]; then
  echo "Provided path does not contain the required executables."
  echo "Has the project been built correctly?"
  exit 1
fi

echo "Launching ${CONFIG_SERVERS_EXE} and ${CVVF_SERVERS_EXE} with prefix ${SERVER_PREFIX}"

/usr/bin/screen -d -m -S SeqTrain_config "${CONFIG_SERVERS_EXE}" -s "${SERVER_PREFIX}"
/usr/bin/screen -d -m -S SeqTrain_cvvf "${CVVF_SERVERS_EXE}" -s "${SERVER_PREFIX}"
