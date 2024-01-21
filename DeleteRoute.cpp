#include "Route.h"

void deleteroutes(string route)
{
    string routename[100],temproute;
    int i=0,a=0;
    ifstream routefile; //Reads all the routes in from the Route file
    routefile.open("Route.txt");
    if(routefile.is_open())
    {
        while ( 1 )
        {
           getline(routefile, temproute);
           routename[i]=temproute;
            i++;
            if (routefile.eof())
				break;
        }
    }
    routefile.close();

    ofstream deletefile; //to delete file contents
    deletefile.open("Route.txt",ios::trunc); 
    deletefile.close();
    ofstream finalfile;//to add the Routes back to the correct file
    finalfile.open("Route.txt",ios::app);
    while (a<i-1)
    {
        if(route==routename[a])
        {
            a++;
        }
        else
        {
            finalfile << routename[a] << endl;
            a++;
        }
    }
        finalfile.close();

}