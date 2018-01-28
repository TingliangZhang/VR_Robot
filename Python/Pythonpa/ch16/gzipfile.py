import sys, gzip
filename = sys.argv[0]         #the first argument as the file name
filenamezip = filename + '.gz'   #file extension .gz
# gzip compression 
with gzip.open(filenamezip, 'wt') as f:  
    for s in open(filename, 'r'):
        f.write(s)
# gzip decompression
for s in gzip.open(filenamezip, 'r'):
    print(s)
input()
