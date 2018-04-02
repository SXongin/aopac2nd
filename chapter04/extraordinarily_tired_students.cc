/*UVa 12108
*/

#include <iostream>
#include <vector>
#include <set>

const int kMax = 10;

struct Student{
    int awake;
    int period;
    int status;
};


std::vector<Student> vec_student;
std::vector<int> vec_status;
std::set<std::vector<int> > set_status;
bool can_sleep;
bool all_awake;
int kase = 1;
int num_students;

bool read_init(){
    int num_awake(0);
    int num_sleep(0);
    for(int i(0);i < num_students; ++i){
        Student stu;
        int sleep;
        std::cin >> stu.awake >> sleep >> stu.status;
        stu.period = stu.awake + sleep;
        vec_student.push_back(stu);
        vec_status.push_back(stu.status);
        if(stu.status <= stu.awake){
            ++num_awake;
        }else{
            ++num_sleep;
        }
    }
    if(num_awake == num_students){
        return true;
    }else{
        if(num_sleep > num_awake){
            can_sleep = true;
        }else{
            can_sleep = false;
        }
        set_status.insert(vec_status);
        return false;
    }
}

bool update(){
    vec_status.clear();
    int num_awake(0), num_sleep(0);
    for(auto& stu: vec_student){
        ++stu.status;
        if(stu.status > stu.period) stu.status = 1;
        if(stu.status == (stu.awake + 1) && !can_sleep) stu.status = 1;
        if(stu.status <= stu.awake){
            ++num_awake;
        }else{
            ++num_sleep;
        }
        vec_status.push_back(stu.status);
    }
    if(num_awake == num_students){
        all_awake = true;
        return false;
    }
    auto search = set_status.find(vec_status);
    if(search != set_status.end()){
        return false;
    }else{
        set_status.insert(vec_status);
    }

    if(num_sleep > num_awake){
        can_sleep = true;
    }else{
        can_sleep = false;
    }
    return true;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("extraordinarily_tired_students_input.txt", "r", stdin);
    freopen("extraordinarily_tired_students_output.txt", "w", stdout);
#endif
    vec_student.reserve(kMax);
    vec_status.reserve(kMax);
    while(std::cin >> num_students && num_students != 0){
        std::cout << "Case " << kase << ": ";
        ++kase;
        vec_student.clear();
        set_status.clear();
        all_awake = false;
        if(read_init()){
            std::cout << "1" << std::endl;
            continue;
        }
        int time;
        for(time = 2; update(); ++time);
        if(all_awake){
            std::cout << time;
        }else{
            std::cout << "-1";
        }
        std::cout << std::endl;
    }
    return 0;
}
