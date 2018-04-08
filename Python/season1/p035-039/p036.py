#coding: UTF-8

def square(n):
    """Returns the square of a number."""  #どうもこれはコメントとは違うらしい http://www.python-izm.com/contents/basis/comment_out.shtml
    squared = n**2
    print "%d squared is %d." % (n, squared)
    return squared

square(10)

