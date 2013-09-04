// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_STATEMENT_H
#define SRC_BIN_SQL_PARSER_STATEMENT_H

#include <string>
#include <map>
#include <memory>

class Statement;
typedef std::shared_ptr<Statement> statement_ptr_t;
typedef std::vector<statement_ptr_t> statement_list_t;

class Statement {
public:
  virtual std::string toString() const = 0;

public:
  static statement_ptr_t parse(const std::string& query);
  static statement_list_t getStatements(const std::string& query);

  template <typename T>
  static bool registerKeyword(const std::string& keyword, bool exceptionIfExists = true) {
    if (keywordMap().find(keyword) != keywordMap().end()) {
      if (exceptionIfExists)
        throw std::runtime_error("keyword \"" + keyword + "\" has already been registered");
      return false;
    }

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

  struct sql_keyword_less {
    bool operator()(std::string x, std::string y) const {
      std::transform(x.begin(), x.end(), x.begin(), ::tolower);
      std::transform(y.begin(), y.end(), y.begin(), ::tolower);
      return x < y;
    }
    typedef std::string first_argument_type;
    typedef std::string second_argument_type;
    typedef bool result_type;
  };

  typedef std::map<std::string, AbstractStatementFactory*, sql_keyword_less> keywordMap_t;
  
  static keywordMap_t& keywordMap();
};

#endif // SRC_BIN_SQL_PARSER_STATEMENT_H

