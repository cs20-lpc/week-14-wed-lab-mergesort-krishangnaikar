#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* sortedMerge(Node* a, Node* b)
{
    // Base cases
    if (a == NULL) return b;
    if (b == NULL) return a;

    // Merge two sorted linked lists recursively
    if (a->data <= b->data)
    {
        a->next = sortedMerge(a->next, b);
        return a;
    }
    else
    {
        b->next = sortedMerge(a, b->next);
        return b;
    }
}

void splitList(Node* source, Node*& front, Node*& back)
{
    // Use slow/fast pointer method to find the midpoint
    Node* slow = source;
    Node* fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Split list into two halves
    front = source;
    back = slow->next;
    slow->next = NULL;
}

void mergeSort(Node*& head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* a;
    Node* b;

    // Split list
    splitList(head, a, b);

    // Recursively sort both halves
    mergeSort(a);
    mergeSort(b);

    // Merge sorted lists
    head = sortedMerge(a, b);
}

int main()
{
    Node* head = NULL;

    int values[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};

    for (int i = 0; i < 10; i++)
        insertEnd(head, values[i]);

    cout << "Before Sorting: ";
    display(head);

    mergeSort(head);

    cout << "After Sorting: ";
    display(head);

    return 0;
}
