#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Catalog.h";

using namespace std;

class book : public catalog
{
	friend ostream& operator<< (ostream&, const book&);
	
public:
	book();

	void setBook(int, string, string);
	
	bool operator==(const book& otherBook) const;
	
	string getTitle();
	
	void setAuthor(string);
	

private:
	string Author_name;
};
#endif