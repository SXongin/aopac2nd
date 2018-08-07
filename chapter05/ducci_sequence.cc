/*UVa 1594
 */

#include <array>
#include <iostream>
#include <unordered_set>
#include <vector>

//using boost::hash_combine
template <class T>
inline void hash_combine(std::size_t& seed, T const& v)
{
    seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
namespace std
{
    template<typename T>
    struct hash<vector<T>>
    {
        typedef vector<T> argument_type;
        typedef std::size_t result_type;
        result_type operator()(argument_type const& in) const
        {
            size_t size = in.size();
            size_t seed = 0;
            for (size_t i = 0; i < size; i++)
                //Combine the hash of the current vector with the hashes of the previous ones
                hash_combine(seed, in[i]);
            return seed;
        }
    };
}


const int kMax = 2010;
std::unordered_set<std::vector<int> > appear;

int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\ducci_sequence_input.txt", "r", stdin);
    freopen("chapter05\\ducci_sequence_output.txt", "w", stdout);
#endif
    int kase;
    std::cin >> kase;
    while (kase > 0) {
        --kase;
        appear.clear();
        std::vector<int> now;
        int n;
        std::cin >> n;
        while (n > 0) {
            --n;
            int tmp;
            std::cin >> tmp;
            now.push_back(tmp);
        }
        bool b_zero = false;
        bool b_loop = false;
        std::vector<int> next;
        for (int i = 0; i < kMax; ++i) {
            b_zero = true;
            for (auto v : now) {
                if (v != 0) {
                    b_zero = false;
                    break;
                }
            }
            if (b_zero) { break; }
            b_loop = false;
            if(appear.count(now) != 0){
                b_loop = true; break;
            }
            appear.insert(now);
            next.clear();
            int length = now.size();
            for(int index = 0; index < length; ++index){
                next.push_back(std::abs(now[index] - now[(index + 1)%length]));
            }
            now = std::move(next);
        }
        if(b_zero){
            std::cout << "ZERO" << std::endl;
        }
        if(b_loop){
            std::cout << "LOOP" << std::endl;
        }
    }
    return 0;
}
