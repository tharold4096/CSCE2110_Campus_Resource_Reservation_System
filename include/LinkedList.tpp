

//Default constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), list_size=0 {}

//Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head != nullptr)
    {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

//Function to insert new node at beginning
template <typename T>
void LinkedList<T>::insert_at_beginning(const T& value)
{
    head = new Node(value, head);
    list_size++;
}

//Insert function to add a new node to the end of the list
template <typename T>
void LinkedList<T>::insert_at_end(const T& value)
{
    Node* node = new Node(value);

    if (head == nullptr)
    {
        head = node;
        return;
    }

    Node* current = head;
    while (current->next != nullptr)
        current = current->next;

    current->next = node;

    list_size++;
}

//Function to insert node after specific node
template <typename T>
void LinkedList<T>::insert_after(const T& target, const T& value)
{
    Node* current = head;
    while (current != nullptr && !(current->data == target))
        current = current->next;

    if (current == nullptr)
        return;

    current->next = new Node(value, current->next);
    list_size++
}

template <typename T>
bool LinkedList<T>::remove(const T& value)
{
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr && !(current->data == value))
    {
        previous = current;
        current = current->next;
    }

    //Don't remove nonexistent nodes
    if (current == nullptr)
        return false;

    //Find the new head
    if (previous == nullptr)
        head = current->next;
    else
        previous->next = current->next;

    delete current;
    list_size--;
    return true;
}

template <typename T>
void LinkedList<T>::print_list() const
{
    Node* current = head;
    while (current != nullptr)
    {
        current->data.print();
        if (current->next != nullptr)
            cout << " -> ";
        current = current->next;
    }
    cout << '\n';
}



template <typename T>
std::vector<T> LinkedList<T>::get_all() const
{
    std::vector<T> results;
    Node* current = head;
    while (current != nullptr)
    {
        results.push_back(current->data);
        current = current->next;
    }
    return results;
}

template <typename T>
bool LinkedList<T>::remove_front()
{
    if (head == nullptr)
        return false;
    Node* node = head;
    out =node->data;
    head = head->next;
    delete node;
    list_size--;
    return true;
}

template <typename T>
bool LinkedList<T>::is_empty() const
{
    return head == nullptr;
}

template <typename T>
T LinkedList<T>::get_head() const 
{
    return head;
}

template <typename T>

int LinkedList<T>::get_size() const
{
    return list_size;
}
