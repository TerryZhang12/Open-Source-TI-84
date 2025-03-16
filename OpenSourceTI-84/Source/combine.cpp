#include "combine.h"

//Structs
//Add
AddExpressions::AddExpressions(std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2) : expression1(std::move(e1)), 
																								 expression2(std::move(e2)) 
{}

float AddExpressions::evaluate(float value) const
{
	return expression1->evaluate(value) + expression2->evaluate(value);
}

//Subtract
SubtractExpressions::SubtractExpressions(std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2) : expression1(std::move(e1)),
																										   expression2(std::move(e2))
{}

float SubtractExpressions::evaluate(float value) const
{
	return expression1->evaluate(value) - expression2->evaluate(value);
}

//Multiply
MultiplyExpressions::MultiplyExpressions(std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2) : expression1(std::move(e1)),
																										   expression2(std::move(e2))
{
}

float MultiplyExpressions::evaluate(float value) const
{
	return expression1->evaluate(value) * expression2->evaluate(value);
}

//Divide
DivideExpressions::DivideExpressions(std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2) : expression1(std::move(e1)),
																									   expression2(std::move(e2))
{
}

float DivideExpressions::evaluate(float value) const
{
	if (expression2->evaluate(value) == 0) return 9999999.f;
	return expression1->evaluate(value) / expression2->evaluate(value);
}

//Chain
ChainExpressions::ChainExpressions(std::unique_ptr<Expression> outside, std::unique_ptr<Expression> inside) : outside(std::move(outside)),
																											  inside(std::move(inside))
{}

float ChainExpressions::evaluate(float value) const
{
	float inValue = inside->evaluate(value);
	return outside->evaluate(inValue);
}

//////////////////////////////////////////////
//Helper Functions
std::unique_ptr<Expression> addExpressions(std::unique_ptr<Expression>& e1, std::unique_ptr<Expression>& e2)
{
	return std::make_unique<AddExpressions>(std::move(e1), std::move(e2));
}

std::unique_ptr<Expression> subtractExpressions(std::unique_ptr<Expression>& e1, std::unique_ptr<Expression>& e2)
{
	return std::make_unique<SubtractExpressions>(std::move(e1), std::move(e2));
}

std::unique_ptr<Expression> multiplyExpressions(std::unique_ptr<Expression>& e1, std::unique_ptr<Expression>& e2)
{
	return std::make_unique<MultiplyExpressions>(std::move(e1), std::move(e2));
}

std::unique_ptr<Expression> divideExpressions(std::unique_ptr<Expression>& e1, std::unique_ptr<Expression>& e2)
{
	return std::make_unique<DivideExpressions>(std::move(e1), std::move(e2));
}

std::unique_ptr<Expression> chainExpressions(std::unique_ptr<Expression>& outside, std::unique_ptr<Expression>& inside)
{
	return std::make_unique<ChainExpressions>(std::move(outside), std::move(inside));
}
