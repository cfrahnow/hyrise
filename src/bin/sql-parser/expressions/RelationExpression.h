// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_RELATIONEXPRESSION_H
#define SRC_BIN_SQL_PARSER_RELATIONEXPRESSION_H

#include "ValueExpression.h"

class RelationExpression : public ValueExpression {
public:
  virtual std::string toString() const = 0;
};

#endif // SRC_BIN_SQL_PARSER_RELATIONEXPRESSION_H

