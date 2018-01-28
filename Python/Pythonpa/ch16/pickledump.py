import pickle
with open(r'c:\pythonpa\dataObj1.dat', 'wb') as f:
    s1='Hello!'
    c1=1+2j
    t1=(1,2,3)
    d1=dict(name='Mary', age=19)
    pickle.dump(s1, f)
    pickle.dump(c1, f)
    pickle.dump(t1, f)
    pickle.dump(d1, f)
