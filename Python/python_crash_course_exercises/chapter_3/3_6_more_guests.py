#using the code from the exercise 3_5, add three new guests for the dinner party, using insert() to add at the beggining and the middle of the list, and append() to add one at the end of the list. Then print a new set of invitation messages, one for each guest.
guest_list = ['Isaac Newton', 'Albert Einstein', 'Marie Curie', 'Stephen Hawking', 'Alan Turing']

treatment = ['Sir', 'Dr.', 'Prof.', 'Mr.', 'Ms.']
print("I have found a bigger dinner table, so I can invite more guests to the dinner party.")

guest_list.insert(0, 'Nikola Tesla')
guest_list.insert(3, 'Galileo Galilei')
guest_list.append('Ada Lovelace')

print("The new guest list is:")

print(f"We are glad to invite you, {treatment[3]} {guest_list[0]}, to our dinner party" )
print(f"We are glad to invite you, {treatment[0]} {guest_list[1]}, to our dinner party" )
print(f"We are glad to invite you, {treatment[2]} {guest_list[2]}, to our dinner party" )
print(f"We are glad to invite you, {treatment[3]} {guest_list[3]}, to our dinner party" )
print(f"We are glad to invite you, {treatment[4]} {guest_list[4]}, to our dinner party" )
print(f"We are glad to invite you, {treatment[0]} {guest_list[5]}, to our dinner party" )
print(f"We are glad to invite you, {treatment[3]} {guest_list[6]}, to our dinner party" )
print(f"We are glad to invite you, {treatment[4]} {guest_list[7]}, to our dinner party" )

