"""
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

motorcycles[0] = 'ducati'
print(motorcycles)


motorcycles.append('ducati')
print(motorcycles)

motorcycles_2 = []
motorcycles_2.append('honda')
motorcycles_2.append('yamaha')
motorcycles_2.append('suzuki')
print(motorcycles_2)

print(f"motorcycles_2: {motorcycles_2}")

del motorcycles_2[1]
print(f"motorcycles_2 after deletion: {motorcycles_2}")

popped_motorcycle = motorcycles_2.pop()
print(f"motorcycles_2 after popping: {motorcycles_2}")
print(f"Popped motorcycle: {popped_motorcycle}")
"""

motorcycles = ['honda', 'yamaha', 'suzuki']

last_owned = motorcycles.pop()
first_owned = motorcycles[0]
print(f"The last motorcycle I owned was a {last_owned.title()}.")
print(f"The first motorcycle I owned was a {first_owned.title()}.")

motorcycles.append('ducati')

print(motorcycles)
too_expensive = 'ducati'
motorcycles.remove(too_expensive)
#motorcycles.remove('ducati')
print(motorcycles)
print(f"\nA {too_expensive.title()} is too expensive for me.")