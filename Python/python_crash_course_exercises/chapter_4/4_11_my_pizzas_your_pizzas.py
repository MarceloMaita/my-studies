pizzas = ['tuna fish', 'mozzarela', 'pepperoni', 'napolitan']
friends_pizzas = pizzas[:]
pizzas.append('chicken')
friends_pizzas.append('veggie')
print("My favorite pizzas are:")
for pizza in pizzas:
    print(f"- {pizza.title()}")
print("\nMy friend's favorite pizzas are:")
for pizza in friends_pizzas:
    print(f"- {pizza.title()}")