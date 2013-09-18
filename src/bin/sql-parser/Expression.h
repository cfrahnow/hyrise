// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_EXPRESSION_H
#define SRC_BIN_SQL_PARSER_EXPRESSION_H

#include <string>
#include <map>
#include <memory>

class Expression;
typedef std::shared_ptr<Expression> expression_ptr_t;
typedef std::vector<expression_ptr_t> expression_list_t;

class Expression {
 public:
  virtual std::string toString() const = 0;
  virtual unsigned priority() const = 0;

 public:
  static expression_ptr_t parse(const std::string& query);
  static expression_list_t getExpressions(const std::string& query);

  template <typename T>
  static bool registerKeyword(const std::string& keyword, bool exceptionIfExists = true) {
    if (keywordMap().find(keyword) != keywordMap().end()) {
      if (exceptionIfExists)
        throw std::runtime_error("keyword \"" + keyword + "\" has already been registered");
      return false;
    }
    keywordMap()[keyword] = new ExpressionFactory<T>();
    return true;
  }

 private:
  struct AbstractExpressionFactory {
    virtual expression_ptr_t create() = 0;
  };

  template <typename T>
  struct ExpressionFactory : public AbstractExpressionFactory{
    virtual expression_ptr_t create() {
      return std::make_shared<T>();
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

  typedef std::map<std::string, AbstractExpressionFactory*, sql_keyword_less> keyword_map_t;
  
  static keyword_map_t& keywordMap();
};

#endif // SRC_BIN_SQL_PARSER_EXPRESSION_H

