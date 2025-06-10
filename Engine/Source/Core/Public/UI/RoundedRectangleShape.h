// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef ROUNDEDRECTANGLESHAPE_H
#define ROUNDEDRECTANGLESHAPE_H

#include <cstddef>

#include "SFML/Graphics/Shape.hpp"


/**
 * @class RoundedRectangleShape
 * @brief A shape class representing a rounded rectangle.
 *
 * This class inherits from sf::Shape and allows the creation
 * and manipulation of rounded rectangles by specifying their corner radius
 * and number of points used to approximate the rounded corners.
 */
class RoundedRectangleShape final : public sf::Shape
{
public:
	/**
	 * @brief Constructs a RoundedRectangleShape with a specified corner radius and point count.
	 *
	 * This constructor initializes a rounded rectangle shape with the given radius and
	 * number of points used to approximate the rounded corners. It provides default
	 * values for both parameters, allowing flexibility in shape creation.
	 *
	 * @param size The size of the bounding  rectangle
	 * @param radius The radius of the rounded corners. Defaults to 0.
	 * @param pointCount The number of points used to approximate the rounded corners. Defaults to 30.
	 */
	explicit RoundedRectangleShape(sf::Vector2f size, float radius = 0, std::size_t pointCount = 32);
	void setRadius(float radius);
	[[nodiscard]] float getRadius() const;
	void setSize(sf::Vector2f size);
	[[nodiscard]] sf::Vector2f getSize() const;
	void setPointCount(std::size_t count);
	[[nodiscard]] std::size_t getPointCount() const override;
	/**
	 * @brief Get a specific point of the rounded rectangle shape.
	 *
	 * This function retrieves a point's position based on the provided index.
	 * The points represent the outline of the shape, including its rounded corners.
	 *
	 * @param index Index of the point to retrieve.
	 * @return The position of the point as a 2D vector (sf::Vector2f).
	 */
	[[nodiscard]] sf::Vector2f getPoint(std::size_t index) const override;
	[[nodiscard]] sf::Vector2f getGeometricCenter() const override;

private:
	float m_radius;			  // Radius of the circle
	std::size_t m_pointCount; // Number of points composing the circle
	sf::Vector2f m_size;	  // Size of the bounding rectangle
};

#endif // ROUNDEDRECTANGLESHAPE_H
