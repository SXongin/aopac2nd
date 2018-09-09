/*UVa 442
 */
const int kMax = 26;
#include <array>
#include <iostream>
#include <stack>
#include <string>

struct Matrix {
    int m;
    int n;
};

std::array<Matrix, kMax> arr_m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("chapter06\\matrix_chain_multiplication_in.txt", "r", stdin);
    freopen("chapter06\\matrix_chain_multiplication_out.txt", "w", stdout);
#endif
    int n;
    std::cin >> n;
    while (n > 0) {
        --n;
        char c;
        std::cin >> c >> arr_m[c - 'A'].m >> arr_m[c - 'A'].n;
    }
    // char tmp = 'A';
    // for(auto& m: arr_m){
    //     std::cout << tmp << ": " << m.m << ", " << m.n << std::endl;
    //     ++tmp;
    // }
    std::string expr;
    while (std::cin >> expr) {
        bool ok = true;
        std::stack<Matrix> s;
        int ans = 0;
        for (const auto c : expr) {
            if (c >= 'A' && c <= 'Z') {
                s.push(arr_m[c - 'A']);
            } else if (c == ')') {
                Matrix m2 = s.top();
                s.pop();
                Matrix m1 = s.top();
                s.pop();
                if (m1.n != m2.m) {
                    ok = false;
                    break;
                } else {
                    ans += m1.m * m1.n * m2.n;
                    Matrix m_new;
                    m_new.m = m1.m;
                    m_new.n = m2.n;
                    s.push(m_new);
                }
            }
        }
        if (ok) {
            std::cout << ans;
        } else {
            std::cout << "error";
        }
        std::cout << std::endl;
    }
}
