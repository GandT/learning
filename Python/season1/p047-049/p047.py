def shut_down(s):
    if s == "yes":
        return "Shutting down"
    elif s == "no":
        return "Shutdown aborted"
    else:
        return "Sorry"

string = raw_input(" Shutdown? > ")
print shut_down(string)
