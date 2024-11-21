//#include <iostream>
//#include <string> 
//#include <typeinfo>
//
//using namespace std;
//
///* Đổi chỗ 2 giá trị */
//
//void swapByValue(int x, int y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//void swapByReference(int& x, int& y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//
///* tính tổng hiệu 2 số */
//struct ThamTri
//{
//	int sum;
//	int diff;
//};
//
//ThamTri caculator(int x, int y)
//{
//	ThamTri result;
//	result.sum = x + y;
//	result.diff = x - y;
//	return result; // tất cả các giá trị đều gói gọn vào result -> dễ quản lý với nhiều tham số
//}
//
//void caculatorByReferenceValue(int x, int y, int& sum, int& diff)
//{
//	sum = x + y;
//	diff = x - y;
//}
//
//void TongHieu(int a, int b, int sum, int diff)
//{
//	ThamTri result = caculator(a, b); // clone ra 1 result để hứng kết quả của hàm caculator() bên trên -> x2 bộ nhớ 
//	cout << result.sum << "end " << result.diff << endl;
//
//	caculatorByReferenceValue(a, b, sum, diff); // cập nhật trực tiếp vào 2 biến đc tạo trong main 
//	cout << sum << "end " << diff << endl;
//}
//
//
//
///* đảo ngược mảng*/
//void reverseArrayByValue(int arr[], int size)
//{
//	int temp = arr[size];
//	for (int i = size; i > 0; i--)
//	{
//		arr[size] = a[]
//	}
//}
//
//
//int main()
//{
//	int a = 10, b = 3;
//	int sum, diff;
//
//	//TongHieu(a, b, sum, diff);
//
//	return 0;
//}