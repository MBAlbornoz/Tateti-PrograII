#include "clsPuntaje.h"


//=============================================================================
// METODO    : bool clsPuntaje::init()
// ACCION    : Genera archivo "Puntajes.dat".En caso de no existrir lo crea,
//             si existe, borra los datos y lo crea de cero.
// PARAMETROS: Nada
// DEVUELVE  : true en caso de que cree  el archivo correctamente. False si se presenta algun problema
//-----------------------------------------------------------------------------

bool clsPuntaje::init()
{
    bool resultado=false;
    FILE*p;
    p=fopen("Puntajes.dat","ab");
    if(p!=NULL)
    {
        resultado=true;
        fclose(p);
    }
    return resultado;
};

//=============================================================================
// METODO    : bool clsPuntaje::eliminarPuntajes()
// ACCION    : drestruye archivo "Pntajes.dat", si no existe lo crea
// PARAMETROS: Nada
// DEVUELVE  : true si esite y lo pone en 0kb, false si no.
//-----------------------------------------------------------------------------

bool clsPuntaje::eliminarPuntajes()
{
    bool resultado=false;
    FILE*p;
    p=fopen("Puntajes.dat","wb");
    if(p!=NULL)
    {
        resultado=true;
        fclose(p);
    }
    fclose(p);
    return resultado;
};



//=============================================================================
// METODO    : bool grabarGanador(int pos)
// ACCION    : Graba los datos iniciales del los jugadores en el archivo"Puntajes.dat"
// PARAMETROS: NADA
// DEVUELVE  : True si graba los datos el archivo, false si no(archivo no existe o error lectura)
//-----------------------------------------------------------------------------

bool clsPuntaje::grabarDatosInicales()
{
    FILE *p;
    p=fopen("Puntajes.dat","ab");
    if (p==NULL)
    {
        return false;
    }
    fwrite(this,sizeof (clsPuntaje),1,p);
    fclose(p);
    return true;
}



//=============================================================================
// METODO    : int clsPuntaje::buscarPuntaje(int idJ)
// ACCION    : Busca el puntaje correspondiente al idJugador que envie por parametro
// PARAMETROS: int idJ: id del jugador que pase por parametro
// DEVUELVE  : int Puntaje que corresponde al jugador
//-----------------------------------------------------------------------------

int clsPuntaje::buscarPuntaje(int idJ)
{
    int rta=-1;
    FILE *p;
    p=fopen("Puntajes.dat","rb");
    if (p==NULL)
    {
        return -1;
    }
    while(fread(this,sizeof (clsPuntaje),1,p)==1)
    {
        if (getIdJugador()==idJ)
        {
            rta=getPuntaje();
        }
    }
    fclose(p);
    return rta;
}



//=============================================================================
// METODO    : void clsPuntaje::modiPuntaje(int pos, int pje)
// ACCION    : verifica archivo "Puntajes.dat" y graba en la posicion recibida el
//          Puntaje recibido +1. Se utiliza para calcular GANAR o EMPATE
// PARAMETROS: NADA
// DEVUELVE  : Nada
//-----------------------------------------------------------------------------

void clsPuntaje::modiPuntaje(int pos, int pje)
{
    FILE *p;
    p=fopen("Puntajes.dat","rb+");
    if (p==NULL)
    {
        exit(1);
    }

    setPuntaje(pje+1);
    fseek(p,pos*sizeof(clsPuntaje),SEEK_SET);
    fseek(p,-sizeof(clsPuntaje),SEEK_CUR);
    fwrite(this,sizeof(clsPuntaje),1,p);
    fclose(p);

}


//=============================================================================
// METODO    : int clsPuntaje::buscarPos(int idJ)
// ACCION    :Busca en el archivo el registro con el ID del jugador igual al rebido por
//          parametro y en caso de encontrarlo devuelve la posicion
// PARAMETROS: int idJ: id del jugador.
// DEVUELVE  :Posicion del id Jugador en archivo "Puntajes.dat"
//-----------------------------------------------------------------------------

int clsPuntaje::buscarPos(int idJ)
{
    int pos=0;
    FILE *p;
    p=fopen("Puntajes.dat","rb");
    if (p==NULL)
    {
        return -1;
    }

    while(fread(this,sizeof(clsPuntaje),1,p)==1)
    {
        if (this->getIdJugador()==idJ)
        {
            fclose(p);
            return pos+1;
        }
       pos++;
    }
    fclose(p);
    return pos;
}


