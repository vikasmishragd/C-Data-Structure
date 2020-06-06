#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};


void PrintList(Node* node)
{
	while(node != NULL)
	{
        cout << node->data << "\n";
        node = node->next;
	}
}

void AddToHead(Node* n1, Node* node,Node* head)
{
    node->next = n1;
    head = node;
}

void AddToTail(Node* n1, Node* node, Node* head)
{
	while(n1 !=NULL)
	{
		if(n1->next == NULL)
		{
            n1->next = node;
            break;
		}
        n1 = n1->next;
	}
}

bool  Find(Node* node, int i)
{
	while(node != NULL)
	{
		if(node->data==6)
		{
            cout << "Item found" << "\n";
            return true;
		}
        node = node->next;
	}
    return false;
}

bool Delete(Node* node, int i)
{
	while(node != NULL)
	{
		if(node->next->data ==i)
		{
            Node* tempNode = node->next;
            Node* nextNode = node->next->next;
            free(tempNode);
            node->next = nextNode;
            cout << "Node removed successfully" << "\n";
            return true;
		}
        node = node->next;
	}
    return false;
}

void Insert(Node* node, int i, int value)
{
    int index = 0;
	while(node !=NULL)
	{
		if(index==i)
		{
            Node* newNode = new Node();
            newNode->data = value;

            Node* tempNode = node->next;

            node->next = newNode;
            newNode->next = tempNode;
            break;
		}
        index++;
        node = node->next;
		
	}
}

void Remove(Node* node, int index)
{
    int i = 0;
	while(node!= NULL)
	{
		if(i==index-1)
		{
            Node* tempNode = node->next->next;
            free(node->next);
            node->next = tempNode;
            break;
		}
        node = node->next;
        i++;	
	}
}

int main()
{
    Node* n1 = new Node();

    Node* head = new Node();
    n1->data = 1;
   
    Node* n2 = new Node();
    n2->data = 2;

    Node* n3 = new Node();
    n3->data = 3;

    Node* n4 = new Node();
    n4->data = 4;

    Node* n5 = new Node();
    n5->data = 5;

    Node* n6 = new Node();
    n6->data = 6;

    Node* n7 = new Node();
    n7->data = 7;

    Node* n = new Node();
    n->data = 0;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    head = n1;
    cout << "------------------------Adding to head-------------------"<<"\n";
	AddToHead(n1, n, head);
    PrintList(head);
    cout << "------------------------Adding to tail-------------------"<<"\n";
    AddToTail(n1, n7, head);
    PrintList(head);
    cout << "------------------------Search an item-------------------"<<"\n";
    Find(head, 6);
    PrintList(head);
    cout << "------------------------insert an item at nth Position -------------------" << "\n";
    Insert(head,3, 99);
    PrintList(head);
    cout << "------------------------delete an item-------------------" << "\n";
    Delete(head, 4);
    PrintList(head);
    cout << "------------------------Remove an item at nth location-------------------" << "\n";
    Remove(head, 4);
    PrintList(head);
}

