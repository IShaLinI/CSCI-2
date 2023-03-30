//Andrew Card

#include <iostream>
#include <fstream>

using namespace std;

enum menuOptions{
    LANDING,
    LOGIN,
    REGISTER,
    DATABASE_SORT_OPTIONS,
    DATABASE_A_Z_SELECT,
    DATABASE_HIST
};

int main(){
    
    system("cls");

    char input;
    menuOptions currentMenu = LANDING;

    while(true){
        if(currentMenu == LANDING){

            ifstream f("menus/landing.txt");
            if(f.is_open()){
                cout << f.rdbuf();
                f.close();
            }

            cin >> input;

            switch(input){
                case '1':
                    currentMenu = LOGIN;
                    break;
                case '2':
                    currentMenu = REGISTER;
                    break;
                case '3':
                    currentMenu = DATABASE_SORT_OPTIONS;
                    break;
                case '4':
                    cout << "Logging out of system: Goodbye!";
                    return 0;
                    break;
                default:
                    cout << "Invalid input" << endl;
                    break;
            }

            system("cls");

        }

        cout << "You are in the " << currentMenu << " menu" << endl;

    }
    

    return 0;
}