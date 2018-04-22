/*UVa 1592
 */

#include <array>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

const int kMaxR = 10000 + 10;
const int kMaxC = 10 + 5;

std::array<std::array<int, kMaxC>, kMaxR> datas;
std::map<std::string, int> ID_cache;
// std::vector<std::string> str_cache;
int id;

std::map<std::pair<std::pair<int, int>, std::pair<int, int>>, int> occur;

int ID(std::string str)
{
    if (ID_cache.count(str))
        return ID_cache[str];
    else {
        ID_cache[str] = id;
        ++id;
        return ID_cache[str];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("database_input.txt", "r", stdin);
    freopen("database_out_put.txt", "w", stdout);
#endif
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ism(line);
    int n, m;
    while (ism >> n >> m) {
        ID_cache.clear();
        occur.clear();
        id = 0;
        for (int r = 0; r < n; ++r) {
            std::getline(std::cin, line);
            ism = std::istringstream(line);
            for (int c = 0; c < m; ++c) {
                std::getline(ism, line, ',');
                datas[r][c] = ID(line);
            }
        }
        bool ok = true;
        for (int r = 0; ok && r < n; ++r) {
            for (int c1 = 0; ok && c1 < m; ++c1)
                for (int c2 = c1+1; c2 < m; ++c2) {
                    auto data_pair =
                        std::make_pair(std::make_pair(c1, datas[r][c1]), std::make_pair(c2, datas[r][c2]));
                    if(occur.count(data_pair)){
                        std::cout << "NO" << std::endl;
                        std::cout << occur[data_pair] + 1 << ' ' << r + 1 << std::endl;
                        std::cout << c1 + 1 << ' ' << c2 + 1 << std::endl;
                        ok = false;
                        break;
                    }else{
                        occur[data_pair] = r;
                    }
                }
        }
        if(ok){
            std::cout << "YES" << std::endl;
        }
        std::getline(std::cin, line);
        ism = std::istringstream(line);
    }
    return 0;
}
