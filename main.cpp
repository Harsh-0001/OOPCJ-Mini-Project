// OOPCJ Mini Project

#include <iostream>
#include <fstream>
using namespace std;

class user
{
protected:
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

        // Open file and write user_name and password to keep track of registered users
        try
        {
            ofstream file;
            file.open("user.txt", ios::app);
            file << user_name << " " << password << endl;
            file.close();
        }
        catch (const std::exception &e)
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
            while (getline(file, line))
            {
                if (line.find(user_name) != string::npos && line.find(password) != string::npos)
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
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};

class admin : public user
{
public:
    void add_user()
    {
        cout << "Enter username: ";
        cin >> user_name;
        cout << "Enter password: ";
        cin >> password;

        // Open file and write user_name and password to keep track of registered users
        try
        {
            ofstream file;
            file.open("user.txt", ios::app);
            file << user_name << " " << password << endl;
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    void delete_user()
    {
        cout << "Enter username: ";
        cin >> user_name;
        cout << "Enter password: ";
        cin >> password;

        // Open file and delete user_name and password
        try
        {
            ifstream file;
            file.open("user.txt");
            string line;
            while (getline(file, line))
            {
                if (line.find(user_name) != string::npos && line.find(password) != string::npos)
                {
                    string filename = "user.txt";
                    int line_number_to_delete = 3;

                    // Open the input file and temporary file
                    ifstream input_file(filename);
                    ofstream temp_file("temp.txt");

                    // Read and copy each line, except for the line to delete
                    string line;
                    int current_line_number = 1;
                    while (getline(input_file, line))
                    {
                        if (current_line_number != line_number_to_delete)
                        {
                            temp_file << line << endl;
                        }
                        current_line_number++;
                    }

                    // Close both files
                    input_file.close();
                    temp_file.close();

                    // Delete the input file and rename the temporary file
                    remove(filename.c_str());
                    rename("temp.txt", filename.c_str());
                    

                }
                else
                {
                    cout << "User not found" << endl;
                    break;
                }
            }
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};

int main()
{
    //     user u;
    //    u.register_user();
    //     u.login();
    admin a;
    a.add_user();
    a.delete_user();
    return 0;
}