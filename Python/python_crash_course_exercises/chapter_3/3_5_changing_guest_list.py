guest_list = ['Isaac Newton', 'Albert Einstein', 'Marie Curie', 'Stephen Hawking', 'Alan Turing']

treatment = ['Sir', 'Dr.', 'Prof.', 'Mr.', 'Ms.']

place = ['at the Royal Society', 'at the Nobel Prize Ceremony', 'at the Science Conference', 'at the University Lecture', 'at the Tech Summit']

print(f"Dear {treatment[0]} {guest_list[0]}, you are cordially invited to speak {place[0]}.")
print(f"Dear {treatment[1]} {guest_list[1]}, you are cordially invited to speak {place[1]}.")
print(f"Dear {treatment[4]} {guest_list[2]}, you are cordially invited to speak {place[2]}.")
print(f"Dear {treatment[3]} {guest_list[3]}, you are cordially invited to speak {place[3]}.")
print(f"Dear {treatment[3]} {guest_list[4]}, you are cordially invited to speak {place[4]}.")

print(f"\nUnfortunately, it seems that {treatment[3]} {guest_list[3]} cannot attend the event. We will need to find a replacement.")
popped_guest = guest_list.pop(3)

guest_list.insert(3, 'Richard Feynman')

print(f"\nWe have found a replacement for {popped_guest}. {guest_list[3]} will be attending the event instead.")

print(f"\nUpdated guest list:")
print(f"Dear {treatment[0]} {guest_list[0]}, you are cordially invited to speak {place[0]}.")
print(f"Dear {treatment[1]} {guest_list[1]}, you are cordially invited to speak {place[1]}.")
print(f"Dear {treatment[4]} {guest_list[2]}, you are cordially invited to speak {place[2]}.")
print(f"Surely we are not joking, {treatment[3]} {guest_list[3]}, you are cordially invited to speak {place[3]}.")




