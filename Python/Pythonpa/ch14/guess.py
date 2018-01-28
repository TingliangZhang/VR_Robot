import random
secret = random.randrange(1, 101)
guess = 0
while guess != secret:
    guess = int(input("请猜测一个100之内的数："))
    if (guess < secret): print('太小')
    elif (guess > secret): print('太大')
    else: print('正确！')
