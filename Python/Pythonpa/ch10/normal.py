import math
def _phi(x):
    return math.exp(-x*x/2.0) / math.sqrt(2*math.pi)
def pdf(x, mu=0.0, sigma=1.0):
    return _phi(float((x - mu) / sigma)) / sigma
#测试代码
if __name__ == '__main__': #如果独立运行时，则运行测试代码
    for i in range(0,101):
        print(i, pdf(i, mu=78, sigma=10))
