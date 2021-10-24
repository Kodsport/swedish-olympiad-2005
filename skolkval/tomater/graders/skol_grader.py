#!/usr/bin/env python

# Skolkval-grader
# Use with 3 testdata groups
# 3 groups = 100p
# 2 groups = 50p
# 0-1 groups = 0p

import sys

def worst_verdict(verdicts):
    for v in ['JE', 'RTE', 'MLE', 'TLE', 'OLE', 'WA']:
        if v in verdicts:
            return v
    return verdicts[0]

# Worst error or AC (50/100)
total_score = 0
bad_verdicts = []
for line in sys.stdin.readlines():
    verdict, score = line.split()
    if verdict != "AC":
        bad_verdicts.append(verdict)
    total_score += float(score)
if total_score >= 2:
    if total_score == 2:
        print "AC", 50
    elif total_score == 3:
        print "AC", 100
    else:
        print "JE", 0
else:
    print worst_verdict(bad_verdicts), 0
