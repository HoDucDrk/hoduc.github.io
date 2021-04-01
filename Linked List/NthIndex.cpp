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

node CreateNode(int new_data)
{
    node temp = (node)malloc(sizeof(struct Node));
    temp->data = new_data;
    temp->next = NULL;
    return temp;
}

void push(node *head, int new_data)
{
    node temp = CreateNode(new_data);
    temp->next = *head;
    *head = temp;
}

void Nthnode(node head, int key_index)
{
    int count = 0;
    while (head != NULL)
    {
        if (count == key_index)
        {
            cout << endl << head->data;
            return;
        }
        count++;
        head = head->next;
    }
    
}

void inds(node p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    
}

int main(int argc, char const *argv[])
{
    node head = NULL;
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 1);
    push(&head, 45);
    inds(head);
    Nthnode(head, 3);
    cout << "\nThe node at index 2 is: ";
    Nthnode(head, 2);
    return 0;
}

