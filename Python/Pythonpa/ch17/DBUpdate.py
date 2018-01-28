import sqlite3
regions = [("021", "上海"),('022', "天津"),("023", "重庆"),("024", "沈阳")]
#打开SQLite数据库：c:\Pythonpa\ch17\sales.db
con = sqlite3.connect(r"c:\Pythonpa\ch17\sales.db")
#使用不同的方法分别插入一行数据
con.execute("insert into region(id, name) values ('020', '广东')")
con.execute("insert into region(id, name) values (?, ?)", ('001', '北京'))
#插入多行数据
con.executemany("insert into region(id, name) values (?, ?)", regions)
#修改一行数据
con.execute("update region set name=? where id=?", ('广州','020'))
#删除一行数据
n=con.execute("delete from region where id=?", ("024",))
print('删除了', n.rowcount, '行记录')
con.commit()           #提交
con.close()             #关闭数据库
