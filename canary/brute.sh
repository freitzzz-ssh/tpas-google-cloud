#!/bin/bash

for i in {0..1024}
do
	echo '=>>>>>>>' $i
	python3 example.py 40 $i 0 8
done
