#include <SFML/Graphics.hpp>

int main() {
    constexpr unsigned int windowWidth = 800;
    constexpr unsigned int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "Hello");

    sf::CircleShape circle;
    circle.setRadius(150);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(5);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            circle.setPosition({mousePos.x, mousePos.y});
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    window.clear(sf::Color::White);
                    window.draw(circle);
                    window.display();
            }
    }
    return 0;
}