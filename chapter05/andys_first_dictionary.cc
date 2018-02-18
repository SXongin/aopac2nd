/*Uva10815
* 输入一个文本，找出所有不同的单词（连续的字母序列），按照字典序从小到大输出。不区分大小写。
*/

#include <iostream>
#include <string>
#include <set>
#include <sstream>

using std::set;
using std::string;
using std::cin;
using std::cout;
using std::isalpha;
using std::islower;
using std::stringstream;

int main(void){
    set<string> dict;
    string s;
    while(cin >> s){
        for(auto& c : s){
            if(isalpha(c)){
                c = tolower(c);
            }else{
                c = ' ';
            }
        }
    stringstream ss(s);
    string tmps;
    while(ss >> tmps){
        dict.insert(tmps);
    }
    }
    for(auto word: dict){
        cout<<word<<"\t";
    }
    cout<<std::endl;
    return 0;
}