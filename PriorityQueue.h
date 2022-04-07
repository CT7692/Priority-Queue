//*****************************************************************************************************
//
//		File:				PriorityQueue.h
//
//		Student:			Joseph Rydel
//
//		Assignment:	 		Assignment  #7
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - 01
//
//		Due:				March 28, 2022
//
//
//		Description: This program is an implementation of
//					 the stock class, which will store 
//					 all relevant information of a stock.
//
//
//      Other files required: Stock.cpp
//							  PriQueDriver.cpp
//							  Stock.h	
//							  Node.h						 
//
//*****************************************************************************************************

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <ostream>

//*****************************************************************************************************

template<typename T>
class PriorityQueue
{
private:
	T* heap;
	int capacity;
	int numValues;

public:
	PriorityQueue(int);
	~PriorityQueue();
	bool enqueue(const T&);
	bool dequeue(const T&);
	void display(std::ostream&) const;
	void heapify(int);
};

//*****************************************************************************************************

template<typename T>
PriorityQueue<T>::PriorityQueue(int cap)
{
	capacity = cap;
	heap = new T[capacity];
	numValues = 0;
}

//*****************************************************************************************************

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	delete[] heap;
	heap = nullptr;
	capacity = 0;
	numValues = 0;
}

//*****************************************************************************************************

template<typename T>
bool PriorityQueue<T>::enqueue(const T& dataIn)
{
	using namespace std;
	bool added = false;
	int child = numValues;
	int parent = (child - 1) / 2;

	while ((child > 0) && (dataIn > heap[parent]))
	{
		heap[child] = heap[parent];
		child = parent;
		parent = (parent - 1) / 2;
	}

	heap[child] = dataIn;
	++numValues;
	added = true;

	if (numValues == capacity)
	{
		int newCap = capacity + 10;
		T* arr = new (std::nothrow) T[newCap];

		for (int i = 0; i < capacity; i++)
			arr[i] = heap[i];
	}

	return added;
}

//*****************************************************************************************************

template<typename T>
bool PriorityQueue<T>::dequeue(const T& dataOut)
{
	bool removed = false;
	int counter = 0;

	if (numValues > 0)
	{
		dataOut = heap[0];
		removed = true;
		heap[0] = heap[numValues - 1];
		--numValues;
		counter++;
		heapify(0);
	}

	if (counter == 10 && capacity > 22)
		capacity = capacity - counter;

	return removed;
}

//*****************************************************************************************************

template<typename T>
void PriorityQueue<T>::heapify(int i)
{
	int left;
	int right;
	int max;
	bool stop = false;
	T temp = heap[i];
	left = i * 2 + 1;

	while ((left < numValues) && (!stop))
	{
		right = left + 1;

		if (right >= numValues)
			max = left;

		else
		{
			if (heap[left] > heap[right])
				max = left;
			else
				max = right;
		}

		if (heap[max] > temp)
		{
			heap[i] = heap[max];
			i = max;
			left = i * 2 + 1;
		}

		else
			stop = true;
	}

	heap[i] = temp;
}

//*****************************************************************************************************

template<typename T>
void PriorityQueue<T>::display(std::ostream& os) const
{

	for (int i = 0; i < numValues; i++)
		os << heap[i] << "\n";
}

//*****************************************************************************************************

#endif