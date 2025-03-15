#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "terms.h"
#include "combine.h"
#include "graph.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode({800, 600}), "Graphing");

	std::unique_ptr<Expression> poly1 = std::make_unique<Polynomial>(2);
	std::unique_ptr<Expression> poly2 = std::make_unique<Polynomial>(1);
	std::unique_ptr<Expression> poly3 = std::make_unique<Polynomial>(2);
	
	std::unique_ptr<Expression> binomial = addExpressions(poly1, poly2);
	std::unique_ptr<Expression> factoredTrinomial = chainExpressions(poly3, binomial);

	Graph graph(factoredTrinomial);
	graph.loadExpression();
	graph.graph(window);

	window.display();
	std::cout << "graphed" << std::endl;

	std::string wait;
	std::cin >> wait;

	return 0;
}