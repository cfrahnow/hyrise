// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include <iostream>

#include <sstream>
#include <string>

#include "Expression.h"

namespace {
  std::string argsToStr(const int argc, char** const args) {
    if (argc == 1)
      return "";

    std::stringstream buf;
    const size_t numberOfArgs = static_cast<size_t>(argc);
    buf << args[1];
    for (size_t i = 2; i < numberOfArgs; ++i)
      buf << ' ' << args[i];
    return buf.str();
  }

  std::string removeWhitespaces(const std::string& str) {
    char quoteChar = 0;
    char lastChar = 0;

    std::stringstream buf;

    for (size_t i = 0; i < str.size(); ++i) {
      const char& c = str.at(i);
      if (lastChar == '\\') { // this char is escaped
        buf << c;
      }
      else if (c == '\\') { // escape sequence starting
        if (quoteChar != 0)
	  buf << c;
      }
      else if (c == quoteChar) { // quote ending
        buf << c;
        quoteChar = 0;
      }
      else if (quoteChar == 0 && (c == '\"' || c == '\'')) {
        buf << c;
	quoteChar = c;
      }
      else if (isspace(c)) {
        if (quoteChar != 0) {
	  if (c == ' ')
            buf << c;
	  else
	    continue;
	}
	else if (lastChar != ' ') {
          buf << ' ';
	  lastChar = ' ';
	  continue;
	}
      }
      else
        buf << c;

      lastChar = c;
    }

    if (quoteChar != 0)
      throw std::runtime_error("no corresponding ending to opened quote char");

    return buf.str();
  }
} // namespace

int main (int argc, char** args) {
  std::string query = argsToStr(argc, args);
  query = removeWhitespaces(query);
  Expression::parse(query);
}

