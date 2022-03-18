#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
	//sf::RenderWindow window(sf::VideoMode(200, 200), "ROA12", sf::Style::Fullscreen);
	sf::RenderWindow window(sf::VideoMode(800, 800), "ROA12", sf::Style::Default);
	//MainBackground.setFillColor(sf::Color::Red);
	sf::Texture backgroundImage;
	if (!backgroundImage.loadFromFile("Data/Wallpaper/Wallpaper_01.jpg"))
	{
		cout << "Unable to open background image.";
	}
	sf::RectangleShape MainBackground(sf::Vector2f(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.84));
	MainBackground.setTexture(&backgroundImage);
	//MainBackground.setOrigin(MainBackground.getSize().x / 2.0 , MainBackground.getSize().y / 2.0);
	MainBackground.setPosition(window.getSize().x / 2 - MainBackground.getSize().x / 2, window.getSize().y / 2 - MainBackground.getSize().y / 2);
	MainBackground.setOutlineThickness(8.f);
	MainBackground.setOutlineColor(sf::Color::Black);
	
	sf::RectangleShape shape(sf::Vector2f(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.30));
	shape.setPosition(MainBackground.getPosition().x, MainBackground.getPosition().y - (shape.getSize().y));
	shape.setFillColor(sf::Color(252, 226, 225));
	
	cout << MainBackground.getPosition().x << " " << MainBackground.getPosition().y << endl;
	cout << shape.getPosition().x << " " << shape.getPosition().y << endl;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			// SWIPING FUNCTION
			sf::FloatRect BoundaryOfMainBackground = MainBackground.getGlobalBounds();
			// Position will be set according to window not to whole screen.
			sf::Vector2f MousePosition(sf::Mouse::getPosition(window));
			// Checking if MainBackground contain mouse or not.
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && BoundaryOfMainBackground.contains(MousePosition))
			{
				cout << "x=" << MousePosition.x << " y=" << MousePosition.y << endl; 
				/*if (MousePosition.x )
				{

				}*/
			}
		}
			
		window.clear(sf::Color::White);
		window.draw(MainBackground);
		window.draw(shape);
		window.display();
	}
	return 0;
}
