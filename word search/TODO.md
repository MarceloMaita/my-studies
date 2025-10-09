# TODO – Word Search Project

## 🚀 Features to Implement
- [X] Creates a MENU to choose what function to call
- [X] Makes the menu running until the user says to stop
- [X] Generate the word search grid
- [X] Place words in different directions:
    - [X] horizontal
        - [X] at a given position
    - [X] vertical
        - [X] at a given position
    - [X] diagonal
        - [X] at a given position
- [X] Fill empty spaces with random letters
    - [X] check if is safe to write a letter in one place for each letter and each place before write it
    - [X] fill with randon letters after the words already in the matrix - change the function to do it first
- [X] initialize the matrix with empty places only
- [X] Print the grid to the screen
- [X] Allows the user to insert their own words
- [ ] Export the grid to a text file (write on a .txt file)
- [ ] Load words from a file (a text file?)

## 🧹 Improvements / Refactoring
- [ ] Organize functions into separate `.c` and `.h` files
- [ ] Add error handling (e.g., invalid input, file not found)
- [ ] Improve random word placement algorithm

## 🐞 Bugs / Fixes
- [ ] Check overlapping words don’t overwrite each other (how can I solve that?)
- [ ] Fix alignment issues in grid printing
- [ ] identify possible issues - note all of them here
- [ ] start the matrix with any letter to avoid another issues


## 📝 Notes
- Decide maximum grid size (e.g., 15x15, 20x20)
- Add command-line arguments (e.g., `./wordsearch input.txt`)
## Documentation
- [ ] write README.md

## 💡 Notes
- Language: **C**
- Compiler: `gcc`
- How to run:
  ```bash
  gcc word_search.c -o word_search
  ./word_search