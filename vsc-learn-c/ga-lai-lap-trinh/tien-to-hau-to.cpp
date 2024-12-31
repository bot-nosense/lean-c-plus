#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);

    int a, b;
    std::cout <<a++ << '\n';
    std::cout <<++b << '\n';

    std::cin.ignore();
    std::cin.get();
    return 0;
}