#coding: UTF-8

ans = "ぴええ"

def piee():
    if ans == "ぴええ":
        return True
    else:             
        return False

def pieee():
    if ans == "ぴえええ":
        return True
    else:             
        return False

def pieepiee():
	if ans == "ぴええぴええ":
		return True
	else:
		return False


print ans
print "ぴええ→" + str(piee())
print "ぴえええ→" + str(pieee())
print "ぴええぴええ→" + str(pieepiee())

