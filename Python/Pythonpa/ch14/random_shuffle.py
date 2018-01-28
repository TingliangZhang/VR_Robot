import random
#一幅牌：Club（梅花）、Diamond（方块）、Heart（红桃）、Spade（黑桃）、2-10,J,Q,K,A
cards = ['2C','3C','4C','5C','6C','7C','8C','9C','10C','JC','QC','KC','AC',
         '2D','3D','4D','5D','6D','7D','8D','9D','10D','JD','QD','KD','AD',
         '2H','3H','4H','5H','6H','7H','8H','9H','10H','JH','QH','KH','AH',
         '2S','3S','4S','5S','6S','7S','8S','9S','10S','JS','QS','KS','AS']
random.shuffle(cards)             #混排，洗牌
deck1=[];deck2=[];deck3=[];deck4=[] #初始化四手牌
for i in range(13):                 #发牌
    deck1.append(cards.pop())
    deck2.append(cards.pop())
    deck3.append(cards.pop())
    deck4.append(cards.pop())
print(deck1);print(deck2);print(deck3);print(deck4)
