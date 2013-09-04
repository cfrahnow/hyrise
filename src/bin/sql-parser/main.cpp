// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include <iostream>

#include <sstream>
#include <string>

#include "Statement.h"

namespace {
  std::string argsToStr(const int argc, char** const args) {
    std::stringstream buf;
    const size_t numberOfArgs = static_cast<size_t>(argc);
    for (size_t i = 1; i < numberOfArgs; ++i)
      buf << args[i] << " ";
    return buf.str();
  }

  void removeWhitespaces(std::string& str) {
    bool lastOneSpace = false;
    bool inQuote = false;

    for (size_t i = 0; i < str.size(); ++i) {
     //replace \n by spaces
      if (str.at(i) == '\n')
        str.replace(i, 1, " ");
      
      if (str.at(i) == '"')
        inQuote = !inQuote;

      //remove multiple spaces
      if (!inQuote && str.at(i) == ' ') {
        if (lastOneSpace)
	  str.erase(i--, 1);
	else
	  lastOneSpace = true;
	continue;
      }

      //obviously some other character
      lastOneSpace = false;
    }
  }

} // namespace

int main (int argc, char** args) {
  std::string query = argsToStr(argc, args);
  removeWhitespaces(query);
  Statement::parse(query);
}

