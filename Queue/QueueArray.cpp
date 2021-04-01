#include <iostream>
#include <stdlib.h>

using namespace std;

int front = -1, rear = -1;

bool isEmpty()
{
    if(front == -1 && rear == -1)
        return true;
    else    
        return false;
}   

void Enqueue(int Q[], int x, int size)
{
    if(rear >= size)
    {
        cout << "The queue is full!";
        return;
    }
    if (isEmpty() == true)
        front = rear = 0;
    else    
        rear++;
    Q[rear] = x;
}

void Dequeue(int Q[])
{
    if(isEmpty() == true)
    {
        cout << "The queue is empty!";
        return;
    }
    else if (front == rear)
        front = rear = -1;
    else
        front++;
}

int Queue(int Q[])
{
    return Q[front];
}

int main()
{
    system("cls");

    int Q[10], size = 4;
    Enqueue(Q, 5, size);
    Enqueue(Q, 1, size);
    Enqueue(Q, 2, size);
    Enqueue(Q, 3, size);
    
    cout << Queue(Q) << " ";
    Dequeue(Q);
    cout << Queue(Q) << " ";
    Dequeue(Q);
    cout << Queue(Q) << " ";
    Dequeue(Q);
}