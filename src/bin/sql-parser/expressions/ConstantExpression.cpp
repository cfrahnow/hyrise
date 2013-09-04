// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.

#include "ConstantExpression.h"
#include <iostream>

namespace {
  std::string strToLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    return str;
  }

  bool isHex(const std::string& str) {
    size_t current;
    if (str.size() > 2 && str[0] == '0' && str[1] == 'x')
      current = 2;
    else if (str.size() > 3 && (str[0] == '-' || str[0] == '+') && str[1] == '0' && str[2] == 'x')
      current = 3;
    else
      return false;

    for (; current < str.size(); ++current) {
      const char c = tolower(str[current]);
      if (!(isdigit(c) || (c >= 'a' && c<= 'f')))
        return false;
    }
    return true;
  }

  bool isDecimal(const std::string& str) {
    if (str.size() == 0)
      return false;
    
    size_t current = 0;
    if (str.size() > 1 && (str[0] == '-' || str[0] == '+'))
      current = 1;
    
    for (; current < str.size(); ++current) {
      if (!isdigit(str[current]))
        return false;
    }
    return true;
  }

  bool isReal(const std::string& str) {
    size_t current = 0;
    bool point = false, digit = false;
    if (str.size() > 1 && (str[0] == '-' || str[1] == '+'))
      current = 1;

    for (; current < str.size(); ++current) {
      const char c = tolower(str[current]);
      if (c == '.') {
        if (point)
	  return false;
	point = true;
	digit = false;
      }
      else if (c == 'e') {
        if (!digit || str[current-1] == '.')
	  return false;
        return isDecimal(str.substr(current + 1, str.size() - current));
      }
      else if (isdigit(c))
        digit = true;
      else
        return false;
    }
    return digit;
  }

  bool isString(const std::string& str) {
    char quoteChar;
    size_t current;
    if (str[0] == '\'' || str[0] == '\"')
      quoteChar = str[0];
    else return false;
    for (current = 1; current < str.size(); ++current) {
      if (str[current] == quoteChar)
        break;
    }
    return current == str.size() - 1;
  }

  bool isBool(const std::string& str) {
    const std::string strl = strToLower(str);
    return strl == "true" || strl == "false";
  }

  bool isNull(const std::string& str) {
    const std::string strl = strToLower(str);
    return strl == "null";
  }
} //namespace



expression_ptr_t ConstantExpression::parse(const std::string& query) {
  if (isHex(query)) {
    std::cout << " !HEX! ";
  }
  if (isDecimal(query)) {
    std::cout << " !DECIMAL! ";
  }
  if (isReal(query)) {
    std::cout << " !REAL! ";
  }
  if (isString(query)) {
    std::cout << " !STRING! ";
  }
  if (isNull(query)) {
    std::cout << " !NULL! "; 
  }
  if (isBool(query)) {
    std::cout << " !BOOL! "; 
  }
  return expression_ptr_t(nullptr);
}

