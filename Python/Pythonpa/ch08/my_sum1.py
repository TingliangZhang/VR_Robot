def my_sum1(mid_score, end_score, mid_rate = 0.4):  #期中成绩、期末成绩、期中成绩权重
    score = mid_score * mid_rate + end_score * (1 - mid_rate) #基于期中成绩、期末成绩和权重计算总评成绩
    print(format(score, '.2f'))  #输出总评成绩，保留2位小数
my_sum1(88, 79)      #期中成绩权重为默认的40%
my_sum1(88, 79, 0.5) #期中成绩权重设置为50%
