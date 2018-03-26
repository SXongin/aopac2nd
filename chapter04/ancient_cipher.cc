/*UVa 1339
* 给定两个长度相同且不超过100的字符串，判断能否把其中一个字符串的各个字母重排，
* 然后对26个字母做一个一一映射，使得两个字符串相同。
*/

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

int main(void){
#ifndef ONLINE_JUDGE
    freopen("ancient_cipher_input.txt", "r", stdin);
    freopen("ancient_cipher_output.txt", "w", stdout);
#endif
    const size_t kLen = 26;
    std::string str;
    std::array<int, kLen> cnt1{};
    std::array<int, kLen> cnt2{};
    while(std::cin>>str){
        std::fill(cnt1.begin(), cnt1.end(), 0);
        std::fill(cnt2.begin(), cnt2.end(), 0);
        std::for_each(str.cbegin(), str.cend(), [&cnt1](const char &c){++cnt1[c-'A'];});
        std::cin>>str;
        std::for_each(str.cbegin(), str.cend(), [&cnt2](const char &c){++cnt2[c-'A'];});
        std::sort(cnt1.begin(),cnt1.end());
        std::sort(cnt2.begin(),cnt2.end());
        if(std::equal(cnt1.cbegin(), cnt1.cend(), cnt2.cbegin())){
            std::cout<<"YES"<<std::endl;
        }else{
            std::cout<<"NO"<<std::endl;
        }
    }
    return 0;
}
