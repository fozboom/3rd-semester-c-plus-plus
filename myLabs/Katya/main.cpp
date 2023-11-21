#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    int option;

    while (true)
    {
        cout << "Choose an option (1-4): " << endl;
        cout << "1. Create a Teacher" << endl;
        cout << "2. Create a Union Member" << endl;
        cout << "3. Create a Union Member and Teacher" << endl;
        cout << "4. View default info" << endl;
        cout << "0. Exit" << endl;

        cin >> option;
        try
        {
            if (option == 0)
            {
                cout << "Exiting the program." << endl;
                break;
            } else if (option == 1)
            {
                task1( );
            } else if (option == 2)
            {
                task2( );
            } else if (option == 3)
            {
                task3( );
            } else if (option == 4)
            {
                task4( );
            } else
            {
                cout << "Invalid option." << endl;
            }
        }catch (ExceptionInputAge& ex)
        {
            std::cerr << ex.what();
        }
        catch (ExceptionInputData& ex)
        {
            std::cerr << ex.what();
        }
        catch (ExceptionInputNumber& ex)
        {
            std::cerr << ex.what();
        }
    }
    return 0;
}