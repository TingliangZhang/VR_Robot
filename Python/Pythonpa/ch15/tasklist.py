import os, re
def tasklist():
    #tasklist /nh
    #System Idle Process              0 Services                   0         20 K
    regex_task = re.compile(r'([\w.]+(?: [\w.]+)*)\s\s+(\d+) \w+\s\s+\d+\s\s+([\d,]+ K)')
    with os.popen('tasklist /nh', 'r') as f:
        for line in f:
            print(regex_task.findall(line.strip()))
if __name__=='__main__':
    tasklist()
