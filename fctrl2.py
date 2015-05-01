import sys

facts = [1] * 101

for i in xrange(2, 101):
    facts[i] = facts[i-1] * i

t = input()

cases = sys.stdin.readlines()
for case in cases:
    case = case.strip()
    if case:
        case = int(case)
        print facts[case]
