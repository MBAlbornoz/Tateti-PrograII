#ifndef CLSFICHAS_H
#define CLSFICHAS_H

#include <clsSprite.h>
#include <clsError.h>
#include <clsEvent.h>
#include <clsScreen.h>


class clsFichas : public clsSprite
{
protected:
    void inherit() {};
    clsScreen *screen;
    clsEvent *event;
    int coordX;
    int coordY;

public:
    int init();
    void setCoordX(int x)
    {
        coordX=x;
    }
    void setCoordY(int y)
    {
        coordY=y;
    }
    void primerEmoji(int,int);
    void segundoEmoji(int,int);
    void ayuda(int, int);
    void ganaste(int, int);
    void empate(int, int);
    void idJugador1(int,int);
    void idJugador2(int,int);
    void pantPuntaje(int,int);
};

#endif // CLSFICHAS_H
