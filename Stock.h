//*****************************************************************************************************
//
//		File:				Stock.h
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
//							  PriorityQueue.h	
//							  Node.h						 
//
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

#include<string>

class Stock
{
private:
	std::string name;
	std::string symbol;
	double price;

public:
	Stock(const std::string& name = "", const std::string& symbol = "", double price = 0);
	Stock(const Stock&);

	std::string getName() const
		{	return name;	}

	std::string getSymbol() const
		{	return symbol;	}

	double getPrice() const
		{	return price;	}


	bool operator == (const Stock& rhs) const
		{	return this->price == rhs.price;}

	bool operator != (const Stock& rhs) const
		{	return this->price != rhs.price;}

	bool operator < (const Stock& rhs) const
		{	return this->price < rhs.price;	}


	bool operator > (const Stock& rhs) const
		{	return this->price > rhs.price;	}


	operator double()
		{	return this->price;}


	friend std::istream& operator >> (std::istream&, Stock&);
	friend std::ostream& operator << (std::ostream&, Stock&);
};

//*****************************************************************************************************

#endif