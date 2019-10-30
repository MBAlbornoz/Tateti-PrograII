#include "clsDespedida.h"

//=============================================================================
// METODO    : int clsDespedida::init()
// ACCION    : genera la pantalla de despedida del juego.
// PARAMETROS: Nada
// DEVUELVE  : Retorna el tipo de error. return error.get();
//-----------------------------------------------------------------------------
int clsDespedida::init()
{
    error.set(0);  //Inicializo el codigo de error
    setItems(1);   //Indico la cantidad de imagenes que tendra el vector de sprites
    setI(0);       //Indico el indice dentro del vector a colocar la imagen
    setX(0);       //Indico coordenada de X
    setY(0);       //Indico coordenada de Y
    error.set(load("IMAGENES/Despedida.png"));
    return error.get();
}
