#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <fstream>
#include <string>

class login {
public:	
    void Menu();
    
private:
    bool IsLoggedIn();
    void Register();

	std::string username, password, un, pw;
    int choice;
    bool loginStatus;
};

bool login::IsLoggedIn() 
{
    cout << "Enter username: " << endl; cin >> username;
    cout << "Enter password: " << endl; cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password) {
        cout << "Successfully logged in!" << endl;
        loginStatus = true;
        return true;
    }
    else {
        cout << "False Login!" << endl;
        loginStatus = true;
        return false;
    }
        
}

void login::Menu() 
{
    cout << "1: Register" << endl
         << "2: LogIn" << endl
         << "Your Choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            Register();
            break;
        case 2:
            IsLoggedIn();
            break;
        default:
            cout << "Invalid Selection";
    }
}

void login::Register() {
    cout << "Select a Username: "; cin >> username;
    cout << "Select a Password: "; cin >> password;

    ofstream file;
    file.open("data\\" + username + ".txt");

    file << username << endl << password << endl;
    file.close();
}


#endif
