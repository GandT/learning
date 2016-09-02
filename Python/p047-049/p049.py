def absolute(arg):
    if type(arg) == int or type(arg) == float:
        return abs(arg)
    else:
        return "Nope"

print absolute(143)
print absolute(-143)
print absolute(-143.23)
print absolute("143.231")

