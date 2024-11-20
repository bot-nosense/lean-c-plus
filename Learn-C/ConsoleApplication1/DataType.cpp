#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string> 
#include <typeinfo>

using namespace std;

/*
Bài tập cơ bản:

Bài 1: Viết chương trình để thực hiện chuyển đổi từ int sang double bằng static_cast. In kết quả ra màn hình.
Bài 2: Sử dụng const_cast để loại bỏ thuộc tính const của một biến const int và thay đổi giá trị của nó.
Bài 3: Viết chương trình chuyển đổi một con trỏ int* sang con trỏ void* và ngược lại bằng reinterpret_cast.
Bài 4: Cho hai lớp Base và Derived với quan hệ kế thừa. Viết chương trình minh họa việc chuyển đổi từ Base* sang Derived* bằng cả static_cast và dynamic_cast.
		Trường hợp nào static_cast dẫn đến hành vi không mong muốn?
Bài 5: Sử dụng dynamic_cast để kiểm tra xem một đối tượng có thực sự thuộc lớp dẫn xuất (derived class) hay không. In kết quả tương ứng ra màn hình.
Gợi ý: Tạo thêm một lớp không liên quan để minh họa tình huống thất bại.
Bài 6: Viết chương trình đọc một chuỗi ký tự từ người dùng, sau đó chuyển đổi nó sang kiểu số nguyên (int) bằng cách sử dụng static_cast. Nếu chuyển đổi không thành công, hãy thông báo lỗi.
Bài 7: Xây dựng một chương trình với mảng các đối tượng Base trỏ tới Derived. Sử dụng dynamic_cast để kiểm tra xem đối tượng thực sự là Derived hay không, sau đó gọi một phương thức cụ thể của Derived.
Bài 8: Viết chương trình minh họa việc sử dụng reinterpret_cast để thay đổi cách diễn giải dữ liệu của một biến (ví dụ: chuyển một số nguyên thành một chuỗi byte).
*/

/*Bài 1: Viết chương trình để thực hiện chuyển đổi từ int sang double bằng static_cast. In kết quả ra màn hình.*/
double Ex1(int a)
{
	return static_cast<double>(a);
}

/*Bài 2: Sử dụng const_cast để loại bỏ thuộc tính const của một biến const int và thay đổi giá trị của nó.*/
float Ex2(int a)
{
	float b;
	b = 1.3f;
	//b = const_cast<float>(a);
	return b;
}

//int main()
//{
//	short a = 10;
//	int b;
//	b = a;
//
//	cout << typeid(a).name() << endl;
//
//	return 0;
//}
