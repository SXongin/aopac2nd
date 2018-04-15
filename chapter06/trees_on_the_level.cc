/*UVa 122
* 输入一颗二叉树，你的任务是按照从上到下，从左到右的顺序输出各个结点的值。每个结点都按照从根结点到它的移动序列给出（L表示左， R表示右）
* 在输入中，每个结点的左括号和右括号之间没有空格，相邻结点之间用一个空格隔开。每个树的输入用一对空括号表示表示结束（这一对括号本身不代表一个结点）
* 注意如果从根到某个叶结点的路径上有的结点没有在输入中给出，或者给出超过一次，应当输出complete.结点个数不超过256.
* 样例输入：
* (11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
* (3,L) (4,R) ()
* 样例输出
* 5 4 8 11 13 4 7 2 11
* not complete
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define MAXN 1000
char node[MAXN];
char path[MAXN];

struct Node{
    bool have_value;
    int value;
    Node* left;
    Node* right;
    Node():have_value(false),value(0),left(NULL),right(NULL){}
};
Node* root;
bool ok = true;

void add_node(int value, char* path){
    int n = strlen(path);
    Node* now = root;
    for(int i = 0; i < n - 1; ++i){//the last is ')'
        if(path[i] == 'L'){
            if(now->left == NULL) now->left = new Node();
            now = now->left;
        }else{
            if(now->right == NULL) now->right = new Node();
            now = now->right;
        }
    }
    if(now->have_value == true) {
        ok = false;
            return;
            }
    now->value = value;
    now->have_value = true;
}

bool read_node(){
    ok = true;
    root = new Node();
    for(;;){
        if(scanf("%s", node)!=1) return false;
        if(strcmp(node,"()")==0) break;
        int value;
        sscanf(&node[1], "%d", &value);
        add_node(value, strchr(node,',')+1);
    }
    return true;
}

void free_node(Node* root){
    if(root == NULL) return;
    if(root->left != NULL) free_node(root->left);
    if(root->right != NULL) free_node(root->right);
    delete root;
}

bool bfs(std::vector<int>& ans){
    ans.clear();
    std::queue<Node*> search_queue;
    search_queue.push(root);
    while(!search_queue.empty()){
        Node* temp = search_queue.front();
        search_queue.pop();
        if(temp->left!=NULL) search_queue.push(temp->left);
        if(temp->right!=NULL) search_queue.push(temp->right);
        if(temp->have_value == false) return false;
        ans.push_back(temp->value);
    }
    return true;
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("trees_on_the_level_input.txt", "r", stdin);
    freopen("trees_on_the_level_output.txt", "w", stdout);
#endif
    while(read_node()){
        std::vector<int> ans;
        if(ok && bfs(ans)){
            for(auto itr = ans.cbegin(); itr != ans.cend(); ++itr){
                if(itr != ans.cbegin()) printf(" ");
                printf("%d", *itr);
            }
        }else{
            printf("not complete");
        }
        free_node(root);
        printf("\n");
    }
    return 0;
}
