#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class bank{
public:
    char name[100],add[1000],type;
    int age,balance=0;
    void open_account(char* s);
    void deposit_money();
    void withdraw_money();
    void display_account();
};
void bank :: open_account(char* s){
    strcpy(name,s);
    cout<<"\n\t\t\tEnter your age : ";
    cin>>age;
    cout<<"\n\t\t\tEnter your address : ";
    cin.ignore();
    cin.getline(add,1000);
    cout<<"\n\t\t\tEnter what type of account do you want savings(s) or current(c) : ";
    cin>>type;
    cout<<"\n\t\t\tEnter the amount for deposit : ";
    cin>>balance;
    cout<<"\n\t\t\t\tYour account is created"<<endl;
}
void bank :: deposit_money(){
    int a;
    cout<<"\n\n\t\t\tEnter the amount of money to deposit : ";
    cin>>a;
    balance+=a;
    cout<<"\n\t\t\t\tAmount deposited successfully "<<endl<<endl<<"\n\t\t\t\tTotal balance amount you have : "<<balance<<endl;
}
void bank :: withdraw_money(){
    int a;
    cout<<"\n\n\t\t\tEnter the amount of money to withdraw : ";
    cin>>a;
    balance-=a;
    cout<<"\n\t\t\t\tAmount withdrawn successfully "<<endl<<endl<<"\n\t\t\t\tTotal balance amount you have : "<<balance<<endl;
}
void bank :: display_account(){
    cout<<"\n\n\t\t\tYour name : "<<name<<endl;
    cout<<"\n\t\t\tYour age : "<<age<<endl;
    cout<<"\n\t\t\tYour address : "<<add<<endl;
    cout<<"\n\t\t\tYour account type : ";
    if(type=='s' || type=='S')cout<<"Savings account "<<endl;
    else if(type=='c'|| type=='C')cout<<"Current account"<<endl;
    else{cout<<type<<endl;}
    cout<<"\n\t\t\tYour deposited amount : "<<balance<<endl;
}
struct account{
    char name[100];
    bank ob;
    struct account* next;
};
struct account* head;
void create(){
    char n[100];
    cout<<"\n\t\t\tEnter your User name : ";
    cin.ignore();
    cin.getline(n,100);
    account* temp2=head;
    while(temp2){
        if(strcmp(temp2->name,n)==0){
            cout<<"\n\t\t\tThis username already exist, try with another name "<<endl;
            return;
        }
        temp2=temp2->next;
    }
    account* temp=new account();
    strcpy(temp->name,n);
    temp->ob.open_account(temp->name);
    temp->next=head;
    head=temp;
}
void del(account* temp){
    struct account* temp1=head;
    if(temp==temp1){
        head=head->next;
        free(temp);
        cout<<"\n\t\t\tAccount deleted successfully "<<endl;
        return;
    }
    while(temp1->next!=temp){
        temp1=temp1->next;
    }
    temp1->next=temp1->next->next;
    free(temp);
    cout<<"\n\t\t\tAccount deleted successfully "<<endl;
}
void findacc(int a){
    char name[100];
    cout<<"\n\t\t\tEnter your User name : ";
    cin.ignore();
    cin.getline(name,100);
    account* temp=head;
    while(temp){
        if(strcmp(temp->name,name)==0){
            switch(a){
                case 2:temp->ob.deposit_money();break;
                case 3:temp->ob.withdraw_money();break;
                case 4:temp->ob.display_account();break;
                case 5:del(temp);break;
            }
            return;
        }
        temp=temp->next;
    }
    cout<<"\n\t\t\tAccount doesn't exist"<<endl;
}
int main(){
    head=NULL;
    int op;
    char ch;
    menustart:
        cout<<"\t\t\t\tWelcome to our bank "<<endl<<endl;
        cout<<"\t\t\t1) Open new account "<<endl;
        cout<<"\t\t\t2) Deposit money "<<endl;
        cout<<"\t\t\t3) Withdraw money "<<endl;
        cout<<"\t\t\t4) Display account "<<endl;
        cout<<"\t\t\t5) Delete account "<<endl;
        cout<<"\t\t\t6) Exit "<<endl<<endl;
        cout<<"\t\t\tSelect any one option [1/2/3/4/5/6] : ";
        cin>>op;
        switch(op){
            case 1:create();break;
            case 2:findacc(2);break;
            case 3:findacc(3);break;
            case 4:findacc(4);break;
            case 5:findacc(5);break;
            case 6:exit(0);
            default :cout<<"\n\t\t\tInvalid choice... Please Try Again.."<<endl;
        }
        cout<<"\n\t\t\t\tThank you for using our bank"<<endl<<endl;
        cout<<"\n\t\t\t\tPress any button to continue "<<endl;
        getch();
        system("cls");
        goto menustart;

}
