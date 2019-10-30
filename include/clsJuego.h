#ifndef CLSJUEGO_H
#define CLSJUEGO_H
#include <clsFichas.h>
#include <clsJugador.h>
#include <clsTablero.h>
#include <clsTimer.h>
#include <clsScreen.h>


class clsJuego
{
    protected:
        clsFichas fichas;
        clsJugador jugadorPri;
        clsJugador jugadorSeg;
        clsTablero *tablero;
        clsTimer *timer;
        clsScreen *screen;
        clsError error;

    public:
        int init(clsScreen*);


};

#endif // CLSJUEGO_H
