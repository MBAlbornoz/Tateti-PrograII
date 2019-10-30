#ifndef CLSBOTON_H
#define CLSBOTON_H

#include <clsSprite.h>
#include <clsEvent.h>


class clsBoton : public clsSprite
{
    protected:
        void inherit(){};
        clsScreen *screen;
        clsEvent *event;
    public:
        int init(clsScreen*);
        bool wasClick(int,int);
        int run();
        void jugar();
        void salir();
        void puntaje();
        void ayuda();
        void mouseCommand(Uint16);
};

#endif // CLSBOTON_H
