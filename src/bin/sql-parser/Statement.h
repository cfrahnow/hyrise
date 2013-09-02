// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_STATEMENT_H
#define SRC_BIN_SQL_PARSER_STATEMENT_H

#include <string>
#include <map>
#include <memory>

class Statement;
typedef std::shared_ptr<Statement> statement_ptr_t;

class Statement {

public:
  static statement_ptr_t parse(std::string query);

  template <typename T>
  static bool registerKeyword(std::string keyword) {
    if (keywordMap().find(keyword) != keywordMap().end())
      return false;

    keywordMap()[keyword] = new StatementFactory<T>();
    return true;
  }

private:
  struct AbstractStatementFactory {
    virtual statement_ptr_t parse(std::string query) = 0;
  };

  template <typename T>
  struct StatementFactory : public AbstractStatementFactory{
    virtual statement_ptr_t parse(const std::string query) {
      return T::parse(query);
    }
  };

  typedef std::map<std::string, AbstractStatementFactory*> keywordMap_t;
  
  static keywordMap_t& keywordMap();
};

#endif // SRC_BIN_SQL_PARSER_STATEMENT_H

