#include <fstream>
#include <iostream>

int main(int argc, char *args[]) {
  if (argc != 2) {
    std::cout << "Invalid number arguments\n";
    std::cout << "USAGE: disf <file_name>\n";
    return 1;
  }

  std::ifstream file_name{args[1]};
  if (!file_name) {
    std::cout << "Failed to read file\n";
    return 1;
  }

  std::string line;
  while (std::getline(file_name, line)) {
    std::cout << line << '\n';
  }

  return 0;
}
