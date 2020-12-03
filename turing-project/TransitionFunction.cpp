//
// Created by Dell on 2020/12/2.
//

#include "TransitionFunction.h"
TransitionFunction::TransitionFunction(string input_state,
                                       const string &input_symbols,
                                       const string &output_symbols,
                                       const string &directions,
                                       string output_state,
                                       int num_tape)
    : input_state_(std::move(input_state)), output_state_(std::move(output_state)), num_tape_(num_tape) {
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

int TransitionFunction::GetNumTape() const {
  return num_tape_;
}
const string &TransitionFunction::GetInputState() const {
  return input_state_;
}
const vector<char> &TransitionFunction::GetInputSymbols() const {
  return input_symbols_;
}
bool TransitionFunction::operator==(const TransitionFunction &other) const {
  return (num_tape_ == other.num_tape_
      && input_state_ == other.input_state_
      && input_symbols_ == other.input_symbols_);
}
