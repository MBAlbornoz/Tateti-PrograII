#ifndef CLSCASILLA_H
#define CLSCASILLA_H

#include <clsSprite.h>
#include <clsEvent.h>
#include <clsError.h>

class clsCasilla : public clsSprite
{
    protected:
        void inherit(){};
        clsScreen *screen;
        clsEvent *event;
        clsError error;
        int coordX;
        int coordY;

    public:
        int init();
        void setCoordX(int x){coordX=x;}
        void setCoordY(int y){coordY=y;}
        int getCoordX(){return x;}
        int getCoordY(){return y;}
        bool elegir(int,int);
        bool ocupada(int,int);
        void mostrar(int,int);
        void ganaste();
        void empate();
        bool wasClick(int,int);
        int run();

};

#endif // CLSCASILLA_H
