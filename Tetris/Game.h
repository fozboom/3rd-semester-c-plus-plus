//
// Created by Даниель Гнетецкий on 20.10.23.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H



#include <iostream>
#include <conio.h>			//_kbhit
#include <Windows.h>		//размеры консоли
#include <vector>

const int FIELD_WIDTH = 50;
const int FIELD_HEIGHT = 35;

#include "GameField.h"
class Game
{
private:
    std::vector<std::vector<int>> board;
public:


    void spawnFigure()
    {

    }
};




#endif //UNTITLED_GAME_H
