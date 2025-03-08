#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Next;
};
typedef struct Node N;

void AddNode(N **, int Data);
void InsertNode(N **, int Data, int position);
void DeleteNode(N **, int position);
void ShowNode(N *);

int main() {
    N *start = NULL;
    int data = 0, pos = 0;
    
    printf("Add (data): "); scanf("%d", &data); AddNode(&start, data);
    printf("Add (data): "); scanf("%d", &data); AddNode(&start, data);
    printf("Add (data): "); scanf("%d", &data); AddNode(&start, data);
    ShowNode(start);

    printf("Insert (data, pos): "); scanf("%d %d", &data, &pos); InsertNode(&start, data, pos);
    printf("Insert (data, pos): "); scanf("%d %d", &data, &pos); InsertNode(&start, data, pos);
    printf("Insert (data, pos): "); scanf("%d %d", &data, &pos); InsertNode(&start, data, pos);
    ShowNode(start);

    printf("Delete (pos): "); scanf("%d", &pos); DeleteNode(&start, pos);
    printf("Delete (pos): "); scanf("%d", &pos); DeleteNode(&start, pos);
    printf("Delete (pos): "); scanf("%d", &pos); DeleteNode(&start, pos);
    ShowNode(start);

    return 0;
}

void AddNode(N **Walk, int Data) {
    N *newNode = (N *)malloc(sizeof(N));
    newNode->Data = Data;
    newNode->Next = NULL;

    if (*Walk == NULL) {
        *Walk = newNode;
    } else {
        N *temp = *Walk;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

void ShowNode(N *Walk) {
    while (Walk != NULL) {
        printf("%d ", Walk->Data);
        Walk = Walk->Next;
    }
    printf("\n");
}

void InsertNode(N **Walk, int Data, int position) {
    N *newNode = (N *)malloc(sizeof(N));
    newNode->Data = Data;
    
    if (position == 1) {
        newNode->Next = *Walk;
        *Walk = newNode;
    } else {
        N *temp = *Walk;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->Next;
        }

        if (temp == NULL) {
            printf("Invalid position!\n");
            free(newNode);
            return;
        }

        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
}

void DeleteNode(N **Walk, int position) {
    if (*Walk == NULL) {
        printf("List is empty!\n");
        return;
    }

    N *temp = *Walk;

    if (position == 1) {
        *Walk = temp->Next;
        free(temp);
    } else {
        N *prev = NULL;
        for (int i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->Next;
        }

        if (temp == NULL) {
            printf("Invalid position!\n");
            return;
        }

        prev->Next = temp->Next;
        free(temp);
    }
}
