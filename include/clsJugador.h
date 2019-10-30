#ifndef CLSJUGADOR_H
#define CLSJUGADOR_H
#include "clsScreen.h"
#include "clsEvent.h"
#include "clsError.h"
#include "clsSprite.h"
#include "clsText.h"
#include "string.h"
#include "clsTimer.h"
#include "clsFichas.h"


class clsJugador : public clsSprite

{
protected:
    char nombre[100];
    int id;
    void inherit() {};
    clsError error;
    clsScreen *screen;
    clsEvent *event;
    clsText *text;
    clsTimer timer;
    clsFichas fichas;



public:

    void setNombre(char*nom)
    {
        strcpy(nombre,nom);
    }
    char *getNombre()
    {
        return nombre;
    }
    void setIdJugador(int idJ)
    {
        id=idJ;
    }
    char getIdJugador()
    {
        return id;
    }
    char* buscarJugador(int);
    int init(clsText*,clsScreen*);
    int run(clsText*,clsScreen*,clsEvent*,int);
    void keyCommand(bool*,Uint16);
    void setNomKeyPreseed(clsEvent*,clsScreen*);
    void grabarEnDisco();

};




#endif // CLSJUGADOR_H
