class CustomAttribute(object):
    def __init__(self):
        pass
    def __getattribute__(self, name):
        return str.upper(object.__getattribute__(self, name))
    def __setattr__(self, name, value):
        object.__setattr__(self, name, str.strip(value))
#测试代码
o = CustomAttribute()
o.firstname='      mary     '
print(o.firstname)
