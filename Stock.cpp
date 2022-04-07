//*****************************************************************************************************
//
//		File:				Stock.cpp
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
//      Other files required: Stock.h
//							  PriQueDriver.cpp
//							  PriorityQueue.h	
//							  Node.h						 
//
//*****************************************************************************************************

#include "Stock.h"

#include<iostream>

using namespace std;

//*****************************************************************************************************

Stock::Stock(const string& na, const string& sym, double pri)
{
	name = na;
	symbol = sym;
	price = pri;
}

//*****************************************************************************************************

Stock::Stock(const Stock& s)
{
	this->name = s.name;
	this->symbol = s.symbol;
	this->price = s.price;
}

//*****************************************************************************************************

istream& operator >> (istream& strm, Stock& sto)
{
	getline(strm, sto.name);
	getline(strm, sto.symbol);
	strm >> sto.price;

	if (!strm.eof())
		strm.ignore();

	return strm;
}

//*****************************************************************************************************

ostream& operator << (ostream& strm, Stock& sto)
{
	strm << sto.getSymbol() << " "
		<< sto.getName() << "\n" << "$"
		<< sto.getPrice() << "\n" << endl;

	return strm;
}

//*****************************************************************************************************