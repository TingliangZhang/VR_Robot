import pickle
with open(r'c:\pythonpa\dataObj1.dat', 'rb') as f:
    o1=pickle.load(f)
    o2=pickle.load(f)
    o3=pickle.load(f)
    o4=pickle.load(f)
    print(type(o1), str(o1))
    print(type(o2), str(o2))
    print(type(o3), str(o3))
    print(type(o4), str(o4))
