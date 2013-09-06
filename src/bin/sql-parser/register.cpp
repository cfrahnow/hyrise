#include "Expression.h"
#include "Operator.h"
#include "expressions/UnimplementedExpression.h"
#include "expressions/SelectExpression.h"

namespace { //sql keywords
  const auto select =   Expression::registerKeyword<SelectExpression>("select");
  const auto _from =    Expression::registerKeyword<UnimplementedExpression>("from");
  const auto _where =   Expression::registerKeyword<UnimplementedExpression>("where");
  const auto _limit =   Expression::registerKeyword<UnimplementedExpression>("limit");
  const auto _offset =  Expression::registerKeyword<UnimplementedExpression>("offset");
  const auto _having =  Expression::registerKeyword<UnimplementedExpression>("having");
  const auto _group =   Expression::registerKeyword<UnimplementedExpression>("group");
  const auto _by =      Expression::registerKeyword<UnimplementedExpression>("by");

  const auto _update =  Expression::registerKeyword<UnimplementedExpression>("update");
  const auto _set =     Expression::registerKeyword<UnimplementedExpression>("set");

  const auto _insert =  Expression::registerKeyword<UnimplementedExpression>("insert");
  const auto _into =    Expression::registerKeyword<UnimplementedExpression>("into");
  const auto _values =  Expression::registerKeyword<UnimplementedExpression>("values");

  const auto _order =   Expression::registerKeyword<UnimplementedExpression>("order");
  const auto _asc =     Expression::registerKeyword<UnimplementedExpression>("asc");
  const auto _desc =    Expression::registerKeyword<UnimplementedExpression>("desc");

  const auto _between = Expression::registerKeyword<UnimplementedExpression>("between");

  const auto _and =     Expression::registerKeyword<UnimplementedExpression>("and");
  const auto _or =      Expression::registerKeyword<UnimplementedExpression>("or");

  const auto _union =   Expression::registerKeyword<UnimplementedExpression>("union");
  
  const auto _avg =     Expression::registerKeyword<UnimplementedExpression>("avg");
  const auto _min =     Expression::registerKeyword<UnimplementedExpression>("min");
  const auto _max =     Expression::registerKeyword<UnimplementedExpression>("max");
  const auto _count =   Expression::registerKeyword<UnimplementedExpression>("count");
} // namespace

namespace { //sql operators
  const auto _brackedo = Operator::registerOperator<UnimplementedExpression>("(");
  const auto _brackedc = Operator::registerOperator<UnimplementedExpression>(")");
  const auto _plus =     Operator::registerOperator<UnimplementedExpression>("+");
  const auto _minus =    Operator::registerOperator<UnimplementedExpression>("-");
  const auto _asterix =  Operator::registerOperator<UnimplementedExpression>("*");
  const auto _div =      Operator::registerOperator<UnimplementedExpression>("/");

  const auto _eq =       Operator::registerOperator<UnimplementedExpression>("=");
  const auto _less =     Operator::registerOperator<UnimplementedExpression>("<");
  const auto _greater =  Operator::registerOperator<UnimplementedExpression>(">");
  const auto _leq =      Operator::registerOperator<UnimplementedExpression>("<=");
  const auto _geq =      Operator::registerOperator<UnimplementedExpression>(">=");
  const auto _neq =      Operator::registerOperator<UnimplementedExpression>("<>");
} // namespace
