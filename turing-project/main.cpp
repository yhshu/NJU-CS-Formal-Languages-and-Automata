//
// Created by Yiheng Shu on 2020/12/2.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool verbose = false;

void help() {
  cout << "usage: turing [-v|--verbose] [-h|--help] <tm> <input>";
}

int main(int argc, char *argv[]) {
  string line;
  cin >> line;
  for (int i = 1; i <= argc; i++) {
    string arg = argv[i];
    if (arg == "-v" or arg == "--verbose") {
      verbose = true;
    } else if (arg == "-h" or arg == "--help") {
      help();
    }
  }

  return 0;
}

