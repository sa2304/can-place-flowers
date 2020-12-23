#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    size_t count = 0;
    for (size_t i = 0; i < flowerbed.size() && count < n; ++i) {
      if (0 == flowerbed[i]) {
        bool is_first_plant = 0 == i;
        bool is_left_vacant = (is_first_plant || flowerbed[i-1] == 0);
        bool is_last_plant = flowerbed.size() - 1 == i;
        bool is_right_vacant = (is_last_plant || flowerbed[i + 1] == 0);
        if (is_left_vacant && is_right_vacant) {
          flowerbed[i] = 1;
          ++count;
        }
      }
    }

    return n <= count;
  }
};

#endif // SOLUTION_H
