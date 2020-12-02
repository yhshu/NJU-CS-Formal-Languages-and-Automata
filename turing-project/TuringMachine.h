//
// Created by Yiheng Shu on 2020/12/2.
//

#ifndef TURING_MACHINE_TURING_PROJECT_TURINGMACHINE_H_
#define TURING_MACHINE_TURING_PROJECT_TURINGMACHINE_H_

#include <set>
#include <string>

using namespace std;

class TuringMachine {
 private:
  set<string> state_set_;
  set<char> input_symbols_set_;
  set<char> tape_symbols_set_;
  string init_state_;
  char blank_symbol_;
  set<string> final_state_set_;
  int num_tape;

 public:
  TuringMachine(const string &tm);

  void buildStateSet(const string &line);

  void buildInputSymbolsSet(const string &line);
};

#endif//TURING_MACHINE_TURING_PROJECT_TURINGMACHINE_H_
