from io import StringIO
f = StringIO('Hello!\nHi!\nGoodbye!')
for s in f:
    print(s.strip())
