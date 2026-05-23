/* 
----------- Project by TECH SPINE -----------

Ahmad Zahid     ---------------    BITF25A003
M Huzaifa Shah  ---------------    BITF25A036
Adil Raffe      ---------------    BITF25A051

*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


int length(int pin) //Digit Counter Function
{
    int count = 0;
    while (pin > 0)
    {
        pin /= 10;
        count++;
    }
    return count;
}

int setPin() // Setting up the PIN
{
    int pin = 0, pinVerify = 0;
    do
    {
        if (pin != pinVerify)
        {
            cout << "\n" << "                   Not matched with the previous PIN... TRY AGAIN! " << "\n\n";
        }
        cout << "                                                         Please enter a four digit PIN:             |                             "; 
        cin >> pin; 
        if (length(pin) == 4)
        {
            cout << "                                                         Please Re-enter the PIN:                   |                             ";
            cin >> pinVerify; 
        }
        else
        {
            cout << "\n" << "                   PIN can only contain four digits... TRY AGAIN! " << "\n\n";
            pin = 0; 
        }
        
    } while (pin != pinVerify || length(pin) != 4);
    return pin;
}

int main ()
{
    //Variables of main function
    int option = 0;

    do
    {
        // Primary Interface or Menu
        cout << "                                                                    ==============================================================" << "\n";
        cout << "                                                                    ||                B A N K I N G    S Y S T E M              || " << "\n";
        cout << "                                                                    ==============================================================" << "\n\n\n";
        cout << "                                                                    1. Create New Account" << "\n";
        cout << "                                                                    2. Login to Account" << "\n";
        cout << "                                                                    3. Admin Panel" << "\n";
        cout << "                                                                    4. Play Zone" << "\n";
        cout << "                                                                    5. Exit" << "\n\n\n";

        cout << "                                                                    Please select an option: ";
        cin >> option;
        cout << "\n\n\n"; 

        // Create Account
        if (option == 1)
        {
            string name, surname, cnic, email, phone, address, account;
            int pin = 0, pinVerify = 0;

            cout << "                                                                     ==============================================================" << "\n";
            cout << "                                                                     ||            C R E A T E   N E W   A C C O U N T           ||   " << "\n";
            cout << "                                                                     ==============================================================" << "\n\n\n";

            // Taking the user details
            cout << "                   Please fill in the following details: " << "\n\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
            cout << "                                                                                          PERSONAL INFORMATION" << "\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n\n\n";
    
            cin.ignore();
            while (name == "")
            {
                cout << "                                                         First Name:                                |                             ";
                getline(cin, name);
                if (name == "")
                {
                    cout << "                                                         Please enter the First name:               |                             ";
                    getline(cin, name);
                }
            }
            cout << "\n";
            cout << "                                                         Surname (optional - Press enter to Skip):  |                             ";
            getline(cin, surname);
            if (surname == "")
            {
                surname = "N/A";
                //cout << surname;
            }
            cout << "\n";
            cout << "                                                         CNIC number:                               |                             ";
            getline(cin, cnic);
            while (cnic == "")
            {
                cout << "                                                         Please enter the CNIC:                     |                             ";
                getline(cin, cnic);
            }
            cout << "\n\n\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
            cout << "                                                                                          CONTACT INFORMATION" << "\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n\n\n";
            cout << "                                                         Email (optional - Press enter to Skip):    |                             ";
            getline(cin, email);
            if (email == "")
            {
                email = "N/A";
            }
            cout << "\n";
            cout << "                                                         Phone Number:                              |                             ";
            getline(cin, phone);
            while (phone == "")
            {
                cout << "                                                         Please enter the Phone Number:             |                             ";
                getline(cin, phone);
            }
            cout << "\n";
            cout << "                                                         Address:                                   |                             ";
            getline(cin, address);
            while (address == "")
            {
                cout << "                                                         Please enter the Address:                  |                             ";
                getline(cin, address);
            }
            cout << "\n\n\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
            cout << "                                                                                         SECURITY INFORMATION" << "\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n\n\n";
            pin = setPin();
            cout << "\n\n\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
            cout << "                                                                                          ACCOUNT INFORMATION" << "\n";
            cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n\n\n";
            cout << "                                                         Account Type (Savings or Current):         |                             ";
            cin >> account;
            while (account != "Savings" && account != "Saving" && account != "current" && account != "Current" && account != "savings" && account != "saving")
            {
                cout << "                   Please enter the valid account type..." << "\n";
                cout << "                                                         Account Type (Savings or Current):         |                             ";
                cin >> account;
            }
            
            //Acounts handling in files
            ofstream fout;
            int status = 0;
            fout.open ("Account.txt");
            if (fout)
            {
                fout << name << pin << " " << surname << " " << cnic << " " << email << " " << phone << " " << address << " " << account;
                fout.close();
                cout << "                   Congrats! Your account have been registered successfully..." << "\n\n";
                status = 1;
            }
            else
            {
                cout << "                   ERROR! in managing account details..." << "\n";
                cout << "                   Please contact the helpline...";
            }
            if (status = 1)
            {
                int choice = 0;
                do
                {
                    status = 0;
                    cout << "                                      You want to:" << "\n\n";
                    cout << "                                      1. Go back to main" << "\n";
                    cout << "                                      2. Exit" << "\n\n";
                    cout << "                                      Enter your choice: ";
                    cin >> choice;
                } while (choice != 1 && choice != 2);
                if (choice == 2)
                {
                    option = 5;
                }
                
            
            }
            
        }
        
    } while (option != 5);

    return 0;
}     
 











