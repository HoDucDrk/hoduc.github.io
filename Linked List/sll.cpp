#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node *node;

node createNode(int value)
{
	node temp = new Node;
	temp->data = value;
	temp->next = NULL;
	return temp;
}

node AddTail(node *head, int value)
{
	node temp = createNode(value);
	if(*head == NULL)
		*head = temp;
	else
	{
		node p = *head;
		while(p->next != NULL)
			p = p->next;
		p->next = temp;
	}
	return *head;
}

node Clearhead()
{
	node head;
	head = NULL;
	return head;
}
void printList(node head)
{
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

int demPhtu(node head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

node InsertNodeTr(node head, int x, int value)
{
	if (x > demPhtu(head))
	{
		cout << "\nKhong tim thay vi tri " << x;
		return head;
	}
	int count = 1;
	node temp = createNode(value);
	node p = head;
	if(x == 1)
	{
		temp->next = head;
		head = temp;
		return head;
	}
	else
	{
		node p = head, q;
		while(count <= demPhtu(head))
		{
			count++;
			if(count == x)
				break;
			p = p->next;
		}
		q = p->next;
		p->next = temp;
		temp->next = q;
		return head;
	}
}

node InsertNodeS(node head, int x, int value)
{
	if (x > demPhtu(head))
	{
		cout << "\nKhong tim thay vi tri " << x;
		return head;
	}
	
	int count = 1;
	node temp = createNode(value);
	node p = head;
	while (count != x)
	{
		p = p->next;
		count++;
	}
	node q = p->next;
	p->next = temp;
	temp->next = q;
	return head;
}

node DeleteLocation(node head, int x)
{
	node q;
	int count = 1;
	do
	{
		cout << "\nnhap x: ";
		cin >> x;
		if(x < 0 || x > demPhtu(head))
			cout << "Khong co gia tri o vi tri " << x;
	} while (x < 0 || x > demPhtu(head));

	if(head == NULL)
	{
		cout << "khong co phan tu de xoa!";
		return head;
	}
	else
	{
		node p = head;
		if(x == 1)
		{
			q = p->next;
			delete p;
			return q;
		}
		else
		{
			while(count != x)
			{
				count++;
				p = p->next;
				if(count == x - 1)
					q = p;
			}
			q->next = p->next;
			delete p;
			return head;
		}
	}	
}

bool checkValue(node head, int x)
{
	while (head != NULL)
	{
		if(head->data == x)
			return true;
		head = head->next;
	}
	return false;
}

node deleteValue(node head, int value)
{
	node p = head, q;
	if(value == head->data)
	{
		q = p;
		p = p->next;
		delete q;
		head = p;
	}
	tryAgain:
	if(!checkValue(head, value))
	{
		return head;
	}
		p = head;
		while (p->data != value)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
		if (checkValue(head, value))
			goto tryAgain;
	return head;
}

void swapNode(node *head, int x, int y)
{
	if(x == y)
		return;
	node crurX = *head, prevX = NULL; 
	while (crurX->data != x)
	{
		prevX = crurX;
		crurX = crurX->next;
	}
	node crurY = *head, prevY = NULL;
	while (crurY->data != y)
	{
		prevY = crurY;
		crurY = crurY->next;
	}

	if(crurX == NULL || crurY == NULL)
		return;

	if(prevX != NULL)
		prevX->next = crurY;
	else
		*head = crurY;
	if(prevY != NULL)
		prevY->next = crurX;
	else
		*head = crurX;
	node temp = crurX->next;
	crurX->next = crurY->next;
	crurY->next = temp;
}

void sapxepGiamdan(node *head)
{
	if(*head == NULL)
	{
		cout << "khong co phan tu!";
		return;
	}
	for (node i = *head; i != NULL; i = i->next)
		for (node j = i->next; j != NULL; j = j->next)
			if(i->data < j->data)
				swapNode(head, i->data, j->data);
}

void sapxepTangdan(node *head)
{
	if(*head == NULL)
	{
		cout << "khong co phan tu!";
		return;
	}
	for (node i = *head; i != NULL; i = i->next)
		for (node j = i->next; j != NULL; j = j->next)
			if(i->data > j->data)
				swapNode(head, i->data, j->data);
}

void menu()
{
	cout << "\n================MENU=================";
	cout << "\n1.Nhap phan tu: ";
	cout << "\n2.in phan tu: ";
	cout << "\n3.Chen phan tu vao dang truoc.";
	cout << "\n4.Chen phan tu vao dang sau.";
	cout << "\n5.Xoa phan tu o vi tri x.";
	cout << "\n6.Xoa phan tu.";
	cout << "\n7.Doi cho phan tu:";
	cout << "\n8.Sap xep thu tu giam dan.";
	cout << "\n9.Sap xep thu tu tam dan.";
	cout << "\n0.Thoat\n";
}
int main()
{
	int a, x;
	node head;
	char lc;
	while (true)
	{
		fflush(stdin);
		menu();
		cout << "Lua chon cua ban: ";
		lc = getchar();
		if(lc == '0')
			break;
		system("cls");
		switch(lc)
		{
			case '1':
				cout << "a: ";
				cin >> a;
				head = AddTail(&head, a);
				break;
			case '2':
				printList(head);
				cout << endl;
				system("pause");
				break;
			case '3':
				cout << "Vi tri x: ";
				cin >> x;
				cout << "Gia tri a: ";
				cin >> a;
				InsertNodeTr(head, x, a);
				break;
			case '4':
				cout << "Vi tri x: ";
				cin >> x;
				cout << "Gia tri a: ";
				cin >> a;
				InsertNodeS(head, x, a);
				break;
			case '5':
				DeleteLocation(head, x);
				break;
			case '6':
				cout << "Gia tri xoa: ";
				cin >> a;
				head = deleteValue(head, a);
				break;
			case '7':
				cout << "Gia tri 1: ";
				cin >> a;
				cout << "Gia tri 2: ";
				cin >> x;
				swapNode(&head, a, x);
				break;
			case '8':
				for(int i = 0; i < demPhtu(head); i++)
					sapxepGiamdan(&head);
				break;
			case '9':
				for(int i = 0; i < demPhtu(head); i++)
					sapxepTangdan(&head);
				break;
		}
	}
	
}

