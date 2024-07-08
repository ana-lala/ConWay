#ifndef ESTABLECERCONSOLA_HPP_INCLUDED
#define ESTABLECERCONSOLA_HPP_INCLUDED
#include <windows.h>
#include <conio.h>


enum EstadoCursor{
	APAGADO,    /**< Cursor no visible */
	ENCENDIDO   /**< Cursor visible */
};


/** Modos o tama&ntilde;os del cursor */
enum ModoCursor{
	MINI = 1,       /**< Tama&ntilde;o de cursor peque&ntilde;o */
	NORMAL = 40,    /**< Tama&ntilde;o de cursor mediano  */
	SOLIDO = 80     /**< Tama&ntilde;o de cursor grande */
};


void CambiarCursor(EstadoCursor estado, ModoCursor modo /* = NORMAL*/);
void MoverCursor(short x, short y);

#endif // ESTABLECERCONSOLA_HPP_INCLUDED
