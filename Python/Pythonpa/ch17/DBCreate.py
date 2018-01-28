import sqlite3
#创建SQLite数据库：c:\Pythonpa\ch17\sales.db
con = sqlite3.connect(r"c:\Pythonpa\ch17\sales.db")
#创建表：regions，包含2个列，id（主码）和name
con.execute("create table region(id primary key, name)")
