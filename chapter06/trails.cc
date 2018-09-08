/* UVa 514
 */

#include <array>
#include <iostream>
#include <stack>
const int kMax = 1000 + 10;

std::array<int, kMax> targets;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("chapter06\\trails_in.txt", "r", stdin);
    freopen("chapter06\\trails_out.txt", "w", stdout);
#endif
    int n;
    while (std::cin >> n && n != 0) {
        while (true) {
            std::cin >> targets[0];
            if (targets[0] == 0) { break; }
            for (int i = 1; i < n; ++i) { std::cin >> targets[i]; }
            int out = 0;
            int in  = 1;
            std::stack<int> station;
            bool ok = true;
            while (out < n) {
                if (targets[out] == in) {
                    ++out;
                    ++in;
                } else if (!station.empty() && targets[out] == station.top()) {
                    ++out;
                    station.pop();
                } else if (in <= n) {
                    station.push(in);
                    ++in;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
        }
        std::cout << std::endl;
    }
}
