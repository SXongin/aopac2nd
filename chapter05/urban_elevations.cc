/*UVa 221
 */

#include <algorithm>
#include <iostream>
#include <vector>

const int kMax = 120;
struct build {
    int nid  = 0;
    double x = -1;
    double y = -1;
    double w = -1;
    double d = -1;
    double h = -1;
    bool operator<(const build& rhs) { return (this->x < rhs.x) || ((this->x == rhs.x) && (this->y < rhs.y)); }
};

int n = 0;
std::vector<build> bs;
std::vector<double> xs;

bool cover(int i, double xm) { return (bs[i].x <= xm) && (bs[i].x + bs[i].w >= xm); }

bool visible(int i, double xm)
{
    if (!cover(i, xm)) return false;
    for (int j = 0; j < n; ++j) {
        if ((bs[j].y < bs[i].y) && (bs[j].h >= bs[i].h) && cover(j, xm)) { return false; }
    }
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\urban_elevations_input.txt", "r", stdin);
    freopen("chapter05\\urban_elevations_output.txt", "w", stdout);
#endif
    bs.reserve(kMax);
    xs.reserve(2 * kMax);
    int kase = 1;
    while ((std::cin >> n) && (n > 0)) {
        if(kase != 1){
            std::cout << std::endl;
        }
        std::cout << "For map #" << kase << ", the visible buildings are numbered as follows:" << std::endl;
        ++kase;
        bs.clear();
        xs.clear();
        for (int i = 0; i < n; ++i) {
            bs.emplace_back();
            std::cin >> bs[i].x >> bs[i].y >> bs[i].w >> bs[i].d >> bs[i].h;
            bs[i].nid = i + 1;
            xs.push_back(bs[i].x);
            xs.push_back(bs[i].x + bs[i].w);
        }
        std::sort(bs.begin(), bs.end());
        std::sort(xs.begin(), xs.end());
        auto last = std::unique(xs.begin(), xs.end());
        xs.erase(last, xs.end());

        std::cout << bs[0].nid;
        for(int i = 1; i < n; ++i){
            bool can_see = false;
            for(int j = 0; j + 1 < xs.size(); ++j){
                if(visible(i, (xs[j] + xs[j + 1]) / 2.0)){
                    can_see = true; break;
                }
            }
            if(can_see){
                std::cout << " " << bs[i].nid;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
