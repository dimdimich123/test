#include "../library/lib.h"
#include "game.h"
int a = 75, b = 10;
using namespace sf;
extern RenderWindow window;

void lose()
{
    int x, y;
    Vector2i mousexy;
    Image backIM;
    backIM.loadFromFile("../src/images/wood.png");

    Texture backTX;
    backTX.loadFromImage(backIM);

    Sprite backSP;
    backSP.setTexture(backTX);
    backSP.setPosition(0, 0);

    Font font;
    font.loadFromFile("../src/font/16872.ttf");
    Text t1, text;
    t1.setFont(font);
    t1.setString(L"Выйти в меню");
    t1.setCharacterSize(60);
    t1.setPosition(200, 390);
    text.setFont(font);
    text.setCharacterSize(100);
    text.setString(L"Вы проиграли");
    text.setPosition(80, 80);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (t1.getGlobalBounds().contains(x, y))
                    return;
            }
        }
        window.clear();
        window.draw(backSP);
        window.draw(t1);
        window.draw(text);
        window.display();
    }
}

void manual()
{
    int x, y;
    Vector2i mousexy;
    Image backIM, rulesIM;
    backIM.loadFromFile("../src/images/wood.png");
    rulesIM.loadFromFile("../src/images/rules.png");

    Texture backTX, rulesTX;
    backTX.loadFromImage(backIM);
    rulesTX.loadFromImage(rulesIM);

    Sprite backSP, rulesSP;
    backSP.setTexture(backTX);
    backSP.setPosition(0, 0);
    rulesSP.setTexture(rulesTX);
    rulesSP.setPosition(0, 0);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (rulesSP.getGlobalBounds().contains(x, y))
                    return;
            }
        }
        window.clear();
        window.draw(backSP);
        window.draw(rulesSP);
        window.display();
    }
}

void recordsmenu()
{
    struct S A;
    FILE* f;
    f = fopen("../records.dat", "rb");

    int x, y, iy, i;
    Vector2i mousexy;
    Image backIM;
    backIM.loadFromFile("../src/images/wood.png");

    Texture backTX;
    backTX.loadFromImage(backIM);

    Sprite backSP;
    backSP.setTexture(backTX);
    backSP.setPosition(0, 0);

    Font font;
    font.loadFromFile("../src/font/16872.ttf");
    Text text, t1, t2, t3, t4, t5, t6;
    text.setFont(font);
    t1.setFont(font);
    t2.setFont(font);
    t3.setFont(font);
    t4.setFont(font);
    t5.setFont(font);
    t6.setFont(font);
    text.setString(L"Рекорды");
    t1.setString(L"Назад");
    t2.setString(L"Очистить рекорды");
    t4.setString(L"Имя");
    t5.setString(L"Ходы");
    text.setCharacterSize(60);
    t1.setCharacterSize(50);
    t2.setCharacterSize(50);
    t3.setCharacterSize(25);
    t4.setCharacterSize(50);
    t5.setCharacterSize(35);
    t6.setCharacterSize(25);
    text.setPosition(250, 10);
    t1.setPosition(10, 425);
    t2.setPosition(340, 425);
    t4.setPosition(100, 70);
    t5.setPosition(490, 70);

    std::ostringstream Score;
    std::ostringstream Num;

    while (window.isOpen()) {
        iy = 120;
        i = 1;
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (t1.getGlobalBounds().contains(x, y))
                    return;
                if (t2.getGlobalBounds().contains(x, y)) {
                    fclose(f);
                    f = fopen("../records.dat", "wb");
                    fclose(f);
                    return;
                }
            }
        }

        window.clear();
        window.draw(backSP);
        window.draw(text);
        window.draw(t1);
        window.draw(t2);
        window.draw(t4);
        window.draw(t5);
        fread(&A, sizeof(A), 1, f);
        while (!feof(f) && i < 11) {
            Score.str(std::string());
            Num.str(std::string());
            Score << A.lim;
            Num << i++;
            t6.setString(Score.str());
            t3.setString(Num.str() + ". " + A.names);
            t6.setPosition(510, iy);
            t3.setPosition(70, iy);
            window.draw(t3);
            window.draw(t6);
            iy += 30;
            fread(&A, sizeof(A), 1, f);
        }
        rewind(f);
        window.display();
    }
}

void record(int s)
{
    struct S A;
    int x, y;
    Vector2i mousexy;
    Image backIM;
    backIM.loadFromFile("../src/images/wood.png");

    Texture backTX;
    backTX.loadFromImage(backIM);

    Sprite backSP;
    backSP.setTexture(backTX);
    backSP.setPosition(0, 0);

    Font font;
    font.loadFromFile("../src/font/16872.ttf");
    Text text, t1, name("", font, 70);
    text.setFont(font);
    text.setString(L"Введите ваше имя");
    text.setCharacterSize(80);
    text.setPosition(45, 50);
    t1.setFont(font);
    t1.setString(L"Принять");
    t1.setCharacterSize(60);
    t1.setPosition(275, 350);
    name.setPosition(100, 175);

    int i = 0;
    char str[16] = {0};
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (t1.getGlobalBounds().contains(x, y)) {
                    FILE* f;
                    f = fopen("../records.dat", "ab");
                    strcpy(A.names, str);
                    A.lim = s;
                    fwrite(&A, sizeof(A), 1, f);
                    fclose(f);
                    return;
                }
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8 && i > 0) {
                    str[--i] = '\0';
                    name.setString(str);
                    break;
                }
                if (event.text.unicode == 13) {
                    FILE* f;
                    f = fopen("../records.dat", "ab");
                    strcpy(A.names, str);
                    A.lim = s;
                    fwrite(&A, sizeof(A), 1, f);
                    fclose(f);
                    return;
                }
                if (event.text.unicode < 128 && event.text.unicode != 8
                    && i < 15) {
                    str[i] = static_cast<char>(event.text.unicode);
                    i++;
                    name.setString(str);
                }
            }
        }
        window.clear();
        window.draw(backSP);
        window.draw(text);
        window.draw(t1);
        window.draw(name);
        window.display();
    }
}

int hod(int* B, std::vector<sf::Sprite>& fish, int x, int y)
{
    int ss = 0, sk = 0;
    for (int i = 0; i < 19; i++, ss++) {
        if (ss >= B[sk]) {
            sk++;
            ss = 0;
        }
        if (ss >= B[sk]) {
            sk++;
            ss = 0;
        }
        if (ss >= B[sk]) {
            sk++;
            ss = 0;
        }
        if (fish[i].getGlobalBounds().contains(x, y)) {
            B[sk] = ss;
            return 0;
        }
    }
    return 3;
}

int pole(int* B, int flag, int jk, int s)
{
    int j, z, iss;
    int x, y;
    int fx = 0, fy = 0;
    Vector2i mousexy;

    Image backIM, fishIM;
    backIM.loadFromFile("../src/images/wood.png");
    fishIM.loadFromFile("../src/images/fishka2.png");

    Font font;
    font.loadFromFile("../src/font/16872.ttf");
    Text text, t1;
    text.setFont(font);
    t1.setFont(font);
    t1.setCharacterSize(50);
    text.setString(L"Назад");
    text.setCharacterSize(70);
    text.setPosition(600, 400);

    std::ostringstream Score;
    Score << s;
    t1.setString(L"Сделано ходов: " + Score.str());
    t1.setPosition(25, 420);

    Texture backTX, fishTX;
    backTX.loadFromImage(backIM);
    fishTX.loadFromImage(fishIM);

    std::vector<sf::Sprite> fish(19, sf::Sprite(fishTX));
    Sprite backSP;
    backSP.setTexture(backTX);
    backSP.setPosition(0, 0);
    while (window.isOpen()) {
        iss = 0;
        fx = b;
        fy = b;
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (text.getGlobalBounds().contains(x, y))
                    return 1;
                z = hod(B, fish, x, y);
                if (z == 0)
                    return z;
            }
        }
        window.clear();
        window.draw(backSP);
        window.draw(text);
        for (j = 0; j < B[0]; j++) {
            fish[iss].setPosition(fx, fy);
            fx += a;
            window.draw(fish[iss]);
            iss++;
        }
        fx = b;
        fy += a;
        for (j = 0; j < B[1]; j++) {
            fish[iss].setPosition(fx, fy);
            fx += a;
            window.draw(fish[iss]);
            iss++;
        }
        fx = b;
        fy += a;
        for (j = 0; j < B[2]; j++) {
            fish[iss].setPosition(fx, fy);
            fx += a;
            window.draw(fish[iss]);
            iss++;
        }
        if (jk == 4) {
            fx = b;
            fy += a;
            for (j = 0; j < B[3]; j++) {
                fish[iss].setPosition(fx, fy);
                fx += a;
                window.draw(fish[iss]);
                iss++;
            }
        }
        window.draw(t1);
        window.display();
        if (flag == 0) {
            usleep(1000000);
            return 0;
        }
    }
    return 0;
}

void difficulty()
{
    int x, y;
    Vector2i mousexy;
    Image backIM;
    backIM.loadFromFile("../src/images/wood.png");

    Texture backTX;
    backTX.loadFromImage(backIM);

    Sprite backSP;
    backSP.setTexture(backTX);
    backSP.setPosition(0, 0);

    Font font;
    font.loadFromFile("../src/font/16872.ttf");
    Text text, t1, t2, t3;
    text.setFont(font);
    t1.setFont(font);
    t2.setFont(font);
    t3.setFont(font);
    text.setString(L"Режимы игры");
    t1.setString(L"Стандартный");
    t2.setString(L"Мариенбад");
    t3.setString(L"Назад");
    text.setCharacterSize(100);
    t1.setCharacterSize(60);
    t2.setCharacterSize(60);
    t3.setCharacterSize(60);
    text.setPosition(100, 20);
    t1.setPosition(250, 180);
    t2.setPosition(250, 260);
    t3.setPosition(250, 400);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (t1.getGlobalBounds().contains(x, y)) {
                    standart(3);
                    break;
                }
                if (t2.getGlobalBounds().contains(x, y)) {
                    standart(4);
                    break;
                }
                if (t3.getGlobalBounds().contains(x, y)) {
                    return;
                }
            }
        }
        window.clear();
        window.draw(backSP);
        window.draw(text);
        window.draw(t1);
        window.draw(t2);
        window.draw(t3);
        window.display();
    }
}

int winner(int* B, int w, int jk)
{
    if (w) {
        if (jk == 3) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0) {
                return 1;
            }
        }
        if (jk == 4) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0) {
                return 1;
            }
        }
    }
    if (w == 0) {
        if (jk == 3) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0) {
                return 0;
            }
        }
        if (jk == 4) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0) {
                return 0;
            }
        }
    }
    return 2;
}
