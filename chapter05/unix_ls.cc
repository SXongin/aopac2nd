/* Uva 400
 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("unix_ls_input.txt", "r", stdin);
    freopen("unix_ls_output.txt", "w", stdout);
#endif
    const int kWidth = 60;
    std::vector<std::string> file_names;
    int n;
    std::cout << std::left;
    while (std::cin >> n) {
        file_names.clear();
        int max_w = 0;
        for (int i = 0; i < n; ++i) {
            std::string file;
            std::cin >> file;
            file_names.push_back(file);
            if (file.size() > max_w) max_w = file.size();
        }
        int columns = (kWidth - max_w) / (max_w + 2) + 1;
        int rows    = (n - 1) / columns + 1;
        std::sort(file_names.begin(), file_names.end());
        for (int i = 0; i < kWidth; ++i) std::cout << "-";
        std::cout << "\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int index = rows * j + i;
                if (index < n) {
                    if (index >= n - rows) {
                        std::cout << std::setw(max_w) << file_names[index];
                    } else {
                        std::cout << std::setw(max_w + 2) << file_names[index];
                    }
                }
            }
            std::cout << "\n";
        }
    }
    return 0;
}
