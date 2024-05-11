#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string username,email,password;
    string searchpass,searchemail,searchname;
    fstream file;
    public:
    void login();
    void signup();
    void forget();
} obj;
int main(){
    char choice;
        cout<<"\n1-login";
        cout<<"\n2- signup";
        cout<<"\n3-forget password";
        cout<<"\n4-exit";
        cout<<"\nEnter your choice-";

        cin>>choice;
        switch(choice){
            case '1':
            cin.ignore();
            obj.login();
            break;

            case '2':
            cin.ignore();
            obj.signup();
            break;

            case '3':
            cin.ignore();
            obj.forget();
            break;

            case '4':
            return 0;
            break;

            defualt:
            cout<<"invalid selection!";
        }
}

void temp :: signup(){
    cout<<"\nenter username :: ";
    getline(cin,username);
    cout<<"enter email address ::";
    getline(cin,email);
    cout<<"enter password ::";
    getline(cin, password);

    file.open("loginData.txt",ios :: out|ios ::app);
    file<<username<<"*"<<email<<"*"<<password<<endl;
    file.close();
}
void temp::login(){

cout<<"-----------login----------"<<endl;
cout<<"enter  username ::"<<endl;
getline(cin,searchname);
cout<<"enter  password::"<<endl;
getline(cin,searchpass);

file.open("loginData.txt",ios::in);
getline(file,username,'*');
getline(file,email,'*');
getline(file,password,'\n');
while(!file.eof()){
    if(username == searchname){

    if(password == searchpass){
        cout<<"\nAccount login succesfull!";
        cout<<"\nUsername :: "<<username<<endl;
        cout<<"\nemail :: "<<email<<endl;
    }
    else{
        cout<<"password is incorrect!";
    }
}
getline(file,username,'*');
getline(file,email,'*');
getline(file,password,'\n');

}
file.close();
}
void temp :: forget(){
    cout<<"\nenter username :: ";
    getline(cin,searchname);
    cout<<"\nenter your email address::";
    getline(cin,searchemail);

file.open("loginData.txt",ios::in);
getline(file,username,'*');
getline(file,email,'*');
getline(file,password,'\n');
while(!file.eof()){
    if
    (username==searchname){
        if
        (email == searchemail){
            cout<<"\nAccount found!"<<endl;
            cout<<"your password::"<<password<<endl;
        }
        else
        {
            cout<<"not found...!\n";
        }
    }
    else{
        cout<<"\nnot found!\n";
    }
    getline(file,username,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
}
file.close();
}