//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <sstream>
//
//using namespace std;
//
//// Hàm cộng chuỗi
//void string_add(const string& str1, const string& str2) {
//    cout << "Kết quả: " << str1 + str2 << endl;
//}
//
//// Hàm trừ chuỗi
//void string_subtract(string& str1, const string& str2) {
//    size_t pos = str1.find(str2);
//    if (pos != string::npos) {
//        str1.erase(pos, str2.length());  // Loại bỏ chuỗi con khỏi chuỗi lớn
//    }
//    cout << "Kết quả: " << str1 << endl;
//}
//
//// Hàm nhân chuỗi
//void string_multiply(const string& str, int times) {
//    for (int i = 0; i < times; ++i) {
//        cout << str;  // Lặp lại chuỗi mà không có khoảng trắng
//    }
//    cout << endl;  // Xuống dòng sau khi lặp lại
//}
//
//// Hàm chia chuỗi (đếm số lần xuất hiện của một từ con)
//int string_divide(const string& str, const string& word) {
//    int count = 0;
//    size_t pos = 0;
//    while ((pos = str.find(word, pos)) != string::npos) {
//        ++count;
//        pos += word.length();  // Di chuyển đến vị trí tiếp theo
//    }
//    return count;
//}
//
//// Hàm xử lý phép nhân
//int handle_multiplication(const string& expr) {
//    string str1;
//    int times;
//    size_t pos = expr.find(" * ");
//    if (pos != string::npos) {
//        str1 = expr.substr(0, pos);  // Lấy chuỗi trước dấu '*'
//        times = stoi(expr.substr(pos + 3));  // Lấy số lần nhân sau dấu '*'
//    }
//
//    string_multiply(str1, times);  // Thực hiện phép nhân chuỗi
//    return times;  // Trả về kết quả nhân
//}
//
//// Hàm xử lý phép trừ
//int handle_subtraction(string& expr) {
//    string str1, str2;
//    size_t pos = expr.find(" - ");
//    if (pos != string::npos) {
//        str1 = expr.substr(0, pos);  // Lấy chuỗi trước dấu '-'
//        str2 = expr.substr(pos + 3);  // Lấy chuỗi sau dấu '-'
//    }
//
//    string_subtract(str1, str2);  // Loại bỏ chuỗi con
//    return 0;
//}
//
//// Hàm xử lý phép chia (đếm số lần xuất hiện)
//int handle_division(const string& expr) {
//    string str1, word;
//    int count;
//    size_t pos = expr.find(" / ");
//    if (pos != string::npos) {
//        str1 = expr.substr(0, pos);  // Lấy chuỗi trước dấu '/'
//        word = expr.substr(pos + 3);  // Lấy từ cần đếm xuất hiện
//    }
//
//    count = string_divide(str1, word);  // Đếm số lần xuất hiện của từ trong chuỗi
//    cout << "Kết quả: Từ \"" << word << "\" xuất hiện " << count << " lần trong chuỗi nhập.\n";
//    return count;
//}
//
//// Hàm xử lý biểu thức phức tạp có dấu ngoặc đơn
//int process_complex_expression(string& expr) {
//    string inner_expr;
//    int result;
//
//    // Tìm vị trí bắt đầu và kết thúc của dấu ngoặc đơn
//    size_t start = expr.find('(');
//    size_t end = expr.find(')');
//
//    if (start != string::npos && end != string::npos && start < end) {
//        // Trích xuất biểu thức bên trong dấu ngoặc đơn
//        inner_expr = expr.substr(start + 1, end - start - 1);
//
//        // Xử lý biểu thức bên trong dấu ngoặc đơn
//        result = handle_multiplication(inner_expr);  // Xử lý phép nhân trong ngoặc đơn
//
//        // Xử lý phép trừ
//        if (expr.find('-') != string::npos) {
//            result = handle_subtraction(expr); // Thực hiện phép trừ
//        }
//
//        // Xử lý phép chia
//        if (expr.find('/') != string::npos) {
//            result = handle_division(expr);  // Thực hiện phép chia
//        }
//
//        return result;
//    }
//
//    cout << "Biểu thức không hợp lệ.\n";
//    return 0;
//}
//
//int main() {
//    string input;
//
//    while (true) {
//        cout << "Nhập chuỗi: ";
//        getline(cin, input);
//
//        // Xử lý phép toán chuỗi (+, -, *, /)
//
//        if (input.find('(') != string::npos && input.find(')') != string::npos) {
//            int result = process_complex_expression(input);
//            cout << "Kết quả: " << result << endl;
//        }
//
//        if (input.find('+') != string::npos) {
//            size_t pos = input.find('+');
//            string str1 = input.substr(0, pos);
//            string str2 = input.substr(pos + 1);
//            string_add(str1, str2);
//        }
//        else if (input.find('-') != string::npos) {
//            size_t pos = input.find('-');
//            string str1 = input.substr(0, pos);
//            string str2 = input.substr(pos + 1);
//            string_subtract(str1, str2);
//        }
//        else if (input.find('*') != string::npos) {
//            size_t pos = input.find('*');
//            string str = input.substr(0, pos);
//            int times = stoi(input.substr(pos + 1));
//            string_multiply(str, times);
//        }
//        else if (input.find('/') != string::npos) {
//            size_t pos = input.find('/');
//            string str = input.substr(0, pos);
//            string word = input.substr(pos + 1);
//            int count = string_divide(str, word);
//            cout << "Kết quả: Từ \"" << word << "\" xuất hiện " << count << " lần trong chuỗi nhập.\n";
//        }
//        /*else if (input.find('(') != string::npos && input.find(')') != string::npos) {
//            int result = process_complex_expression(input);
//            cout << "Kết quả: " << result << endl;
//        }*/
//        else {
//            cout << "Không có phép toán hợp lệ.\n";
//        }
//    }
//
//    return 0;
//}
