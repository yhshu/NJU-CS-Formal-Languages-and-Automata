//
// Created by yhshu on 12/6/20.
//

#include "Tape.h"

#include <sstream>

Tape::Tape(int id, char blank) {
  this->id_ = id;
  this->blank_ = blank;
  this->head_ = 0;
  this->tape_.insert(make_pair(0, blank_));
}

Tape::Tape(int id, const string &input, char blank) {
  this->id_ = id;
  this->blank_ = blank;
  this->head_ = 0;
  int i = 0;
  for (const char &ch: input) {
    this->tape_.insert(make_pair(i++, ch));
  }
}

string Tape::to_string() {
  cleanBothEnds(); // clean the blank symbols at both ends

  stringstream index_ss;
  stringstream tape_ss;
  stringstream head_ss;

  // key set
  index_ss << "Index" << id_ << " :";
  int head_pos = 0;
  int cnt = 0;
  for (auto &it : tape_) {
    index_ss << " " << it.first;
    if (it.first == head_)
      head_pos = cnt;
    cnt++;
  }

  // value set
  tape_ss << "Tape" << id_ << "  :";
  for (auto &it: tape_) {
    tape_ss << " " << it.second;
  }

  // head
  head_ss << "Head" << id_ << "  : ";
  for (int i = 0; i < head_pos; i++) {
    head_ss << "  ";
  }
  head_ss << "^" << endl;

  return index_ss.str() + "\n" + tape_ss.str() + "\n" + head_ss.str();
}

void Tape::cleanBothEnds() {
  // the left end
  for (auto it = tape_.begin(); it != tape_.end();) {
    if (it->second != blank_ or head_ == it->first)
      break;
    it = tape_.erase(it);
  }

  // the right end
  auto it = tape_.end();
  it--;
  while (it != tape_.begin()) {
    if (it->second != blank_ or head_ == it->first)
      break;
    it = tape_.erase(it);
  }
}
