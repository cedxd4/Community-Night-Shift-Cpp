#include "Community_Main.h"



int main() 
{
    string firstname,lastname,route;
    int choice;
begin:
    cout << "1.Add Worker" << endl;
    cout << "2.Delete Worker" << endl;
    cout << "3.Show Worker Names" << endl;
    cout << "4.Add Route" << endl;
    cout << "5.Delete Route" << endl;
    cout << "6.Show Routes" << endl;
    cout << "7.Input Todays Info" << endl;
    cout << "8.Show Day Totals" << endl;
    cout << "9.Show Week Totals" << endl;
    cout << "10.Show Month Totals" << endl;
    cout << "11.Exit" << endl;

    cout << "Please enter the corresponding number you would like to run: ";
    cin >> choice;
    if(choice<1 || choice>11)
    {
        cout << "1Please enter a number between 1-11" << endl;
        cin.clear();
        cin.ignore();
        system("pause");
        goto begin;
    }
        do
        {
            switch(choice)
            {
                case 1:
                    cout << "Please enter first and last name to add: ";
                    cin >> firstname >> lastname;
                    addworker(firstname, lastname);
                    break;
                case 2:
                    cout << "Please enter first and last name to delete: ";
                    cin >> firstname >> lastname;
                    deleteworker(firstname, lastname);
                    break;
                case 3:
                    showworkers();
                    break;
                case 4:
                    cout << "Please enter the route you would like to add: ";
                    cin.ignore();
                    getline(cin, route);
                    addroutes(route);
                    break;
                case 5:
                    cout << "Please enter the route you would like to delete: ";
                    cin.ignore();
                    getline(cin, route);
                    deleteroutes(route);
                    break;
                case 6:
                    showroutes();
                    break;
                case 7:
                    addtotals();
                    break;
                case 8:
                    showdaytotals();
                    break;
                case 9:
                    showweekmonthtotals();
                    break;
                case 10:
                    showweekmonthtotals();
                    break;
                case 11:
                    return 0;
                default:
                    cout << "Please Enter a Number between 1-11: " << endl;
                    cin.clear();
                    cin.ignore();
                    system("pause");
                    break;
            }
            cout << "1.Add Worker" << endl;
            cout << "2.Delete Worker" << endl;
            cout << "3.Show Worker Names" << endl;
            cout << "4.Add Route" << endl;
            cout << "5.Delete Route" << endl;
            cout << "6.Show Routes" << endl;
            cout << "7.Input Todays Info" << endl;
            cout << "8.Show Day Totals" << endl;
            cout << "9.Show Week Totals" << endl;
            cout << "10.Show Month Totals" << endl;
            cout << "11.Exit" << endl;
            cout << "Please enter the corresponding number you would like to run: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cin >> choice;
        } while (choice != 11);

}

