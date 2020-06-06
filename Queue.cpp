#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
	stack<int> s1, s2;
public:
	void Enqueue(int val)
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(val);

		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	int Dequeue()
	{
		if (s1.empty()) {
			cout << "Q is Empty";
			exit(0);
		}
		int x = s1.top();
		s1.pop();
		return x;
	}
};


int main()
{
	MyQueue* mq = new MyQueue();
	mq->Enqueue(2);
	cout<< mq->Dequeue();
	mq->Enqueue(4);
	mq->Enqueue(5);
	mq->Enqueue(6);
	mq->Enqueue(7);
	mq->Enqueue(8);
	mq->Enqueue(9);
	cout << mq->Dequeue();
	
	
	
}
