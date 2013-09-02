// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_STATEMENT_H
#define SRC_BIN_SQL_PARSER_STATEMENT_H

#include <string>
#include <memory>

class Statement;
typedef std::shared_ptr<Statement> statement_ptr_t;

class Statement {

public:
  static statement_ptr_t parse(std::string query);
};

#endif // SRC_BIN_SQL_PARSER_STATEMENT_H

