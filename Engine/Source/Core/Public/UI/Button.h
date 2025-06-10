// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef BUTTON_H
#define BUTTON_H

#include "RoundedRectangleShape.h"
#include "UIComponent.h"

#include "SFML/Graphics/Font.hpp"
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
	void SetOutlineFillColor(const sf::Color& color);
	void SetSize(const sf::Vector2f& size);

	// Outline parameters
	void SetOutlineColor(const sf::Color& color);
	void SetOutlineThickness(const float& thickness);
	void SetOutlineRadius(const float& radius);

	bool Contains(const sf::Vector2f& position) const;
	void TestHit(const sf::Vector2f& position) override;

private:
	// Drawable objects
	sf::Text _text;
	RoundedRectangleShape _outline;

	// Display the bounding boxes when hovered
	bool _debug = true;
	std::shared_ptr<sf::Font> _font;
};

#endif // BUTTON_H
