#方法一：
mark = int(input("请输入分数："))
if (mark >= 90): grade = "优"
elif (mark >= 80): grade = "良"
elif (mark >= 70): grade = "中"
elif (mark >= 60): grade = "及格"
else: grade = "不及格"
print(grade)
#方法二：
if (mark >= 90): grade = "优"
elif (mark >= 80 and mark < 90): grade = "良"
elif (mark >= 70 and mark < 80): grade = "中"
elif (mark >= 60 and mark < 70): grade = "及格"
else: grade = "不及格"
print(grade)
#方法三：
if (mark >= 60): grade = "及格"
elif (mark >= 70): grade = "中"
elif (mark >= 80): grade = "良"
elif (mark >= 90): grade = "优"
else: grade = "不及格"
print(grade)
