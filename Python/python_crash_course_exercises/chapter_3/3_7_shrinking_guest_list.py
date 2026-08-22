guest_list = ['Isaac Newton', 'Albert Einstein', 'Marie Curie', 'Stephen Hawking', 'Alan Turing']
treatment = ['Sir', 'Dr.', 'Prof.', 'Mr.', 'Ms.']

print("Sorry, but we can only invite two guests to the dinner party.") 

popped_guest = guest_list.pop()
print(f"Sorry, {treatment[3]} {popped_guest}, but we can't invite you to the dinner party.")

popped_guest = guest_list.pop(2)
print(f"Sorry, {treatment[4]} {popped_guest}, but we can't invite you to the dinner party.")

popped_guest = guest_list.pop(2)
print(f"Sorry, {treatment[0]} {popped_guest}, but we can't invite you to the dinner party.")

print(f"But you, {treatment[0]} {guest_list[0]}, and you, {treatment[2]} {guest_list[1]}, are still invited to the dinner party.")

del guest_list[0]
del guest_list[0]

print(f"The guest list is now empty: {guest_list}")