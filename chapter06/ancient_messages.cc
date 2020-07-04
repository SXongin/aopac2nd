/*UVa 1103
 */
#include <array>  //array
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <set>

constexpr int kMaxWidth = 50 * 4 + 10;
constexpr int kMaxHeight = 200 + 10;

bool graph[kMaxHeight][kMaxWidth];
int black[kMaxHeight][kMaxWidth];
int white[kMaxHeight][kMaxWidth];
bool visited[kMaxHeight][kMaxWidth];

char sym[] = {'W', 'A', 'K', 'J', 'S', 'D'};
const std::map<char, int> kHex = {
    {'0', 0},   {'1', 1},   {'2', 2},   {'3', 3},  {'4', 4},   {'5', 5},
    {'6', 6},   {'7', 7},   {'8', 8},   {'9', 9},  {'a', 0xa}, {'b', 0xb},
    {'c', 0xc}, {'d', 0xd}, {'e', 0xe}, {'f', 0xf}};
std::map<char, int> result;

int W, H;

std::map<int, std::set<int>> hole_touch;
std::map<int, int> hieroglyphs_holes;

void DfsBlack(const int i, const int j, const int num) {
  if (i < 0 || i >= H || j < 0 || j >= 4 * W || visited[i][j]) return;
  visited[i][j] = true;
  if (graph[i][j]) {
    black[i][j] = num;
    DfsBlack(i - 1, j, num);
    DfsBlack(i + 1, j, num);
    DfsBlack(i, j - 1, num);
    DfsBlack(i, j + 1, num);
  }
}

void DfsWhite(const int i, const int j, const int num) {
  if (i < 0 || i >= H || j < 0 || j >= 4 * W) {
    hole_touch[num].insert(-1);
    return;
  }
  if (visited[i][j]) {
    return;
  }
  visited[i][j] = true;
  if (!graph[i][j]) {
    white[i][j] = num;
    for (int offset_i = -1; offset_i < 2; ++offset_i) {
      for (int offset_j = -1; offset_j < 2; ++offset_j) {
        if (offset_i == 0 && offset_j == 0) {
          continue;
        }
        DfsWhite(i + offset_i, j + offset_j, num);
      }
    }
  } else {
    hole_touch[num].insert(black[i][j]);
    visited[i][j] = false;
  }
}

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("chapter06/ancient_messages_in.txt", "r", stdin);
  freopen("chapter06/ancient_messages_out.txt", "w", stdout);
#endif
  std::string s;
  s.reserve(kMaxWidth);
  int kase = 0;
  while ((scanf("%d", &H) > 0) && (scanf("%d", &W) > 0)) {
    if (W <= 0 || H <= 0) {
      break;
    }
    ++kase;
    result.clear();
    hole_touch.clear();
    hieroglyphs_holes.clear();
    std::memset(black, 0, kMaxHeight * kMaxWidth);
    for (int h = 0; h < H; ++h) {
      std::cin >> s;
      for (int i = 0; i < s.size(); ++i) {
        const auto number = kHex.at(s[i]);
        for (int j = 0; j < 4; ++j) {
          graph[h][4 * i + j] = ((number & (0x1 << (3 - j))) != 0);
        }
      }
    }

    int hieroglyphs = 0;
    std::memset(visited, 0, kMaxHeight * kMaxWidth);

    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < 4 * W; ++j) {
        if (!visited[i][j] && graph[i][j]) {
          ++hieroglyphs;
          DfsBlack(i, j, hieroglyphs);
        }
      }
    }
    /*std::cout << "hieroglyphs: " << hieroglyphs << std::endl;*/
    int holes = 0;
    std::memset(visited, 0, kMaxHeight * kMaxWidth);
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < 4 * W; ++j) {
        if (!visited[i][j] && !graph[i][j]) {
          ++holes;
          DfsWhite(i, j, holes);
        }
      }
    }

    /*std::cout << "holes: " << holes << std::endl;*/
    for (const auto& touches : hole_touch) {
      /*std::cout << hole << " : ";
      for (auto touch : touches) {
        std::cout << touch << " ";
      }
      std::cout << std::endl;*/
      if (touches.second.size() == 1) {
        ++hieroglyphs_holes[*touches.second.begin()];
      }
    }

    for (int i = 1; i <= hieroglyphs; ++i) {
      ++result[sym[hieroglyphs_holes[i]]];
    }
    std::cout << "Case " << kase << ": ";
    for (const auto& sym_number : result) {
      for (int i = 0; i < sym_number.second; ++i) {
        std::cout << sym_number.first;
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
