#include <iostream>
#include <vector>
#include <conio.h>
#include <cmath>
#include<time.h>
#include<cstdlib>

using namespace std;

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
};

vector<customer> c;
int indx;

void NEFT();
void cust();
void add_money();
// void details();
void acc_open();
// void trans_history();
void atm_card();
void check_bal();
// void loan();
// void manager();
int recaptcha();
int search(string);
void update_pass();
void customer_login();
int ifsc_check(string);
long long int card_no();

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
            cout<<"You are a manager"<<endl;
            cout<<"hii"<<endl;
            }
            // manager();            // manager function
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

void cust(){

    cout<<" YOUR ACCOUNT DETAILS"<<endl<<endl;
    cout<<"USERNAME :"<<c[index].username;
    cout<<"NAME :"<<c[index].name<<endl;
    cout<<"ACCOUNT NUMBER :"<<c[index].acc_no<<endl;
    cout<<"BANK BALANCE :"<<c[index].bbal<<endl;
    cout<<"PHONE NO :"<<c[index].ph_no<<endl;
    cout<<"ADDRESS :"<<c[index].address<<endl;
    if(c[index].loan==0)
    {cout<<"YOU DON'T HAVE LOAN"<<endl<<endl;}
    else{ cout<<"LOAN :"<<c[index].loan<<endl<<endl;}
        int y;
        cout<<"Enter any mentioned key to proceed further"<<endl;
        cout<<"[1] Add money"<<endl;
        cout<<"[2] Transaction History"<<endl;
        cout<<"[3] Check Balance"<<endl;
        cout<<"[4] Fund Transfer"<<endl;
        cout<<"[5] ATM Card"<<endl;
        cout<<"[6] Loan"<<endl;
        cout<<"[7] Reset Password"<<endl;
        cout<<"[0] Exit"<<endl<<endl;

        cin>>y;

        if(y==0)
        main();

        else if(y==1)
        add_money();

        // else if(y==2)
        // trans_history();

        else if(y==3)
        check_bal();

        else if(y==4)
        NEFT();

        else if(y==5)
        atm_card();

        // else if(y==6)
        // loan();

        else if(y==7)
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

void acc_open(){ 

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

void customer_login(){

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
            cust();
        }
        else{
            cout<<"Invalid recaptcha"<<endl;
            if(recaptcha()){
            cout<<"Transfer successful"<<endl<<endl;
            c[indx].bbal=c[indx].bbal-amount;
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
    cout<<endl<<"Your balance is "<<c[indx].bbal<<endl<<endl;
    cust();
}

void add_money(){
    cout<<"Welcome to ";
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

/*void atm_card()
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
            cout<< "Please enter your username: \n" << endl;
            fflush(stdin);
            getline(cin,un);
            cout<< "Please enter your current password: \n" << endl;
            getline(cin,pw);
            if(search(un))
            {
                srand(time(0));
                if(pw==c[indx].login_pass){
                    long long int card=cardno();
                    c[indx].card_no=to_string(card);
                    c[indx].card_no.insert(4," ");
                    c[indx].card_no.insert(8," ");
                    c[indx].card_no.insert(12," ");
                    int vth=((rand()%12)+1)*100+((rand()%10)+25);
                    c[indx].valid_thru=to_string(vth);

                    if(vth<1000)
                    {
                        c[indx].valid_thru.insert(0,"0");
                    }
                    
                    c[indx].valid_thru.insert(2,"/");
                    c[indx].cvv=(rand()%900+99);

                    cout<<"Don't share these details with anyone"<<endl;
                    cout<<"Your Card No. is: "<<c[indx].card_no<<endl;
                    cout<<"Your Card No. is: "<<c[indx].valid_thru<<endl;
                    cout<<"Your Card No. is: "<<c[indx].cvv<<endl;

                    cout<<"Generate your pin: "<<endl;
                }
                else
                {
                    cout<<"INVALID PASSWORD";
                    char z;
                    cout<<"Press 1 to Re-enter"<<endl;
                    cout<<"Press any key to go back to home page"<<endl;
                    cin>>z;

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
}*/

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
            cout<< "Please enter your username: \n" << endl;
            fflush(stdin);
            getline(cin,un);
            cout<< "Please enter your current password: \n" << endl;
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

                    cout<<"Don't share these details with anyone"<<endl;
                    cout<<"Your Card No. is : "<<c[indx].card_no<<endl;
                    cout<<"Your Card is valid till : "<<c[indx].valid_thru<<endl;
                    cout<<"Your Card CVV : "<<c[indx].cvv<<endl;

                    cout<<"Generate your pin: "<<endl;
                    cin>>c[indx].card_pin;
                    cout<<"Your ATM generation is successful"<<endl<<"Redirecting you back to home page"<<endl<<endl;
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
    cust();
}
