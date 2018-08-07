/*UVa 10953
 */

#include <deque>
#include <iostream>

std::deque<int> deck;

void init_deck(int n)
{
    deck.clear();
    for (int i = 0; i < n; ++i) { deck.push_back(i + 1); }
}

void throw_cards(void)
{
    std::cout << "Discarded cards:";
    bool first_in = true;
    while (deck.size() > 1) {
        if (!first_in) {
            std::cout << ", " << deck.front();
        } else {
            std::cout << " " << deck.front();
            first_in = false;
        }
        deck.pop_front();
        deck.push_back(deck.front());
        deck.pop_front();
    }
    std::cout << std::endl << "Remaining card: " << deck.front() << std::endl;
}
int main(void)
{
#ifndef ONLINE_JUDGE
    freopen("chapter05\\throwing_cards_away_input.txt", "r", stdin);
    freopen("chapter05\\throwing_cards_away_output.txt", "w", stdout);
#endif
    int n;
    while ((std::cin >> n) && (n > 0)) {
        init_deck(n);
        throw_cards();
    }
    return 0;
}
