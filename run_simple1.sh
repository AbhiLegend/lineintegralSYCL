#!/bin/bash
source /opt/intel/oneapi/setvars.sh > /dev/null 2>&1
/bin/echo "##" $(whoami) is compiling DPCPP_Essentials Module1 -- oneAPI Techgig example - 1 of 1 simple1.cpp
dpcpp lab/simple1.cpp
if [ $? -eq 0 ]; then ./a.out; fi

