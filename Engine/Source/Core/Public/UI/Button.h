// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef BUTTON_H
#define BUTTON_H

#include "UIComponent.h"

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"

class Button final : public UIComponent
{
public:
	Button(const std::shared_ptr<sf::Font>& font, const std::string& label, const unsigned int& fontSize,
		   const sf::Color& textColor, const int& commandId);

	void Update(const sf::Time& deltaTime) override;
	void Render(sf::RenderTexture& renderTexture) const override;

	// Text parameters
	void SetLabel(const std::string& label);
	void ResetLabelOrigin();

	// Button parameters
	void SetPosition(const sf::Vector2f& position) override;
	void SetSize(const sf::Vector2f& size);

	// Outline parameters
	void CreateOutline();
	void SetOutlineColor(const sf::Color& color);
	void SetOutlineThickness(const float& thickness);
	void SetOutlineRadius(const float& radius);

	bool Contains(const sf::Vector2f& position) const;
	void TestHit(const sf::Vector2f& position) override;

private:
	sf::Text _text;
	sf::VertexArray _vertices;

	// Parameters
	unsigned int _resolution = 64;
	sf::Vector2f _size{100, 100};
	sf::Color _color = sf::Color::White;
	float _radius = 10.f;
	float _thickness = 10.f;
	bool _isFilled = true;

	// Debug
	bool _debug = true;
};

#endif // BUTTON_H
