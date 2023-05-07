// OOPCJ Mini Project

#include <iostream>
#include <fstream>
#include <vector>
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
        cout << "Not permitted" << endl;
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

class product
{
public:
    string products;
    product()
    {
    }
    product(string products)
    {
        this->products = products;
    }
    void addProduct()
    {

        cout << "Enter Product:";
        cin >> products;
        // Take amount and description of product
        double amount;
        string description;
        cout << "Enter amount:";
        cin >> amount;
        cout << "Enter description:";
        cin >> description;
        cout << description;
        // Open file and write product to file

        try
        {
            ofstream file;
            file.open("Products.txt", ios::app);
            file << products << " " << amount << " " << description << endl;
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};

class producer : public user
{
private:
    int login_success = 0;

public:
    producer()
    {
        login_success = 0;
    }
    producer(string name, string password) : user(name, password) {}
    // ADD PRODUCT

    void login()
    {
        string user_name;
        string password;
        cout << "Enter username:";
        cin >> user_name;
        cout << "Enter password:";
        cin >> password;
        try
        {
            ifstream file;
            file.open("producer.txt");
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
            file.open("producer.txt", ios::app);
            file << user_name << " " << password << endl;
            file.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // VIEW PRODUCT

    void viewProduct()
    {
        try
        {
            ifstream file;
            file.open("Products.txt");
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

    // DELETE PRODUCTS

    void delete_product()
    {
        string product;
        string price;
        string description;

        cout << "Enter product: ";
        cin >> product;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter description: ";
        cin >> description;

        try
        {
            ifstream input_file("Products.txt");
            ofstream temp_file("temp.txt");

            bool product_found = false;
            string line;
            while (getline(input_file, line))
            {
                if (line.find(product) != string::npos &&
                    line.find(price) != string::npos &&
                    line.find(description) != string::npos)
                {
                    product_found = true;
                }
                else
                {
                    temp_file << line << endl;
                }
            }

            input_file.close();
            temp_file.close();

            if (!product_found)
            {
                cout << "Product not found" << endl;
                remove("temp.txt");
            }
            else
            {
                remove("Products.txt");
                rename("temp.txt", "Products.txt");
                cout << "Product deleted successfully" << endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void updateProduct()
    {
        string product;
        string price;
        string description;

        cout << "Enter product: ";
        cin >> product;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter description: ";
        cin >> description;

        try
        {
            ifstream input_file("Products.txt");
            ofstream temp_file("temp.txt");

            bool product_found = false;
            string line;
            while (getline(input_file, line))
            {
                if (line.find(product) != string::npos &&
                    line.find(price) != string::npos &&
                    line.find(description) != string::npos)
                {
                    product_found = true;
                }
                else
                {
                    temp_file << line << endl;
                }
            }

            input_file.close();
            temp_file.close();

            if (!product_found)
            {
                cout << "Product not found" << endl;
                remove("temp.txt");
            }
            else
            {
                remove("Products.txt");
                rename("temp.txt", "Products.txt");
                cout << "Product updated successfully" << endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};

class Consumer : public user
{
private:
    vector<string> cart;

public:
    Consumer()
    {
    }

    Consumer(string name, string password) : user(name, password) {}

    void viewProducts()
    {
        cout << "Available Products:\n";
        // From products.txt display all products

        try
        {
            ifstream file;
            file.open("Products.txt");
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

        // Code to display available products
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
            file.open("consumer.txt", ios::app);
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
        string user_name;
        string password;
        cout << "Enter username:";
        cin >> user_name;
        cout << "Enter password:";
        cin >> password;
        try
        {
            ifstream file;
            file.open("consumer.txt");
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

    void viewCart()
    {
        cout << "Items in Cart:\n";
        for (int i = 0; i < cart.size(); i++)
        {
            cout << cart[i] << endl;
        }
    }

    void addToCart(string product)
    {
        cart.push_back(product);
        cout << product << " added to cart.\n";
    }

    void removeFromCart(string product)
    {
        for (int i = 0; i < cart.size(); i++)
        {
            if (cart[i] == product)
            {
                cart.erase(cart.begin() + i);
                cout << product << " removed from cart.\n";
                return;
            }
        }
        cout << product << " not found in cart.\n";
    }

    void checkout()
    {
        double total = 0;
        // Code to calculate total amount
        // Compute your total amount from product.txt file for each item in cart
        try
        {
            ifstream file;
            file.open("Products.txt");
            string line;
            while (getline(file, line))
            {
                for (int i = 0; i < cart.size(); i++)
                {
                    if (line.find(cart[i]) != string::npos)
                    {
                        string price = line.substr(line.find(" ") + 1, line.find(" ", line.find(" ") + 1));
                        total += stod(price);
                    }
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        cout << "Total amount to be paid: " << total << endl;
    }

    void pay(string card_number, string cvv, string expiry_date)
    {

        // Code to pay using card
        // Check if card is valid
        // Check if card is not expired
        // Check if cvv is correct
        // Check if card number is correct
        // Check if sufficient balance is available
        // If all conditions are satisfied, pay the amount
        if (card_number.length() != 16)
        {
            cout << "Invalid card number" << endl;
            return;
        }
        if (cvv.length() != 3)
        {
            cout << "Invalid cvv" << endl;
            return;
        }
        if (expiry_date.length() != 5)
        {
            cout << "Invalid expiry date" << endl;
            return;
        }
        cout << "Payment Successful!\n";
        cout << "Thank you for shopping with us!\n";
    }
};

int main()
{
    cout << "Welcome to the Online Shopping Portal!\n";
    int secret_code = 1234;
    admin admin1;
    admin1.add_admin();
    system("cls");
    while (true)
    {
        cout << "Are you a consumer or a seller?\n";
        cout << "1. Consumer\n";
        cout << "2. Seller\n";
        int choice;
        cin >> choice;
        if (choice == 1)

        {
            cout << "Are you a new user or an existing user?" << endl;
            cout << "1. New user" << endl;
            cout << "2. Existing user" << endl;
            int choice1;
            cin >> choice1;
            if (choice1 == 2)
            {
                cout << "Nice to see you again!" << endl;
                string user_name;
                string password;
                cout << "Enter username:";
                cin >> user_name;
                cout << "Enter password:";
                cin >> password;
                // Code to login
                try
                {
                    ifstream file;
                    file.open("consumer.txt");
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
                system("cls");
                Consumer old;
                cout << "What would you like to do?" << endl;
                cout << "1. View products" << endl;
                cout << "2. View cart" << endl;
                cout << "3. Add to cart" << endl;
                cout << "4. Remove from cart" << endl;
                cout << "5. Checkout" << endl;
                cout << "6. Pay" << endl;

                int choice2;
                cin >> choice2;
                system("cls");
                string prod;
                string prod1;
                string old_card_number;
                string old_cvv;
                string old_expiry_date;
                do
                {
                    switch (choice2)
                    {
                    case 1:
                        old.viewProducts();
                        break;
                    case 2:
                        old.viewCart();
                        break;
                    case 3:
                        cout << "Enter the product you want to add to cart" << endl;
                        cin >> prod;
                        old.addToCart(prod);
                        break;
                    case 4:
                        cout << "Enter the product you want to remove from cart" << endl;
                        cin >> prod1;
                        old.removeFromCart(prod1);
                        break;
                    case 5:
                        old.checkout();
                        break;
                    case 6:
                        cout << "Enter your card number" << endl;
                        cin >> old_card_number;
                        cout << "Enter your cvv" << endl;
                        cin >> old_cvv;
                        cout << "Enter your expiry date" << endl;
                        cin >> old_expiry_date;
                        old.pay(old_card_number, old_cvv, old_expiry_date);
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                        break;
                    }
                    cout << "What would you like to do?" << endl;
                    cout << "1. View products" << endl;
                    cout << "2. View cart" << endl;
                    cout << "3. Add to cart" << endl;
                    cout << "4. Remove from cart" << endl;
                    cout << "5. Checkout" << endl;
                    cout << "6. Pay" << endl;
                    cin >> choice2;
                    system("cls");

                } while (choice2 != 6);
                if (choice1 == 1)
                {
                    cout << "Great! Let's get you registered" << endl;
                    string new_user_name;
                    string new_password;
                    cout << "Enter username:";
                    cin >> new_user_name;
                    cout << "Enter password:";
                    cin >> new_password;
                    system("cls");
                    // Code to register
                    Consumer new_consumer;
                    new_consumer.register_user();
                    cout << "Registration successful" << endl;
                    cout << "Login to continue" << endl;
                    new_consumer.login();
                    cout << "What would you like to do?" << endl;
                    cout << "1. View products" << endl;
                    cout << "2. View cart" << endl;
                    cout << "3. Add to cart" << endl;
                    cout << "4. Remove from cart" << endl;
                    cout << "5. Checkout" << endl;
                    cout << "6. Pay" << endl;
                    int choice3;
                    cin >> choice3;
                    system("cls");
                    do
                    {
                        switch (choice3)
                        {
                        case 1:
                            new_consumer.viewProducts();
                            break;
                        case 2:
                            new_consumer.viewCart();
                            break;
                        case 3:
                            cout << "Enter the product you want to add to cart" << endl;
                            cin >> prod;
                            new_consumer.addToCart(prod);
                            break;
                        case 4:
                            cout << "Enter the product you want to remove from cart" << endl;
                            cin >> prod1;
                            new_consumer.removeFromCart(prod1);
                            break;
                        case 5:
                            new_consumer.checkout();
                            break;
                        case 6:
                            cout << "Enter your card number" << endl;
                            cin >> old_card_number;
                            cout << "Enter your cvv" << endl;
                            cin >> old_cvv;
                            cout << "Enter your expiry date" << endl;
                            cin >> old_expiry_date;
                            new_consumer.pay(old_card_number, old_cvv, old_expiry_date);
                            break;
                        default:
                            cout << "Invalid choice" << endl;
                            break;
                        }
                        cout << "What would you like to do?" << endl;
                        cout << "1. View products" << endl;
                        cout << "2. View cart" << endl;
                        cout << "3. Add to cart" << endl;
                        cout << "4. Remove from cart" << endl;
                        cout << "5. Checkout" << endl;
                        cout << "6. Pay" << endl;
                        cin >> choice3;
                        system("cls");
                    } while (choice3 != 6);
                }
                if (choice == 2)
                {
                    cout << "Welcome seller!" << endl;
                    cout << "Are you a new seller or an existing seller?" << endl;
                    cout << "1. New seller" << endl;
                    cout << "2. Existing seller" << endl;
                    int choice4;
                    cin >> choice4;
                    system("cls");
                    if (choice4 == 1)
                    {
                        cout << "Great! Let's get you registered" << endl;
                        string new_user_name;
                        string new_password;
                        cout << "Enter username:";
                        cin >> new_user_name;
                        cout << "Enter password:";
                        cin >> new_password;
                        system("cls");
                        // Code to register
                        producer new_seller;
                        new_seller.register_user();
                        cout << "Registration successful" << endl;
                        cout << "Login to continue" << endl;
                        new_seller.login();
                        cout << "What would you like to do?" << endl;
                        cout << "1. Add products" << endl;
                        cout << "2. View products" << endl;
                        cout << "3. Remove products" << endl;
                        cout << "4. Update products" << endl;
                        int choice5;
                        cin >> choice5;
                        system("cls");
                        do
                        {
                            product new_product;

                            switch (choice5)
                            {
                            case 1:
                                new_product.addProduct();
                                break;
                            case 2:
                                new_seller.viewProduct();
                                break;
                            case 3:
                                new_seller.delete_product();
                                break;
                            case 4:
                                new_seller.updateProduct();
                                break;
                            default:
                                cout << "Invalid choice" << endl;
                                break;
                            }
                            cout << "What would you like to do?" << endl;
                            cout << "1. Add products" << endl;
                            cout << "2. View products" << endl;
                            cout << "3. Remove products" << endl;
                            cout << "4. Update products" << endl;
                            cin >> choice5;
                            system("cls");
                        } while (choice5 != 4);
                    }
                    if (choice4 == 2)
                    {
                        cout << "Enter your username" << endl;
                        string old_user_name;
                        cin >> old_user_name;
                        cout << "Enter your password" << endl;
                        string old_password;
                        cin >> old_password;
                        producer old_seller;
                        system("cls");
                        old_seller.login();
                        system("cls");
                        cout << "What would you like to do?" << endl;
                        cout << "1. Add products" << endl;
                        cout << "2. View products" << endl;
                        cout << "3. Remove products" << endl;
                        cout << "4. Update products" << endl;
                        int choice6;
                        cin >> choice6;
                        do
                        {
                            product new_product;
                            switch (choice6)
                            {
                            case 1:
                                new_product.addProduct();
                                break;
                            case 2:
                                old_seller.viewProduct();
                                break;
                            case 3:
                                old_seller.delete_product();
                                break;
                            case 4:
                                old_seller.updateProduct();
                                break;
                            default:
                                cout << "Invalid choice" << endl;
                                break;
                            }
                            cout << "What would you like to do?" << endl;
                            cout << "1. Add products" << endl;
                            cout << "2. View products" << endl;
                            cout << "3. Remove products" << endl;
                            cout << "4. Update products" << endl;
                            cin >> choice6;
                            system("cls");
                        } while (choice6 != 4);
                    }
                }
            }
        }
        if (choice == secret_code)
        {
            cout << "Welcome admin!" << endl;
            cout << "Let's get you logged in quickly" << endl;
            admin1.login();
            cout << "What would you like to do?" << endl;
            cout << "1. Add a admin" << endl;
            cout << "2. Remove a admin" << endl;
            cout << "3. View all admins" << endl;
            cout << "4. Add a seller" << endl;
            cout << "5. Remove a seller" << endl;
            cout << "6. View all sellers" << endl;
            cout << "7. Add a consumer" << endl;
            cout << "8. Remove a consumer" << endl;
            cout << "9. View all consumers" << endl;

            int choice7;
            cin >> choice7;
            system("cls");
            do
            {
                switch (choice7)
                {
                case 1:
                    admin1.add_admin();
                    break;
                case 2:
                    admin1.delete_admin();
                    break;
                case 3:
                    admin1.display_admins();
                    break;
                case 4:
                    admin1.add_producer();
                    break;
                case 5:
                    admin1.delete_producer();
                    break;
                case 6:
                    admin1.display_producer();
                    break;
                case 7:
                    admin1.add_consumer();
                    break;
                case 8:
                    admin1.delete_consumer();
                    break;
                case 9:
                    admin1.display_consumer();
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
                cout << "What would you like to do?" << endl;
            cout << "1. Add a admin" << endl;
            cout << "2. Remove a admin" << endl;
            cout << "3. View all admins" << endl;
            cout << "4. Add a seller" << endl;
            cout << "5. Remove a seller" << endl;
            cout << "6. View all sellers" << endl;
            cout << "7. Add a consumer" << endl;
            cout << "8. Remove a consumer" << endl;
            cout << "9. View all consumers" << endl;

            int choice7;
            cin >> choice7;
            system("cls");
            } while (choice7 != 10);
        }
        if (choice == 0)
        {
            cout << "Thank you for using our application" << endl;
            exit(0);
        }

        return 0;
    }
}