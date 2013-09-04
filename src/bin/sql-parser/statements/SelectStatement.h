// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_SELECTSTATEMENT_H
#define SRC_BIN_SQL_PARSER_SELECTSTATEMENT_H

#include "RelationStatement.h"

class SelectStatement : public RelationStatement {
 public:
  std::string toString() const {
    return "select"
  }

 public:
  static statement_ptr_t SelectStatement::parse(const std::string query) {
    statement_ptr_t ret = std::make_shared<SelectStatement>();
    return ret;
  }
};

namespace {
  const auto _ = Statement::registerKeyword<SelectStatement>("select");
}

#endif // SRC_BIN_SQL_PARSER_SELECTSTATEMENT_H

