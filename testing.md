## TEST 1

*Empty system*

What it covered:

- The report has no data, nothing shows up when printed

Test result:

- Clear messages about failing to undo cancellation, reserve resource, across all tests

## TEST 2

*Bad input*

What it covered:

- Strings in the menu, poor date format, numbers out of range, nonexistant resources

Test result:

- All inputs rejected with clear message and returned to menu for retry of prompt

## TEST 3

*Waiting list*

What it covered:

- Queued up reservations with duplicates joining, cancelling queue reservation, undoing after cancel, edge cases

Test results:

- Queue stays in order, reservations move up correctly in the line, cancel blocked when slot already filled. 

## TEST 4

*Undo*

What it covered:

- cancel, then the undoing

Test result:

- Reservation comes back only when nobody waiting, restored to state and popped off cancellation history

## TEST 5

*Input ends early*

WHat it covered:

- exit during the middle of a menu

Results:

- Program exits cleanly. 
