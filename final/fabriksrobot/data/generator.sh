#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution joshua.cpp

samplegroup
sample fabriksrobot0

group group1 20
tc_manual g1-1
tc_manual g1-2

group group2 80
include_group sample
include_group group1
tc_manual g2-1
tc_manual g2-2
tc_manual g2-3
tc_manual g2-4
tc_manual g2-5

