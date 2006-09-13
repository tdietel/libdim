#!/bin/bash
#
# written by Benjamin Schockert

setVariables(){
	export OS="Linux"
	export DIMDIR="$(pwd)"
	export ODIR="linux"
	export LD_LIBRARY_PATH=$DIMDIR/$ODIR
	echo "OS is set to $OS"
	echo "DIMDIR is set to $DIMDIR"
	echo "ODIR is set to $ODIR"
	echo "LD_LIBRARY_PATH is set to $LD_LIBRARY_PATH"
}

setVariables
