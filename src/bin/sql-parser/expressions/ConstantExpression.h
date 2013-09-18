// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_CONSTANTEXPRESSION_H
#define SRC_BIN_SQL_PARSER_CONSTANTEXPRESSION_H

#include "ValueExpression.h"

class ConstantExpression : public virtual ValueExpression {
 public:
  std::string toString() const = 0;
  virtual unsigned priority() const {
    return 100;
  }

 public:
  static expression_ptr_t parse(const std::string& query);
};

#endif // SRC_BIN_SQL_PARSER_CONSTANTEXPRESSION_H

