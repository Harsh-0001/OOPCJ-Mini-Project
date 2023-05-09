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
            file.open("admin.txt", ios::app);
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
            file.open("admin.txt");
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
    cout << "Welcome to Online Shopping Portal\n";






    //Admin
    cout<<"Are you an administartor?\n";
    int choice;
    cout<<"1. Yes\n";
    cout<<"2. No\n";
    cin>>choice;
    if(choice == 1)
    {
        admin a;
        a.add_admin();
        int cont;
        do
        {
        cout<<"Welcome Admin!\n";
        cout<<"1. Add a admin"<<endl;
        cout<<"2. Remove a admin"<<endl;
        cout<<"3. Display all admins"<<endl;
        cout<<"4. Add a producer"<<endl;
        cout<<"5. Remove a producer"<<endl;
        cout<<"6. Display all producers"<<endl;
        cout<<"7. Add a consumer"<<endl;
        cout<<"8. Remove a consumer"<<endl;
        cout<<"9. Display all consumers"<<endl;
        cout<<"10. Verify that you are an admin"<<endl;
        cout<<"11. Register as an admin"<<endl;
        int choiceint;
        cin>>choiceint;
        if(choiceint == 1)
        {
            admin b;
            b.add_admin();
        }
        else if(choiceint == 2)
        {
            a.delete_admin();
        }
        else if(choiceint == 3)
        {
            a.display_admins();
        }
        else if(choiceint == 4)
        {
            a.add_producer();
        }
        else if(choiceint == 5)
        {
            a.delete_producer();
        }
        else if(choiceint == 6)
        {
            a.display_producer();
        }
        else if(choiceint == 7)
        {
            a.add_consumer();
        }
        else if(choiceint == 8)
        {
            a.delete_consumer();
        }
        else if(choiceint == 9)
        {
            a.display_consumer();
        }
        else if(choiceint == 10)
        {
            a.login();
        }
        else if(choiceint == 11)
        {
            a.register_user();
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
        cout<<"Do you want to continue operations as an admin?\n";
        cin>>cont;
    }while(cont == 1);

}

else{
    cout<<"Okay, let's continue\n";
}






//Producer
cout<<"Are you an producer?\n";
    
    cout<<"1. Yes\n";
    cout<<"2. No\n";
    cin>>choice;
    int cont;
    if(choice == 1)
    {
         producer p;
         product prod;
    do{
    
       
        cout<<"Welcome Producer!\n";
        cout<<"1. Add a product"<<endl;
        cout<<"2. Remove a product"<<endl;
        cout<<"3. Display all products"<<endl;
        cout<<"4. Verify that you are a producer"<<endl;
        cout<<"5. Register as a producer"<<endl;
        int choiceint;
        cin>>choiceint;
       
        if(choiceint == 1)
        {
            prod.addProduct();
        }
        else if(choiceint == 2)
        {
            p.delete_product();
        }
        else if(choiceint == 3)
        {
            p.viewProduct();
        }
        else if(choiceint == 4)
        {
            p.login();
        }
        else if(choiceint == 5)
        {
            p.register_user();
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
          cout<<"Do you want to continue operations as an producer?\n";
    cin>>cont;

}while(cont == 1);
    }
else{
    cout<<"Okay, let's continue\n";
}   




//Consumer
cout << "Are you a consumer?\n";
cout << "1. Yes\n";
cout << "2. No\n";
cin >> choice;
if(choice == 1)
{
    Consumer c;
    product prod;
    string item;
    string card;
    string ed;
    string cvv;
    do
    {
        cout << "Welcome Consumer!\n";
        cout << "0. View all products\n";
        cout << "1. Add a product to cart\n";
        cout << "2. Remove a product from cart\n";
        cout << "3. View cart\n";
        cout << "4. Checkout\n";
        cout << "5. Pay\n";
        cout << "6. Verify that you are a consumer\n";
        cout << "7. Register as a consumer\n";
        int choiceint;
        cin >> choiceint;
        if(choice == 0)
        {
            c.viewProducts();
        }
        else if (choiceint == 1)
        {
            cout<<"Enter the name of the product you want to add to cart\n";                                                                                                
            cin>>item;
            c.addToCart(item);
        }
        else if (choiceint == 2)
        {
            cout<<"Enter the name of the product you want to remove from cart\n";
            cin>>item;
            c.removeFromCart(item);
        }
        else if (choiceint == 3)
        {
            c.viewCart();
        }
        else if (choiceint == 4)
        {
            c.checkout();
        }
        else if (choiceint == 5)
        {
            cout<<"Enter your card number\n";
            cin>>card;
            cout<<"Enter the expiry date of your card\n";
            cin>>ed;
            cout<<"Enter the CVV of your card\n";
            cin>>cvv;
            c.pay(card, ed, cvv);
        }
        else if (choiceint == 6)
        {
            c.login();
        }
        else if (choiceint == 7)
        {
            c.register_user();
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
        cout << "Do you want to continue operations as a consumer?\n";
        cin >> cont;
    } while (cont == 1);
}

cout<<"Thank you for using our services!\n";
return 0;
}