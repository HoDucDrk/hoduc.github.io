#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *node;

void push(node *head_ref, int new_data)
{
    node new_node = (node)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(node prev_node, int new_data)
{
    if(prev_node == NULL) 
    {
        cout << "the given previous node cannot be NULL";
        return;
    }
    node new_node = (node)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append (node *head_ref, int new_data)
{
    node new_node = (node)malloc(sizeof(struct Node));
    node last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void printList(node p)
{
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main(int argc, char const *argv[])
{
    system("cls");
    node head = NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    cout << "\n Created Linked list is: ";
    printList(head);
    
    return 0;
}
