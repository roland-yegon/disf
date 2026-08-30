#include <fstream>
#include <iostream>

int main(int argc, char *args[]) {
  if (argc < 2) {
    std::cout << "Invalid number arguments\n";
    std::cout << "USAGE: disf <file_name>\n";
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    std::ifstream file_name{args[i]};
    if (!file_name) {
      std::cout << "Failed to read file " << args[i] << '\n';
      return 1;
    }

    std::cout << "\n=========================================\n";
    std::cout << "Displaying: " << args[i];
    std::cout << "\n=========================================\n";

    std::cout << '\n';
    std::string line;
    while (std::getline(file_name, line)) {
      std::cout << line << '\n';
    }
  }

  return 0;
}
