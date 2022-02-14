//--------------------------------------------------------------------
//
//  "Laboratory 11, In-lab Exercise 1"                     "database.cpp"
//
//  "(Shell) Indexed accounts database program"
//
//--------------------------------------------------------------------
// "Builds a binary search tree index for the account records in the
// text file accounts.txt."

#include <iostream>
#include <fstream>
#include "BSTree.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// "Declarations specifying the accounts database."
//

const int nameLength      = 11;   // "Maximum number of characters in                                  
								  //   a name."
const long bytesPerRecord = 38;   
								  // "Number of bytes used to store                                  
								  //   each record in the accounts                                  
								  //   database file."
struct AccountRecord
{    
	int acctID;                   // "Account identifier."  
	char firstName[nameLength],   // "Name of account holder."         
		lastName[nameLength];    
	double balance;               // "Account balance."
};

//--------------------------------------------------------------------
//
// "Declaration specifying the database index."
//

struct IndexEntry
{    
	int acctID;              // "(Key) Account identifier."    
	long recNum;             // "Record number."    
	int getKey () const        
	    { return acctID; }   // "Return key field."

};

//--------------------------------------------------------------------

int main ()
{    
	ifstream acctFile ("accounts.txt");   // "Accounts database file."   
	AccountRecord acctRec{};                // "Account record."    
	BSTree<IndexEntry,int> index;         // "Database index."    
	IndexEntry entry;                     // "Index entry."    
	int searchID;                         // "User input account ID."
    long record_num{};                          // "Record number."  

	// "Iterates through the database records. This will read the    
	// account ID and add the (account ID, record number) pair to the    
	// index."    
	string s;
	acctFile >> entry.acctID;
	while (acctFile.good())
	{
		acctFile >> s >> s >> s;
		entry.recNum = record_num;
		record_num++;
		index.insert(entry);
		acctFile >> entry.acctID;
	}
	// "Outputs the account IDs in ascending order."   
	cout << "\nAccount IDs in ascending order : " << endl;
	index.writeKeys();
	// "Clears the status flags for the database file."    
	acctFile.clear();
	acctFile.close();
	// "Reads an account ID from the keyboard and outputs the    
	// corresponding record."
	acctFile.open("accounts.txt");
	cout << endl << "Enter account ID : ";
	while (cin >> searchID)
	{
		if (index.retrieve(searchID, entry))
		{
			for (int i = 0; i <= entry.recNum; i++)
			{
				acctFile >> acctRec.acctID;
				acctFile >> acctRec.firstName >> acctRec.lastName;
				acctFile >> acctRec.balance;
			}

			cout << "Record # : " << entry.recNum << endl;
			cout << "Account ID : " << acctRec.acctID << endl;
			cout << "First name : " << acctRec.firstName << endl;
			cout << "Last name : " << acctRec.lastName << endl;
			cout << "Balance : " << acctRec.balance << endl;
		}
		else
		{
			cout << "There is no record with that account ID. Try another one.";

		}
		acctFile.clear();
		acctFile.close();
		acctFile.open("accounts.txt");
		cout << endl << "Enter account ID : ";
	}
}                            