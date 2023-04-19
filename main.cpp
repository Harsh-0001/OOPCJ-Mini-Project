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
    user()
    {
        user_name = "";
        password = "";
    }
    user(string user_name, string password)
    {
        cout<<"Not permitted"<<endl;
    }

    // Pure virtual functions as we don't want to create object of user class and we want to make sure that all the derived classes have to implement these functions as thier register_user and login functions are different
    virtual void register_user() = 0;
    virtual void login() = 0;
};

class admin : public user
{
public:
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

        // Open file and check if user_name and password exists
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
    
    
    void add_admin()
    {
        cout << "Enter your name: ";
        cin >> user_name;
        cout << "Enter your password: ";
        cin >> password;

        // Open file and write user_name and password to keep track of registered users
        try
        {
            ofstream file;
            file.open("admin.txt", ios::app);
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

    void display_users()
    {
        // Open file and display all the users
        try
        {
            ifstream file;
            file.open("user.txt");
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void display_admins()
    {
        // Open file and display all the users
        try
        {
            ifstream file;
            file.open("admin.txt");
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void delete_admin()
    {
        cout << "Enter username: ";
        cin >> user_name;
        cout << "Enter password: ";
        cin >> password;

        // Open file and delete user_name and password
        try
        {
            ifstream file;
            file.open("admin.txt");
            string line;
            while (getline(file, line))
            {
                if (line.find(user_name) != string::npos && line.find(password) != string::npos)
                {
                    string filename = "admin.txt";
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

    void add_producer()
    {
        cout << "Enter your name: ";
        cin >> user_name;
        cout << "Enter your password: ";
        cin >> password;

        // Open file and write user_name and password to keep track of registered users
        try
        {
            ofstream file;
            file.open("producer.txt", ios::app);
            file << user_name << " " << password << endl;
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void display_producer()
    {
        // Open file and display all the users
        try
        {
            ifstream file;
            file.open("producer.txt");
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void delete_producer()
    {
        cout << "Enter username: ";
        cin >> user_name;
        cout << "Enter password: ";
        cin >> password;

        // Open file and delete user_name and password
        try
        {
            ifstream file;
            file.open("producer.txt");
            string line;
            while (getline(file, line))
            {
                if (line.find(user_name) != string::npos && line.find(password) != string::npos)
                {
                    string filename = "producer.txt";
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
    
    void add_consumer()
    {
        cout << "Enter your name: ";
        cin >> user_name;
        cout << "Enter your password: ";
        cin >> password;

        // Open file and write user_name and password to keep track of registered users
        try
        {
            ofstream file;
            file.open("consumer.txt", ios::app);
            file << user_name << " " << password << endl;
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void display_consumer()
    {
        // Open file and display all the users
        try
        {
            ifstream file;
            file.open("consumer.txt");
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void delete_consumer()
    {
        cout << "Enter username: ";
        cin >> user_name;
        cout << "Enter password: ";
        cin >> password;

        // Open file and delete user_name and password
        try
        {
            ifstream file;
            file.open("consumer.txt");
            string line;
            while (getline(file, line))
            {
                if (line.find(user_name) != string::npos && line.find(password) != string::npos)
                {
                    string filename = "consumer.txt";
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
    // admin a;
    // a.add_user();
    // a.delete_user();
    admin a;
    a.add_admin();
    return 0;
}