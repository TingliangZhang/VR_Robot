file_name = "txt_count.py"  #文本文件名
line_counts = 0             #行数
word_counts = 0             #单词个数       
character_counts = 0        #字符数
with open(file_name, 'r',encoding='utf8') as f:  
    for line in f:  
        words = line.split()          #分离出单词
        line_counts += 1              #行数加1
        word_counts += len(words)     #单词个数加1
        character_counts += len(line) #字符数加1 
print("行数：", line_counts)
print("单词个数：", word_counts) 
print("字符个数：", character_counts)
