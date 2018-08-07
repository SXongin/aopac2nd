/*UVa 1594
 */

#include <array>
#include <iostream>
#include <set>
#include <vector>

const int kMax = 2010;
std::set<std::vector<int> > appear;

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\ducci_sequence_input.txt", "r", stdin);
    freopen("chapter05\\ducci_sequence_output.txt", "w", stdout);
#endif
    int kase;
    std::cin >> kase;
    while (kase > 0) {
        --kase;
        appear.clear();
        std::vector<int> now;
        int n;
        std::cin >> n;
        while (n > 0) {
            --n;
            int tmp;
            std::cin >> tmp;
            now.push_back(tmp);
        }
        bool b_zero = false;
        bool b_loop = false;
        std::vector<int> next;
        for (int i = 0; i < kMax; ++i) {
            b_zero = true;
            for (auto v : now) {
                if (v != 0) {
                    b_zero = false;
                    break;
                }
            }
            if (b_zero) { break; }
            b_loop = false;
            if(appear.count(now) != 0){
                b_loop = true; break;
            }
            appear.insert(now);
            next.clear();
            int length = now.size();
            for(int index = 0; index < length; ++index){
                next.push_back(std::abs(now[index] - now[(index + 1)%length]));
            }
            now = std::move(next);
        }
        if(b_zero){
            std::cout << "ZERO" << std::endl;
        }
        if(b_loop){
            std::cout << "LOOP" << std::endl;
        }
    }
    return 0;
}
