#include "EstablecerConsola.hpp"

//*************************************************************************************************************************
void CambiarCursor(EstadoCursor estado, ModoCursor modo /* = NORMAL*/)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info = {modo,estado};
	SetConsoleCursorInfo(consoleHandle, &info);
}
void MoverCursor(short x, short y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
