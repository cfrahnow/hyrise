// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.

#include "Statement.h"

statement_ptr_t Statement::parse(const std::string query) {
  statement_ptr_t ret= std::make_shared<Statement>();
  return ret;
}

Statement::keywordMap_t& Statement::keywordMap() {
  static keywordMap_t* const keywordMap = new keywordMap_t();
  return *keywordMap;
}

