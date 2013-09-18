// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_UNIMPLEMENTEDEXPRESSION_H
#define SRC_BIN_SQL_PARSER_UNIMPLEMENTEDEXPRESSION_H

#include "../Expression.h"
#include "../Operator.h"

class UnimplementedExpression : public virtual Expression {
 public:
  UnimplementedExpression() {
    //throw std::runtime_error("Expression is unimplemented");
  }

  std::string toString() const {
    return "<unimplemented>";
  }
  virtual unsigned priority() const {
    return 0;
  }
};

class UnimplementedOperator : public Operator, public UnimplementedExpression {
 public:
  std::string toString() const {
    return "<unimplementedOperator>";
  }
  virtual unsigned priority() const {
    return UnimplementedOperator::priority();
  }
};

#endif // SRC_BIN_SQL_PARSER_UNIMPLEMENTEDEXPRESSION_H

