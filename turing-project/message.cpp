//
// Created by Yiheng Shu on 2020/12/3.
//

#include "message.h"
#include "utils.h"

void PrintErr() {
  if (GetVerbose())
    cerr << "==================== ERR ====================" << endl;
}
void PrintEnd() {
  if (GetVerbose())
    cerr << "==================== END ====================" << endl;
}
void PrintRun() {
  if (GetVerbose())
    cerr << "==================== RUN ====================" << endl;
}
void PrintDivider() {
  if (GetVerbose())
    cerr << "---------------------------------------------" << endl;
}
void PrintInput(const string &input) {
  if (GetVerbose())
    cerr << "Input: " << input << endl;
}