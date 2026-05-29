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
#include <cstdlib>
#include <ctime>

using namespace std;

// GLOBAL for Accounts
const int MAX_ACCOUNTS = 10000;
int pin[MAX_ACCOUNTS];
int totalAccounts = 0, option = 0;
string name[MAX_ACCOUNTS];
string surname[MAX_ACCOUNTS];
string cnic[MAX_ACCOUNTS];
string email[MAX_ACCOUNTS];
string phone[MAX_ACCOUNTS]; 
string address[MAX_ACCOUNTS];
string account[MAX_ACCOUNTS];
string accountNumber[MAX_ACCOUNTS];

// GLOBAL for games
char box[3][3]={{'1','2','3'},
                {'4','5','6'},
                {'7','8','9'}};

char currentPLayer='X';

string firstPlayer,secondPlayer;
string F_NAME;
string S_NAME;
string c_PLAYER_NAME;

int length(int);
void setPin();
void loadAccounts();
bool createNewAccount();
void saveData();
void toContinue();
bool loginToAccount();
string toHigherStr(string);
void funTime();
void numberGuess();
void ticTacToe();
void display();
void playerTurn();
bool checkWin();
bool checkDraw();
void assignAccountNumber();


int main ()
{
    srand(time(0));
    loadAccounts();

    do
    {
        // Primary Interface or Menu
        cout << "                                                                    ==============================================================" << "\n";
        cout << "                                                                    ||                B A N K I N G    S Y S T E M              || " << "\n";
        cout << "                                                                    ==============================================================" << "\n\n\n";
        cout << "                                                                    1. Create New Account" << "\n";
        cout << "                                                                    2. Login to Account" << "\n";
        cout << "                                                                    3. Admin Panel" << "\n";
        cout << "                                                                    4. Fun Time" << "\n";
        cout << "                                                                    5. Exit" << "\n\n\n";

        cout << "                                                                    Please select an option: ";
        cin >> option;
        cout << "\n\n\n"; 

        // Create Account
        if (option == 1)
        {
            bool a = false;
            a = createNewAccount();
            while (a == true)
            {
                a = createNewAccount();
            }
                  
        }   
        // else if(option == 2)
        // {
        //     loginToAccount();
        // }
        else if (option == 4)
        {
            funTime();
        }
        
    } while (option != 5);

    return 0;
}

int length(int pin) //Digit Counter 
{
    int count = 0;
    while (pin > 0)
    {
        pin /= 10;
        count++;
    }
    return count;
}

string toHigherStr(string tempStr)
{
    int i = 0;

    while (tempStr[i] != '\0')
    {
        if (tempStr[i] >= 97 && tempStr[i] <= 122)
        {
            tempStr[i] = tempStr[i] - 32;
        }
        i++;       
    }
    
    return tempStr;
}

void assignAccountNumber()
{
    int tempNum = 0, flag = 0;
    string tempStr;

    do
    {
        flag = 0, tempNum = 0;
        for (int i = 0; i < 9; i++)
        {
            tempNum = (tempNum * 10) + (rand() % 10);
        }
        tempStr = to_string(tempNum);
        for (int j = 0; j < totalAccounts; j++)
        {
            if (tempStr == accountNumber[j])
            {
                flag = 1;
                break;
            }
            
        }
        
    } while (flag == 1);
    
    accountNumber[totalAccounts - 1] = tempStr;
}

void loadAccounts()
{
    ifstream fin;

    fin.open("Accounts.txt");
    if (fin)
    {
        while (getline(fin, accountNumber[totalAccounts], '|') && totalAccounts < MAX_ACCOUNTS)
        {
            string tempPin;
            getline(fin, name[totalAccounts], '|');
            getline(fin, surname[totalAccounts], '|');
            getline(fin, cnic[totalAccounts], '|');
            getline(fin, email[totalAccounts], '|');
            getline(fin, phone[totalAccounts], '|');
            getline(fin, address[totalAccounts], '|');
            getline(fin, tempPin, '|');
            pin[totalAccounts] = stoi(tempPin);
            getline(fin, account[totalAccounts]);

            totalAccounts++;
        }
        
        fin.close();
    }
    
}

void toContinue()
{
    int choice = 0;
    do
    {
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

void saveData()
{
    assignAccountNumber();
    totalAccounts++;

    //Acounts handling in files
    ofstream fout;
    int status = 0;
    fout.open ("Accounts.txt");
    if (fout)
    {
        for (int i = 0; i < totalAccounts; i++)
        {
            fout << accountNumber[i] << "|" << name[i] << "|" << surname[i] << "|" << cnic[i] << "|" << email[i] << "|" << phone[i] << "|" << address[i] << "|" << pin[i] << "|" << account[i] << "\n";      
        }
        
        fout.close();
        cout << "                   Congrats! Your account have been registered successfully..." << "\n\n";
        cout << "Your Account Number is: " << accountNumber[totalAccounts - 1];
        status = 1;
    }
    else
    {
        cout << "                   ERROR! in managing account details..." << "\n";
        cout << "                   Please contact the helpline or try again...";
    }
    if (status == 1)
    {
        toContinue();                   
    }

}

void setPin() // Setting up the PIN
{
    int pinVerify = 0;
    do
    {
        if (pin[totalAccounts] != pinVerify)
        {
            cout << "\n" << "                   Not matched with the previous PIN... TRY AGAIN! " << "\n\n";
        }
        cout << "                                                         Please enter a four digit PIN:             |                             "; 
        cin >> pin[totalAccounts]; 
        if (length(pin[totalAccounts]) == 4)
        {
            cout << "                                                         Please Re-enter the PIN:                   |                             ";
            cin >> pinVerify; 
        }
        else
        {
            cout << "\n" << "                   PIN can only contain four digits... TRY AGAIN! " << "\n\n";
            pin[totalAccounts] = 0; 
        }
        
    } while (pin[totalAccounts] != pinVerify || length(pin[totalAccounts]) != 4);
}

bool createNewAccount()
{
    cout << "                                                                     ==============================================================" << "\n";
    cout << "                                                                     ||            C R E A T E   N E W   A C C O U N T           ||   " << "\n";
    cout << "                                                                     ==============================================================" << "\n\n\n";

            // Taking the user details
    cout << "                   Please fill in the following details: " << "\n\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
    cout << "                                                                                          PERSONAL INFORMATION" << "\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n\n\n";
    
    cin.ignore();
    while (name[totalAccounts] == "")
    {
        cout << "                                                         First Name:                                |                             ";
        getline(cin, name[totalAccounts]);
        if (name[totalAccounts] == "")
        {
            cout << "                                                         Please enter the First name:               |                             ";
            getline(cin, name[totalAccounts]);
        }
    }
    cout << "\n";
    cout << "                                                         Surname (optional - Press enter to Skip):  |                             ";
    getline(cin, surname[totalAccounts]);
    if (surname[totalAccounts] == "")
    {
        surname[totalAccounts] = "N/A";
        //cout << surname[totalAccounts];
    }
    cout << "\n";
    cout << "                                                         CNIC number:                               |                             ";
    getline(cin, cnic[totalAccounts]);
    while (cnic[totalAccounts] == "")
    {
        cout << "                                                         Please enter the CNIC:                     |                             ";
        getline(cin, cnic[totalAccounts]);
    }
    cout << "\n\n\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
    cout << "                                                                                          CONTACT INFORMATION" << "\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n\n\n";
    cout << "                                                         Email (optional - Press enter to Skip):    |                             ";
    getline(cin, email[totalAccounts]);
    if (email[totalAccounts] == "")
    {
        email[totalAccounts] = "N/A";
    }
    cout << "\n";
    cout << "                                                         Phone Number:                              |                             ";
    getline(cin, phone[totalAccounts]);
    while (phone[totalAccounts] == "")
    {
        cout << "                                                         Please enter the Phone Number:             |                             ";
        getline(cin, phone[totalAccounts]);
    }
    cout << "\n";
    cout << "                                                         Address:                                   |                             ";
    getline(cin, address[totalAccounts]);
    while (address[totalAccounts] == "")
    {
        cout << "                                                         Please enter the Address:                  |                             ";
        getline(cin, address[totalAccounts]);
    }
    cout << "\n\n\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
    cout << "                                                                                         SECURITY INFORMATION" << "\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n\n\n";
    
    setPin();

    cout << "\n\n\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";
    cout << "                                                                                          ACCOUNT INFORMATION" << "\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n\n\n";
    int select = 0;
    
    do
    {
        cout << "Your account should be:\n\n";
        cout << "1. Current\n";
        cout << "2. Saving\n\n";
        cout << "Enter your choice: ";
        cin >> select;
        if (select == 1)
        {
            account[totalAccounts] = "Current";
        }
        else if (select == 2)
        {
            account[totalAccounts] = "Saving";
        }
        else
        {
            cout << "\n\nPlease select 1 or 2...\n\n\n";
        }
        
    } while (select != 1 && select != 2);
    
    cout << "                                                         Account Type:                              |                             " << account[totalAccounts] << "\n\n\n";

    int confirm = 0;
    do
    {
        cout <<"Are you sure, you have filled the above information correctly ?\n\n";
        cout << "1. YES\n";
        cout << "2. NO\n";
        cin >> confirm;
        if (confirm == 2)
        {
           return true;
        }
        else if (confirm > 2 || confirm < 1)    
        {
            cout << "\n\nKindly enter 1 or 2 only...\n\n\n";
        }
        else
        {
            saveData();
            return false;
        }
            
    } while (confirm != 1 && confirm != 2);
    
}

void funTime()
{
    int GameChoice;
    cout <<  setw(130) << "==============================================================" << "\n";
    cout <<  setw(130) << "||                     PLAY    ZONE                         ||" << "\n";
    cout <<  setw(130) << "==============================================================" << "\n";
    
    cout << setw(85) <<"Game Categories ." << "\n";
    cout << setw(92) <<"1. Number Guessing Game."<< "\n";
    cout << setw(84) <<"2. Tic Tac toe ."<< "\n\n";

    cout << setw(103) <<"Enter game Number you want to play: ";
    cin >> GameChoice;

    if(GameChoice==1)
    {
        numberGuess();
    }
    
    if(GameChoice==2)
    {
        ticTacToe();
    }

}

void numberGuess()
{

    cout <<  setw(130) << "==============================================================" << "\n";
    cout <<  setw(130) << "||            WELCOME TO NUMBER GUESSING GAME               ||" << "\n";
    cout <<  setw(130) << "==============================================================" << "\n";
    
    int number_of_guesses=0;
    int rand_Number;
    rand_Number = rand() % 100 + 1;
    int guess;
    do
    {
        cout << setw(86) << "Guess the number: ";
        cin >> guess;
        cout << "\n";
        number_of_guesses++;
        if(guess>rand_Number)
        {
            cout << setw(113) << "Guess is too high.Enter lower number please. " <<endl;
            cout << "\n";
        }
        else if (guess<rand_Number)
        {
            cout << setw(114) << "Guess is too low. Enter higher number please. " <<endl;
            cout << "\n";
        }
        else
        {
            cout <<setw(104) << "Congrats! You Guessed the number in " << number_of_guesses << " attempts." << endl;
        }

    }while(guess!=rand_Number);
}

void ticTacToe()
{
    cout <<  setw(130) << "==============================================================" << "\n";
    cout <<  setw(130) << "||               WELCOME  TO  TIC  TAC TOE                  ||" << "\n";
    cout <<  setw(130) << "==============================================================" << "\n";

    cout << "\n";

    cout <<setw(94) << "Enter first Player Name : ";
    cin >> firstPlayer;

    F_NAME = firstPlayer;

    cout << setw(95) << "Enter Second Player Name : ";
    cin >> secondPlayer;

    cout << "\n";
    S_NAME = secondPlayer;

    c_PLAYER_NAME = firstPlayer;

    display();

    while(true)
    {
        playerTurn();

        if(checkWin())
        {
            if(currentPLayer=='X')
            {
                cout << setw(75) << "Congrats " << S_NAME << " you win the game." << endl;
            }
            else
            {
                cout << setw(75) << "Congrats " << F_NAME << " you win the game." << endl;
            }
            break;
        }
        if(checkDraw())
        {
            cout << setw(80) << "It's a draw!" << endl;
            break;
        }

    }

}
 

void display()
{
    for(int i =0;i<3;i++)
    {
        cout << setw(69);
        for(int j=0;j<3;j++)
        {
            cout << box[i][j] << setw(5);
            if(j<2)
            {
                cout << "|  ";
            }
        }
        cout << "\n";
        if(i<2)
        {
            cout << setw(85) << " ----|-----|-----  " << "\n";
        }

    }
    cout << "\n";

}

void playerTurn()
{
    int position;
    int rows,cols;

    cout << setw(74) << c_PLAYER_NAME << " it's you're turn . Please Enter a position: ";
    cin >> position;
    
    cout << "\n";

    switch (position)
    {
    case 1:
        rows=0;
        cols=0;
        break;
    case 2:
        rows=0;
        cols=1;
        break;
    case 3:
        rows=0;
        cols=2;
        break;
    case 4:
        rows=1;
        cols=0;
        break;
    case 5:
        rows=1;
        cols=1;
        break;
    case 6:
        rows=1;
        cols=2;
        break;
    case 7:
        rows=2;
        cols=0;
        break;
    case 8:
        rows=2;
        cols=1;
        break;
    case 9:
        rows=2;
        cols=2;
        break;
    default:
        break;
    }
    if(position<1 || position>9 || box[rows][cols]=='X' || box[rows][cols]=='O')
    {
        cout << setw(91) << "Invalid move. Try again." << endl;
        playerTurn();
        return;
    }

    box[rows][cols]=currentPLayer;

    if(currentPLayer=='X')
    {
        currentPLayer='O';
        c_PLAYER_NAME=secondPlayer;

    }
    else
    {
        currentPLayer='X';
        c_PLAYER_NAME=firstPlayer;
    }
    
    display();
    cout << "\n";

}

bool checkWin()
{ 
    // check rows whether they are equal or not

    for(int i=0;i<3;i++)
    {
        if(box[i][0]==box[i][1] && box[i][1]==box[i][2])
        {
            return true;
        }
    }

    // check colums whether they are equal or not

    for(int i=0;i<3;i++)
    {
        if(box[0][i]==box[1][i] && box[1][i]==box[2][i])   
        {
            return true;
        }
    }

    // check dioganols whether they are equal or not

    if(box[0][0]==box[1][1] && box[1][1]==box[2][2])
    {
        return true;
    }

    if(box[0][2]==box[1][1] && box[1][1]==box[2][0])
    {
        return true;
    }
    return false;   
}

bool checkDraw()
{
    // It's check that rows ,colums and diagonal are not of same category.

    for(int i=0;i<3;i++)
    {

        for(int j=0;j<3;j++)

        {
            if(box[i][j]!='X' && box[i][j]!='O')

            {
                return false;
            }
        }
    }

    return true;
}
