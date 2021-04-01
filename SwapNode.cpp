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


void display(node p)
{
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// void swapNode(node head,int x,int y)
// {
//     if(x == y)
//         return;
//     node p = head, p1, x1;
//     node q = head, q1, y1;
//     while (p->next->data != x)
//     {
//         p = p->next;
//     }
//     p1 = p->next->next;
//     x1 = p->next;
//     while (q->next->data != y)
//     {
//         q = q->next;
//     }
//     q1 = q->next->next;
//     y1 = q->next;
//     p->next = y1;
//     y1->next = p1;
//     q->next = x1;
//     x1->next = q1;  
// }

void swapNode(node *head_ref, int x, int y)
{
    if(x == y)
        return;
    node prevX = NULL, currX = *head_ref;
    while(currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }
    node prevY = NULL, currY = *head_ref;
    while(currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;
    if(prevX != NULL)
        prevX->next = currY;
    else    
        *head_ref = currY;
    if(prevY != NULL)
        prevY->next = currX;
    else    
        *head_ref = currX;
    node temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
int main(int argc, char const *argv[])
{
    system("cls");
    node head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 9);
    push(&head, 5);

    cout << "Created Linked List: ";
    display(head);

    swapNode(&head, 5, 3);
    cout << "\nSwap list: ";
    display(head);
    return 0;
}