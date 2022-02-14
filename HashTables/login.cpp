#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.cpp"

using namespace std;

class Login
{
public:
    void setKey(const string& username) { login = username; }
    void setPassword(const string& password) { this->password = password; }
    string getKey() const { return login; }
    string getPassword() const { return password; }
    static unsigned int hash(const string& str);

private:
    string login;
    string password;
};

unsigned int Login::hash(const string& str)
{
    unsigned int val = 0;

    for (int i = 0; i < str.length(); ++i)
        val += str[i];

    return val;
}

int main()
{
    ifstream passFile("password.dat");
    HashTable<Login, string> table(8);
    Login temp;

    string login, password;
    passFile >> login;

    while (passFile.good())
    {
        passFile >> password;
        temp.setKey(login);
        temp.setPassword(password);
        table.insert(temp);
        passFile >> login;
    }

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;

    if (table.retrieve(login, temp))
    {

        if (temp.getPassword() == password)
            cout << "Authentication successful" << endl;

        else
            cout << "Authentication failure" << endl;
    }

    else
        cout << "Authentication failure" << endl;

    return 0;

}
