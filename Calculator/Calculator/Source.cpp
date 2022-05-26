#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::Font sidefont;
    if (!sidefont.loadFromFile("Fonts/ARIAL.ttf"))
    {
        cout << "Error!" << endl;
    }

    sf::Font font;
    if (!font.loadFromFile("Data/Fonts/ProductSans-Regular.ttf"))
    {
        cout << "Error!" << endl;
    }

    // the main display

    sf::RenderWindow window(sf::VideoMode(800, 800), "ROA12 - Calculator", sf::Style::Default);
    sf::RectangleShape CalculatorBackground(sf::Vector2f(window.getSize().y * 0.467 * 0.84, window.getSize().y * 0.84));
    CalculatorBackground.setPosition(window.getSize().x / 2 - CalculatorBackground.getSize().x / 2, window.getSize().y / 2 - CalculatorBackground.getSize().y / 2);
    CalculatorBackground.setOutlineThickness(8.f);
    CalculatorBackground.setOutlineColor(sf::Color::Black);
    CalculatorBackground.setFillColor(sf::Color::Transparent);

    sf::RectangleShape display(sf::Vector2f(CalculatorBackground.getSize().x, CalculatorBackground.getSize().y * 0.25));
    display.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    display.setFillColor(sf::Color(93, 93, 55));

    sf::RectangleShape predict(sf::Vector2f(CalculatorBackground.getSize().x, CalculatorBackground.getSize().y * 0.0625));
    predict.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    predict.move(sf::Vector2f(0, display.getSize().y));
    predict.setFillColor(sf::Color(93, 93, 55));
    predict.setOutlineThickness(5.f);                 // can comment these lines to remove the outline of the prediction bar
    predict.setOutlineColor(sf::Color::Black);        // can comment these lines to remove the outline of the prediction bar


    // layer 1 of extra buttons

    sf::RectangleShape a(sf::Vector2f(CalculatorBackground.getSize().x, CalculatorBackground.getSize().y * 0.0625));
    a.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    a.move(sf::Vector2f(0, display.getSize().y + predict.getSize().y));
    a.setFillColor(sf::Color(52, 52, 24));

    sf::RectangleShape root(sf::Vector2f(CalculatorBackground.getSize().x * 0.17, CalculatorBackground.getSize().y * 0.0625));
    root.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    root.move(sf::Vector2f(0, display.getSize().y + predict.getSize().y));
    root.setFillColor(sf::Color::Transparent);

    sf::Text rootsign;
    rootsign.setFont(sidefont);
    rootsign.setCharacterSize(25);
    rootsign.setFillColor(sf::Color::White);
    rootsign.Bold;
    rootsign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    rootsign.move(sf::Vector2f(0, display.getSize().y + predict.getSize().y));
    rootsign.move(sf::Vector2f(root.getSize().x * 0.4, root.getSize().y * 0.2));
    rootsign.setString(L"√");

    sf::RectangleShape pi(sf::Vector2f(CalculatorBackground.getSize().x * 0.17, CalculatorBackground.getSize().y * 0.0625));
    pi.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    pi.move(sf::Vector2f(root.getSize().x + 0.2 * root.getSize().x, display.getSize().y + predict.getSize().y));
    pi.setFillColor(sf::Color::Transparent);

    sf::Text pisign;
    pisign.setFont(font);
    pisign.setCharacterSize(25);
    pisign.setFillColor(sf::Color::White);
    pisign.Bold;
    pisign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    pisign.move(sf::Vector2f(root.getSize().x + 0.2 * root.getSize().x, display.getSize().y + predict.getSize().y));
    pisign.move(sf::Vector2f(pi.getSize().x * 0.4, pi.getSize().y * 0.2));
    pisign.setString(L"π");

    sf::RectangleShape power(sf::Vector2f(CalculatorBackground.getSize().x * 0.17, CalculatorBackground.getSize().y * 0.0625));
    power.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    power.move(sf::Vector2f(root.getSize().x * 2 + 0.4 * root.getSize().x, display.getSize().y + predict.getSize().y));
    power.setFillColor(sf::Color::Transparent);

    sf::Text powersign;
    powersign.setFont(font);
    powersign.setCharacterSize(25);
    powersign.setFillColor(sf::Color::White);
    powersign.Bold;
    powersign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    powersign.move(sf::Vector2f(root.getSize().x * 2 + 0.4 * root.getSize().x, display.getSize().y + predict.getSize().y));
    powersign.move(sf::Vector2f(power.getSize().x * 0.4, power.getSize().y * 0.2));
    powersign.setString(L"^");

    sf::RectangleShape euler(sf::Vector2f(CalculatorBackground.getSize().x * 0.17, CalculatorBackground.getSize().y * 0.0625));
    euler.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    euler.move(sf::Vector2f(root.getSize().x * 3 + 0.6 * root.getSize().x, display.getSize().y + predict.getSize().y));
    euler.setFillColor(sf::Color::Transparent);

    sf::Text esign;
    esign.setFont(font);
    esign.setCharacterSize(25);
    esign.setFillColor(sf::Color::White);
    esign.Bold;
    esign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    esign.move(sf::Vector2f(root.getSize().x * 3 + 0.6 * root.getSize().x, display.getSize().y + predict.getSize().y));
    esign.move(sf::Vector2f(euler.getSize().x * 0.4, euler.getSize().y * 0.2));
    esign.setString("e");

    sf::RectangleShape factorial(sf::Vector2f(CalculatorBackground.getSize().x * 0.17, CalculatorBackground.getSize().y * 0.0625));
    factorial.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    factorial.move(sf::Vector2f(root.getSize().x * 4 + 0.8 * root.getSize().x, display.getSize().y + predict.getSize().y));
    factorial.setFillColor(sf::Color::Transparent);

    sf::Text factorialsign;
    factorialsign.setFont(font);
    factorialsign.setCharacterSize(25);
    factorialsign.setFillColor(sf::Color::White);
    factorialsign.Bold;
    factorialsign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    factorialsign.move(sf::Vector2f(root.getSize().x * 4 + 0.8 * root.getSize().x, display.getSize().y + predict.getSize().y));
    factorialsign.move(sf::Vector2f(factorial.getSize().x * 0.4, factorial.getSize().y * 0.2));
    factorialsign.setString("!");

    // layer 1 of main buttons

    sf::RectangleShape b(sf::Vector2f(CalculatorBackground.getSize().x, CalculatorBackground.getSize().y * 0.125));
    b.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    b.move(sf::Vector2f(0, display.getSize().y + predict.getSize().y * 2));
    b.setFillColor(sf::Color(52, 52, 24));

    sf::CircleShape clear(CalculatorBackground.getSize().y * 0.055);
    clear.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    clear.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 2)));
    clear.setFillColor(sf::Color(153, 234, 234));

    sf::Text clearsign;
    clearsign.setFont(font);
    clearsign.setCharacterSize(30);
    clearsign.setFillColor(sf::Color::Black);
    clearsign.Bold;
    clearsign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    clearsign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 2)));
    clearsign.move(sf::Vector2f(clear.getRadius() * 0.6, clear.getRadius() * 0.5));
    clearsign.setString("AC");

    sf::CircleShape bracket(CalculatorBackground.getSize().y * 0.055);
    bracket.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    bracket.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 2, display.getSize().y + (predict.getSize().y * 2)));
    bracket.setFillColor(sf::Color(188, 188, 143));

    sf::Text bracketsign;
    bracketsign.setFont(font);
    bracketsign.setCharacterSize(30);
    bracketsign.setFillColor(sf::Color::Black);
    bracketsign.Bold;
    bracketsign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    bracketsign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 2, display.getSize().y + (predict.getSize().y * 2)));
    bracketsign.move(sf::Vector2f(bracket.getRadius() * 0.8, bracket.getRadius() * 0.5));
    bracketsign.setString("()");

    sf::CircleShape percent(CalculatorBackground.getSize().y * 0.055);
    percent.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    percent.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 4, display.getSize().y + (predict.getSize().y * 2)));
    percent.setFillColor(sf::Color(188, 188, 143));

    sf::Text percentsign;
    percentsign.setFont(font);
    percentsign.setCharacterSize(30);
    percentsign.setFillColor(sf::Color::Black);
    percentsign.Bold;
    percentsign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    percentsign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 4, display.getSize().y + (predict.getSize().y * 2)));
    percentsign.move(sf::Vector2f(percent.getRadius() * 0.8, percent.getRadius() * 0.5));
    percentsign.setString(L"%");

    sf::CircleShape divide(CalculatorBackground.getSize().y * 0.055);
    divide.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    divide.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 6, display.getSize().y + (predict.getSize().y * 2)));
    divide.setFillColor(sf::Color(188, 188, 143));

    sf::Text dividesign;
    dividesign.setFont(font);
    dividesign.setCharacterSize(35);
    dividesign.setFillColor(sf::Color::Black);
    dividesign.Bold;
    dividesign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    dividesign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 6, display.getSize().y + (predict.getSize().y * 2)));
    dividesign.move(sf::Vector2f(divide.getRadius() * 0.8, divide.getRadius() * 0.5));
    dividesign.setString(L"÷");

    // layer 2 of main buttons

    sf::RectangleShape c(sf::Vector2f(CalculatorBackground.getSize().x, CalculatorBackground.getSize().y * 0.125));
    c.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    c.move(sf::Vector2f(0, display.getSize().y + predict.getSize().y * 4));
    c.setFillColor(sf::Color(52, 52, 24));

    sf::CircleShape seven(CalculatorBackground.getSize().y * 0.055);
    seven.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    seven.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 4)));
    seven.setFillColor(sf::Color(1, 14, 1));

    sf::Text sevensign;
    sevensign.setFont(font);
    sevensign.setCharacterSize(30);
    sevensign.setFillColor(sf::Color::White);
    sevensign.Bold;
    sevensign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    sevensign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 4)));
    sevensign.move(sf::Vector2f(seven.getRadius() * 0.8, seven.getRadius() * 0.5));
    sevensign.setString("7");

    sf::CircleShape eight(CalculatorBackground.getSize().y * 0.055);
    eight.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    eight.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + seven.getRadius() * 2, display.getSize().y + (predict.getSize().y * 4)));
    eight.setFillColor(sf::Color(1, 14, 1));

    sf::Text eightsign;
    eightsign.setFont(font);
    eightsign.setCharacterSize(30);
    eightsign.setFillColor(sf::Color::White);
    eightsign.Bold;
    eightsign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    eightsign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + seven.getRadius() * 2, display.getSize().y + (predict.getSize().y * 4)));
    eightsign.move(sf::Vector2f(eight.getRadius() * 0.8, eight.getRadius() * 0.5));
    eightsign.setString("8");

    sf::CircleShape nine(CalculatorBackground.getSize().y * 0.055);
    nine.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    nine.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 4, display.getSize().y + (predict.getSize().y * 4)));
    nine.setFillColor(sf::Color(1, 14, 1));

    sf::Text ninesign;
    ninesign.setFont(font);
    ninesign.setCharacterSize(30);
    ninesign.setFillColor(sf::Color::White);
    ninesign.Bold;
    ninesign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    ninesign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 4, display.getSize().y + (predict.getSize().y * 4)));
    ninesign.move(sf::Vector2f(nine.getRadius() * 0.8, nine.getRadius() * 0.5));
    ninesign.setString("9");

    sf::CircleShape multiply(CalculatorBackground.getSize().y * 0.055);
    multiply.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    multiply.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 6, display.getSize().y + (predict.getSize().y * 4)));
    multiply.setFillColor(sf::Color(188, 188, 143));

    sf::Text multiplysign;
    multiplysign.setFont(font);
    multiplysign.setCharacterSize(35);
    multiplysign.setFillColor(sf::Color::Black);
    multiplysign.Bold;
    multiplysign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    multiplysign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + clear.getRadius() * 6, display.getSize().y + (predict.getSize().y * 4)));
    multiplysign.move(sf::Vector2f(multiply.getRadius() * 0.8, multiply.getRadius() * 0.4));
    multiplysign.setString("x");

    // layer 3 of main buttons

    sf::RectangleShape d(sf::Vector2f(CalculatorBackground.getSize().x, CalculatorBackground.getSize().y * 0.125));
    d.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    d.move(sf::Vector2f(0, display.getSize().y + predict.getSize().y * 6));
    d.setFillColor(sf::Color(52, 52, 24));

    sf::CircleShape four(CalculatorBackground.getSize().y * 0.055);
    four.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    four.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 6)));
    four.setFillColor(sf::Color(1, 14, 1));

    sf::Text foursign;
    foursign.setFont(font);
    foursign.setCharacterSize(30);
    foursign.setFillColor(sf::Color::White);
    foursign.Bold;
    foursign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    foursign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 6)));
    foursign.move(sf::Vector2f(four.getRadius() * 0.8, four.getRadius() * 0.5));
    foursign.setString("4");

    sf::CircleShape five(CalculatorBackground.getSize().y * 0.055);
    five.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    five.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + four.getRadius() * 2, display.getSize().y + (predict.getSize().y * 6)));
    five.setFillColor(sf::Color(1, 14, 1));

    sf::Text fivesign;
    fivesign.setFont(font);
    fivesign.setCharacterSize(30);
    fivesign.setFillColor(sf::Color::White);
    fivesign.Bold;
    fivesign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    fivesign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + four.getRadius() * 2, display.getSize().y + (predict.getSize().y * 6)));
    fivesign.move(sf::Vector2f(five.getRadius() * 0.8, five.getRadius() * 0.5));
    fivesign.setString("5");

    sf::CircleShape six(CalculatorBackground.getSize().y * 0.055);
    six.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    six.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + four.getRadius() * 4, display.getSize().y + (predict.getSize().y * 6)));
    six.setFillColor(sf::Color(1, 14, 1));

    sf::Text sixsign;
    sixsign.setFont(font);
    sixsign.setCharacterSize(30);
    sixsign.setFillColor(sf::Color::White);
    sixsign.Bold;
    sixsign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    sixsign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + four.getRadius() * 4, display.getSize().y + (predict.getSize().y * 6)));
    sixsign.move(sf::Vector2f(six.getRadius() * 0.8, six.getRadius() * 0.5));
    sixsign.setString("6");

    sf::CircleShape minus(CalculatorBackground.getSize().y * 0.055);
    minus.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    minus.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + four.getRadius() * 6, display.getSize().y + (predict.getSize().y * 6)));
    minus.setFillColor(sf::Color(188, 188, 143));

    sf::Text minussign;
    minussign.setFont(font);
    minussign.setCharacterSize(40);
    minussign.setFillColor(sf::Color::Black);
    minussign.Bold;
    minussign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    minussign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + four.getRadius() * 6, display.getSize().y + (predict.getSize().y * 6)));
    minussign.move(sf::Vector2f(minus.getRadius() * 0.8, minus.getRadius() * 0.4));
    minussign.setString("-");

    // layer 4 of main buttons

    sf::RectangleShape e(sf::Vector2f(CalculatorBackground.getSize().x, CalculatorBackground.getSize().y * 0.125));
    e.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    e.move(sf::Vector2f(0, display.getSize().y + predict.getSize().y * 8));
    e.setFillColor(sf::Color(52, 52, 24));

    sf::CircleShape one(CalculatorBackground.getSize().y * 0.055);
    one.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    one.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 8)));
    one.setFillColor(sf::Color(1, 14, 1));

    sf::Text onesign;
    onesign.setFont(font);
    onesign.setCharacterSize(30);
    onesign.setFillColor(sf::Color::White);
    onesign.Bold;
    onesign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    onesign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 8)));
    onesign.move(sf::Vector2f(one.getRadius() * 0.8, one.getRadius() * 0.5));
    onesign.setString("1");

    sf::CircleShape two(CalculatorBackground.getSize().y * 0.055);
    two.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    two.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + one.getRadius() * 2, display.getSize().y + (predict.getSize().y * 8)));
    two.setFillColor(sf::Color(1, 14, 1));

    sf::Text twosign;
    twosign.setFont(font);
    twosign.setCharacterSize(30);
    twosign.setFillColor(sf::Color::White);
    twosign.Bold;
    twosign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    twosign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + one.getRadius() * 2, display.getSize().y + (predict.getSize().y * 8)));
    twosign.move(sf::Vector2f(two.getRadius() * 0.8, two.getRadius() * 0.5));
    twosign.setString("2");

    sf::CircleShape three(CalculatorBackground.getSize().y * 0.055);
    three.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    three.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + one.getRadius() * 4, display.getSize().y + (predict.getSize().y * 8)));
    three.setFillColor(sf::Color(1, 14, 1));

    sf::Text threesign;
    threesign.setFont(font);
    threesign.setCharacterSize(30);
    threesign.setFillColor(sf::Color::White);
    threesign.Bold;
    threesign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    threesign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + one.getRadius() * 4, display.getSize().y + (predict.getSize().y * 8)));
    threesign.move(sf::Vector2f(three.getRadius() * 0.8, three.getRadius() * 0.5));
    threesign.setString("3");

    sf::CircleShape plus(CalculatorBackground.getSize().y * 0.055);
    plus.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    plus.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + one.getRadius() * 6, display.getSize().y + (predict.getSize().y * 8)));
    plus.setFillColor(sf::Color(188, 188, 143));

    sf::Text plussign;
    plussign.setFont(font);
    plussign.setCharacterSize(35);
    plussign.setFillColor(sf::Color::Black);
    plussign.Bold;
    plussign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    plussign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + one.getRadius() * 6, display.getSize().y + (predict.getSize().y * 8)));
    plussign.move(sf::Vector2f(plus.getRadius() * 0.8, plus.getRadius() * 0.4));
    plussign.setString("+");

    // layer 5 of main buttons

    sf::RectangleShape f(sf::Vector2f(CalculatorBackground.getSize().x, CalculatorBackground.getSize().y * 0.125));
    f.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    f.move(sf::Vector2f(0, display.getSize().y + predict.getSize().y * 10));
    f.setFillColor(sf::Color(52, 52, 24));

    sf::CircleShape zero(CalculatorBackground.getSize().y * 0.055);
    zero.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    zero.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 10)));
    zero.setFillColor(sf::Color(1, 14, 1));

    sf::Text zerosign;
    zerosign.setFont(font);
    zerosign.setCharacterSize(30);
    zerosign.setFillColor(sf::Color::White);
    zerosign.Bold;
    zerosign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    zerosign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015, display.getSize().y + (predict.getSize().y * 10)));
    zerosign.move(sf::Vector2f(zero.getRadius() * 0.8, zero.getRadius() * 0.5));
    zerosign.setString("0");

    sf::CircleShape decimal(CalculatorBackground.getSize().y * 0.055);
    decimal.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    decimal.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + zero.getRadius() * 2, display.getSize().y + (predict.getSize().y * 10)));
    decimal.setFillColor(sf::Color(1, 14, 1));

    sf::Text decimalsign;
    decimalsign.setFont(font);
    decimalsign.setCharacterSize(30);
    decimalsign.setFillColor(sf::Color::White);
    decimalsign.Bold;
    decimalsign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    decimalsign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + zero.getRadius() * 2, display.getSize().y + (predict.getSize().y * 10)));
    decimalsign.move(sf::Vector2f(decimal.getRadius() * 0.9, decimal.getRadius() * 0.5));
    decimalsign.setString(".");

    sf::CircleShape backspace(CalculatorBackground.getSize().y * 0.055);
    backspace.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    backspace.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + zero.getRadius() * 4, display.getSize().y + (predict.getSize().y * 10)));
    backspace.setFillColor(sf::Color(1, 14, 1));

    sf::Text backspacesign;
    backspacesign.setFont(sidefont);
    backspacesign.setCharacterSize(30);
    backspacesign.setFillColor(sf::Color::White);
    backspacesign.Bold;
    backspacesign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    backspacesign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + zero.getRadius() * 4, display.getSize().y + (predict.getSize().y * 10)));
    backspacesign.move(sf::Vector2f(backspace.getRadius() * 0.7, backspace.getRadius() * 0.5));
    backspacesign.setString(L"←");

    sf::CircleShape equal(CalculatorBackground.getSize().y * 0.055);
    equal.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    equal.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + zero.getRadius() * 6, display.getSize().y + (predict.getSize().y * 10)));
    equal.setFillColor(sf::Color(255, 255, 102));

    sf::Text equalsign;
    equalsign.setFont(font);
    equalsign.setCharacterSize(35);
    equalsign.setFillColor(sf::Color::Black);
    equalsign.Bold;
    equalsign.setPosition(sf::Vector2f(CalculatorBackground.getPosition()));
    equalsign.move(sf::Vector2f(CalculatorBackground.getSize().y * 0.015 + zero.getRadius() * 6, display.getSize().y + (predict.getSize().y * 10)));
    equalsign.move(sf::Vector2f(equal.getRadius() * 0.8, equal.getRadius() * 0.5));
    equalsign.setString("=");




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(CalculatorBackground);
        window.draw(display);
        window.draw(predict);

        window.draw(a);
        window.draw(root);      window.draw(rootsign);
        window.draw(pi);        window.draw(pisign);
        window.draw(power);     window.draw(powersign);
        window.draw(euler);     window.draw(esign);
        window.draw(factorial); window.draw(factorialsign);

        window.draw(b);
        window.draw(clear);     window.draw(clearsign);
        window.draw(bracket);   window.draw(bracketsign);
        window.draw(percent);   window.draw(percentsign);
        window.draw(divide);    window.draw(dividesign);

        window.draw(c);
        window.draw(seven);     window.draw(sevensign);
        window.draw(eight);     window.draw(eightsign);
        window.draw(nine);      window.draw(ninesign);
        window.draw(multiply);  window.draw(multiplysign);

        window.draw(d);
        window.draw(four);      window.draw(foursign);
        window.draw(five);      window.draw(fivesign);
        window.draw(six);       window.draw(sixsign);
        window.draw(minus);     window.draw(minussign);

        window.draw(e);
        window.draw(one);       window.draw(onesign);
        window.draw(two);       window.draw(twosign);
        window.draw(three);     window.draw(threesign);
        window.draw(plus);      window.draw(plussign);

        window.draw(f);
        window.draw(zero);      window.draw(zerosign);
        window.draw(decimal);   window.draw(decimalsign);
        window.draw(backspace); window.draw(backspacesign);
        window.draw(equal);     window.draw(equalsign);

        window.display();
    }

    return 0;
}
