#include "clsAyuda.h"

//=============================================================================
// METODO    : int clsAyuda::init(clsScreen *s)
// ACCION    : Genera la pantalla de ayuda del juego.
// PARAMETROS: clsScreen *s
// DEVUELVE  : int -> codigo Error del Juego
//-----------------------------------------------------------------------------
int clsAyuda::init(clsScreen *s)
{
    screen=s;
    setItems(1);
    setI(0);
    error.set(load("IMAGENES/Ayuda.jpg"));
    if (error.get())
    {
        error.show(true);
        return error.get();
    }
    return error.get();
}
