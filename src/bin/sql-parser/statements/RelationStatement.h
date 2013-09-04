// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_RELATIONSTATEMENT_H
#define SRC_BIN_SQL_PARSER_RELATIONSTATEMENT_H

#include "../Statement.h"

class RelationStatement : public Statement {
public:
  virtual std::string toString() const = 0;
};

#endif // SRC_BIN_SQL_PARSER_RELATIONSTATEMENT_H

