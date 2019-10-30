#ifndef CLSMENU_H
#define CLSMENU_H

#include <clsSprite.h>
#include <clsEvent.h>



class clsMenu : public clsSprite
{
    protected:
        void inherit(){};
        clsEvent *event;
        clsScreen *screen;

    public:
        int init(clsEvent*,clsScreen*);
        int initBotones();
        int run();
        int keyCommand(bool*,Uint16);

};

#endif // CLSMENU_H
