#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Hello");

    sf::CircleShape circle(150.f);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(5.f);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        circle.setPosition({static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)});

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            window.clear(sf::Color::White);
            window.draw(circle);
            window.display();
        }

    }
    return 0;
}