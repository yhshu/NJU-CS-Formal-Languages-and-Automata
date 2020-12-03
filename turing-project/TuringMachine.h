//
// Created by Yiheng Shu on 2020/12/2.
//

#ifndef TURING_MACHINE_TURING_PROJECT_TURINGMACHINE_H_
#define TURING_MACHINE_TURING_PROJECT_TURINGMACHINE_H_

#include <unordered_set>
#include <string>
#include <vector>
#include "TransitionFunction.h"

using namespace std;

class TuringMachine {
 private:
  unordered_set<string> state_set_;
  unordered_set<char> input_symbols_set_;
  unordered_set<char> tape_symbols_set_;
  string init_state_;
  char blank_symbol_;
  unordered_set<string> final_state_set_;
  unordered_set<TransitionFunction, TransitionFunction::Hash> transition_functions_;
  int num_tape_;

 public:
  explicit TuringMachine(const vector<string> &tm_str);

  void BuildStateSet(const string &line);

  void BuildInputSymbolsSet(const string &line);

  void BuildTapeSymbolsSet(const string &line);

  void CheckDefinition();

  void BuildFinalStateSet(const string &line);

  bool CheckTransitionFuncDefinition(const vector<string> &transition_func_vec);
};

#endif//TURING_MACHINE_TURING_PROJECT_TURINGMACHINE_H_
