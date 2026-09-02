arr = []

def sum(arr):
    total = 0
   
    if len(arr) == 0:
        return total
    #elif len(arr) == 1:
     #   return arr[0]
    else:
        total += arr[0]
        return total + sum(arr[1:]) #First time  I saw this slicing character.

        

print(sum([1, 2, 3, 4, 5]))
#doing the same without using slicing character"
def add(arr, i):
    if i == len(arr):
        return 0

    return arr[i] + add(arr, i + 1)

print(add([1, 2, 3, 4, 5], 0))