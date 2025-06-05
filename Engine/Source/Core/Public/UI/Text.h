// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef TEXT_H
#define TEXT_H

#include "UIComponent.h"

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

class Text : public UIComponent
{
public:
	Text(const std::shared_ptr<sf::Font>& font, const std::string& label, const unsigned int& size,
		 const sf::Color& color);

	void Update(const sf::Time& deltaTime) override;
	void Render(sf::RenderTexture& renderTexture) const override;

	void SetLabel(const std::string& label);

	void TestHit(const sf::Vector2f& position) override;

private:
	std::shared_ptr<sf::Font> _font;
	std::string _label;
	unsigned int _size;
	sf::Color _color;

	sf::Text _drawable;
};

#endif // TEXT_H
