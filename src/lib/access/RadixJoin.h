// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#ifndef SRC_LIB_ACCESS_RADIXJOIN_H_
#define SRC_LIB_ACCESS_RADIXJOIN_H_

#include "PlanOperation.h"

class RadixJoin : public _PlanOperation {
 private:
    uint32_t _bits1;
    uint32_t _bits2;
 public:

  RadixJoin() {
    
  }

  virtual ~RadixJoin() {
  }

  void executePlanOperation();

  static std::shared_ptr<_PlanOperation> parse(Json::Value &data);
  static bool is_registered;
  static std::string name() {
    return "RadixJoin";
  }
  const std::string vname() {
    return "RadixJoin";
  }


  inline void setBits2(uint32_t b) {
    _bits2 = b;
  }

  inline uint32_t bits2() { 
    return _bits2;
  }

    inline void setBits1(uint32_t b) {
    _bits1 = b;
  }

  inline uint32_t bits1() { 
    return _bits1;
  }
};

#endif  // SRC_LIB_ACCESS_RADIXJOIN_H_