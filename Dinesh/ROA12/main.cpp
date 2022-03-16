#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200),"ROA12", sf::Style::Fullscreen);
    //MainBackground.setFillColor(sf::Color::Red);
    sf::Texture backgroundImage;
    if (!backgroundImage.loadFromFile("Data/Wallpaper/Wallpaper_01.jpg"))
    {
        cout << "Unable to open background image.";
    }

    
    sf::RectangleShape MainBackground(sf::Vector2f(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.84));
    MainBackground.setTexture(&backgroundImage);
    MainBackground.setPosition(window.getSize().x / 2 - MainBackground.getSize().x / 2, window.getSize().y / 2 - MainBackground.getSize().y / 2);
    MainBackground.setOutlineThickness(8.f);
    MainBackground.setOutlineColor(sf::Color::Black);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
           // cout << MainBackground.getSize().x << " " << MainBackground.getSize().y << endl;
        }

        window.clear(sf::Color::White);
        window.draw(MainBackground);
        window.display();
    }

    return 0;
}