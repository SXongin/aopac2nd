/*UVa 548
* 给一颗点带权（权值各不相同，都是小于10000的正整数）的二叉树的中序遍历和后序遍历，找一个叶子使得它到根上的路径的圈和最小。
* 如果有多解，该叶子本身的权应该尽量小。
* 输入中没两行表示一棵树，其中第一行为中序遍历，第二行为后序遍历。
* 样例输入：
* 3 2 1 4 5 7 6
* 3 1 2 5 6 7 4
* 7 8 11 3 5 16 12 18
* 8 3 11 7 16 18 12 5
* 255
* 255
* 样例输出:
* 1
* 3
* 255
*/

#define LOCAL
#include <iostream>
#include <string>
#include <sstream>

#define MAXN 10000+10
int in_order[MAXN];
int post_order[MAXN];
int left[MAXN];
int right[MAXN];
int n;

int best, min_sum;

bool read_list(int* list){
    std::string line;
    if(!std::getline(std::cin, line)) return false;
    std::stringstream ss(line);
    n = 0;
    while(ss >> list[n]){
        ++n;
    }
    return n > 0;
}

int build(int in_L, int in_R, int post_L, int post_R){
    if(in_L > in_R) return 0;
    int root = post_order[post_R];
    int t = in_L;
    while(in_order[t] != root) ++t;
    left[root] = build(in_L, t - 1, post_L, post_L + t -1 - in_L);
    right[root] = build(t + 1, in_R, post_L + t -1 - in_L + 1, post_R - 1);
    return root;
}

void dfs(int root, int sum){
    sum += root;
    if((left[root] == 0) && (right[root] == 0)){
        if(sum < min_sum){
            best = root;
            min_sum = sum;
        }else if( (sum==min_sum) && (root < best) ){
            best = root;
        }
    }

    if(left[root] != 0) dfs(left[root], sum);
    if(right[root] != 0) dfs(right[root], sum);
}

int main(void){
#ifdef LOCAL
    freopen("tree_input.txt", "r", stdin);
#endif
    while(read_list(in_order)){
        read_list(post_order);
        build(0, n-1, 0, n-1);
        best = MAXN;
        min_sum = MAXN;
        int sum = 0;
        dfs(post_order[n-1], sum);
        std::cout<< best;
        std::cout<<std::endl;
    }
    return 0;
}