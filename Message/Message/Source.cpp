#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

int main()
{
	sf::Font font;
	if (!font.loadFromFile("Data/Fonts/ProductSans-Regular.ttf"))
	{
		cout << "Error!" << endl;
	}

	// window creation
	sf::RenderWindow window(sf::VideoMode(800, 800), "ROA12 - Message", sf::Style::Default);
	sf::RectangleShape MessageBackground(sf::Vector2f(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.84));
	MessageBackground.setPosition(window.getSize().x / 2 - MessageBackground.getSize().x / 2, window.getSize().y / 2 - MessageBackground.getSize().y / 2);
	MessageBackground.setOutlineThickness(8.f);
	MessageBackground.setOutlineColor(sf::Color::White);
	MessageBackground.setFillColor(sf::Color::White);

	// heading of message
	sf::RectangleShape name(sf::Vector2f(MessageBackground.getSize().x, MessageBackground.getSize().y * 0.2));
	name.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	name.setFillColor(sf::Color(93, 93, 55));
	name.setOutlineThickness(5.f);
	name.setOutlineColor(sf::Color::Black);

	sf::Text messagename;
	messagename.setFont(font);
	messagename.setCharacterSize(30);
	messagename.Bold;
	messagename.setFillColor(sf::Color::White);
	messagename.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	messagename.move(sf::Vector2f(name.getSize().x * 0.3, name.getSize().y * 0.3));
	messagename.setString("Message");

	sf::Image image;
	if (!(image.loadFromFile("Data/Icons/dpimage.png")))
	{
		cout << " Error!Cannot load image..." << endl;
	}

	sf::Texture imagetexture;
	imagetexture.loadFromImage(image);
	imagetexture.setSmooth(true);


	// chats, numbers and dps
	sf::RectangleShape dp1(sf::Vector2f(MessageBackground.getSize().x * 0.2, MessageBackground.getSize().y * 0.1));
	dp1.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	dp1.move(sf::Vector2f(0, name.getSize().y));
	dp1.setFillColor(sf::Color(51, 102, 0));
	dp1.setOutlineThickness(5.f);
	dp1.setOutlineColor(sf::Color::Black);

	sf::Sprite dp1sprite;
	dp1sprite.setScale(sf::Vector2f(0.201f, 0.231f));
	dp1sprite.setTexture(imagetexture);
	dp1sprite.setPosition(sf::Vector2f(dp1.getPosition()));

	sf::RectangleShape chat1(sf::Vector2f(MessageBackground.getSize().x * 0.8, MessageBackground.getSize().y * 0.1));
	chat1.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	chat1.move(sf::Vector2f(dp1.getSize().x, name.getSize().y));
	chat1.setFillColor(sf::Color(51, 102, 0));
	chat1.setOutlineThickness(5.f);
	chat1.setOutlineColor(sf::Color::Black);

	sf::Text number1;
	number1.setFont(font);
	number1.setCharacterSize(20);
	number1.Bold;
	number1.setFillColor(sf::Color::White);
	number1.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	number1.move(sf::Vector2f(dp1.getSize().x + (chat1.getSize().x * 0.2), name.getSize().y + (chat1.getSize().y * 0.3)));
	number1.setString("12345678000");

	sf::RectangleShape dp2(sf::Vector2f(MessageBackground.getSize().x * 0.2, MessageBackground.getSize().y * 0.1));
	dp2.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	dp2.move(sf::Vector2f(0, name.getSize().y + chat1.getSize().y));
	dp2.setFillColor(sf::Color(51, 102, 0));
	dp2.setOutlineThickness(5.f);
	dp2.setOutlineColor(sf::Color::Black);

	sf::Sprite dp2sprite;
	dp2sprite.setScale(sf::Vector2f(0.201f, 0.231f));
	dp2sprite.setTexture(imagetexture);
	dp2sprite.setPosition(sf::Vector2f(dp2.getPosition()));

	sf::RectangleShape chat2(sf::Vector2f(MessageBackground.getSize().x * 0.8, MessageBackground.getSize().y * 0.1));
	chat2.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	chat2.move(sf::Vector2f(dp2.getSize().x, name.getSize().y + chat1.getSize().y));
	chat2.setFillColor(sf::Color(51, 102, 0));
	chat2.setOutlineThickness(5.f);
	chat2.setOutlineColor(sf::Color::Black);

	sf::Text number2;
	number2.setFont(font);
	number2.setCharacterSize(20);
	number2.Bold;
	number2.setFillColor(sf::Color::White);
	number2.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	number2.move(sf::Vector2f(dp2.getSize().x + (chat2.getSize().x * 0.2), name.getSize().y + chat2.getSize().y + (chat2.getSize().y * 0.3)));
	number2.setString("12345678001");

	sf::RectangleShape dp3(sf::Vector2f(MessageBackground.getSize().x * 0.2, MessageBackground.getSize().y * 0.1));
	dp3.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	dp3.move(sf::Vector2f(0, name.getSize().y + (chat1.getSize().y * 2)));
	dp3.setFillColor(sf::Color(51, 102, 0));
	dp3.setOutlineThickness(5.f);
	dp3.setOutlineColor(sf::Color::Black);

	sf::Sprite dp3sprite;
	dp3sprite.setScale(sf::Vector2f(0.201f, 0.231f));
	dp3sprite.setTexture(imagetexture);
	dp3sprite.setPosition(sf::Vector2f(dp3.getPosition()));

	sf::RectangleShape chat3(sf::Vector2f(MessageBackground.getSize().x * 0.8, MessageBackground.getSize().y * 0.1));
	chat3.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	chat3.move(sf::Vector2f(dp3.getSize().x, name.getSize().y + (chat1.getSize().y * 2)));
	chat3.setFillColor(sf::Color(51, 102, 0));
	chat3.setOutlineThickness(5.f);
	chat3.setOutlineColor(sf::Color::Black);

	sf::Text number3;
	number3.setFont(font);
	number3.setCharacterSize(20);
	number3.Bold;
	number3.setFillColor(sf::Color::White);
	number3.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	number3.move(sf::Vector2f(dp3.getSize().x + (chat3.getSize().x * 0.2), name.getSize().y + (chat3.getSize().y * 2) + (chat3.getSize().y * 0.3)));
	number3.setString("12345678010");

	sf::RectangleShape dp4(sf::Vector2f(MessageBackground.getSize().x * 0.2, MessageBackground.getSize().y * 0.1));
	dp4.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	dp4.move(sf::Vector2f(0, name.getSize().y + (chat1.getSize().y * 3)));
	dp4.setFillColor(sf::Color(51, 102, 0));
	dp4.setOutlineThickness(5.f);
	dp4.setOutlineColor(sf::Color::Black);

	sf::Sprite dp4sprite;
	dp4sprite.setScale(sf::Vector2f(0.201f, 0.231f));
	dp4sprite.setTexture(imagetexture);
	dp4sprite.setPosition(sf::Vector2f(dp4.getPosition()));

	sf::RectangleShape chat4(sf::Vector2f(MessageBackground.getSize().x * 0.8, MessageBackground.getSize().y * 0.1));
	chat4.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	chat4.move(sf::Vector2f(dp3.getSize().x, name.getSize().y + (chat1.getSize().y * 3)));
	chat4.setFillColor(sf::Color(51, 102, 0));
	chat4.setOutlineThickness(5.f);
	chat4.setOutlineColor(sf::Color::Black);

	sf::Text number4;
	number4.setFont(font);
	number4.setCharacterSize(20);
	number4.Bold;
	number4.setFillColor(sf::Color::White);
	number4.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	number4.move(sf::Vector2f(dp4.getSize().x + (chat4.getSize().x * 0.2), name.getSize().y + (chat4.getSize().y * 3) + (chat4.getSize().y * 0.3)));
	number4.setString("12345678011");

	sf::RectangleShape dp5(sf::Vector2f(MessageBackground.getSize().x * 0.2, MessageBackground.getSize().y * 0.1));
	dp5.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	dp5.move(sf::Vector2f(0, name.getSize().y + (chat1.getSize().y * 4)));
	dp5.setFillColor(sf::Color(51, 102, 0));
	dp5.setOutlineThickness(5.f);
	dp5.setOutlineColor(sf::Color::Black);

	sf::Sprite dp5sprite;
	dp5sprite.setScale(sf::Vector2f(0.201f, 0.231f));
	dp5sprite.setTexture(imagetexture);
	dp5sprite.setPosition(sf::Vector2f(dp5.getPosition()));

	sf::RectangleShape chat5(sf::Vector2f(MessageBackground.getSize().x * 0.8, MessageBackground.getSize().y * 0.1));
	chat5.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	chat5.move(sf::Vector2f(dp3.getSize().x, name.getSize().y + (chat1.getSize().y * 4)));
	chat5.setFillColor(sf::Color(51, 102, 0));
	chat5.setOutlineThickness(5.f);
	chat5.setOutlineColor(sf::Color::Black);

	sf::Text number5;
	number5.setFont(font);
	number5.setCharacterSize(20);
	number5.Bold;
	number5.setFillColor(sf::Color::White);
	number5.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	number5.move(sf::Vector2f(dp5.getSize().x + (chat5.getSize().x * 0.2), name.getSize().y + (chat5.getSize().y * 4) + (chat5.getSize().y * 0.3)));
	number5.setString("12345678100");

	sf::RectangleShape dp6(sf::Vector2f(MessageBackground.getSize().x * 0.2, MessageBackground.getSize().y * 0.1));
	dp6.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	dp6.move(sf::Vector2f(0, name.getSize().y + (chat1.getSize().y * 5)));
	dp6.setFillColor(sf::Color(51, 102, 0));
	dp6.setOutlineThickness(5.f);
	dp6.setOutlineColor(sf::Color::Black);

	sf::Sprite dp6sprite;
	dp6sprite.setScale(sf::Vector2f(0.201f, 0.231f));
	dp6sprite.setTexture(imagetexture);
	dp6sprite.setPosition(sf::Vector2f(dp6.getPosition()));

	sf::RectangleShape chat6(sf::Vector2f(MessageBackground.getSize().x * 0.8, MessageBackground.getSize().y * 0.1));
	chat6.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	chat6.move(sf::Vector2f(dp3.getSize().x, name.getSize().y + (chat1.getSize().y * 5)));
	chat6.setFillColor(sf::Color(51, 102, 0));
	chat6.setOutlineThickness(5.f);
	chat6.setOutlineColor(sf::Color::Black);

	sf::Text number6;
	number6.setFont(font);
	number6.setCharacterSize(20);
	number6.Bold;
	number6.setFillColor(sf::Color::White);
	number6.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	number6.move(sf::Vector2f(dp6.getSize().x + (chat6.getSize().x * 0.2), name.getSize().y + (chat6.getSize().y * 5) + (chat6.getSize().y * 0.3)));
	number6.setString("12345678101");

	sf::RectangleShape dp7(sf::Vector2f(MessageBackground.getSize().x * 0.2, MessageBackground.getSize().y * 0.1));
	dp7.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	dp7.move(sf::Vector2f(0, name.getSize().y + (chat1.getSize().y * 6)));
	dp7.setFillColor(sf::Color(51, 102, 0));
	dp7.setOutlineThickness(5.f);
	dp7.setOutlineColor(sf::Color::Black);

	sf::Sprite dp7sprite;
	dp7sprite.setScale(sf::Vector2f(0.201f, 0.231f));
	dp7sprite.setTexture(imagetexture);
	dp7sprite.setPosition(sf::Vector2f(dp7.getPosition()));

	sf::RectangleShape chat7(sf::Vector2f(MessageBackground.getSize().x * 0.8, MessageBackground.getSize().y * 0.1));
	chat7.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	chat7.move(sf::Vector2f(dp3.getSize().x, name.getSize().y + (chat1.getSize().y * 6)));
	chat7.setFillColor(sf::Color(51, 102, 0));
	chat7.setOutlineThickness(5.f);
	chat7.setOutlineColor(sf::Color::Black);

	sf::Text number7;
	number7.setFont(font);
	number7.setCharacterSize(20);
	number7.Bold;
	number7.setFillColor(sf::Color::White);
	number7.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	number7.move(sf::Vector2f(dp7.getSize().x + (chat7.getSize().x * 0.2), name.getSize().y + (chat7.getSize().y * 6) + (chat7.getSize().y * 0.3)));
	number7.setString("12345678110");

	sf::RectangleShape dp8(sf::Vector2f(MessageBackground.getSize().x * 0.2, MessageBackground.getSize().y * 0.1));
	dp8.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	dp8.move(sf::Vector2f(0, name.getSize().y + (chat1.getSize().y * 7)));
	dp8.setFillColor(sf::Color(51, 102, 0));
	dp8.setOutlineThickness(5.f);
	dp8.setOutlineColor(sf::Color::Black);

	sf::RectangleShape chat8(sf::Vector2f(MessageBackground.getSize().x * 0.8, MessageBackground.getSize().y * 0.1));
	chat8.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	chat8.move(sf::Vector2f(dp3.getSize().x, name.getSize().y + (chat1.getSize().y * 7)));
	chat8.setFillColor(sf::Color(51, 102, 0));
	chat8.setOutlineThickness(5.f);
	chat8.setOutlineColor(sf::Color::Black);

	sf::Sprite dp8sprite;
	dp8sprite.setScale(sf::Vector2f(0.201f, 0.231f));
	dp8sprite.setTexture(imagetexture);
	dp8sprite.setPosition(sf::Vector2f(dp8.getPosition()));

	sf::Text number8;
	number8.setFont(font);
	number8.setCharacterSize(20);
	number8.Bold;
	number8.setFillColor(sf::Color::White);
	number8.setPosition(sf::Vector2f(MessageBackground.getPosition()));
	number8.move(sf::Vector2f(dp8.getSize().x + (chat8.getSize().x * 0.2), name.getSize().y + (chat8.getSize().y * 7) + (chat8.getSize().y * 0.3)));
	number8.setString("12345678111");

	sf::CircleShape newmessagebutton;
	newmessagebutton.setRadius(25);
	newmessagebutton.setFillColor(sf::Color(93, 93, 55));
	newmessagebutton.setPosition(sf::Vector2f(MessageBackground.getPosition()).x + MessageBackground.getSize().x * 0.80, MessageBackground.getPosition().y + MessageBackground.getSize().y * 0.85);

	sf::Text plus;
	plus.setFont(font);
	plus.setString("+");
	plus.setCharacterSize(60);
	plus.setFillColor(sf::Color::White);
	plus.setPosition(sf::Vector2f(newmessagebutton.getPosition().x + newmessagebutton.getRadius() * 0.37, newmessagebutton.getPosition().y - newmessagebutton.getRadius() * 0.68));


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(MessageBackground);
		window.draw(name);               window.draw(messagename);
		window.draw(dp1);                window.draw(chat1);        window.draw(number1);		window.draw(dp1sprite);
		window.draw(dp2);				 window.draw(chat2);		window.draw(number2);		window.draw(dp2sprite);
		window.draw(dp3);				 window.draw(chat3);		window.draw(number3);		window.draw(dp3sprite);
		window.draw(dp4);				 window.draw(chat4);		window.draw(number4);		window.draw(dp4sprite);
		window.draw(dp5);				 window.draw(chat5);		window.draw(number5);		window.draw(dp5sprite);
		window.draw(dp6);				 window.draw(chat6);		window.draw(number6);		window.draw(dp6sprite);
		window.draw(dp7);				 window.draw(chat7);		window.draw(number7);		window.draw(dp7sprite);
		window.draw(dp8);				 window.draw(chat8);		window.draw(number8);		window.draw(dp8sprite);
		window.draw(newmessagebutton);	 window.draw(plus);			
		window.display();
	}

	return 0;
}
