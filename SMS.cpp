#include <iostream>
#include <stdexcept>
#include <thread>
using namespace std; 

void welcomeMessage()
{
    cout << "STUDENT MANAGMENT SYSTEM ©2000-2001 ANDAMAN MICROSYSTEMS, ALL RIGHTS RESERVED";
    this_thread::sleep_for(chrono::seconds(3));
};

void getOption()
{
    int option;
    cout << "** SMS Main Menu ***\n" ;
    cout << "[1] Load Starting Data\n";
    cout << "[2] Show Student Records\n";
    cout << "[3] Add/Delete Students\n"; 
    cout << "[4] Edit Students\n"; 
    cout << "[5] Generate Transcript\n"; 
    cout << "[6] Credits and Exit\n"; 
    cout << "*********************"; 
    cout << "Option (1 - 6):";
    cin >> option; 
    try {
        if (option < 1 || option > 6 || cin.fail()) { 
            throw runtime_error(
                "Error! Please enter a number corresponding to the available options (1 - 6)"
            );
        }
        cout << "You have selected option" << option << endl; 
        switch(option) {
            case 1:
                load();
                break; 
            case 2:
                showRecord(); 
                break;
            case 3:
                addDelete(); 
                break;
            case 4:
                edit();
                break;
            case 5:
                genTranscript(); 
                break; 
            case 6:
                creditExit();
                break;
            }
    } catch (const runtime_error& e) { 
        cout << e.what() << endl;
        cin.clear(); 
        cin.ignore(1000, '\n');
        getOption();
    }
};
int main()
{
    welcomeMessage();
    getOption(); 
    return 0;
}