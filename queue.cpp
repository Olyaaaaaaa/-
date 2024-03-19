#include <iostream>
#include <exception>
#include "queue.h"
using namespace std;
Queue::Queue(): start(nullptr), end(nullptr){}
Queue::~Queue()
{
	makeEmpty();
}
void Queue::makeEmpty()
{
	while (start != nullptr)
	{
		Node* temp = start;
		start = start->next;
		delete temp;
	}
	end = nullptr;
	cout << "Your queue was deleted..." << endl;
}
void Queue::push(DataType val)
{
	if (start == nullptr)
	{
		start = new Node(val);
		end = start;
	}
	else
	{
		end->next = new Node(val);
		end = end->next;
	}
}
void Queue::pop()
{
	if (start != nullptr)
	{
		Node* temp = start;
		start = start->next;
		delete temp;
	}
	else
		throw exception("Your queue is empty...");
}
void Queue::swap(Queue& Q)
{
	Node* temp = this->start;
	this->start = Q.start;
	Q.start = temp;
	temp = this->end;
	this->end = Q.end;
	Q.end = temp;
	temp = nullptr;
}
bool Queue::isEmpty()const
{
	if (start == nullptr)
	{
		return true;
	}
	else
		return false;
}
DataType Queue::front()const
{
	if (!isEmpty())
	{
		return start->value;
	}
	else
		throw exception("Your queue is empty...");
}
DataType Queue::back()const
{
	if (!isEmpty())
	{
		return end->value;
	}
	else
		throw exception("Your queue is empty...");
}
size_t Queue::size()const
{
	size_t count = 0;
	Node* temp = start;
	while (temp != nullptr)
	{
		++count;
		temp = temp->next;
	}
	temp = nullptr;
	return count;
}
void Queue::print()const
{
	Node* temp = start;
	while (temp != nullptr)
	{
		cout << temp->value << ' ';
		temp = temp->next;
	}
	temp = nullptr;
	cout << endl;
}
Queue& Queue::operator=(const Queue& Q)
{
	if (this != &Q)
	{
		this->makeEmpty();
		Node* temp = Q.start;
		while (temp != nullptr)
		{
			this->push(temp->value);
			temp = temp->next;
		}
		temp = nullptr;
	}
	return *this;
}

//------------------------Queue with priority--------------------------
PriorityQueue::PriorityQueue()
	: start(nullptr), end(nullptr){}
PriorityQueue::~PriorityQueue()
{
	clear();
}
void PriorityQueue::clear()
{
	while (start != nullptr)
	{
		PriorityNode* current = start;
		start = start->next;
		delete current;
	}
	end = nullptr;
	cout << "Your queue was deleted..." << endl;
}
void PriorityQueue::enqueue(DataType val, int priority)
{
	if (start == nullptr)
	{
		start = new PriorityNode(val, priority, start);
		end = start;
	}
	else if (start->priority > priority)
	{
		start = new PriorityNode(val, priority, start);
	}
	else
	{
		PriorityNode* current = start;
		while (current->next != nullptr && current->next->priority <= priority)
		{
			current = current->next;
		}
		current->next = new PriorityNode(val, priority, current->next);
		if (current == end)
		{
			end = end->next;
		}
	}
}
void PriorityQueue::dequeue()
{
	if (!isEmpty())
	{
		PriorityNode* temp = start;
		start = start->next;
		delete temp;
	}
	else
		throw exception("Your queue is empty...");
}
bool PriorityQueue::isEmpty()const
{
	if (start == nullptr)
		return true;
	else
		return false;
}
DataType PriorityQueue::front()const
{
	if (!isEmpty())
	{
		return start->value;
	}
	else
		throw exception("Your queue is empty...");
}
DataType PriorityQueue::Back()const
{
	if (!isEmpty())
	{
		return end->value;
	}
	else
		throw exception("Your queue is empty...");
}
size_t PriorityQueue::size()const
{
	size_t count = 0;
	PriorityNode* temp = start;
	while (temp != nullptr)
	{
		++count;
		temp = temp->next;
	}
	return count;
}
void PriorityQueue::print()const
{
	if (start != nullptr)
	{
		PriorityNode* temp = start;
		while (temp != nullptr)
		{
			cout << "(" << temp->value << ", " << temp->priority << ")  ";
			temp = temp->next;
		}
		cout << endl;
		temp = nullptr;
	}
	else 
		throw exception("Your queue is empty...");
}
void PriorityQueue::swap(PriorityQueue& P)
{
	PriorityNode* temp = this->start;
	this->start = P.start;
	P.start = temp;
	temp = this->end;
	this->end = P.end;
	P.end = temp;
	temp = nullptr;
}