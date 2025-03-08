#include <stdio.h>

class Node {
public:
    int Data;
    Node *Next;
    Node *Back;

    Node(int data = 0) : Data(data), Next(NULL), Back(NULL) {}
};

class DoubleLinkedList {
private:
    Node *head;

public:
    DoubleLinkedList() : head(NULL) {}

    void AddNode();
    void InsertNode();
    void DeleteNode();
    void ShowFront();
    void ShowBack();
};

int main() {
    DoubleLinkedList A, B;

    // Adding Nodes to the list
    A.AddNode();
    A.AddNode();
    A.ShowFront();  // Showing the list from the front

    // Inserting Nodes into specific positions
    A.InsertNode();
    A.InsertNode();
    A.ShowFront();  // Showing the list from the front

    // Deleting Nodes from specific positions
    A.DeleteNode();
    A.DeleteNode();
    A.ShowFront();  // Showing the list after deletion

    printf("---\n");

    // Show list from back
    B.AddNode();
    B.AddNode();
    B.AddNode();
    B.ShowBack();  // Showing the list from the back

    return 0;
}

void DoubleLinkedList::ShowBack() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    while (current->Next != NULL) {
        current = current->Next;
    }

    printf("Show Back: ");
    while (current != NULL) {
        printf("%d ", current->Data);
        current = current->Back;
    }
    printf("\n");
}

void DoubleLinkedList::ShowFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    printf("Show Front: ");
    while (current != NULL) {
        printf("%d ", current->Data);
        current = current->Next;
    }
    printf("\n");
}

void DoubleLinkedList::DeleteNode() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    Node *current = head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position) {
        current = current->Next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (current->Back == NULL) { // Deleting the first node
        head = current->Next;
        if (head != NULL) {
            head->Back = NULL;
        }
    } else if (current->Next == NULL) { // Deleting the last node
        current->Back->Next = NULL;
    } else { // Deleting a node in the middle
        current->Back->Next = current->Next;
        current->Next->Back = current->Back;
    }

    delete current; // Free memory
}

void DoubleLinkedList::InsertNode() {
    int data, position;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    Node *temp = new Node(data);

    if (head == NULL || position == 1) { // Insert at the beginning
        temp->Next = head;
        if (head != NULL) {
            head->Back = temp;
        }
        head = temp;
        return;
    }

    Node *current = head;
    int currentPosition = 1;

    while (current->Next != NULL && currentPosition < position - 1) {
        current = current->Next;
        currentPosition++;
    }

    if (current->Next == NULL && currentPosition < position - 1) {
        current->Next = temp;
        temp->Back = current;
        return;
    }

    temp->Next = current->Next;
    temp->Back = current;

    if (current->Next != NULL) {
        current->Next->Back = temp;
    }

    current->Next = temp;
}

void DoubleLinkedList::AddNode() {
    int data;
    printf("Enter data to add: ");
    scanf("%d", &data);

    Node *temp = new Node(data);

    if (head == NULL) {
        head = temp;
        return;
    }

    Node *current = head;
    while (current->Next != NULL) {
        current = current->Next;
    }

    current->Next = temp;
    temp->Back = current;
}