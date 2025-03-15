#include "graph.h"

Graph::Graph(std::unique_ptr<Expression>& expression) : expression(std::move(expression)),
														xStart(-20.f),
														xEnd(20.f),
														yStart(-10.f),
														yEnd(10.f)
{}

void Graph::loadExpression()
{
	for (float i = xStart; i <= xEnd; i += graphPrecision)
	{
		points[i] = expression->evaluate(i);
	}
}

void Graph::graph(sf::RenderWindow& window)
{
	sf::VertexArray verticies(sf::PrimitiveType::Points, points.size());
	size_t pointsLength = 0;

	const float xScale = screenWidth / (xEnd - xStart);
	const float yScale = screenHeight / (yEnd - yStart);

	for (const auto& [x, y] : points)
	{
		if (x > xStart && x < xEnd && y > yStart && y < yEnd)
		{
			float transformX = (x - xStart) * xScale;
			float transformY = screenHeight - ((y - yStart) * yScale);

			auto vertex = verticies[pointsLength];
			vertex.position = { transformX, transformY };
			vertex.color = sf::Color::Red;
			pointsLength++;
		}

		verticies.resize(pointsLength);
		window.draw(verticies);
	}
}

