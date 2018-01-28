import sys
n = int(sys.argv[1])
result=[]
factor = 2
while factor*factor <= n:
    while (n % factor) == 0:
        n //= factor
        result.append(factor)
        print(n, factor)
    factor += 1
if n > 1:
    result.append(n)
print(result)
