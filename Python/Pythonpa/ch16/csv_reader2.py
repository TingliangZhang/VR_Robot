import csv
def readcsv2(csvfilepath):
    with open(csvfilepath, newline='') as f:  #打开文件
        f_csv = csv.reader(f)     #创建csv.DictReader对象
        headers = next(f_csv)    #标题
        print(headers)          #打印标题（列表）
        for row in f_csv:        #循环打印各行（列表）
            print(row)
if __name__ == '__main__':
    readcsv2(r'scores.csv')
