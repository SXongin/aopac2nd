#include <iostream>

size_t N[] = {1048576}; 

int main(){
    freopen("data_mining_test.txt", "w", stdout);
    for(auto n:N){
        for(int a = 896; a <= 960; ++a){
            for(int b = 1; b<= 1024; ++b){
                std::cout<<n<<" "<<a<<" "<<b<<" "<<std::endl;
            }
        }
    }
    return 0;
}