#include <iostream>

int main()
{
    int n;

    std::cout<<"Nhap vao do dai tam giac" << '\n';
    std::cin>>n;


    std::cout<<"tam giac nguoc"<<'\n';
    for (int i = n; i > 0; i--)
    {
        for (int a = 0; a < i; a++)
        {
            std::cout<<'*';
        }
        std::cout<<'\n';
    }

    std::cout<<"tam giac xuoi"<<'\n';
    for (int a = 1; a <= n; a++) // bắt đầu từ 1 vì b = 0, nếu a cùng bằng 0, nó sẽ skip qua đoạn điều kiện b<a -> in ra kết quả không đúng như mong muôns
    {
        for (int  b = 0; b < a; b++)
        {
            std::cout<<"*";
        }
        std::cout<<'\n';
    }
    
    std::cout<<"tam giac xuoi lech phai";
    std::cout<<"tam giac nguoc lech phai";
    std::cout<<"tam giac can";
    std::cout<<"tam giac can nguoc";
    std::cout<<"hinh thoi";
    std::cout<<"hinh vuong";
    std::cout<<"hinh chu nhat";
    std::cout<<"tam giac pascal";


    
    std::cin.ignore();
    std::cin.get();
    return 0;
}