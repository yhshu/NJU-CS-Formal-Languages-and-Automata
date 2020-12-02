//
// Created by Dell on 2020/12/2.
//

#ifndef TURING_MACHINE_TURING_PROJECT_TRANSITIONFUNCTION_H_
#define TURING_MACHINE_TURING_PROJECT_TRANSITIONFUNCTION_H_

#include <string>
#include <vector>

using namespace std;

class TransitionFunction {
 private:
  int num_tape_;

  string input_state_;
  vector<char> input_symbols_;
  vector<char> output_symbols_;
  vector<char> directions_;
  string output_state_;

 public:
  TransitionFunction(string input_state,
                     string input_symbols,
                     string output_symbols,
                     string directions,
                     string output_state, int num_tape)
      : input_state_(input_state), output_state_(output_state), num_tape_(num_tape) {
    for (const char &ch : input_symbols) {
      input_symbols_.emplace_back(ch);
    }
    for (const char &ch: output_symbols) {
      output_symbols_.emplace_back(ch);
    }
    for (const char &ch: directions) {
      directions_.emplace_back(ch);
    }
  }
};

#endif//TURING_MACHINE_TURING_PROJECT_TRANSITIONFUNCTION_H_
