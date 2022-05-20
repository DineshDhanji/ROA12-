#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

// GLOBAL SCOPE
int WhoIsActiveNow = 0;

// CLASSES
class DefaultSystem
{
private:
	bool DarkTheme;
	sf::Color FontColor;
	sf::Color BackgroundColor;

public:
	// CONSTRUCTOR(S)
	DefaultSystem()
	{
		FontColor = sf::Color::Black;
		//BackgroundColor = sf::Color::White;
		BackgroundColor = sf::Color(48, 49, 44, 120);
		DarkTheme = 0;
	}
	// DESTRUCTOR(S)
	~DefaultSystem() {}

	// SETTERS
	void setFontColor(sf::Color FontColor)
	{
		this->FontColor = FontColor;
	}
	void setBackgroundColor(sf::Color BackgroundColor)
	{
		this->BackgroundColor = BackgroundColor;
	}
	void setDarkTheme(bool DarkTheme)
	{
		this->DarkTheme = DarkTheme;
	}
	// GETTERS
	sf::Color getFontColor(void)
	{
		return FontColor;
	}
	sf::Color getBackgroundColor(void)
	{
		return BackgroundColor;
	}
	bool getDarkTheme(void)
	{
		return DarkTheme;
	}
};
class Tile
{
public:
	sf::RectangleShape Background;
	int ID;

	// CONSTRUCTOR(S)
	Tile(int ID) {
		this->ID = ID;
	}
	// DESTRUCTOR(S)
	~Tile()
	{}

	// SETTER(S)
	void setID(int ID)
	{
		this->ID = ID;
	}
	// GETTER(S)
	int getID(void)
	{
		return ID;
	}
};
class Navigation
{
public:

	sf::RectangleShape Bar;
	// NAVIGATION BAR ICONS
	sf::CircleShape BackIcon;
	sf::CircleShape HomeIcon;
	sf::CircleShape HomeIconSmall;
	sf::RectangleShape RecentIcon;

	// FUNCTION(S)
	void Appear(float x, float y)
	{
		Bar.setPosition(x, y - Bar.getSize().y);
		BackIcon.setPosition(Bar.getPosition().x + Bar.getSize().x / 4.0 - BackIcon.getRadius() / 2, Bar.getPosition().y + Bar.getSize().y / 4.0 - BackIcon.getRadius() / 2);
		HomeIcon.setPosition(Bar.getPosition().x + Bar.getSize().x / 2.0 - HomeIcon.getRadius() / 2, Bar.getPosition().y + Bar.getSize().y / 2.0 - HomeIcon.getRadius() / 2);
		HomeIconSmall.setPosition(Bar.getPosition().x + Bar.getSize().x / 2.0 - HomeIconSmall.getRadius() / 2, Bar.getPosition().y + Bar.getSize().y / 2.0 - HomeIconSmall.getRadius() / 2);
		RecentIcon.setPosition(Bar.getPosition().x + Bar.getSize().x * 0.75, Bar.getPosition().y + Bar.getSize().y / 2 - RecentIcon.getSize().x / 2);
	}

	// CONSTRUCTOR(S)
	Navigation(float x, float y)
	{
		Bar.setSize(sf::Vector2f(x, y));
		Bar.setFillColor(sf::Color::Black);
		//BackIcon.setRadius(Bar.getSize().y * 0.24f, 3);
		BackIcon.setRadius(Bar.getSize().y * 0.24f);
		BackIcon.setPointCount(3);
		BackIcon.setFillColor(sf::Color::White);
		BackIcon.setRotation(30.f);
		BackIcon.setPosition(Bar.getPosition().x + Bar.getSize().x / 4.0 - BackIcon.getRadius() / 2, Bar.getPosition().y + Bar.getSize().y / 4.0 - BackIcon.getRadius() / 2);

		HomeIcon.setRadius(Bar.getSize().y * 0.22f);
		HomeIcon.setFillColor(sf::Color::Transparent);
		HomeIcon.setOutlineThickness(1);
		HomeIcon.setOutlineColor(sf::Color::White);
		HomeIcon.setOrigin(HomeIcon.getRadius() / 2, HomeIcon.getRadius() / 2);
		HomeIcon.setPosition(Bar.getPosition().x + Bar.getSize().x / 2.0 - HomeIcon.getRadius() / 2, Bar.getPosition().y + Bar.getSize().y / 2.0 - HomeIcon.getRadius() / 2);


		HomeIconSmall.setRadius(Bar.getSize().y * 0.15f);
		HomeIconSmall.setFillColor(sf::Color::White);
		HomeIconSmall.setOrigin(HomeIconSmall.getRadius() / 2, HomeIconSmall.getRadius() / 2);
		HomeIconSmall.setPosition(Bar.getPosition().x + Bar.getSize().x / 2.0 - HomeIconSmall.getRadius() / 2, Bar.getPosition().y + Bar.getSize().y / 2.0 - HomeIconSmall.getRadius() / 2);

		RecentIcon.setSize(sf::Vector2f(Bar.getSize().y * 0.38f, Bar.getSize().y * 0.38f));
		RecentIcon.setFillColor(sf::Color::White);
		RecentIcon.setPosition(Bar.getPosition().x + Bar.getSize().x * 0.75, Bar.getPosition().y + Bar.getSize().y / 2 - RecentIcon.getSize().x / 2);

	}

};

class Notification : protected Tile
{
public:
	Notification(int ID, float x, float y) :Tile(ID)
	{
		Background.setSize(sf::Vector2f(x, y));
	}
};


int main()
{
	//	sf::RenderWindow window(sf::VideoMode(200, 200), "ROA12", sf::Style::Fullscreen);
	sf::RenderWindow window(sf::VideoMode(800, 800), "ROA12", sf::Style::Default);

	// Default Setting
	DefaultSystem DefaultSetting;

	// MAINBACKGROUND
	Tile Home(0);
	sf::Texture backgroundImage;
	if (!backgroundImage.loadFromFile("Data/Wallpaper/Wallpaper_01.jpg"))
	{
		cout << "Unable to open background image.";
	}
	Home.Background.setSize(sf::Vector2f(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.84));
	Home.Background.setTexture(&backgroundImage);
	Home.Background.setPosition(window.getSize().x / 2 - Home.Background.getSize().x / 2, window.getSize().y / 2 - Home.Background.getSize().y / 2);
	Home.Background.setOutlineThickness(8.f);
	Home.Background.setOutlineColor(sf::Color::Black);

	// NAVIGATION
	Navigation NavigationBar(Home.Background.getSize().x, Home.Background.getSize().y * 0.047);

	// NAVIGATION BAR 
	Notification Notifications(1, Home.Background.getSize().x, Home.Background.getSize().y);

	Notifications.Background.setPosition(Home.Background.getPosition().x, Home.Background.getPosition().y - (Home.Background.getSize().y));
	Notifications.Background.setFillColor(DefaultSetting.getBackgroundColor());
	sf::Vector2f PreviousPositionOfNotificationBackground(Notifications.Background.getPosition());
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
			// Position will be set according to window not to whole screen.
			sf::Vector2f MousePosition(sf::Mouse::getPosition(window));
			// Checking if MainBackground contain mouse or not.
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Home.Background.getGlobalBounds().contains(MousePosition) && !NavigationBar.Bar.getGlobalBounds().contains(MousePosition))
			{
				int up = 1, down = 1;
				sf::Vector2f temp(sf::Mouse::getPosition());
				sf::Clock clock;
				sf::Time time = sf::seconds(1);
				while (clock.getElapsedTime().asSeconds() <= time.asSeconds() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//cout << "x=" << sf::Mouse::getPosition().x << " y=" << sf::Mouse::getPosition().y << endl;
					if (sf::Mouse::getPosition().x == temp.x && sf::Mouse::getPosition().y > temp.y)
					{
						up++;
					}
					else if (sf::Mouse::getPosition().x == temp.x && sf::Mouse::getPosition().y < temp.y)
					{
						down++;
					}
				}
				cout << "UP: " << up << endl;
				cout << "Down: " << down << endl;
				if (up > down)
				{
					Notifications.Background.setPosition(Home.Background.getPosition());
				}
				else
				{
					Notifications.Background.setPosition(PreviousPositionOfNotificationBackground);
				}
			}



			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				Home.Background.setPosition(Home.Background.getPosition().x - 10, Home.Background.getPosition().y);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				Home.Background.setPosition(Home.Background.getPosition().x + 10, Home.Background.getPosition().y);
			}
		}
		NavigationBar.Appear(Home.Background.getPosition().x, Home.Background.getSize().y + Home.Background.getPosition().y);

		window.clear(sf::Color::White);
		window.draw(Home.Background);
		window.draw(Notifications.Background);
		window.draw(NavigationBar.Bar);
		window.draw(NavigationBar.BackIcon);
		window.draw(NavigationBar.HomeIcon);
		window.draw(NavigationBar.HomeIconSmall);
		window.draw(NavigationBar.RecentIcon);
		window.display();
	}





	return 0;
}
