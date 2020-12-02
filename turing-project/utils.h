//
// Created by Yiheng Shu on 2020/12/2.
//

#ifndef TURING_MACHINE_TURING_PROJECT_UTILS_H_
#define TURING_MACHINE_TURING_PROJECT_UTILS_H_

#include <iostream>
#include <vector>

using namespace std;

void syntaxError();
void help();
string trim(const string &str);
vector<string> split(const string &str, const string &delim);

#endif //TURING_MACHINE_TURING_PROJECT_UTILS_H_
