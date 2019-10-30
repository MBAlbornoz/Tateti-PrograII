#include "clsJuego.h"

//=============================================================================
// METODO    : int clsJuego::init(clsScreen*screen)
// ACCION    : Inicializa el modo juego
// PARAMETROS: clsScreen*screen
// DEVUELVE  : retorna el codigo de error del juego return error.get();
//-----------------------------------------------------------------------------
int clsJuego::init(clsScreen*screen)
{

    screen->clean(WHITE);
    fichas.primerEmoji(0,0);
    fichas.paste(screen->getPtr());
    screen->refresh();

    screen->clean(BLACK);
    fichas.segundoEmoji(0,0);
    fichas.paste(screen->getPtr());
    screen->refresh();

    tablero->paste(screen->getPtr());
    error.get();
    screen->refresh();
    tablero->mostrarTablero();
    error.get();
    screen->refresh();
    return error.get();
}
