#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Catalog.h";
#include "Book.h";
using namespace std;

 ostream& operator<< (ostream& osBook, const book& bookObject)
 {
	 const int WIDTH = 20;
	 const int WIDTH2 = 5;
	osBook <<  "ID: " << setw(WIDTH2) << bookObject.ID << setw(WIDTH) << "Title: " << setw(WIDTH2) << bookObject.title << setw(WIDTH)
		<< "Status: " << setw(WIDTH2) << bookObject.status << setw(WIDTH) << "Author: " << setw(WIDTH2) << bookObject.Author_name <<  endl;
	return osBook;
 }
book::book()
{
		title = "";
		ID = 0;
		status = true;
		Author_name = " ";
}

void book::setBook(int number, string name, string author)
{
		title = name;
		ID = number;
		status = true;
		Author_name = author;
}
bool book::operator==(const book& otherBook) const
{
		return (Author_name == otherBook.Author_name && title == otherBook.title && ID == otherBook.ID);
}
string book::getTitle()
{
		return title;
}
void book::setAuthor(string author)
{
	Author_name = author;
}

