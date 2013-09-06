// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_OPERATOR_H
#define SRC_BIN_SQL_PARSER_OPERATOR_H

#include "Expression.h"

class Operator : public Expression {
 public:
  virtual std::string toString() const = 0;

 public:
  static expression_ptr_t parse(const std::string& query);
  static expression_list_t getExpressions(const std::string& query);

  template <typename T>
  static bool registerOperator(const std::string& op, bool exceptionIfExists = true) {
    if (operatorSet().find(op) != operatorSet().end()) {
      if (exceptionIfExists)
        throw std::runtime_error("operator \"" + op + "\" has already been registered");
      return false;
    }
    operatorSet().insert(op);
    registerKeyword<T>(op);
    return true;
  }

 private:
  struct sql_operator_less {
    bool operator()(const std::string& x, const std::string& y) const {
      if (x.size() != y.size())
        return x.size() < y.size();
      return x < y;
    }
    typedef std::string first_argument_type;
    typedef std::string second_argument_type;
    typedef bool result_type;
  };

  typedef std::set<std::string, sql_operator_less> operator_set_t;
  
  static operator_set_t& operatorSet();
};

#endif // SRC_BIN_SQL_PARSER_OPERATOR_H

