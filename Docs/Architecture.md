# Architectural Consideration

To avoid bloating the README file I will take some notes and reflexion here.

## Principles of Good Engineering

1. Separation of concerns, separate rendering and game logic
2. Encapsulation of shared rendering logic into components
3. Iterate quickly, refactor for clarity, avoid premature optimization
4. Keep it simple, avoid unnecessary complexity
5. Use object pooling, avoid generating objects in the update loop

## Separation of concerns

Components are data object. They contain no logic. They are only responsible for holding data and providing access to 
that data to the rendering objects and logic objects.

Data object are easily serializable if necessary. They can be serialized to a file or sent over a network.

```C++
// This is pseudo-code, it doesn't work

struct ButtonComponent 
{
    std::string label{""};
    sf::Vector2f position{0.f, 0.f};
    sf::Vector2f size{0.f, 0.f};
    sf::Vector2f origin{0.f, 0.f};
    sf::Vector2f scale{1.f, 1.f};
    sf::Color fillColor{sf::Color::Blue};
    sf::Color textColor{sf::Color::White};    
}
```

Logic object:

```C++
class Button : public Entity
{
public:
    Button(ButtonComponent component) : _component(component) {}
    ~Button() = default;
    
    Update(const TimeTicker& timeTicker, const GameState& gameState) override {}
private:
    ButtonComponent _component;
}

class Entity
{
public:
    virtual Update(const TimeTicker& timeTicker, const GameState& gameState) = 0;
}
```

The rendering class knows how to render a component:

```C++
class ButtonRenderer : public RenderableObject 
{
public:
    Button(ButtonComponent component) 
    {
        buttonShape.setSize(component.size);
        buttonShape.setFillColor(component.fillColor);
        buttonShape.setPosition(component.position);

        buttonText.setFont(component.font);
        buttonText.setString(component.label);
        buttonText.setCharacterSize(component.characterSize);
        buttonText.setFillColor(component.textColor);
        buttonText.setPosition(component.textPosition);
    }

    void Render(sf::RenderTexture& texture) override 
    {
        texture.draw(buttonShape);
        texture.draw(buttonText);
    }

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
};
```

```C++
class ButtonJsonSerializer : public JsonSerializableObject
{
    // ...
}

class JsonSerializableObject
{
public:
    JsonSerializableObject() = default;
    virtual ~JsonSerializableObject() = default;
    virtual void Serialize(JsonSerializer& serializer) const = 0;
    virtual void Deserialize(JsonSerializer& serializer) = 0;
}
```

## Factories

```C++
Text title = Text::Create("Space Invaders", 50, sf::Color::White);
Button playButton = Button::Create("Play");
Button exitButton = Button::Create("Exit");
```

## Object pooling

```C++
BulletPool pool;
Bullet bullet = pool.Allocate();
bullet.velocity({player.x, -1.f});
```
