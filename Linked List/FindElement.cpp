#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node 
{
    int data;
    struct Node *next;
};

typedef struct Node * node;

node CreateNode(int new_data)
{
    node temp;
    temp = (node)malloc(sizeof(struct Node));
    temp->data = new_data;
    temp->next = NULL;
    return temp;
}

bool findItem(node head, int key)
{
    if(head == NULL)
        return false;
    else
    {
        node q;
        while (q->next != NULL)
        {
            if(q->data == key)
                return true;
            q = q->next;
        }
        return false;
    }
    
}

void push(node *head, int new_data)
{
    node temp = CreateNode(new_data);
    temp->data = new_data;
    temp->next = *head;
    *head = temp;
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
    system("cls");
    node head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 5);
    push(&head, 3);
    push(&head, 4);
    push(&head, 9);
    inds(head);
    // if (findItem(head, 8) == true)
    //     cout << endl << "yes";
    // else
    //     cout << endl << "no";

    findItem(head, 9) ? cout << "yes" : cout << "no";
    
    return 0;
}
