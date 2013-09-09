// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_INTEXPRESSION_H
#define SRC_BIN_SQL_PARSER_INTEXPRESSION_H

#include "ConstantExpression.h"
#include <sstream>

class IntExpression : public virtual ValueExpression {
 public:
   virtual std::string toString() const = 0;
};

class ConstantIntExpression : public IntExpression, public ConstantExpression {
 public:
  ConstantIntExpression(const int value) : _value(value) {}
  virtual std::string toString() const {
    std::stringstream s;
    s << _value;
    return s.str();
  }
  virtual bool evaluable() const {
    return true;
  }
  int value() const {
    return _value;
  }
 
 protected:
  const int _value;
};

#endif // SRC_BIN_SQL_PARSER_INTEXPRESSION_H

