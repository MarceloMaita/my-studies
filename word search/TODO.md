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
- [X] Export the grid to a text file (write on a .txt file)
- [ ] Load words from a .txt file and write in the matrix.

## 🧹 Improvements / Refactoring
- [X] Organize functions into separate `.c` and `.h` files
- [ ] Add error handling (e.g., invalid input, file not found)
- [ ] Improve random word placement algorithm

```markdown
# TODO – Word Search Project (refined)

This file lists clear tasks, bug fixes and improvements organized so you can apply and test them one at a time.

## ✅ Critical fixes (apply first)
- [ ] Initialize the matrix in `main()` with spaces (`memset(matrix, ' ', sizeof matrix)`) and include `<string.h>`
- [ ] Call `srand((unsigned)time(NULL))` in `main()` to seed `rand()` (include `<time.h>`)
- [ ] Fix `filling_the_second_diagonal`: use `matrix[i][N-1-i] = 'C';` to avoid out-of-bounds access
- [ ] Replace `scanf("%s", ...)` with safe reads (e.g. `scanf("%19s", word)` or `fgets`) — prevent buffer overflow
- [ ] In `filling_the_matrix`: ensure consistent behavior (initialize before testing `== ' '` or fill all cells when random option is chosen)
- [ ] In `writing_from_a_file`: return immediately if `fopen` fails and implement the logic that places words into the `matrix` using `is_safe`

## 🛠️ Robustness & validation
- [ ] Validate user inputs in `get_position()` (ensure `0 <= pos < N` and re-prompt until valid)
- [ ] Check return values of `scanf` / `fgets` everywhere and handle EOF/errors
- [ ] Remove or guard debug prints in `is_safe` (use a `debug` flag)

## ♻️ `is_safe` behavior and writing policy
- [ ] Ensure `is_safe` receives the correct `word_length` (use the full length, not `count-1`)
- [ ] Make sure `is_safe` returns `1` when safe and `0` when not; document the function contract (inputs/outputs)
- [ ] Decide and test overlap policy: allow overlap only when letters match (if that is the chosen policy)

## 🧪 Tests & verification
- [ ] Create a small set of manual test cases to validate:
        - Insert a horizontal word that fits (edge and center)
        - Insert a vertical word that fits
        - Insert a diagonal word that fits
        - Insert a word that exceeds bounds
        - Insert a word that collides with different letters
- [ ] Add a `run_quick_tests()` helper (an executable that runs functions with known inputs and prints PASS/FAIL)

## 🧹 Repository cleanup (already addressed)
- [x] Add `.DS_Store` to `.gitignore`
- [x] Remove tracked `.DS_Store` from the index (`git rm --cached ...`) — committed/pushed
- [ ] Add patterns to avoid committing executables (e.g. `/fibonacci/fibonacci`, `/is_prime/is_prime`, etc.)

## 📁 Code organization & docs
- [ ] Split declarations and implementations into `word_search.h` / `word_search.c` if not done yet
- [ ] Write `README.md` with build/run instructions and `.gitignore` rules

## ✅ Optional tasks (after critical fixes)
- [ ] Implement reading and automatic placement of words from `words_to_be_written.txt` (use `is_safe` and try random positions)
- [ ] Improve the random-fill algorithm to avoid accidentally forming real words

## ℹ️ Quick notes
- Language: **C**
- Recommended compiler flags: `gcc -Wall -Wextra`
- Useful commands:
    ```bash
    gcc "word search/word_search.c" -o "word search/word_search" -Wall -Wextra
    cd "word search" && ./word_search
    ```

``` 