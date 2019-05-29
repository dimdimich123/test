#include "../library/lib.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <unistd.h>

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
                if (x > 201 && x < 602 && y > 405 && y < 458) {
                    return;
                }
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
                if (x > 0 && x < 800 && y > 0 && y < 500) {
                    return;
                }
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
    f = fopen("records.dat", "rb");

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

    std::ostringstream Score; // объявили переменную
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
                if (x > 13 && x < 145 && y > 436 && y < 480) {
                    return;
                }
                if (x > 339 && x < 785 && y > 439 && y < 479) {
                    fclose(f);
                    f = fopen("records.dat", "wb");
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
                if (x > 276 && x < 508 && y > 366 && y < 414) {
                    FILE* f;
                    f = fopen("records.dat", "ab");
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
                    f = fopen("records.dat", "ab");
                    strcpy(A.names, str);
                    A.lim = s;
                    fwrite(&A, sizeof(A), 1, f);
                    fclose(f);
                    return;
                }
                if (event.text.unicode < 128 && event.text.unicode != 8
                    && i < 16) {
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

int pole(int* B, int flag, int jk, int s)
{
    int j, ss, sk;
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

    Sprite backSP, fishSP;
    backSP.setTexture(backTX);
    backSP.setPosition(0, 0);
    fishSP.setTexture(fishTX);

    while (window.isOpen()) {
        fx = 10;
        fy = 10;
        ss = 0;
        sk = 0;
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 605 && x < 789 && y > 420 && y < 484)
                    return 1;

                for (int i = 10; i <= (60 * jk) + (10 * jk) - 60; i += 70) {
                    ss = 0;
                    for (int is = 10; is <= 430; is += 70) {
                        if (y > i && y < i + 60 && x > is && x < is + 60) {
                            if (B[sk] > ss && sk < jk) {
                                B[sk] = ss;
                                return 0;
                            }
                        }
                        ss++;
                    }
                    sk++;
                }
            }
        }
        window.clear();
        window.draw(backSP);
        window.draw(text);
        for (j = 0; j < B[0]; j++) {
            fishSP.setPosition(fx, fy);
            fx += 70;
            window.draw(fishSP);
        }
        fx = 10;
        fy = 80;
        for (j = 0; j < B[1]; j++) {
            fishSP.setPosition(fx, fy);
            fx += 70;
            window.draw(fishSP);
        }
        fx = 10;
        fy = 150;
        for (j = 0; j < B[2]; j++) {
            fishSP.setPosition(fx, fy);
            fx += 70;
            window.draw(fishSP);
        }
        if (jk == 4) {
            fx = 10;
            fy = 220;
            for (j = 0; j < B[3]; j++) {
                fishSP.setPosition(fx, fy);
                fx += 70;
                window.draw(fishSP);
            }
        }
        window.draw(t1); //рисую этот текст
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
                if (x > 252 && x < 641 && y > 197 && y < 243) {
                    standart(3);
                    break;
                }
                if (x > 248 && x < 554 && y > 278 && y < 327) {
                    standart(4);
                    break;
                }
                if (x > 251 && x < 410 && y > 418 && y < 467) {
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
