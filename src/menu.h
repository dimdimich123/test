#ifndef SRC_MENU_H
#define SRC_MENU_H
void manual();
void recordsmenu();
void record(int s);
int winner(int* B, int w, int jk);
int pole(int* B, int flag, int jk, int s);
void difficulty();
void lose();
int hod(int* B, std::vector<sf::Sprite>& fish, int x, int y);
#endif
