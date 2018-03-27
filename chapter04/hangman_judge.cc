/*UVa 489
 */

#include <bitset>
#include <iostream>
#include <string>

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("hangman_judge_input.txt", "r", stdin);
  freopen("hangman_judge_output.txt", "w", stdout);
#endif
  const int kLen = 26;
  std::bitset<kLen> alphabet;
  std::bitset<kLen> solved;
  int round;
  while ((std::cin >> round) and round != -1) {
    std::string str;
    std::cin >> str;
    alphabet.reset();
    solved.reset();
    for (auto c : str) {
      alphabet.set(c - 'a');
    }
    std::cin >> str;
    int chance = 7;
    bool lose = false;
    bool win = false;
    for (auto c : str) {
      if (solved.test(c - 'a')) continue;
      solved.set(c - 'a');
      if (alphabet.test(c - 'a')) {
        alphabet.reset(c - 'a');
      } else {
        --chance;
      }
      if (alphabet.none()) {
        win = true;
        break;
      }
      if (chance == 0) {
        lose = true;
        break;
      }
    }
    std::cout << "Round " << round << std::endl;
    if (win) {
      std::cout << "You win." << std::endl;
    } else if (lose) {
      std::cout << "You lose." << std::endl;
    } else {
      std::cout << "You chickened out." << std::endl;
    }
  }
  return 0;
}
