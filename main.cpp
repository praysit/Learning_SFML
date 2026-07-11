#include <SFML/Graphics.hpp>
#include <cmath>


int main() {
    // init window
    constexpr unsigned int windowWidth = 800;
    constexpr unsigned int windowHeight = 600;
    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "Gravity simulation");

    // circle (particle)
    sf::CircleShape circle(15.f);
    circle.setOutlineColor(sf::Color::Black);
    circle.setFillColor(sf::Color::Black);
    circle.setPosition({400, 100});

    sf::Vector2f position;
    sf::Vector2f velocity;

    sf::Clock clock; // create clock
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds(); // amount of time that passed between the last frame and the current one
        const float gravity = 9.81f;
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        sf::Vector2f& pos = position; // reference (nickname) to position

        velocity.y += gravity * deltaTime;
        pos.y += velocity.y * deltaTime * 100.f; // 100.f is a scale factor for pixels

        if (pos.y > 570.f) {
            pos.y = 570.f; // snap to floor
            velocity.y *= -0.8f; // bounce

            // stop jittering if the bounce is weak
            if (std::abs(velocity.y) < 2.0f) { // abs is absolute value -> cmath
                velocity.y = 0.0f;
            }
        }
        pos.x = 400;

        circle.setPosition(position);

    window.clear(sf::Color::White);
    window.draw(circle);
    window.display();

    }
    return 0;
}