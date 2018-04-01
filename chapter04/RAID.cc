/*UVa 509
*/

#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <cstdint>
#include <ios>

const int kMaxd = 6;
const int kMaxs = 64;
const int kMaxb = 100;

std::array<std::string, kMaxd> disks;
int d, s, b;
bool is_even;
int num = 0;

bool check(void){
    for(int i = 0; i < s*b; ++i){
        bool have_flaw = false;
        int flaw_index = -1;
        for(int j = 0; j < d; ++j){
            if(disks[j][i] == 'x'){
                if(have_flaw){
                    return false;
                }else{
                    have_flaw = true;
                    flaw_index = j;
                }
            }
        }
        if(have_flaw){
            bool bit = 0;
            for(int j = 0; j < d; ++j){
                if(j != flaw_index){
                    bit ^= (disks[j][i] - '0');
                }
            }
            if(is_even){
                disks[flaw_index][i] = '0' + bit;
            }else{
                disks[flaw_index][i] = '0' + (!bit);
            }
        }else{
            bool bit = 0;
            for(int j = 0; j < d; ++j){
                bit ^= (disks[j][i] - '0');
            }
            if(is_even && bit != 0){
                return false;
            }else if(!is_even && bit != 1){
                return false;
            }
        }
    }
    return true;
}

void print_disks(){
    std::cout << "Disk set " << std::dec << num << " is valid, contents are: ";
    const int max = 4;
    int info_len = 0;
    uint8_t info;
    std::string str_max;
    str_max.resize(max);
    std::fill(str_max.begin(), str_max.end(), '0');
    for(int i = 0; i < b; ++i){
        for(int j = 0; j < d; ++j){
            if(j != i%d){
                for(int k = 0; k < s; ++k){
                    str_max[(info_len++) % max] = disks[j][i * s + k];
                    if(info_len % max == 0){
                        info = std::stoll(str_max, 0, 2);
                        std::cout << std::uppercase << std::hex << (info & 0xF);
                        std::fill(str_max.begin(), str_max.end(), '0');
                    }
                }
            }
        }
    }
    if(info_len % max != 0){
        info = std::stoll(str_max, 0, 2);
        std::cout << std::uppercase << std::hex << (info & 0xF);
    }
    std::cout << std::endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("RAID_input.txt", "r", stdin);
    freopen("RAID_output.txt", "w", stdout);
#endif
    std::for_each(disks.begin(), disks.end(), [](std::string& str){str.reserve(kMaxs*kMaxb);});
    while(std::cin >> d && d != 0){
        ++num;
        std::cin >> s >> b;
        char ch;
        std::cin >> ch;
        if(ch == 'E'){
            is_even = true;
        }else if(ch == 'O'){
            is_even = false;
        }
        for(int i = 0; i < d; ++i){
            std::cin >> disks[i];
        }
        if(!check()){
            std::cout << "Disk set " <<  std::dec << num  << " is invalid." << std::endl;
        }else{
            print_disks();
        }
    }
    return 0;
}
 