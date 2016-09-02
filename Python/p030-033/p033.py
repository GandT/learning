#coding: UTF-8

#恒真装置
def ValidMachine():
    if 1 >= 2:		# 1=2の否定
        return True and False
    elif 1 <= 0:	# 1=0の否定
        return False or False
    else:			# 真理(?)
        return not 1 != 1 and 1 == 1


print ValidMachine()
