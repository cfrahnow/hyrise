// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_NULLEXPRESSION_H
#define SRC_BIN_SQL_PARSER_NULLEXPRESSION_H

#include "ConstantExpression.h"

class NullExpression : public virtual ValueExpression, public ConstantExpression {
 public:
   virtual std::string toString() const {
     return "null";
   }
   virtual bool evaluable() const {
     return true;
   }
  virtual unsigned priority() const {
    return ConstantExpression::priority();
  }
};

#endif // SRC_BIN_SQL_PARSER_NULLEXPRESSION_H

