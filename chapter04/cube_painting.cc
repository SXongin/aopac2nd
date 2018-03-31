/*UVa 253
*/

#include <iostream>
#include <array>
#include <string>
#include <iomanip>

const int kMax = 6;

const std::array<std::array<int, kMax>, kMax> map_table{
    std::array<int, kMax>({1, 2, 4, 3, 5, -1}),
    {0, 3, 5, 2, 4, -1},
    {0, 1, 5, 4, 3, -1},
    {0, 4, 5, 1, 2, -1},
    {0, 2, 5, 3, 1, -1},
    {1, 3, 4, 2, 0, -1}
};
std::string s1, s2;

bool equal_adjoin(int i){
    for(int offset = 0; offset < 4; ++offset){
        bool ok = true;
        for(int mi = 0; mi < 4; ++mi){
            if(s1[1+mi] != s2[map_table[i][(mi + offset)%4]]){
                ok = false; break;
            }
        }
        if(ok) return true;
    }
    return false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("cube_painting_input.txt", "r", stdin);
    freopen("cube_painting_output.txt", "w", stdout);
#endif
    while(std::cin>>std::setw(6)>>s1){
        std::cin>>std::setw(6)>>s2;
        char tmp = s1[3];
        s1[3] = s1[4];
        s1[4] = tmp;
        bool equal = false;
        for(int i = 0; i < 6; ++i){
            if(s1[0] == s2[i] && s1[5] == s2[map_table[i][4]] && equal_adjoin(i)){
                equal = true; break;
            }
        }
        if(equal){
            std::cout<<"TRUE"<<std::endl;
        }else{
            std::cout<<"FALSE"<<std::endl;
        }
    }
    return 0;
}
