animals = ['dog', 'cat', 'lion', 'whale']
attributes = ['company', 'pet', 'hunter', 'diver']
counter = 0

for animal in animals:
    print(f"{animal.title()} would be a great {attributes[counter]}.")
    counter = counter + 1
    #Here I am looking for a nested for, but right now I don't have the knowledge to use it
print(f"{animals} are all mamals.")
    