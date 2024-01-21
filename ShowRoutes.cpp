#include "Route.h"

void showroutes()
{
    string routes;
    int i=0;
    ifstream routefile;
    routefile.open("Route.txt");
    if(routefile.is_open())
    {
        while ( 1 )
        {
            getline(routefile, routes);
            cout << routes << endl;
            if (routefile.eof())
				break;
        }
    }
    routefile.close();
    system("pause");
}