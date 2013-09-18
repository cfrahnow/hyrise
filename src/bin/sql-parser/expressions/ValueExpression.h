// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_VALUEEXPRESSION_H
#define SRC_BIN_SQL_PARSER_VALUEEXPRESSION_H

#include "../Expression.h"

class ValueExpression : public virtual Expression {
 public:
  virtual bool evaluable() const = 0;
};

#endif // SRC_BIN_SQL_PARSER_VALUEEXPRESSION_H

