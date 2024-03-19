#include <iostream>
#include <exception>
#include "queue.h"
using namespace std;
int main()
{
	Queue MyQueue;
	Queue OtherQueue;
	OtherQueue.push(21);
	OtherQueue.push(14);
	OtherQueue.push(98);
	OtherQueue.push(27);
	OtherQueue.push(22);
	OtherQueue.push(91);
	MyQueue.push(8);
	MyQueue.push(9);
	MyQueue.push(10);
	MyQueue.push(2);
	MyQueue.push(45);
	MyQueue.push(33);
	MyQueue.push(71);
	cout << "My queue: "; MyQueue.print();
	cout << "Other queue: "; OtherQueue.print();
	cout << "Checking emptyness..." << endl;
	cout << "Is my queue empty(0 - no, 1 - yes): " << MyQueue.isEmpty() << endl;
	cout << "Queues after swaping: " << endl;
	MyQueue.swap(OtherQueue);
	cout << "My queue: "; MyQueue.print();
	cout << "Other queue: "; OtherQueue.print();
	try
	{
		cout <<"Back element: "<< MyQueue.back() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout <<"Front element: "<< MyQueue.front() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	MyQueue.pop();
	MyQueue.pop();
	MyQueue.pop();
	cout << "My queue after poping: "; MyQueue.print();
	cout << "Other queue: "; OtherQueue.print();
	MyQueue = OtherQueue;
	cout << "Work of operator=, My queue: ";
	MyQueue.print();
	cout << "Size of my queue: " << MyQueue.size() << endl;
	cout << endl;
	cout << endl;


	cout << "Working with priority queue." << endl;
	PriorityQueue Q;
	PriorityQueue P;
	P.enqueue(40, 6); 
	P.enqueue(34, 2); 
	Q.enqueue(11, 5); 
	Q.enqueue(21, 4);
	Q.enqueue(4, 1); 
	Q.enqueue(5, 1); 
	Q.enqueue(41, 4); 
	Q.enqueue(7, 2);
	Q.enqueue(8, 3); 
	Q.enqueue(5, 5); 
	Q.enqueue(15, 5);
	Q.enqueue(67, 1);
	cout << "Our queue: "; Q.print();
	cout << "Size of our queue: " << Q.size() << endl;
	cout << "Other queue: "; P.print();
	cout << "Checking emptyness..." << endl;
	cout << "Is our queue empty(0 - no, 1 - yes): " << Q.isEmpty() << endl;
	Q.swap(P);
	cout << "Queues after swaping: " << endl;
	cout << "My queue: "; Q.print();
	cout << "Other queue: ";P.print();
	try
	{
		Q.dequeue();
		Q.dequeue();
		Q.dequeue();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout << "Our queue after dequeueing: "; Q.print();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout << "Front element: " << Q.front() << endl;
		cout << "Back element: " << Q.Back() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Deleting queues: " << endl;
	Q.clear();
	P.clear();
	MyQueue.makeEmpty();
	OtherQueue.makeEmpty();
	return 0;
}