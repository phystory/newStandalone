#!/bin/bash
export DAQROOT=/usr/opt/daq/current
cp *.dat ~/
$DAQROOT/bin/ReadoutShell -host=spdaq35 -path=./Readout
