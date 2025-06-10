// Copyright (c) Eric Jeker. All Rights Reserved.

#include "../../Public/UI/RoundedRectangleShape.h"

#include <cmath>
#include <cstddef>

RoundedRectangleShape::RoundedRectangleShape(const sf::Vector2f size, const float radius, const std::size_t pointCount)
	: m_radius(radius)
	, m_pointCount(pointCount)
	, m_size(size)
{
	update();
}

void RoundedRectangleShape::setRadius(float radius)
{
	m_radius = radius;
	update();
}

float RoundedRectangleShape::getRadius() const
{
	return m_radius;
}

void RoundedRectangleShape::setSize(sf::Vector2f size)
{
	m_size = size;
	update();
}

sf::Vector2f RoundedRectangleShape::getSize() const
{
	return m_size;
}

void RoundedRectangleShape::setPointCount(std::size_t count)
{
	m_pointCount = count;
	update();
}

std::size_t RoundedRectangleShape::getPointCount() const
{
	return m_pointCount;
}

sf::Vector2f RoundedRectangleShape::getPoint(std::size_t index) const
{
	// ------------------------------------------------------------
	// 1.  Trivial / degenerate cases
	// ------------------------------------------------------------
	if (m_radius <= 0.f || m_pointCount < 4)
	{
		// Pure rectangle ‑ four hard corners
		switch (index % 4)
		{
			case 0:
				return {0.f, 0.f};
			case 1:
				return {m_size.x, 0.f};
			case 2:
				return {m_size.x, m_size.y};
			default:
				return {0.f, m_size.y};
		}
	}

	// ------------------------------------------------------------
	// 2.  Geometry for the rounded variant
	// ------------------------------------------------------------
	//
	// let  P = m_pointCount
	//      C = points on one *quarter* arc *without* the duplicate
	//      D = C + 1 (quarter arc including its duplicate)
	//
	// P = 4·C + 4 → C = (P-4)/4, D = C+1
	//
	const std::size_t cornerPointCount = (m_pointCount - 4) / 4; // C
	const std::size_t pointsPerCorner = cornerPointCount + 1;	 // D

	// Define which corner we are working with (Top-Left to Bottom-Left)
	const std::size_t cornerIndex = index / pointsPerCorner;   // 0 .. 3
	const std::size_t indexInCorner = index % pointsPerCorner; // 0 .. D-1

	// Angle step (clock-wise, screen coordinates: +y is down)
	const float deltaAngle = 90.f / static_cast<float>(cornerPointCount);
	// Angle of the current quarter circle
	float angleDeg = 0.f;
	// Center of the current quarter circle
	sf::Vector2f center;

	switch (cornerIndex)
	{
		case 0: // Top-left: 180° → 270°
			angleDeg = 180.f + indexInCorner * deltaAngle;
			center = {m_radius, m_radius};
			break;

		case 1: // Top-right: 270° → 360°
			angleDeg = 270.f + indexInCorner * deltaAngle;
			center = {m_size.x - m_radius, m_radius};
			break;

		case 2: // Bottom-right: 0° → 90°
			angleDeg = indexInCorner * deltaAngle;
			center = {m_size.x - m_radius, m_size.y - m_radius};
			break;

		default: // Bottom-left: 90° → 180°
			angleDeg = 90.f + indexInCorner * deltaAngle;
			center = {m_radius, m_size.y - m_radius};
			break;
	}

	constexpr float PI = M_PI;
	const float rad = angleDeg * PI / 180.f;

	// Offset from the center of the current quarter circle
	const sf::Vector2f offset(std::cos(rad) * m_radius, std::sin(rad) * m_radius);

	return center + offset;
}

sf::Vector2f RoundedRectangleShape::getGeometricCenter() const
{
	return {m_size.x / 2, m_size.y / 2};
}