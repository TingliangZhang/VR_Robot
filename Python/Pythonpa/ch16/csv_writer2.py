import csv
def writecsv2(csvfilepath):
    headers = ['学号', '姓名', '语文', '数学', '英语']
    rows = [{'学号': '101511', '姓名': '宋颐园', '语文': '72', '数学': '85', '英语': '82'},
            {'学号': '101513', '姓名': '王二丫', '语文': '75', '数学': '82', '英语': '51'}]
    with open(csvfilepath,'w', newline='') as f:      #打开文件
        f_csv = csv.DictWriter(f, headers)  #创建csv.DictWriter对象
        f_csv.writeheader()             #写入标题
        f_csv.writerows(rows)          #写入多行（数据）
if __name__ == '__main__':
    writecsv2(r'scores2.csv')
