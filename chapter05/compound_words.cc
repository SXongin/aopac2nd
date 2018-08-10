/*UVa 10391
 */

#include <array>
#include <iostream>
#include <set>
#include <string>

const int KAlphabetSize = 26;
std::array<std::set<std::string>, KAlphabetSize> dict;

inline bool cover(std::string word, std::string in_word)
{
    return (word.size() > in_word.size()) && (word.substr(0, in_word.size()) == in_word);
}

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\compound_words_input.txt", "r", stdin);
    freopen("chapter05\\compound_words_output.txt", "w", stdout);
#endif
    std::string tmp;
    while (std::cin >> tmp) { dict[*tmp.begin() - 'a'].insert(tmp); }
    for (auto& words : dict) {
        for (auto& word : words) {
            for (auto& in_word : words) {
                if (cover(word, in_word)) {
                    std::string reserve = word.substr(in_word.size());
                    std::size_t index = *reserve.begin() - 'a';
                    if (dict[index].find(reserve) != dict[index].end()) {
                        std::cout << word << std::endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
