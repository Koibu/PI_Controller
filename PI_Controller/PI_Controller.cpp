// PI_Controller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

std::vector<double> temperature;

double temperature_changes()
{
    // TODO Here we need some kind of history information.
    return 0;
}

std::string drive_fan()
{
    int middle;
    int tmpp = 0;
    int tmpf = 0;

    double past_values = 0;
    double future_values = 0;
    double past_average = 0;
    double future_average = 0;

    std::string past;
    std::string future;

    if (temperature.size() < 10) {
        return "Liian vähän dataa";
    }
    middle = temperature.size() / 2;
    for (std::vector<double>::iterator it = temperature.begin(); it != temperature.end(); ++it)
    {
        if (tmpp < middle)
        {
            past_values = past_values + *it;
            tmpp++;
        }
        else
        {
            future_values = future_values + *it;
        }
    }
    past_average = past_values / middle;
    future_average = future_values / middle;

    return "Past average: " + std::to_string(past_average) + " Future_average: " + std::to_string(future_average);

}

double check_temperature() 
{  
    int grow = rand() % 10 + 1;
    if ((grow % 2) == 0)
    {
        temperature.push_back(temperature.back() + (double)grow);
    } 
    else
    {
        temperature.push_back(temperature.back() - (double)grow);
    }

    return temperature.back();
}

int main()
{
    bool running = true;
    double T;
    char mark = ' ';
    std::cout << "Program started\n";
    temperature.push_back(22);
    while (running) 
    {
        T=check_temperature();
        drive_fan();
        std::cout << "Lopeta/jatka [L/j]";
        std::cout << temperature.back() << std::endl;
        std::cout << "Temperature vector size: " << temperature.size() << std::endl;
        std::cout << drive_fan() << std::endl;
        std::cin >> mark;
        if (mark == 'L')
        {
            break;
        }
    }
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
