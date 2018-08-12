/*UVa 12100
 */

#include <array>
#include <iostream>

std::array<int, 9> counts;
std::array<int, 110> jobs;
std::array<int, 110> priorities;

inline void get_next(int& max_pri)
{
    while (max_pri > 0 && counts[max_pri - 1] == 0) { --max_pri; }
}

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\printer_queue_input.txt", "r", stdin);
    freopen("chapter05\\printer_queue_output.txt", "w", stdout);
#endif
    int kase;
    std::cin >> kase;
    while (kase > 0) {
        --kase;
        for (auto& i : counts) { i = 0; }
        int n, aim;
        std::cin >> n >> aim;
        for (int i = 0; i < n; ++i) {
            jobs[i] = i;
            int pri;
            std::cin >> pri;
            ++counts[pri - 1];
            priorities[i] = pri;
        }
        int index      = 0;
        int max_pri    = 9;
        int print_time = 0;
        while (true) {
            if (counts[max_pri - 1] == 0) { get_next(max_pri); }
            while (jobs[index] == -1) {
                ++index;
                index %= n;
            }
            if (priorities[jobs[index]] == max_pri) {
                ++print_time;
                if (jobs[index] == aim) {
                    std::cout << print_time << std::endl;
                    break;
                }
                jobs[index] = -1;
                --counts[max_pri - 1];
            }
            ++index;
            index %= n;
        }
    }
    return 0;
}
