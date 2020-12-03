//
// Created by Yiheng Shu on 2020/12/2.
//

#ifndef TURING_MACHINE_TURING_PROJECT_UTILS_H_
#define TURING_MACHINE_TURING_PROJECT_UTILS_H_

#include <iostream>
#include <vector>

using namespace std;

void SyntaxError(const string& error, const string& input, int error_pos);
void Help();
string Trim(const string &str);
vector<string> Split(const string &str, const string &delim);

#endif //TURING_MACHINE_TURING_PROJECT_UTILS_H_
