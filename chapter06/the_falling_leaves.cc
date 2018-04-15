/*Uva 699
* 给定一颗二叉树，每个节点都有一个水平位置：左子结点在它左边一个单位，右子结点在它右边一个单位。
* 从左向右输出每个水平位置的所有结点的权值之和。二叉树按照递归先序方式输入，-1表示空树
* 样例输入：
* 5 7 -1 6 -1 -1 3 -1 -1
* 8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1
* -1
* 样例输出：
* Case 1:
* 7 11 3
* 
* Case 2:
* 9 7 21 15
*/

#include <iostream>
#include <cstring>
const int kMaxn = 10000;
int sum[kMaxn];


void build(int p){
    int v;
    std::cin>>v;
    if(v == -1) return;
    sum[p] += v;
    build(p-1);
    build(p+1);
}
bool init(){
    int v;
    std::cin>>v;
    if(v == -1) return false;
    memset(sum,0,sizeof(int)*kMaxn);
    int p = kMaxn/2;
    sum[p] += v;
    build(p-1);
    build(p+1);
    return true;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("the_falling_leaves_input.txt", "r", stdin);
    freopen("the_falling_leaves_output.txt", "w", stdout);
#endif
    int kase = 1;
    while(init()){
        static bool first = true;
        int p = 0;
        while(sum[p] == 0) ++p;
        std::cout<<"Case "<<kase<<":"<<std::endl<<sum[p];
        ++p; ++kase;
        while(sum[p]!=0){
            std::cout<<" "<<sum[p];
            ++p;
        }
        std::cout<< std::endl << std::endl;
    }
    return 0;
}

