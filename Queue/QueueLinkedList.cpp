#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *node;

node front = NULL, rear = NULL;

node createNode(int x)
{
    node temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void Enqueue(int x)
{
    node temp = createNode(x);
    if(front == NULL && rear == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }   
}

void Dequeue()
{
    node temp = front;
    if(front == NULL && rear == NULL)
        return;
    else if (front == rear)
        front = rear = NULL;
    else    
        front = front->next;
    free(temp);
}

void Queue()
{
    if (front == NULL)
    {
        cout << "Is empty!";
        return;
    }
    cout << front->data << " ";
}
int main()
{
    system("cls");
    Enqueue(5);
    Enqueue(6);
    Enqueue(8);
    Dequeue();
    Dequeue();
    Queue();
    Dequeue();
    Queue();
}