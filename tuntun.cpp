#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include <Windows.h>
#include<cstring>
using namespace std;
enum color{ //enumeration is a user-defined data type
	NONE,
	DARK_BLUE,
	GREEN,
	DARK_CYAN,
	DARK_RED,
	PURPLE,
	DARK_YELLOW,
	NORMAL,
	GRAY,
	BLUE,
	LIME,
	CYAN,
	RED,
	PINK,
	YELLOW,
	WHITE
};

struct Edge;

struct Vertex
{
        string userid,emailid,passcode,gen,dobirth,follower,following,messages,inbox_text;
        int no_of_followings;
         Vertex *nextVertex;  /*next vertex in the linked list of vertices*/
         Edge *firstEdge;  /*first Edge of the adjacency list of this vertex*/
}*start = NULL;

struct Edge
{
        Vertex *destVertex;  /*Destination vertex of the Edge*/
        Edge *nextEdge; /*next Edge of the adjacency list*/
};
string loginaccount();
void login();
void search(string current);
void update();
void send_message(string current);
void inbox_message(string current);
Vertex *findVertex(string u);
void insertVertex_creat();
void insertEdge(string u,string v);
void deleteEdge(string u,string v);
void deleteIncomingEdges(string u);
void deleteVertex(string u);
void following(string current);
void follower(string current);
void setcolor   (color newColor);

int main()
{
    system("cls");
    string u,v;
    int choice;
    setcolor(GRAY);
    cout<<"\n\n\n\n  ____    _     _           ____   _     _   _   _       ___ "<<endl;
	  cout<<" |____|  ||    ||  |\\  ||  |____|  ||    ||  |\\  ||     ||  ||  || "<<endl;
	  cout<<"   ||    ||    ||  | \\ ||    ||    ||    ||  | \\ ||     ||__//  ||   __     __ "<<endl;
	  cout<<"   ||    \\     //  ||\\\ ||    ||    \\     //  ||\\ ||     ||  \\   || ||  || ||  || "<<endl;
	  cout<<"   ||     \\___//   || \ ||    ||     \\___//   || \ ||     ||__||  || ||__|| ||__|| "<<endl;
	  cout<<"                                                                            //|| "<<endl;
	  cout<<"                                                                           // || "<<endl;
	cout<<"                                                                           ||_|| "<<endl;




    while(1)

    {
        system("COlOR 3f");
        //system("cls");
        cout<<"\n\n\n\n1::Create account\n2::login account\n3::exit\n";
    cin>>choice;
    switch(choice)
    {
        case 1:insertVertex_creat(); break;
        case 2:login();break;
        case 3: exit(0);
        default: cout<<"invalid choice\n";
    }

}
return 0;
}

void insertVertex_creat()
{
    system("cls");

          char pin[20];
    int a=0;
        string user,email,password,gender,dob;
   cout<<"Username (without_space): ";
   cin>>user;
   cout<<"\nEmail:";
   cin>>email;
   cout<<"\nPasscode:";
    while(pin[a-1]!='\r')
    {
        pin[a]=getch();
        if(pin[a-1]!='\r')
        {
            cout<<"*";
        }
        a++;
    }
    pin[a-1]='\0';
cout<<endl;
password=pin;
//cout<<"show password:"<<password<<endl;
   cout<<"\nGender:";
   cin>>gender;
   cout<<"\nDate of Birth(DD/MM/YYYY):";
   cin>>dob;
   cout<<"\nCONGRATULATIONS: Your account is successfully created:";
         Vertex *newnode,*ptr;
        newnode = new Vertex;
        newnode->userid=user;
    newnode->emailid=email;
    newnode->passcode=password;
    newnode->gen=gender;
    newnode->dobirth=dob;
    newnode->messages="No Messages";
    newnode->inbox_text="NULL";
    newnode->follower="ZERO";
    newnode->following="ZERO";
    newnode->no_of_followings=0;
        newnode->nextVertex = NULL;
        newnode->firstEdge = NULL;

        if(start == NULL)
        {
                start = newnode;
                return;
        }
        ptr = start;
        while(ptr->nextVertex!=NULL)
                ptr = ptr->nextVertex;
        ptr->nextVertex = newnode;
}/*End of insertVertex()*/
void login()
{
    system("cls");
    setcolor(YELLOW);
    string current=loginaccount();
    string blockuser;
    int x;
    int n;
    while(1){
    cout<<"\n\t\t\t\tCONTROL PANEL\n";
    cout<<"\n\n1:: search account\n2::update account\n3::followers\n4::followings\n5::delete account\n6::block account\n7::log out\n";
    cin>>x;
    switch(x)
    {
        case 1:search(current);break;
        case 2: update();break;
        case 0: system("cls");setcolor(RED);
         cout<<"\n\n\t\t\t\tMESSAGE BOX\n";
         cout<<"\n\n1::INBOX\n2::SEND MESSAGE\n3::BACK\n";
         cin>>n;
         switch(n){ case 1:inbox_message(current);break;
                    case 2: send_message(current);break;
                    case 3: return;
                    default: cout<<"Invalid choice";
         } break;
        case 3:follower(current);break;
       fflush(stdin);
        case 4:following(current);break;
         case 5: deleteIncomingEdges(current);deleteVertex(current);goto back;
         case 6:setcolor(DARK_RED); cout<<"\nUsername(to be BLOCKED)";
                cin>>blockuser;
                deleteEdge(current,blockuser);break;
        case 7: return;
        default : cout<<"invalid choice:";
    }
    }
    back: return;
}
string loginaccount()
{
   again: char pin[20];
    int a=0;
    string username,password;
	Vertex *current_acc;
	cout<<"\nUsername:";
	cin>>username;
	   cout<<"\nPasscode:";
    while(pin[a-1]!='\r')
    {
        pin[a]=getch();
        if(pin[a-1]!='\r')
        {
            cout<<"*";
        }
        a++;
    }
    pin[a-1]='\0';
cout<<endl;
password=pin;
cout<<"show password:"<<password<<endl;
	for(current_acc=start;current_acc!=NULL;current_acc=current_acc->nextVertex)
	{
		if(current_acc->userid==username&&current_acc->passcode==password)
		{
		    cout<<"You are succefully logged in.";

		    //curr_acc=current_acc;
		    //curr_acc->prev=curr_acc->next=NULL;
			return current_acc->userid;
		}
	}
	setcolor(RED);cout<<"\nUnable to login. Username or passcode is INCORRECT:";
	goto again;

}
 void search(string current)
{
    system("cls");
	string username;char ch;
	Vertex *temp;
	cout<<"\n\t\t\t\tSEARCH ACCOUNT\n\nUsername:";
	cin>>username;
	temp=findVertex(username);
	if(temp!=NULL){
			cout<<"\nUsername:"<<temp->userid<<"\nEmail:"<<temp->emailid<<"\nGender:"<<temp->gen<<"\nDate of Birth:"<<temp->dobirth;
			cout<<"\nFollow  "<<temp->userid<<"(Y/N)";
			cin>>ch;
			if(ch=='Y'||ch=='y')
            {
                cout<<"\nYou followed  "<<temp->userid;
                temp->follower=current;
                insertEdge(current,temp->userid);

            }

			return;

        }
	printf("NO search Results !!! The user does not EXIST\n");
}


void deleteVertex(string u)
{
         Vertex *tmp,*q;
         Edge *p,*temporary;
        if(start == NULL)
        {
                printf("\nNo vertices to be deleted\n");
                return;
        }
        if(start->userid == u)/* Vertex to be deleted is first vertex of list*/
        {
                tmp = start;
                start = start->nextVertex;
        }
        else /* Vertex to be deleted is in between or at last */
        {
        q = start;
                while(q->nextVertex != NULL)
                {
                        if(q->nextVertex->userid == u)
                                break;
                        q = q->nextVertex;
                }
                if(q->nextVertex==NULL)
                {
                        printf("Vertex not found\n");
                        return;
                }
                else
                {
                        tmp = q->nextVertex;
                        q->nextVertex = tmp->nextVertex;
                }
        }
        /*Before freeing the node tmp, free all edges going from this vertex */
        p = tmp->firstEdge;
        while(p!=NULL)
        {
                temporary = p;
                p = p->nextEdge;
                free(temporary);
        }
        free(tmp);
}/*End of deleteVertex()*/

void deleteIncomingEdges(string u)
{
        Vertex *ptr;
        Edge *q,*tmp;

        ptr = start;
        while(ptr!=NULL)
        {
                if(ptr->firstEdge == NULL)   /*Edge list for vertex ptr is empty*/
                {
                        ptr = ptr->nextVertex;
                        continue; /* continue searching in other Edge lists */
                }

                if(ptr->firstEdge->destVertex->userid == u)
                {
                        tmp = ptr->firstEdge;
                        ptr->firstEdge = ptr->firstEdge->nextEdge;
                        free(tmp);
                        continue; /* continue searching in other Edge lists */
                }
                q = ptr->firstEdge;
                while(q->nextEdge!= NULL)
                {
                        if(q->nextEdge->destVertex->userid == u)
                        {
                                tmp = q->nextEdge;
                                q->nextEdge = tmp->nextEdge;
                                free(tmp);
                                continue;
                        }
                        q = q->nextEdge;
                }
                ptr = ptr->nextVertex;
        }

}


 Vertex *findVertex(string u)
{
        Vertex *ptr,*loc;
        ptr = start;
        while(ptr!=NULL)
        {
                if(ptr->userid == u )
                {
                        loc = ptr;
                        return loc;
                }
                else
                        ptr = ptr->nextVertex;
        }
        loc = NULL;
        return loc;
}

void insertEdge(string u,string v)
{
         Vertex *locu,*locv;
         Edge *ptr,*tmp;

        locu = findVertex(u);
        locv = findVertex(v);

        if(locu == NULL )
        {
                cout<<"\nStart vertex not present, first insert vertex \n"<<u;
                return;
        }
        if(locv == NULL )
        {
                cout<<"\nUser does not exist.\n"<<v;
                return;
        }
        tmp = new Edge;
        tmp->destVertex = locv;
        tmp->nextEdge = NULL;

        if(locu->firstEdge == NULL)
        {
                 locu->firstEdge = tmp;
         return;
        }
        ptr = locu->firstEdge;
        while(ptr->nextEdge!=NULL)
                ptr = ptr->nextEdge;
        ptr->nextEdge = tmp;

}/*End of insertEdge()*/

void deleteEdge(string u,string v)
{
        Vertex *locu;
         Edge *tmp,*q;

        locu = findVertex(u);

        if(locu == NULL )
        {
                printf("\nStart vertex not present\n");
                return;
        }
        if(locu->firstEdge == NULL)
        {
                printf("\nEdge not present\n");
                return;
        }

        if(locu->firstEdge->destVertex->userid == v)
        {
                tmp = locu->firstEdge;
                locu->firstEdge = locu->firstEdge->nextEdge;
                free(tmp);
                return;
        }
        q = locu->firstEdge;
        while(q->nextEdge != NULL)
        {
                if(q->nextEdge->destVertex->userid == v)
                {
                        tmp = q->nextEdge;
                        q->nextEdge = tmp->nextEdge;
                        free(tmp);
                        return;
                }
                q = q->nextEdge;
        }/*End of while*/

        printf("\nThis Edge is not present in the graph\n");
}/*End of deleteEdge()*/
void update()
{
    system("cls");setcolor(RED);
relogin:  string new_gmail,password;Vertex *ptr;
    cout<<"Please login to your account:";
    cout<<"\nEnter Email:";
    cin>>new_gmail;

        ptr = start;
        while(ptr!=NULL)
        {
                if(ptr->emailid == new_gmail )
                {
                          cout<<"\nEnter New Passcode:";
   // cout<<"\Re-enter Passcode:";
    cin>>password;
   // temp->emailid=new_gmail;
    ptr->passcode=password;
     cout<<"Passcode is changed successfully:";
                        return;
                }
                else
                        ptr = ptr->nextVertex;
        }
            cout<<"\nINVALID Email id!!\n\n";
            goto relogin;

    }
void send_message(string current)
{
    Vertex* temp,*messaging;
    Edge *q;
    string curr=current;string message_to,inbox;
    temp=findVertex(curr);
    q=temp->firstEdge;

    while(q!=NULL)
    {
        cout<<q->destVertex->userid<<endl;
        q=q->nextEdge;
    }
    cout<<"\n\n message to(Username):";
    cin>>message_to;
    messaging=findVertex(message_to);
    setcolor(YELLOW);
       cout<<"\nmessage: ";
            cin>>inbox;
            //messaging->messages=inbox;


   q=temp->firstEdge;
    while(q!=NULL)
    {
        if(q->destVertex->userid==message_to)
        {
            q->destVertex->messages=inbox;
            return;

        }
         q=q->nextEdge;
    }


}
void inbox_message(string current)
{
    Vertex* temp;
    //Edge *q;
   // string curr=current;//string message_to,inbox;
   temp=findVertex(current);
    if(temp->inbox_text=="NULL")
    {
        cout<<"\n\nZERO follower\n";
    }
    else
    {
        cout<<temp->inbox_text;
    }

    return;
}
 void following(string current)
{
        Vertex *ptr;
        Edge *q;
        string curr=current;
        ptr=findVertex(curr);

                q = ptr->firstEdge;
                if(q==NULL)
                   {
                     cout<<"\nYou have ZERO followings.";
                   }

                while(q!=NULL)
               {
                    cout<<"You followed "<<q->destVertex->userid<<endl;
                       // ptr->no_of_followings++;
                        q = q->nextEdge;
                }


                return;

                //return ptr->no_of_followings;


}
void follower(string current)
{
    Vertex* temp;
    //Edge *q;
   // string curr=current;//string message_to,inbox;
   temp=findVertex(current);
    if(temp->follower=="NULL")
    {
        cout<<"\n\nNO MESSAGES\n";
    }
    else
    {
        cout<<temp->follower<<" followed you\n";
    }

    return;
}
void setcolor   (color newColor)
{
	//A "handle" is a generic identifier (typically a pointer) used to represent something.
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), (newColor ) );
}


