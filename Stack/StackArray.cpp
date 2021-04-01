#include <iostream>
#include <stdlib.h>

using namespace std;

int top = -1;
int temp;
bool isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

void push(int S[], int x, int size)
{
    if (top >= size - 1)
    {
        cout <<  "Stack is Full! " << x << " isn't added to the stack" << endl;
        return;
    }
    top++;
    S[top] = x;
    cout << x << " added successfully" << endl;
}

void pop(int S[])
{
    
    if(isEmpty() == true)
    {
        cout << "Stack is empty! ";
        return;
    }
    temp = S[top];
    top--;
}

void display()
{
    cout << temp << " ";
}

int main()
{
    system("cls");
    int S[10], size = 3;
    push(S, 6, size);
    push(S, 2, size);
    push(S, 3, size);
    push(S, 1, size);
    push(S, 5, size); 
    pop(S);
    display();
    pop(S);
    display();
    pop(S);
    display();
    return 0;
}