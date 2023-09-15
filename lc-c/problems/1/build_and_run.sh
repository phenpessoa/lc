#!/bin/bash

gcc hashmaps/ihm/ihm.h hashmaps/ihm/ihm.c problems/1/1.h problems/1/1.c -o builds/1

if [ $? -eq 0 ]; then
    builds/1
    rm builds/1
fi