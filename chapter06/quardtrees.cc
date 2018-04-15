/*UVa 297
* 可以用四分数表示一个黑白图像，方法是用根结点表示整幅图像，然后把行列各分成两等分，按照坐标系象限进行编号，
* 从左到右对应4个子结点。如果某子结点对应的区域全黑或者全白，则直接用一个黑节点表示；如果既有黑又有白，
* 则用一个灰结点表示，并且为这个区域递归建树。
* 给出两颗四分树的先序遍历，求两者合并之后（黑色部分合并以后）黑色像素的个数。p表示中间结点，f表示黑色（full），
* e表示白色（empty）。
* 样例输入：
* 3
* ppeeefpffeefe
* pefepeefe
* peeef
* peefe
* peeef
* peepefefe
* 样例输出：
* There are 640 black pixels.
* There are 512 black pixels.
* There are 384 black pixels.
*/

#include <iostream>
#include <string>
#include <cstring>

const int LEN = 32;
const int MAXN = 2048;
std::string s;
bool image[LEN][LEN];
int cnt;

void draw(int& p, int r, int c, int w){
    char ch = s[p];
    ++p;
    if(ch=='p'){
        draw(p,r,c+w/2,w/2);
        draw(p,r,c,w/2);
        draw(p,r+w/2,c,w/2);
        draw(p,r+w/2,c+w/2,w/2);
    }else if(ch == 'f'){
        for(int i = r; i < r+w; ++i)
            for(int j = c; j < c+w; ++j){
                if(image[i][j] == false){
                    image[i][j] = true; ++cnt;
                }
            }
    }
}
int main(void){
#ifndef ONLINE_JUDGE
    freopen("quardtrees_input.txt", "r", stdin);
    freopen("quardtrees_output.txt", "w", stdout);
#endif
    s.reserve(MAXN);
    int n;
    std::cin>>n;
    while(n>0){
        --n;
        memset(image,0,LEN*LEN*sizeof(bool));
        cnt = 0;
        for(int i = 0; i < 2; ++i){
            std::cin>>s;
            int p =0;
            draw(p,0,0,LEN);
        }
        std::cout<<"There are "<<cnt<<" black pixels."<<std::endl;
    }
    return 0;
}
