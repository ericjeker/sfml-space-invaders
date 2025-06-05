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
	Button(const std::shared_ptr<sf::Font>& font, const std::string& label, const unsigned int& fontSize, const int& commandId);

	void Update(const sf::Time& deltaTime) override;
	void Render(sf::RenderTexture& renderTexture) const override;

	void SetLabel(const std::string& label);
	void SetSize(sf::Vector2f size);

	void TestHit(const sf::Vector2f& position) override;

private:
	sf::Font _font;
	std::string _label;
	unsigned int _fontSize;
	sf::Color _color;
	sf::Vector2f _size;

	sf::Text _text;
	sf::RectangleShape _drawable;
	bool _debug = true;
};

#endif // BUTTON_H
