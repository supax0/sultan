#!/bin/sh

cd compiler/manager
gcc -o manager manager.c ../builder/builder.c ../builder/run.c


./manager build