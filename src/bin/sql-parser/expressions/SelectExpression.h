// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_SELECTEXPRESSION_H
#define SRC_BIN_SQL_PARSER_SELECTEXPRESSION_H

#include "RelationExpression.h"

class SelectExpression : public RelationExpression {
 public:
  std::string toString() const {
    return "select"
  }

 public:
};

namespace {
  const auto _ = Expression::registerKeyword<SelectExpression>("select");
}

#endif // SRC_BIN_SQL_PARSER_SELECTEXPRESSION_H

