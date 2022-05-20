#include <SFML/Graphics.hpp>
#include<fstream>
#include <iostream>
using namespace std;

class Tile
{
public:
	//sf::RectangleShape Background;
	int ID;

	// CONSTRUCTOR(S)
	Tile()
	{}
	Tile(int ID)
	{
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

class Notes : protected Tile
{

public:
	//sf::RectangleShape PhoneBackground(sf::Vector2f(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.84));
	string title;
	int ID;

public:
	void set_title(string title)
	{
		this->title = title;
	}
	string get_title()
	{
		return this->title;
	}
	void set_ID(int ID)
	{
		this->ID = ID;
	}
	int get_ID()
	{
		this->ID;
	}
	void createfile(int ID)
	{
		setID(ID);
		string name;
		cout << "Enter the name of the file : " << endl;
		getline(cin, name);
		set_title(name);
		ofstream newfile;
		newfile.open(title.c_str(), ios::out);
		if (!newfile)
		{
			cout << "File creation failed";
		}
		else
		{
			string* notes = new string;
			getline(cin, *notes);
			newfile << *notes;
			newfile.close();
		}
	}

	void readfile()
	{
		// Reading from file
		ifstream newfile;
		newfile.open(title.c_str(), ios::in);
		string data;
		while (getline(newfile, data))
		{
			cout << data;
			if (newfile.eof())
			{
				break;
			}
		}
		newfile.close();
	}
	//Constructor
	Notes(int ID)
	{

	}
	//Destructor
	~Notes()
	{}
	// SETTER(S)
	//void setID(int ID)
	//{
	//	this->ID = ID;
	//}
	//// GETTER(S)
	//int getID(void)
	//{
	//	return ID;
	//}

};


int main()
{
	//sf::RenderWindow window(sf::VideoMode(200, 200), "Notes", sf::Style::Fullscreen);
	sf::Font sidefont;
	if (!sidefont.loadFromFile("Data/Fonts/ProductSans-Light.ttf"))
	{
		cout << "Error! Font cannot be loaded..." << endl;
	}

	sf::RenderWindow window(sf::VideoMode(800, 700), "Notes");
	sf::RectangleShape NotesBackground(sf::Vector2f(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.84));
	NotesBackground.setPosition(window.getSize().x / 2 - NotesBackground.getSize().x / 2, window.getSize().y / 2 - NotesBackground.getSize().y / 2);
	NotesBackground.setOutlineThickness(3.f);
	NotesBackground.setOutlineColor(sf::Color::Magenta);
	NotesBackground.setFillColor(sf::Color::White);


	sf::RectangleShape Titlebar(sf::Vector2f(NotesBackground.getSize().x, NotesBackground.getSize().y * 0.10));
	Titlebar.setPosition(sf::Vector2f(NotesBackground.getPosition()));
	Titlebar.setFillColor(sf::Color(3, 3, 3));
	
	sf::Text Title;
	Title.setFont(sidefont);
	Title.setString("Notepad");
	Title.setCharacterSize(20);
	Title.setFillColor(sf::Color::White);
	Title.Bold;
	Title.setPosition(sf::Vector2f(Titlebar.getPosition().x + Titlebar.getSize().x * 0.04, Titlebar.getPosition().y + Titlebar.getSize().y * 0.3));

	sf::RectangleShape Image(sf::Vector2f(NotesBackground.getSize().x, NotesBackground.getSize().y * 0.25));
	Image.setPosition(sf::Vector2f(NotesBackground.getPosition().x , NotesBackground.getPosition().y + NotesBackground.getSize().y * 0.10));
	Image.setFillColor(sf::Color::Blue);

	sf::RectangleShape SavedNotes(sf::Vector2f(NotesBackground.getSize().x, NotesBackground.getSize().y * 0.65));
	SavedNotes.setPosition(sf::Vector2f(NotesBackground.getPosition().x, NotesBackground.getPosition().y + NotesBackground.getSize().y * 0.35));
	SavedNotes.setFillColor(sf::Color::Transparent);

	sf::Image image;
	if (!(image.loadFromFile("Data/Images/notesimage15.jpg")))
	{
		std::cout << "Error! Cannot load image...";
	}

	sf::Texture imagetexture;
	imagetexture.loadFromImage(image);
	imagetexture.setSmooth(true);
	
	sf::Sprite imagesprite;
	imagesprite.setScale(sf::Vector2f(0.961f, 0.831f));
	imagesprite.setTexture(imagetexture);
	imagesprite.setPosition(sf::Vector2f(Image.getPosition()));

	sf::CircleShape newnotesbutton;
	newnotesbutton.setRadius(25);
	newnotesbutton.setFillColor(sf::Color(3, 3, 3));
	newnotesbutton.setPosition(sf::Vector2f(NotesBackground.getPosition()).x + NotesBackground.getSize().x * 0.40 , NotesBackground.getPosition().y + NotesBackground.getSize().y * 0.85);

	sf::Text plus;
	plus.setFont(sidefont);
	plus.setString("+");
	plus.setCharacterSize(60);
	plus.setFillColor(sf::Color::White);
	plus.setPosition(sf::Vector2f(newnotesbutton.getPosition().x + newnotesbutton.getRadius() * 0.37, newnotesbutton.getPosition().y - newnotesbutton.getRadius() * 0.68 ));
		
	
		
		sf::Vector2f MousePosition(sf::Mouse::getPosition(window));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && newnotesbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			cout << "CLICKED";

			sf::RectangleShape Newfile(sf::Vector2f(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.84));
			Newfile.setPosition(window.getSize().x / 2 - NotesBackground.getSize().x / 2, window.getSize().y / 2 - NotesBackground.getSize().y / 2);
			Newfile.setOutlineThickness(3.f);
			Newfile.setOutlineColor(sf::Color::Magenta);
			Newfile.setFillColor(sf::Color::White);

			sf::RectangleShape Titlebarnew(sf::Vector2f(Newfile.getSize().x, Newfile.getSize().y * 0.10));
			Titlebarnew.setPosition(sf::Vector2f(Newfile.getPosition()));
			Titlebarnew.setFillColor(sf::Color(3, 3, 3));

			sf::RectangleShape Backicon(sf::Vector2f(Titlebarnew.getSize().x * 0.20, Titlebarnew.getSize().y));
			Backicon.setPosition(sf::Vector2f(Titlebarnew.getPosition()));
			Backicon.setFillColor(sf::Color(sf::Color(3, 3, 3)));

			sf::Image backiconimage;
			if (!(backiconimage.loadFromFile("Data/Images/Backicon.png")))
			{
				std::cout << "Error! Cannot load image...";
			}

			sf::Texture backiconimagetexture;
			backiconimagetexture.loadFromImage(backiconimage);
			backiconimagetexture.setSmooth(true);

			sf::Sprite backiconimagesprite;
			backiconimagesprite.setScale(sf::Vector2f(0.03f, 0.03f));
			backiconimagesprite.setTexture(backiconimagetexture);
			backiconimagesprite.setPosition(sf::Vector2f(Backicon.getPosition().x + Backicon.getSize().x * 0.30, Backicon.getPosition().y + Backicon.getSize().y * 0.20));


			sf::RectangleShape tickicon(sf::Vector2f(Titlebarnew.getSize().x * 0.20, Titlebarnew.getSize().y));
			tickicon.setPosition(sf::Vector2f(Titlebarnew.getPosition().x + Titlebarnew.getSize().x * 0.80, Titlebarnew.getPosition().y));
			tickicon.setFillColor(sf::Color(sf::Color(3, 3, 3)));

			sf::Image tickiconimage;
			if (!(tickiconimage.loadFromFile("Data/Images/tickicon.png")))
			{
				std::cout << "Error! Cannot load image...";
			}

			sf::Texture tickiconimagetexture;
			tickiconimagetexture.loadFromImage(tickiconimage);
			tickiconimagetexture.setSmooth(true);

			sf::Sprite tickiconimagesprite;
			tickiconimagesprite.setScale(sf::Vector2f(0.05f, 0.05f));
			tickiconimagesprite.setTexture(tickiconimagetexture);
			tickiconimagesprite.setPosition(sf::Vector2f(tickicon.getPosition().x + tickicon.getSize().x * 0.30, tickicon.getPosition().y + tickicon.getSize().y * 0.20));

			ofstream filecollection;
			filecollection.open("filecollection.txt", ios::out);
			filecollection.write("0", ios::beg);

			while (1)
			{
				//create name
				std::string name = "file_" + std::to_string(i) + ".txt"; // C++11 for std::to_string 
				//create file
				std::ofstream file(name);
				//if not C++11 then std::ostream file(name.c_str());
				//then do with file
				i++;
		}
		//fstream newfile;
		//newfile.open(name.c_str(), ios::out);
		//if (!newfile)
		//{
		//	cout << "File creation failed";
		//}
		//else
		//{
		//	string* notes = new string;
		//	cout << "Enter characters : " << endl;
		//	getline(cin, *notes);
		//	newfile << *notes;
		//	newfile.close();
		//}*/
//	}


	
	while (window.isOpen())
	{
		sf::Event event;
		/*ofstream newfile;
		newfile.open((string)filename, ios::out);
		if (!newfile)
		{
			cout << "File creation failed";
		}*/
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered)
			{
				filename += event.text.unicode;
				filenametext.setString(filename);
			}

			/*if (event.type == sf::Event::TextEntered)
			{
				filedata += event.text.unicode;
				filetext.setString(filedata);
			}*/

			else if (event.type == sf::Event::Closed)
				window.close();
		}
		//newfile.close();
		
		window.clear(sf::Color::White);
		window.draw(NotesBackground);
		/*window.draw(Titlebar);
		window.draw(Title);
		window.draw(Image);
		window.draw(SavedNotes);
		window.draw(imagesprite);
		window.draw(newnotesbutton);
		window.draw(plus);*/

			window.draw(Newfile);
			window.draw(Titlebarnew);
			window.draw(Backicon);
			window.draw(backiconimagesprite);
			window.draw(tickicon);
			window.draw(tickiconimagesprite);
		//window.draw(filetext);
			//window.draw(data);
			//window.draw(cursor);
	//	window.draw(Backicon);
		//window.draw(Saveicon);
		window.display();
	}
}