// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include "Expression.h"

#include <iostream>
#include <boost/tokenizer.hpp>

#include "expressions/ConstantExpression.h"

expression_ptr_t Expression::parse(const std::string& query) {
  auto expression = getExpressions(query);

  return expression_ptr_t(nullptr);
}

expression_list_t Expression::getExpressions(const std::string& query) {
  expression_list_t list;

  boost::char_separator<char> sep(" ");
  boost::tokenizer<boost::char_separator<char>> tokens(query, sep);
  for (auto t : tokens) {
    std::cout << "\"" << t << "\"";
    if (keywordMap().find(t) != keywordMap().end()) {
      std::cout << " (Keyword)";
    }
    else {
      ConstantExpression::parse(t);
    }
    std::cout << std::endl;
  }

  return list;
}

Expression::keyword_map_t& Expression::keywordMap() {
  static keyword_map_t* const keywordMap = new keyword_map_t();
  return *keywordMap;
}

