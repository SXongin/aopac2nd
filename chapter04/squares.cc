/*UVa 201
*/

#include <iostream>
#include <array>
#include <algorithm>

int main(void){
#ifndef ONLINE_JUDGE
    freopen("squares_input.txt", "r", stdin);
    freopen("squares_output.txt", "w", stdout);
#endif
    const int kMax = 10;
    std::array<std::array<bool, kMax>, kMax> H;
    std::array<std::array<bool, kMax>, kMax> V;
    std::array<int,kMax> squares;
    int d,l;
    int T = 0;
    while(std::cin>>d){
        ++T;
        std::cin>>l;
        std::for_each(H.begin(), H.end(), [](std::array<bool, kMax>& a){std::fill(a.begin(),a.end(),false);});
        std::for_each(V.begin(), V.end(), [](std::array<bool, kMax>& a){std::fill(a.begin(),a.end(),false);});
        std::fill(squares.begin(), squares.end(), 0);
        char ch;
        int r,c;
        while(l--){
            std::cin>>ch>>r>>c;
            if(ch == 'H'){
                H[r][c] = true;
            }else{
                V[r][c] = true;
            }
        }
        for(int size = 1; size < d; ++size){
            for(int i = 1; i <= d - size; ++i)
                for(int j = 1; j <= d - size; ++j){
                    bool is_square = true;
                    for(int mj = j; mj < j + size; ++mj){
                        if(!H[i][mj] || !H[i+size][mj]){
                            is_square = false;
                            break;
                        }
                    }
                    if(is_square){
                        for(int mi = i; mi < i + size; ++mi){
                            if(!V[j][mi] || !V[j+size][mi]){
                                is_square = false;
                                break;
                            }
                        }
                    }
                    if(is_square){
                        ++squares[size];
                    }
                }
        }
        static bool first = true;
        if(first){
            first = false;
        }else{
            std::cout << std::endl << "**********************************" << std::endl << std::endl;
        }
        std::cout << "Problem #" << T << std::endl << std::endl;
        bool have_square = false;
        for(int size = 1; size < d; ++size){
            if(squares[size] > 0){
                std::cout<< squares[size] << " square (s) of size " << size << std::endl;
                have_square = true;
            }
        }
        if(!have_square){
            std::cout << "No completed squares can be found." << std::endl;
        }
    }
    return 0;
}
