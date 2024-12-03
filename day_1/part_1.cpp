#include <algorithm>
#include <cassert>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, const char *argv[]) {
  const std::filesystem::path input_path{"input.txt"};
  assert(std::filesystem::exists(input_path));

  std::ifstream file{input_path};
  assert(file.is_open());

  std::vector<int> left_list;
  std::vector<int> right_list;

  int left_num, right_num;
  while (file >> left_num >> right_num) {
    left_list.push_back(left_num);
    right_list.push_back(right_num);
  }

  std::sort(left_list.begin(), left_list.end());
  std::sort(right_list.begin(), right_list.end());

  int total_distance = 0;
  for (auto i = 0; i < left_list.size(); ++i) {
    total_distance += std::abs(left_list[i] - right_list[i]);
  }

  std::cout << total_distance << '\n';
}
