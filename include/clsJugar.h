#ifndef CLSJUGAR_H
#define CLSJUGAR_H
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
#include <clsAyuda.h>
#include <clsPuntaje.h>

class clsJugar
{
protected:
    clsEvent *event;
    clsTimer timer;
    clsMode mode;
    clsScreen *screen;
    clsError error;
    clsText text;
    clsAudio audio;
    clsMusic music;
    clsSoundEffect effect;
    clsPresentacion presentacion;
    clsBoton boton;
    clsTablero tablero;
    clsCasilla casilla;
    clsDespedida despedida;
    clsFichas fichas;
    clsJugador jugadorPri;
    clsJugador jugadorSeg;
    clsJuego juego;
    clsAyuda ayuda;
    clsPuntaje puntaje;

    char pj[100];

public:
    int init(clsScreen*,clsEvent*);
    int run();
    void keyCommand(bool*,Uint16);
    int fila; //Lo ultilo para desplazarme en filas
    int columna; //Lo utilizo para desplazarme columnas}
    int movimiento;
    void setPuntaje(int);
    char* getPuntaje(){return pj;};
    bool ganar(int);
    bool eliminarJugadores();
    int contarRegistros(const char*, int);
    void mostrarPuntajes();

};

#endif // CLSJUGAR_H
