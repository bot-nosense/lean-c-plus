#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int x;
    while (std::cin >> x) {
        std::cout << x << "\n";
    }
    return 0;
}
