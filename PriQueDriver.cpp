//*****************************************************************************************************
//
//		File:				PriQueDriver.h
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
//					 a priority queue which enables storage
//					 and access of stock information.
//
//      Other files required: Stock.cpp
//							  PriorityQueue.h
//							  Stock.h	
//							  Node.h						 
//
//*****************************************************************************************************

#include "Stock.h"
#include "PriorityQueue.h"

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

//*****************************************************************************************************

void formList(PriorityQueue<Stock>&);

//*****************************************************************************************************

int main()
{
	PriorityQueue<Stock> obj(12);
	ostream& os = cout;
	formList(obj);
	obj.display(os);

	return 0;
}

//*****************************************************************************************************

void formList(PriorityQueue<Stock>& stockQue)
{
	Stock info;
	ifstream fin;
	fin.open("Stock.txt");

	if (fin.fail())
		cout << "File failed to load." << endl;

	else
	{
		while (fin >> info)
			stockQue.enqueue(info);

		cout << "File loaded successfully.\n" << endl;
		fin.close();
	}
}

//*****************************************************************************************************