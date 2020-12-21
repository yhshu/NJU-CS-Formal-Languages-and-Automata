//
// Created by Yiheng Shu on 2020/12/2.
//

#ifndef TURING_MACHINE_TURING_PROJECT_UTILS_H_
#define TURING_MACHINE_TURING_PROJECT_UTILS_H_

#include <iostream>
#include <vector>

using namespace std;

bool &GetVerbose();
void SyntaxError(const string &error, const string &sentence, int error_pos);
void IllegalInput(const string &input, int error_pos);
void Help();
string Trim(const string &str, const char &ch);
vector<string> Split(const string &str, const string &delim);
int NumLen(long long int num);
string Space(int num_space);

#endif //TURING_MACHINE_TURING_PROJECT_UTILS_H_
