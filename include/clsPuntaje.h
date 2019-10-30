#ifndef CLSPUNTAJE_H
#define CLSPUNTAJE_H

#include <clsSprite.h>
#include <clsScreen.h>
#include <clsText.h>


class clsPuntaje : public clsSprite
{
public:
    clsScreen* screen;
    clsText *text;
    void setIdJugador(int id)
    {
        idJugador=id;
    };
    void setPuntaje(int p)
    {
        puntaje=p;
    };
    int getIdJugador()
    {
        return idJugador;
    };
    int getPuntaje()
    {
        return puntaje;
    };


    bool init();
    bool eliminarPuntajes();
    void inherit() {};
    bool grabarDatosInicales();
      //PUNTAJES
    void modificarPuntajes(int, int);
    int buscarPuntaje(int);
    int buscarPos(int); //ver
    void grabarPuntajes(int);
    void modiPuntaje(int,int);



   // clsPuntaje(){idJugador=0,puntaje=0;};


private:
    int idJugador;
    int puntaje;

};

#endif // CLSPUNTAJE_H
