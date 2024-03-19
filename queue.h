#pragma once
#include <iostream>
typedef int DataType;
struct Node
{
	DataType value;
	Node* next;
	Node(DataType val, Node* N = nullptr): value(val), next(N){}
};
class Queue
{
private:
	Node* start;
	Node* end;
public:
	Queue();
	~Queue();
	void push(DataType val);
	void pop();
	void swap(Queue& Q);
	void print()const;
	void makeEmpty();
	bool isEmpty()const;
	DataType front()const;
	DataType back()const;
	size_t size()const;
	Queue& operator=(const Queue& Q);
};
struct PriorityNode
{
	DataType value;
	int priority;
	PriorityNode* next;
	PriorityNode(DataType val, int prior, PriorityNode* P = nullptr): value(val), priority(prior), next(P){}
};
class PriorityQueue
{
private:
	PriorityNode* start;
	PriorityNode* end;
public:
	PriorityQueue();
	~PriorityQueue();
	void clear();
	void enqueue(DataType val, int priority);
	void dequeue();
	void swap(PriorityQueue& P);
	void print()const;
	bool isEmpty()const;
	DataType front()const;
	DataType Back()const;
	size_t size()const;

};