//
// Created by Yiheng Shu on 2020/12/2.
//

#ifndef TURING_MACHINE_TURING_PROJECT_TURINGMACHINE_H_
#define TURING_MACHINE_TURING_PROJECT_TURINGMACHINE_H_

#include <set>
#include <string>
#include <vector>
#include "TransitionFunction.h"

using namespace std;

class TuringMachine {
 private:
  set<string> state_set_;
  set<char> input_symbols_set_;
  set<char> tape_symbols_set_;
  string init_state_;
  char blank_symbol_;
  set<string> final_state_set_;
  set<TransitionFunction> transition_functions_;
  int num_tape;

 public:
  TuringMachine(const vector<string> &tm_str);

  void buildStateSet(const string &line);

  void buildInputSymbolsSet(const string &line);

  void buildTapeSymbolsSet(const string &line);

  void checkDefinition();

  void buildFinalStateSet(string line);

  bool checkTransitionFuncDefinition(const vector<string> &transition_func_vec);
};

#endif//TURING_MACHINE_TURING_PROJECT_TURINGMACHINE_H_
