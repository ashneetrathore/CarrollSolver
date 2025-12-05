#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include "runtimeexcept.hpp"
#include <vector>
#include <iostream>

class PriorityQueueEmptyException : public RuntimeException 
{
public:
	PriorityQueueEmptyException(const std::string & err) : RuntimeException(err) {}
};


template<typename Object>
class MyPriorityQueue
{
private:
	std::vector<Object> min_heap;

public:

	MyPriorityQueue();
	~MyPriorityQueue();

 	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	void insert(const Object & elem);

	const Object & min() const; 

	void extractMin(); 

};


template<typename Object>
MyPriorityQueue<Object>::MyPriorityQueue()
{

}


template<typename Object>
MyPriorityQueue<Object>::~MyPriorityQueue()
{
	
}

template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
	return this->min_heap.size();
}



template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
	if (this->min_heap.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem) 
{
	// min heap ex: 6, 7, 12, 10, 15, 17
	this->min_heap.push_back(elem);
	int index = this->size() - 1;
	int parentIndex;
	while (index > 0) {
		parentIndex = (index - 1) / 2;
		if ((this->min_heap[parentIndex] < this->min_heap[index]) || (this->min_heap[parentIndex] == this->min_heap[index])) { // if parent <= child --> min_heap property satisfied
			return;
		}
		else {
			Object temp = this->min_heap[index];
			this->min_heap[index] = this->min_heap[parentIndex];
			this->min_heap[parentIndex] = temp;
			index = parentIndex;
		}
	}
}


template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
	if (this->isEmpty()) {
		throw PriorityQueueEmptyException("Queue is empty");
	}
	return this->min_heap[0];
}



template<typename Object>
void MyPriorityQueue<Object>::extractMin() 
{
	if (this->isEmpty()) {
		throw PriorityQueueEmptyException("Queue is empty");
	}
	int index = 0;
	Object popped = this->min_heap[this->min_heap.size() - 1];
	this->min_heap.pop_back();
	this->min_heap[index] = popped;

	int childIndex = (2 * index) + 1;
	Object val = this->min_heap[0];

	while (childIndex < this->min_heap.size()) {
		Object minVal = val;
		int minIndex = -1;
		for (int i = 0; (i < 2) && ((i + childIndex) < this->min_heap.size()); i++) {
			if (this->min_heap[i + childIndex] < minVal) {
				minVal = this->min_heap[i + childIndex];
				minIndex = i + childIndex;
			}
		}
		if (minVal == val) {
			return;
		}
		else {
			Object temp = this->min_heap[index];
			this->min_heap[index] = this->min_heap[minIndex];
			this->min_heap[minIndex] = temp;
			index = minIndex;
			childIndex = (2 * index) + 1;
		}
	}
}


#endif 