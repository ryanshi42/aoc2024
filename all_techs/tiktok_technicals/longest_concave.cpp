#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

int best_concave(std::vector<int> &nums) {
  int best = 0;

  auto decs = std::vector<int>();
  for (int i = 0; i < nums.size(); i++) {
    while (!decs.empty() && nums[decs.back()] < nums[i])
      decs.pop_back();

    if (!decs.empty())
      best = std::max(best, i - decs.back() + 1);

    decs.push_back(i);
  }
  return best;
}

int solve(std::vector<int> &nums) {
  auto best = best_concave(nums);
  std::reverse(nums.begin(), nums.end());
  return std::max(best, best_concave(nums));
}

int main() {
    std::vector<int> nums = {4, 1, 5, 2, 3, 6};

    std::cout << solve(nums);
}