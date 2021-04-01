#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node 
{
    int data;
    struct Node* next;
};

typedef struct Node *node;

void display(struct Node* p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    // node head = NULL;
    // node second = NULL;
    // node third = NULL;

    node head = (node)malloc(sizeof(struct Node));
    node second = (node)malloc(sizeof(struct Node));
    node third = (node)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    display(head);

    return 0;
}
