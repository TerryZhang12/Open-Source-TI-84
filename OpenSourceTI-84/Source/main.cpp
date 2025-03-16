#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "terms.h"
#include "combine.h"
#include "graph.h"
#include "constant.h"

//I know this isn't "great" but it was too annoying to type the whole thing
typedef std::unique_ptr<Expression> ExpressionPtr;

int main()
{
	sf::RenderWindow window(sf::VideoMode({screenWidth, screenHeight}), "Graphing");

	ExpressionPtr poly1 = std::make_unique<Polynomial>(3);
	ExpressionPtr poly2 = std::make_unique<Polynomial>(2);
	ExpressionPtr poly3 = std::make_unique<Polynomial>(1);
	ExpressionPtr const1 = std::make_unique<ConstPolynomial>(1);
	ExpressionPtr const5 = std::make_unique<ConstPolynomial>(5);
	ExpressionPtr sin = std::make_unique<Sin>();

	poly3->coefficient = 2;
	ExpressionPtr poly4 = addExpressions(poly2, poly3);
	ExpressionPtr poly5 = addExpressions(poly4, const5);
	ExpressionPtr polysin = chainExpressions(sin, poly5);

	ExpressionPtr testPoly = divideExpressions(const1, polysin);


	window.clear();
	window.display();
	Graph graph(testPoly);
	graph.xStart = -10;
	graph.xEnd = 10;
	graph.yStart = -10;
	graph.yEnd = 10;

	graph.loadExpression();
	graph.transformToGraph();
	graph.graph(window);

	window.display();
	std::cout << "graphed" << std::endl;

	int eval;
	std::cin >> eval;

	std::cout << graph.expression->evaluate(eval);

	return 0;
}