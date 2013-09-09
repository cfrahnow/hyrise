// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_LEQOPERATOR_H
#define SRC_BIN_SQL_PARSER_LEQOPERATOR_H

#include "../../Operator.h"
#include <memory>
#include "../ValueExpression.h"

template <class T1, class T2>
class LeqOperator : public virtual Operator {
 public:
  virtual std::string toString() const {
    return "<=";
  }
 protected:
  std::shared_ptr<T1> _expr1;
  std::shared_ptr<T2> _expr2;
};

#endif // SRC_BIN_SQL_PARSER_LEQOPERATOR_H

