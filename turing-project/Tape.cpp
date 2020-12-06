//
// Created by Yiheng Shu on 2020/12/6.
//

#include "Tape.h"
#include "utils.h"

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

string Tape::to_string(int num_tape) {
  CleanBothEnds(); // clean the blank symbols at both ends

  stringstream index_ss;
  stringstream tape_ss;
  stringstream head_ss;
  map<long long, int> pos_map;

  // index
  index_ss << "Index" << id_ << Space(NumLen(num_tape - 1) - NumLen(id_)) << " :";
  int head_pos = 0;
  int pos = 0;
  for (auto &it : tape_) {
    auto index = abs(it.first);
    index_ss << " " << index;
    pos_map.insert(make_pair(index, pos));
    if (it.first == head_) {
      head_pos = pos;
    }
    pos += (NumLen(index) + 1);
  }

  // tape symbol
  tape_ss << "Tape" << id_ << Space(NumLen(num_tape - 1) - NumLen(id_)) << "  : ";
  vector<char> tape_str(pos_map.rbegin()->second + 1, ' ');
  for (auto &it : pos_map) {
    tape_str.at(it.second) = tape_.at(it.first);
  }
  for (auto &ch : tape_str) {
    tape_ss << ch;
  }

  // head
  head_ss << "Head" << id_ << Space(NumLen(num_tape - 1) - NumLen(id_)) << "  : " << Space(head_pos) << "^";

  return index_ss.str() + "\n" + tape_ss.str() + "\n" + head_ss.str() + "\n";
}

void Tape::CleanBothEnds() {
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

char Tape::GetCurSymbol() {
  if (tape_.find(head_) == tape_.end())
    return blank_;
  return tape_.at(head_);
}

void Tape::SetCurSymbol(char ch) {
  if (tape_.find(head_) == tape_.end())
    tape_.insert(make_pair(head_, ch));
  else tape_.at(head_) = ch;
}

void Tape::MoveTheHead(char ch) {
  if (ch == 'l') {
    head_--;
  } else if (ch == 'r') {
    head_++;
  }
}
