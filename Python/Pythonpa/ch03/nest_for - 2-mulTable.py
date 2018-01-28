#chapter03\nest_for.py
for i in range(1, 10):
    s = ""
    for j in range(1, i+1):
        s += str.format("{0:1}*{1:1}={2:<2} ", i, j, i * j)
    print(s)
input()
