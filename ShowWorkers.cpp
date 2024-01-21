#include "AddWorker.h"

void showworkers()
{
    string firstname[20],lastname[20];
    int i=0;
    ifstream workerfile;
    workerfile.open("Worker.txt",ios::app);
    if(workerfile.is_open())
    {
        while ( 1 )
        {
            workerfile >> firstname[i] >> lastname[i];
            cout << firstname[i] << " " << lastname[i] << endl;
            i++;
            if (workerfile.eof())
				break;
        }
    }
    workerfile.close();
    system("pause");
}