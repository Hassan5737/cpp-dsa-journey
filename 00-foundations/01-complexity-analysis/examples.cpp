/*
===============================================================================
                        Complexity Analysis Examples
===============================================================================

Project : cpp-dsa-journey
Module  : 00-foundations / 01-complexity-analysis

Description:
    This file contains practical examples demonstrating the most common
    time complexity classes. Each example focuses on a single concept
    to make complexity analysis easier to understand.

Covered Complexities:
    • O(1)      Constant Time
    • O(n)      Linear Time
    • O(log n)  Logarithmic Time
    • O(n log n) Linearithmic Time
    • O(n²)     Quadratic Time

===============================================================================
*/

#include <iostream>
#include <vector>

using namespace std;

/*
===============================================================================
O(1) - Constant Time
-------------------------------------------------------------------------------
Accessing an element by its index takes constant time because the memory
address can be calculated directly.
===============================================================================
*/

void constantTimeExample()
{
    vector<int> numbers = {10, 20, 30, 40, 50};

    cout << "Element at index 2: " << numbers[2] << endl;
}

/*
===============================================================================
O(n) - Linear Time
-------------------------------------------------------------------------------
The algorithm visits every element exactly once.
===============================================================================
*/

void linearTimeExample()
{
    vector<int> numbers = {10, 20, 30, 40, 50};

    cout << "Array Elements: ";

    for (int value : numbers)
    {
        cout << value << " ";
    }

    cout << endl;
}

/*
===============================================================================
O(log n) - Logarithmic Time
-------------------------------------------------------------------------------
The iterator doubles every iteration, reducing the remaining work
by half each time.
===============================================================================
*/

void logarithmicTimeExample()
{
    cout << "Values: ";

    for (int i = 1; i <= 64; i *= 2)
    {
        cout << i << " ";
    }

    cout << endl;
}

/*
===============================================================================
O(n log n) - Linearithmic Time
-------------------------------------------------------------------------------
The outer loop grows logarithmically while the inner loop processes
all elements.
===============================================================================
*/

void linearithmicTimeExample()
{
    const int n = 8;

    for (int i = 1; i < n; i *= 2)
    {
        for (int j = 0; j < n; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}

/*
===============================================================================
O(n²) - Quadratic Time
-------------------------------------------------------------------------------
Nested loops multiply their complexities.
===============================================================================
*/

void quadraticTimeExample()
{
    const int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "(" << i << ", " << j << ") ";
        }

        cout << endl;
    }
}

int main()
{
    cout << "==================================================\n";
    cout << "Complexity Analysis Examples\n";
    cout << "==================================================\n\n";

    cout << "O(1) Example\n";
    constantTimeExample();

    cout << "\n----------------------------------------\n\n";

    cout << "O(n) Example\n";
    linearTimeExample();

    cout << "\n----------------------------------------\n\n";

    cout << "O(log n) Example\n";
    logarithmicTimeExample();

    cout << "\n----------------------------------------\n\n";

    cout << "O(n log n) Example\n";
    linearithmicTimeExample();

    cout << "\n----------------------------------------\n\n";

    cout << "O(n²) Example\n";
    quadraticTimeExample();

    return 0;
}