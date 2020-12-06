//
// Created by yhshu on 12/6/20.
//

#ifndef NJU_CS_FLA_FALL_2020_PROJECT_TURING_PROJECT_TAPE_H_
#define NJU_CS_FLA_FALL_2020_PROJECT_TURING_PROJECT_TAPE_H_

#include <map>

using namespace std;

class Tape {
 private:
  int id_;
  long long  head_;
  map<long long, char> tape_;
  char blank_;

 public:
  Tape(int id, const string &input, char blank);

  Tape(int id, char blank);

  string to_string();
  void cleanBothEnds();
};

#endif //NJU_CS_FLA_FALL_2020_PROJECT_TURING_PROJECT_TAPE_H_
