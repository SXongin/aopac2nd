/*UVa 508
 */

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

std::map<char, std::string> morse;
std::unordered_map<std::string, std::string> dict;
std::unordered_set<std::string> ambiguous;
std::unordered_map<std::string, int> orders;

void read_morse(void) {
  char ch;
  std::string code;
  while (std::cin >> ch && ch != '*') {
    std::cin >> code;
    morse[ch] = code;
  }
}

void read_dict(void) {
  std::string code;
  std::string word;
  int order = 0;
  while (std::cin >> word && word != "*") {
    code = "";
    for (auto ch : word) {
      code += morse[ch];
    }
    if (dict.find(code) == dict.end()) {
      dict[code] = word;
      orders[word] = order;
      ++order;
    } else {
      ambiguous.insert(code);
    }
  }
}

void decode() {
  std::string code;
  while (std::cin >> code && code != "*") {
    auto search = dict.find(code);
    if (search != dict.end()) {
      std::cout << search->second;
      auto ambi = ambiguous.find(code);
      if (ambi != ambiguous.end()) {
        std::cout << "!";
      }
    } else {
      int max_size = 80;
      std::string back_str;
      bool have_bigger = false;
      for (auto item : dict) {
        if (item.first.size() > code.size()) {
          if (item.first.substr(0, code.size()) == code) {
            if ((item.first.size() - code.size()) < max_size ||
                ((item.first.size() - code.size()) == max_size &&
                 orders[item.second] < orders[back_str])) {
              back_str = item.second;
              have_bigger = true;
              max_size = item.first.size() - code.size();
            }
          }
        }
      }

      std::string may_matches;
      int i;
      for (i = 1; i < code.size() && i <= max_size; ++i) {
        auto search = dict.find(code.substr(0, code.size() - i));
        if (search != dict.end()) {
          may_matches = search->second;
          break;
        }
      }

      if (have_bigger &&
          (i >= code.size() || i > max_size ||
           (i == max_size && orders[back_str] < orders[may_matches]))) {
        std::cout << back_str;
      } else {
        std::cout << may_matches;
      }

      std::cout << "?";
    }
    std::cout << std::endl;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("morse_mismatches_input.txt", "r", stdin);
  freopen("morse_mismatches_output.txt", "w", stdout);
#endif
  read_morse();
  read_dict();
  decode();
  return 0;
}
