/*UVa 1595
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<int, std::vector<int>> points;

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\symmetry_input.txt", "r", stdin);
    freopen("chapter05\\symmetry_output.txt", "w", stdout);
#endif
    int kase;
    std::cin >> kase;
    while (kase > 0) {
        --kase;
        for (auto& line : points) { line.second.clear(); }
        points.clear();
        int n;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            int x, y;
            std::cin >> x >> y;
            points[y].push_back(x);
        }
        for (auto& line : points) { std::sort(line.second.begin(), line.second.end()); }
        bool b_first_in = true;
        bool ok         = true;
        int test;
        for (auto& line : points) {
            int length = line.second.size();
            for (int i = 0; i <= length / 2; ++i) {
                if (b_first_in && i == 0) {
                    test       = (line.second)[i] + (line.second)[length - 1 - i];
                    b_first_in = false;
                } else if (test != (line.second)[i] + (line.second)[length - 1 - i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) { break; }
        }
        if (ok) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
