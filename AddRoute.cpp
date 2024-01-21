#include "Route.h"

void addroutes(string route)
{
    fstream routefile;
    routefile.open("Route.txt",ios::app);
    routefile << route << endl;
    routefile.close();

}