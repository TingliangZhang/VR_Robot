import sys
lo = int(sys.argv[1])
hi = int(sys.argv[2])
for line in sys.stdin:
    value = int(line)
    if (value >= lo) and (value <= hi):
        print(str(value))
