#chapter03\while_e.py
i = 1; e = 1; t = 1
while (1/t >= pow(10,-6)):
    t *= i
    e += 1 / t
    i += 1
print("e =", e)
