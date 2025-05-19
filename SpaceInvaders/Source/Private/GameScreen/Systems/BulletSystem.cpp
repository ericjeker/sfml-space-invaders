// Copyright (c) 2025 Eric Jeker. All rights reserved.

#include "GameScreen/Systems/BulletSystem.h"


BulletSystem::BulletSystem(const Configuration& configuration) : _configuration(configuration) {}

void BulletSystem::Initialize()
{
    _bulletShape = std::make_unique<sf::RectangleShape>(sf::Vector2f(10.f, 10.f));
    _bulletShape->setFillColor(sf::Color::Red);
    _bulletShape->setOrigin(_bulletShape->getSize() / 2.f);
}

void BulletSystem::Update(const sf::Time& deltaTime, BulletCollection& bullets)
{
    for (size_t i = 0; i < bullets.position.size(); ++i)
    {
        float delta = deltaTime.asSeconds();
        bullets.position[i] += bullets.velocity[i] * delta;
    }
}

void BulletSystem::Render(sf::RenderTexture& renderTexture, const BulletCollection& bullets) const
{
    // TODO: will have to create an object pool
    for (size_t i = 0; i < bullets.position.size(); ++i)
    {
        _bulletShape->setPosition(bullets.position[i]);
        renderTexture.draw(*_bulletShape);
    }
}

void BulletSystem::SpawnBullet(BulletCollection& bullets, const sf::Vector2f& position)
{
    bullets.position.push_back(position);
    bullets.velocity.push_back(sf::Vector2f(0.f, 1000.f));
    bullets.damages.push_back(10);
}
