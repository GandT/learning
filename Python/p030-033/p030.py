def iftest1():
    if True:
        return "true @1"

def iftest2():
    if 1 != 2:
        return "true @2"

def iftest3():
	if "piee" == "piee":
		return "true @3"

print iftest1()
print iftest2()
print iftest3()
