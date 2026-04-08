#include <iostream>
#include <iomanip>
using namespace std;


struct stmatch {
    string team1;
    string team2;
    int score1;
    int score2;
    string Time;
    string date;
    string status;
};
stmatch match[300];
void DisplayMatches()
{
    int numberofmatches = 300;
    for (int i = 0; i < numberofmatches; i++)
    {
        if (match[i].status == "past")
        {
            cout << setw(11.5)<< match[i].status << endl;
            cout << match[i].team1 << setw(15) << match[i].team2 << endl;
            cout << match[i].score1 << setw(15) << match[i].score2 << endl;
            cout << setw(11) << match[i].Time << endl;
            cout << setw(13) << match[i].date << endl;
        }
        else if (match[i].status == "upcoming")
        {
            cout << setw(11.5) << match[i].status << endl;
            cout << match[i].team1 << setw(15) << match[i].team2 << endl;
            cout << match[i].score1 << setw(15) << match[i].score2 << endl;
            cout << setw(11) << match[i].Time << endl;
            cout << setw(13) << match[i].date << endl;
        }
    }
}
int main()
{
    
    match[0] = { "AlAhly","alzamalek",3,2,"09:00","7/4/2026","past" };

    DisplayMatches();



    return 0;
}
