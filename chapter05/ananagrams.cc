/*UVa 156
* 输入一些单词，找出所有满足如下条件的单词：该单词不能通过字母重排，得到输入文本的另外一个单词。在判断是否满足条件时，
* 字母不分大小写，但在输出时应保留输入中的大小写，按字典序进行排列。
*/

#define LOCAL
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>

using std::cout;
using std::cin;
using std::string;

string stand(string word){
    for(auto& c: word){
        c = tolower(c);
    }
    std::sort(word.begin(), word.end());
    return word;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("ananagrams_input.txt", "r", stdin);
    freopen("ananagrams_output.txt", "w", stdout);
#endif
    std::vector<string> words;
    string word;
    std::map<string, int> cnt;
    while(cin>>word){
        if(word[0] == '#') break;   
        words.push_back(word);
        ++cnt[stand(word)];
    }
    std::set<string> ans;
    for(auto& word : words){
        if(cnt[stand(word)] == 1){
            ans.insert(word);
        }
    }

    for(auto& word : ans){
        cout<<word<<std::endl;
    }
    return 0;
}
