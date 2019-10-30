#ifndef CLSAYUDA_H
#define CLSAYUDA_H

#include <clsSprite.h>
#include <clsScreen.h>


class clsAyuda : public clsSprite
{
   public:
       void inherit(){};
       int init(clsScreen *s);
   private:
    clsScreen *screen;
};

#endif // CLSAYUDA_H
