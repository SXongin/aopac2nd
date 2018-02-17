/*UVa101
* 从左到右有n个木块，要求模拟以下4种操作（a和b是木块编号）
* move a onto b: 把a和b上方的木块放回原位，把a木块放到b上
* move a over b：把a上方的木块放回原位，把a木块放到b木块所在堆的顶上
* pile a onto b: 把b上方的木块放回原位，把a木块及其以上木块放到b木块上
* pile a over b: 把a木块及其以上木块放到b木块所在堆的顶上
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iterator> //distance

using std::vector;
using std::find;
using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::string;

vector<vector<int> > piles;

void print_piles(){
    for(int i = 0; i < piles.size(); ++i){
        cout<<"piles"<<i<<": ";   
        for(auto&& blocks: piles[i]){
            cout<<blocks<<" ";
       }
       cout<<endl;
    }
}

void find_block(vector<vector<int> >::iterator& itr_pile, 
                vector<int>::iterator& itr_block, int block_number){
    for(auto itr_pnow = piles.begin(); itr_pnow != piles.end(); ++itr_pnow){
        for(auto itr_bnow = itr_pnow->begin(); itr_bnow != itr_pnow->end(); ++itr_bnow){
            if(*itr_bnow == block_number){
                itr_pile = itr_pnow;
                itr_block = itr_bnow;
                return;
            }
        }
    }
}

void clear_above(vector<vector<int> >::iterator& itr_pile, vector<int>::iterator& itr_block){
    for(auto itr = itr_block + 1; itr != itr_pile->end(); ++itr){
        piles[*itr].push_back(move(*itr));
    }
    itr_pile->resize(itr_block - itr_pile->begin() + 1);
}

void pile_over(vector<vector<int> >::iterator& itr_pa, vector<vector<int> >::iterator& itr_pb, 
               vector<int>::iterator itr_a){
    for(auto itr_block = itr_a; itr_block!= itr_pa->end(); ++itr_block){
        itr_pb->push_back(move(*itr_block));
    }
    itr_pa->resize(itr_a - itr_pa->begin());
}
int main(void){
    const int kMaxn = 20;
    piles.reserve(kMaxn);
    int n;
    cin>>n;
    piles.reserve(n);
    for(int i = 0; i < n; ++i){
        vector<int> vecint(1, i);
        vecint.reserve(kMaxn);
        piles.push_back(move(vecint));
    }
    print_piles();
    int a, b;
    string s1, s2;
    while(cin>>s1>>a>>s2>>b){
        vector<vector<int> >::iterator itr_pa, itr_pb;
        vector<int>::iterator itr_a, itr_b;
        find_block(itr_pa, itr_a, a);
        find_block(itr_pb, itr_b, b);
        if(std::distance(itr_pa, itr_pb) == 0) break;
        if(s1 == "move") clear_above(itr_pa, itr_a);
        if(s2 == "onto") clear_above(itr_pb, itr_b);
        pile_over(itr_pa, itr_pb, itr_a);
    }
    print_piles();
    return 0;
}