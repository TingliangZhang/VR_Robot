import os, re
def check_email(strEmail):
    regex_email = re.compile(r'^[\w\.\-]+@([\w\-]+\.)+[\w\-]+$')
    result = True if regex_email.match(strEmail) else False
    return result
#测试代码
if __name__=='__main__':
    str1 = "hjiang@yahoo.com" #有效的电子邮箱
    str2 = "hjiang.yahoo.com" #无效的电子邮箱
    print(str1,'是有效的电子邮件格式吗？', check_email(str1))
    print(str2,'是有效的电子邮件格式吗？', check_email(str2))
