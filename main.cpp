#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int choice;
    cout << "[1] Toss" << endl
         << "[2] Spin wheel" << endl
         << "[0] Exit\n" << endl;

    cout << "Enter your choice [1-2] : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        break;

    case 2:
        break;

    case 0:
        exit(1);

    default:
        cout << "Invalid input";
        break;
    }
}