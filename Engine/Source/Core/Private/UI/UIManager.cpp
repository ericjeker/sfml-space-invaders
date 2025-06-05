// Copyright (c) 2025 Eric Jeker. All rights reserved.


#include "../../Public/UI/UIManager.h"

#include "Command.h"
#include "CommandRegistry.h"

#include <iostream>
#include <ResourceManager.h>
#include <TimeTicker.h>

UIManager::UIManager(CommandRegistry& commandRegistry)
    : _commandRegistry(commandRegistry)
{
};

void UIManager::Update(const sf::Time& deltaTime) const
{
    for (const auto& component : _components)
    {
        component->Update(deltaTime);
    }
}

void UIManager::Render(sf::RenderTexture& renderTexture) const
{
	for (const auto& component : _components)
	{
		component->Render(renderTexture);
	}
}

void UIManager::AddComponent(std::unique_ptr<UIComponent> component)
{
    _components.push_back(std::move(component));
}

void UIManager::ClearComponents()
{
	_components.clear();
}

void UIManager::HandleEvents(const std::optional<sf::Event>& event) const
{
	if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
	{
		OnMouseMove(*mouseMoved);
	}
	else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
	{
		OnMousePressed(*mousePressed);
	}
}

void UIManager::OnMouseMove(const sf::Event::MouseMoved& event) const
{
	for (const auto& component : _components)
	{
		if (component->IsDisabled() || component->IsHidden())
		{
			continue;
		}

		component->TestHit(sf::Vector2f(event.position));
	}
}

void UIManager::OnMousePressed(const sf::Event::MouseButtonPressed& event) const
{
    const sf::Vector2i mousePosition = event.position;

	for (const auto& component : _components)
	{
		if (component->IsDisabled() || component->IsHidden())
		{
			continue;
		}

		if (component->IsHovered())
		{
			// Call the button's assigned action
			_commandRegistry.Execute(component->GetCommand());
		}

		component->TestHit(sf::Vector2f(mousePosition));
	}
}
