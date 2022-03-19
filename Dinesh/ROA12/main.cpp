#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;



//class Notification
//{
//private:
//	bool IsActive;
//	sf::RectangleShape Background;
//public:
//	Notification(float x, float y)
//	{
//		IsActive = 0;
//		Background.setSize(sf::Vector2f(sf::Vector2f(x, y)));
//	}
//
//	// Setters & Getters
//	void SetIsACtive(int IsActive)
//	{
//		this->IsActive = IsActive;
//	}
//	bool GetIsACtive(void)
//	{
//		return IsActive;
//	}
//
//};


int main()
{

	//sf::RenderWindow window(sf::VideoMode(200, 200), "ROA12", sf::Style::Fullscreen);
	sf::RenderWindow window(sf::VideoMode(800, 800), "ROA12", sf::Style::Default);
	//Notification notification(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.84);
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
	//shape.setFillColor(sf::Color(255, 255, 0));
	//shape.setOrigin(0, shape.getSize().y);
	sf::Vector2f PreviousPositionOfShape(shape.getPosition());
	// cout << MainBackground.getPosition().x << " " << MainBackground.getPosition().y << endl;
	// cout << shape.getPosition().x << " " << shape.getPosition().y << endl;

	// NAVIGATION BAR 
	sf::RectangleShape NavigationBar(sf::Vector2f(MainBackground.getSize().x, MainBackground.getSize().y * 0.047));
	NavigationBar.setFillColor(sf::Color::Black);
	NavigationBar.setPosition(MainBackground.getPosition().x, MainBackground.getSize().y + MainBackground.getPosition().y - NavigationBar.getSize().y);
	
	// NAVIGATION BAR ICONS
		// Back Icon
	sf::CircleShape BackIcon(NavigationBar.getSize().y * 0.24f, 3);
	BackIcon.setFillColor(sf::Color::White);
	BackIcon.setPosition(NavigationBar.getPosition().x + NavigationBar.getSize().x / 4.0 - BackIcon.getRadius() / 2, NavigationBar.getPosition().y + NavigationBar.getSize().y / 4.0 - BackIcon.getRadius() / 2);
	
	BackIcon.setRotation(30.f);
		// Outer Home Icon
	sf::CircleShape HomeIcon(NavigationBar.getSize().y * 0.22f);
	HomeIcon.setFillColor(sf::Color::Transparent);
	HomeIcon.setOutlineThickness(1);
	HomeIcon.setOutlineColor(sf::Color::White);
	HomeIcon.setOrigin(HomeIcon.getRadius() / 2, HomeIcon.getRadius() / 2);
	HomeIcon.setPosition(NavigationBar.getPosition().x + NavigationBar.getSize().x / 2.0 - HomeIcon.getRadius()/2, NavigationBar.getPosition().y + NavigationBar.getSize().y / 2.0 - HomeIcon.getRadius() / 2);
		// Inner Home Icon
	sf::CircleShape HomeIconSmall(NavigationBar.getSize().y * 0.15f);
	HomeIconSmall.setFillColor(sf::Color::White);
	HomeIconSmall.setOrigin(HomeIconSmall.getRadius() / 2, HomeIconSmall.getRadius() / 2);
	HomeIconSmall.setPosition(NavigationBar.getPosition().x + NavigationBar.getSize().x / 2.0 - HomeIconSmall.getRadius()/2, NavigationBar.getPosition().y + NavigationBar.getSize().y / 2.0 - HomeIconSmall.getRadius() / 2);
		// Recent Icon
	sf::RectangleShape RecentIcon(sf::Vector2f(NavigationBar.getSize().y * 0.38f, NavigationBar.getSize().y * 0.38f));
	RecentIcon.setFillColor(sf::Color::White);
	RecentIcon.setPosition(NavigationBar.getPosition().x + NavigationBar.getSize().x*0.75, NavigationBar.getPosition().y + NavigationBar.getSize().y/2 - RecentIcon.getSize().x/2);



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
		window.draw(NavigationBar);
		window.draw(BackIcon);
		window.draw(HomeIcon);
		window.draw(HomeIconSmall);
		window.draw(RecentIcon);
		window.display();
	}
	return 0;
}
