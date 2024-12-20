#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);

    int a = 0;
    std::cout << "enter a number" << '\n';
    std::cin >> a; 

    if (a > 0 && a < 10) std::cout << "number is in the range 0 - 10";
    else std::cout << "number is not in the range 0 - 10";

    std::cin.ignore();
    std::cin.get();
    return 0;
}
    
