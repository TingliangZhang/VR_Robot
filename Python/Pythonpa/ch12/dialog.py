from tkinter.messagebox import *
r1=askokcancel(title='askokcancel', message='是否放弃修改的内容？')
r2=askquestion(title='askquestion', message='是否放弃修改的内容？')
r3=askyesno(title='askyesno', message='是否放弃修改的内容？')
r4=askretrycancel(title='askretrycancel', message='系统忙，是否重试？')
showerror(title='showerror', message='无法连接！')
showinfo(title='showinfo', message='连接成功！')
showwarning(title='showwarning', message='磁盘碎片过多！')
