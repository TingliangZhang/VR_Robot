def my_sum(*, mid_score, end_score, mid_rate = 0.4): #期中成绩、期末成绩、期中成绩权重
    #基于期中成绩、期末成绩和权重计算总评成绩
    score = mid_score * mid_rate + end_score * (1 - mid_rate)
    print(format(score, '.2f'))  #输出总评成绩，保留2位小数
my_sum(mid_score = 88, end_score = 79) #期中88，期末79，期中权重为默认的40%
my_sum(end_score = 79, mid_score = 88) #期末79，期中88，期中权重为默认的40%
my_sum(88, 79)                     #报错，必须显式使用命名参数传递值

