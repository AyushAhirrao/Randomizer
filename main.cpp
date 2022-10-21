#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

using namespace std;

int main()
{
    srand(time(0));
    int random_number_flip = rand() % 100;
    int rand_number_loop = rand() % 100;

    int choice;
    cout << "[1] Toss" << endl
         << "[2] Spin wheel" << endl
         << "[0] Exit\n"
         << endl;

    cout << "Enter your choice [1-2] : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        for (int i = 0; i < random_number_flip; i++)
        {
            cout << "Heads\n";
            usleep(50000);
            system("clear");
            cout << "Tails\n";
            usleep(50000);
            system("clear");
        }

        if (rand() % 100 >= 50)
        {
            cout << "Heads" << endl;
            exit(1);
        }
        else
        {
            cout << "Tails" << endl;
            exit(1);
        }

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