#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution sol.cpp

samplegroup
sample 1

group group1 100
include_group sample
tc_manual tc1
tc_manual tc2
tc_manual tc3

