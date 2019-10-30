#include "clsTablero.h"
#include "clsScreen.h"
#include "clsCasilla.h"

//=============================================================================
// METODO    : int clsTablero::init(clsScreen *scr)
// ACCION    : inicializa la pantalla de tablero de tateti.
// PARAMETROS: clsScreen *scr
// DEVUELVE  : el codigo de error si no puede inicializar la pantalla. return error.get();
//-----------------------------------------------------------------------------
int clsTablero::init(clsScreen *scr)
{
    this->screen=scr;
    error.set(0);  //Inicializo el codigo de error
    setItems(1);   //Indico la cantidad de imagenes que tendra el vector de sprites
    setI(0);       //Indico el indice dentro del vector a colocar la imagen
    setX(0);       //Indico coordenada de X
    setY(0);       //Indico coordenada de Y
    error.set(load("IMAGENES/Tablero/FONDOTATETI.jpg")); //Cargo la imagen
     if(error.get())
        return error.get();

    return error.get();
}

//=============================================================================
// METODO    : void clsTablero::mostrarTablero()
// ACCION    : inicializa la matriz del juego para la colocacion de fichas
// PARAMETROS: Nada
// DEVUELVE  : Nada
//-----------------------------------------------------------------------------
void clsTablero::mostrarTablero()
{

    int canFilas=3;
    int canColumnas=3;

    for(int f=0; f<canFilas; f++)
    {
        for(int c=0; c<canColumnas; c++)
        {
            mat[f][c].init();
        }
    }

    for(int f=0; f<canFilas; f++)
    {
        for(int c=0; c<canColumnas; c++)
        {
            if(this->getOcupado(f,c)==false)
            {
                mat[f][c].setI(0);
                mat[f][c].paste(c*mat[f][c].getWidth() +300,
                                f*mat[f][c].getHeight()+70,
                                screen->getPtr());
            }
            else if ((this->getOcupado(f,c))&&(this->getIdJugador(f,c)))
            {
                mat[f][c].setI(0);
                mat[f][c].paste(c*mat[f][c].getWidth() +300,
                                f*mat[f][c].getHeight()+70,
                                screen->getPtr());

                mat[f][c].setI(1);
                mat[f][c].paste(c*mat[f][c].getWidth() +300,
                                f*mat[f][c].getHeight()+70,
                                screen->getPtr());
            }
            else if ((this->getOcupado(f,c))&&(!this->getIdJugador(f,c)))
            {
                mat[f][c].setI(0);
                mat[f][c].paste(c*mat[f][c].getWidth() +300,
                                f*mat[f][c].getHeight()+70,
                                screen->getPtr());

                mat[f][c].setI(2);
                mat[f][c].paste(c*mat[f][c].getWidth() +300,
                                f*mat[f][c].getHeight()+70,
                                screen->getPtr());
            }

        }
    }

}

//=============================================================================
// METODO    : void clsTablero::mostrarSeleccionada(int f, int c)
// ACCION    : Muestra la posicion del tablero selecionada
// PARAMETROS: int f, int c
// DEVUELVE  : Nada
//-----------------------------------------------------------------------------
void clsTablero::mostrarSeleccionada(int f, int c)
{
    if(this->getOcupado(f,c)==false)
    {
        mat[f][c].setI(3);
        mat[f][c].paste(c*mat[f][c].getWidth() +300,
                        f*mat[f][c].getHeight()+70,
                        screen->getPtr());
    }
    else if ((this->getOcupado(f,c))&&(this->getIdJugador(f,c)))
    {
        mat[f][c].setI(3);
        mat[f][c].paste(c*mat[f][c].getWidth() +300,
                        f*mat[f][c].getHeight()+70,
                        screen->getPtr());

        mat[f][c].setI(1);
        mat[f][c].paste(c*mat[f][c].getWidth() +300,
                        f*mat[f][c].getHeight()+70,
                        screen->getPtr());
    }
    else if ((this->getOcupado(f,c))&&(!this->getIdJugador(f,c)))
    {
        mat[f][c].setI(3);
        mat[f][c].paste(c*mat[f][c].getWidth() +300,
                        f*mat[f][c].getHeight()+70,
                        screen->getPtr());

        mat[f][c].setI(2);
        mat[f][c].paste(c*mat[f][c].getWidth() +300,
                        f*mat[f][c].getHeight()+70,
                        screen->getPtr());
    }
}


////=============================================================================
//// METODO    : void clsTablero::iniOcupado()
//// ACCION    : verifica las ubicaciones del tablero si estan ocupadas
//// PARAMETROS: Nada
//// DEVUELVE  : Nada
////-----------------------------------------------------------------------------
void clsTablero::iniOcupado()
{
    for(int f=0; f<3; f++)
    {
        for(int c=0; c<3; c++)
        {
            ocupado[c][f]=false;
        }
    }
}


//=============================================================================
// METODO    : void clsTablero::setIdJugador(int f,int c, int jug)
// ACCION    : verifica quien juega y elige que ficha usa
// PARAMETROS: int f,int c, int jug (Filas, Columnas y Jugador en curso)
// DEVUELVE  : Nada
//-----------------------------------------------------------------------------
void clsTablero::setIdJugador(int f,int c, int jug)
{
    if(jug==1)
    {
        idJugador[c][f]=true;
    }

    else if(jug==2)
    {
        idJugador[c][f]=false;
    }
}
