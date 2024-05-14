#!/usr/bin/env bash

SCRIPT_PATH=$(dirname "$0")
APP=/opt/codac/bin/sequencer-cli
cd $SCRIPT_PATH

echo "Launch procedure 1 in background"
/usr/bin/screen -d -m -S Training_Ping ${APP} -f ping.xml

sleep 1

echo "Launch procedure 2 in foreground"
time ${APP} -f pong.xml