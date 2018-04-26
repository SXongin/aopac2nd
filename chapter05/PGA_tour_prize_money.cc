/*UVa 207
 */

#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <string>

const int kMax      = 150;
const int kPrizeNum = 70;

struct Player {
    std::string name;
    bool amateur  = false;
    bool dq4      = false;
    bool dq2      = false;
    int scores[4] = {0};
    int total2    = 0;
    int total4    = 0;
    int rank      = 0;
};

double amount;
std::array<double, kPrizeNum> prizes;
int player_num;
std::array<Player, kMax> players;
int players_index[kMax];

bool cutcmp(const int& li, const int& ri)
{
    if (!players[li].dq2 && !players[ri].dq2) {
        return players[li].total2 < players[ri].total2;
    } else if (players[li].dq2) {
        return false;
    } else {
        return true;
    }
}

bool prizecmp(const int& li, const int& ri)
{
    auto& lhs = players[li];
    auto& rhs = players[ri];
    if (!lhs.dq4 && !rhs.dq4) {
        return (lhs.total4 < rhs.total4) || ((lhs.total4 == rhs.total4) && (lhs.name < rhs.name));
    } else if (lhs.dq4 && rhs.dq4) {
        return (lhs.rank > players[ri].rank) ||
               ((lhs.rank == rhs.rank) &&
                ((lhs.total4 < rhs.total4) || ((lhs.total4 == rhs.total4) && (lhs.name < rhs.name))));
    } else if (lhs.dq4) {
        return false;
    } else {
        return true;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("PGA_tour_prize_money_input.txt", "r", stdin);
    freopen("PGA_tour_prize_money_output.txt", "w", stdout);
#endif
    int kase;
    std::cin >> kase;
    while (kase > 0) {
        --kase;
        std::cin >> amount;
        for (int i = 0; i < kPrizeNum; ++i) {
            double percent;
            std::cin >> percent;
            prizes[i] = percent;
        }
        std::cin >> player_num;
        std::string str;
        std::getline(std::cin, str);
        int notdq2 = player_num;
        for (int i = 0; i < player_num; ++i) {
            players_index[i] = i;
            players[i] = Player();
            std::getline(std::cin, str);
            players[i].name = str.substr(0, 20);
            int last        = players[i].name.find_last_not_of(" ");
            players[i].name.resize(last + 1);
            if (players[i].name[last] == '*') {
                players[i].amateur = true;
            }
            int j;
            for (j = 0; j < 4; ++j) {
                std::string tmp = str.substr(20 + j * 3, 3);
                try {
                    players[i].scores[j] = std::stoi(tmp);
                } catch (std::invalid_argument& e) {
                    players[i].scores[j] = -1;
                    if (j < 2) {
                        players[i].dq2 = true;
                        --notdq2;
                    } else {
                        players[i].dq4 = true;
                    }
                    break;
                }
                if (j < 2) {
                    players[i].total2 += players[i].scores[j];
                }
                players[i].total4 += players[i].scores[j];
            }
            players[i].rank = j;
        }

        std::sort(players_index, players_index + player_num, cutcmp);

        int cut_num = notdq2;
        if (cut_num > kPrizeNum) {
            for (cut_num = kPrizeNum; cut_num < player_num && !players[players_index[cut_num]].dq2 &&
                                      players[players_index[cut_num]].total2 == players[players_index[69]].total2;
                 ++cut_num) {
                ;
            }
        }

        std::cout << std::left << std::setw(21) << "Player Name" << std::setw(10) << "Place" << std::setw(5) << "RD1"
                  << std::setw(5) << "RD2" << std::setw(5) << "RD3" << std::setw(5) << "RD4" << std::setw(10) << "TOTAL"
                  << "Money Won" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;

        std::sort(players_index, players_index + cut_num, prizecmp);

        for (int i = 0, j = 0; i < cut_num;) {
            int place          = i + 1;
            auto& start        = players[players_index[i]];
            int tie = 1;
            int prize_tie;
            if(start.amateur){
                prize_tie = 0;
            }else{
                prize_tie = 1;
            }
            double total_prize = 0;
            if (!start.dq4 && !start.amateur && j < kPrizeNum) {
                total_prize = prizes[j];
                ++j;
            }

            while (true) {
                if(start.dq4){
                    ++i;
                    break;
                }
                auto& now = players[players_index[i + 1]];
                ++i;
                if (!now.dq4 && !now.dq2 && now.total4 == start.total4) {
                    if (!now.amateur) {
                        if (j < kPrizeNum) {
                            total_prize += prizes[j];
                            ++j;
                        }
                        ++prize_tie;
                    }
                    ++tie;
                } else {
                    break;
                }
            }

            double prize          = total_prize * amount / prize_tie / 100.0;
            std::string str_place = std::to_string(place);
            if (prize_tie > 1) {
                str_place.append("T");
            }
            for (int n = 0; n < tie; ++n) {
                auto player = players[players_index[place - 1 + n]];
                std::cout << std::left << std::setw(21) << player.name;
                if (player.dq4) {
                    std::cout << std::setw(10) << " ";
                } else {
                    if (player.amateur) {
                        std::cout << std::setw(10) << place;
                    } else {
                        std::cout << std::setw(10) << str_place;
                    }
                }

                for (int k = 0; k < 4; ++k) {
                    if (player.scores[k] > 0) {
                        std::cout << std::setw(5) << player.scores[k];
                    }else {
                        std::cout << std::setw(5) << " ";
                    }
                }

                if (!player.dq4) {
                    std::cout << std::setw(3) << player.total4;
                } else {
                    std::cout << "DQ";
                }

                if (total_prize != 0 && !player.amateur) {
                    std::cout << "       $" /*<< std::right << std::fixed << std::setprecision(2) << std::setw(9) << prize*/;
                    printf("%9.2f", prize);

                }
                std::cout << std::endl;
            }
        }
        if(kase != 0){
            std::cout << std::endl;
        }
    }
    return 0;
}
