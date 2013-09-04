// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include "Statement.h"

#include <iostream>
#include <boost/tokenizer.hpp>

#include "statements/ConstantStatement.h"

statement_ptr_t Statement::parse(const std::string& query) {
  auto statements = getStatements(query);

  return statement_ptr_t(nullptr);
}

statement_list_t Statement::getStatements(const std::string& query) {
  statement_list_t list;

  boost::char_separator<char> sep(" ");
  boost::tokenizer<boost::char_separator<char>> tokens(query, sep);
  for (auto t : tokens) {
    std::cout << "\"" << t << "\"";
    if (keywordMap().find(t) != keywordMap().end())
      std::cout << " (Keyword)";
    else {
      ConstantStatement::parse(t);
    }
    std::cout << std::endl;
  }

  return list;
}

Statement::keywordMap_t& Statement::keywordMap() {
  static keywordMap_t* const keywordMap = new keywordMap_t();
  return *keywordMap;
}

