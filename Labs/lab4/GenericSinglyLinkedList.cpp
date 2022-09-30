#include <iostream>
using namespace std;

template <typename E>
class SLinkedList; // forward declare the class

template <typename E>
class SNode
{ // singly linked list node
private:
    E elem;                      // linked list element value
    SNode<E> *next;              // next item in the list
    friend class SLinkedList<E>; // provide SLinkedList access
};

template <typename E>
class SLinkedList
{ // a singly linked list
public:
    SLinkedList();                     // empty list constructor
    ~SLinkedList();                    // destructor
    bool empty() const;                // is list empty?
    const E &front() const;            // return front element
    void addFront(const E &e);         // add to front of list
    void removeFront();                // remove front item list
    void traverse();                   // traverse the list
    SNode<E> *search(const E &e);      // searches for the given elem in the list
    void swap(const E &a, const E &b); // swap the nodes representing the given elems.
private:
    SNode<E> *head; // head of the list

    bool isEqual(const E &a, const E &b); // checks whether the two generic types are equal or not.
};

template <typename E>
SLinkedList<E>::SLinkedList() // constructor
    : head(NULL)
{
}

template <typename E>
bool SLinkedList<E>::empty() const // is list empty?
{
    return head == NULL;
}

template <typename E>
const E &SLinkedList<E>::front() const // return front element
{
    return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList() // destructor
{
    while (!empty())
        removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E &e)
{                               // add to front of list
    SNode<E> *v = new SNode<E>; // create new node
    v->elem = e;                // store data
    v->next = head;             // head now follows v
    head = v;                   // v is now the head
}

template <typename E>
void SLinkedList<E>::removeFront()
{                         // remove front item
    SNode<E> *old = head; // save current head
    head = old->next;     // skip over old head
    delete old;           // delete the old head
}

template <typename E>
void SLinkedList<E>::traverse()
{
    SNode<E> *temp = head;
    while (temp != NULL)
    {
        cout << temp->elem << " ";
        temp = temp->next;
    }
    cout << endl;
}

// search for a given element in the singly linked list
// returns the pointer to the node containing that item
// or NULL if such a node does not exist.
template <typename E>
SNode<E> *SLinkedList<E>::search(const E &e)
{
    for (SNode<E> *curr = head; curr != NULL; curr = curr->next)
    {
        // if this is the node containing the given element,
        // return the pointer to that node.
        // ..... code here ................................. Task 1
        //const E &c = curr->elem;
        if(isEqual(curr->elem, e)) return curr;
    }
    return NULL; // not found
}

// utility method to compare two given elements of generic type.
template <typename E>
bool SLinkedList<E>::isEqual(const E &a, const E &b)
{
    return ((string)a).compare((string)b) == 0;
}

// Solution to C-3.10
// utility method to swap two nodes in a singly linked list
// NOTE: You should swap the nodes of the linked list.
// simply swapping (replacing) the dataItems will not give you any marks.
template <typename E>
void SLinkedList<E>::swap(const E &a, const E &b)
{
    // first search for element 'a' in the list.
    SNode<E> *node1 = search(a);

    if (node1 == NULL)
        return;

    // next, search for element 'b'
    SNode<E> *node2 = search(b);

    if (node2 == NULL)
        return;

    SNode<E> *prevNode1 = NULL; // pointer to the previous node of [node1]
    SNode<E> *prevNode2 = NULL; // pointer to the previous node of [node2]

    // find previous node of node1 and update prevNode1 pointer
    for (SNode<E> *curr = head; curr != node1; curr = curr->next)
        prevNode1 = curr;

    // find previous node of node2 and update prevNode2 pointer
    // ..... code here .................................. Task 2
    for (SNode<E> *curr = head; curr != node2; curr = curr->next)
        prevNode2 = curr;
   
    // first, we need to fix head pointer
    if (head == node1 || head == node2)
    {
        if (head == node1)
            head = node2;
        else
            head = node1;
    }

    // Handling the case:-
    // head -> ... -> node1 -> node2 -> ... -> NULL
    if (prevNode2 == node1)
    {
        node1->next = node2->next;
        node2->next = node1;
        if (prevNode1 != NULL)
            prevNode1->next = node2;
        return;
    }

    // Handling the case:-
    // head -> ... -> node2 -> node1 -> ... -> NULL
    // .... code here .................................. Task 3
    if (prevNode1 == node2)
    {
        node2->next = node1->next;
        node1->next = node2;
        if (prevNode2 != NULL)
            prevNode2->next = node1;
        return;
    }
   
    // Hold the next pointer of [node1]
    SNode<E> *nextNode1 = node1->next;

    // next pointer of [node1] points to
    // the next pointer of [node2]
    // ..... code here .................................. Task 4
    if(node1 != NULL)
        node1->next = node2->next;
    // next pointer of [node2] points to [nextNode1]
    // ..... code here ................................... Task 5
    if(node2 != NULL)
        node2->next = nextNode1;
   
    // next pointer of [prevNode1] points to [node2]
    if (prevNode1 != NULL)
        prevNode1->next = node2;
    // next pointer of [prevNode2] points to [node1]
    if (prevNode2 != NULL)
        prevNode2->next = node1;
}

void printChoices()
{
    cout << "+----------------------------------------+\n";
    cout << "Please enter one of the following choices:\n";
    cout << "1 : Add at the front\n";
    cout << "2 : Get frontmost element\n";
    cout << "3 : Remove front element\n";
    cout << "4 : Check if list is empty\n";
    cout << "5 : Traverse the list\n";
    cout << "6 : Search for an element\n";
    cout << "7 : Swap two nodes\n";
    cout << "8 : Exit\n";
}

int main()
{
    SLinkedList<string> sl;
    string a, b;
    int choice;
    while (1)
    {
        printChoices();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> a;
            sl.addFront(a);
            break;
        case 2:
            cout << "Frontmost element is : " << sl.front() << endl;
            break;
        case 3:
            cout << "Removing from the front\n";
            sl.removeFront();
            break;
        case 4:
            cout << "List is " << (sl.empty() ? "" : "not") << " empty\n";
            break;
        case 5:
            cout << "Traversing the list : ";
            sl.traverse();
            break;
        case 6:
            cout << "Enter the element to search: ";
            cin >> a;
            if (sl.search(a) != NULL)
                cout << a << " is present in the list." << endl;
            else
                cout << a << " is NOT present in the list." << endl;
            break;
        case 7:
            cout << "Enter the first element: ";
            cin >> a;
            cout << "Enter the second element: ";
            cin >> b;
            sl.swap(a, b);
            break;
        case 8:
            cout << "Exiting";
            exit(1);
            break;
        default:
            cout << "Not a valid entry!\n";
            break;
        }
    }
    return 0;
}