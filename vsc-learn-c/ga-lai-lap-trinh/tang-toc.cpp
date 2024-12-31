#include <iostream>
#include <chrono>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++) 
    {
        std::cout<<""<<std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();

    // Tính toán thời gian chạy
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Thời gian chạy: " << elapsed.count() << " giây" << std::endl;

    std::cin.ignore();
    std::cin.get();
    return 0;
}
