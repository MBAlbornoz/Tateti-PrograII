#include "clsBoton.h"

//=============================================================================
// METODO    : init(clsScreen *scr)
// ACCION    : inicializa los botones del juego
// PARAMETROS: clsScreen *scr
// DEVUELVE  : int -> codigo Error del Juego
//-----------------------------------------------------------------------------
int clsBoton::init(clsScreen *scr)
{
    this->screen=scr;
    setItems(5);
    setI(0);
    error.set(load("IMAGENES/Menu/Boton1.png"));
    if(error.get()) return error.get();

    setI(1);
    error.set(load("IMAGENES/Menu/Boton2.png"));
    if(error.get()) return error.get();

    setI(2);
    error.set(load("IMAGENES/Menu/Boton3.png"));
    if(error.get()) return error.get();

    setI(3);
    error.set(load("IMAGENES/Menu/Boton4.png"));
    if(error.get()) return error.get();
    return error.get();
}

//=============================================================================
// METODO    : void clsBoton::jugar()
// ACCION    : inicializa el boton jugar en la posicion de pantalla
// PARAMETROS: Nada.
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsBoton::jugar()
{
    setI(0);
    setX(350);
    setY(150);
}
//=============================================================================
// METODO    : void clsBoton::puntaje()
// ACCION    : inicializa el boton puntaje en la posicion de pantalla
// PARAMETROS: Nada.
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsBoton::puntaje()
{
    setI(1);
    setX(350);
    setY(253);
}
//=============================================================================
// METODO    : void clsBoton::ayuda()
// ACCION    : inicializa el boton ayuda en la posicion de pantalla
// PARAMETROS: Nada.
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsBoton::ayuda()
{
    setI(2);
    setX(350);
    setY(356);
}

//=============================================================================
// METODO    : void clsBoton::salir()
// ACCION    : inicializa el boton salir en la posicion de pantalla
// PARAMETROS: Nada.
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsBoton::salir()
{
    setI(3);
    setX(350);
    setY(459);
}


//=============================================================================
// METODO    : bool clsBoton::wasClick(int X,int Y)
// ACCION    : verifica los eventos de Mouse en la pantalla
// PARAMETROS: int X,int
// DEVUELVE  : true o false.
//-----------------------------------------------------------------------------
bool clsBoton::wasClick(int X,int Y)
{
    bool rta=false;

    if(X>=getX() && X<=getX()+getWidth() && Y>=getY() && Y<=getY()+ getHeight())
    {
        rta=true;
    }
    return rta;
}

//=============================================================================
// METODO    : void clsBoton::mouseCommand(Uint16 mbutton)
// ACCION    : verifica que boton del Mouse se apreto.
// PARAMETROS: Uint16 mbutton
// DEVUELVE  : Nada
//-----------------------------------------------------------------------------
void clsBoton::mouseCommand(Uint16 mbutton)
{

  switch(mbutton)
  {
    case MOUSE_LEFT_BUTTON:
                             break;

    case MOUSE_RIGHT_BUTTON:
                             break;
  }

}
