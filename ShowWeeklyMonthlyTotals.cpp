#include "DailyTotals.h"


void showweekmonthtotals()
{
    string firstname[20], lastname[20], starttime, endtime, stires, totaltime,newdate,filepath,stireperhour;
    int beginmonth,beginday,beginyear,endmonth,endday,endyear,tires[20]={0},count[20]={0};
    double tireperhour[20]={0};
    char dash1,dash2;

    begindate:
    cout << "What Start date would you like to see (MM-DD-YYYY): ";
    cin >> beginmonth >> dash1 >> beginday >> dash2 >> beginyear;
    if(beginmonth<1||beginmonth>12||dash1!='-'||beginday<1||beginday>31||dash2!='-'||beginyear<2020||beginyear>3020)
    { 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
        goto begindate;
    }
    date:
    cout << "What End date would you like to see (MM-DD-YYYY): ";
    cin >> endmonth >> dash1 >> endday >> dash2 >> endyear;
    if(endmonth<1||endmonth>12||dash1!='-'||endday<1||endday>31||dash2!='-'||endyear<2020||endyear>3020)
    { 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
        goto date;
    }
    if(endday<beginday)
    {
        if(endmonth<beginmonth)
        {
            if(endyear<=beginyear)
            {
                cout << "End Date must be greater than Begin Date" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                goto date;
            }
        }
    }
    for(int k=0;k<endyear;k++)
    {
        for(int j=0;j<endmonth&&j<=12;j++)
        {
            for(int a=0;a<endday&&a<32;a++)
            {    
                ifstream monthlyfile;
                int i=0;
                newdate=to_string(beginmonth+j)+dash1+to_string(beginday+a)+dash2+to_string(beginyear);
                newdate=newdate+".txt";
                string actualmonth[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
                filepath="./"+to_string(beginyear)+"/"+actualmonth[(beginmonth+j)-1]+"/"+newdate;  
                cout << filepath << endl;  
                monthlyfile.open(filepath.c_str());
                
                if(monthlyfile.is_open())
                {
                    while ( 1 )
                    {
                        monthlyfile >> firstname[i] >> lastname[i] >> starttime >> endtime >> stires >> totaltime >> stireperhour;
                        tires[i]=tires[i]+stoi(stires);
                        tireperhour[i]=tireperhour[i]+stoi(stireperhour);
                        count[i]++;
                        if(monthlyfile.eof())
                            break;
                        i++;
                        
                        
                    }
                }
                monthlyfile.close();
            }
                beginday=1;
        }
        if(beginyear==endyear)
        {
            break;
        }
        else
        {
            beginyear=beginyear+1;
            filepath = " ";
            beginmonth=1;
            beginday=1;
        }
    }
    for(int c=0;c<20;c++)
    {
            cout << firstname[0] << " " << lastname[0] << "\t" << tires[0] << "\t" << tireperhour[0]/count[0] << endl; 
            cout << firstname[1] << " " << lastname[1] << "\t" << tires[1] << "\t" << tireperhour[1]/count[1] << endl;
            cout << firstname[2] << " " << lastname[2] << "\t" << tires[2] << "\t" << tireperhour[2]/count[2] << endl;
    }
    system("pause");

}