f1_drivers_champion = ["Alain Prost", "Ayrton Senna", "Michael Schumacher", "Lewis Hamilton", "Sebastian Vettel"]
championships_won = [4, 3, 7, 7, 4]

print("The first three F1 drivers champion are:")
print(f1_drivers_champion[0:3])  # ['Alain Prost', 'Ayrton Senna', 'Michael Schumacher']
print("\nThe last two F1 drivers champion are:")
print(f1_drivers_champion[-2:])  # ['Lewis Hamilton', 'Sebastian Vettel']
print("\nthe middle three F1 drivers champion are:")
print(f1_drivers_champion[1:4])  # ['Ayrton Senna', 'Michael Schumacher', 'Lewis Hamilton']

print("\nThe championships won by the first three F1 drivers champion are:")
for driver in f1_drivers_champion[:3]:
    print(f"{driver.title()} won {championships_won[f1_drivers_champion.index(driver)]} championships.")