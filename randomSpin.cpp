#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string element[100];
    FILE *ptr;
    int i = 0;
    ptr = fopen("spinItemsInput.txt", "r");

    fstream f("spinItemsInput.txt", ios::in);

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

            c = fgetc(ptr);
        }

        for (int i = 0; i < i; i++)
        {
            cout << element[i] << endl;
        }
    }

    return 0;
}