#include "clsMenu.h"

//=============================================================================
// METODO    : int clsMenu::init(clsEvent *ev, clsScreen *scr)
// ACCION    : genera la imagen del fondo del menu principal
// PARAMETROS: clsEvent *ev, clsScreen *scr
// DEVUELVE  : devuelve el codigo del error   return error.get();
//-----------------------------------------------------------------------------
int clsMenu::init(clsEvent *ev, clsScreen *scr)
{
    error.set(0);
    this->event=ev;
    this->screen=scr;
    setItems(1);
    setI(0);
    setX(0);
    setY(0);
    error.set(load("IMAGENES/Menu/fondoMenu.png"));
    if(error.get())
    {
        return error.get();
    }
    return error.get();
}


//=============================================================================
// METODO    : int clsMenu::run()
// ACCION    : Inicializa el motor del menu del juego
// PARAMETROS: Nada.
// DEVUELVE  : devuelve el codigo del error   return error.get();
//-----------------------------------------------------------------------------
int clsMenu::run()
{
    error.set(0);
    screen->refresh();
    error.get();

    bool salir = false;


    while(!salir)  //Ciclo del programa
    {
        if(event->wasEvent())  //Verifico si hay evento
        {
            if(event->getEventType() ==KEY_PRESSED)  //Verifico si hay evento de teclado
            {
                keyCommand(&salir,event->getKey());  //Administro la tecla
            }
        }
    }
    return error.get();
}

//=============================================================================
// METODO    : int clsMenu::keyCommand(bool*salir,Uint16 key)
// ACCION    : verifica las teclas que son precionadas en el Menu
// PARAMETROS: bool*salir,Uint16 key.
// DEVUELVE  : devuelve el codigo del error   return error.get();
//-----------------------------------------------------------------------------
int clsMenu::keyCommand(bool*salir,Uint16 key)
{
    error.set(0);
    switch(key)
    {
    case KEY_ESCAPE:  //Si se preciona escape termino el programa
    {
        *salir = true;
    }
    break;
    }
    return error.get();
}

