/*UVa 10763
 */

#include <array>
#include <iostream>
#include <set>

using Student = std::array<int, 2>;
std::multiset<Student> students;

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\foreign_exchange_input.txt", "r", stdin);
    freopen("chapter05\\foreign_exchange_output.txt", "w", stdout);
#endif
    int n;
    while ((std::cin >> n) && (n > 0)) {
        Student now;
        students.clear();
        for(int i = 0; i < n; ++i){
            std::cin >> now[0] >> now[1];
            Student target{{now[1], now[0]}};
            auto ret = students.find(target);
            if(ret != students.end()){
                students.erase(ret);
            }else{
                students.insert(now);
            }
        }
        if(students.empty()){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
