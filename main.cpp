#include <iostream>
#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <time.h>

using namespace std;

void animation(string element[], int size);

int main(int argc, char *argv[])
{
    system("clear");
    srand(time(0));

    int random_number_flip = rand() % 100;
    int rand_number_loop = rand() % 100;

    int choice;

    int i = 0;
    int lineCount = 1;

    string element[100];

    FILE *ptr;
    fstream f("spinItemsInput.txt", ios::in);

    ptr = fopen("spinItemsInput.txt", "r");

    if (argc == 2)
    {
        if (strcmp(argv[1], "toss") == 0)
        {
            goto toss;
        }
        else if (strcmp(argv[1], "spin") == 0)
        {
            goto spin;
        }
    }

    cout << "[1] Toss" << endl
         << "[2] Spin wheel" << endl
         << "[0] Exit\n"
         << endl;

    cout << "Enter your choice [1-2] : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    toss:
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
    spin:
        system("clear");
        cout << "Input elements in the file" << endl;
        sleep(2);
        system("nano spinItemsInput.txt");

        if (ptr == NULL)
        {
            cout << "Input elements in the file\n and run program again";
        }
        else
        {
            char c = fgetc(ptr);
            while (c != EOF)
            {
                if (f.is_open())
                {
                    getline(f, element[i]);
                    i++;
                }
                if (c == '\n')
                {
                    lineCount++;
                }

                c = fgetc(ptr);
            }
            system("clear");
            animation(element, lineCount - 1);
        }

        break;

    case 0:
        exit(1);

    default:
        cout << "Invalid input";
        break;
    }
}

void animation(string element[], int size)
{
    int speed = 150000;
    int random;
    for (int runTime = 1; runTime < 100; runTime++)
    {

        for (int i = 1; i <= size; i++)
        {
            system("clear");
            for (int j = 1; j <= size; j++)
            {
                random = rand() % 100;
                if (j == i)
                {

                    cout << ">";
                }
                else
                {
                    cout << " ";
                }
                cout << " " << element[j - 1] << endl;
            }
            if (random <= 2)
            {
                goto stop;
            }
            // cout << random << endl;
            // if (runTime == 7)
            // {
            //     speed = 500000;
            // }
            usleep(speed);
        }
    }
stop:
    cout << "";
}