// Copyright (c) 2012 Hasso-Plattner-Institut fuer Softwaresystemtechnik GmbH. All rights reserved.
#include "RadixJoin.h"
#include "QueryParser.h"
#include "access/BasicParser.h"

bool RadixJoin::is_registered = QueryParser::registerPlanOperation<RadixJoin>();

std::shared_ptr<_PlanOperation> RadixJoin::parse(Json::Value &data) {
    auto instance = BasicParser<RadixJoin>::parse(data);
  instance->setBits1(data["bits1"].asUInt());
  instance->setBits2(data["bits2"].asUInt());
  return instance;
}

void RadixJoin::executePlanOperation() {
}