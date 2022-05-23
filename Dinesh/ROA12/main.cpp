#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <iterator>

using namespace std;

// GLOBAL SCOPE
int WhoIsActiveNow = 0;
int RecentCount = 1;
int* RecentArray = new int[RecentCount];

void changeRecent(int ID)
{
	bool* found = new bool;
	*found = 0;
	for (int i = 0; i < RecentCount; i++)
	{
		if (ID == RecentArray[i])
		{
			*found = 1;
			int* j = new int(i);
			int* temp = new int(0);

			while (*j != RecentCount - 1)
			{
				*temp = RecentArray[(*j) + 1];
				RecentArray[(*j) + 1] = ID;
				RecentArray[*j] = *temp;
				(*j)++;
			}
			delete j, temp;
			// int *temp = new int;
			// *temp = RecentArray[i];
			// RecentArray[i] = RecentArray[RecentCount - 1];
			// RecentArray[RecentCount - 1] = *temp;
			// delete temp;
			break;
		}
	}
	if (*found != 1)
	{
		int* temp = new int[RecentCount];
		for (int i = 0; i < RecentCount; i++)
		{
			temp[i] = RecentArray[i];
		}
		RecentCount++;
		RecentArray = new int[RecentCount];
		for (int i = 0; i < RecentCount - 1; i++)
		{
			RecentArray[i] = temp[i];
		}
		RecentArray[RecentCount - 1] = ID;
		delete temp;


	}
	cout << "arr  ";
	for (int i = 0; i < RecentCount; i++)
	{
		cout << RecentArray[i] << ", ";
	}
	cout << endl;
	delete found;

	WhoIsActiveNow = ID;
}

// CLASSES
class DefaultSystem
{
public:
	bool DarkTheme;
	sf::Color FontColor;
	sf::Color BackgroundColor;
	sf::Color BackgroundTileColor;
	sf::Font font;
	time_t *MyTime;

public:
	// CONSTRUCTOR(S)
	DefaultSystem()
	{
		FontColor = sf::Color::Black;
		//BackgroundColor = sf::Color::White;
		BackgroundColor = sf::Color(255, 255, 255, 200);
		// BackgroundColor = sf::Color(48, 49, 44, 120);
		DarkTheme = 0;
		if (!font.loadFromFile("Data/Fonts/ProductSans-Regular.ttf"))
		{
			cout << "Unable to load the fonts from file.";
		}
		BackgroundTileColor = sf::Color::White;
		MyTime = new time_t;
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
	bool IsActive;
	// CONSTRUCTOR(S)
	Tile(int ID) {
		this->ID = ID;
		setIsActive(0);
	}
	Tile(int ID, bool IsActive)
	{
		this->ID = ID;
		this->IsActive = IsActive;
	}
	// DESTRUCTOR(S)
	~Tile()
	{}

	// SETTER(S)
	void setID(int ID)
	{
		this->ID = ID;
	}
	void setIsActive(bool IsActive)
	{
		this->IsActive = IsActive;
	}

	// GETTER(S)
	int getID(void)
	{
		return ID;
	}
	bool getIsActive(void)
	{
		return IsActive;
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
		changeRecent(getID());
		Background.setPosition(x, y);
	}
	void Disappear()
	{
		Background.setPosition(getPreviousPositionX(), getPreviousPositionY());

		//WhoIsActiveNow = 0;
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
	Notification(int ID, float x, float y) :Tile(ID, false)
	{
		Background.setSize(sf::Vector2f(x, y));
	}

	// Destructor
	~Notification()
	{}
};

class Recent : public Tile
{
public:
	void Appear(sf::Vector2f Position, DefaultSystem* Temp)
	{
		//Background.setFillColor(Temp->getBackgroundColor());
		Background.setFillColor(Temp->BackgroundColor);
		changeRecent(getID());
		Background.setPosition(Position);
	}


	void Disappear() {
		Background.setPosition(Background.getPosition().x, Background.getPosition().y + Background.getSize().y * 1.20f);


	}

	void DrawMe(sf::RenderWindow* window)
	{
		window->draw(Background);
		int* tempCount = new int(0);
		for (int i = 0; i < RecentCount; i++)
		{
			if (RecentArray[i] != 0 && RecentArray[i] != 1 && RecentArray[i] != 2)
			{
				(*tempCount)++;
			}
		}
		int* tempArray = new int[*tempCount];
		int* count = new int(0);
		int* j = new int(0);
		while (*count != *tempCount)
		{
			if (RecentArray[*j] != 0 && RecentArray[*j] != 1 && RecentArray[*j] != 2)
			{
				tempArray[*count] = RecentArray[*j];
				(*count)++;
			}
			(*j)++;
		}


		sf::RectangleShape* Box = new sf::RectangleShape[*tempCount];
		sf::Texture* tempTex = new sf::Texture;
		//sf::RectangleShape* Box = new sf::RectangleShape[2];
		//for (int i = 0; i < 2; i++)
		for (int i = 0; i < *tempCount; i++)
		{
			if (i % 2 == 0)
			{
				Box[i].setSize(sf::Vector2f(Background.getSize().x * 0.45, Background.getSize().y * 0.25));
				//	Box[i].setFillColor(sf::Color::Red);
				Box[i].setPosition(Background.getPosition().x + Background.getSize().x * 0.03, Background.getPosition().y + Background.getSize().y * 0.01);
			}
			else
			{
				Box[i].setSize(sf::Vector2f(Background.getSize().x * 0.45, Background.getSize().y * 0.25));
				Box[i].setFillColor(sf::Color::Blue);
				Box[i].setPosition(Box[0].getPosition().x + Box[0].getPosition().x * 0.6f, Box[0].getPosition().y);
			}
			switch (tempArray[i])
			{
			case 3:
				if (!tempTex->loadFromFile("Data/Icons/NotesIcon.jpg"))
				{
					cout << "Unable to open the cover ofr the notes." << endl;
				}
				Box[i].setTexture(tempTex);

			default:
				break;
			}
			window->draw(Box[i]);
		}

		delete tempCount, tempArray, count, j, tempTex;
	}

	// Constructor
	Recent(int ID, sf::Vector2f Size) :Tile(ID, 0) // 0 indicates that currently recent is active
	{
		Background.setSize(sf::Vector2f(Size.x, Size.y - Size.y * 0.047));
	}

	// Destructor
	~Recent() {}
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
	Tile* AppBackground;
	sf::Text AppName;


	// Function(s)
	virtual void Appear(sf::Vector2f, sf::RenderWindow*) = 0;
	virtual int Disappear() = 0;
	virtual void AppearanceAnimation(sf::RenderWindow*) = 0;
	// Setter(s)
	void setAppName(string AppName)
	{
		this->AppName.setString(AppName);
	}

	// Getter(s)
	string getAppName()
	{
		return AppName.getString();
	}

	// Constructor(s)
	App(float AppIconSize, string AppName)
	{
		Icon.setRadius(AppIconSize);
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
	void Appear(sf::Vector2f HomePosition, sf::RenderWindow* window)
	{
		changeRecent(AppBackground->getID());
		AppBackground->Background.setSize(sf::Vector2f(window->getSize().y * 0.467 * 0.84, window->getSize().y * 0.84));
		AppBackground->Background.setPosition(HomePosition);;
		AppearanceAnimation(window);
	}
	int Disappear()
	{
		return 0;
	}
	void AppearanceAnimation(sf::RenderWindow* window)
	{
		sf::RectangleShape* Cover = new sf::RectangleShape;
		sf::RectangleShape* CoverPicture = new sf::RectangleShape;

		Cover->setSize(sf::Vector2f(AppBackground->Background.getSize().x, AppBackground->Background.getSize().y - AppBackground->Background.getSize().y * 0.047));
		CoverPicture->setSize(sf::Vector2f(AppBackground->Background.getSize().x, AppBackground->Background.getSize().y - AppBackground->Background.getSize().y * 0.047));
		sf::Texture* texture = new sf::Texture;
		if (!texture->loadFromFile("Data/Icons/NotesIcon.jpg"))
		{
			cout << "Unable to open the cover ofr the notes." << endl;
		}
		Cover->setFillColor(sf::Color(254, 177, 59));
		CoverPicture->setTexture(texture);
		CoverPicture->setScale(1.0f, 0.5f);
		Cover->setPosition(AppBackground->Background.getPosition().x, AppBackground->Background.getPosition().y);
		CoverPicture->setPosition(AppBackground->Background.getPosition().x, AppBackground->Background.getPosition().y + Cover->getSize().y / 4.f);



		sf::Time* timer = new sf::Time;
		*timer = sf::milliseconds(1000);
		sf::Clock* clock = new sf::Clock;
		while (clock->getElapsedTime().asMilliseconds() < timer->asMilliseconds())
		{
			window->draw(*Cover);
			window->draw(*CoverPicture);
			window->display();
			//cout << "wait ";
		}

		//delete Cover, timer, clock;
	}
	// Constructor(s)
	TempApp(float AppIconSize) : App(AppIconSize, "Notes")
	{
		AppBackground = new Tile(3);
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
	DefaultSystem* DefaultSetting;
	Tile* Home;
	sf::Texture backgroundImage;
	Notification* Notifications;
	Navigation* NavigationBar;
	Recent* Recents;

	TempApp* App_01;

	sf::RenderWindow* window;

	// Google Bar
	sf::Texture *GoogleGTexture;
	sf::CircleShape* GoogleG;
	sf::CircleShape *GoogleGBackground;
	sf::RectangleShape* GoogleSearch;
	sf::Texture* GoogleMicTexture;
	sf::CircleShape* GoogleMic;
	sf::CircleShape* GoogleMicBackground;

	// Time Clock
	sf::Text* TimeWidget;

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
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Home->Background.getGlobalBounds().contains(MousePosition) && !NavigationBar->Bar.getGlobalBounds().contains(MousePosition) && Home->getIsActive() == 1 && !App_01->Icon.getGlobalBounds().contains(MousePosition))
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
						Deactivate(WhoIsActiveNow);
						Notifications->Appear(Home->Background.getPosition().x, Home->Background.getPosition().y);
						Activate(WhoIsActiveNow);
						window->draw(Notifications->Background);

						//Notifications.Background.setPosition(Home.Background.getPosition());
					}
					// else if (*down > *up)
					// {
					// 	Deactivate(Notifications->getID());
					// 	Notifications->Disappear();
					// 	Activate(RecentArray[RecentCount - 2]);
					// 	// Notifications.Background.setPosition(PreviousPositionOfNotificationBackground);
					// }
					delete up, down;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && App_01->Icon.getGlobalBounds().contains(MousePosition) && Home->getIsActive() == 1)
				{
					Deactivate(WhoIsActiveNow);
					App_01->Appear(Home->Background.getPosition(), window);
					Activate(WhoIsActiveNow);
				}
				else if (NavigationBar->BackIcon.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					BackButton();
					//Notifications->Disappear(PreviousPositionOfNotificationBackground.x, PreviousPositionOfNotificationBackground.y);
				}
				else if (NavigationBar->RecentIcon.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && WhoIsActiveNow != 2)
				{
					Deactivate(WhoIsActiveNow);
					Recents->Appear(Home->Background.getPosition(), DefaultSetting);
					Activate(WhoIsActiveNow);
				}
			}

			// Setting Positions
			NavigationBar->Appear(Home->Background.getPosition().x, Home->Background.getSize().y + Home->Background.getPosition().y);

			// if (NavigationBar->HomeIcon.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			// {
			// 	Notifications->Disappear(PreviousPositionOfNotificationBackground.x, PreviousPositionOfNotificationBackground.y);
			// }



			// Setting Positions 

		/*	for (int i = 0; i < RecentCount; i++)
			{
				cout << RecentArray[i] << ", ";
			}*/
			/*cout << GoogleG->getPosition().x << " " << GoogleG->getPosition().y;
			*/
			cout << "" << TimeWidget->getPosition().x << " " << TimeWidget->getPosition().y << endl;
			window->clear(sf::Color::White);
			window->draw(Home->Background);
			window->draw(*GoogleSearch);
			window->draw(*GoogleGBackground);
			window->draw(*GoogleMicBackground);
			window->draw(*GoogleG);
			window->draw(*GoogleMic);
			window->draw(*TimeWidget);
			window->draw(App_01->Icon);
			window->draw(App_01->AppName);
			window->draw(Notifications->Background);
			window->draw(NavigationBar->Bar);
			window->draw(NavigationBar->BackIcon);
			window->draw(NavigationBar->HomeIcon);
			window->draw(NavigationBar->HomeIconSmall);
			window->draw(NavigationBar->RecentIcon);
		//	window->draw(*GoogleGBackground);
	


			Recents->DrawMe(window);
			//window->draw(Recents->Background);

			window->display();
		}



	}


	void BackButton()
	{
		int* tempId = new int;
		*tempId = WhoIsActiveNow;
		if (*tempId == 1)
		{
			Deactivate(Notifications->getID());
			Notifications->Disappear();

			int* temp = new int[RecentCount - 1];
			for (int i = 0; i < RecentCount; i++)
			{
				if (RecentArray[i] != 1)
				{
					temp[i] = RecentArray[i];

				}
			}
			RecentCount--;
			RecentArray = new int[RecentCount];
			for (int i = 0; i < RecentCount; i++)
			{
				RecentArray[i] = temp[i];
			}
			delete temp;

			Activate(RecentArray[RecentCount - 1]);
		}
		else if (*tempId == 2)
		{
			Deactivate(Recents->getID());
			Recents->Disappear();
			int* temp = new int[RecentCount - 1];
			for (int i = 0; i < RecentCount; i++)
			{
				if (RecentArray[i] != 2)
				{
					temp[i] = RecentArray[i];
				}
			}
			RecentCount--;
			RecentArray = new int[RecentCount];
			for (int i = 0; i < RecentCount; i++)
			{
				RecentArray[i] = temp[i];
			}
			delete temp;
			Activate(RecentArray[RecentCount - 1]);

		}
		else if (*tempId == 3)
		{
			if (App_01->Disappear() == 0)
			{
				Deactivate(App_01->AppBackground->getID());
				App_01->Disappear();
				Activate(RecentArray[RecentCount - 2]);
			}
		}
		delete tempId;
	}
	void RecentButton() {}
	void Deactivate(int ID)
	{
		switch (ID)
		{
		case 0:
			Home->setIsActive(false);
			break;
		case 1:
			Notifications->setIsActive(false);
			break;
		case 2:
			Recents->setIsActive(false);
			break;
		case 3:
			App_01->AppBackground->setIsActive(false);
			break;
		default:
			break;
		}
		// int *temp = new int(0);
		// for (int i = RecentCount-2; i >= 0; i--)
		// {
		// 	if (RecentArray[i] != 1 && RecentArray[i] != 2)
		// 	{
		// 		RecentArray[i] = * temp;
		// 		break;
		// 	}
		// }
		// Activate(*temp);
		// delete temp;
	}
	void Activate(int ID)
	{
		int* temp = new int(0);
		switch (ID)
		{
		case 0:

			/*
			*temp = RecentArray[RecentCount - 1];
			for (int i = 0; i < RecentCount; i++)
			{
			if (RecentArray[i] == 0)
			{
			RecentArray[i] = *temp;
			RecentArray[RecentCount - 1] = 0;
			break;
			}
			}
			*/
			Home->setIsActive(true);

			break;
			// case 1:
			// 	Notifications->setIsActive(true);
			// 	break;
			// case 2:
			// 	Recents->setIsActive(true);
			// 	break;

		case 2:
			Recents->setIsActive(true);
			break;
		default:
			break;
		}
		changeRecent(ID);
		delete temp;
	}
	
	// Constructor
	ROA12()
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 800), "ROA12", sf::Style::Default);
		//window = new sf::RenderWindow(sf::VideoMode(800, 800), "ROA12", sf::Style::Fullscreen);

		// Setting Default System
		DefaultSetting = new DefaultSystem;

		// Setting Home Screen
		RecentArray[0] = 0;
		Home = new Tile(0, true);
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
		//Notifications->Background.setPosition(Home->Background.getPosition());
		Notifications->Background.setFillColor(DefaultSetting->getBackgroundColor());
		Notifications->setPreviousPosition(Notifications->Background.getPosition());

		// Setting Recent
		Recents = new Recent(2, Home->Background.getSize());
		Recents->Background.setPosition(Notifications->Background.getPosition());
		Recents->Background.setFillColor(DefaultSetting->getBackgroundColor());
		
		// Setting App_01
		App_01 = new TempApp(Home->Background.getSize().y * 0.047 * 0.8f);
		App_01->AppName.setFont(DefaultSetting->getSystemFonts());
//		App_01->Icon.setPosition(Home->Background.getPosition().x + App_01->Icon.getRadius() / 2.0, Home->Background.getSize().y - App_01->Icon.getRadius() - App_01->AppName.getGlobalBounds().height);
		App_01->Icon.setPosition(Home->Background.getPosition().x + App_01->Icon.getRadius() / 2.0, Home->Background.getSize().y - 2.5f* (App_01->Icon.getRadius() + App_01->AppName.getGlobalBounds().height) );
		App_01->AppName.setOrigin(App_01->AppName.getGlobalBounds().width / 2.f, App_01->AppName.getGlobalBounds().height / 2.f);
		App_01->AppName.setPosition(App_01->Icon.getPosition().x + (App_01->Icon.getRadius() / 2.f) * 2.f, App_01->Icon.getPosition().y + App_01->Icon.getRadius() * 215.f / 100.f);

		// Google's Search Bar Setting
		GoogleGTexture = new sf::Texture;
		if (!GoogleGTexture->loadFromFile("Data/Icons/Google.png"))
		{
			cout << "Unable to load the Goolge G Icon" << endl;
		}
		GoogleG = new sf::CircleShape;
		GoogleG->setRadius(Home->Background.getSize().y * 0.047 * 0.6f);
		GoogleG->setTexture(GoogleGTexture);
		//GoogleG->setFillColor(sf::Color::Red);
		GoogleG->setPosition(Home->Background.getPosition().x + GoogleG->getRadius() / 1.6f, Home->Background.getSize().y - GoogleG->getRadius() * 0.8f);
		//GoogleGBackground->setPosition(GoogleG->getPosition());
		GoogleGBackground = new sf::CircleShape;
		GoogleGBackground->setRadius(Home->Background.getSize().y * 0.047 * 0.7f);
		GoogleGBackground->setPosition(Home->Background.getPosition().x + GoogleG->getRadius() / 2.f, Home->Background.getSize().y - GoogleG->getRadius());
		GoogleGBackground->setFillColor(DefaultSetting->BackgroundTileColor);

		GoogleSearch = new sf::RectangleShape;
		GoogleSearch->setSize(sf::Vector2f(Home->Background.getSize().x - Home->Background.getSize().x * 0.2f, Home->Background.getSize().y * 0.063f));
		GoogleSearch->setPosition(GoogleGBackground->getPosition().x + GoogleG->getRadius() , GoogleGBackground->getPosition().y+1.f);
		GoogleSearch->setFillColor(DefaultSetting->BackgroundTileColor);
		//GoogleSearch->setFillColor(sf::Color(0,0,255,120));

		GoogleMicTexture = new sf::Texture;
		if (!GoogleMicTexture->loadFromFile("Data/Icons/GoogleMIc.png"))
		{
			cout << "Unable to load the Goolge Mic Icon" << endl;
		}
		GoogleMic = new sf::CircleShape;
		GoogleMic->setRadius(Home->Background.getSize().y * 0.047 * 0.6f);
		GoogleMic->setTexture(GoogleMicTexture);
		//GoogleMic->setFillColor(sf::Color::Green);
		GoogleMic->setPosition(GoogleG->getPosition().x+ GoogleMic->getRadius()* 13.1f, GoogleG->getPosition().y);

		GoogleMicBackground = new sf::CircleShape;
		GoogleMicBackground->setRadius(Home->Background.getSize().y * 0.047 * 0.7f);
		GoogleMicBackground->setPosition(GoogleG->getPosition().x + 13.f * GoogleMic->getRadius(), GoogleG->getPosition().y - GoogleMic->getRadius() * 0.2);
		GoogleMicBackground->setFillColor(DefaultSetting->BackgroundTileColor);
	
		// Time Widget Setting
		TimeWidget = new sf::Text;
		TimeWidget->setString("1 2\n00");
		TimeWidget->setFont(DefaultSetting->font);
		TimeWidget->setFillColor(sf::Color::Red);
		TimeWidget->setCharacterSize(75);
		TimeWidget->setPosition(Home->Background.getPosition());

	}

	// Destructor
	~ROA12()
	{
		delete window, Home, DefaultSetting, NavigationBar, Notifications, Recents, App_01, GoogleG, GoogleGBackground, GoogleGTexture, GoogleMic, GoogleMicBackground, GoogleMicTexture, TimeWidget;
	}
};




int main()
{
	ROA12 phone;
	phone.initiate();

	return 0;
}
