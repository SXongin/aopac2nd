/*UVa 1590
*/

#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>

uint32_t read_ip(){
    uint32_t ret = 0;
    uint32_t in;
    std::string ip_str;
    std::cin >> ip_str;
    for(auto& ch:ip_str){
        if(ch == '.') ch = ' ';
    }
    std::istringstream is(ip_str);
    for(int i = 0; i < 4; ++i){
        is >> in;
        ret = ret << 8 | (in & 0xFF);
    }
    return ret;
}


void print_ip(const uint32_t& ip){
    std::cout << static_cast<uint32_t>((ip >> 24) & 0xFF) << ".";
    std::cout << static_cast<uint32_t>((ip >> 16) & 0xFF) << ".";
    std::cout << static_cast<uint32_t>((ip >> 8) & 0xFF) << ".";
    std::cout << static_cast<uint32_t>(ip & 0xFF) << std::endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("ip_networks_input.txt", "r", stdin);
    freopen("ip_networks_output.txt", "w", stdout);
#endif
    int n;
    while(std::cin>>n){
        uint32_t ip_network = read_ip();
        n--;
        uint32_t ip_mask = 0xFFFFFFFF;
        while(n--){
            uint32_t ip = read_ip();
            while(((ip & ip_mask) ^ ip_network) != 0){
                ip_mask = ip_mask << 1;
                ip_network = ip_network & ip_mask;
            }
        }
        print_ip(ip_network);
        print_ip(ip_mask);
    }
    return 0;
}
