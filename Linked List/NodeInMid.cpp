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
/*
void midItem(node head)
{
    int count = 0;
    node temp = head;
    while(temp != NULL)
    {
        if(temp->next != NULL)
            count++;
        temp = temp->next;
    }
    int mid = count / 2;
    count = 0; temp = head;
    while (temp != NULL)
    {
        if (count == mid)
        {
            cout << temp->data;
            return;
        }
        count++;
        temp = temp->next;
    }
}
*/

// void midItem(struct Node *head)
// {
//     struct Node *slow_ptr = head;
//     struct Node *fast_ptr = head;
 
//     if (head!=NULL)
//     {
//         while (fast_ptr != NULL && fast_ptr->next != NULL)
//         {
//             fast_ptr = fast_ptr->next->next;
//             slow_ptr = slow_ptr->next;
//         }
//         printf("The middle element is [%d]\n\n", slow_ptr->data);
//     }
// }

// void countNumber(node head, int key)
// {
//     int count;
//     node p = head;
//     while(p!= NULL)
//     {
//         if(p->data == key)
//             count++;
//         p = p->next;
//     }
//     printf("number %d is %d:", key, count);
// }
int count = 0;
int LengthHead(node head)
{
    if(head == NULL)
        return count;
    else
    {
        count++;
    }
    return LengthHead(head->next);
}
int countt = 0;
int midItem(node head, int mid)
{   
    if(countt < mid)
        countt++;
    if(countt == mid)
        return head->data;
    return midItem(head->next, mid);
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
\
    cout << "Created Linked List: ";
    display(head);
    int mid = 2;
    // cout << endl << "Item in mid: ";
    // midItem(head);
    // countNumber(head, 1);
    // cout << "\nLength: " << LengthHead(head); 
    cout << endl << mid << endl << midItem(head, mid);
    
    return 0;
}