#pragma once

#include "expression.h"
#include <unordered_map>
#include <memory>
#include "global.h"
#include <SFML/Graphics.hpp>
#include <iostream>

struct Graph
{
	std::unique_ptr<Expression> expression;
	std::unordered_map<float, float> points;
	sf::VertexArray verticies;
	sf::Color color;

	float xStart;
	float xEnd;
	float yStart;
	float yEnd;

	float xScale() const;
	float yScale() const;

	Graph(std::unique_ptr<Expression>& expression);

	void loadExpression();
	void transformToGraph();

	void graph(sf::RenderWindow& window);
};