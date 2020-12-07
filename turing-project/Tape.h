//
// Created by Yiheng Shu on 2020/12/6.
//

#ifndef NJU_CS_FLA_FALL_2020_PROJECT_TURING_PROJECT_TAPE_H_
#define NJU_CS_FLA_FALL_2020_PROJECT_TURING_PROJECT_TAPE_H_

#include <map>

using namespace std;

class Tape {
 private:
  /**
   * The tape id
   */
  int id_;

  /**
   * The head position
   */
  long long head_;

  /**
   * The tape content
   */
  map<long long, char> tape_;

  /**
   * The blank symbol for this tape
   */
  char blank_;

 public:
  /**
   * The constructor for the 1st tape
   * @param id the tape id
   * @param input the TM input string
   * @param blank the blank symbol
   */
  Tape(int id, const string &input, char blank);

  /**
   * The constructor for tapes that are not the 1st
   * @param id the tape id
   * @param blank the blank symbol
   */
  Tape(int id, char blank);

  /**
   * Get the verbose string for the tape, used for debugging
   * @param num_tape the number of tapes
   * @return the verbose string
   */
  string GetVerboseStr(int num_tape);

  /**
   * Get the string on the tape
   * @return string on the tape
   */
  string GetString();

  void CleanBothEnds();

  char GetCurSymbol();

  void SetCurSymbol(char ch);

  void MoveTheHead(char ch);
};

#endif //NJU_CS_FLA_FALL_2020_PROJECT_TURING_PROJECT_TAPE_H_
