#pragma once

#include "expression.h"
#include <memory>
#include <iostream>

struct AddExpressions : public Expression {
	std::unique_ptr<Expression> expression1;
	std::unique_ptr<Expression> expression2;

	AddExpressions(std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2);
	float evaluate(float value) const override;
};

struct SubtractExpressions : public Expression
{
	std::unique_ptr<Expression> expression1;
	std::unique_ptr<Expression> expression2;

	SubtractExpressions(std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2);

	float evaluate(float value) const override;
};

struct MultiplyExpressions : public Expression {
	std::unique_ptr<Expression> expression1;
	std::unique_ptr<Expression> expression2;

	MultiplyExpressions(std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2);
	float evaluate(float value) const override;
};

struct DivideExpressions : public Expression
{
	std::unique_ptr<Expression> expression1;
	std::unique_ptr<Expression> expression2;

	DivideExpressions(std::unique_ptr<Expression> e1, std::unique_ptr<Expression> e2);

	float evaluate(float value) const override;
};

struct ChainExpressions : public Expression //f(g(x))
{
	std::unique_ptr<Expression> outside; //f(x)
	std::unique_ptr<Expression> inside; //g(x)

	ChainExpressions(std::unique_ptr<Expression> outside, std::unique_ptr<Expression> inside);

	float evaluate(float value) const override;
};

/////////////////////////////////////////////////////
std::unique_ptr<Expression> addExpressions(std::unique_ptr<Expression>& e1, std::unique_ptr<Expression>& e2);
std::unique_ptr<Expression> subtractExpressions(std::unique_ptr<Expression>& e1, std::unique_ptr<Expression>& e2);
std::unique_ptr<Expression> multiplyExpressions(std::unique_ptr<Expression>& e1, std::unique_ptr<Expression>& e2);
std::unique_ptr<Expression> divideExpressions(std::unique_ptr<Expression>& e1, std::unique_ptr<Expression>& e2);
std::unique_ptr<Expression> chainExpressions(std::unique_ptr<Expression>& outside, std::unique_ptr<Expression>& inside);
