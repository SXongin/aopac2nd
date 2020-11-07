/*UVa 816
 */

#include <iostream>
#include <map>
#include <tuple>
#include <utility>

enum class Direction : uint8_t {
  NORTH = 'N',
  WEST = 'W',
  SOUTH = 'S',
  EAST = 'E'
};

enum class Turn : uint8_t { FORWARD = 'F', LEFT = 'L', RIGHT = 'R' };

struct DirectionTurn {
  Direction d;
  Turn t;
};

bool operator<(const DirectionTurn& lhs, const DirectionTurn& rhs) {
  return std::tie(lhs.d, lhs.t) < std::tie(rhs.d, rhs.t);
}

using Walk = std::pair<int, int>;

const std::map<Direction, Walk> move = {{Direction::NORTH, {-1, 0}},
                                        {Direction::WEST, {0, -1}},
                                        {Direction::SOUTH, {1, 0}},
                                        {Direction::EAST, {0, 1}}};

const std::map<DirectionTurn, Direction> WalkTo = {
    {{Direction::NORTH, Turn::FORWARD}, Direction::NORTH},
    {{Direction::NORTH, Turn::LEFT}, Direction::WEST},
    {{Direction::NORTH, Turn::RIGHT}, Direction::EAST},
    {{Direction::WEST, Turn::FORWARD}, Direction::WEST},
    {{Direction::WEST, Turn::LEFT}, Direction::SOUTH},
    {{Direction::WEST, Turn::RIGHT}, Direction::NORTH},
    {{Direction::SOUTH, Turn::FORWARD}, Direction::SOUTH},
    {{Direction::SOUTH, Turn::LEFT}, Direction::EAST},
    {{Direction::SOUTH, Turn::RIGHT}, Direction::WEST},
    {{Direction::EAST, Turn::FORWARD}, Direction::EAST},
    {{Direction::EAST, Turn::LEFT}, Direction::NORTH},
    {{Direction::EAST, Turn::RIGHT}, Direction::SOUTH}};

struct Position{
  int row;
  int column;
  Direction direction;
};

bool operator<(const Position& lhs, const Position& rhs){
  return std::tie(lhs.row, lhs.column, lhs.direction) < std::tie(rhs.row, rhs.column, rhs.direction);
}

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("chapter06/abbotts_revenge_in", "r", stdin);
  freopen("chapter06/abbotts_revenge_out", "w", stdout);
#endif

}
