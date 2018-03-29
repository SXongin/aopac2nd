/*UVa 220
 */

#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Site {
  int r;
  int c;
  Site(int r, int c) : r(r), c(c) {}
};

const int kMax = 10;
std::array<std::string, kMax> board;
std::vector<Site> vec_site;
int B, W;
bool is_black;

bool the_oppo(char ch) {
  if (is_black)
    return ch == 'W';
  else
    return ch == 'B';
}

bool the_same(char ch) {
  if (is_black)
    return ch == 'B';
  else
    return ch == 'W';
}

void set_same(char& ch) {
  if (is_black) {
    ch = 'B';
    ++B;
    --W;
  } else {
    ch = 'W';
    ++W;
    --B;
  }
}

bool go(int r, int c, int dr, int dc, bool is_test) {
  int mr = r;
  int mc = c;
  if (!the_oppo(board[mr][mc])) return false;
  while (the_oppo(board[mr][mc])) {
    mr += dr;
    mc += dc;
  }
  if (board[mr][mc] == '-') return false;
  if (!is_test) {
    for (; r != mr || c != mc; r += dr, c += dc) {
      set_same(board[r][c]);
    }
  }
  return true;
}

bool move(int r, int c, bool is_test) {
  bool legal = false;
  for (int dr = -1; dr <= 1; ++dr) {
    for (int dc = -1; dc <= 1; ++dc) {
      if (dr != 0 || dc != 0) {
        bool tmp_legal;
        tmp_legal = go(r + dr, c + dc, dr, dc, is_test);
        if (!legal && tmp_legal) {
          legal = tmp_legal;
        }
        if (is_test && legal) return legal;
      }
    }
  }
  if (!is_test && !legal) {
    is_black = !is_black;
    for (int dr = -1; dr <= 1; ++dr) {
      for (int dc = -1; dc <= 1; ++dc) {
        if (dr != 0 || dc != 0) {
          go(r + dr, c + dc, dr, dc, is_test);
        }
      }
    }
  }
  return legal;
}

void print_legal_move(void) {
  if (!vec_site.empty()) {
    bool first = true;
    for (const auto& site : vec_site) {
      if (first)
        first = false;
      else
        std::cout << " ";
      std::cout << "(" << site.r << "," << site.c << ")";
    }
  } else {
    std::cout << "No legal move.";
  }
  std::cout << std::endl;
}

void print_status(void) {
  std::cout << "Black - " << std::setw(2) << B << " White - " << std::setw(2)
            << W << std::endl;
}

void print_board(void) {
  for (int r = 1; r <= 8; ++r) {
    for (int c = 1; c <= 8; ++c) {
      std::cout << board[r][c];
    }
    std::cout << std::endl;
  }
}

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("othello_input.txt", "r", stdin);
  freopen("othello_output.txt", "w", stdout);
#endif
  vec_site.reserve(kMax * kMax);
  std::for_each(board.begin(), board.end(),
                [](std::string& str) { str.resize(kMax); });
  int T;
  std::cin >> T;
  while (T--) {
    std::for_each(board.begin(), board.end(), [](std::string& str) {
      std::fill(str.begin(), str.end(), '-');
    });
    B = 0;
    W = 0;
    char ch;
    for (int i = 1; i <= 8; ++i) {
      for (int j = 1; j <= 8; ++j) {
        std::cin >> ch;
        if (ch == 'W') {
          board[i][j] = ch;
          ++W;
        } else if (ch == 'B') {
          board[i][j] = ch;
          ++B;
        }
      }
    }

    std::cin >> ch;
    if (ch == 'B') {
      is_black = true;
    } else {
      is_black = false;
    }

    static bool first = true;
    if (first)
      first = false;
    else
      std::cout << std::endl;
    while (std::cin >> ch && ch != 'Q') {
      switch (ch) {
        case 'L':
          vec_site.clear();
          for (int r = 1; r <= 8; ++r)
            for (int c = 1; c <= 8; ++c) {
              if (board[r][c] == '-' && move(r, c, true)) {
                vec_site.push_back(std::move(Site(r, c)));
              }
            }
          print_legal_move();
          break;
        case 'M':
          int r, c;
          int num;
          std::cin >> num;
          r = num / 10;
          c = num % 10;
          move(r, c, false);
          if (is_black) {
            board[r][c] = 'B';
            ++B;
          } else {
            board[r][c] = 'W';
            ++W;
          }
          print_status();
          is_black = !is_black;
          break;
        default:
          break;
      }
    }
    if (ch == 'Q') print_board();
  }
  return 0;
}
