#pragma once
#include <iostream>
#include <conio.h>			//_kbhit
#include <Windows.h>		//размеры консоли
#include <vector>

const int FIELD_WIDTH = 50 + 2;
const int FIELD_HEIGHT = 35 + 1;


void setCurcorPosition(int x, int y);

struct Point {
    int x;
    int y;
};
class Figure
{
private:
    std::vector<Point> figure;
public:
    void pushPosition(int x_pos, int y_pos)
    {
        Point tmp;
        tmp.x = x_pos;
        tmp.y = y_pos;
        figure.push_back(tmp);
    }

    void drawFigure()
    {
        for (int i = 0; i < figure.size(); ++i)
        {
            setCurcorPosition(figure[i].x, figure[i].y);
            std::cout << "*";
        }
    }

    void eraseFigure()
    {
        for (int i = 0; i < figure.size(); ++i)
        {
            setCurcorPosition(figure[i].x, figure[i].y);
            std::cout << " ";
        }
    }

    void moveDown()
    {
        for (int i = 0; i < figure.size(); ++i)
            figure[i].y++;
    }
    void moveLeft()
    {
        for (int i = 0; i < figure.size(); ++i)
            figure[i].x--;
    }
    void moveRight()
    {
        for (int i = 0; i < figure.size(); ++i)
            figure[i].x++;
    }
    void moveUp()
    {
        for (int i = 0; i < figure.size(); ++i)
            figure[i].y--;
    }

    void generateFigure()
    {
        pushPosition(5, 0);
        pushPosition(6, 0);
        pushPosition(5, 1);
        pushPosition(6, 1);
    }
};



class GameField : public Figure
{
private:
    std::vector<std::vector<int>> board;
public:


    void drawFields(int width, int height)
    {
        //for (int i = 0; i < height - 1; ++i)				//рисование левой колонки
        //	std::cout << '#' << std::endl;

        //for (int i = 0; i < width; ++i)						//рисование нижней полоски
        //	std::cout << '#';

        //for (int i = 0; i < height; ++i)					//рисование правой колонки
        //{
        //	setCurcorPosition(width , i);
        //	std::cout << '#';
        //}

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 1)
                    std::cout << "#";
                else if (board[i][j] == 0)
                    std::cout << ' ';
            }
            std::cout << "\n";
        }



    }



    void spawnFigure()
    {
        this->board;
    }

    void generateVector(int width, int height)
    {
        std::vector<int> tmp;
        tmp.push_back(1);
        for (int i = 1; i < width - 1; ++i)
            tmp.push_back(0);
        tmp.push_back(1);

        for (int i = 0; i < height - 1; ++i)
            board.push_back(tmp);

        tmp.clear();
        for (int i = 0; i < width; ++i)
            tmp.push_back(1);
        board.push_back(tmp);
    }

    void playGame()
    {
        Figure fig;
        fig.generateFigure();

        int x = 5, y = 5;

        while (true)
        {
            while (!_kbhit())
            {
                fig.eraseFigure();
                fig.moveDown();
                fig.drawFigure();
                Sleep(200);

            }

            char c = _getch();

            switch (c)
            {
                case 72:		//вверх
                {
                    fig.eraseFigure();
                    fig.moveUp();
                    break;
                }
                case 80:		//вниз
                {
                    fig.eraseFigure();
                    fig.moveDown();
                    break;
                }
                case 75:		//влево
                {
                    fig.eraseFigure();
                    fig.moveLeft();
                    break;
                }
                case 77:		//вправо
                {
                    fig.eraseFigure();
                    fig.moveRight();
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










