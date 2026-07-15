#include <SFML/Graphics.hpp>
#include <cmath>


int main() {
    // init window
    constexpr unsigned int windowWidth = 800; // constexpr means @ compiled, not runtime -> save memory
    constexpr unsigned int windowHeight = 600;
    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "Gravity simulation");

    // circle (particle)
    float radius = 15.f;
    sf::CircleShape circle(radius);
    circle.setOutlineColor(sf::Color::Black);
    circle.setFillColor(sf::Color::Black);
    circle.setPosition({400, 100});

    sf::Vector2f position;
    sf::Vector2f velocity;

    velocity.x = 150.f; // for test

    sf::Clock clock; // create clock
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        const float deltaTime = elapsed.asSeconds(); // amount of time that passed between the last frame and the current one
        constexpr float gravity = 9.81f;

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        sf::Vector2f& pos = position; // reference (nickname) to position

        velocity.y += gravity * deltaTime;
        pos.y += velocity.y * deltaTime * 100.f; // 100.f is a scale factor for pixels
        pos.x += velocity.x * deltaTime * 100.f;

        if (pos.y > windowHeight - radius) {
            pos.y = windowHeight - radius; // snap to floor
            velocity.y *= -0.8f; // bounce

            // stop jittering if the bounce is weak
            if (std::abs(velocity.y) < 2.0f) { // abs is absolute value -> cmath
                velocity.y = 0.0f;
            }
        }

        if (pos.x > windowWidth - radius) {
            pos.x = windowWidth - radius;
            velocity.x *= -0.8f;

            if (std::abs(velocity.x) < 2.0f) { // abs is absolute value -> cmath
                velocity.x = 0.0f;
            }
        }

        if (pos.x < radius) { // ???
            pos.x = radius;
            velocity.x *= -0.8f;

            if (std::abs(velocity.x) < 2.0f) {
                velocity.x = 0.0f;
            }
        }

        circle.setPosition(position);

    window.clear(sf::Color::White);
    window.draw(circle);
    window.display();

    }
    return 0;
}