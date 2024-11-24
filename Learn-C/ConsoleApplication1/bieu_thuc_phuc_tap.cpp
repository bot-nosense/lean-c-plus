#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

/*
    input: x * 3
    output: xxx -> cộng chuỗi thông thường

    input: ( ( (x*31) - x ) / x )
    output: 30 -> các giá trị x được triệt tiêu
*/



// Hàm tính giá trị biểu thức toán học
int evaluateExpression(const string& expr, int x) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') continue;

        if (expr[i] == '(') {
            ops.push('(');
        }
        else if (expr[i] == ')') {
            while (ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                int result = 0;
                if (op == '*') result = val1 * val2;
                else if (op == '-') result = val1 - val2;
                else if (op == '/') result = val1 / val2;

                values.push(result);
            }
            ops.pop(); // Loại bỏ dấu '('
        }
        else if (expr[i] == '*' || expr[i] == '-' || expr[i] == '/') {
            ops.push(expr[i]);
        }
        else if (isdigit(expr[i]) || expr[i] == 'x') {
            int val = 0;
            if (expr[i] == 'x') {
                val = x;
            }
            else {
                while (i < expr.length() && isdigit(expr[i])) {
                    val = val * 10 + (expr[i] - '0');
                    i++;
                }
                i--;
            }
            values.push(val);
        }
    }

    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();

        int result = 0;
        if (op == '*') result = val1 * val2;
        else if (op == '-') result = val1 - val2;
        else if (op == '/') result = val1 / val2;

        values.push(result);
    }

    return values.top();
}

int main() {
    string input;
    cout << "Nhap bieu thuc: ";
    getline(cin, input);
    
    // Xử lý trường hợp biểu thức toán học
    int x = 1; // Giả sử x = 1
    int result = evaluateExpression(input, x);
    cout << "Ket qua: " << result << endl;

    return 0;
}
