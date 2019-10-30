#ifndef CLSTABLERO_H
#define CLSTABLERO_H

#include <clsSprite.h>
#include <clsEvent.h>
#include <clsCasilla.h>
#include <clsFichas.h>
#include <clsJugador.h>

class clsTablero : public clsCasilla
{
protected:
    void inherit() {};
    clsScreen *screen;
    clsEvent *event;
    clsError error;
    clsFichas ficha;
    clsJugador jugador;
    clsCasilla mat[3][3];
    bool ocupado[3][3];
    bool idJugador[3][3]; // 1 si es jugador 1 y 0 si es jugador 2

    int coorXFichaSelec;
    int coorYFichaSelec;

public:
    int init(clsScreen*);
    void mostrarTablero();
    void mostrarSeleccionada(int, int);
    void pegarFichaSeleccionada(int, int, int); //coordenada X,coordenada y, ficha (I correspondiente)
    void jugar();
    bool wasClick(int,int);
    int run();
    void iniOcupado();
    void setOcupado(int f,int c){ocupado[c][f]=true;}
    bool getOcupado(int f,int c){return ocupado[c][f];}

    void setCoorXFichaSelec(int xSelec){coorXFichaSelec=xSelec;}
    void setCoorYFichaSelec(int ySelec){coorYFichaSelec=ySelec;}

    int getCoorXFichaSelec(){return coorXFichaSelec;}
    int getCoorYFichaSelec(){return coorYFichaSelec;}

    void setIdJugador(int f,int c, int jug);
    bool getIdJugador(int f, int c){return idJugador[c][f];};

};

#endif // CLSTABLERO_H
