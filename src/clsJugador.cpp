#include "clsJugador.h"
#include "clsSprite.h"
#include "clsTimer.h"
#include "clsScreen.h"


//=============================================================================
// METODO    : int clsJugador::init(clsText* text, clsScreen*screen)
// ACCION    : Inicializa el modo juegador
// PARAMETROS: clsText* text, clsScreen*screen
// DEVUELVE  : retorna el codigo de error del juego return error.get();
//-----------------------------------------------------------------------------
int clsJugador::init(clsText* text, clsScreen*screen)
{
    error.set(0);

    error.set(text->init());
    if (error.get())
        return error.get();

    error.set(text->loadFont("FONTS/FreeMonoBold.ttf",40));
    if (error.get())
        return error.get();

    return error.get();
}

//=============================================================================
// METODO    : int clsJugador::run(clsText* text, clsScreen*screen, clsEvent*event)
// ACCION    : Inicializa el motor juegador y carga los datos del jugador
// PARAMETROS: clsText* text, clsScreen*screen, clsEvent*event
// DEVUELVE  : retorna el codigo de error del juego return error.get();
//-----------------------------------------------------------------------------
int clsJugador::run(clsText* text, clsScreen*screen, clsEvent*event, int idj)
{
    error.set(0);

    error.set(text->init());
    if(error.get())
    {
        return error.get();
    }

    error.set(text->loadFont("FONTS/FreeSerif.ttf",30));
    if(error.get())
    {
        return error.get();
    }

    text->setFontColor(WHITE);
    screen->refresh();

    bool salir=false;
    char cadena[50]=" ";

    //Debo crear un auxuliar char para guardar nombre jugador 1 y despues comparar con cadena.
    //Nombre JUgador1 debe ser diferente a Nombre jugador 2

    /// int jugador=idj; //ver error jugador=1 debe ser IDJ

    while(!salir)
    {
        if(event->wasEvent())
        {
            text->setFontColor(WHITE);

            if (event->getEventType()==KEY_PRESSED)
            {
                int key=event->getKey();
                if(((key>='a')&&(key<='z')) || ((key>='A')&&(key<='Z')))
                {
                    int l=strlen(cadena);
                    cadena[l]=event->getKey();
                    cadena[l+1]=0;
                }
                else if(key==KEY_BACKSPACE && strlen(cadena)>0)
                {
                    if(idj==1)
                    {
                        screen->clean(BLACK);
                        text->setFontColor(WHITE);
                        text->write("Primer Jugador",500,100,screen->getPtr());
                        fichas.primerEmoji(0,0);
                        screen->refresh();
                        int l=strlen(cadena);
                        if(l>1)
                        {
                            cadena[l-1]='\0';
                        }
                        else if(l==1)
                        {
                            cadena[l-1]=' ';
                            cadena[l]='\0';
                        }
                    }
                    else
                    {
                        screen->clean(BLACK);
                        text->setFontColor(WHITE);
                        text->write("Segundo Jugador",500,100,screen->getPtr());
                        fichas.segundoEmoji(0,0);
                        screen->refresh();
                        int l=strlen(cadena);
                        if(l>1)
                        {
                            cadena[l-1]='\0';
                        }
                        else if(l==1)
                        {
                            cadena[l-1]=' ';
                            cadena[l]='\0';
                        }
                    }
                }

                else if(key==KEY_ENTER)
                {
                    ///ANTES AGREGAR CONDICION DE CADENA NO VACIA PARA JUGADOR 1
                    if(idj==1)
                    {
                        if(strlen(cadena)>1)
                        {
                            salir=true;
                            //GRABA EN DISCO
                            this->setNombre(cadena);
                            this->setIdJugador(idj);
                            grabarEnDisco();
                        }
                        else
                        {
                          salir=false;

                        }

                    }

                    ///CONDICION DE CADENA NO VACIA Y CONDICION JUGADOR2 != JUGADOR1
                    if(idj==2)
                    {
                        if((strlen(cadena)>1)&& (strcmp(cadena,this->buscarJugador(1))!=0))
                        {
                            salir=true;
                            //GRABA EN DISCO
                            this->setNombre(cadena);
                            this->setIdJugador(idj);
                            grabarEnDisco();
                        }
                        else
                        {
                          salir=false;
                        }
                    }

                }
            }
            text->write(strupr(cadena),450,150,screen->getPtr());
            screen->refresh();
        }
    }
    return error.get();
}


//=============================================================================
// METODO    : void clsJugador::keyCommand(bool *salir, Uint16 key)
// ACCION    : verifica la tecla presionada y cambia el estado para salir del juego.
// PARAMETROS: bool *salir, Uint16 key
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsJugador::keyCommand(bool *salir, Uint16 key)
{
    error.set(0);
    switch(key)
    {
    case KEY_ESCAPE:
    {
        *salir = true;
        exit(0);
    }
    break;
    }
}

//=============================================================================
// METODO    :void clsJugador::grabarEnDisco()
// ACCION    :Graba los datos del jugador
// PARAMETROS:Nada
// DEVUELVE  :Nada
//-----------------------------------------------------------------------------

void clsJugador::grabarEnDisco()
{
    FILE*p;
    p=fopen("jugadores.dat","ab");
    if(p==NULL)
    {
        exit(1);
    }
    fwrite(this,sizeof*this,1,p);
    fclose(p);
}


//=============================================================================
// METODO    : char *clsJugar::buscarJugador(int id)
// ACCION    : busca el nombre del jugador
// PARAMETROS: int id del jugador
// DEVUELVE  : Nombre del jugador
//-----------------------------------------------------------------------------

char *clsJugador::buscarJugador(int id)
{
    FILE*p;

    clsJugador j;
    p=fopen("jugadores.dat","rb");
    if(p==NULL)
    {
        exit(1);
    }
    while(fread(&j,sizeof j,1,p)==1)
    {
        if(j.getIdJugador()==id)
        {
            fclose(p);
            return j.getNombre();
        }
    }
    fclose(p);
    return j.getNombre();
}
