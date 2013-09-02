// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.

#include "SelectStatement.h"

namespace {
  const auto _ = Statement::registerKeyword<SelectStatement>("select");
}


statement_ptr_t SelectStatement::parse(const std::string query) {
  statement_ptr_t ret = std::make_shared<SelectStatement>();
  return ret;
}

