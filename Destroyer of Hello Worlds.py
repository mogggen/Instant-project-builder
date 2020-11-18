import os
s = "!}{?"
while(1):
    input(os.getcwd() + s)
    command  = "echo \"" + s + "\"" + " >> " + "\"FFFF FFFF FFFF FFFF\""
    print(command)
    os.system(command)
    input("are you sure about that?")
    
