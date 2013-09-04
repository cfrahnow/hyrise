// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_BOOLEXPRESSION_H
#define SRC_BIN_SQL_PARSER_BOOLEXPRESSION_H

#include "../ConstantExpression.h"

class BoolExpression : public ValueExpression {
 public:
   virtual std::string toString() const = 0;
};

class ConstantBoolExpression : public BoolExpression, public ConstantExpression {
 public:
  ConstantBoolExpression(const bool value) : _value(value) {}
 
 protected:
  _value;
};

#endif // SRC_BIN_SQL_PARSER_BOOLEXPRESSION_H

