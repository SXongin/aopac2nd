/* UVz 1591
*/
// #include <iostream>
// #include <map>
// #include <utility>
// #include <algorithm>
// #include <iomanip>
// #include <iterator>

// const int kMax = 32;
// std::multimap<double, std::pair<int, int> > table;

// void make_table(){
//     for(int A = 0; A < kMax; ++A){
//         for(int B = 0; B < kMax; ++B){
//             size_t one = 1;
//             double d = static_cast<double>((one << A) + 1)/static_cast<double>(one << B);
//             table.emplace(d, std::make_pair(A, B));
//         }
//     }
// }

// void print_table(){
//     auto itr = table.begin();
//     for(int i = 0; i < kMax; ++i){
//         for(int j = 0; j < kMax; ++j){
//             std::cout << std::setw(11) << itr->first << ": " << std::setw(2) << itr->second.first << ", " << std::setw(2) << itr->second.second << "| ";
//             ++itr;
//         }
//         std::cout << std::endl;
//     }
// }

// bool cmp(const std::pair<double, std::pair<int, int>>& iteml, const std::pair<double, std::pair<int, int>>& itemr){
//     return iteml.second < itemr.second;
// }

// int main(){
// #ifndef ONLINE_JUDGE
//     freopen("data_mining_input.txt", "r", stdin);
//     freopen("data_mining_output.txt", "w", stdout);
// #endif
//     make_table();
//     //print_table();
//     int N, P, Q;
//     while(std::cin >> N >> P >> Q){
//         int A, B;
//         size_t K;
//         auto start = table.lower_bound(Q / static_cast<double>(P));
//         std::multimap<double, std::pair<int, int> >::iterator end;
//         if(N == 1){
//             end = table.end();
//         }else{
//             end = table.lower_bound(Q/static_cast<double>(P) + 1/static_cast<double>(N -1)/P);
//         }
//         auto equal_end = table.upper_bound(Q / static_cast<double>(P));
//         if(std::distance(equal_end, end) < 0){
//             end = equal_end;
//         }
//         auto result = std::min_element(start, end, cmp);
//         A = result->second.first;
//         B = result->second.second;
//         K = (N - 1) * P;
//         K = K + (K << A);
//         K = (K >> B) + Q;
//         std::cout << K << " " << A << " " << B << std::endl;
//     }
//     return 0;
// }

#include<cstdio>  
typedef long long LL;  
int main(){  
#ifndef ONLINE_JUDGE
    freopen("data_mining_input.txt", "r", stdin);
    freopen("data_mining_output.txt", "w", stdout);
#endif
    LL n,sp,sq;  
    while(~scanf("%lld%lld%lld",&n,&sp,&sq)){  
        LL best=(LL)1<<62,a,b,aa=0,bb=0;  
        for(a=0;a<32;++a)  
            for(b=0;b<32;++b){  
                LL cur=(((n-1)*sp+((n-1)*sp<<a))>>b)+sq;  
                if(cur>=n*sq&&cur<best) best=cur,aa=a,bb=b;  
            }  
        printf("%lld %lld %lld\n",best,aa,bb);  
    }  
    return 0;  
}  