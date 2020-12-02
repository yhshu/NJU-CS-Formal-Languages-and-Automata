//
// Created by Yiheng Shu on 2020/12/2.
//

#include <iostream>
#include "TuringMachine.h"
#include "utils.h"
#include "TransitionFunction.h"

TuringMachine::TuringMachine(const vector<string> &tm_str, bool &res) {
  for (string line: tm_str) {
    auto commentIndex = line.find(';');
    line = line.substr(0, commentIndex);
    line = trim(line);
    if (line.empty())  // empty line or comment
      continue;
    if (line.size() <= 6) {
      res = false;
      return;
    }

    if (line.find("#Q = ") == 0) { // 1. state set
      res = buildStateSet(line);
    } else if (line.find("#S = ") == 0) { // 2. input symbol set
      res = buildInputSymbolsSet(line);
    } else if (line.find("#G = ") == 0) { // 3. tape symbol set
      res = buildTapeSymbolsSet(line);
    } else if (line.find("#q0 = ") == 0) { // 4. init_state
      this->init_state_ = line.substr(6, line.size());
    } else if (line.find("#B = ") == 0) { // 5. blank symbol
      string blank_symbol = line.substr(6, line.size());
      if (blank_symbol.size() != 1) {
        syntaxError();
        return;
      }
      this->blank_symbol_ = blank_symbol[0];
    } else if (line.find("#F = ") == 0) { // 6. final state set
      buildFinalStateSet(line);
    } else if (line.find("#N = ") == 0) { // 7. the tape number
      this->num_tape = stoi(line.substr(6, line.size()));
    } else { // 8. transition functions
      auto transition_func_vec = split(line, " ");
      if (transition_func_vec.size() != 5) {
        res = false;
        return;
      }
      // check the transition definition
      
      TransitionFunction transition_function(, num_tape);
    }
  }

  res = checkDefinition(); // check the TM definition
}

bool TuringMachine::buildStateSet(const string &line) {
  // todo
}

bool TuringMachine::buildInputSymbolsSet(const string &line) {
  // todo
}
bool TuringMachine::buildTapeSymbolsSet(const string &line) {
  // todo
}
void TuringMachine::buildFinalStateSet(string line) {

}
bool TuringMachine::checkDefinition() {
  return false;
}
