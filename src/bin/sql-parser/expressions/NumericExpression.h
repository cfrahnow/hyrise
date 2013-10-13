// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_BIN_SQL_PARSER_NUMERICEXPRESSION_H
#define SRC_BIN_SQL_PARSER_NUMERICEXPRESSION_H

#include "ConstantExpression.h"
#include <sstream>

class NumericExpression : public virtual ValueExpression {
 public:
   virtual std::string toString() const = 0;

   virtual bool isFloat() const = 0;
   virtual bool isInt() const = 0;

   virtual float floatValue() const = 0;
   virtual int intValue() const = 0;
};

class ConstantIntExpression : public NumericExpression, public ConstantExpression {
 public:
  ConstantIntExpression(const int value) : _value(value) {}
  virtual std::string toString() const {
    std::stringstream s;
    s << _value;
    return s.str();
  }
  virtual bool evaluable() const {
    return true;
  }
  virtual unsigned priority() const {
    return ConstantExpression::priority();
  }

  virtual bool isFloat() const {
    return false;
  }
  virtual bool isInt() const {
    return true;
  }

  virtual int intValue() const {
    return _value;
  }
  virtual float floatValue() const {
    return static_cast<float>(_value);
  }
 
 protected:
  const int _value;
};

class ConstantFloatExpression : public NumericExpression, public ConstantExpression {
 public:
  ConstantFloatExpression(const float value) : _value(value) {}
  virtual std::string toString() const {
    std::stringstream s;
    s << _value;
    return s.str();
  }
  virtual bool evaluable() const {
    return true;
  }
  virtual unsigned priority() const {
    return ConstantExpression::priority();
  }

  virtual bool isFloat() const {
    return true;
  }
  virtual bool isInt() const {
    return false;
  }

  virtual int intValue() const {
    throw std::runtime_error("one does not simply get the int value of a float");
  }
  virtual float floatValue() const {
    return _value; 
  }
 
 protected:
  const float _value;
};

#endif // SRC_BIN_SQL_PARSER_NUMERICEXPRESSION_H

