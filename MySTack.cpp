#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class MyStack
{
private:
	Node* top;
public:
	MyStack()
	{
		top = new Node();
	}
public:
	void Push(int val)
	{
		Node* n1 = new Node();
		n1->data = val;
		n1->next = top;
		top = n1;
	}
	int Pop()
	{
		int val = NULL;
		if (top->next != NULL)
		{
			Node* node = top;
			val = top->data;
			top = top->next;
			node->next = NULL;
			free(node);
		}
		return val;
	}
	int peek()
	{
		if (top->next != NULL)
			return top->data;
		else
			return -1;
	}
	void PrintStack()
	{
		Node* node = top;
		while (node->next != NULL)
		{
			cout << node->data << "\n";
			node = node->next;
		}
	}
};

int main()
{
	MyStack* myStack = new MyStack();
	myStack->Push(5);
	cout << "Peeking inserted value    " << myStack->peek() << "\n";
	myStack->Push(7);
	myStack->Push(10);
	cout << "Popped value" << myStack->Pop() << "\n";
	cout << "Popped value" << myStack->Pop() << "\n";
	cout << "Popped value" << myStack->Pop() << "\n";
	myStack->Push(11);
	myStack->Push(13);
	myStack->Push(15);
	cout << "Popped value" << myStack->Pop() << "\n";
	myStack->PrintStack();
}
