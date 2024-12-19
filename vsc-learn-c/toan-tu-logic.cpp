#include <iostream>

int main()
{
    int a = 0;
    std::cout << "nhap vao 1 so" << std::endl;
    std::cin >> a;

    if (a > 0 && a < 10) std::cout << "a nam trong khoan tu 0 toi 10";
    else std::cout << "a k nam trong khoang 0-10";

    std::cin.ignore();
    std::cin.get();
    return 0;
}