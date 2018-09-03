/*UVa 1596
 */

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

struct My_array{
    int length;
    std::unordered_set<int> indexes;
    std::unordered_map<int, int> values;
    My_array(int len):length(len){};
    My_array() = default;
    My_array(const My_array&) = default;
    My_array(My_array&&) = default;
    bool get_value(int index, int& value) const{
        if(!(index >= 0 && index < length)){
            return false;
        }
        auto search = indexes.find(index);
        if(search == indexes.end()){
            return false;
        }
        value = values.at(*search);
        return true;
    }
    bool add_value(int index, int value){
        if(!(index >= 0 && index < length)){
            return false;
        }
        indexes.insert(index);
        values[index] = value;
        return true;
    }
};

std::unordered_map<char, My_array> as;
std::string codes;
int index;
bool parse_define(const std::string& codes)
{
    as.emplace(std::make_pair(codes[0], My_array(std::stoi(codes.substr(2)))));
    return true;
}

bool parse_value(const std::string& codes, int& val)
{
    if (std::isdigit(codes[index])) {
        std::size_t pos;
        val = std::stoi(codes.substr(index), &pos);
        index += pos;
        index += 1;
        return true;
    }
    char arr = codes[index];
    index += 2;
    int cur_idx;
    if (!parse_value(codes, cur_idx)) { return false; }
    if(!as[arr].get_value(cur_idx, val)){
        return false;
    }
    index += 1;
    return true;
}

bool parse_assignment(const std::string& codes)
{
    char arr = codes[0];
    index    = 2;
    int cur_idx;
    if (!parse_value(codes, cur_idx)) { return false; }
    index += 1;
    int cur_val;
    if (!parse_value(codes, cur_val)) { return false; }
    return as[arr].add_value(cur_idx, cur_val);
}
bool parse_line(const std::string& codes)
{
    std::string::size_type pos = codes.find('=');
    if (pos == std::string::npos) {
        return parse_define(codes);
    } else {
        index = 0;
        return parse_assignment(codes);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\bug_hunt_input.txt", "r", stdin);
    freopen("chapter05\\bug_hunt_output.txt", "w", stdout);
#endif
    while (std::getline(std::cin, codes) && codes != std::string(".")) {
        int line = 1;
        bool ok = true;
        as.clear();
        while (true) {
            if (codes == std::string(".")) break;
            if (!parse_line(codes)) {
                ok       = false;
                break;
            }
            ++line;
            std::getline(std::cin, codes);
        }
        while (true) {
            if (codes == std::string(".")) break;
            std::getline(std::cin, codes);
        }
        if (!ok) {
            std::cout << line << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
}
