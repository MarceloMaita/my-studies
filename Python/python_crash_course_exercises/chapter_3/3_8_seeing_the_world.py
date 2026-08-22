places = ['New York', 'Boston', 'Dublin', 'Edimburgh', 'Belfast', 'Berlin', 'Cherbourg']

print(places)

print(sorted(places))
print(f"My list is still in its original order: {places}")
print("Now the list in its reverse alphabetical order:")
print(sorted(places, reverse=True))
print(f"The list is still in its original order: {places}")
places.reverse()
print(places)
places.reverse()
print(places)
places.sort()
print(places)
places.sort(reverse=True)
print(places)
