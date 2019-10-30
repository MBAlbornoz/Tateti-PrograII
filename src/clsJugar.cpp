#include "clsJugar.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "string.h"
#include "stdlib.h"
#include "stdlib.h"
#include <stdlib.h>
#include  <stdio.h>
#include <cstdlib>
#include <cstdio>


//=============================================================================
// METODO    : int clsJugar::init(clsScreen* scr,clsEvent* ev)
// ACCION    : Inicia las clases del juego, principal
// PARAMETROS: clsScreen* scr,clsEvent* ev
// DEVUELVE  : retorna el codigo de error return error.get();
//-----------------------------------------------------------------------------

int clsJugar::init(clsScreen* scr,clsEvent* ev)
{
    error.set(0);
    this->screen =scr;
    this->event =ev;

    error.set(presentacion.init());
    if(error.get())
        return error.get();
    error.set(despedida.init());
    if(error.get())
        return error.get();
    error.set(boton.init(screen));
    if(error.get())
        return error.get();
    error.set(tablero.init(screen));
    if(error.get())
        return error.get();
    error.set(fichas.init());
    if (error.get())
        return error.get();
    error.set(text.init());
    if (error.get())
        return error.get();
    error.set(text.loadFont("FONTS/FreeMonoBold.ttf",30));
    if (error.get())
        return error.get();
         error.set(audio.init());
    if(error.get())
        return error.get();

    error.set(music.loadMusic("AUDIO/trueno.mp3"));
    if(error.get())
        return error.get();

    return error.get();
}

//=============================================================================
// METODO    : int clsJugar::init(clsScreen* scr,clsEvent* ev)
// ACCION    : Inicial el motor principal del juego
// PARAMETROS: Nada
// DEVUELVE  : retorna el codigo de error return error.get();
//-----------------------------------------------------------------------------
int clsJugar::run()
{
    error.set(0);
    puntaje.init();
    music.playMusic(-1);

    int registrosP,registrosJ;
    registrosP=this->contarRegistros("Puntajes.dat",sizeof (clsPuntaje));
    registrosJ=this->contarRegistros("jugadores.dat",sizeof(clsJugador));
    if((registrosP==0)&&(registrosJ==0))
    {
        error.set(0);
        screen->clean(BLACK);
        text.setFontColor(WHITE);
        text.write("Primer Jugador",400,100,screen->getPtr());
        fichas.primerEmoji(0,0);
        fichas.paste(screen->getPtr());


        error.set(jugadorPri.run(&text,screen,event,1)); ///SOLO SI ES JUEGO DESDE CERO
        if (error.get())
            return error.get();

        //Ver seteo valor a Puntajes.dat
        puntaje.setIdJugador(jugadorPri.getIdJugador());
        puntaje.setPuntaje(0);
        puntaje.grabarDatosInicales();

        screen->clean(BLACK);
        text.setFontColor(WHITE);
        text.write("Segundo Jugador",400,100,screen->getPtr());
        fichas.segundoEmoji(0,0);
        fichas.paste(screen->getPtr());
        error.set(jugadorSeg.run(&text,screen,event,2)); ///SOLO SI ES JUEGO DESDE CERO
        if (error.get())
            return error.get();
        screen->refresh();

        //Ver asignacion a puntaje
        puntaje.setIdJugador(jugadorSeg.getIdJugador());
        puntaje.setPuntaje(0);
        puntaje.grabarDatosInicales();
        //Lo voy a utilizar para los empates
        puntaje.setIdJugador(3);
        puntaje.setPuntaje(0);
        puntaje.grabarDatosInicales();


    }
    tablero.iniOcupado();
    fila=0;
    columna=0;
    movimiento=0;


    bool salir=false;
    while(!salir)
    {
        screen->clean(BLACK);
        tablero.paste(screen->getPtr());
        tablero.mostrarTablero();
        tablero.mostrarSeleccionada(fila, columna);
        text.setFontColor(WHITE);
        text.loadFont("FONTS/FreeSans.ttf",30); ///Agrega el nombre del jugador en la pantalla de ganador.
        text.write("PRESIONE: ESC(SALIR) A(AYUDA)",10,10,screen->getPtr());
        mostrarPuntajes();

        if(event->wasEvent())
        {
            if(event->getEventType()==KEY_PRESSED)
            {
                keyCommand(&salir,event->getKey());  //Administro la tecla
            }
        }
    }
    return error.get();
}


//=============================================================================
// METODO    : void clsJugar::keyCommand(bool* salir,Uint16 key)
// ACCION    : verifica las teclas precionadas durante el juego
// PARAMETROS: bool* salir,Uint16 key
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsJugar::keyCommand(bool* salir,Uint16 key)
{

    switch(key)
    {
    case KEY_RIGHT:
    {
        if(columna<2)
        {
            columna++;
        }
    }
    break;
    case KEY_LEFT:
    {
        if(columna>0)
        {
            columna--;
        }
    }
    break;
    case KEY_DOWN:
    {
        if(fila<2)
        {
            fila++;
        }
    }
    break;
    case KEY_UP:
    {
        if(fila>0)
        {
            fila--;
        }
    }
    break;
    case KEY_ESCAPE:
    {
        *salir=true;
        ///FUNCION PARA GUARDAR JUEGO. EN CASO DE SELECCIONAR NO, ELIMINAR ARCHIVOS
    }
    break;
    case KEY_a:
    case KEY_A:
    {
        screen->clean(BLACK);
        fichas.ayuda(0,0);
        fichas.paste(screen->getPtr());
        screen->refresh();
        timer.waitForKey(KEY_ESCAPE);
    }
    break;
    case KEY_ENTER:
    {
        if(tablero.getOcupado(fila,columna)==false)
        {

            if ((movimiento%2==0)|| (movimiento==9))
            {
                tablero.setCoorXFichaSelec(columna);
                tablero.setCoordY(fila);
                tablero.setOcupado(fila,columna);
                tablero.setIdJugador(fila,columna,1);
                if (ganar(1)) //ID del jugador 1
                {
                    puntaje.modiPuntaje(puntaje.buscarPos(1),puntaje.buscarPuntaje(1));
                    movimiento++;
                    tablero.mostrarTablero();/// MUESTRA EL TABLERO FINAL
                    mostrarPuntajes();
                    screen->refresh();
                    timer.wait(4000);

                    fichas.ganaste(0,0);
                    fichas.paste(screen->getPtr());
                    screen->refresh();
                    text.setFontColor(BLACK);
                    text.loadFont("FONTS/FreeMonoBold.ttf",90); ///Agrega el nombre del jugador en la pantalla de ganador.
                    text.write(jugadorPri.getNombre(),150,150,screen->getPtr());
                    screen->refresh();

                    timer.wait(3000);

                    *salir=true;
                }
                else if((movimiento==8)&&(!ganar(1))&&(!ganar(0)))
                {
                    puntaje.modiPuntaje(puntaje.buscarPos(3),puntaje.buscarPuntaje(3));
                    movimiento++;
                    tablero.mostrarTablero();/// MUESTRA EL TABLERO FINAL
                    mostrarPuntajes();
                    screen->refresh();
                    timer.wait(4000);

                    fichas.empate(0,0);
                    fichas.paste(screen->getPtr());
                    screen->refresh();
                    timer.wait(3000);
                    *salir=true;
                }
                movimiento++;

            }
            else
            {
                tablero.setCoorXFichaSelec(columna);
                tablero.setCoordY(fila);
                tablero.setOcupado(fila,columna);
                tablero.setIdJugador(fila,columna,2);
                if (ganar(0)) //ID del jugador 2
                {
                    puntaje.modiPuntaje(puntaje.buscarPos(2),puntaje.buscarPuntaje(2));
                    movimiento++;
                    tablero.mostrarTablero();/// MUESTRA EL TABLERO FINAL
                    mostrarPuntajes();
                    screen->refresh();
                    timer.wait(4000);

                    fichas.ganaste(0,0);
                    fichas.paste(screen->getPtr());
                    screen->refresh();
                    text.setFontColor(BLACK);
                    text.loadFont("FONTS/FreeMonoBold.ttf",90); ///Agrega el nombre del jugador en la pantalla de ganador.
                    text.write(jugadorSeg.getNombre(),150,150,screen->getPtr());
                    screen->refresh();
                    timer.wait(3000);

                    *salir=true;

                }

                movimiento++;
            }

        }
        screen->refresh();
    }
    break;

    }
}

//=============================================================================
// METODO    : bool clsJugar::ganar(int idJugador)
// ACCION    : recibe el numero de jugador y verifica la posicion de las fichas y verifica si alguno gana
// PARAMETROS: int idJugador, recibe el numero de jugador
// DEVUELVE  : devuelve que jugador gano.
//-----------------------------------------------------------------------------
bool clsJugar::ganar(int idJugador)
{

    if ( (( ((tablero.getOcupado(0,0))&&((tablero.getIdJugador(0,0))==idJugador))&&
            ((tablero.getOcupado(0,1))&&((tablero.getIdJugador(0,1))==idJugador))&&
            ((tablero.getOcupado(0,2))&&((tablero.getIdJugador(0,2))==idJugador)))
            ||
            ( ((tablero.getOcupado(1,0))&&((tablero.getIdJugador(1,0))==idJugador))&&
              ((tablero.getOcupado(1,1))&&((tablero.getIdJugador(1,1))==idJugador))&&
              ((tablero.getOcupado(1,2))&&((tablero.getIdJugador(1,2))==idJugador)))
            ||
            ( ((tablero.getOcupado(2,0))&&((tablero.getIdJugador(2,0))==idJugador))&&
              ((tablero.getOcupado(2,1))&&((tablero.getIdJugador(2,1))==idJugador))&&
              ((tablero.getOcupado(2,2))&&((tablero.getIdJugador(2,2))==idJugador)))
         ) //Vertical
            ||

            ( (((tablero.getOcupado(0,0))&&((tablero.getIdJugador(0,0))==idJugador))&&
               ((tablero.getOcupado(1,0))&&((tablero.getIdJugador(1,0))==idJugador))&&
               ((tablero.getOcupado(2,0))&&((tablero.getIdJugador(2,0))==idJugador)))
              ||
              ( ((tablero.getOcupado(0,1))&&((tablero.getIdJugador(0,1))==idJugador))&&
                ((tablero.getOcupado(1,1))&&((tablero.getIdJugador(1,1))==idJugador))&&
                ((tablero.getOcupado(2,1))&&((tablero.getIdJugador(2,1))==idJugador)))
              ||
              (
                  ((tablero.getOcupado(0,2))&&((tablero.getIdJugador(0,2))==idJugador))&&
                  ((tablero.getOcupado(1,2))&&((tablero.getIdJugador(1,2))==idJugador))&&
                  ((tablero.getOcupado(2,2))&&((tablero.getIdJugador(2,2))==idJugador)))
            ) //Horizontal
            ||

            ( ((tablero.getOcupado(0,0))&&((tablero.getIdJugador(0,0))==idJugador))&&
              ((tablero.getOcupado(1,1))&&((tablero.getIdJugador(1,1))==idJugador))&&
              ((tablero.getOcupado(2,2))&&((tablero.getIdJugador(2,2))==idJugador)))
            || //Cruz izq a der
            ( ((tablero.getOcupado(2,0))&&((tablero.getIdJugador(2,0))==idJugador))&&
              ((tablero.getOcupado(1,1))&&((tablero.getIdJugador(1,1))==idJugador))&&
              ((tablero.getOcupado(0,2))&&((tablero.getIdJugador(0,2))==idJugador)))

       )

    {
        return true;
    }
    return false;
}




//=============================================================================
// METODO    :bool clsJugar::eliminarJugadores()
// ACCION    :Borra el archivo Jugador
// PARAMETROS:Nada
// DEVUELVE  :Nada
//-----------------------------------------------------------------------------

bool clsJugar::eliminarJugadores()
{
    FILE*p;
    p=fopen("jugadores.dat","wb");
    if(p==NULL)
    {
        return false;
    }
    fclose(p);
    return true;
}

//=============================================================================
// METODO    : void clsJugar::setPuntaje(int p)
// ACCION    : Recibe  int Puntaje (Debo obtenerlo de clsPuntaje.buscarPuntajeGanador()
//              y  lo convierte a char*Puntaje
// PARAMETROS: Nada
// DEVUELVE  : Nada
//-----------------------------------------------------------------------------

void clsJugar::setPuntaje(int p)
{
    char numTostr[100];
    itoa(p,numTostr,10);
    strcpy(pj,numTostr);
}

//=============================================================================
// METODO    : int clsJugar::contarRegistros(FILE *archivo, int tamObj)
// ACCION    :  Cuenta los registros en el archivo "Puntajes.dat"
// PARAMETROS:   const char*direccion,
//               int tamObj: tamaño del objeto
// DEVUELVE  :int (cantidad de registros en el archivo
//-----------------------------------------------------------------------------

int clsJugar::contarRegistros(const char*direccion, int tamObj)
{
    int resultado=0;
    int tamArchivo=0;
    FILE*a;
    a=fopen(direccion,"rb");
    if (a!=NULL)
    {
        fseek(a,0L,SEEK_END);
        tamArchivo=ftell(a);
        resultado=tamArchivo/tamObj;
        fclose(a);
    }

    else
    {
        return -1;
    }
    return resultado;
}


//=============================================================================
// METODO    :void clsJugar::mostrarPuntajes()
// ACCION    : Muestra la Pantalla Puntaje con ficha, nombre y puntajes de los jugadores
// PARAMETROS:NADA
// DEVUELVE  :NADA
//-----------------------------------------------------------------------------

void clsJugar::mostrarPuntajes()
{

    fichas.pantPuntaje(150,200); //DIBUJA LA PANTALLA PARA PUNTAJE
    fichas.paste(screen->getPtr());

    text.setFontColor(WHITE);
    text.loadFont("FONTS/FreeSerifBoldItalic.ttf",25);
    text.write(jugadorPri.getNombre(),0,220,screen->getPtr());
    text.write(jugadorSeg.getNombre(),0,340,screen->getPtr());
    fichas.idJugador1(05,260);//Dibuja icono del 1ª jugador en pantalla juego
    fichas.paste(screen->getPtr());
    fichas.idJugador2(05,360);//Dibuja icono del 2ª jugador en pantalla juego
    fichas.paste(screen->getPtr());


    text.setFontColor(BLACK);
    text.loadFont("FONTS/FreeSerifBold.ttf",40);
    ///gano jugador 1 IMPRIME UNA X EN PARTIDOS GANADOS
    setPuntaje(puntaje.buscarPuntaje(1));
    text.write(getPuntaje(),180,250,screen->getPtr());

    ///gano jugador 2 IMPRIME UNA X EN PARTIDOS GANADOS
    setPuntaje(puntaje.buscarPuntaje(2));
    text.write(getPuntaje(),180,360,screen->getPtr());

    ///Empate
    setPuntaje(puntaje.buscarPuntaje(3));
    text.write(getPuntaje(),250,300,screen->getPtr());
    screen->refresh();

}



