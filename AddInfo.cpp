#include "DailyTotals.h"

void makefolder(string,string);

void addtotals() //Add the info for the day
{
    string routename[100],temproute,sstartmin,sendmin,newdate,filepath;
    char amorpm,c,dash1,dash2;
    int numoftires, numofroutes=0, numofpeople=0, whodidroute, totaltires[100]={0},month,day,year;
    double starthour, startmin,endhour,endmin, timetaken,tireperhour;
    ifstream routefile; //Reads all the routes in from the Route file
    routefile.open("Route.txt");
    if(routefile.is_open())
    {
        while ( 1 )
        {
           getline(routefile, temproute);
           routename[numofroutes]=temproute;
            numofroutes++;
            if (routefile.eof())
				break;
        }
    }
    routefile.close();
    string firstname[20],lastname[20];
    ifstream workerfile; //Reads all the workers in from the Worker file
    workerfile.open("Worker.txt");
    if(workerfile.is_open())
    {
        while ( 1 )
        {
            workerfile >> firstname[numofpeople] >> lastname[numofpeople];
            numofpeople++;
            if (workerfile.eof())
				break;
        }
    }
    workerfile.close();
date: //gets the date from the user.
    cout << "Please enter the date in the form MM-DD-YYYY: ";
    cin >> month >> dash1 >> day >> dash2 >> year;
    if(month<1||month>12||dash1!='-'||day<1||day>31||dash2!='-'||year<2020||year>3020)
    { 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
        goto date;
    }
    for(int c=0;c<numofroutes-1;c++)//goes through all the routes and waits for input on who did it and how many tires they picked.
    {
        for(int b=0;b<numofpeople-1;b++)
        {
            cout << b+1 << ". " << firstname[b] << " " << lastname[b] << endl;
        }
backagain:
        cout << routename[c] << " Enter who did it using the associated number: ";
        cin >> whodidroute;
        if(whodidroute<1 || whodidroute>numofpeople-1)
        {
            cout << "Please enter a number between 1-" << numofpeople-1 << endl;
            cin.clear();
            cin.ignore();
            system("pause");
            goto backagain;
        }
        cout << "Enter how many tires was picked: ";
        cin >> numoftires;
        totaltires[whodidroute-1]=totaltires[whodidroute-1]+numoftires;

    }
    ofstream dailyfile; //opens file to put info for the day date, first/last name, start/end time, how many picked and how long it took.
    newdate = to_string(month)+dash1+to_string(day)+dash2+to_string(year);
    newdate = newdate+".txt";
    makefolder(to_string(year),to_string(month));
    string actualmonth[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    filepath = "./"+to_string(year)+"/"+actualmonth[month-1]+"/"+newdate;
    cout << filepath << endl;
    dailyfile.open(filepath.c_str());
    for(int b=0;b<numofpeople-1;b++)
        {
            if(totaltires[b]==0)
            {
            }
            else
            {
starttime:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "What is the start time for " << firstname[b] << " " << lastname[b] << " (HH:MM A/P)? ";
                cin >> starthour >> c >> sstartmin >> amorpm;
                startmin = stoi(sstartmin);
                if(starthour>1&&starthour<12&&startmin>=0&&c==':'&&startmin<60)
                {
                    if(toupper(amorpm)=='A'||toupper(amorpm)=='P')
                    {
                        goto endtime;
                    }
                    else
                    {
                        cout << "Please enter the start time in format HH:MM A/P" << endl;
                        cin.clear();
                        cin.ignore();
                        system("pause");
                        goto starttime;
                    }
                }
                else
                {
                    cout << "Please enter the start time in format HH:MM A/P" << endl;
                    cin.clear();
                    cin.ignore();
                    system("pause");
                    goto starttime;

                }
endtime:
                cin.clear();
                cin.ignore();
                cout << "What is the end time for " << firstname[b] << " " << lastname[b] << "(HH:MM A/P)? ";
                cin >> endhour >> c >> sendmin;
                endmin = stoi(sendmin); 
                if(endhour>0&&endhour<12&&c==':'&&endmin>=0&&endmin<60)
                {
                    if(toupper(amorpm)=='A'||toupper(amorpm)=='P')
                    {
                        goto after;
                    }
                    else
                    {
                        cout << "Please enter end time in format HH:MM A/P" << endl;
                        cin.clear();
                        cin.ignore();
                        system("pause");
                        goto endtime;
                    }
                }
                else
                {
                    cout << "Please enter end time in format HH:MM A/P" << endl;
                    cin.clear();
                    cin.ignore();
                    system("pause");
                    goto endtime;
                }
after:
                timetaken = (endhour+(endmin/60))-(starthour+(startmin/60));
                tireperhour = totaltires[b]/timetaken;
                dailyfile << setw(8) << left << firstname[b] << setw(5) << left << lastname[b] << 
                setw(5) << right << fixed << setprecision(0) << starthour 
                << ":" << sstartmin << setw(10) << right << endhour << ":" << sendmin 
                << setw(10) << right << totaltires[b] << setw(10) << right <<  fixed 
                << setprecision(2) << timetaken << setw(10) << right << tireperhour << endl;
        
                
            }
        }
            dailyfile.close();


}

void makefolder(string years,string months)
{
    string actualmonth[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    string filepath;
    filepath = "./"+years;
    mkdir(filepath.c_str());
    filepath = filepath +"./"+actualmonth[stoi(months)-1];
    mkdir(filepath.c_str());
}