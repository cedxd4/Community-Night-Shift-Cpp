#include "AddWorker.h"

void deleteworker(string first, string last)
{
    {
    string firstname[20],lastname[20];
    int i=0,a=0;
    ifstream workerfile; //Reads all the workers in from the Worker file
    workerfile.open("Worker.txt");
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

    ofstream deletefile; //to delete file contents
    deletefile.open("Worker.txt",ios::trunc); 
    deletefile.close();
    ofstream finalfile;//to add the workers back to the correct file
    finalfile.open("Worker.txt",ios::app);
    while (a<i-1)
    {
        if(first==firstname[a] && last==lastname[a])
        {
            a++;
        }
        else
        {
            finalfile << firstname[a] << " " << lastname[a] << endl;
            a++;
        }
    }
        finalfile.close();


}

}