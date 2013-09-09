// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_FLOATEXPRESSION_H
#define SRC_BIN_SQL_PARSER_FLOATEXPRESSION_H

#include "ConstantExpression.h"
#include <sstream>

class FloatExpression : public virtual ValueExpression {
 public:
   virtual std::string toString() const = 0;
};

class ConstantFloatExpression : public FloatExpression, public ConstantExpression {
 public:
  ConstantFloatExpression(const float value) : _value(value) {}
  virtual std::string toString() const {
    std::stringstream s;
    s << _value;
    return s.str();
  }
  virtual bool evaluable() const {
    return true;
  }
  float value() const {
    return _value;
  }
 
 protected:
  const float _value;
};

#endif // SRC_BIN_SQL_PARSER_FLOATEXPRESSION_H

