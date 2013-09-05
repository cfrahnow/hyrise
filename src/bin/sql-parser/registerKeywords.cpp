#include "Expression.h"
#include "expressions/UnimplementedExpression.h"
#include "expressions/SelectExpression.h"

namespace {
  const auto select = Expression::registerKeyword<SelectExpression>("select");
  const auto _1 = Expression::registerKeyword<UnimplementedExpression>("from");
  const auto _2 = Expression::registerKeyword<UnimplementedExpression>("where");
  const auto _3 = Expression::registerKeyword<UnimplementedExpression>("limit");
  const auto _4 = Expression::registerKeyword<UnimplementedExpression>("offset");
  const auto _5 = Expression::registerKeyword<UnimplementedExpression>("having");
  const auto _6 = Expression::registerKeyword<UnimplementedExpression>("group");
  const auto _7 = Expression::registerKeyword<UnimplementedExpression>("by");

  const auto _8 = Expression::registerKeyword<UnimplementedExpression>("update");
  const auto _9 = Expression::registerKeyword<UnimplementedExpression>("set");

  const auto _10 = Expression::registerKeyword<UnimplementedExpression>("insert");
  const auto _11 = Expression::registerKeyword<UnimplementedExpression>("into");
  const auto _12 = Expression::registerKeyword<UnimplementedExpression>("values");

  const auto _order = Expression::registerKeyword<UnimplementedExpression>("order");
  const auto _asc = Expression::registerKeyword<UnimplementedExpression>("asc");
  const auto _desc = Expression::registerKeyword<UnimplementedExpression>("desc");

  const auto _between = Expression::registerKeyword<UnimplementedExpression>("between");

  const auto _and = Expression::registerKeyword<UnimplementedExpression>("and");
  const auto _or = Expression::registerKeyword<UnimplementedExpression>("or");

  const auto _union = Expression::registerKeyword<UnimplementedExpression>("union");
  
  const auto _avg = Expression::registerKeyword<UnimplementedExpression>("avg");
  const auto _min = Expression::registerKeyword<UnimplementedExpression>("min");
  const auto _max = Expression::registerKeyword<UnimplementedExpression>("max");
  const auto _count = Expression::registerKeyword<UnimplementedExpression>("count");
}

