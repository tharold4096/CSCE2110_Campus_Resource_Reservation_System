# Complexity Analysis

##  Reservation Insertion 
Reservation Insertion is O(n) because when a new reservation is added to the end of the linked list, the program has to go through the list until it reaches the last node. As the number of reservations increases, the amount of time it takes to reach the end can also increase. 

## Reservation removal
Reservation removal is O(n) because the program might have to search through the linked list to find the reservation that needs to be cancelled. In the worst case, the reservation could be at the end of the list or not in the list at all, so every node may need to be checked. 

## Waiting-list processing
 Waiting- list processing is currently O(n) because the waiting list uses the linked list implementation. Adding a student to the end of the list requires moving through the list until the last node is found. Removing a student can also require searching through the list. This can change if the waiting list is later implemented as a true queue with direct access to the front and back. 

## Undo cancellation
Undo cancellation is O(1) because the cancellation history uses a stack. A stack removes the most recently added item from the top, so the program does not have to search through the other cancelled reservations. 

## Binary Search
Binary search is O(log n) because the algorithm checks the middle resource's ID and eliminates half of the remaining resources after each comparison. The best case is O(1) when the resource is found on the first check. The average and worst cases are O(log n) because the number of resources to search is reduced by half each time. The space complexity is O(1) because the algorithm only uses a few variables, such as left, right, and mid. Binary search requires the resources to be sorted by ID before searching.