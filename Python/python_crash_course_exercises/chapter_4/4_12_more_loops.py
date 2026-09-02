my_foods = ["pizza", "falafel", "carrot cake"]
friend_foods = my_foods[:]  # This creates a copy of the list
print("My favorite foods are:")
for food in my_foods:
    print(f"- {food.title()}")

print("\nMy friend's favorite foods are:")
for food in friend_foods:
    print(f"- {food.title()}")

my_foods.append("cannoli")
friend_foods.append("ice cream")
print("\nMy favorite foods are:")
for food in my_foods[:]:
    print(f"- {food.title()}")
print("\nMy friend's favorite foods are:")
for food in friend_foods[:3]:
    print(f"- {food.title()}")
print(friend_foods)
