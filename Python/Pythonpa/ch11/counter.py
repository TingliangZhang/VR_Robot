import collections, re
path = r'c:\pythonpa\ch11\counter.py'
with open(path, encoding='utf8') as f:
    words = re.findall(r'\w+', f.read().lower())#读取文本内容，转化为小写
    c = collections.Counter(words)        #统计各单词的计数
    print(c.most_common(5))            #最高计数的5个单词
