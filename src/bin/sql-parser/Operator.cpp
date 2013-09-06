// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include "Operator.h"

Operator::operator_set_t& Operator::operatorSet() {
  static operator_set_t* const operatorSet = new operator_set_t();
  return *operatorSet;
}

