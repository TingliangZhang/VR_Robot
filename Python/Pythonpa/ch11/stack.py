class Stack:  
    def __init__(self,size = 16):  #初始化栈
        self.stack = []  
    def push(self,obj):         #入栈操作（push）
        self.stack.append(obj)  
    def pop(self):            #出栈操作（pop）
        try:  
            return self.stack.pop()
        except IndexError as e:
            print("stack is empty")  
    def __str__(self):
        return str(self.stack)
def main():
    stack = Stack()     #创建并初始化栈
    stack.push(1)      #整数1入栈
    stack.push(2)      #整数2入栈
    print(stack)        #打印栈的内容
    stack.pop()         #整数2出栈
    stack.pop()         #整数1出栈
    stack.pop()        #出栈操作，但是因为是空栈，提示"stack is empty"
if __name__ == '__main__': main()

