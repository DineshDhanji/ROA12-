#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
	//sf::RenderWindow window(sf::VideoMode(200, 200), "ROA12", sf::Style::Fullscreen);
	sf::RenderWindow window(sf::VideoMode(800, 800), "ROA12", sf::Style::Default);
	//MainBackground.setFillColor(sf::Color::Red);
	
	// MAINBACKGROUNG
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
	
	// NOTIFICATIONBACKGROUND
	sf::RectangleShape shape(MainBackground.getSize());
	shape.setPosition(MainBackground.getPosition().x, MainBackground.getPosition().y - (shape.getSize().y));
	shape.setFillColor(sf::Color(48, 49, 44, 120));
	//shape.setOrigin(0, shape.getSize().y);
	sf::Vector2f PreviousPositionOfShape(shape.getPosition());
	// cout << MainBackground.getPosition().x << " " << MainBackground.getPosition().y << endl;
	// cout << shape.getPosition().x << " " << shape.getPosition().y << endl;

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
			// if (BoundaryOfMainBackground.contains(MousePosition))
			{
				int up = 1, down = 1, left = 1;
				sf::Vector2f temp(sf::Mouse::getPosition());
				sf::Clock clock;
				sf::Time time = sf::milliseconds(50);
				while (clock.getElapsedTime() <= time && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					cout << "x=" << sf::Mouse::getPosition().x << " y=" << sf::Mouse::getPosition().y << endl;
					if (sf::Mouse::getPosition().x == temp.x  && sf::Mouse::getPosition().y > temp.y)
					{
						up++;
					}
					else if (sf::Mouse::getPosition().x == temp.x && sf::Mouse::getPosition().y < temp.y)
					{
						down++;
						/*temp.x = sf::Mouse::getPosition().x;
						temp.y = sf::Mouse::getPosition().y;*/
					}


					//shape.setPosition(temp.x, sf::Mouse::getPosition(window).y);


				}
				cout << "UP: " << up << endl;
				cout << "Down: " << down << endl;
				if (up > down)
				{
					shape.setPosition(MainBackground.getPosition());
				}
				else
				{
					shape.setPosition(PreviousPositionOfShape);
				}
			}
		}
			
		window.clear(sf::Color::White);
		window.draw(MainBackground);
		window.draw(shape);
		window.display();
	}
	return 0;
}
