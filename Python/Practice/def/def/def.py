import sys
def print_star(n):
	print(("*"*n).center(50))
lines=int(sys.argv[1])
for i in range(1,2*lines,2):
	print_star(i)
input()

