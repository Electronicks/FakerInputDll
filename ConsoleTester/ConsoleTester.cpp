// ConsoleTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "fakerinputclient.h"

int main()
{
    std::cout << "Hello World!\n";
    auto fic = fakerinput_alloc();

    if (!fakerinput_connect(fic))
    {
        std::cout << "Boohoo, can't connect";
    }
    else
    {
        while (std::cin.get() != 'q')
        {
            if (!fakerinput_update_relative_mouse(fic, 0, 100, 100, 0, 0))
            {
                std::cout << "Boohoo, can't update relative";
            }
        }
        fakerinput_disconnect(fic);
    }
    fakerinput_free(fic);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
