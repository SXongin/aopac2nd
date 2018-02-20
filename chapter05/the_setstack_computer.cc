/*UVa 2096
* 有一个专门为了处理集合运算而设计的“集合栈”计算机。该机器有一个初始为空的栈，并且支持一下操作：
* PUSH：空集“{}”入栈。
* DUP：把当前栈顶元素复制一份后再入栈。
* UNION：出栈两个集合，然后把两者并集入栈
* INTERSECT：出栈两个集合，然后把两者交集入栈
* ADD：出栈两个集合，然后把先出栈的集合加入到后出栈的集合中，把结果入栈。
* 输入不超过2000个操作，并且保证操作能顺利进行。
*/

#include <iostream>
#include <set>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using Set = std::set<int>;

std::map<Set, int> id_cache;
std::vector<Set> set_cache;

int get_id(Set set){
    if(id_cache.count(set)) return id_cache[set];
    else{
        set_cache.push_back(set);
        return set_cache.size() - 1;
    }
}

int main(void){
    std::stack<int> set_stack;
    std::string op;
    int n;
    std::cin>>n;
    while(n--){
        std::cin >> op;
        if(op[0] == 'P') set_stack.push(get_id(Set()));
        else if(op[0] == 'D') set_stack.push(set_stack.top());
        else{
            Set s1, s2;
            Set s;
            s1 = set_cache[set_stack.top()];
            set_stack.pop();
            s2 = set_cache[set_stack.top()];
            set_stack.pop();
            if(op[0] == 'U') std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s, s.begin()));
            else if(op[0] == 'I') std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s, s.begin()));
            else if(op[0] == 'A') {
                s = s2;
                s.insert(get_id(s1));
            }
            set_stack.push(get_id(s));
        }
        std::cout<<set_cache[set_stack.top()].size()<<std::endl;
    }
    return 0;
}