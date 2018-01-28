import sys
import turtle
def koch(t, order, size):
        if order == 0:
            t.forward(size)
        else:
            koch(t, order-1, size/3)
            t.left(60.0)
            koch(t, order-1, size/3)
            t.right(120.0)  #t.left(-120.0)
            koch(t, order-1, size/3)
            t.left(60.0)
            koch(t, order-1, size/3)
def main():
        n = 3 #int(sys.argv[1])
        step = 300
        p = turtle.Turtle()
        koch(p, n, step)
if __name__ == '__main__': main()    

