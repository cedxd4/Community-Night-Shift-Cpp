#include "AddWorker.h"


void addworker(string first,string last)
{
    fstream workerfile;
    workerfile.open("Worker.txt",ios::app);
    workerfile << first << " " << last << endl;
    workerfile.close();

}