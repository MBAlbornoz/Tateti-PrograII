#include "clsFichas.h"
#include <clsSprite.h>
#include <clsEvent.h>
#include <clsError.h>

//=============================================================================
// METODO    : int clsFichas::init()
// ACCION    : elije el tipo tipo de imagen segun el jugador
// PARAMETROS: Nada
// DEVUELVE  : Retorna el tipo de error. return error.get();
//-----------------------------------------------------------------------------
int clsFichas::init()
{
    setItems(8);
    setI(0);
    error.set(load("IMAGENES/FICHAS/ficha1.png"));
    if(error.get()) return error.get();

    setI(1);
    error.set(load("IMAGENES/FICHAS/ficha2.png"));
    if(error.get()) return error.get();

    setI(2);
    error.set(load("IMAGENES/Ayuda.jpg"));
    if(error.get()) return error.get();

    setI(3);
    error.set(load("IMAGENES/Tablero/ganaste.jpg"));
    if(error.get()) return error.get();

     setI(4);
    error.set(load("IMAGENES/Tablero/empate.png"));
    if(error.get()) return error.get();

     setI(5);
    error.set(load("IMAGENES/Tablero/IDJugador1.png"));
    if(error.get()) return error.get();

     setI(6);
    error.set(load("IMAGENES/Tablero/IDJugador2.png"));
    if(error.get()) return error.get();

    setI(7);
    error.set(load("IMAGENES/Tablero/cPuntaje.png"));
    if(error.get()) return error.get();

    return error.get();

}

//=============================================================================
// METODO    : void clsFichas::primerEmoji(int x,int y)
// ACCION    : posiciona las ficha en la pantalla
// PARAMETROS: int x,int y
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsFichas::primerEmoji(int x,int y)
{
    setI(0);
    setX(x);
    setY(y);
}

//=============================================================================
// METODO    : void clsFichas::segundoEmoji(int x,int y)
// ACCION    : posiciona las ficha en la pantalla
// PARAMETROS: int x,int y
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsFichas::segundoEmoji(int x,int y)
{
    setI(1);
    setX(x);
    setY(y);
}

//=============================================================================
// METODO    : void clsFichas::ayuda(int x,int y)
// ACCION    : posiciona las ficha en la pantalla
// PARAMETROS: int x,int y
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsFichas::ayuda(int x,int y)
{
    setI(2);
    setX(x);
    setY(y);
}

//=============================================================================
// METODO    : void clsFichas::ganaste(int x,int y)
// ACCION    : posiciona las ficha en la pantalla
// PARAMETROS: int x,int y
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsFichas::ganaste(int x,int y)
{
    setI(3);
    setX(x);
    setY(y);
}

//=============================================================================
// METODO    : void clsFichas::empate(int x,int y)
// ACCION    : posiciona las ficha en la pantalla
// PARAMETROS: int x,int y
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsFichas::empate(int x,int y)
{
    setI(4);
    setX(x);
    setY(y);
}

//=============================================================================
// METODO    : void clsFichas::primerEmoji(int x,int y)
// ACCION    : posiciona las ficha en la pantalla
// PARAMETROS: int x,int y
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsFichas::idJugador2(int x,int y)
{
    setI(6);
    setX(x);
    setY(y);
}

//=============================================================================
// METODO    : void clsFichas::segundoEmoji(int x,int y)
// ACCION    : posiciona las ficha en la pantalla
// PARAMETROS: int x,int y
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsFichas::idJugador1(int x,int y)
{
    setI(5);
    setX(x);
    setY(y);
}


//=============================================================================
// METODO    : void clsFichas::segundoEmoji(int x,int y)
// ACCION    : posiciona las ficha en la pantalla
// PARAMETROS: int x,int y
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsFichas::pantPuntaje(int x,int y)
{
    setI(7);
    setX(x);
    setY(y);
}
