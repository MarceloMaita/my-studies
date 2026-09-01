"""
def countdown(i):
    print(i)
    if i <= 0:
        return
    else:
        countdown(i - 1)

print(countdown(5))"""

#The call stack
"""
def greet(name):
    print("Hello, " + name + "!")
    greet2(name)
    print("Getting ready to say bye...")
    bye()

def greet2(name):
    print("How are you, " + name + "?")

def bye():
    print("Ok bye!")

print(greet("Maita"))"""

#the factorial function

def fact(x):
    if x == 1:
        return 1
    else:
        return x * fact(x-1)

print(fact(3))