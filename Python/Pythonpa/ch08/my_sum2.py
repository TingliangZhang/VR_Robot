def my_sum2(mid_score, end_score, mid_rate = 0.4): #期中成绩、期末成绩、期中成绩权重
    #基于期中成绩、期末成绩和权重计算总评成绩
    score = mid_score * mid_rate + end_score * (1 - mid_rate)
    print(format(score, '.2f'))  #输出总评成绩，保留2位小数
#期中88，期末79，并且期中成绩权重为默认的40%。三种调用方式等价
my_sum2(88, 79)     
my_sum2(mid_score = 88, end_score = 79)
my_sum2(end_score = 79, mid_score = 88)

