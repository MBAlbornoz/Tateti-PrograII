#include <string>
using namespace std;
#include "stdlib.h"
#include <iostream>
#include <string>


#include <clsScreen.h>
#include <clsError.h>
#include <adnConsts.h>
#include <clsEvent.h>
#include <clsMode.h>
#include <clsTimer.h>
#include <clsPresentacion.h>
#include <clsDespedida.h>
#include <clsMenu.h>
#include <clsBoton.h>
#include <clsTablero.h>
#include <clsCasilla.h>
#include <clsFichas.h>
#include <clsAudio.h>
#include <clsMusic.h>
#include <clsSoundEffect.h>
#include <clsJugador.h>
#include <clsJuego.h>
#include <clsFichas.h>
#include <clsText.h>
#include <clsJugar.h>
#include <clsAyuda.h>
#include <clsPuntaje.h>

class clsMotor
{
    protected:
        clsEvent event;
        clsTimer timer;
        clsMode mode;
        clsScreen screen;
        clsError error;
        clsText text;
        clsAudio audio;
        clsMusic music;
        clsSoundEffect effect;
        clsPresentacion presentacion;
        clsMenu menu;
        clsBoton boton;
        clsTablero tablero;
        clsCasilla casilla;
        clsDespedida despedida;
        clsFichas fichas;
        clsJugador jugadorPri;
        clsJugador jugadorSeg;
        clsJuego juego;
        clsJugar jugar;
        clsAyuda ayuda;
        clsPuntaje puntaje;


    public:
        int init();
        int run();
        void keyCommand(bool*,Uint16);
        int mouseCommand(bool*, bool*, Uint8,Uint16);
};

//#endif // CLSMOTOR_H
