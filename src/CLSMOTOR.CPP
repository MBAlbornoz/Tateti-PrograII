#include "clsMotor.h"

//=============================================================================
// METODO    : int clsMotor::init()
// ACCION    : Motor principal. verifica errores al inicializar clases.
// PARAMETROS: NADA.
// DEVUELVE  : int -> codigo Error del Juego
//-----------------------------------------------------------------------------
int clsMotor::init()
{
    error.set(0);
    error.set(mode.init(DEFAULT)); //Inicio el modo grafico
    if(error.get())
        return error.get();

    error.set(screen.init(mode.getScrWidth(),   //Inicio la pantalla
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE));
    if(error.get())
        return error.get();

    error.set(audio.init());
    if(error.get())
        return error.get();

    error.set(music.loadMusic("AUDIO/trueno.mp3"));
    if(error.get())
        return error.get();

    error.set(ayuda.init(&screen));
    if (error.get())
    {
        error.show(true);
        return error.get();
    }


    error.set(presentacion.init());
    if(error.get())
        return error.get();

    error.set(despedida.init());
    if(error.get())
        return error.get();

    error.set(menu.init(&event,&screen));
    if(error.get())
        return error.get();

    error.set(boton.init(&screen));
    if(error.get())
        return error.get();

    error.set(tablero.init(&screen));
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

    return error.get();
}

//=============================================================================
// METODO    : int clsMotor::run()
// ACCION    : Estructura principal del juego
// PARAMETROS: Nada.
// DEVUELVE  : devuelve el codigo del error   return error.get();
//-----------------------------------------------------------------------------

int clsMotor::run()
{

    error.set(0);
    music.playMusic(-1);
    bool salir = false;
    bool enMenu=false;
    presentacion.paste(screen.getPtr());  //Pego imagen presentacion
    screen.refresh();
    timer.wait(1000); //Espera el tiempo asignado

    while(!salir)
    {
        screen.clean(BLACK);
        menu.paste(screen.getPtr());
        enMenu=true;
        boton.jugar();
        boton.paste(screen.getPtr());
        boton.puntaje();
        boton.paste(screen.getPtr());
        boton.ayuda();
        boton.paste(screen.getPtr());
        boton.salir();
        boton.paste(screen.getPtr());
        screen.refresh();
        if(event.wasEvent())
        {
            switch(event.getEventType())
            {
            case KEY_PRESSED:
                if(KEY_ESCAPE)
                {
                    keyCommand(&salir,event.getKey());  //Administro la tecla
                }
                break;
            }
            if (event.getMouseButton())
            {
                mouseCommand(&salir,&enMenu,event.getMouseButton(),Uint16());

            }

        }
    }
    despedida.paste(screen.getPtr());
    screen.refresh();
    timer.wait(1500);

    return error.get();
}

//=============================================================================
// METODO    : void clsMotor::keyCommand(bool *salir, Uint16 key)
// ACCION    : verifica el estado del juego y las teclas precionadas.
// PARAMETROS: bool *salir, Uint16 key
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsMotor::keyCommand(bool *salir, Uint16 key)
{
    error.set(0);
    switch(key)
    {
    case KEY_ESCAPE:
    {
        *salir = true;
        jugar.eliminarJugadores();
        puntaje.eliminarPuntajes();
        despedida.paste(screen.getPtr());
        screen.refresh();
        timer.wait(2000);
        exit(0);
    }
    break;
    }

}



//=============================================================================
// METODO    : int mouseCommand(Uint16 short mbutton)
// ACCION    : bool *salir: permite Salir del juego
//             bool *enMenu: permite volver al menu principal
//             Uint8 mbutton: Administra funcionamiento del mouse.
//             Uint16 key: administra Tecla presionada
// PARAMETROS: unsigned short mbutton --> codigo del boton presionado.
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
int clsMotor::mouseCommand(bool *salir,bool *enMenu, Uint8 mbutton, Uint16 key)
{

    switch(mbutton)
    {
        error.set(0);
    case MOUSE_LEFT_BUTTON:
        if(*enMenu)
        {
            /*Jugar*/if((event.getCursorX()>=350)&&(event.getCursorX()<=550)
                        &&(event.getCursorY()>=150)&&(event.getCursorY()<=250))
            {
                music.stopMusic();
                music.closeMusic();
                audio.closeAudio();

                error.set(jugar.init(&screen,&event));
                if(error.get())
                    return error.get();
                error.set(jugar.run());
                if(error.get())
                    return error.get();

            }
            /*Puntaje*/if((event.getCursorX()>=350)&&(event.getCursorX()<=550)
                          &&(event.getCursorY()>=253)&&(event.getCursorY()<=353))
            {
                text.setFontColor(WHITE);
                text.loadFont("FONTS/FreeSerifBold.ttf",30);
                screen.clean(BLACK);
                if((jugar.contarRegistros("Puntajes.dat",sizeof (clsPuntaje)))!=0)
                {
                    jugar.mostrarPuntajes();
                    text.write("PRESIONES ESC PARA VOLVER AL MENU ANTERIOR",0,0,screen.getPtr());
                    screen.refresh();
                }
                else
                {
                    text.write("PRESIONES ESC PARA VOLVER AL MENU ANTERIOR",0,0,screen.getPtr());
                    text.write("NO EXISTEN PUNTAJES REGISTRADOS",0,40,screen.getPtr());
                    screen.refresh();
                }
                timer.waitForKey(KEY_ESCAPE);
                *enMenu=false;
            }
            /*Ayuda*/if((event.getCursorX()>=350)&&(event.getCursorX()<=550)
                        &&(event.getCursorY()>=356)&&(event.getCursorY()<=456))
            {
                screen.clean(BLACK);
                screen.refresh();
                ayuda.paste(screen.getPtr());
                text.setFontColor(WHITE);
                text.loadFont("FONTS/FreeSerifBold.ttf",30);
                text.write("PRESIONES ESC PARA VOLVER AL MENU AANTERIOR",0,0,screen.getPtr());
                screen.refresh();
                *enMenu=false;
                timer.waitForKey(KEY_ESCAPE);
            }
            /*Salir*/if((event.getCursorX()>=350)&&(event.getCursorX()<=550)
                        &&(event.getCursorY()>=459)&&(event.getCursorY()<=559))
            {
                despedida.paste(screen.getPtr());
                screen.refresh();
                timer.wait(2000);
                music.stopMusic();
                music.closeMusic();
                audio.closeAudio();
                jugar.eliminarJugadores();/// ELIMINA ARCHIVO "jugadores.dat"
                puntaje.eliminarPuntajes();///ELIMINA ARCHIVO "Puntajes.dat"
                *salir=true;
                exit(0);
            }

            break;
        }
    }
    return error.get();
}
