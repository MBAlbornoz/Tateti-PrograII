#include "clsCasilla.h"

//=============================================================================
// METODO    : int clsCasilla::init()
// ACCION    : Seleccciona que imagen va a ser cargada
// PARAMETROS: Nada
// DEVUELVE  : Retorna el tipo de error. return error.get();
//-----------------------------------------------------------------------------
int clsCasilla::init()
{
    error.set(0);

    setItems(4);
    setI(0);
    error.set(load("IMAGENES/TABLERO/casilla.png"));
    if(error.get())return error.get();
    setI(3);
    error.set(load("IMAGENES/TABLERO/casillaSelec.png"));
    if(error.get())return error.get();
    setI(1);
    error.set(load("IMAGENES/TABLERO/Jugador1.png"));
    if(error.get())return error.get();
    setI(2);
    error.set(load("IMAGENES/TABLERO/Jugador2.png"));
    if(error.get())return error.get();

    return error.get();
}


