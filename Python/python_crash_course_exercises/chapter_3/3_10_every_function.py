places = ['New York', 'São Paulo', 'Buenos aires', 'Cairo', 'London', 'Montevideo']
monuments = ['empire state building', 'masp', 'obelisc', 'pyramids', 'big ben', 'centenary stadium']

print(f"The {monuments[0].title()} is located in {places[0]}.")
print(f"The {monuments[1].upper()} is located in {places[1]}.")
print(f"The {monuments[2].title()} is located in {places[2]}.")
print(f"The {monuments[3].title()} is located in places[3].")
print(f"The {monuments[4].title()} is located in places[4].")
print(f"The {monuments[5].title()} is located in places[5].")

monuments[0] = monuments[0].title()
monuments[1] = monuments[1].upper()
monuments[2] = monuments[2].title()
monuments[3] = monuments[3].title()
monuments[4] = monuments[4].title()



print(f"Here is a list of places I want to visit {places}.")
print(f"to see all these interesting buildings {monuments}.")
print(f"I can not wait to see all the {len(monuments)} places")
print(f"One way to enjoy the travel is follow one order to travel. Could be alphabetically: {sorted(places)}.")
monuments.sort(reverse=True)
print(f"And other way could be simply by picking the places in the reverse mode thar they came to my mind: {monuments}.")

favorite_city = places.pop(1)

print(f"but one place is special to me: {favorite_city}.")
