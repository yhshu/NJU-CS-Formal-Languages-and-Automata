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
  int num_tape;

  string input_state_;
  vector<char> input_symbols_;
  vector<char> output_symbols_;
  vector<char> directions;
  string output_state_;
};

#endif//TURING_MACHINE_TURING_PROJECT_TRANSITIONFUNCTION_H_
