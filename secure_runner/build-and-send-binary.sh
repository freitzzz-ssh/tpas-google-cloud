#!/bin/bash

source_name=$1

# build
gcc -fno-stack-protector -z execstack $source_name.c -o $source_name

# translate to base64
cat $source_name | base64 > $source_name.txt

# send payload
cat <(cat $source_name.txt) - | nc tpas.alunos.dcc.fc.up.pt 5008
