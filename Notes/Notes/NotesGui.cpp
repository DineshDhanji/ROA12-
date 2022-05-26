#include <SFML/Graphics.hpp>
#include<fstream>
#include <iostream>
using namespace std;

int main()
{
	sf::Font sidefont;
	if (!sidefont.loadFromFile("Data/Fonts/ProductSans-Light.ttf"))
	{
		cout << "Error! Font cannot be loaded..." << endl;
	}

	sf::RenderWindow window(sf::VideoMode(800, 800), "Notes");
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
	Image.setPosition(sf::Vector2f(NotesBackground.getPosition().x, NotesBackground.getPosition().y + NotesBackground.getSize().y * 0.10));
	//Image.setFillColor(sf::Color::Blue);

	sf::RectangleShape SavedNotes(sf::Vector2f(NotesBackground.getSize().x, NotesBackground.getSize().y * 0.65));
	SavedNotes.setPosition(sf::Vector2f(NotesBackground.getPosition().x, NotesBackground.getPosition().y + NotesBackground.getSize().y * 0.35));
	SavedNotes.setFillColor(sf::Color::Transparent);

	sf::Texture image;
	if (!(image.loadFromFile("Data/Wallpaper/notesimage15.jpeg")))
	{
		std::cout << "Error! Cannot load image...";
	}
	Image.setTexture(&image);

	/*sf::Texture imagetexture;
	imagetexture.loadFromImage(image);
	imagetexture.setSmooth(true);

	sf::Sprite imagesprite;
	imagesprite.setScale(sf::Vector2f(0.961f, 0.831f));
	imagesprite.setTexture(imagetexture);
	imagesprite.setPosition(sf::Vector2f(Image.getPosition()));*/

	sf::CircleShape newnotesbutton;
	newnotesbutton.setRadius(25);
	newnotesbutton.setFillColor(sf::Color(3, 3, 3));
	newnotesbutton.setPosition(sf::Vector2f(NotesBackground.getPosition()).x + NotesBackground.getSize().x * 0.40, NotesBackground.getPosition().y + NotesBackground.getSize().y * 0.85);

	sf::Text plus;
	plus.setFont(sidefont);
	plus.setString("+");
	plus.setCharacterSize(60);
	plus.setFillColor(sf::Color::White);
	plus.setPosition(sf::Vector2f(newnotesbutton.getPosition().x + newnotesbutton.getRadius() * 0.37, newnotesbutton.getPosition().y - newnotesbutton.getRadius() * 0.68));


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

	



	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::White);
		window.draw(NotesBackground);
		window.draw(Titlebar);
		window.draw(Title);
		window.draw(Image);
		window.draw(SavedNotes);
		//window.draw(imagesprite);
		window.draw(newnotesbutton);
		window.draw(plus);

		/*window.draw(Newfile);
		window.draw(Titlebarnew);
		window.draw(Backicon);
		window.draw(backiconimagesprite);
		window.draw(tickicon);
		window.draw(tickiconimagesprite);*/
		
		window.display();
	}
}