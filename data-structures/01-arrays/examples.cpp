/*
===============================================================================
                            Arrays Fundamentals Examples
===============================================================================

Project : cpp-dsa-journey
Module  : Data Structures / Arrays

Description:
    This file contains practical examples demonstrating the fundamental
    operations on arrays in C++.

Covered Topics:
    • Creating an array
    • Updating elements
    • Reading input
    • Accessing elements
    • Traversing an array

===============================================================================
*/

#include <iostream>

using namespace std;

/*
===============================================================================
Create an Array
===============================================================================
*/

void createArrayExample()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    cout << "Array created successfully." << endl;
}

/*
===============================================================================
Update an Element
===============================================================================
*/

void updateElementExample()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    numbers[2] = 100;

    cout << "Updated element: " << numbers[2] << endl;
}

/*
===============================================================================
Read Input
===============================================================================
*/

void userInputExample()
{
    int numbers[5];

    cout << "Enter 5 integers: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> numbers[i];
    }

    cout << "Input stored successfully." << endl;
}

/*
===============================================================================
Access an Element
Time Complexity: O(1)
===============================================================================
*/

void accessElementExample()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    cout << "First element: " << numbers[0] << endl;
}

/*
===============================================================================
Traverse an Array
Time Complexity: O(n)
===============================================================================
*/

void traverseArrayExample()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    cout << "Array elements: ";

    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;
}

int main()
{
    cout << "=========================================\n";
    cout << "Arrays Fundamentals Examples\n";
    cout << "=========================================\n\n";

    createArrayExample();

    cout << "\n-----------------------------------------\n\n";

    updateElementExample();

    cout << "\n-----------------------------------------\n\n";

    accessElementExample();

    cout << "\n-----------------------------------------\n\n";

    traverseArrayExample();

    cout << "\n-----------------------------------------\n\n";

    userInputExample();

    return 0;
}