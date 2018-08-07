/*UVa 1593
 */

#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const int kMax = 1900;
std::vector<std::vector<std::string>> doc;
std::array<int, kMax> widths;

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\alignment_of_code_input.txt", "r", stdin);
    freopen("chapter05\\alignment_of_code_output.txt", "w", stdout);
#endif
    std::string line;
    int row = 0;
    std::fill(widths.begin(), widths.end(), -1);
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        doc.emplace_back();
        int cln = 0;
        std::string tmp;
        while (ss >> tmp) {
            int leng = tmp.size();
            if (leng > widths[cln]) { widths[cln] = leng; }
            doc[row].push_back(tmp);
            ++cln;
        }
        ++row;
    }
    row = 0;
    for (auto& words : doc) {
        int cln = 0;
        for (auto& word : words) {
            if (cln == words.size() - 1) {
                std::cout << word;
            } else {
                std::cout << std::setw(widths[cln] + 1) << std::left << word;
            }
            ++cln;
        }
        std::cout << std::endl;
        ++row;
    }
    return 0;
}
