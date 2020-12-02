//
// Created by Yiheng Shu on 2020/12/2.
//

#include <cstring>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool verbose = false;

void help() {
  cout << "usage: turing [-v|--verbose] [-h|--help] <tm> <input>";
}

int main(int argc, char *argv[]) {
  int arg_num = 0;

  for (int i = 1; i <= argc; i++) {
    string arg = argv[i];
    if (arg == "-v" or arg == "--verbose") {
      verbose = true;
    } else if (arg == "-h" or arg == "--help") {
      help();
    } else
      arg_num++;
  }

  if (arg_num < 3) {
    cerr << "the number of arguments is illegal";
    return 0;
  }

  ifstream tm_file;
  string tm_filepath = argv[argc - 1];
  tm_file.open(tm_filepath);
  string input = argv[argc];

  return 0;
}
