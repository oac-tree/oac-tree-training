#!/usr/bin/env bash

SERVER_PREFIX="test"

if [ $# -ne 1 ]; then
  echo "Please provide build directory as command line parameter"
  exit 1
fi

if [ ! -d $1 ]; then
  echo "Command line parameter must be a path to the build directory"
  exit 1
fi

cd $1

/usr/bin/screen -d -m -S SeqTrain_config "$1"/bin/config-servers -s "${SERVER_PREFIX}"
/usr/bin/screen -d -m -S SeqTrain_cvvf "$1"/bin/cvvf-servers -s "${SERVER_PREFIX}"
