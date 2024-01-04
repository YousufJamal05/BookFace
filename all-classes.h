#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

static int ID = 1;
bool found=false;
vector<vector<bool>> connections;

class Node
{
public:
    string notification;
    Node* next;

    Node(string notification)
    {
        this->notification=notification;
        next=nullptr;
    }
};
class Updates
{
public:
   Node* front=nullptr;
   Node* rear=nullptr;

   void addUpdate(string text)
   {
    Node* n= new Node(text);
    if(front==nullptr)
    {
        front=n;
        rear=n;
    }
    else
    {
        rear->next=n;
        rear=n;
    }
   }
   void displayUpdates()
   {
    Node* temp=front;
    if(front==nullptr && rear==nullptr)
    {
        cout<<"No Updates yet. Updates will be displayed here."<<endl;
    }
    else
    {
        Node* temp=front;
        while(temp!=nullptr)
        {
            cout<<temp->notification;
            cout<<endl;
            temp=temp->next;
        }
    }
   }
};
Updates allUpdates;

class User {
private:
    string password;

public:
    string first_name;
    string last_name;
    int numOffriends;
    int ID;
    string bio="none";

    User() {
        password = "none";
        first_name = "none";
        last_name = "none";
        numOffriends = 0;
        ID=0;
    }

    User(string password, string first_name, string last_name, int ID) {
        this->password = password;
        this->first_name = first_name;
        this->last_name = last_name;
        this->numOffriends = 0;
        this->ID=ID;
    }

    void incNoOfFriends() {numOffriends++; }

    bool validate(string fname, string lname, string pw) {
        return (first_name == fname && last_name == lname && password == pw);
    }

    string getPassword() {return password;}

    void viewProfile()
    {
        cout<<first_name <<" "<<last_name<<endl;
        if(bio=="none")
        {
            string temp;
            cout<<"Your bio is empty. Add a bio to let people know about yourself"<<endl;
            cout<<"Enter Bio: ";
            getline(cin,temp);
            bio=temp;
        }
        else
        {
            cout<<bio<<endl;
        }
    }
};


class Reply {
public:
    string content;
    Reply* next;
    User *u;
    Reply(string text,User *user)
    {
        content=text;
        next=nullptr;
        u=user;
    }
};

class Comment {
public:
    string content;
    Comment* next;
    Reply* replies;
    User *u;
    int noOfreplies=0;

    Comment(string text,User *user) 
    {
        content=text;
        next=nullptr;
        replies=nullptr;
        u=user;
    }

    void addReply(string text,User *u) {
        noOfreplies++;
        Reply* n = new Reply(text,u);
        n->next = replies;
        replies = n;
    }

    void displayReplies()
    {
        Reply* temp = replies;
        while (temp!=nullptr) {
            cout <<"        "<<temp->u->first_name<<" "<<temp->u->last_name<<": "<< temp->content <<endl;
            temp = temp->next;
        }
    }
};

class UserGraph
{
public:
    vector<User> users;

    void assignIDs() 
    {
        for (int i = 0; i < users.size(); i++) 
        {
            users[i].ID = i + 1;
        }
    }

    void initializeConnectionsMatrix()
    {
        connections.resize(users.size(), vector<bool>(users.size(), false));
    }

    void retrieveData()
    {
        ifstream ifile("users.txt");
        string temp;
        string fn, ln, pwrd;
        int uid;

        users.clear();

        while (getline(ifile, temp))
        {
            istringstream sfile(temp);
            if (sfile >> uid >> fn >> ln >> pwrd)
            {
                users.emplace_back(pwrd, fn, ln,uid);
            }
        }
        assignIDs();
        initializeConnectionsMatrix();

        ID = users.empty() ? 1 : uid + 1;
    }

    User addUser(string fname, string lname, string password, int numOffriends)
    {
        ID++;
        retrieveData();
        ofstream ofile("users.txt", ios::app);

        ofile << ID << " " << fname << " " << lname << " " << password << endl;

        ofile.close();

        retrieveData();

        return users.empty() ? User() : users.back();
    }

    bool status()
    {
        return found;
    }

    User validate(string fname, string lname, string pw)
    {
        retrieveData();
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].validate(fname, lname, pw))
            {
                cout << "User found!\n";
                found = true;
                return users[i];
            }
        }
    }
    int find(string fname,string lname)
    {
        retrieveData();
       for(int i=0;i<users.size();i++)
       {
           if(users[i].first_name==fname && users[i].last_name==lname)
           {
            return users[i].ID;
           }
       }
       return 0;
    }

    bool addFriend(int senderID, string fname, string lname)
    {
        retrieveData();
        int receiverID;
        receiverID= find(fname,lname);

        if (senderID == receiverID)
        {
            cout << "User not found" << endl;
            return false;
        }
        else if(receiverID==0)
        {
            cout<<"User not found."<<endl;
            return false;
        }

        connections[senderID - 1][receiverID - 1] = true;

        string prototype = "added";
        string text = users[senderID - 1].first_name + " " + users[senderID - 1].last_name + " " + prototype + " "+users[receiverID-1].first_name+" "+users[receiverID-1].last_name;
        allUpdates.addUpdate(text);
        
        users[senderID-1].incNoOfFriends();
        users[receiverID-1].incNoOfFriends();
        
        return true;
    }

    void displayFriends(int uID)
    {
        retrieveData();
        for(int i=0;i<users.size();i++)
        {
            if(connections[uID-1][i]==true)
            {
                cout<<users[i].first_name<<" "<<users[i].last_name<<endl;
            }
        }
    }
};


class Post {
public:
    string content;
    Post* next;
    Comment* comments;
    User *user;
    int noOfcomments=0;

    Post(string text,User *us)
    {
        content=text;
        next=nullptr;
        comments=nullptr;
        user=us;
    }

    void addComment(string text,User *u) {
        noOfcomments++;
        Comment* n = new Comment(text,u);
        n->next = comments;
        comments = n;
    }

    void displayComments(User *us)  {
        Comment* temp = comments;
        char show;
        string rep,tp;
        UserGraph ug;
        string prototype="replied to";
        while (temp!=nullptr) {
            cout <<"    "<<temp->u->first_name<<" "<<temp->u->last_name<<": "<< temp->content <<endl;
            cout<<"Replies: "<<temp->noOfreplies<<endl;
            cout<<"Press 'R'to view replies,'A' to reply: ";
            cin >> show;
            cin.ignore();
            if(show =='r' || show=='R')
            {temp->displayReplies();}
            else if(show=='A' || show=='a')
            {
                cout<<"Enter Reply: ";
                getline(cin,rep);
                tp= us->first_name + " " + us->last_name + " " + prototype+" "+temp->u->first_name+" "+temp->u->last_name;
                allUpdates.addUpdate(tp);
                User* replier= new User(us->getPassword(),us->first_name,us->last_name,us->ID);
                temp->addReply(rep,replier);
            }
            temp = temp->next;
        }
    }
};

class NewsFeed 
{
public:
    Post* posts;

    NewsFeed()
    {posts=nullptr;}

    void addPost(string text,User *u) {
        User* poster= new User(u->getPassword(),u->first_name,u->last_name,u->ID);
        Post* n = new Post(text,poster);
        n->next = posts;
        posts = n;
    }

    void displayPosts(User *u)
    {
        Post *temp = posts;
        string n;
        string prototype="commented on";
        if (posts == nullptr)
        {
            cout << "News Feed is empty." << endl;
        }
        else
        {
            // UserGraph ug;
            char show;
            while (temp != nullptr)
            {
                if(connections[u->ID - 1][temp->user->ID - 1]==true || u->ID==temp->user->ID)
                {
                    cout << temp->user->first_name << " " << temp->user->last_name << " posted:" << endl;
                    cout << "---------------------------------------------------" << endl;
                    cout << temp->content << endl;
                    cout << "---------------------------------------------------" << endl;
                    cout << "Comments: " << temp->noOfcomments << endl;
                    cout << "Press 'C' to view comments, 'A' to comment: ";
                    cin >> show;
                    cin.ignore();
                    if (show == 'C' || show == 'c')
                    {
                        temp->displayComments(u);
                    }
                    else if (show == 'A' || show == 'a')
                    {
                        string cmnt;
                        cout << "Enter comment: ";
                        getline(cin, cmnt);
                        User *commenter = new User(u->getPassword(), u->first_name, u->last_name, u->numOffriends);
                        n = commenter->first_name + " " + commenter->last_name + " " + prototype + " " + temp->user->first_name+" "+temp->user->last_name+"'s post";
                        allUpdates.addUpdate(n);
                        temp->addComment(cmnt, commenter);
                    }
                }
                cout << endl;
                temp = temp->next;
            }
        }
    }
};