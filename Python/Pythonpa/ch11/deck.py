import random
SUITS = ['Club', 'Diamond', 'Heart', 'Spade']  #梅花、方块、红桃、黑桃
RANKS = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
#生成一副扑克牌，每副牌包含52张牌（大小王除外）
deck = []  #一副扑克牌
for rank in RANKS:
    for suit in SUITS:
        card = rank + ' of ' + suit
        deck += [card]
#洗牌
n = len(deck)
for i in range(n):
    r = random.randrange(i, n)
    temp = deck[r]
    deck[r] = deck[i]
    deck[i] = temp
#输出一副牌
for s in deck: print(s)
