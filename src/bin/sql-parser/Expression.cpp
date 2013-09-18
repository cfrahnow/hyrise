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

  std::cout << "Query: \"" << std::endl
            << "        " << query << std::endl
	    << "\"" << std::endl;
  boost::char_separator<char> sep(" ");
  boost::tokenizer<boost::char_separator<char>> tokens(query, sep);
  for (auto t : tokens) {
    std::cout << "\"" << t << "\"";
    auto keyword = keywordMap().find(t);
    if (keyword != keywordMap().end()) {
      auto e = (*keyword).second->create();
      std::cout << " (Keyword)";
    }
    else {
      auto e = ConstantExpression::parse(t);
      if (e != nullptr) {
        std::cout << " (" << e->toString() << ")";
      }
    }
    std::cout << std::endl;
  }

  return list;
}

Expression::keyword_map_t& Expression::keywordMap() {
  static keyword_map_t* const keywordMap = new keyword_map_t();
  return *keywordMap;
}

