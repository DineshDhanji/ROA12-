#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

// GLOBAL SCOPE
int WhoIsActiveNow = 0;
int arr[2] = { 0, 1 };


// CLASSES
class DefaultSystem
{
public:
	bool DarkTheme;
	sf::Color FontColor;
	sf::Color BackgroundColor;
	sf::Font font;

public:
	// CONSTRUCTOR(S)
	DefaultSystem()
	{
		FontColor = sf::Color::Black;
		//BackgroundColor = sf::Color::White;
		BackgroundColor = sf::Color(48, 49, 44, 120);
		DarkTheme = 0;
		if (!font.loadFromFile("Data/Fonts/ProductSans-Regular.ttf"))
		{
			cout << "Unable to load the fonts from file.";
		}
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
	sf::Font& getSystemFonts()
	{
		return font;
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

class Notification : public Tile
{
protected:
	sf::Vector2f PreviousPosition;
public:
	// Function(s)
	void Appear(float x, float y)
	{
		Background.setPosition(x, y);
		WhoIsActiveNow = getID();
	}
	void Disappear()
	{
		Background.setPosition(getPreviousPositionX(), getPreviousPositionY());
		WhoIsActiveNow = 0;
	}

	// Setter(s)
	void setPreviousPosition(sf::Vector2f position)
	{
		this->PreviousPosition.x = position.x;
		this->PreviousPosition.y = position.y;
	}
	void setPreviousPosition(int x, int y)
	{
		this->PreviousPosition.x = x;
		this->PreviousPosition.y = y;
	}

	// Getter(s)
	int getPreviousPositionX()
	{
		return PreviousPosition.x;
	}
	int getPreviousPositionY()
	{
		return PreviousPosition.y;
	}
	sf::Vector2f getPreviousPosition()
	{
		return PreviousPosition;
	}

	// Constructor
	Notification(int ID, float x, float y) :Tile(ID)
	{
		Background.setSize(sf::Vector2f(x, y));
	}

	// Destructor
	~Notification()
	{}
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

class App
{
public:
	sf::CircleShape Icon;
	sf::Texture textureIcon;
	Tile *AppBackground;
	float AppIconSize;
	sf::Text AppName;

	// Function(s)
	virtual void Appear() = 0;
	virtual void Disappear() = 0;

	// Setter(s)
	void setAppSize(float AppIconSize)
	{
		if (AppIconSize < 1)
		{
			cout << "Error! the given app icon size is invalid." << endl;
		}
		else
		{
			this->AppIconSize = AppIconSize;
		}
	}
	void setAppName(string AppName)
	{
		this->AppName.setString(AppName);
	}

	// Getter(s)
	float getAppSize()
	{
		return AppIconSize;
	}
	string getAppName()
	{
		return AppName.getString();
	}

	// Constructor(s)
	App(float AppIconSize, string AppName)
	{
		setAppSize(AppIconSize);
		setAppName(AppName);
		this->AppName.setCharacterSize(15);
		this->AppName.setFillColor(sf::Color::White);
		this->AppName.setOutlineThickness(1.f);
		this->AppName.setOutlineColor(sf::Color::Black);
	}

	// Destructor(s)
	~App()
	{
		delete AppBackground;
	}

};

class TempApp : public App
{
public:
	// Function(s)
	void Appear(){}
	void Disappear(){}

	// Constructor(s)
	TempApp() : App(3.3, "Notes")
	{
		AppBackground = new Tile(2);
		if (!textureIcon.loadFromFile("Data/Icons/NotesIcon.jpg"))
		{
			cout << "Unable to open the App icon of Notes.";
		}
		Icon.setTexture(&textureIcon);
		
	}

	// Constructor(s)
	~TempApp()
	{
	}
};

class ROA12
{
protected:
	DefaultSystem DefaultSetting;
	Tile *Home;
	sf::Texture backgroundImage;
	Notification* Notifications;
	Navigation* NavigationBar;

	TempApp *App_01;

	sf::RenderWindow* window;

public:
	void initiate()
	{
		while (window->isOpen())
		{
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();

				// SWIPING FUNCTION
				// Position will be set according to window not to whole screen.
				sf::Vector2f MousePosition(sf::Mouse::getPosition(*window));
				// Checking if MainBackground contain mouse or not.
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Home->Background.getGlobalBounds().contains(MousePosition) && !NavigationBar->Bar.getGlobalBounds().contains(MousePosition))
				{
					int* up = new int;
					int* down = new int;
					*up = 1;
					*down = 1;
					sf::Vector2f temp(sf::Mouse::getPosition());
					sf::Clock clock;
					sf::Time time = sf::seconds(1);
					while (clock.getElapsedTime().asSeconds() <= time.asSeconds() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						//cout << "x=" << sf::Mouse::getPosition().x << " y=" << sf::Mouse::getPosition().y << endl;
						if (sf::Mouse::getPosition().x == temp.x && sf::Mouse::getPosition().y > temp.y)
						{
							(*up)++;
						}
						else if (sf::Mouse::getPosition().x == temp.x && sf::Mouse::getPosition().y < temp.y)
						{
							(*down)++;
						}
					}
					cout << "UP: " << *up << endl;
					cout << "Down: " << *down << endl;
					if (*up > *down)
					{
						Notifications->Appear(Home->Background.getPosition().x, Home->Background.getPosition().y);
						window->draw(Notifications->Background);
						//Notifications.Background.setPosition(Home.Background.getPosition());
					}
					else if (*down > *up)
					{
						Notifications->Disappear();
						// Notifications.Background.setPosition(PreviousPositionOfNotificationBackground);
					}
					delete up, down;
				}


				/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
				Home.Background.setPosition(Home.Background.getPosition().x - 10, Home.Background.getPosition().y);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
				Home.Background.setPosition(Home.Background.getPosition().x + 10, Home.Background.getPosition().y);
				}*/
			}

			// Setting Positions
			NavigationBar->Appear(Home->Background.getPosition().x, Home->Background.getSize().y + Home->Background.getPosition().y);

			if (NavigationBar->BackIcon.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				BackButton();
				//Notifications->Disappear(PreviousPositionOfNotificationBackground.x, PreviousPositionOfNotificationBackground.y);
			}
			// if (NavigationBar->HomeIcon.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			// {
			// 	Notifications->Disappear(PreviousPositionOfNotificationBackground.x, PreviousPositionOfNotificationBackground.y);
			// }



			// Setting Positions 

			window->clear(sf::Color::White);
			window->draw(Home->Background);
			window->draw(App_01->Icon);
			window->draw(App_01->AppName);
			window->draw(Notifications->Background);
			window->draw(NavigationBar->Bar);
			window->draw(NavigationBar->BackIcon);
			window->draw(NavigationBar->HomeIcon);
			window->draw(NavigationBar->HomeIconSmall);
			window->draw(NavigationBar->RecentIcon);
			window->display();
		}


	}


	void BackButton()
	{
		int *tempId = new int;
		*tempId = WhoIsActiveNow;
		if (*tempId == 1)
		{
			Notifications->Disappear();
		}
		delete tempId;
	}

	// Constructor
	ROA12()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 800), "ROA12", sf::Style::Default);

		// Setting Home Screen
		Home = new Tile(0);
		if (!backgroundImage.loadFromFile("Data/Wallpaper/Wallpaper_01.jpg"))
		{
			cout << "Unable to open background image.";
		}
		Home->Background.setSize(sf::Vector2f(window->getSize().y * 0.467 * 0.84, window->getSize().y * 0.84));
		Home->Background.setTexture(&backgroundImage);
		Home->Background.setPosition(window->getSize().x / 2 - Home->Background.getSize().x / 2, window->getSize().y / 2 - Home->Background.getSize().y / 2);
		Home->Background.setOutlineThickness(8.f);
		Home->Background.setOutlineColor(sf::Color::Black);

		// Setting NavigationBar
		NavigationBar = new Navigation(Home->Background.getSize().x, Home->Background.getSize().y * 0.047);

		// Setting Notification
		Notifications = new Notification(1, Home->Background.getSize().x, Home->Background.getSize().y);
		Notifications->Background.setPosition(Home->Background.getPosition().x, Home->Background.getPosition().y - (Home->Background.getSize().y));
		Notifications->Background.setFillColor(DefaultSetting.getBackgroundColor());
		Notifications->setPreviousPosition(Notifications->Background.getPosition());

		// Setting App_01
		App_01 = new TempApp;
		App_01->Icon.setRadius(window->getSize().x * App_01->getAppSize() / 100.0);
		App_01->AppName.setFont(DefaultSetting.getSystemFonts());
		App_01->Icon.setPosition(Home->Background.getPosition().x + App_01->Icon.getRadius() / 2.0, Home->Background.getSize().y - App_01->Icon.getRadius() -  App_01->AppName.getGlobalBounds().height);
		App_01->AppName.setOrigin(App_01->AppName.getGlobalBounds().width / 2.f, App_01->AppName.getGlobalBounds().height / 2.f);
		App_01->AppName.setPosition(App_01->Icon.getPosition().x + (App_01->Icon.getRadius() / 2.f) * 2.f, App_01->Icon.getPosition().y + App_01->Icon.getRadius() * 215.f / 100.f);


	}

	// Destructor
	~ROA12()
	{
		delete window, Home, NavigationBar, Notifications, App_01;
	}
};




int main()
{
	ROA12 phone;
	phone.initiate();

	return 0;
}
