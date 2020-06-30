/* UVa 11988
 */

#include <array>
#include <iostream>
#include <string>

const int kMax = 100000 + 10;
std::array<int, kMax> next;
std::string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("chapter06\\broken_keyboard_in.txt", "r", stdin);
    freopen("chapter06\\broken_keyboard_out.txt", "w", stdout);
#endif
    s.reserve(kMax);
    while (std::cin >> s) {
        int now  = 0;
        int last = 0;
        next[0]  = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                now = 0;
            } else if (s[i] == ']') {
                now = last;
            } else {
                next[i + 1] = next[now];
                next[now]   = i + 1;
                if (now == last) { last = i + 1; }
                now = i + 1;
            }
        }
        for (int i = next[0]; i != 0; i = next[i]) { std::cout << s[i - 1]; }
        std::cout << std::endl;
    }
}
