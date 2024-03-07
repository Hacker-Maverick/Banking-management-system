#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <fstream>

using namespace std;

//Class of transaction details
class trans{
public:
    string time;
    double amount;
    string tran_type;
    double prev_bal;
    double current_bal;
};

//Class of customers
class customer{
public:
    string username;
    string name;
    long long int acc_no;
    double bbal;
    long long int ph_no;
    string pan;
    long long int aadharno;
    string address;
    string login_pass;
    int login_pin;
    string card_no;
    string valid_thru;
    int cvv;
    int card_pin; 
    double loan;
    long long int max_bal;
    long long int l_time;
    vector<trans> tranj;
};

//Vector containing Customer details
vector<customer> c;

//Identifier variable as index for customers
int indx;

void NEFT();
void cust();
void add_money();
void interest();
void acc_open();
void transaction(double,string);
void trans_history();
void atm_card();
void check_bal();
void loan();
void loan_in(int r);
void loan_repay();
void manager();
int recaptcha();
int search(string);
void update_pass();
void customer_login();
int ifsc_check(string);
long long int card_no();
void m_customer(int ind);
void m_amt();
void m_loan();
void m_cust_detail();
void print_fm();


int main()
{
    cout<<"Welcome To Our Bank"<<endl<<endl;
    int x;
    cout<<"Enter the mentioned key to proceed"<<endl;
    cout<<"[1] Manager Login"<<endl;
    cout<<"[2] Customer Login"<<endl;
    cin>>x;

    if(x==1)
    {
        string manager_login="MANAGER";
        string manager_password="PASSWORD";
        string m_login;
        string m_password;
        do{
        cout<<"Enter Manager Login ID : ";
        fflush(stdin);
        getline(cin,m_login);
        cout<<"Enter Password: ";
        fflush(stdin);
        getline(cin,m_password);
        if(m_login==manager_login)
        {
            if(m_password==manager_password){
            manager();            // manager function
            }
            else
            cout<<"INVALID PASSWORD"<<endl;
            cout<<"Press any key to continue or escape to exit to main menu" <<endl<<endl;
            if(int(getch())==27)
            main();
        }
        else
            cout<<"INVALID LOGIN ID"<<endl;
            cout<<"Press any key to continue or escape to exit to main menu" <<endl<<endl;
            if(int(getch())==27)
            main();
        }while(true);
    }
    else
    {
        cout<<endl<<endl<<"Welcome to Customer Page"<<endl<<endl;
        cout<<"Enter the mentioned key to proceed"<<endl;
        cout<<"Enter 1: Create a NEW Account"<<endl;
        cout<<"Enter 2: Customer Login"<<endl;
        cout<<"Press any other key to return to main menu"<<endl;
        char an;
        cin>>an;

        if(an=='1')
        acc_open();

        else if(an=='2')
        customer_login();

        else
        main();
    }
    return 0;
}

void cust()
{
    cout<<" YOUR ACCOUNT DETAILS"<<endl<<endl;
    cout<<"USERNAME :"<<c[indx].username<<endl;
    cout<<"NAME :"<<c[indx].name<<endl;
    cout<<"ACCOUNT NUMBER :"<<c[indx].acc_no<<endl;
    cout<<"BANK BALANCE :"<<c[indx].bbal<<endl;
    cout<<"PHONE NO :"<<c[indx].ph_no<<endl;
    cout<<"ADDRESS :"<<c[indx].address<<endl;
    if(c[indx].loan==0)
    {cout<<"YOU DON'T HAVE LOAN"<<endl<<endl;}
    else{ cout<<"LOAN :"<<c[indx].loan<<endl<<endl;}
        int y;
        cout<<"Enter any mentioned key to proceed further"<<endl;
        cout<<"[1] Add money"<<endl;
        cout<<"[2] Transaction History"<<endl;
        cout<<"[3] Check Balance"<<endl;
        cout<<"[4] Fund Transfer"<<endl;
        cout<<"[5] ATM Card"<<endl;
        cout<<"[6] Loan"<<endl;
        cout<<"[7] Loan Re-payment"<<endl;
        cout<<"[8] Reset Password"<<endl;
        cout<<"[0] Exit"<<endl<<endl;

        cin>>y;

        if(y==0)
        main();

        else if(y==1)
        add_money();

        else if(y==2){interest();
        trans_history();}

        else if(y==3)
        check_bal();

        else if(y==4)
        NEFT();

        else if(y==5)
        atm_card();

        else if(y==6)
        loan();

        else if(y==7)
        loan_repay();

        else if(y==8)
        update_pass();

        else{
            cout<<"Wrong input -- You are being redirected to your profile"<<endl;
            cust();
        }
}

int search(string user_n)
{
    for(int i=0;i<c.size();i++)
    {
        if(user_n==c[i].username)
        {
            indx=i;
            return 1;
            break;
        }
    }
        return 0;
}

void acc_open()
{ 
    customer obj;

    cout<<"WELCOME TO IIIT BHOPAL BANK"<<endl<<endl;
    cout<<"Please enter valid details to open your account"<<endl<<endl;

    fflush(stdin);
    cout<<"ENTER YOUR NAME :";
    getline(cin,obj.name);
    cout<<"ENTER USER NAME :";
    getline(cin,obj.username);
    cout<<"CREATE PASSWORD FOR LOGIN :";
    getline(cin,obj.login_pass);
    cout<<"ENTER YOUR PHONE NUMBER :";
    cin>>obj.ph_no;
    fflush(stdin);
    cout<<"ENTER PAN CARD NUMBER :";
    getline(cin,obj.pan);
    cout<<"ENTER YOUR ADDRESS :";
    getline(cin,obj.address);
    cout<<"ENTER YOUR ADHAR NUMBER :";
    cin>>obj.aadharno;
    cout<<"CREATE PIN :";
    cin>>obj.login_pin;
    obj.loan=0;
    time_t tme = time(0);
    obj.l_time= tme;
    long long int n =1;
    srand(time(0));
    while(n<10000000000){n=n*10+rand()%10;}
    obj.acc_no=n;
    obj.bbal=0;
    cout<<"Your Account Number is : "<<obj.acc_no<<endl;
    c.push_back(obj);
    cout<<endl<<"ACCOUNT OPENED SUCCESSFULLY "<<endl<<endl;
    cout<<"Press any key to continue or escape to exit to main menu" <<endl<<endl;
    if(int(getch())==27)
    main();
    customer_login();
}

void customer_login()
{
    string un;string pw;
    cout<< "Please enter your username: " << endl;
    fflush(stdin);
    getline(cin,un);
    if(search(un))
    {
        cout<< "Please enter your password: " << endl;
        getline(cin,pw);
        if(pw==c[indx].login_pass)
        cust();
        else
        cout<<"INVALID PASSWORD"<<endl<<"TRY AGAIN"<<endl;
    }
    else{
        int z;
        cout<<"INVALID USERNAME"<<endl;
        cout<<"[1] Login Again"<<endl;
        cout<<"[2] Create a new Account"<<endl;
        cout<<"Press Any Key to Exit"<<endl;
        cin>>z;
        if(z==1)
        customer_login();
        else if(z==2)
        acc_open();
        else
        main();
    }
}

void update_pass()
{
    string un;string pw;string password1,password2;
    cout<< "Please enter your username: " << endl;
    fflush(stdin);
    getline(cin,un);
    cout<< "Please enter your current password: " << endl;
    getline(cin,pw);
    if(search(un))
    {
        if(pw==c[indx].login_pass){
            cout << "Please enter the new password:" << endl;
            getline(cin,password1);
            cout << "Please Re-enter your password:" << endl;
            getline(cin,password2);

            if (password1 == password2)
            {
                c[indx].login_pass=password1;
                cout<< "your password is updated!\nYou are being redirected to the login page" << endl;
                customer_login();
            }
            else{
                cout<< "Both Passwords must be same -- Try again"<< endl;
                update_pass();
            }
        }
        else
        {
            cout<<"INVALID PASSWORD";
            char z;
            cout<<"Press 1 to Re-try"<<endl;
            cout<<"Press any key to go back"<<endl;
            cin>>z;

            if(z==1)
            update_pass();

            else
            cust();
        }
    }
    else{
        cout<<"INVALID USERNAME"<<endl;
            char z;
            cout<<"Press 1 to Re-enter"<<endl;
            cout<<"Press 2 to Create an Account"<<endl;
            cout<<"Press any key to go back"<<endl;
            cin>>z;

            if(z==1)
            update_pass();

            else if(z==2)
            acc_open();

            else
            cust();
    }
}

void NEFT(){
    cout<<"Welcome to  NEFT window"<<endl<<endl;
    cout<<"Enter reciepient's name : ";
    string name;
    fflush(stdin);
    getline(cin,name);
    long long int acc_no;
    cout<<"Enter the account no. : ";
    cin>>acc_no;
    string ifsc;
    cout<<"Enter the IFSC code : ";
    fflush(stdin);
    getline(cin,ifsc);
    if (ifsc_check(ifsc)){}
    else{
        cout<<"Please enter a valid IFSC code"<<endl;
         cout<<"Enter the IFSC code : ";
         getline(cin,ifsc);
          if (ifsc_check(ifsc))
        {
        }
        else{
        cout<<" Invalid input "<<endl<<endl<<"Press any key to return to NEFT window"<<endl<<endl;
        getchar();
        NEFT();
        }
    }
    double amount;
    cout<<"Enter amount"<<endl;
    cin>>amount;
    if(amount>c[indx].bbal){
        cout<<"your amount is insufficient for the transaction"<<endl<<"Re-enter the amount"<<endl;
        cin>>amount;
        if(amount>c[indx].bbal){
        cout<<"your amount is insufficient for the transaction"<<endl<<"Re-enter the amount"<<endl;
        cin>>amount;
        if(amount>c[indx].bbal){
        cout<<"You have entered incorrect amount thrice"<<endl<<"You are being redirected to Fund transfer window"<<endl<<"Press any key to continue"<<endl<<endl;
        fflush(stdin);
        getchar();
        NEFT();
    }
    }
    }
    int pin;
    cout<<"Enter your pin"<<endl;
    cin>>pin;
    if(pin==c[indx].login_pin){
        if(recaptcha()){
            cout<<"Transfer successful"<<endl<<endl;
            c[indx].bbal=c[indx].bbal-amount;
            transaction(amount,"debit");
            cust();
        }
        else{
            cout<<"Invalid recaptcha"<<endl;
            if(recaptcha()){
            cout<<"Transfer successful"<<endl<<endl;
            c[indx].bbal=c[indx].bbal-amount;
            transaction(amount,"debit");
            cust();
            }
            else{
            cout<<"Invalid recaptcha again"<<endl<<"You are being redirected to the NEFT window"<<endl<<endl;
            NEFT();
            }
        }
    }
}

int ifsc_check(string s){
    for(int i=0;i<s.size();i++){
        if(i<4&&int(s[i])>64&&int(s[i])<91){
        }
        else if(i==4&&s[i]=='0'){
        }
        else if(i>4&&i<11){
        }
        else{
            return 0;
        }
    }
    return 1;
}

int recaptcha(){
    int arr[10]={36,38,23,42,63,126,60,62,94,64};
  char arr1[10]={};
    srand(time(0));
    for(int i=0;i<5;i++){
        arr1[i]=char(arr[rand()%10]);
        cout<<arr1[i]<<ends;
    }
    cout<<endl<<"Enter the captcha"<<endl;
    fflush(stdin);
    string s;
    getline(cin,s);
        if(s==arr1){
            return 1;
        }
    return 0;
}

void check_bal(){
    interest();
    cout<<endl<<"Your balance is "<<c[indx].bbal<<endl<<endl;
    getch();
    cust();
}

void add_money(){
    cout<<"welcome to add money panel"<<endl;
    cout<< "your current balance is :"<<c[indx].bbal<<endl;
    cout<<"enter amount you want to credit"<<endl;
    double add;
    cin>>add;
    c[indx].bbal+=add;
    cout<<"now your bank balance is :"<<c[indx].bbal<<endl;
    transaction(add,"credit");
    interest();
    cout<<"press any key"<<endl<<endl;
    fflush(stdin);
    getch();
    cust();
}

long long int cardno(){
    srand(time(0));
    long long int card=0;
    for(int i=0;i<16;i++)
    {
        card=card*10+rand()%10;
    }
    return card;
}

void atm_card()
{
    cout<<endl<<"Press :"<<endl;
    cout<<"[1] Issue an new card"<<endl;
    cout<<"[2] Card Details"<<endl;
    cout<<"[3] Generate a new pin"<<endl;
    int crd=0;
    cin>>crd;
    string un;
    if(crd==1)
    {
        int count=0;
        do
        {
            string un;string pw;
            cout<< "Please enter your username: ";
            fflush(stdin);
            getline(cin,un);
            cout<< "Please enter your current password: ";
            getline(cin,pw);
            if(search(un))
            {
                srand(time(0));
                if(pw==c[indx].login_pass){
                    c[indx].card_no=to_string(cardno());
                    c[indx].card_no.insert(4," ");
                    c[indx].card_no.insert(9," ");
                    c[indx].card_no.insert(14," ");
                    int vth=((rand()%12)+1)*100+((rand()%10)+25);
                    c[indx].valid_thru=to_string(vth);

                    if(vth<1000)
                    {
                        c[indx].valid_thru.insert(0,"0");
                    }
                    
                    c[indx].valid_thru.insert(2,"/");
                    c[indx].cvv=(rand()%900+99);

                    cout<<endl<<"Don't share these details with anyone"<<endl<<endl;
                    cout<<"Your Card No. is : "<<c[indx].card_no<<endl;
                    cout<<"Your Card is valid till : "<<c[indx].valid_thru<<endl;
                    cout<<"Your Card CVV : "<<c[indx].cvv<<endl;

                    cout<<"Generate your pin: "<<endl;
                    cin>>c[indx].card_pin;
                    cout<<"Your ATM generation is successful"<<endl<<endl;
                    getch();
                    cout<<"Redirecting you back to home page"<<endl<<endl;
                    cust();

                }
                else
                {
                    cout<<"INVALID PASSWORD";
                    char z;
                    cout<<"Press 1 to Re-enter"<<endl;
                    cout<<"Press any key to go back to home page"<<endl;
                    z=getch();
                    if(z==1)
                    count++;

                    else
                    cust();
                }
            }
        } while (count<3);
        cout<<"You entered wrong password 3 times \n You have been redirected to Home page"<<endl;
        cust();
    }

    else if(crd==2)
    {
        cout<<"Card Number : "<<c[indx].card_no<<endl;
        cout<<"Valid Thru : "<<c[indx].valid_thru<<endl;

        cout<<"For CVV Enter Your atm pin : ";
        int x;
        cin>>x;

        if(x==c[indx].card_pin)
        cout<<"CVV : "<<c[indx].cvv<<endl;
        else{
        cout<<"Wrong Pin Please Enter it again";
        atm_card();}
    }

    else
    {
        cout<<"Enter Your ATM pin : ";
        int x;
        cin>>x;

        if(x==c[indx].card_pin)
        {
            int newp,newp2;
            cout<<"Enter New pin: ";
            cin>>newp;
            cout<<"Re-Enter New pin: ";
            cin>>newp2;
            if(newp==newp2)
            c[indx].card_pin=newp;

        }
        else{
        cout<<"Wrong Pin ";
        atm_card();}
    }
    getch();
    cust();
}

void manager()
{
    cout<<"Welcome Manager "<<endl;
    cout<<"Press [1] : View customer Details"<<endl;
    cout<<"Press [2] : View Loan details"<<endl;
    cout<<"Press [3] : Total Amount in Bank"<<endl;
    cout<<"Press [4] : Print customer details"<<endl;
    cout<<"Press [0] : To Go Back"<<endl;
    int m;
    cin>>m;

    if(m==1)
    m_cust_detail();

    else if(m==2)
    m_loan();

    else if(m==3)
    m_amt();

    else if(m==4)
    print_fm();

    else
    main();
}

void m_cust_detail()
{
    int ind=0;
    cout<<"No."<<"  "<<"Customer Name"<<"  "<<"Account No."<<endl;
    for(int i=0;i<c.size();i++)
    {
        cout<<i+1<<"  "<<c[i].name<<"  "<<c[i].acc_no<<endl;
    }
    cout<<endl<<"For More Details for  a Particular person Enter Number: ";
    cin>>ind;
    m_customer(ind);
}

void m_loan()
{
    int l=0;
    for(int i=0;i<c.size();i++)
    {
        if(c[i].loan!=0){
            cout<<l+1<<"  "<<c[i].name<<"  "<<c[i].acc_no<<" "<<c[i].loan<<endl;
            l++;
        }
    }
}

void m_amt()
{
    int total_amt=0;
    for(int i=0;i<c.size();i++)
    {
        total_amt += c[i].bbal;
    }
    cout<<"Total Amount in Bank is : "<<total_amt;
}

void m_customer(int ind)
{
    int m;
    cout<<"Details of "<<ind<<" th Customer "<<endl;
    cout<<"USERNAME :"<<c[ind-1].username<<endl;
    cout<<"NAME :"<<c[ind-1].name<<endl;
    cout<<"ACCOUNT NUMBER :"<<c[ind-1].acc_no<<endl;
    cout<<"BANK BALANCE :"<<c[ind-1].bbal<<endl;
    cout<<"PHONE NO :"<<c[ind-1].ph_no<<endl;
    cout<<"ADDRESS :"<<c[ind-1].address<<endl;
    cout<<"LOAN :"<<c[ind-1].loan<<endl<<endl;
    cout<<"Press [1] to delete this Account"<<endl;
    cout<<"Press any key to back"<<endl;
    cin>>m;
    if(m==1)
    c.erase(c.begin()+ind-1);
    else
    manager();
}

void print_fm()
{
    ofstream fout;
    fout.open("Customer_Data.txt");
    fout<<"S No. \t Customer Name \t User Name \t Account Number \t Phone Number \t Pan Card "<<endl;
    for(int i=0;i<c.size();i++)
    {
        // fout<<"S No. \t Customer Name \t User Name \t Account Number \t Phone Number \t Pan Card "<<endl;
        fout<<i+1<<"\t"<<c[i].name<<"\t"<<c[i].username<<"\t"<<c[i].acc_no<<"\t"<<c[i].ph_no<<"\t"<<c[i].pan<<endl;
    }
    fout.close();
    getch();
    manager();
}

void loan()
{
    cout<<"Press mentioned key for a particular Loan"<<endl;
    cout<<"[1] Home Loan"<<endl;
    cout<<"[2] Education Loan"<<endl;
    cout<<"[3] Collateral Loan"<<endl;
    cout<<"Press any key to go back Collateral Loan"<<endl;
    int a;cin>>a;
    if(a==1)
    {
        cout<<"Interest for Home Loan is: 12%"<<endl;
        loan_in(12);
    }
    else if(a==2)
    {
        cout<<"Interest for Education Loan is: 9%"<<endl;
        loan_in(9);
    }
    else if(a==3)
    {
        cout<<"Interest for Collateral Loan is: 14%"<<endl;int r=14;
        string mor;                         // Name of the thing that is mortaged
        int mor_value;                      // Original Price of the thing that is mortaged
        cout<<"What you want to Mortage: ";fflush(stdin);getline(cin,mor);
        cout<<"What is the original amount of "<<mor<<" : ";cin>>mor_value;
            int loan_amt;
            cout<<"Enter The Loan Amount: ";
            cin>>loan_amt;
            if(loan_amt<=(0.75*mor_value))
            {
                int loan_time;
                cout<<"Enter the time in year for Which you Want loan: ";
                cin>>loan_time;
                // if(100000000>=loan_amt)
                c[indx].bbal += loan_amt;

                // Calculate interest for loan 
                int t=(loan_amt*r*loan_time)/100;
                cout<<"The Total Amount that you have to repay to bank is: "<<loan_amt+t;
                c[indx].loan=loan_amt+t;
            }
            else
            cout<<"Your Expectations Are High"<<endl;
    }
    else
    cust();
    cout<<endl;
    getch();
    cust();  
}

void loan_in(int r)
{
    int loan_amt;
    cout<<"Enter The Loan Amount: ";
    cin>>loan_amt;
    int loan_time;c[indx].loan=0;
    cout<<"Enter the time in year for Which you Want loan: ";
    cin>>loan_time;
    if(c[indx].max_bal>=loan_amt && c[indx].loan==0)
    {
        c[indx].loan += loan_amt;
        c[indx].bbal+=c[indx].loan;
        // interest for loan 
        int t=(loan_amt*r*loan_time)/100;
        c[indx].loan += t;
        cout<<"The Total Amount that you have to repay to bank is: "<<loan_amt+t<<endl;
    }
    else if(c[indx].loan!=0)
    cout<<"You Already have a Loan First Repay it."<<endl;
    else
    cout<<"Your Expectations Are High."<<endl;
    
    getch();
    cust();
}

void loan_repay()
{
    cout<<"Loan Amount Left To Re-Pay: "<<c[indx].loan<<endl;
    cout<<"Enter Amount To Re-Pay: ";
    double amt;cin>>amt;
    if(amt<=c[indx].bbal)
    {
        c[indx].bbal-=amt;
        c[indx].loan-=amt;
    }
    cout<<endl<<"Now Loan Amount Left To Re-Pay: "<<c[indx].loan<<endl;
    getch();
    cust();
}

void interest(){
    time_t tme = time(0);
    int diff = tme - c[indx].l_time;
    if(c[indx].bbal>0){
        c[indx].bbal+=diff;
        transaction(diff,"credit");}
    c[indx].l_time = tme;
}

void transaction(double amt,string tranj_type){
    trans detail;int i=0;
    detail.amount= amt;
    detail.tran_type=tranj_type;
    time_t tme = time(0);
    char* dt = ctime(&tme);
    detail.time=dt;
    if(tranj_type=="credit"){
        detail.prev_bal = c[indx].bbal-amt;
    }
    else{
        detail.prev_bal = c[indx].bbal+amt;
    }
    detail.current_bal = c[indx].bbal;
    c[indx].tranj.push_back(detail);
}

void trans_history(){
    cout<<"Welcome to transaction history window"<<endl<<endl;
    cout<<"Date and Time \t \t \tAmount\t Transaction type   Previous Balance   Current Balance\n"<<endl;
    for (int i=(c[indx].tranj.size()-1); i>=0;i--){
        cout<<c[indx].tranj[i].time<<"\t\t\t\t"<<c[indx].tranj[i].amount<<"\t\t"<<c[indx].tranj[i].tran_type<<"\t\t"<<c[indx].tranj[i].prev_bal<<"\t\t"<<c[indx].tranj[i].current_bal<<endl;
    }
    cout<<"\nPress any key to return to Profile page"<<endl<<endl;
    fflush(stdin);
    getch();
    cust();
}
