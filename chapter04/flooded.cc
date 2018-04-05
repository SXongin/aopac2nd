/*UVa 815
*/

#include <iostream>
#include <set>
#include <iterator> /* distance() */
#include <iomanip>

int main(){
#ifndef ONLINE_JUDGE
    freopen("flooded_input.txt", "r", stdin);
    freopen("flooded_output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    const int unit = 10;
    std::multiset<int> areas;
    int m, n;
    double w;
    int region = 1;
    std::cout << std::fixed << std::setprecision(2);
    while(std::cin >> m >> n && m != 0 && n != 0){
        areas.clear();
        std::cout << "Region " << region << std::endl;
        ++region;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                int h;
                std::cin >> h;
                areas.insert(h);
            }
        std::cin >> w;
        int submerge = 0;
        double water_level = static_cast<double>(*areas.begin());
        for(auto itr = areas.begin(); w > 0 && itr != areas.end(); ){
            auto next = areas.upper_bound(*itr);
            submerge += std::distance(itr, next);
            if(next == areas.end()){
                water_level += w / static_cast<double>(submerge * unit * unit);
                w = 0;
            }else{
                water_level += *next - *itr;
                w -= (*next - *itr) * submerge * unit * unit;
            }
            itr = next;
        }
        if(w < 0){
            water_level += w/static_cast<double>(submerge * unit *unit);
        }
        std::cout << "Water level is " << water_level << " meters." << std::endl;
        std::cout << static_cast<double>(submerge) * 100.0 /((static_cast<double>(m) * n)) <<" percent of the region is under water." << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
