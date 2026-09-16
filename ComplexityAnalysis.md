# Complexity Analysis

# Reservation Insertion is O(n) because when a new reservation is added to the end of the linked list, the program has to go through the list until it reaches the last node. As the number of reservations increases, the amount of time it takes to reach the end can also increase. 

# Reservation removal is O(n) because the program might have to search through the linked list to find the reservation that needs to be cancelled. In the worst case, the reservation could be at the end of the list or not in the list at all, so every node may need to be checked. 

# Waiting-list processing is currently O(n) because the waiting list uses the linked list implementation. Adding a student to the end of the list requires moving through the list until the last node is found. Removing a student can also require searching through the list. This can change if the waiting list is later implemented as a true queue with direct access to the front and back. 

# Undo cancellation is O(1) because the cancellation history uses a stack. A stack removes the most recently added item from the top, so the program does not have to search through the other cancelled reservations. 
