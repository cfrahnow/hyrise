// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_UNIMPLEMENTEDEXPRESSION_H
#define SRC_BIN_SQL_PARSER_UNIMPLEMENTEDEXPRESSION_H

#include "../Expression.h"

class UnimplementedExpression : public Expression {
 public:
  UnimplementedExpression() {
    throw std::runtime_error("Expression is unimplemented");
  }

  std::string toString() const {
    return "<unimplemented>";
  }
};

#endif // SRC_BIN_SQL_PARSER_UNIMPLEMENTEDEXPRESSION_H

