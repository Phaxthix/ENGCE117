#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Next;
    struct Node *Back;
} typedef N;

void AddNode(N **, int);
void InsertNode(N **, int, int);
void DeleteNode(N **, int);
void SwapNode(N **, int, int);
void ShowFront(N **);
void ShowBack(N **);

int main() {
    N *start = NULL;
    int data, pos1, pos2;

    printf("Add (data): "); scanf("%d", &data); AddNode(&start, data);
    printf("Add (data): "); scanf("%d", &data); AddNode(&start, data);
    printf("Add (data): "); scanf("%d", &data); AddNode(&start, data);
    ShowFront(&start); ShowBack(&start);

    printf("Insert (data, pos): "); scanf("%d %d", &data, &pos1); InsertNode(&start, data, pos1);
    printf("Insert (data, pos): "); scanf("%d %d", &data, &pos1); InsertNode(&start, data, pos1);
    printf("Insert (data, pos): "); scanf("%d %d", &data, &pos1); InsertNode(&start, data, pos1);
    ShowFront(&start);

    printf("DeleteNode (pos): "); scanf("%d", &pos1); DeleteNode(&start, pos1);
    printf("DeleteNode (pos): "); scanf("%d", &pos1); DeleteNode(&start, pos1);
    ShowFront(&start);

    printf("SwapNode (pos1 pos2): "); scanf("%d %d", &pos1, &pos2);
    SwapNode(&start, pos1, pos2);
    ShowFront(&start);

    return 0;
}

void AddNode(N **Walk, int Data) {
    N *temp = NULL;
    while (*Walk != NULL) {
        temp = *Walk;
        Walk = &(*Walk)->Next;
    }
    
    *Walk = (N *)malloc(sizeof(N));
    (*Walk)->Data = Data;
    (*Walk)->Next = NULL;
    (*Walk)->Back = temp;

    if (temp) temp->Next = *Walk;
}

void ShowFront(N **Walk) {
    N *current = *Walk;
    printf("Show Front: ");
    while (current != NULL) {
        printf("%d ", current->Data);
        current = current->Next;
    }
    printf("\n");
}

void ShowBack(N **Walk) {
    N *current = *Walk;
    if (!current) return;

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

void InsertNode(N **Walk, int Data, int position) {
    N *temp = (N *)malloc(sizeof(N));
    temp->Data = Data;
    temp->Next = NULL;
    temp->Back = NULL;

    if (position == 1) {  
        temp->Next = *Walk;
        if (*Walk) (*Walk)->Back = temp;
        *Walk = temp;
        return;
    }

    N *current = *Walk;
    int currentPosition = 1;
    while (current != NULL && currentPosition < position - 1) {
        current = current->Next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position!\n");
        free(temp);
        return;
    }

    temp->Next = current->Next;
    temp->Back = current;

    if (current->Next) current->Next->Back = temp;
    current->Next = temp;
}

void DeleteNode(N **Walk, int position) {
    if (*Walk == NULL) {
        printf("List is empty!\n");
        return;
    }

    N *current = *Walk;
    int currentPosition = 1;
    while (current != NULL && currentPosition < position) {
        current = current->Next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position!\n");
        return;
    }

    if (current->Back == NULL) {
        *Walk = current->Next;
        if (current->Next) current->Next->Back = NULL;
    } else if (current->Next == NULL) {
        current->Back->Next = NULL;
    } else {
        current->Back->Next = current->Next;
        current->Next->Back = current->Back;
    }

    free(current);
}

void SwapNode(N **Walk, int position1, int position2) {
    if (position1 == position2) return;

    N *start = *Walk, *node_one = NULL, *node_two = NULL;
    int pos = 1;

    while (start != NULL) {
        if (pos == position1) node_one = start;
        if (pos == position2) node_two = start;
        start = start->Next;
        pos++;
    }

    if (node_one == NULL || node_two == NULL) {
        printf("Invalid positions!\n");
        return;
    }

    int temp = node_one->Data;
    node_one->Data = node_two->Data;
    node_two->Data = temp;
}