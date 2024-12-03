#include <cassert>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

bool is_safe_report(const std::vector<int>& report) {
  auto strictly_increasing = true, strictly_decreasing = true;
  for (auto i = 1; i < report.size(); ++i) {
    auto diff = report[i] - report[i - 1];
    if (std::abs(diff) < 1 || std::abs(diff) > 3) {
      return false;
    }

    strictly_increasing = strictly_increasing && (diff > 0);
    strictly_decreasing = strictly_decreasing && (diff < 0);
  }

  return strictly_increasing || strictly_decreasing;
}

int main(int argc, const char* argv[]) {
  const std::filesystem::path input_path{"input.txt"};
  assert(std::filesystem::exists(input_path));

  std::ifstream file{input_path};
  assert(file.is_open());

  std::vector<std::vector<int>> reports;

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream line_stream{line};
    std::vector<int> row;

    int num;
    while (line_stream >> num) {
      row.push_back(num);
    }

    reports.push_back(std::move(row));
  }

  const auto n_safe_reports = std::ranges::count_if(reports, is_safe_report);
  std::cout << n_safe_reports << '\n';
}
