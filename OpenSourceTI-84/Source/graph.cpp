#include "graph.h"


Graph::Graph(std::unique_ptr<Expression>& expression) : expression(std::move(expression)),
														xStart(-20.f),
														xEnd(20.f),
														yStart(-10.f),
														yEnd(10.f),
														color(sf::Color::Red)
{
	sf::VertexArray verticies(sf::PrimitiveType::Points, points.size());
}

float Graph::xScale() const
{
	return screenWidth / (xEnd - xStart);
}

float Graph::yScale() const
{
	return screenHeight / (yEnd - yStart);
}

void Graph::loadExpression()
{
	for (float i = xStart; i <= xEnd; i += graphPrecision)
	{
		points[i] = expression->evaluate(i);
	}
	verticies.resize(points.size());
}

void Graph::transformToGraph()
{
	size_t totalPoints = 0;

	for (const auto& [x, y] : points)
	{
		if (x >= xStart && x <= xEnd && y >= yStart && y <= yEnd)
		{
			float transformX = (x - xStart) * xScale();
			float transformY = screenHeight - ((y - yStart) * yScale());

			auto& vertex = verticies[totalPoints++];
			vertex.position = { transformX, transformY };
		}
	}

	verticies.resize(totalPoints + 1);
}

void Graph::graph(sf::RenderWindow& window)
{
	for (size_t i = 0; i < verticies.getVertexCount(); i++)
	{
		auto& vertex = verticies[i];
		sf::CircleShape point;
		point.setPosition(vertex.position);
		point.setFillColor(color);
		point.setRadius(1.f);
		window.draw(point);
	}
}

