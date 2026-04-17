#include <iostream>
#include <fstream>
#include <string> 
using namespace std ;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Ibrahim :
struct User{
    string username;
    string password;
    string role;

};
struct Team{
    string name;
    string coach ;
    int totalPoints;
    int titles;
};
struct Match {
    string team1;
    string team2;
    string date;   
    string status; 
    int score1;   
    int score2;    
};
struct Follow{
    string username;
    string teamName;
};
User users[100];
int usersCount = 0;
Team teams[20]; 
int teamsCount = 0;
Match matches[200];
int matchesCount = 0;
Follow follow[200];
int followCount = 0 ;
string currentLoggedInUser = "";
string currentUserRole = "";
void SaveData(){
    // Saving Teams 
    ofstream teamFile("teams.txt");
    for (int i = 0; i < teamsCount; i++){
        teamFile << teams[i].name << " " << teams[i].coach << " " << teams[i].totalPoints << " " << teams[i].titles << endl;
    }
    teamFile.close();

    // Saving Users
    ofstream userFile("users.txt");
    for (int i = 0; i < usersCount; i++){
        userFile << users[i].username << " " << users[i].password << " " << users[i].role << endl;
    }
    userFile.close();

    // Saving Matches 
    ofstream matchFile("matches.txt");
    for (int i = 0; i < matchesCount; i++){
        matchFile << matches[i].team1 << " " << matches[i].team2 << " " << matches[i].date << " " << matches[i].status << " " << matches[i].score1 << " " << matches[i].score2 << endl; 
    }
    matchFile.close();

    // Saving Followers
    ofstream followFile("follow.txt");
    for (int i = 0; i < followCount; i++){
        followFile << follow[i].username << " " << follow[i].teamName << endl;
    }
    followFile.close();
}

void LoadData() {
    // Loading Teams 
    ifstream teamFile("teams.txt");
    if (teamFile.is_open()) { 
        while (teamFile >> teams[teamsCount].name >> teams[teamsCount].coach >> teams[teamsCount].totalPoints >> teams[teamsCount].titles) {
            teamsCount++;
        }
        teamFile.close();
    }

    // Loading Users
    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        while (userFile >> users[usersCount].username >> users[usersCount].password >> users[usersCount].role) {
            usersCount++;
        }
        userFile.close();
    }

    // Loading Matches 
    ifstream matchFile("matches.txt");
    if (matchFile.is_open()) {
        while (matchFile >> matches[matchesCount].team1 >> matches[matchesCount].team2 >> matches[matchesCount].date >> matches[matchesCount].status >> matches[matchesCount].score1 >> matches[matchesCount].score2) {
            matchesCount++;
        }
        matchFile.close();
    }

    // Loading Followers
    ifstream followFile("follow.txt");
    if (followFile.is_open()) {
        while (followFile >> follow[followCount].username >> follow[followCount].teamName) {
            followCount++;
        }
        followFile.close();
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Muhammad
void FollowTeam() {

}

void FilterMatchesByTeam() {

}



int main() {
    LoadData();
    cout<<"Welcome to CounterAttack , The number 1 app for all Football team  news regarding your favorite teams and world-wide football"<<endl;
    while (true) {
        cout<<"Press 1 to Sign up."<<endl;
        cout<<"Already a user ? Press 2 to sign in. "<<endl;
        int option;
        bool choice = false;
        do {
            cin>>option;
            if (option==1) {
                choice = true;
                char choice_inner_1 ;
                do {





                    cout<<" Would you you like to stay logged in of your account ? Press Y to stay logged in , Or N to log out"<<"   ";
                    for (; ; ){
                        cin>>choice_inner_1;
                        if (choice_inner_1 !='y' &&choice_inner_1 != 'Y'&& choice_inner_1 != 'N'&& choice_inner_1 != 'n') {
                            cout<<"Option is incorrect , Please try again "<<endl;
                        }else break;
                    }
                }while (choice_inner_1== 'y' || choice_inner_1 == 'Y');
            } else if (option==2) {
                choice = true;
                char choice_inner_2 ;
                do {





                    cout<<" Would you like to stay logged in to your account ? Press Y to stay logged in , Or N to log out"<<"   ";
                    for (; ; ){
                        cin>>choice_inner_2;
                        if (choice_inner_2 !='y' &&choice_inner_2 != 'Y'&& choice_inner_2 != 'N'&& choice_inner_2 != 'n') {
                            cout<<"Option is incorrect , Please try again "<<endl;
                        }else break;
                    }
                }while (choice_inner_2 == 'y' || choice_inner_2 == 'Y');
            }else {  cout<<"Option is incorrect , Please try again "<<endl;
                cout<<"Press 1 to Sign up."<<endl;
                cout<<"Already a user ? Press 2 to sign in. "<<endl;
            }
        }while(choice==false);


















        bool continueapp=false;
        char answer;
        cout<<"Would you like to continue using the app ? Press Y if yes , N if no "<<"   ";
        while (true){
        cin>>answer;
        if (answer == 'N' || answer == 'n') {
            cout<<"Thank you for using our football app !"<<endl<<" Make sure to check again for the lastest news regarding your favorite team."<<endl;
            break;
        } else if (answer == 'Y' || answer == 'y') {
            continueapp=true;
            break;
        }
        else{
            cout<<"Option is incorrect , Please try again "<<endl;
        }
        }if (continueapp != true) {
            break;
        }
    }
    SaveData();
    return 0 ;
}