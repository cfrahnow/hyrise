// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_STRINGEXPRESSION_H
#define SRC_BIN_SQL_PARSER_STRINGEXPRESSION_H

#include "ConstantExpression.h"

class StringExpression : public virtual ValueExpression {
 public:
   virtual std::string toString() const = 0;
};

class ConstantStringExpression : public StringExpression, public ConstantExpression {
 public:
  ConstantStringExpression(const std::string value) : _value(value) {}
  virtual std::string toString() const {
    return value();
  }
  virtual bool evaluable() const {
    return true;
  }
  std::string value() const {
    return _value;
  }
 
 protected:
  const std::string _value;
};

#endif // SRC_BIN_SQL_PARSER_STRINGEXPRESSION_H

