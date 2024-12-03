#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <unordered_map>

int main(int argc, const char* argv[]) {
  const std::filesystem::path input_path{"input.txt"};
  assert(std::filesystem::exists(input_path));

  std::ifstream file{input_path};
  assert(file.is_open());

  std::unordered_map<int, int> left_list_counts;
  std::unordered_map<int, int> right_list_counts;

  int left_num, right_num;
  while (file >> left_num >> right_num) {
    ++left_list_counts[left_num];
    ++right_list_counts[right_num];
  }

  int similarity_score = 0;
  for (const auto& [num, left_count] : left_list_counts) {
    if (const auto it = right_list_counts.find(num);
        it != right_list_counts.end()) {
      similarity_score += num * left_count * it->second;
    }
  }

  std::cout << similarity_score << '\n';
}
