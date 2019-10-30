#include "clsPresentacion.h"


//=============================================================================
// METODO    : int clsPresentacion::init()
// ACCION    : inicializa la pantalla de presentacion.
// PARAMETROS: Nada
// DEVUELVE  : el codigo de error si no puede inicializar la pantalla. return error.get();
//-----------------------------------------------------------------------------

int clsPresentacion::init()
{
    error.set(0);  //Inicializo el codigo de error
    setItems(1);   //Indico la cantidad de imagenes que tendra el vector de sprites
    setI(0);       //Indico el indice dentro del vector a colocar la imagen
    setX(0);       //Indico coordenada de X
    setY(0);       //Indico coordenada de Y
    error.set(load("IMAGENES/Pantallas saludos/Presentacion.jpg"));
    if (error.get())
        return error.get();

    return error.get();
}
