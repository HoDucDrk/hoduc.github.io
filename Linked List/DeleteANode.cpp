#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct DeleteANode
{
    int data;
    struct DeleteANode *next;
};

typedef struct DeleteANode *node;

void push(node *head_ref, int new_data)
{
    node new_node = (node)malloc(sizeof(struct DeleteANode));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(node *head_ref, int key)
{
    node temp = *head_ref, prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void display(node p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    
}

int main(int argc, char const *argv[])
{
    system("cls");
    node head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    cout << "Created Linked List: ";
    display(head);
    deleteNode(&head, 8);
    cout << "\nLinked List after Deletion of 1: ";
    display(head);
    return 0;
}
