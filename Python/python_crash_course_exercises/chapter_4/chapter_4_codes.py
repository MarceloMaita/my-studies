#Slicing a list
"""players = ["charles", "martina", "michael", "florence", "eli"]
print(players[0:3])  # ['charles', 'martina', 'michael']
print(players[1:4])  # ['martina', 'michael', 'florence']
print(players[:4])   # ['charles', 'martina', 'michael', 'florence']
print(players[2:])   # ['michael', 'florence', 'eli']
print(players[-3:])  # ['michael', 'florence', 'eli']

print("\n")
for player in players[:3]:
    print(player.title())"""

#copying a list
"""my_foods = ["pizza", "falafel", "carrot cake"]
friend_foods = my_foods[:]  # This creates a copy of the list
print("My favorite foods are:")
print(my_foods)
print("\nMy friend's favorite foods are:")
print(friend_foods)

my_foods.append("cannoli")
friend_foods.append("ice cream")
print("\nMy favorite foods are:")
print(my_foods)
print("\nMy friend's favorite foods are:")
print(friend_foods)"""

#tuples 
dimensions = (200, 50)
print(dimensions[0])  # 200
print(dimensions[1])  # 50

my_t = (3,)
print(my_t[0])  # 3

print("original dimensions:")
for dimension in dimensions:
    print(dimension)
dimensions = (400, 100)
print("\nmodified dimensions:")
for dimension in dimensions:
    print(dimension)
