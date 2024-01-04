#include <iostream>
#include <vector>
#include <windows.h>
#include "frontend.h"
#include "all-classes.h"
#include <fstream>
#include <limits>
using namespace std;

NewsFeed nf;
void mainMenu(User *u)
{
    UserGraph ug;
    system("cls");
    system("color 02");
    int choice;
    string text;
    cout<<"Welcome "<<u->first_name<<" "<<u->last_name<<endl;
    
    while(true)
    {
        allUpdates.displayUpdates();
        cout<<"Press"<<endl<<"1.To add a post"<<endl<<"2.To go to news feed"<<endl<<"3. To view Profile"<<endl<<"4.Add friend."<<endl<<"5.To log out/exit"<<endl;
        cout<<"Enter choice: ";
        cin >> choice;

        cin.ignore();

        if(choice==1)
        {
            cout << "Enter text you want to post: ";
            getline(cin, text);
            nf.addPost(text, u);
        }
        else if(choice==2)
        {
            nf.displayPosts(u);
        }
        else if(choice==3)
        {
            u->viewProfile();
            cout<<"Friends: "<<endl;
            ug.displayFriends(u->ID);
            cout<<endl;
            cout<<endl;
        }
        else if(choice==4)
        {
            string fname,lname;
            cout<<"Enter first name: ";
            cin>>fname;
            cout<<"Enter last name: ";
            cin >> lname;
            ug.addFriend(u->ID,fname,lname);
        }
        else if(choice==5)
        {
            return;
        }
    }
}
void loginSignupPage(int choice)
{   
    string credentials[3];
    getInput(choice,credentials);
    if(choice==1)
    {
        UserGraph ug;
        User u;
        bool stat;
      check:
        u=ug.validate(credentials[0],credentials[1],credentials[2]);
        stat= ug.status();
        if(stat)
        {
            mainMenu(&u);
        }
        else
        {
            system("cls");
            system("color 04");
            cout<<"The password you have entered is incorrect."<<endl<<"Please enter again.";
            getInput(1,credentials);
            goto check;
        }
    }
    else if(choice==2)
    {
        UserGraph ug;
        User u;
        u=ug.addUser(credentials[0],credentials[1],credentials[2],0);
        mainMenu(&u);
    }
}
int main()
{
    system("color 02");
    UserGraph ug;
    ug.retrieveData();
    int choice;
   login:
    cout<<"---------------------------------------------"<<endl;
    cout<<"|         WELCOME TO BOOKFACE               |"<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"Press"<<endl<<"1 to Log in."<<endl<<"2 to Sign Up."<<endl<<"3 to exit.";
    cin >> choice;
    cin.ignore();
    if(choice!=3)
    {
        loginSignupPage(choice);
        system("cls");
        goto login;
    } 
    else
    {
        system("cls");
        exit(0);
    }
}