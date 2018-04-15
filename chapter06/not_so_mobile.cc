/*UVa 839
* 输入一个树状天平，根据力矩平衡判断两边是否平衡。即W_l*D_l=W_r*D_r,其中W_l和W_r分别为天平两边的重量，D为距离。
* 采用递归（先序）方式输入：每个天平的格式为W_l,D_l,W_r,D_r,当W为0时，表明该砝码实际上是一个子天平，
* 接下来会描述这个子天平。当两个W都为0时，会先描述左子天平，然后是右子天平。
* 样例输入：
* 1
* 0 2 0 4
* 0 3 0 1
* 1 1 1 1
* 2 4 4 2
* 1 6 3 2
* 样例输出：
* YES
*/

#include <iostream>

bool is_balance(int& W){
    int Wl, Dl, Wr, Dr;
    std::cin>>Wl>>Dl>>Wr>>Dr;
    bool bl = true, br = true;
    if(Wl==0) bl = is_balance(Wl);
    if(Wr==0) br = is_balance(Wr);
    W = Wl + Wr;
    return bl&&br&&(Wl*Dl == Wr*Dr);
}

int main(void){
#ifndef ONLINE_JUDGE
    freopen("not_so_mobile_input.txt", "r", stdin);
    freopen("not_so_mobile_output.txt", "w", stdout);
#endif
    int n;
    int W;
    std::cin >> n;
    while(n>0){
        --n;
        if(is_balance(W)) std::cout<<"YES"<<std::endl;
        else std::cout<<"NO"<<std::endl;
        if(n != 0){
            std::cout<<std::endl;
        }
    }
}
