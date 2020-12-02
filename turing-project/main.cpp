//
// Created by Yiheng Shu on 2020/12/2.
//

#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include "TuringMachine.h"
#include "utils.h"

using namespace std;

bool verbose = false;

int main(int argc, char *argv[]) {
  int arg_num = 0;

  for (int i = 1; i < argc; i++) {
    string arg = argv[i];
    if (arg == "-v" or arg == "--verbose") {
      verbose = true;
    } else if (arg == "-h" or arg == "--help") {
      help();
    } else {
      arg_num++;
    }
  }

  if (arg_num < 2) {
    cerr << "error: the number of arguments is illegal";
    exit(1);
  }

  ifstream tm_file;
  tm_file.open(argv[argc - 2]);
  string input = argv[argc - 1];
  if (!tm_file) {
    cerr << "error: the TM program path is not correct";
    exit(1);
  }

  string line;
  vector<string> tm_str;
  while (tm_file >> line) {
    tm_str.push_back(line);
  }
  bool build_success;
  TuringMachine turing_machine(tm_str);
  if (!build_success) {
    syntaxError();
  }

  return 0;
}
