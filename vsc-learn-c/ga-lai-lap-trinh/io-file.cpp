#include <iostream>
#include <sstream>

int getInt(const std::string& prompt)
{
    int value;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        if (iss >> value && iss.eof()) return value;
        else std::cout << "Invalid input. Please try again.\n";
    }
}

float getFloat(const std::string& prompt)
{
    float value;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        if (iss >> value && iss.eof()) return value;
        else std::cout << "Invalid input. Please try again.\n";
    }
}

std::string getString(const std::string& prompt)
{
    std::string value;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty()) return value;
        else std::cout << "Invalid input. Please try again.\n";
    }
}

int main ()
{
    std::ios::sync_with_stdio(false);

    int a;
    float b;
    std::string c;

    std::cout<<"hello world" << '\n';
    a = getInt("Enter a: ");
    b = getFloat("Enter b: ");
    c = getString("Enter c: ");
    std::cout<< a << " " << b << " " << c;

    std::cin.ignore();
    std::cin.get();
    return 0;
}