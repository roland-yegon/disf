#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void help();

int main(int argc, char *args[]) {
  // Ensuring the user passes in a file
  if (argc < 2) {
    std::cout << "Invalid number of arguments\n";
    std::cout << '\n';
    help();
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++) { // Loop to access and print multiple files
    std::ifstream file_name{args[i]};

    // Checking for options and invalid files
    if (!file_name) {
      if (static_cast<std::string>(args[1]).compare("--help") == 0) {
        help();
        break; // Ends the loop
      }

      std::cout << "\n=========================================\n";
      std::cout << "Failed to read file \"" << args[i] << '\"';
      std::cout << "\n=========================================\n";
      return EXIT_FAILURE;
    }

    // displaying the file line by line
    std::cout << "\n=========================================\n";
    std::cout << "Displaying: " << args[i];
    std::cout << "\n=========================================\n";

    std::cout << '\n';
    std::string line;
    while (std::getline(file_name, line)) {
      std::cout << line << '\n';
    }
  }

  return EXIT_SUCCESS;
}

// help function
void help() {
  std::cout << "Disf V0.1.0\n";
  std::cout << "Usage: disf [OPTIONS]... [FILES]...\n";
  std::cout << "\n[OPTIONS]\n";
  std::cout << "\t--help\tdisplay the help menu\n";
  std::cout << "\n[EXAMPLES]\n";
  std::cout << "\tdisf --help\n";
  std::cout << "\tdisf file0.txt\n";
  std::cout << "\tdisf file1.txt file2.txt\n";
  std::cout << "\tdisf file3.txt ~/Documents/file4.txt\n";
  std::cout << "\n[NOTE]\n";
  std::cout
      << "\t--help is a stand-alone argument.\n\tAny arguments after it will "
         "be ignored.\n\tIf it appears after some arguents, it won't work\n";
}
