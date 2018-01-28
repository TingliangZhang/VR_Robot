from collections import *
import csv
EmployeeRecord = namedtuple('EmployeeRecord', 'name, age, title, department, paygrade')
for emp in map(EmployeeRecord._make, csv.reader(open("employees.csv"))):
    print(emp.name, emp.title)
