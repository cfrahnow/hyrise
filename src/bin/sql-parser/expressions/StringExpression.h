// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_STRINGEXPRESSION_H
#define SRC_BIN_SQL_PARSER_STRINGEXPRESSION_H

#include <boost/algorithm/string.hpp>

#include "ConstantExpression.h"

class StringExpression : public virtual ValueExpression {
 public:
   virtual std::string toString() const = 0;
};

class ConstantStringExpression : public StringExpression, public ConstantExpression {
 public:
  ConstantStringExpression(const std::string& value) : _value(value) {}
  virtual std::string toString() const {
    return value();
  }
  virtual bool evaluable() const {
    return true;
  }
  virtual unsigned priority() const {
    return ConstantExpression::priority();
  }

  std::string value() const {
    return _value;
  }
 
 private:
  std::string removeEscapes(const std::string& str) {
    std::string ret(str);
    boost::replace_all(ret, "\\", "");
    return ret;
  }

 protected:
  const std::string _value;
};

#endif // SRC_BIN_SQL_PARSER_STRINGEXPRESSION_H

