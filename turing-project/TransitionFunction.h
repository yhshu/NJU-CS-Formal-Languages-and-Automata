//
// Created by Dell on 2020/12/2.
//

#ifndef TURING_MACHINE_TURING_PROJECT_TRANSITIONFUNCTION_H_
#define TURING_MACHINE_TURING_PROJECT_TRANSITIONFUNCTION_H_

#include <string>
#include <utility>
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
                     const string &input_symbols,
                     const string &output_symbols,
                     const string &directions,
                     string output_state, int num_tape);

  int GetNumTape() const;
  const string &GetInputState() const;
  const vector<char> &GetInputSymbols() const;
  const vector<char> &GetOutputSymbols() const;
  const vector<char> &GetDirections() const;
  const string &GetOutputState() const;

  bool operator==(const TransitionFunction &other) const;


  struct Hash {
    size_t operator()(const TransitionFunction &tf) const {
      size_t input_symbols;
      for (const char &ch : tf.GetInputSymbols()) {
        input_symbols += std::hash<char>()(ch);
      }
      size_t input_state;
      for (const char &ch: tf.GetInputState()) {
        input_state += std::hash<char>()(ch);
      }
      size_t num_tape = std::hash<int>()(tf.GetNumTape());
      return (num_tape + input_symbols) ^ (num_tape + input_state);
    }
  };

};

#endif//TURING_MACHINE_TURING_PROJECT_TRANSITIONFUNCTION_H_
