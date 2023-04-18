// OOPCJ Mini Project

#include <iostream>
#include <fstream>
using namespace std;


class user
{
    string user_name;
    string password;
    public:
    void set_user_name(string name)
    {
        user_name = name;
    }
    void set_password(string pass)
    {
        password = pass;
    }
    string get_user_name()
    {
        return user_name;
    }
    string get_password()
    {
        return password;
    }
    void register_user()
    {
        cout << "Enter your name: ";
        cin >> user_name;
        cout << "Enter your password: ";
        cin >> password;
        
        //Open file and write user_name and password to keep track of registered users
        try
        {
            ofstream file;
            file.open("user.txt", ios::app);
            file << user_name << " " << password << endl;
            file.close();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void login()
    {
        cout << "Enter username: ";
        cin >> user_name;
        cout << "Enter password: ";                                                                     
        cin >> password;


        // Open file and check if user_name and password match
        try
        {
            ifstream file;
            file.open("user.txt");
            string line;
            while(getline(file, line))
            {
                if(line.find(user_name) != string::npos && line.find(password) != string::npos)
                {
                    cout << "Login successful" << endl;
                    break;
                }
                else
                {
                    cout << "Login failed" << endl;
                    break;
                }
            }
            file.close();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};

int main()
{

}