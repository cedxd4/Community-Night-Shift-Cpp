#include "DailyTotals.h"

void showdaytotals()
{
    string firstname[20], lastname[20], starttime, endtime, tires, totaltime,newdate,filepath,tireperhour;
    int month,day,year;
    char dash1,dash2;
    int i=0;
    ifstream dailyfile;
date:
    cout << "What date would you like to see (MM-DD-YYYY): ";
    cin >> month >> dash1 >> day >> dash2 >> year;
    if(month<1||month>12||dash1!='-'||day<1||day>31||dash2!='-'||year<2020||year>3020)
    { 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
        goto date;
    }
    newdate=to_string(month)+dash1+to_string(day)+dash2+to_string(year);
    newdate=newdate+".txt";
    string actualmonth[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    filepath="./"+to_string(year)+"/"+actualmonth[month-1]+"/"+newdate;  
    cout << filepath << endl;  
    dailyfile.open(filepath.c_str());
    cout << "   Name \t" << "Start Time\t" << "End Time\t" << "Tires\t" << "Total Time\t" << "Tire Per Hour" << endl;
    if(dailyfile.is_open())
    {
        while ( 1 )
        {
            dailyfile >> firstname[i] >> lastname[i] >> starttime >> endtime >> tires >> totaltime >> tireperhour;
            if(dailyfile.eof())
                break;
            cout << firstname[i] << " " << lastname[i] << "\t  " << starttime << "\t\t  " << endtime << "\t\t  " << tires << "\t  " << totaltime << "\t\t    " << tireperhour << endl;
            i++;
            
        }
    }
    dailyfile.close();
    system("pause");
}
