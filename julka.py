import sys

while True:
    ns = sys.stdin.readline()

    if not ns:
        break

    ns = ns.strip()

    ks = sys.stdin.readline()
    ks = ks.strip()

    n = long(ns)
    k = long(ks)

    x = (n - k) / 2
    y = n - x

    print y
    print x
