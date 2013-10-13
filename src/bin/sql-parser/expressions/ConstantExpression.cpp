// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.

#include "ConstantExpression.h"
#include <sstream>
#include <iostream>

#include "NumericExpression.h"
#include "BoolExpression.h"
#include "StringExpression.h"
#include "NullExpression.h"

namespace {
  enum BaseType {Dec, Hex};

  template <typename T, BaseType base = Dec>
  T readFromStr(const std::string& str) {
    std::stringstream s;
    switch (base) {
      case Dec: s << std::dec; break;
      case Hex: s << std::hex; break;
    }
    s << str;
    T t;
    s >> t;
    return t;
  }
  
  std::string strToLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    return str;
  }

  bool strToBool(const std::string& str) {
    const std::string strl = strToLower(str);
    if (str == "true") return true;
    else if (str == "false") return false;
    throw std::runtime_error("\"" + str + "\" is neither true or false");
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
    if (str.at(0) == '\'' || str.at(0) == '\"')
      quoteChar = str.at(0);
    else return false;
    for (current = 1; current < str.size(); ++current) {
      if (str.at(current) == quoteChar && str.at(current-1) != '\\')
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
  std::stringstream s;
  if (isHex(query)) {
    s << std::hex << query;
    int i;
    s >> i;
    return std::make_shared<ConstantIntExpression>(readFromStr<int>(query));
  }
  if (isDecimal(query)) {
    s << query;
    int i;
    s >> i;
    return std::make_shared<ConstantIntExpression>(readFromStr<int>(query));
  }
  if (isReal(query)) {
    s << query;
    float f;
    s >> f;
    return std::make_shared<ConstantFloatExpression>(f);
  }
  if (isString(query)) {
    return std::make_shared<ConstantStringExpression>(query.substr(1, query.size() - 2));
  }
  if (isNull(query)) {
    return std::make_shared<NullExpression>();
  }
  if (isBool(query)) {
    return std::make_shared<ConstantBoolExpression>(strToBool(query));
  }
  return expression_ptr_t(nullptr);
}

