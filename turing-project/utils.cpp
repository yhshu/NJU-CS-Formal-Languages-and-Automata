//
// Created by Yiheng Shu on 2020/12/2.
//

#include "utils.h"
#include "message.h"

string Trim(const string &str) {
  if (str.empty())
    return str;
  string res = str;
  res.erase(0, res.find_first_not_of(' '));
  res.erase(res.find_last_not_of(' ') + 1);
  return res;
}
void Help() {
  cout << "usage: turing [-v|--verbose] [-h|--help] <tm> <input>";
}
void SyntaxError(const string &error, const string &input, int error_pos) {
  printERR();
  cerr << "error: " << error << endl;
  if (not input.empty())
    cerr << "Input: " << input << endl;
  if (not input.empty() and error_pos >= 0 and error_pos < input.size()) {
    cerr << "       ";
    for (int i = 0; i < error_pos; i++) { cerr << " "; }
    cerr << "^" << endl;
  }
  printEND();
  exit(1);
}
vector<string> Split(const string &str, const string &delim) {
  vector<string> res;
  string::size_type lastPos = str.find_first_not_of(delim, 0);
  string::size_type pos = str.find_first_of(delim, lastPos);
  while (string::npos != pos || string::npos != lastPos) {
    res.emplace_back(str.substr(lastPos, pos - lastPos));
    lastPos = str.find_first_not_of(delim, pos);
    pos = str.find_first_of(delim, lastPos);
  }
  return res;
}
