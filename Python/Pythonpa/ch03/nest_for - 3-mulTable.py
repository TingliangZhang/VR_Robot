#chapter03\nest_for.py
for i in range(1, 10):
    s = ' '*(7 * (i - 1))
    for j in range(i, 10):
        s += str.format("{0:1}*{1:1}={2:<2} ", i, j, i * j)
    print(s)
input()
