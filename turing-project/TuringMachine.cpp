//
// Created by Yiheng Shu on 2020/12/2.
//

#include <iostream>
#include "TuringMachine.h"
#include "utils.h"
#include "TransitionFunction.h"

TuringMachine::TuringMachine(const vector<string> &tm_str) {
  for (string line: tm_str) {
    auto commentIndex = line.find(';');
    line = line.substr(0, commentIndex);
    line = Trim(line);
    if (line.empty())  // empty line or comment
      continue;
    if (line.size() <= 5) {
      SyntaxError();
    }

    if (line.find("#Q = ") == 0) {         // 1. state set
      BuildStateSet(line);
    } else if (line.find("#S = ") == 0) {  // 2. input symbol set
      BuildInputSymbolsSet(line.substr(6));
    } else if (line.find("#G = ") == 0) {  // 3. tape symbol set
      BuildTapeSymbolsSet(line);
    } else if (line.find("#q0 = ") == 0) { // 4. init_state
      this->init_state_ = line.substr(6, line.size());
    } else if (line.find("#B = ") == 0) {  // 5. blank symbol
      string blank_symbol = line.substr(6, line.size());
      if (blank_symbol.size() != 1) {
        SyntaxError();
      }
      this->blank_symbol_ = blank_symbol[0];
    } else if (line.find("#F = ") == 0) {  // 6. final state set
      BuildFinalStateSet(line);
    } else if (line.find("#N = ") == 0) {  // 7. the tape number
      this->num_tape_ = stoi(line.substr(6, line.size()));
    } else {                                  // 8. transition functions
      auto trans_func_vec = Split(line, " ");
      if (trans_func_vec.size() != 5) {
        SyntaxError();
      }

      if (CheckTransitionFuncDefinition(trans_func_vec)) {
        TransitionFunction transition_function(trans_func_vec.at(0), trans_func_vec.at(1),
                                               trans_func_vec.at(2), trans_func_vec.at(3),
                                               trans_func_vec.at(4), num_tape_);
        transition_functions_.insert(transition_function);
      } else {
        SyntaxError();
      }
    }
  }

  CheckDefinition(); // check the TM definition
}

void TuringMachine::BuildStateSet(const string &line) {
  if (line.find("#Q = {") != 0)
    SyntaxError();
  if (line.find('}') != line.size() - 1)
    SyntaxError();

  auto state_vec = Split(line.substr(6, line.size() - 1), ",");
  for (const string &state: state_vec) {
    this->state_set_.insert(state);
  }
}

void TuringMachine::BuildInputSymbolsSet(const string &line) {
  if (line.find("#S = {") != 0)
    SyntaxError();
  if (line.find('}') != line.size() - 1)
    SyntaxError();

  auto input_symbols_vec = Split(line.substr(6, line.size() - 1), ",");
  for (const string &input_symbol: input_symbols_vec) {
    if (input_symbol.size() != 1 or input_symbol[0] == ';' or input_symbol[0] == '*' or input_symbol[0] == '_')
      SyntaxError();
    this->input_symbols_set_.insert(input_symbol[0]);
  }
}

void TuringMachine::BuildTapeSymbolsSet(const string &line) {
  if (line.find("#G = {") != 0)
    SyntaxError();
  if (line.find('}') != line.size() - 1)
    SyntaxError();

  auto tape_symbols_vec = Split(line.substr(6, line.size() - 1), ",");
  for (const string &tape_symbol: tape_symbols_vec) {
    if (tape_symbol.size() != 1 or tape_symbol[0] == ';' or tape_symbol[0] == '*')
      SyntaxError();
    this->tape_symbols_set_.insert(tape_symbol[0]);
  }
}

void TuringMachine::BuildFinalStateSet(const string &line) {
  if (line.find("#F = {") != 0)
    SyntaxError();
  if (line.find('}') != line.size() - 1)
    SyntaxError();

  auto final_states_vec = Split(line.substr(6, line.size() - 1), ",");
  for (const string &final_state: final_states_vec) {
    this->final_state_set_.insert(final_state);
  }
}

void TuringMachine::CheckDefinition() {
  // check the init state definition
  if (state_set_.find(init_state_) == state_set_.end())
    SyntaxError();

  // check the blank symbol definition
  if (tape_symbols_set_.find(blank_symbol_) == tape_symbols_set_.end())
    SyntaxError();

  // check the final state definition
  for (const string &final_state: final_state_set_) {
    if (state_set_.find(final_state) == state_set_.end()) {
      SyntaxError();
    }
  }

  // check the number of tape
  if (num_tape_ <= 0)
    SyntaxError();
}

bool TuringMachine::CheckTransitionFuncDefinition(const vector<string> &transition_func_vec) {
  if (transition_func_vec.size() != 5)
    return false;
  if (state_set_.find(transition_func_vec.at(0)) == state_set_.end()) // the current state
    return false;

  for (const char &ch : transition_func_vec.at(1)) { // symbols under read-write head
    if (tape_symbols_set_.find(ch) == tape_symbols_set_.end())
      return false;
  }

  for (const char &ch : transition_func_vec.at(2)) { // new symbols to write
    if (tape_symbols_set_.find(ch) == tape_symbols_set_.end())
      return false;
  }

  for (const char &ch : transition_func_vec.at(3)) {
    if (ch != 'r' and ch != 'l')
      return false;
  }

  if (state_set_.find(transition_func_vec.at(4)) == state_set_.end()) // the next state
    return false;

  return true;
}
