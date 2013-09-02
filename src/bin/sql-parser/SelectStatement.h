// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_SELECTSTATEMENT_H
#define SRC_BIN_SQL_PARSER_SELECTSTATEMENT_H

#include "Statement.h"

class SelectStatement : public Statement {

public:
  static statement_ptr_t parse(std::string query);
};

#endif // SRC_BIN_SQL_PARSER_SELECTSTATEMENT_H

