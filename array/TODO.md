# TODO

## Arrays

- [X] Creating an Array
- [X] Iterate through Array
- [X] Get an Element
- [X] Search an Element
- [X] Insert Element(s)
    - [ ] Allow insertions that expand the array, adding new numbers, for example
- [X] Delete Element(s)
- [X] Filter an Array
- [X] Fetch a Sub-Array
    -[ ] allow more conditions
- [X] Merging Arrays
- [X] Reverse Array
- [X] Rotate Array


gcc array.c -o array -Wall -Wextra;# Array Program To-Do List

## Safety

- [X] Check if the array was created before using it in every menu option.
- [X] Validate user input after each `scanf`.
- [X] Reject invalid array sizes, like `0` or negative numbers.
- [X] Remove `fflush(stdin)`.
- [X] Compile with warnings enabled:

```sh
gcc -Wall -Wextra -pedantic array.c -o arrays
```

## Indexes

- [ ] Make all position/index rules consistent.
- [ ] Decide if the user enters positions starting at `1` or indexes starting at `0`.
    (considering an user point of view, he will always start in the position 1 and never 0. So, when the user enters "position 1" I must treat it as the first position of the array - In this condition, the number entered by the user must be consider minus one to replicate's it's desire. For example, if the users enters position 1, the code will understand the secondo postion, after 0, so whenever this number is transmitted as a parameter, I must pass it minus one)
        - [ ] pass eny position enter bu the user minus one to be accurate. (I didn't solve it yet)
- [] Fix `fetch_subarray` so it does not skip the first selected element.
- [ ] Pass `array_size` to `fetch_subarray`.
- [ ] Check that subarray indexes do not go past the end of the array.

## Array Operations

- [ ] Decide if `insert_element` should replace or truly insert.
- [ ] If it only replaces, rename it to `replace_element`.
- [ ] If it truly inserts, use `realloc` and shift elements right.
- [ ] Make `delete_element` actually delete by shifting elements left.
- [ ] Update `array_size` after real insertions and deletions.
- [ ] Make `rotate_array` handle displacements bigger than the array size.
- [ ] Decide if `rotate_array` should only print or actually modify the array.

## Code Clean-Up

- [X] Add a missing `break` after `case 11`.
- [X] Remove the extra stray semicolon after the function declarations.
- [ ] Keep function names honest about what they do.
- [ ] Avoid repeating the same validation logic too much.
- [ ] Consider creating a helper function to read integers safely.

## Good Next Order

- [ ] First: add array existence checks.
- [ ] Second: fix `fetch_subarray`.
- [ ] Third: clean up insert/delete behavior.
- [ ] Fourth: improve rotation.
- [ ] Fifth: add safer input handling.
- [ ] Last: compile with warnings and fix them one by one.
