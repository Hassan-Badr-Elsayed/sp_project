#include <iostream>
#include <fstream>
#include <string> 
#include <conio.h>  // for password 
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

int MainMenuOption() {
    cout<<"Press 1 to Sign up."<<endl;
    cout<<"Already have an account ? Press 2 to sign in. "<<endl;
    int result;
    while (true) {
        cin>>result;
        if (result == 1||result==2) {
            return result;
        }   cout<<"Incorrect option , please Try again "<<endl;
        cout<<"Are you a user ? Press 1 to sign in to your account"<<endl;
        cout<<"Are you an admin ? Press 2 to sign in to your account"<<endl;
    }
}

bool AskToContinue() {
    char answer;
    cout<<"Would you like to continue using the app ? Press Y if yes , N if no "<<"   ";
    while (true) {
        cin>>answer;
        if (answer == 'N' || answer == 'n') {
            cout<<"Thank you for using our football app !"<<endl<<" Make sure to check again for the lastest news regarding your favorite team."<<endl;
            return false;
        }
        if (answer=='Y' || answer=='y') {
            return true;
        }
        cout<<"Option is incorrect , Please try again "<<endl;
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
////Hassan Tarek

//////////////////////////////////////// update match result (function definition)
void UpdateMatchResult(){
    
/////////////////////////////////////// print the upcoming matches
cout<<"update match results"<<endl;
bool upcoming = false ;
cout<<"current upcoming matches"<<endl;
for ( int i = 0 ; i < matchesCount ; i++ ){

if( matches[i].status == "upcoming" ){
cout<<matches[i].team1<<" "<<matches[i].team2<<" "<<matches[i].date<<" "<<matches[i].time<<endl;         // Error: .time is not in struct 
upcoming = true ;
}
}

if(!upcoming){
cout<<"there is no upcoming matches :("<<endl;
return;
}



///////////////////// input the two teams
string input_team1 ;
string input_team2 ;
cout<<"enter team 1"<<endl;
cin>>input_team1;
cout<<"enter team 2"<<endl;
cin>>input_team2;


//////////////////// search for the match 
bool matchfound = false ;
for ( int i = 0 ; i < matchesCount ; i++ ) 
{    
if( matches[i].team1 == input_team1 && matches[i].team2 == input_team2 && matches[i].status == "upcoming" ){   
cout<<"Match found!"<<endl;
cout<<"Enter final score for "<< matches[i].team1<<endl;
cin>>matches[i].score1;            
cout<<"Enter final score for "<< matches[i].team2<<endl;
cin>>matches[i].score2;
matches[i].status = "past";             
cout<<"Match updated successfully!"<<endl;
matchfound = true;
break;
}
}

if(!matchfound)
cout <<"Error: Match not found or it is already played.Please check your spelling :)"<< endl;


}



//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Joe 

string inputPassword() {
    string password = "";
    int ch;

    while (true) {
        ch = _getch();

        if (ch == 13) { // ASCII code for Enter
            break;
        }
        else if (ch == 8) { // ASCII code for Backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; // **|* -> ** | -> **|
            }
        }
        else {
            password += (char)ch;
            cout << "*";
        }
    }

    cout << '\n';
    return password;
}

void Register() {
    User newUser;

    // USERNAME
    while (true) {

        cout << "Enter username: ";
        cin >> newUser.username;

        bool validUsername = true;
        for (int i = 0; i < usersCount; i++) {
            if (users[i].username == newUser.username) {
                cout << "Username already exists!\n";
                validUsername = false;
                break;
            }
        }

        if (validUsername)break;
    }


    // PASSWORD
    while (true) {
        cout << "Enter password: ";
        newUser.password = inputPassword();

        if (newUser.password.length() < 4) {
            cout << "Password too short!\n";
        }
        else {
            break;
        }
    }


    // ROLE
    while (true) {

        cout << "Enter role (admin/user): ";
        cin >> newUser.role;

        if (newUser.role == "admin" || newUser.role == "user") {
            break;
        }
        cout << "Invalid role!\n";
    }

    //SAVEUSER
    if (usersCount >= 100) {
        cout << "User limit reached!\n";
        return;
    }
    users[usersCount] = newUser;
    usersCount++;

    cout << "Registered successfully!\n";
}

void Login() {
    while (true) {

        string username, password;

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        password = inputPassword();

        for (int i = 0; i < usersCount; i++) {
            if (users[i].username == username && users[i].password == password) {

                currentLoggedInUser = username;
                currentUserRole = users[i].role;

                cout << "Login successful!\n";
                cout << "Role: " << currentUserRole << endl;
                return;
            }
        }

        cout << "Invalid username or password!\n";

        char choice;
        cout << "Try again? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            return;
        }
    }


}

void Logout() {
    currentLoggedInUser = "";
    currentUserRole = "";

    cout << "Logged out successfully!\n";
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    LoadData();
    cout<<"Welcome to CounterAttack , The number 1 app for all Football team  news regarding your favorite teams and world-wide football"<<endl;
    while (true) {
        int option=MainMenuOption();
        if (option==1) {
            Register();                    //handle registering



        }

        else if (option==2) {
            Login();            //handles Sign in
            if (currentUserRole == "admin") {
                int ChoiceAdmin;
                cout<<"What would you like to do? Press 1 for ...,2 for .. ,3 for ..,4 to logout"<<endl;
                cin>>ChoiceAdmin;
                /*
                while(true){
                    adminMenu()
                    if (choice==1){
                        1)fun1()
                     }
                     if (choice==2){
                     2)fun2()
                     }
                       if (choice==3){
                       3)fun3()
                      }
                      if (choice==4){
                        4)logout()
                            break;
                      }
                }
                */
            }
            else if (currentUserRole == "user") {
                int ChoiceUser;
                cout<<"What would you like to do? Press 1 for ...,2 for .. ,3 for ..,4 to logout"<<endl;
                cin>>ChoiceUser;
                /*
                while(true){
                    UserMenu()
                    if (choice==1){
                        1)fun1()
                     }
                     if (choice==2){
                     2)fun2()
                     }
                       if (choice==3){
                       3)fun3()
                      }
                      if (choice==4){
                        4)logout()
                            break;
                      }
            }*/
            }









            if (AskToContinue()==false) {
                break;
            }

        }
    }
    SaveData();
    return 0 ;
}
