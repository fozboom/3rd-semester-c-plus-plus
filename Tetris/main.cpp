#include "Game.h"


int main()
{
    HWND hWindowConsole = GetConsoleWindow();							//получить дискриптор и стать указателем на окно
    RECT r;																//создать структуру для хранения координат окна
    GetWindowRect(hWindowConsole, &r);									//получение текущей позиции
    MoveWindow(hWindowConsole, r.left, r.top, 700, 900, TRUE);			//изменение размеров окна
    GameField x;





    x.generateVector(FIELD_WIDTH, FIELD_HEIGHT);
    x.drawFields(FIELD_WIDTH,FIELD_HEIGHT);
    x.playGame();

    std::cout << "\n\n\n\n\n\n\n\n\n";


}
