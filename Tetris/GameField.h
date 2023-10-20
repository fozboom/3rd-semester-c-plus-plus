//
// Created by Даниель Гнетецкий on 20.10.23.
//

#ifndef UNTITLED_GAMEFIELD_H
#define UNTITLED_GAMEFIELD_H


#include "Game.h"

struct Figure {
    int x;
    int y;
};

class Tetris {
public:

private:

};

class GameField: public Game
{
private:
public:
    void setCurcorPosition(int x, int y)
    {
        COORD p = { x,  y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    }
    void drawFields(int width, int height)
    {
        for (int i = 0; i < height - 1; ++i)				//рисование левой колонки
            std::cout << '#' << std::endl;

        for (int i = 0; i < width; ++i)						//рисование нижней полоски
            std::cout << '#';

        for (int i = 0; i < height; ++i)					//рисование правой колонки
        {
            setCurcorPosition(width , i);
            std::cout << '#';
        }



    }

    void playGame()
    {
        int x = 5, y = 5;

        while (true)
        {
            while (!_kbhit())
            {
                setCurcorPosition(x, y);
                std::cout << "X";
            }

            char c = _getch();

            switch (c)
            {
                case 72:		//вверх
                {
                    y--;
                    break;
                }
                case 80:		//вниз
                {
                    y++;
                    break;
                }
                case 75:		//влево
                {
                    x--;
                    break;
                }
                case 77:		//вправо
                {
                    x++;
                    break;
                }
                    setCurcorPosition(x, y);
                    std::cout << "X";

            }
            if (c == 'a')
                break;
        }

    }
};




#endif //UNTITLED_GAMEFIELD_H
