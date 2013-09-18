// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_SELECTEXPRESSION_H
#define SRC_BIN_SQL_PARSER_SELECTEXPRESSION_H

#include "RelationExpression.h"

class SelectExpression : public RelationExpression {
 public:
  virtual std::string toString() const {
    return "select";
  }

  virtual bool evaluable() const {
    return false;
  }
  virtual unsigned priority() const {
    return 100;
  }

};

#endif // SRC_BIN_SQL_PARSER_SELECTEXPRESSION_H

