#include<bits/stdc++.h>
#include<windows.h>
//#include<cstdio>
//#include<dirent.h>
#include<sys/stat.h>
using namespace std;
typedef struct donors
{
    string name;
    string number;
    string blood;
    string lastdonation;
    string Division;
    string district;
    string gender;
} bld;
typedef struct thalassemia
{
    string name;
    string contact_num;
    string district;
    string division;
    int id;
} th;
typedef struct ambulance
{
    int id;
    string org_name;
    string location;
    string phn_num;
    string ambunumber;

} ambu;

typedef struct doctors
{
    int id;
    string doctors_name;
    string degree;
    string chamber;
    string work_days;
    string phone;
    string visiting_hour;
    string specialist;
} doc;

void sign_up();
void sign_in();
void sign_out();
void forget_pass();
void update_pass();
void home();
void main_menu();
void reg_as_a_donor();
void display_donor_list();
void gotoxy(int x,int y);
void search_donor();
void search_using_blood_group();
void search_using_area();
void fix_an_appointment_for_donation();
void cancel_reg_from_donor_list();
void update_reg_info();
void blood_donation_request();
void blood_req_accepted_notification();
void blood_donation_rejected_notification();
void add_thalassemia_patient_info();
void display_thalassemia_patients_list(int a_or_u);
void admin_home();
string Current_date ();
string make_formal(string a);
void ambulance_list_add();
void display_ambulance_list(int a_or_u);
void Add_doctors_info();
void display_doctors_list(int a_or_u);
void search_for_specialist();
void delete_thalassemia_patient_info();
void update_thalassamia_info();
void delete_doctors_info();
void update_doctors_info();
void delete_ambulance_information();
void update_ambulance_info();
int main()
{

    struct stat buffer;
    int x=(stat("Blood", &buffer)==0);
    if(!x)
    {
        mkdir("Blood");
    }
    struct stat bufferr;
    int y=(stat("Thalassamia", &bufferr)==0);
    if(!y)
    {
        mkdir("Thalassamia");
    }
    struct stat bufferrr;
    int z=(stat("Ambulance", &bufferrr)==0);
    if(!z)
    {
        mkdir("Ambulance");
    }
    struct stat bufferrrr;
    int zz=(stat("Doctors", &bufferrrr)==0);
    if(!zz)
    {
        mkdir("Doctors");
    }

    bool flag=false;
    ifstream file;
    file.open("log_info.txt");
    string s;
    while(file>>s)
    {
        flag=true;
    }
    file.close();

    if(flag)
    {
        ifstream file;
        file.open("Admin_pass.txt");
        string u,p;
        file>>u>>p;
        file.close();
        if(s==u)
        {
            admin_home();
        }
        else
        {
            home();
        }


    }
    else
    {
        main_menu();
    }
}
void sign_up()
{
    system("cls");
    ofstream file;
    file.open("usernames.txt",ios::out|ios::app);
    file.close();
    gotoxy(10,0);
    cout<<"*************************************************************************************************************"<<endl;
    gotoxy(10,1);
    cout<<"*********************************************************SIGN-UP*********************************************"<<endl;
    gotoxy(10,2);
    cout<<"*************************************************************************************************************"<<endl<<endl;
    gotoxy(40,8);
    cout<<"Enter Username : ";
    string user_name;
    cin.ignore();
    getline(cin,user_name);
    bool p=false;
    for(int i=0; i<user_name.size(); i++)
    {
        if(user_name[i]==' ')
        {
            p=true;
        }
    }
    if(p)
    {
        gotoxy(40,10);
        cout<<"Invalid username!!Enter username without any space!!"<<endl;
        gotoxy(40,11);
        cout<<"1.Try again."<<endl;
        gotoxy(40,12);
        cout<<"2.main-menu."<<endl;
        gotoxy(40,13);
        cout<<"Enter your choice: ";
        char y;
        cin>>y;
        switch(y)
        {
        case '1':
            sign_up();
            break;
        case '2':
            main_menu();
            break;
        default:
            gotoxy(40,15);
            cout<<"wrong choice!!"<<endl;
            gotoxy(40,16);
            cout<<"Press Enter to continue: ";
            cin.get();
            cin.get();
            main_menu();
        }
    }
    else
    {
        ifstream file2;
        file2.open("usernames.txt");
        string src;
        bool flag=false;
        while(file2>>src)
        {
            if(src==user_name)
            {
                flag=true;
            }
        }
        file2.close();
        if(flag|| user_name=="Thalassamia" || user_name=="Blood" || user_name=="Ambulance" || user_name=="Doctors")
        {
            gotoxy(40,10);
            cout<<"This user name is not available,Please try an unique username."<<endl;
            gotoxy(40,12);
            cout<<"1.Want to try again?\n";
            gotoxy(40,13);
            cout<<"2.go to the main menu."<<endl;
            char choice;
            gotoxy(40,14);
            cout<<"Press any number(1-2): ";
            cin>>choice;
            switch(choice)
            {
            case '1':
                sign_up();
                break;
            case '2':
                main_menu();
            default:
            {
                gotoxy(40,15);
                cout<<"Wrong choice!!Press Enter to continue: ";
                cin.get();
                cin.get();
                main_menu();

            }
            }
        }
        else
        {
            gotoxy(40,10);
            cout<<"Enter Password: ";
            string password;
            cin>>password;
            if(password.size()<5)
            {
                gotoxy(40,12);
                cout<<"Password should be at least 5 characters."<<endl;
                gotoxy(40,14);
                cout<<"1.Want to try again?"<<endl;
                gotoxy(40,15);
                cout<<"2.go to the main menu"<<endl;
                gotoxy(40,17);
                cout<<"Press any number(1-2): ";
                char choice;
                cin>>choice;
                switch(choice)
                {
                case '1':
                    sign_up();
                    break;
                case '2':
                    main_menu();
                    break;
                default:
                {
                    gotoxy(40,18);
                    cout<<"Wrong choice!!Press Enter to continue: ";
                    cin.get();
                    cin.get();
                    main_menu();
                }
                }

            }
            else
            {
                ofstream file4;
                file4.open("usernames_and_pass.txt",ios::out|ios::app);
                file4<<user_name<<endl;
                file4<<password<<endl;
                file4.close();
                ofstream file5;
                file5.open("usernames.txt",ios::out|ios::app);
                file5<<user_name<<endl;
                file5.close();
                gotoxy(35,13);
                cout<<"Hello Dear "<<user_name<<"!We are glad that you are here :-) "<<endl;
                gotoxy(35,15);
                cout<<"Press Enter to continue: ";
                cin.get();
                cin.get();
                main_menu();
            }
        }
    }
}
void sign_in()
{
    system("cls");
    gotoxy(10,0);
    cout<<"**************************************************************************************************************"<<endl;
    gotoxy(10,1);
    cout<<"***************************************************************SIGN-IN****************************************"<<endl;
    gotoxy(10,2);
    cout<<"**************************************************************************************************************"<<endl<<endl;
    gotoxy(40,8);
    cout<<"Enter username : ";
    string user_name;
    cin>>user_name;
    ifstream file;
    string  password;
    gotoxy(40,9);
    cout<<"Enter password: ";
    cin>>password;
    ifstream ad;
    ad.open("Admin_pass.txt");
    string nm,ps;
    ad>>nm;
    ad>>ps;
    ad.close();
    if(user_name==nm && password==ps)
    {
        ofstream file2;
        file2.open("log_info.txt",ios::out|ios::app);
        file2<<user_name<<endl;
        file2.close();

        admin_home();
    }
    file.open("usernames_and_pass.txt");
    string nam,pass;
    bool flag=false;
    while(file>>nam)
    {
        file>>pass;
        if(nam==user_name && pass==password)
        {
            flag=true;
        }
    }
    file.close();
    if(flag)
    {
        gotoxy(40,11);
        cout<<"sign-in succesfully !!"<<endl;
        ofstream file2;
        file2.open("log_info.txt",ios::out|ios::app);
        file2<<user_name<<endl;
        file2.close();
        gotoxy(40,12);

        cout<<"Press Enter to go the home page: ";
        cin.get();
        cin.get();
        home();

    }
    else
    {
        gotoxy(40,11);
        cout<<"password or username maybe incorrect!"<<endl;
        gotoxy(40,13);
        cout<<"1.Try again."<<endl;
        gotoxy(40,14);
        cout<<"2.go to the main-menu."<<endl;
        gotoxy(40,15);
        cout<<"Press any number(1-2) :";
        char choice;
        cin>>choice;
        switch(choice)
        {
        case '1':
            sign_in();
            break;
        case '2':
            main_menu();
            break;
        default:
        {
            gotoxy(40,17);
            cout<<"Wrong choice!!Press Enter to continue: "<<endl;;
            cin.get();
            cin.get();
            main_menu();
        }

        }
    }

}
void sign_out()
{
    system("cls");
    gotoxy(40,8);
    cout<<"Are you sure you want to sign-out?"<<endl;
    gotoxy(40,9);
    cout<<"1.YES."<<endl;
    gotoxy(40,10);
    cout<<"2.NO."<<endl;
    gotoxy(40,11);
    cout<<"Press any number(1-2): ";
    char choice;
    cin>>choice;
    switch(choice)
    {
    case '1':
    {
        remove("log_info.txt");
        ofstream file2;
        file2.open("log_info.txt");
        file2.close();
        gotoxy(40,13);
        cout<<"Sign-out succesfully!"<<endl;
        gotoxy(40,14);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        main_menu();
    }
    break;
    case '2':
        home();
        break;
    default:
    {
        cout<<"wrong choice.try again!"<<endl;
        sign_out();
    }

    }
}
void home()
{
    system("cls");
    system("Color 0E");
    blood_donation_request();
    system("cls");
    blood_req_accepted_notification();
    system("cls");
    blood_donation_rejected_notification();
    system("cls");
    ifstream file;
    file.open("log_info.txt");
    string s;
    file>>s;
    file.close();
    gotoxy(44,0);
    cout<<"You are sign-in as "<<s<<".";
    gotoxy(40,8);
    cout<<"1.Registration as a Blood donor.";
    gotoxy(40,9);
    cout<<"2.Display Blood donor list.";
    gotoxy(40,10);
    cout<<"3.Search Blood donors.";
    gotoxy(40,11);
    cout<<"4.Fix an appointment for Blood donation."<<endl;
    gotoxy(30,12);
    cout<<"------------------------------------------------------------------";
    gotoxy(40,13);
    cout<<"5.Display thalassamia patient list.";
    gotoxy(40,14);
    cout<<"6.Display Ambulance list.";
    gotoxy(40,15);
    cout<<"7.Display Doctors list.";
    gotoxy(40,16);
    cout<<"8.Search Specialist.";
    gotoxy(30,17);
    cout<<"------------------------------------------------------------------";
    gotoxy(40,18);
    cout<<"9.update-password."<<endl;
    gotoxy(40,19);
    cout<<"10.sign-out"<<endl;

    gotoxy(40,20);
    cout<<"11.Exit.";
    gotoxy(30,22);
    cout<<"-----------------------------------------------------------------";

    for(int i=7; i<=22; i++)
    {
        gotoxy(30,i);
        cout<<"|";
        gotoxy(95,i);
        cout<<"|";
    }
    for(int i=30; i<=95; i++)
    {
        gotoxy(i,7);
        cout<<"-";
    }
    gotoxy(40,24);
    cout<<"Press any number(1-11): ";
    int y;
    cin>>y;

    switch(y)
    {
    case 1:
        reg_as_a_donor();
        break;
    case 2:
        display_donor_list();

        break;
    case 3:
        search_donor();
        break;
    case 4:
        fix_an_appointment_for_donation();
        break;
    case 5:
    {
        int a_or_u=0;
        display_thalassemia_patients_list(a_or_u);
        break;
    }
    case 6:
    {

        int a_or_u=0;
        display_ambulance_list(a_or_u);
        break;
    }
    case 7:
    {
        int a_or_u=0;
        display_doctors_list(a_or_u);
        break;
    }
    case 8:
        search_for_specialist();
        break;
    case 9:
    {

        update_pass();
        break;

    }
    case 10:
    {
        sign_out();
        break;
    }
    case 11:
        exit(0);
        break;
    default:
    {
        gotoxy(40,26);
        cout<<"wrong choice!Try again!";
        gotoxy(40,27);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();
    }
    }
}
void forget_pass()
{
    system("cls");

    gotoxy(40,8);
    cout<<"Enter your remembered username: ";
    string s;
    cin>>s;
    ifstream file;
    file.open("usernames_and_pass.txt");
    string ss,pp;
    bool flag=false;
    string r,p;
    while(file>>ss>>pp)
    {

        if(ss==s)
        {
            flag=true;
            r=ss;
            p=pp;
        }
    }
    file.close();
    if(flag)
    {
        gotoxy(40,11);
        cout<<"Password recovered successfully."<<endl;
        gotoxy(40,13);
        cout<<"Your user name is "<<r<<endl;
        gotoxy(40,14);
        cout<<"Your password is "<<p<<endl;
        gotoxy(40,16);
        cout<<"Press Enter to continue.";
        cin.get();
        cin.get();
        main_menu();
    }
    else
    {
        gotoxy(40,11);
        cout<<"Account not found,try again!"<<endl;
        gotoxy(40,13);
        cout<<"Press Enter to continue.";
        cin.get();
        cin.get();
        main_menu();
    }
}

void main_menu()
{
    system("Color 70");
    system("cls");
    gotoxy(50,0);
    cout<<"------MAIN-MENU-------";
    gotoxy(40,8);
    cout<<"1.Sign-Up."<<endl;
    gotoxy(40,9);
    cout<<"2.Sign-In."<<endl;
    gotoxy(40,10);
    cout<<"3.Forget password."<<endl;
    gotoxy(40,11);
    cout<<"4.Exit.";
    gotoxy(40,13);
    cout<<"Press any number(1-4): ";
    char y;
    cin>>y;
    switch(y)
    {
    case '1':
        sign_up();
        break;
    case '2':
        sign_in();
        break;
    case '3':
        forget_pass();
        break;
    case '4':
        exit(0);
        break;
    default:
    {
        gotoxy(35,15);
        cout<<"Wrong choice!!Press Enter to continue: ";
        cin.get();
        cin.get();
        main_menu();
    }

    }
}
void update_pass()
{
    system("cls");
    gotoxy(40,8);
    cout<<"Enter old password: ";
    string old;
    cin>>old;
    ifstream file;
    file.open("log_info.txt");
    string s;
    file>>s;
    file.close();
    ifstream file2;

    file2.open("usernames_and_pass.txt");
    string k,l;
    ofstream file3;
    bool flag=false;
    file3.open("new.txt");
    while(file2>>k>>l)
    {
        if(k==s && l==old)
        {
            flag=true;
        }
        else
        {
            file3<<k;
            file3<<endl;
            file3<<l;
            file3<<endl;
        }
    }
    if(!flag)
    {
        file2.close();
        file3.close();
        remove("new.txt");
        gotoxy(40,9);
        cout<<"This is a wrong password!!Try again!"<<endl;
        gotoxy(40,10);
        cout<<"1.home."<<endl;
        gotoxy(40,11);
        cout<<"2.Try again."<<endl;
        gotoxy(40,12);
        cout<<"Press any number(1-2): ";
        char y;
        cin>>y;
        switch(y)
        {
        case '1':
            home();
            break;
        case '2':
            update_pass();
            break;
        default:
        {
            gotoxy(40,14);
            cout<<"Wrong choice!Press Enter to continue: ";
            cin.get();
            cin.get();
            home();

        }

        }
    }
    else
    {
        gotoxy(40,9);
        cout<<"Enter New password: ";
        string n;
        cin>>n;
        if(n.size()<5)
        {
            gotoxy(40,12);
            cout<<"Password should be at least 5 characters."<<endl;
            gotoxy(40,14);
            cout<<"1.Want to try again?"<<endl;
            gotoxy(40,15);
            cout<<"2.go to home"<<endl;
            gotoxy(40,17);
            cout<<"Press any number(1-2): ";
            char choice;
            cin>>choice;
            switch(choice)
            {
            case '1':
                sign_up();
                break;
            case '2':
                main_menu();
                break;
            default:
            {
                gotoxy(40,18);
                cout<<"Wrong choice!!Press Enter to continue: ";
                cin.get();
                cin.get();
                main_menu();
            }
            }

        }
        else
        {
            file3<<s;
            file3<<endl;
            file3<<n;
            file3<<endl;
            file2.close();
            file3.close();
            remove("usernames_and_pass.txt");
            rename("new.txt","usernames_and_pass.txt");
            gotoxy(40,10);
            cout<<"Password updated succesfully."<<endl;
            gotoxy(40,11);
            cout<<"Press Enter to continue: ";
            cin.get();
            cin.get();
            home();
        }
    }
}
void reg_as_a_donor()
{
    system("cls");
    ofstream r;
    string q="./Blood/donors.txt";
    const char *path =(q).c_str();
    r.open(path,ios::out|ios::app);
    r.close();
    ifstream file8;
    string q1 ="./Blood/donors.txt";
    const char *path1 =q1.c_str();
    file8.open(q1);
    ifstream file6;
    file6.open("log_info.txt");
    string s;
    file6>>s;
    file6.close();
    bld ss;
    bool flag=false;
    while(file8>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
    {
        if(ss.name==s)
        {
            flag=true;
        }
    }
    file8.close();
    if(flag)
    {
        gotoxy(40,8);
        cout<<"You are already registered!!";
        gotoxy(40,9);
        cout<<"1.Cancel Registration.";
        gotoxy(40,10);
        cout<<"2.Update your information.";

        gotoxy(40,11);
        cout<<"3.home.";
        gotoxy(40,12);
        cout<<"Press any number(1-3): ";
        char y;
        cin>>y;
        switch(y)
        {
        case '1':
            cancel_reg_from_donor_list();
            break;
        case '2':
            update_reg_info();
            break;
        case '3':
            home();
            break;
        default:
        {
            gotoxy(40,13);
            cout<<"Wrong choice!!Press Enter to continue: ";
            cin.get();
            cin.get();
            home();
        }
        }
    }
    else
    {

        gotoxy(40,8);
        cout<<"Enter your age: ";
        string age;
        cin>>age;
        bool u=0;
        for(int i=0; i<age.size(); i++)
        {
            if(!isdigit(age[i]))
            {
                u=1;
            }
        }
        if(u)
        {
            gotoxy(40,9);
            cout<<"Invalid input!!Try again!";
            gotoxy(40,10);
            cout<<"Press Enter to continue: ";
            cin.get();
            cin.get();
            home();

        }
        else
        {
            int aa=stoi(age);
            if(aa<18)
            {
                gotoxy(40,9);
                cout<<"Sorry!!You must be at least 18 years old to donate blood!";
                gotoxy(40,10);
                cout<<"Press Enter to continue: ";
                cin.get();
                cin.get();
                home();
            }
            else if(aa>65)
            {
                gotoxy(40,9);
                cout<<"Sorry!!You cannot donate blood after 65!";
                gotoxy(40,10);
                cout<<"Press Enter to continue: ";
                cin.get();
                cin.get();
                home();
            }
            else
            {
                int weight;
                gotoxy(40,9);
                cout<<"Enter your weight: ";
                cin>>weight;
                if(weight<45)
                {
                    gotoxy(40,10);
                    cout<<"Sorry!!To donate blood your weight must be atleast 45!"<<endl;
                    gotoxy(40,11);
                    cout<<"Press Enter to continue: ";
                    cin.get();
                    cin.get();
                    home();
                }
                else
                {
                    bld ss;
                    gotoxy(40,10);
                    cout<<"Enter your blood group: ";
                    cin>>ss.blood;
                    for(int i=0; i<ss.blood.size(); i++)
                    {
                        ss.blood[i]=tolower(ss.blood[i]);
                    }
                    if(ss.blood != "ab+" && ss.blood != "ab-" && ss.blood != "a+" && ss.blood != "a-" && ss.blood != "b+" && ss.blood != "b-" && ss.blood != "o+" && ss.blood != "o-")
                    {
                        gotoxy(40,12);
                        cout<<"Invalid Input!";
                        gotoxy(40,13);
                        cout<<"Press Enter to continue: ";
                        cin.get();
                        cin.get();
                        home();
                    }
                    gotoxy(40,11);
                    cout<<"Enter your Mobile number: ";
                    cin>>ss.number;
                    if(ss.number.size() !=11 || ss.number[0] != '0' || ss.number[1] != '1' )
                    {
                        gotoxy(40,13);
                        cout<<"Please enter a valid number!";
                        gotoxy(40,14);
                        cout<<"Press Enter to continue: ";
                        cin.get();
                        cin.get();
                        home();
                    }
                    else
                    {
                        bool f=false;
                        for(int i=0; i<ss.number.size(); i++)
                        {
                            if(!isdigit(ss.number[i]))
                            {
                                f=true;
                            }
                        }
                        if(f)
                        {
                            gotoxy(40,13);
                            cout<<"Please enter a valid number!";
                            gotoxy(40,14);
                            cout<<"Press Enter to continue: ";
                            cin.get();
                            cin.get();
                            home();
                        }
                        else
                        {
                            gotoxy(40,12);
                            cout<<"Enter your Division: ";
                            cin>>ss.Division;
                            gotoxy(40,13);
                            cout<<"Enter your District: ";
                            cin>>ss.district;
                            gotoxy(40,14);
                            cout<<"Enter gender: ";
                            gotoxy(40,15);
                            cout<<"1.Male.";
                            gotoxy(40,16);
                            cout<<"2.Female.";
                            gotoxy(40,17);
                            cout<<"Enter any number(1-2): ";
                            char ch;
                            cin>>ch;
                            switch(ch)
                            {
                            case'1':
                                    ss.gender="Male";
                                break;
                            case '2':
                                ss.gender="Female";
                                break;
                            default:
                            {

                                gotoxy(40,19);
                                cout<<"Wrong choice!Try again!";
                                gotoxy(40,20);
                                cout<<"Press Enter to continue.";
                                cin.get();
                                cin.get();
                                home();
                            }
                            }
                            gotoxy(20,19);
                            cout<<"Enter your last donation date((YYYY-MM-DD)in this formet)(If you never donated blood Before Enter 'NA'): ";
                            cin>>ss.lastdonation;
                            if(ss.lastdonation != "na" && ss.lastdonation != "NA")
                            {
                                string md=Current_date();

                                string y="";
                                string m="";
                                string d="";
                                int i=0;
                                while(ss.lastdonation[i] !='-')
                                {
                                    y+=ss.lastdonation[i];
                                    i++;
                                }
                                i++;
                                while(ss.lastdonation[i] != '-')
                                {
                                    m+=ss.lastdonation[i];
                                    i++;
                                }

                                i++;
                                while(i  != ss.lastdonation.size())
                                {
                                    d+=ss.lastdonation[i];
                                    i++;
                                }
                                // cout<<endl<<y<<" "<<m<<" "<<d<<endl;
                                int ry=stoi(y);
                                int rm=stoi(m);
                                int rd=stoi(d);

                                string y1="";
                                string m1="";
                                string d1="";
                                i=0;
                                while(md[i] !='-')
                                {
                                    y1+=md[i];
                                    i++;
                                }
                                i++;
                                while(md[i] != '-')
                                {
                                    m1+=md[i];
                                    i++;
                                }

                                i++;
                                while(i  != md.size())
                                {
                                    d1+=md[i];
                                    i++;
                                }


                                int miny=stoi(y1);
                                int minm=stoi(m1);
                                int mind=stoi(d1);

                                if(ry>miny || (miny==ry && rm>minm) || (miny==ry && rm==minm && rd>mind))
                                {
                                    gotoxy(40,21);
                                    cout<<"You've Enterd an invalid date.";
                                    gotoxy(40,22);
                                    cout<<"1.Try Again.";
                                    gotoxy(40,23);
                                    cout<<"2.Home.";
                                    gotoxy(40,24);
                                    cout<<"Press any number(1-2): ";
                                    char yy;
                                    switch(yy)
                                    {
                                    case '1':
                                        reg_as_a_donor();
                                    case '2':
                                        home();
                                    default:
                                    {
                                        gotoxy(40,25);
                                        cout<<"Wrong choice!!";
                                        gotoxy(40,26);
                                        cout<<"Press Enter to continue: ";
                                        cin.get();
                                        cin.get();
                                        home();
                                    }

                                    }
                                    home();
                                }

                            }
                            ofstream file;
                            string q3 = "./Blood/donors.txt";
                            const char *path2  =q3.c_str();
                            file.open(q3,ios::out|ios::app);
                            ifstream file2;
                            file2.open("log_info.txt");
                            string s;
                            file2>>s;
                            file2.close();
                            ss.name=s;
                            file<<ss.name;
                            file<<endl;
                            file<<ss.blood;
                            file<<endl;
                            file<<ss.number;
                            file<<endl;
                            file<<ss.Division;
                            file<<endl;
                            file<<ss.district;
                            file<<endl;
                            file<<ss.lastdonation;
                            file<<endl;
                            file<<ss.gender;
                            file<<endl;
                            file.close();
                            gotoxy(40,20);
                            ofstream file3;
                            string q10="./Blood/"+s;
                            mkdir(q10.c_str());
                            file3.close();

                            gotoxy(32,21);
                            cout<<"You've successfully registered as a blood donor!!"<<endl;
                            gotoxy(40,23);
                            cout<<"Press Enter to continue: ";
                            cin.get();
                            cin.get();
                            home();

                        }
                    }
                }
            }
        }
    }
}
void display_donor_list()
{
    system("cls");
    ifstream file;
    string h1="./Blood/donors.txt";
    const char *path = h1.c_str();
    file.open(path);


    int i=3;
    bld ss;
    bool flag=false;
    while(file>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
    {


        if(i==3)
        {
            flag=true;
            gotoxy(10,1);
            cout<<"Name";
            gotoxy(30,1);
            cout<<"Blood group";
            gotoxy(50,1);
            cout<<"Contact info.";
            gotoxy(70,1);
            cout <<"location"<<endl;
            gotoxy(6,0);

        }

        gotoxy(8,i);
        cout<<ss.name;
        gotoxy(34,i);
        ss.blood=make_formal(ss.blood);
        if(ss.blood=="Ab+" || ss.blood=="Ab-")
        {
            ss.blood[1]='B';
        }
        cout<<ss.blood;
        gotoxy(50,i);
        cout<<ss.number;
        gotoxy(70,i);
        ss.district=make_formal(ss.district);
        ss.Division=make_formal(ss.Division);
        cout<<ss.district<<","<<ss.Division<<endl;
        i++;
    }
    if(!flag)
    {
        gotoxy(40,i+1);
        cout<<"donors list is empty!";
    }
    cout<<endl;
    file.close();
    gotoxy(40,i+2);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    home();
}
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void search_donor()
{
    system("cls");
    gotoxy(40,8);
    cout<<"1.Search by blood group."<<endl;
    gotoxy(40,9);
    cout<<"2.Search by location."<<endl;
    gotoxy(40,10);
    cout<<"3.home.";
    gotoxy(40,11);
    cout<<"Press any number(1-3): ";
    char y;
    cin>>y;
    switch(y)
    {
    case '1':
        search_using_blood_group();
        break;

    case '2':
        search_using_area();
        break;
    case '3':
        home();
        break;
    default:
    {
        gotoxy(40,11);
        cout<<"Wrong choice!Try again!!";
        gotoxy(40,12);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();
    }
    }
}
void search_using_blood_group()
{
    system("cls");
    gotoxy(40,8);
    cout<<"Enter Blood group: ";
    string k;
    cin>>k;
    for(int i=0; i<k.size(); i++)
    {
        k[i]=tolower(k[i]);
    }
    ofstream rr;
    ofstream rrr;
    string h1="./Blood/n1.txt";
    string h2="./Blood/n2.txt";
    const char *path=h1.c_str();
    const char *path2=h2.c_str();
    rr.open(path);
    rrr.open(path2);
    system("cls");
    ifstream file;
    string h3="./Blood/donors.txt";
    const char *path3=h3.c_str();
    file.open(path3);
    bld ss;
    bool flag1=false;
    bool flag2=false;
    while(file>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
    {
        string  u=ss.blood;
        for(int i=0; i<u.size(); i++)
        {
            u[i]=tolower(u[i]);
        }
        if(u.find(k) != string :: npos)
        {
            if(u==k)
            {
                flag1=true;
                rr<<ss.name;
                rr<<endl;
                rr<<ss.blood;
                rr<<endl;
                rr<<ss.number;
                rr<<endl;
                rr<<ss.district;
                rr<<endl;
                rr<<ss.Division;
                rr<<endl;
                rr<<ss.lastdonation;
                rr<<endl;
                rr<<ss.gender;
                rr<<endl;

            }
            else
            {
                flag2=true;
                rrr<<ss.name;
                rrr<<endl;
                rrr<<ss.blood;
                rrr<<endl;
                rrr<<ss.number;
                rrr<<endl;
                rrr<<ss.district;
                rrr<<endl;
                rrr<<ss.Division;
                rrr<<endl;
                rrr<<ss.lastdonation;
                rrr<<endl;
                rrr<<ss.gender;
                rrr<<endl;
            }

        }
    }

    file.close();
    rr.close();
    rrr.close();
    ifstream ff1;
    ifstream ff2;
    ff1.open(path);
    ff2.open(path2);
    int i=3;
    if(!flag1)
    {
        gotoxy(40,1);
        cout<<"No matching result found!"<<endl;
    }
    else
    {
        bld kk;
        gotoxy(10,1);
        cout<<"Name";
        gotoxy(30,1);
        cout<<"Blood group";
        gotoxy(50,1);
        cout<<"Contact info.";
        gotoxy(70,1);
        cout <<"location"<<endl;

        while(ff1>>kk.name>>kk.blood>>kk.number>>kk.Division>>kk.district>>kk.lastdonation>>kk.gender)
        {
            gotoxy(10,i);

            cout<<kk.name<<" ";
            gotoxy(30,i);
            kk.blood=make_formal(kk.blood);
            if(kk.blood=="Ab+" || kk.blood=="Ab-")
            {
                kk.blood[1]='B';
            }
            cout<<kk.blood<<" ";

            gotoxy(50,i);
            cout<<kk.number<<" ";
            gotoxy(70,i);
            kk.district=make_formal(kk.district);
            kk.Division=make_formal(kk.Division);
            cout<<kk.district<<","<<kk.Division<<endl;
            i++;
        }
        cout<<endl;
    }
    if(flag2)
    {
        gotoxy(10,i+1);
        cout<<"Related matching results: ";
        gotoxy(10,i+3);
        cout<<"Name";
        gotoxy(30,i+3);
        cout<<"Blood group";
        gotoxy(50,i+3);
        cout<<"Contact info.";
        gotoxy(70,i+3);
        cout <<"location"<<endl;
        bld kk;
        i+=4;
        while(ff2>>kk.name>>kk.blood>>kk.number>>kk.Division>>kk.district>>kk.lastdonation>>kk.gender)
        {
            gotoxy(10,i);

            cout<<kk.name;
            gotoxy(30,i);
            kk.blood=make_formal(kk.blood);
            if(kk.blood=="Ab+" || kk.blood=="Ab-")
            {
                kk.blood[1]='B';
            }

            cout<<kk.blood;
            gotoxy(50,i);
            cout<<kk.number;
            gotoxy(70,i);
            kk.district=make_formal(kk.district);
            kk.Division=make_formal(kk.Division);
            cout<<kk.district<<","<<kk.Division;
            i++;
        }

    }
    ff1.close();
    ff2.close();
    remove(path);
    remove(path2);
    file.close();
    gotoxy(40,i+3);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    home();
}
void search_using_area()
{
    system("cls");
    gotoxy(25,8);
    cout<<"Enter any area(district/division)where you want to find donor: ";
    string src;
    cin>>src;
    system("cls");
    for(int i=0; i<src.size(); i++)
    {
        src[i]=tolower(src[i]);
    }
    ifstream file;
    string h="./Blood/donors.txt";
    const char *path=h.c_str();
    file.open(h);
    bld ss;
    int o=0,p=0;
    bool flag1=false;
    bool flag2=false;
    ofstream f1;
    ofstream f2;
    string h1="./Blood/n1.txt";
    string h2="./Blood/n2.txt";
    const char *path4 = h1.c_str();
    const char *path5 = h2.c_str();
    f1.open(path4);
    f2.open(path5);
    while(file>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
    {
        string u=ss.Division;
        string w=ss.district;
        for(int i=0; i<u.size(); i++)
        {
            u[i]=tolower(u[i]);
        }
        for(int i=0; i<w.size(); i++)
        {
            w[i]=tolower(w[i]);
        }
        if(w.find(src) != string::npos || u.find(src) != string::npos)
        {


            if(w==src || u==src)
            {
                flag1=true;
                f1<<ss.name;
                f1<<endl;
                f1<<ss.blood;
                f1<<endl;
                f1<<ss.number;
                f1<<endl;
                f1<<ss.district;
                f1<<endl;
                f1<<ss.Division;
                f1<<endl;
                f1<<ss.lastdonation;
                f1<<endl;
                f1<<ss.gender;
                f1<<endl;
            }
            else
            {
                flag2=true;
                f2<<ss.name;
                f2<<endl;
                f2<<ss.blood;
                f2<<endl;
                f2<<ss.number;
                f2<<endl;
                f2<<ss.district;
                f2<<endl;
                f2<<ss.Division;
                f2<<endl;
                f2<<ss.lastdonation;
                f2<<endl;
                f2<<ss.gender;
                f2<<endl;
            }
        }
    }
    f1.close();
    f2.close();
    ifstream ff1;
    ifstream ff2;
    string hh1="./Blood/n1.txt";
    string hh2="./Blood/n2.txt";
    const char *pathh=hh1.c_str();
    const char *pathh2=hh2.c_str();
    ff1.open(pathh);
    ff2.open(pathh2);
    int i=3;
    if(!flag1)
    {
        gotoxy(40,1);
        cout<<"No matching result found!"<<endl;
    }
    else
    {
        bld kk;
        gotoxy(10,1);
        cout<<"Name";
        gotoxy(30,1);
        cout<<"Blood group";
        gotoxy(50,1);
        cout<<"Contact info.";
        gotoxy(70,1);
        cout <<"location"<<endl;

        while(ff1>>kk.name>>kk.blood>>kk.number>>kk.Division>>kk.district>>kk.lastdonation>>kk.gender)
        {
            gotoxy(10,i);
            cout<<kk.name<<" ";
            gotoxy(30,i);
            kk.blood=make_formal(kk.blood);
            if(kk.blood=="Ab+" || kk.blood=="Ab-")
            {
                kk.blood[1]='B';
            }
            cout<<kk.blood<<" ";
            gotoxy(50,i);
            cout<<kk.number<<" ";
            gotoxy(70,i);
            kk.district=make_formal(kk.district);
            kk.Division=make_formal(kk.Division);
            cout<<kk.district<<","<<kk.Division<<endl;
            i++;
        }
        cout<<endl;
    }
    if(flag2)
    {
        gotoxy(10,i+1);
        cout<<"Related matching results: ";
        gotoxy(10,i+3);
        cout<<"Name";
        gotoxy(30,i+3);
        cout<<"Blood group";
        gotoxy(50,i+3);
        cout<<"Contact info.";
        gotoxy(70,i+3);
        cout <<"location"<<endl;
        bld kk;
        i+=4;
        while(ff2>>kk.name>>kk.blood>>kk.number>>kk.Division>>kk.district>>kk.lastdonation>>kk.gender)
        {
            gotoxy(10,i);
            cout<<kk.name;
            gotoxy(30,i);
            kk.blood=make_formal(kk.blood);
            if(kk.blood=="Ab+" || kk.blood== "Ab-")
            {
                kk.blood[1]='B';
            }
            cout<<kk.blood;
            gotoxy(50,i);
            cout<<kk.number;
            gotoxy(70,i);
            kk.district=make_formal(kk.district);
            kk.Division=make_formal(kk.Division);
            cout<<kk.district<<","<<kk.Division;
            i++;
        }

    }
    ff1.close();
    ff2.close();
    remove(pathh);
    remove(pathh2);
    file.close();
    gotoxy(40,i+3);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    home();
}
void fix_an_appointment_for_donation()
{
    system("cls");
    gotoxy(40,2);
    cout<<"Enter donor user name: ";
    string s;
    cin>>s;
    ifstream ff1;
    ff1.open("log_info.txt");
    string meee;
    ff1>>meee;
    ff1.close();
    if(meee==s)
    {
        gotoxy(40,3);
        cout<<"Sorry!!Here you can't fix an appointment with yourself :) ";
        gotoxy(40,4);
        cout<<("Press Enter to continue: ");
        cin.get();
        cin.get();
        home();
    }

    ifstream file;
    string h1="./Blood/donors.txt";
    const char *path=h1.c_str();
    file.open(path,ios::out|ios::app);
    bld y;
    bool f=0;
    string ll;
    string lll;
    while(file>>y.name>>y.blood>>y.number>>y.Division>>y.district>>y.lastdonation>>y.gender)
    {
        if(y.name==s)
        {
            f=1;
            ll=y.lastdonation;
            lll=y.gender;
        }
    }
    file.close();
    ifstream fffile;
    string h11="./Blood/"+s+"/notification.txt";
    const char *path11=h11.c_str();
    fffile.open(path11);
    string kk,kkk;
    bool ache_already=0;
    while(fffile>>kk>>kkk)
    {

        if(kk==meee)
        {
            ache_already=1;
        }
    }
    fffile.close();
    if(ache_already)
    {
        gotoxy(40,4);
        cout<<"You've already sent a request to them,please wait for there response.";
        gotoxy(40,5);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();
    }

    if(f)
    {
        gotoxy(40,3);
        cout<<"Enter date for donation(YYYY-MM-DD): ";
        string a;
        cin>>a;

        string y="";
        string m="";
        string d="";
        int i=0;
        while(a[i] !='-')
        {
            y+=a[i];
            i++;
        }
        i++;
        while(a[i] != '-')
        {
            m+=a[i];
            i++;
        }

        i++;
        while(i  != a.size())
        {
            d+=a[i];
            i++;
        }
        // cout<<endl<<y<<" "<<m<<" "<<d<<endl;
        int ry=stoi(y);
        int rm=stoi(m);
        int rd=stoi(d);
        string md;
        md=Current_date();
        string y1="";
        string m1="";
        string d1="";
        i=0;
        while(md[i] !='-')
        {
            y1+=md[i];
            i++;
        }
        i++;
        while(md[i] != '-')
        {
            m1+=md[i];
            i++;
        }

        i++;
        while(i  != md.size())
        {
            d1+=md[i];
            i++;
        }


        int miny=stoi(y1);
        int minm=stoi(m1);
        int mind=stoi(d1);
        if(ry<miny || (miny==ry && rm<minm) || (miny==ry && rm==minm && rd<mind))
        {
            gotoxy(40,5);
            cout<<"You've Enterd an invalid date.";
            gotoxy(40,6);
            cout<<"Press Enter to continue.";
            cin.get();
            cin.get();
            home();
        }



        if(ll =="NA" || ll=="na" || ll=="Na" || ll=="nA")
        {
            string u="./Blood/"+s+"/notification.txt";
            const char *path=u.c_str();
            ofstream file2(path,ios::out|ios::app);
            string data(meee.c_str());
            file2 << data;

            file2<<endl;
            file2<<a;
            file2<<endl;
            file2.close();
            if(lll=="Female")
            {
                gotoxy(10,5);
                cout<<"We've sent notification to this user,if she accept your request you can contact her for further quiries."<<endl;
            }
            else
            {
                gotoxy(10,5);
                cout<<"We've sent notification to this user,if he accept your request you can contact him for further quiries."<<endl;
            }
            cin.get();
            cin.get();
            home();
        }
        else
        {




            string yj,mj,dj;
            int j=0;
            while(ll[j] !='-')
            {
                yj+=ll[j];
                j++;
            }
            j++;
            while(ll[j] != '-')
            {
                mj+=ll[j];
                j++;
            }

            j++;
            while(j  != ll.size())
            {
                dj+=ll[j];
                j++;
            }
            int ky=stoi(yj);
            int km=stoi(mj);
            int kd=stoi(dj);
            if(ky==ry && km==rm)
            {
                int day=abs(km-rm);
                gotoxy(0,5);
                cout<<"Sorry this donor cannot donate blood.he has last donated blood only "<<day<< " ago.(The minimum interval between 2 donation should be at least 3 months(For Male))";
                gotoxy(40,6);
                cout<<"Press Enter to continue.";
                cin.get();
                cin.get();
                home();
            }
            if(ky-ry>=2)
            {
                string u="./Blood/"+s+"/notification.txt";
                const char *path=u.c_str();
                ofstream file2(path,ios::out|ios::app);
                string data(meee.c_str());
                file2 << data;
                file2<<endl;
                file2<< a;
                file2<<endl;
                file2.close();
                gotoxy(10,5);
                if(lll=="Female")
                {
                    cout<<"We've sent notification to this user,if she accept your request you can contact her for further quiries."<<endl;
                }
                else
                {
                    cout<<"We've sent notification to this user,if he accept your request you can contact him for further quiries."<<endl;
                }
                gotoxy(40,6);
                cout<<"Press Enter to continue: ";
                cin.get();
                cin.get();
                home();
            }
            else
            {
                if(ky==ry)
                {
                    int day=0;
                    int x;
                    for(int i=km; i<=rm; i++)
                    {
                        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
                        {
                            x=31;
                        }
                        else if(i==4 || i==6 || i==9 || i==11)
                        {
                            x=30;
                        }
                        else
                        {
                            x=28;
                        }
                        if(i==km)
                        {
                            day+=(x-km);
                        }
                        else if(i==rm)
                        {
                            day+=(rm);
                        }
                        else
                        {
                            day+=(x);
                        }
                    }
                    if(lll=="Male")
                    {
                        if(day>=89)
                        {
                            string u="./Blood/"+s+"/notification.txt";
                            const char *path=u.c_str();
                            ofstream file2(path,ios::out|ios::app);
                            string data(meee.c_str());
                            file2 << data;
                            file2<<endl;
                            file2<<a;
                            file2<<endl;
                            file2.close();
                            gotoxy(10,5);
                            cout<<"We've sent notification to this user,if he accept your request you can contact him for further quiries."<<endl;
                            gotoxy(40,6);
                             cout<<"Press Enter to continue: ";
                            cin.get();
                            cin.get();
                            home();
                        }
                        else
                        {
                            gotoxy(0,5);
                            cout<<"Sorry this donor cannot donate blood.he has last donated blood only "<<day<< "ago.(The minimum interval between 2 donation should be at least 3 months(For Male))";
                            gotoxy(40,6);
                            cout<<"Press Enter to continue.";
                            cin.get();
                            cin.get();
                            home();

                        }
                    }
                    else
                    {
                        if(day>=120)
                        {
                            string u="./Blood/"+s+"/notification.txt";
                            const char *path=u.c_str();
                            ofstream file2(path,ios::out|ios::app);
                            string data(meee.c_str());
                            file2 << data;
                            file2<<endl;
                            file2<<a;
                            file2<<endl;
                            file2.close();
                            gotoxy(10,5);
                            cout<<"We've sent notification to this user,if she accept your request you can contact her for further quiries."<<endl;
                            gotoxy(40,6);
                            cout<<"Press Enter to continue: ";
                            cin.get();
                            cin.get();
                            home();
                        }
                        else

                            gotoxy(0,5);
                        cout<<"Sorry this donor cannot donate blood.she has last donated blood only "<<day<< "ago.(The minimum interval between 2donation should be at least 4 months(For Female))";
                        gotoxy(40,6);
                        cout<<"Press Enter to continue.";
                        cin.get();
                        cin.get();
                        home();

                    }


                }

                else
                {
                    int day=0;
                    int x;
                    for(int i=km; i<=12; i++)
                    {
                        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
                        {
                            x=31;
                        }
                        else if(i==4 || i==6 || i==9 || i==11)
                        {
                            x=30;
                        }
                        else
                        {
                            x=28;
                        }
                        if(i==km)
                        {
                            day+=(x-km);
                        }
                        else
                        {
                            day+=(x);
                        }
                    }
                    for(int i=1; i<=rm; i++)
                    {
                        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
                        {
                            x=31;
                        }
                        else if(i==4 || i==6 || i==9 || i==11)
                        {
                            x=30;
                        }
                        else
                        {
                            x=28;
                        }
                        if(i==rm)
                        {
                            day+=(rm);
                        }
                        else
                        {
                            day+=(x);
                        }
                        if(lll=="Male")
                        {

                            if(day>=89)
                            {
                                string u="./Blood/"+s+"/notification.txt";
                                const char *path=u.c_str();
                                ofstream file2(path,ios::out|ios::app);
                                string data(meee.c_str());
                                file2 << data;
                                file2<<endl;
                                file2<<a;
                                file2<<endl;
                                file2.close();
                                gotoxy(10,5);
                                cout<<"We've sent notification to this user,if he accept your request you can contact him for further quiries."<<endl;
                                gotoxy(40,6);
                                cout<<"Press Enter to continue : ";
                                cin.get();
                                cin.get();
                                home();
                            }
                            else
                            {
                                gotoxy(0,5);
                                cout<<"Sorry this donor cannot donate blood.he has last donated blood only "<<day<< "ago.(The minimum interval between 2donation should be at least 3 months)9";
                                gotoxy(40,6);
                                cout<<"Press Enter to continue.";
                                cin.get();
                                cin.get();
                                home();

                            }

                        }
                        else
                        {

                            if(day>=120)
                            {
                                string u="./Blood/"+s+"/notification.txt";
                                const char *path=u.c_str();
                                ofstream file2(path,ios::out|ios::app);
                                string data(meee.c_str());
                                file2 << data;
                                file2<<endl;
                                file2<<a;
                                file2<<endl;
                                file2.close();
                                gotoxy(10,5);
                                cout<<"We've sent notification to this user,if she accept your request you can contact her for further quiries."<<endl;
                                gotoxy(40,6);
                                cout<<"Press Enter to continue: ";
                                cin.get();
                                cin.get();
                                home();
                            }
                            else
                            {
                                gotoxy(10,5);
                                cout<<"Sorry this donor cannot donate blood.she has last donated blood only "<<day<< "ago.(The minimum interval between 2donation should be at least 4 months(For female))";
                                gotoxy(40,6);
                                cout<<"Press Enter to continue.";
                                cin.get();
                                cin.get();
                                home();

                            }

                        }
                    }

                }

            }





        }
    }
    else
    {
        gotoxy(40,4);
        cout<<"This donor is not found."<<endl;;
        gotoxy(40,5);
        cout<<"Press Enter to continue."<<endl;
        cin.get();
        cin.get();
        home();
    }
}

void cancel_reg_from_donor_list()
{
    system("cls");
    ifstream file;
    file.open("log_info.txt");
    string q;
    file>>q;
    file.close();

    ifstream file2;
    string h1="./Blood/donors.txt";
    const char *path1=h1.c_str();
    file2.open(path1);
    bld ss;
    ofstream file3;
    string h2="./Blood/new.txt";
    const char *path2=h2.c_str();
    file3.open(path2);
    while(file2>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
    {
        if(q != ss.name)
        {
            file3<<ss.name;
            file3<<endl;
            file3<<ss.blood;
            file3<<endl;
            file3<<ss.number;
            file3<<endl;
            file3<<ss.Division;
            file3<<endl;
            file3<<ss.district;
            file3<<endl;
            file3<<ss.lastdonation;
            file3<<endl;
            file3<<ss.gender;
            file3<<endl;
        }
    }
    file2.close();
    file3.close();
    remove(path1);
    rename(path2,"./Blood/donors.txt");
    gotoxy(40,1);
    cout<<"Registration canceled successfully !!"<<endl;
    gotoxy(40,3);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    home();
}
void update_reg_info()
{
    system("cls");
    gotoxy(40,10);
    cout<<"1.update blood group.";
    gotoxy(40,11);
    cout<<"2.update mobile number.";
    gotoxy(40,12);
    cout<<"3.update district.";
    gotoxy(40,13);
    cout<<"4.update division.";
    gotoxy(40,14);
    cout<<"5.Update last donation date.";
    gotoxy(40,15);
    cout<<"Press any number(1-5): ";
    char y;
    cin>>y;
    switch(y)
    {
    case '1':
    {
        system("cls");
        ifstream file;
        file.open("log_info.txt");
        string q;
        file>>q;
        file.close();
        ifstream file2;
        string h1="./Blood/donors.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        bld ss;
        ofstream file3;
        string h2="./Blood/new.txt";
        const char *path2=h2.c_str();
        file3.open(path2);
        while(file2>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
        {
            if(q != ss.name)
            {
                file3<<ss.name;
                file3<<endl;
                file3<<ss.blood;
                file3<<endl;
                file3<<ss.number;
                file3<<endl;
                file3<<ss.Division;
                file3<<endl;
                file3<<ss.district;
                file3<<endl;
                file3<<ss.lastdonation;
                file3<<endl;
                file3<<ss.gender;
                file3<<endl;
            }
            else
            {
                gotoxy(40,10);
                cout<<"Enter new blood group: ";
                string b;
                cin>>b;
                file3<<ss.name;
                file3<<endl;
                file3<<b;
                file3<<endl;
                file3<<ss.number;
                file3<<endl;
                file3<<ss.Division;
                file3<<endl;
                file3<<ss.district;
                file3<<endl;
                file3<<ss.lastdonation;
                file3<<endl;
                file3<<ss.gender;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        remove(path1);
        rename(path2,"./Blood/donors.txt");
        gotoxy(40,11);
        cout<<"blood group successfully updated.";
        gotoxy(40,12);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();
        break;
    }
    case '2':
    {

        system("cls");
        ifstream file;
        file.open("log_info.txt");
        string q;
        file>>q;
        file.close();
        ifstream file2;
        string h1="./Blood/donors.txt";
        const char *path1 = h1.c_str();
        file2.open(path1);
        bld ss;
        ofstream file3;
        string h2="./Blood/new.txt";
        const char *path2=h2.c_str();
        file3.open(path2);
        while(file2>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
        {
            if(q != ss.name)
            {
                file3<<ss.name;
                file3<<endl;
                file3<<ss.blood;
                file3<<endl;
                file3<<ss.number;
                file3<<endl;
                file3<<ss.Division;
                file3<<endl;
                file3<<ss.district;
                file3<<endl;
                file3<<ss.lastdonation;
                file3<<endl;
                file3<<ss.gender;
                file3<<endl;
            }
            else
            {
                gotoxy(40,10);
                cout<<"Enter new contact number: ";
                string b;
                cin>>b;
                if(b.size() !=11 || b[0] != '0' || b[1] != '1' )
                {
                    gotoxy(40,13);
                    cout<<"Please Enter a valid number!";
                    gotoxy(40,14);
                    cout<<"Press Enter to continue: ";
                    cin.get();
                    cin.get();
                    home();
                }
                else
                {
                    bool f=false;
                    for(int i=0; i<b.size(); i++)
                    {
                        if(!isdigit(b[i]))
                        {
                            f=true;
                        }
                    }
                    if(f)
                    {
                        gotoxy(40,13);
                        cout<<"Please enter a valid number!";
                        gotoxy(40,14);
                        cout<<"Press Enter to continue: ";
                        cin.get();
                        cin.get();
                        home();
                    }
                    else
                    {
                        file3<<ss.name;
                        file3<<endl;
                        file3<<ss.blood;
                        file3<<endl;
                        file3<<b;
                        file3<<endl;
                        file3<<ss.Division;
                        file3<<endl;
                        file3<<ss.district;
                        file3<<endl;
                        file3<<ss.lastdonation;
                        file3<<endl;
                        file3<<ss.gender;
                        file3<<endl;
                    }


                }
            }
        }
        file2.close();
        file3.close();
        string ee= "./Blood/donors.txt";
        const char *pathh1=ee.c_str();
        string eee="./Blood/new.txt";
        const char *pathh2=eee.c_str();

        remove(pathh1);
        rename(pathh2,"./Blood/donors.txt");
        gotoxy(40,11);
        cout<<"Contact number successfully updated.";
        gotoxy(40,12);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();
        break;
    }
    case '3':
    {
        system("cls");
        ifstream file;
        file.open("log_info.txt");
        string q;
        file>>q;
        file.close();
        ifstream file2;
        string h1="./Blood/donors.txt";
        const char *path1 = h1.c_str();
        file2.open(path1);
        bld ss;
        ofstream file3;
        string h2="./Blood/new.txt";
        const char *path2=h2.c_str();
        file3.open(path2);
        while(file2>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
        {
            if(q != ss.name)
            {
                file3<<ss.name;
                file3<<endl;
                file3<<ss.blood;
                file3<<endl;
                file3<<ss.number;
                file3<<endl;
                file3<<ss.Division;
                file3<<endl;
                file3<<ss.district;
                file3<<endl;
                file3<<ss.lastdonation;
                file3<<endl;
                file3<<ss.gender;
                file3<<endl;
            }
            else
            {
                gotoxy(40,10);
                cout<<"Enter new district: ";
                string b;
                cin>>b;
                file3<<ss.name;
                file3<<endl;
                file3<<ss.blood;
                file3<<endl;
                file3<<ss.number;
                file3<<endl;
                file3<<ss.Division;
                file3<<endl;
                file3<<b;
                file3<<endl;
                file3<<ss.lastdonation;
                file3<<endl;
                file3<<ss.gender;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        string h3="./Blood/donors.txt";
        const char *path3 = h3.c_str();

        string h4="./Blood/new.txt";
        const char *path4=h4.c_str();
        remove(path3);
        rename(path4,"./Blood/donors.txt");
        gotoxy(40,11);
        cout<<"District successfully updated.";
        gotoxy(40,12);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();
        break;
    }
    case '4':
    {
        system("cls");
        ifstream file;
        file.open("log_info.txt");
        string q;
        file>>q;
        file.close();
        ifstream file2;
        string h1="./Blood/donors.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        bld ss;
        ofstream file3;
        string h2="./Blood/new.txt";
        const char *path2=h2.c_str();
        file3.open(path2);
        while(file2>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
        {
            if(q != ss.name)
            {
                file3<<ss.name;
                file3<<endl;
                file3<<ss.blood;
                file3<<endl;
                file3<<ss.number;
                file3<<endl;
                file3<<ss.Division;
                file3<<endl;
                file3<<ss.district;
                file3<<endl;
                file3<<ss.lastdonation;
                file3<<endl;
                file3<<ss.gender;
                file3<<endl;
            }
            else
            {
                gotoxy(40,10);
                cout<<"Enter new Division: ";
                string b;
                cin>>b;
                file3<<ss.name;
                file3<<endl;
                file3<<ss.blood;
                file3<<endl;
                file3<<ss.number;
                file3<<endl;
                file3<<b;
                file3<<endl;
                file3<<ss.district;
                file3<<endl;
                file3<<ss.lastdonation;
                file3<<endl;
                file3<<ss.gender;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        string h3="./Blood/donors.txt";
        const char *path3=h3.c_str();
        string h4="./Blood/new.txt";
        const char *path4=h4.c_str();

        remove(path3);
        rename(path4,"./Blood/donors.txt");
        gotoxy(40,11);
        cout<<"Division successfully updated.";
        gotoxy(40,12);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();
        break;
    }
    case '5':
    {
        system("cls");
        ifstream file;
        file.open("log_info.txt");
        string q;
        file>>q;
        file.close();
        ifstream file2;
        string h1="./Blood/donors.txt";

        const char *path1=h1.c_str();
        file2.open(path1);
        bld ss;
        ofstream file3;
        string h2="./Blood/new.txt";
        const char *path2= h2.c_str();
        file3.open(path2);
        while(file2>>ss.name>>ss.blood>>ss.number>>ss.Division>>ss.district>>ss.lastdonation>>ss.gender)
        {
            if(q != ss.name)
            {
                file3<<ss.name;
                file3<<endl;
                file3<<ss.blood;
                file3<<endl;
                file3<<ss.number;
                file3<<endl;
                file3<<ss.Division;
                file3<<endl;
                file3<<ss.district;
                file3<<endl;
                file3<<ss.lastdonation;
                file3<<endl;
                file3<<ss.gender;
                file3<<endl;
            }
            else
            {
                gotoxy(40,10);
                cout<<"Enter last donation date: ";
                string b;
                cin>>b;
                file3<<ss.name;
                file3<<endl;
                file3<<ss.blood;
                file3<<endl;
                file3<<ss.number;
                file3<<endl;
                file3<<ss.Division;
                file3<<endl;
                file3<<ss.district;
                file3<<endl;
                file3<<b;
                file3<<endl;
                file3<<ss.gender;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        string h3="./Blood/donors.txt";
        const char *path3= h3.c_str();
        string h4="./Blood/new.txt";
        const char *path4= h4.c_str();
        remove(path3);
        rename(path4,"./Blood/donors.txt");
        gotoxy(40,11);
        cout<<"Last donation date successfully updated.";
        gotoxy(40,12);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();
        break;
    }
    default:
    {
        gotoxy(40,17);
        cout<<"Wrong choice!!Press Enter to continue: ";
        cin.get();
        cin.get();
        home();
    }
    }

}

void add_thalassemia_patient_info()
{
    system("cls");
    ifstream idd;
    string iddd="./Thalassamia/id.txt";
    const char *pp=iddd.c_str();
    idd.open(pp);
    int tha;
    idd>>tha;
    idd.close();

    gotoxy(40,5);
    cout<<"How many patients information you want to store?" ;
    int no;
    cin>>no;

    th k;
    ofstream file;
    string h1="./Thalassamia/patient_list.txt";
    const char *path1=h1.c_str();
    file.open(path1,ios::out|ios::app);
    int j = 7;
    cin.ignore();
    //cout<<no<<endl;
    for(int i=0; i<no; i++)
    {
        ++j;
        gotoxy(40,++j);
        cout<<"Enter patient name: ";
        getline(cin,k.name);
        gotoxy(40,++j);
        cout<<"Enter patient mobile number: ";
        cin>>k.contact_num;
        gotoxy(40,++j);
        cout<<"Enter patient district: ";
        cin>>k.district;
        gotoxy(40,++j);
        cout<<"Enter patient division: ";
        cin>>k.division;
        k.id=tha++;
        file<<k.id;
        file<<endl;
        file<<k.name;
        file<<endl;
        file<<k.contact_num;
        file<<endl;
        file<<k.district;
        file<<endl;
        file<<k.division;
        file<<endl;
        cin.ignore();
    }
    file.close();
    ofstream fff;
    string zoom="./Thalassamia/id.txt";
    const char *zoom1=zoom.c_str();
    fff.open(zoom1);
    fff<<(++tha);
    fff<<endl;
    fff.close();

    gotoxy(40,++j);
    cout<<"Data stored succesfully."<<endl;
    gotoxy(40,++j);
    cout<<"Press Enter to continue.";
    cin.get();
    cin.get();
    admin_home();
}

void display_thalassemia_patients_list(int a_or_u)
{

    system("cls");
    ifstream file;
    string h1="./Thalassamia/patient_list.txt";
    const char *path1=h1.c_str();
    file.open(path1);
    bool flag=0;
    th data;
    int i=3;

    while(file>>data.id,file.ignore(),getline(file,data.name),file>>data.contact_num>>data.district>>data.division)
    {
        if(!flag)
        {
            gotoxy(16,1);
            cout<<"ID";
            gotoxy(30,1);
            cout<<"Patient Name";
            gotoxy(60,1);
            cout<<"Contact Info.";
            gotoxy(90,1);
            cout<<"Address";


        }
        flag=1;
        gotoxy(16,i);
        cout<<data.id;
        gotoxy(30,i);
        data.name=make_formal(data.name);
        cout<<data.name;
        gotoxy(60,i);
        cout<<data.contact_num;
        gotoxy(90,i);
        data.district=make_formal(data.district);
        data.division=make_formal(data.division);
        cout<<data.district<<","<<data.division;
        i++;

    }
    if (!flag)
    {
        gotoxy(45,4);
        cout<<"This list is empty.";

    }
    file.close();
    gotoxy(45,i+4);

    cout<<"Press Enter to continue.";
    cin.get();
    cin.get();
    if(a_or_u==0)
    {
        home();
    }
    else
    {
        admin_home();
    }

}
void blood_donation_request()
{
    string s;
    ifstream ll;
    ll.open("log_info.txt");
    ll>>s;
    ll.close();
    ifstream file;
    string h1="./Blood/"+s+"/notification.txt";
    const char *path1=h1.c_str();
    file.open(path1);
    string kk,kkk;
    int no_of_notification=0;
    while(file>>kk>>kkk)
    {
        no_of_notification++;
    }
    file.close();
    if(no_of_notification !=0)
    {
        string h2="./Blood/"+s+"/notification.txt";
        const char *path2=h2.c_str();
        file.open(path2);
        string kk,kkk;
        int i=3;
        while(file>>kk>>kkk)
        {
            system("cls");
            gotoxy(40,1);
            cout<<"You've "<<no_of_notification<<" new blood donation request."<<endl;
            gotoxy(45,i);
            cout<<kk<<endl;
            gotoxy(45,i+1);
            cout<<"1.Accept."<<endl;
            gotoxy(45,i+2);
            cout<<"2.Reject."<<endl;
            gotoxy(45,i+3);
            cout<<"Press any number(1-2): ";
            int ch;
            cin>>ch;
            if(ch==1)
            {
                struct stat buffer;
                int x=(stat(kk.c_str(), &buffer)==0);
                if(!x)
                {
                    mkdir(kk.c_str());
                }
                ofstream f1;
                string h4="./"+kk+"/accepted_req_blood.txt";
                const char *p4=h4.c_str();
                f1.open(p4,ios::out|ios::app);
                f1<<s;
                f1<<endl;
                f1.close();
                ofstream f2;
                string h5="./Blood/"+s+"/history.txt";
                const char *p5=h5.c_str();
                f2.open(p5,ios::out|ios::app);
                f2<<kk;
                f2<<endl;
                f2<<kkk;
                f2<<endl;
                f2.close();
            }
            else
            {
                struct stat buffer;
                int x=(stat(kk.c_str(), &buffer)==0);
                if(!x)
                {
                    mkdir(kk.c_str());
                }
                ofstream f1;
                string h4="./"+kk+"/rejected_req_blood.txt";
                const char *p4=h4.c_str();
                f1.open(p4,ios::out|ios::app);
                f1<<s;
                f1<<endl;
                f1.close();
            }
            i++;

        }
        file.close();
        string h6="./Blood/"+s+"/notification.txt";
        const char *p6=h6.c_str();
        remove(p6);
        gotoxy(40,i+3);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();

    }

}
void blood_req_accepted_notification()
{
    string me;
    ifstream m;
    m.open("log_info.txt");
    m>>me;
    m.close();
    string h2="./"+me+"/accepted_req_blood.txt";
    const char *p2=h2.c_str();
    string s1;
    ifstream file1;
    file1.open(p2);
    int no_of_notification=0;
    while(file1>>s1)
    {
        no_of_notification++;
    }
    file1.close();
    gotoxy(40,1);
    if(no_of_notification !=0)
    {
        ifstream file;

        string h1="./"+me+"/accepted_req_blood.txt";
        const char *p1=h1.c_str();
        file.open(p1);
        string s;
        int i=3;
        ofstream ff2;
        string h6="./"+me+"/acc_history.txt";
        const char *p6=h6.c_str();
        ff2.open(p6,ios::out|ios:: app);
        while(file>>s)
        {
            system("cls");
            gotoxy(40,1);
            cout<<no_of_notification<<" donor accepted your blood donation request.";
            gotoxy(10,i);
            cout<<s<<" Accepted your blood donation request.Now you can personally contact them for further queries.";
            ff2<<s;
            ff2<<endl;
            i++;
        }
        ff2.close();
        file.close();
        string h8="./"+me+"/accepted_req_blood.txt";
        const char *p8=h8.c_str();
        remove(p8);
        gotoxy(40,i+2);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();

    }
}
void blood_donation_rejected_notification()
{
    ifstream file;
    file.open("log_info.txt");
    string k;
    file>>k;
    file.close();
    string h1="./"+k+"/rejected_req_blood.txt";
    const char *path1=h1.c_str();
    file.open(path1);
    int no_of_notification=0;
    string w;

    while(file>>w)
    {
        no_of_notification++;
    }
    file.close();
    if(no_of_notification !=0)
    {
        ifstream file1;

        string h2="./"+k+"/rejected_req_blood.txt";
        const char *p1=h1.c_str();
        file1.open(p1);
        string s;
        int i=3;
        while(file1>>s)
        {
            system("cls");
            gotoxy(40,1);
            cout<<no_of_notification<<" donor rejected your blood donation request.";
            gotoxy(40,i);
            cout<<s<<" Rejected your blood donation request.";
            i++;
        }
        file1.close();
        string h8="./"+k+"/rejected_req_blood.txt";
        const char *p8=h8.c_str();
        remove(p8);
        gotoxy(40,i+2);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        home();

    }

}

void update_admin_pass()
{
    system("cls");
    ofstream n;

    n.open("new.txt");
    n<<"admin00";
    n<<endl;
    gotoxy(40,10);
    cout<<"Enter new password: ";
    string y;
    cin>>y;
    n<<y;
    n.close();
    remove("Admin_pass.txt");
    rename("new.txt","Admin_pass.txt");
    gotoxy(40,11);
    cout<<"Admin password updated successfully.";
    gotoxy(40,12);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    admin_home();

}
void admin_home()
{
    system("cls");
    system("Color DE");
    gotoxy(45,1);
    cout<<"You are sign in as an Admin.";
    gotoxy(40,10);
    cout<<"1.Add Thalassamia Patient Information.";
    gotoxy(40,11);
    cout<<("2.Update/Delete Thalassamia patient information.");
    gotoxy(40,12);
    cout<<"3.Display Thalassamia patient list.";
    gotoxy(40,13);
    cout<<"--------------------------------------------------------";
    gotoxy(40,14);
    cout<<"4.Add Doctors information in Doctors list.";
    gotoxy(40,15);
    cout<<"5.Update/Delete Doctors information.";
    gotoxy(40,16);
    cout<<"6.Display doctors information list.";
    gotoxy(39,17);
    cout<<"-------------------------------------------------------";
    gotoxy(40,18);
    cout<<"7.Add ambulance information in Ambulance information list.";
    gotoxy(40,19);
    cout<<"8.Update/Delete Ambulance information.";
    gotoxy(40,20);
    cout<<"9.Display Ambulance list.";
    gotoxy(40,21);
    cout<<"10.Update Admin password.";
    gotoxy(40,22);
    cout<<"11.Sign-out.";
    gotoxy(40,23);
    cout<<"12.Exit.";
    gotoxy(40,25);
    cout<<"Press any number(1-11): ";

    int y;
    cin>>y;
    switch(y)
    {
    case 1:
        add_thalassemia_patient_info();
        break;
    case 2:
    {
        system("cls");
        gotoxy(40,10);
        cout<<"1.Update";
        gotoxy(40,11);
        cout<<"2.Delete.";
        gotoxy(40,12);
        cout<<"3.home.";
        gotoxy(40,13);
        cout<<("Press any number(1-3): ");
        int yy;
        cin>>yy;
        switch(yy)
        {
        case 1:
        {


            update_thalassamia_info();
            break;
        }
        case 2:
        {
            delete_thalassemia_patient_info();
            break;
        }
        case 3:
            admin_home();
            break;
        default:
        {
            gotoxy(40,13);
            cout<<"Wrong choice!!Press Enter to continue: ";
            cin.get();
            cin.get();
            admin_home();

        }

        }

        break;

    }
    case 3:
    {
        int a_or_u=1;
        display_thalassemia_patients_list(a_or_u);
        break;
    }
    case 4:
        Add_doctors_info();
        break;
    case 5:
    {
        system("cls");
        gotoxy(40,10);
        cout<<"1.Update.";
        gotoxy(40,11);
        cout<<"2.Delete";
        gotoxy(40,12);
        cout<<"3.home.";
        gotoxy(40,14);
        cout<<"Press any number(1-2): ";
        int yy;
        cin>>yy;
        switch(yy)
        {
        case 1:

            update_doctors_info();
            break;
        case 2:
            delete_doctors_info();
            break;
        case 3:
            admin_home();
            break;
        default:
        {
            gotoxy(40,14);
            cout<<"Wrong choice!!Press Enter to continue: ";
            cin.get();
            cin.get();
            admin_home();
        }
        }
        break;
    }

    case 6:
    {
        int a_or_u=1;
        display_doctors_list(a_or_u);
        break;
    }
    case 7:
        ambulance_list_add();
        break;
    case 8:
    {
        system("cls");
        gotoxy(40,10);
        cout<<"1.Update.";
        gotoxy(40,11);
        cout<<"2.Delete.";

        gotoxy(40,12);
        cout<<"3.home.";
        gotoxy(40,13);
        cout<<"Press any number(1-2): ";
        int yy;
        cin>>yy;
        switch(yy)
        {
        case 1:
            update_ambulance_info();
            break;
        case 2:
            delete_ambulance_information();
            break;
        case 3:
            admin_home();
            break;
        default:
        {
            gotoxy(40,15);
            cout<<"Wrong choice!Press Enter to go to the home page.";
            cin.get();
            cin.get();
            admin_home();
        }

        }
    }
    break;
    case 9:
    {
        int a_or_u=1;
        display_ambulance_list(a_or_u);
        break;
    }
    case 10:
        update_admin_pass();
        break;
    case 11:
        sign_out();
        break;
    case 12 :
        exit(0);
        break;
    default:
    {

        gotoxy(40,27);

        cout<<"Wrong choice!!Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
    }
    }
}

string Current_date ()
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    string k=asctime(timeinfo);
    int i=0;

    while(k[i]  != ' ')
    {
        i++;
    }
    i++;
    string m="";
    while(k[i] != ' ')
    {
        m+=k[i];
        i++;
    }
    string b[]= {"0","1","2","3","4","5","6","7","8","9","10","11","12"};
    string c[]= {"g","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
    int q=0;
    for(int j=0; j<13; j++)
    {
        if(c[j]==m)
        {
            m=b[j];
            break;
        }

    }
    string d="";
    i++;
    while(k[i] != ' ')
    {
        d+=k[i];
        i++;
    }


    i++;
    while(k[i] != ' ')
    {
        i++;
    }
    i++;
    string y="";
    int j=1;
    while(j !=5)
    {
        j++;
        y+=k[i];
        i++;
    }

    string date=y+"-"+m+"-"+d;

    return date;
}
string make_formal(string a)
{
    a[0]=toupper(a[0]);
    for(int i=1; i<a.size(); i++)
    {
        a[i]=tolower(a[i]);
    }
    return a;

}

void ambulance_list_add()
{
    system("cls");
    ifstream idd;
    string iddd="./Ambulance/id.txt";
    const char *pp=iddd.c_str();
    idd.open(pp);
    int aam;
    idd>>aam;
    idd.close();
    string h1="./Ambulance/ambulance_list.txt";
    const char *path1 = h1.c_str();
    ofstream file;
    file.open(path1,ios::out|ios::app);
    ambu ss;
    gotoxy(40,5);
    gotoxy(40,10);
    cout<<"How many Ambulance information you want to add: ";
    int y;
    cin>>y;
    cin.ignore();
    int j=13;
    for(int i=0; i<y; i++)
    {
        gotoxy(40,++j);
        cout<<"Enter Organization name: ";
        getline(cin,ss.org_name);
        gotoxy(40,++j);
        cout<<"Enter location: ";
        getline(cin,ss.location);
        gotoxy(40,++j);
        cout<<"Enter contact number: ";
        cin>>ss.phn_num;
        cin.ignore();
        ss.id=++aam;
        file<<ss.id;
        file<<endl;
        file<<ss.org_name;
        file<<endl;
        file<<ss.location;
        file<<endl;
        file<<ss.phn_num;
        file<<endl;
        ++j;
    }
    ofstream fff;
    string zoom="./Ambulance/id.txt";
    const char *zoom1=zoom.c_str();
    fff.open(zoom1);
    fff<<(++aam);
    fff<<endl;
    fff.close();

    file.close();
    gotoxy(40,++j);
    cout<<"Data stored succesfully.";
    gotoxy(40,++j);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    admin_home();

}

void display_ambulance_list(int a_or_u)
{
    system("cls");
    string h1="./Ambulance/ambulance_list.txt";
    const char *path1=h1.c_str();
    ifstream file;
    file.open(path1);

    ambu ss;
    int k=3;
    bool flag=false;
    while(file>>ss.id,file.ignore(),getline(file,ss.org_name),getline(file,ss.location),file>>ss.phn_num)
    {

        if(k==3)
        {
            flag=true;
            gotoxy(16,1);
            cout<<"ID";

            gotoxy(25,1);
            cout<<"Organization Name";
            gotoxy(70,1);
            cout <<"location"<<endl;
            gotoxy(110,1);
            cout<<"Contact info.";
        }
        gotoxy(16,k);
        cout<<ss.id;
        gotoxy(25,k);
        cout<<ss.org_name;
        gotoxy(70,k);
        cout<<ss.location;
        gotoxy(110,k);
        cout<<ss.phn_num;
        k++;

    }
    file.close();
    if(!flag)
    {
        gotoxy(40,++k);
        cout<<"Ambulance list is empty.";
    }
    gotoxy(50,++k);

    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    if(!a_or_u)
    {
        home();
    }
    else
    {
        admin_home();
    }

}
void Add_doctors_info()
{
    ifstream idd;
    string iddd="./Doctors/id.txt";
    const char *pp=iddd.c_str();
    idd.open(pp);
    int doct;
    idd>>doct;
    idd.close();
    system("cls");
    string h1="./Doctors/doctors_list.txt";
    const char *path1=h1.c_str();
    ofstream file;
    file.open(path1,ios::out|ios::app);
    gotoxy(40,5);
    cout<<"How many Doctors information you want to store? ";
    int y;
    cin>>y;
    cin.ignore();
    int j=7;
    doc ss;
    for(int i=0; i<y; i++)
    {
        gotoxy(40,++j);
        cout<<"Enter Doctor name: ";
        getline(cin,ss.doctors_name);
        gotoxy(40,++j);
        cout<<"Enter Doctor degree: ";
        getline(cin,ss.degree);

        if(ss.degree.find("Medicine")!= string :: npos)
        {
            ss.specialist="Medicine";
        }
        else if(ss.degree.find("Cardiologist")!= string :: npos)
        {
            ss.specialist="Cardiologist";
        }
        else if(ss.degree.find("Paediatrics")!= string :: npos)
        {
            ss.specialist="Paediatrics";
        }
        else if(ss.degree.find("Paulmonology")!= string :: npos)
        {
            ss.specialist="Paulmonologist";
        }
        else if(ss.degree.find("Endocrinology")!= string :: npos)
        {
            ss.specialist="Endocrinologist";
        }
        else if(ss.degree.find("Surgery")!= string :: npos)
        {
            //cout<<"1";
            //system("pause");
            ss.specialist="Surgery";
        }
        else if(ss.degree.find("ENT")!= string :: npos)
        {
            ss.specialist="ENT specialist";
        }
        else if(ss.degree.find("Eye")!= string :: npos)
        {
            ss.specialist="Eye specialist";   ///"Medicine","Cardiologist","Paediatrics","Paulmonologist","Endocrinologist","Surgery","ENT specialist","Eye specialist","Orthopadic surgeon","USG specialist","Radiology and imaging specialist","Hepatologist","Gastroenterologist","Gynecologist",""Oncologist","Neurologist","Burn and plastic","Cardio-thoracic surgery","Neuro-sergery";
        }
        else if(ss.degree.find("Orthopaedics")!= string :: npos)
        {
            ss.specialist="Orthopadic surgeon";
        }
        else if(ss.degree.find("USG")!= string :: npos)
        {
            ss.specialist="USG specialist";
        }
        else if(ss.degree.find("Radiology and imaging")!= string :: npos)
        {
            ss.specialist="Radiology and imaging specialist";
        }
        else if(ss.degree.find("Hepatology")!= string :: npos)
        {
            ss.specialist="Hepatologist";
        }
        else if(ss.degree.find("Gastroent")!= string :: npos)
        {
            ss.specialist="Gastroenterologist";
        }
        else if(ss.degree.find("gyne and obs.")!= string :: npos)
        {
            ss.specialist="Gynecologist";
        }
        else if(ss.degree.find("Oncology")!= string :: npos)
        {
            ss.specialist="Oncologist";
        }
        else if(ss.degree.find("Neurology")!= string :: npos)
        {
            ss.specialist="Neurologist";
        }
        else if(ss.degree.find("Burn and plastic")!= string :: npos)
        {
            ss.specialist="Burn and plastic surgery";
        }
        else if(ss.degree.find("Cardiothoracic surgery")!= string :: npos)
        {
            ss.specialist="Cardio-thoracic surgery";
        }
        else if(ss.specialist.find("Neuro-sergery") != string :: npos)
        {
            ss.specialist="Neuro-sergery";
        }
        else
        {
            gotoxy(40,++j);

            cout<<"Wrong Input!!Press Enter to continue: ";
            file.close();
            cin.get();
            cin.get();
            admin_home();
        }
        gotoxy(40,++j);
        cout<<"Enter doctor chamber : ";
        getline(cin,ss.chamber);
        gotoxy(40,++j);
        cout<<"Enter Working days: ";
        getline(cin,ss.work_days);
        gotoxy(40,++j);
        cout<<"Enter Visiting hour: ";
        getline(cin,ss.visiting_hour);

        gotoxy(40,++j);
        cout<<"Enter contact number: ";
        cin>>ss.phone;

        file<<++doct;
        file<<endl;
        file<<ss.doctors_name;
        file<<endl;
        file<<ss.degree;
        file<<endl;
        file<<ss.specialist;
        file<<endl;
        file<<ss.chamber;
        file<<endl;
        file<<ss.work_days;
        file<<endl;
        file<<ss.visiting_hour;
        file<<endl;
        file<<ss.phone;
        file<<endl;

        ++j;
        cin.ignore();
    }
    ofstream fff;
    string zoom="./Doctors/id.txt";
    const char *zoom1=zoom.c_str();
    fff.open(zoom1);
    fff<<(++doct);
    fff<<endl;
    fff.close();
    file.close();
    gotoxy(40,++j);
    cout<<"Data stored succesfully.";
    gotoxy(40,++j);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    admin_home();
}
void display_doctors_list(int a_or_u)
{
    system("cls");
    ifstream file;
    string h1="./Doctors/doctors_list.txt";
    const char *path = h1.c_str();
    file.open(path);
    int i=3;
    doc ss;
    bool flag=false;

    while(file>>ss.id,file.ignore(),getline(file,ss.doctors_name),getline(file,ss.degree),getline(file,ss.specialist),getline(file,ss.chamber),getline(file,ss.work_days),getline(file,ss.visiting_hour),file>>ss.phone)
    {
        if(i==3)
        {
            flag=true;
            gotoxy(2,1);
            cout<<"ID";
            gotoxy(10,1);
            cout<<"Dr.Name";
            gotoxy(40,1);
            cout<<"Degree ";
            gotoxy(70,1);
            cout <<"Chamber";
            gotoxy(105,1);
            cout<<"Working days";
            gotoxy(120,1);
            cout<<"Visiting hour";
            gotoxy(140,1);
            cout<<"Contact number";
        }
        gotoxy(2,++i);
        cout<<ss.id;
        ss.doctors_name=make_formal(ss.doctors_name);
        gotoxy(10,i);
        cout<<ss.doctors_name;
        bool mark=0;
        for(int j=0; j<ss.degree.size(); j++)
        {
            if(mark)
            {
                break;
            }
            if(ss.degree[j]=='(')
            {
                mark=1;
            }
            ss.degree[j]=toupper(ss.degree[j]);
        }
        gotoxy(40,i);
        cout<<ss.degree;
        ss.chamber=make_formal(ss.chamber);
        gotoxy(70,i);
        cout<<ss.chamber;
        gotoxy(105,i);
        cout<<ss.work_days;
        gotoxy(120,i);
        cout<<ss.visiting_hour;
        gotoxy(140,i);
        cout<<ss.phone;
        //++i;


    }
    if(!flag)
    {
        gotoxy(40,i+1);
        cout<<"doctors list is empty!";
    }
    file.close();
    gotoxy(50,i+3);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    if(a_or_u)
    {
        admin_home();
    }
    else
    {
        home();
    }
}
void search_for_specialist()
{
    system("cls");
    gotoxy(40,8);
    cout<<"Searching for: ";
    string st[]= {"kk","Medicine","Cardiologist","Paediatrics","Paulmonologist","Endocrinologist","Surgery","ENT specialist","Eye specialist","Orthopadic surgeon","USG specialist","Radiology and imaging specialist","Hepatologist","Gastroenterologist","Gynecologist","Oncologist","Neurologist","Burn and plastic","Cardio-thoracic surgery","Neuro-sergery"};


    ofstream rr;
    string h1="./Doctors/n1.txt";
    const char *path=h1.c_str();
    rr.open(path);

    ifstream file;
    string h3="./Doctors/doctors_list.txt";
    const char *path3=h3.c_str();
    file.open(path3);
    doc ss;
    bool flag1=false;
    gotoxy(40,9);
    cout<<"1.Medicine";
    gotoxy(40,10);
    cout<<"2.Cardiologist";
    gotoxy(40,11);
    cout<<"3.Paediatrics";
    gotoxy(40,12);
    cout<<"4.Paulmonologist";
    gotoxy(40,13);
    cout<<"5.Endocrinologist";
    gotoxy(40,14);
    cout<<"6.Surgery";
    gotoxy(40,15);
    cout<<"7.ENT specialist";
    gotoxy(40,16);
    cout<<"8.Eye specialist";
    gotoxy(40,17);
    cout<<"9.Orthopadic surgeon";
    gotoxy(40,18);
    cout<< "10.USG specialist";
    gotoxy(80,9);
    cout<<"11.Radiology and imaging specialist";
    gotoxy(80,10);
    cout<<"12.Hepatologist";
    gotoxy(80,11);
    cout<<"13.Gastroenterologist";
    gotoxy(80,12);
    cout<<"14.Gynecologist";
    gotoxy(80,13);
    cout<<"15.Oncologist";
    gotoxy(80,14);
    cout<< "16.Neurologist";
    gotoxy(80,15);
    cout<<"17.Burn and plastic";
    gotoxy(80,16);
    cout<<"18.Cardio-thoracic surgery";
    gotoxy(80,17);
    cout<<"19.Neuro-sergery";

    gotoxy(40,20);
    cout<<"Press any number(1-19): ";
    int k;
    cin>>k;
    system("cls");
    while(file>>ss.id,file.ignore(),getline(file,ss.doctors_name),getline(file,ss.degree),getline(file,ss.specialist),getline(file,ss.chamber),getline(file,ss.work_days),getline(file,ss.visiting_hour),file>>ss.phone)
    {
        if(st[k]==ss.specialist)
        {

            // cout<<st[k]<<" "<<ss.specialist<<endl;
            //  system("pause");
            flag1=true;
            rr<<ss.id;
            rr<<endl;
            rr<<ss.doctors_name;
            rr<<endl;
            rr<<ss.degree;
            rr<<endl;

            rr<<ss.specialist;
            rr<<endl;
            rr<<ss.chamber;
            rr<<endl;
            rr<<ss.work_days;
            rr<<endl;
            rr<<ss.visiting_hour;
            rr<<endl;
            rr<<ss.phone;
            rr<<endl;

        }

    }

    file.close();
    rr.close();
    ifstream ff1;
    ff1.open(path);
    int i=3;
    if(!flag1)
    {
        gotoxy(40,1);
        cout<<"Not found this specialist in the list!"<<endl;
    }
    else
    {
        doc kk;
        gotoxy(2,1);
        cout<<"ID";
        gotoxy(10,1);
        cout<<"Dr.Name";
        gotoxy(40,1);
        cout<<"Degree ";
        gotoxy(70,1);
        cout <<"Chamber";
        gotoxy(105,1);
        cout<<"Working days";
        gotoxy(120,1);
        cout<<"Visiting hour";
        gotoxy(140,1);
        cout<<"Contact number";
        while(ff1>>ss.id,ff1.ignore(),getline(ff1,ss.doctors_name),getline(ff1,ss.degree),getline(ff1,ss.specialist),getline(ff1,ss.chamber),getline(ff1,ss.work_days),getline(ff1,ss.visiting_hour),ff1>>ss.phone)
        {
            gotoxy(2,++i);
            cout<<ss.id;
            ss.doctors_name=make_formal(ss.doctors_name);
            gotoxy(10,i);
            cout<<ss.doctors_name;
            bool kkk=0;
            for(int j=0; j<ss.degree.size(); j++)
            {
                if(kkk){
                    break;
                }
                if(ss.degree[i]=='('){
                    kkk=1;
                   }
                ss.degree[j]=toupper(ss.degree[j]);
            }
            gotoxy(40,i);
            cout<<ss.degree;

            ss.chamber=make_formal(ss.chamber);
            gotoxy(70,i);
            cout<<ss.chamber;
            gotoxy(105,i);
            cout<<ss.work_days;
            gotoxy(120,i);
            cout<<ss.visiting_hour;
            gotoxy(140,i);
            cout<<ss.phone;
            i++;
        }
        cout<<endl;
    }

    ff1.close();

    remove(path);
    file.close();
    gotoxy(40,i+3);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    home();
}
void delete_thalassemia_patient_info()
{
    system("cls");
    gotoxy(40,5);
    cout<<"Enter patient ID which info. you want to delete: ";
    int kk;
    cin>>kk;
    string h1="./Thalassamia/patient_list.txt";
    ifstream file;
    const char *path1=h1.c_str();
    file.open(path1);
    th data;
    ofstream f1;
    f1.open("./Thalassamia/n1.txt");
    bool flag1=0;
    bool flag2=0;
    while(file>>data.id,file.ignore(),getline(file,data.name),file>>data.contact_num>>data.district>>data.division)
    {
        if(data.id!=kk)
        {
            f1<<data.id;
            f1<<endl;
            f1<<data.name;
            f1<<endl;
            f1<<data.contact_num;
            f1<<endl;
            f1<<data.district;
            f1<<endl;
            f1<<data.division;
            f1<<endl;

        }
        else
        {
            flag1=1;
        }
        flag2=1;
    }
    file.close();
    f1.close();

    remove("./Thalassamia/patient_list.txt");
    rename("./Thalassamia/n1.txt","./Thalassamia/patient_list.txt");
    gotoxy(40,8);
    if(!flag2)
    {
        cout<<"Patient list is empty."<<endl;
    }
    else if(!flag1)
    {
        cout<<"This id is not found in the list."<<endl;
    }
    else
    {
        cout<<"Patient info. deleted successfully."<<endl;
    }
    gotoxy(40,10);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    admin_home();
}
void update_thalassamia_info()
{
    system("cls");
    gotoxy(40,10);
    cout<<"1.update patient name.";
    gotoxy(40,11);
    cout<<"2.Update contact number.";
    gotoxy(40,12);
    cout<<"3.update district.";
    gotoxy(40,13);
    cout<<"4.update division.";
    gotoxy(40,14);
    cout<<"5.home.";
    gotoxy(40,16);
    cout<<"Press any number(1-4): ";
    char y;
    cin>>y;
    switch(y)
    {
    case '1':
    {
        system("cls");
        ifstream file2;
        string h1="./Thalassamia/patient_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        th data;
        ofstream file3;
        string h2="./Thalassamia/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter patient ID whose name you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        /// while(file>>data.id,file.ignore(),getline(file,data.name),file>>data.contact_num>>data.district>>data.division)
        while(file2>>data.id,file2.ignore(),getline(file2,data.name),file2>>data.contact_num>>data.district>>data.division)
        {
            if(q != data.id)
            {

                file3<<data.id;
                file3<<endl;
                file3<<data.name;
                file3<<endl;
                file3<<data.contact_num;
                file3<<endl;
                file3<<data.district;
                file3<<endl;
                file3<<data.division;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cin.ignore();
                cout<<("Enter new name : ");
                string r;
                getline(cin,r);
                file3<<data.id;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<data.contact_num;
                file3<<endl;
                file3<<data.district;
                file3<<endl;
                file3<<data.division;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!f)
        {
            cout<<"Patient with this ID is not found.";
        }
        else
        {

            cout<<"name successfully updated.";
        }
        remove("./Thalassamia/patient_list.txt");
        rename("./Thalassamia/new.txt","./Thalassamia/patient_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }
    case '2':
    {

        system("cls");
        ifstream file2;
        string h1="./Thalassamia/patient_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        th data;
        ofstream file3;
        string h2="./Thalassamia/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter patient ID whose contact number you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        ///  while(file>>data.id,file.ignore(),getline(file,data.name),file>>data.contact_num>>data.district>>data.division)
        while(file2>>data.id,file2.ignore(),getline(file2,data.name),file2>>data.contact_num>>data.district>>data.division)
        {
            if(q != data.id)
            {

                file3<<data.id;
                file3<<endl;
                file3<<data.name;
                file3<<endl;
                file3<<data.contact_num;
                file3<<endl;
                file3<<data.district;
                file3<<endl;
                file3<<data.division;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,11);
                cout<<("Enter new contact number : ");
                string r;
                cin>>r;
                file3<<data.id;
                file3<<endl;
                file3<<data.name;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<data.district;
                file3<<endl;
                file3<<data.division;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,12);
        if(!f)
        {
            cout<<"Patient with this ID is not found.";
        }
        else
        {
            cout<<"contact number successfully updated.";
        }
        remove("./Thalassamia/patient_list.txt");
        rename("./Thalassamia/new.txt","./Thalassamia/patient_list.txt");

        gotoxy(40,13);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }
    case '3':
    {
        system("cls");
        ifstream file2;
        string h1="./Thalassamia/patient_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        th data;
        ofstream file3;
        string h2="./Thalassamia/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter patient ID whose district you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        while(file2>>data.id,file2.ignore(),getline(file2,data.name),file2>>data.contact_num>>data.district>>data.division)
        {
            if(q != data.id)
            {

                file3<<data.id;
                file3<<endl;
                file3<<data.name;
                file3<<endl;
                file3<<data.contact_num;
                file3<<endl;
                file3<<data.district;
                file3<<endl;
                file3<<data.division;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cout<<("Enter new district number : ");
                string r;
                cin>>r;
                file3<<data.id;
                file3<<endl;
                file3<<data.name;
                file3<<endl;
                file3<<data.contact_num;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<data.division;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,13);
        if(!f)
        {
            cout<<"Patient with this ID is not found.";
        }
        else
        {
            cout<<"District successfully updated.";
        }
        remove("./Thalassamia/patient_list.txt");
        rename("./Thalassamia/new.txt","./Thalassamia/patient_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }
    case '4':
    {

        system("cls");
        ifstream file2;
        string h1="./Thalassamia/patient_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        th data;
        ofstream file3;
        string h2="./Thalassamia/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter patient ID whose Division you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        while(file2>>data.id,file2.ignore(),getline(file2,data.name),file2>>data.contact_num>>data.district>>data.division)
        {
            if(q != data.id)
            {

                file3<<data.id;
                file3<<endl;
                file3<<data.name;
                file3<<endl;
                file3<<data.contact_num;
                file3<<endl;
                file3<<data.district;
                file3<<endl;
                file3<<data.division;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cout<<("Enter new contact number : ");
                string r;
                cin>>r;
                file3<<data.id;
                file3<<endl;
                file3<<data.name;
                file3<<endl;
                file3<<data.contact_num;
                file3<<endl;
                file3<<data.district;
                file3<<endl;
                file3<<r;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,13);
        if(!f)
        {
            cout<<"Patient with this ID is not found.";
        }
        else
        {
            cout<<"Division successfully updated.";
        }
        remove("./Thalassamia/patient_list.txt");
        rename("./Thalassamia/new.txt","./Thalassamia/patient_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }
    case '5':
    {
        admin_home();
        break;
    }

    default:
    {
        gotoxy(40,10);
        cout<<"Wrong choice!Press Enter to go to home: ";
        cin.get();
        cin.get();
        admin_home();
    }

    }
}
void delete_doctors_info()
{
    system("cls");
    gotoxy(40,5);
    cout<<"Enter Doctor ID which info. you want to delete: ";
    int kk;
    cin>>kk;
    string h1="./Doctors/doctors_list.txt";
    ifstream file;
    const char *path1=h1.c_str();
    file.open(path1);
    doc ss;
    ofstream f1;
    f1.open("./Doctors/n1.txt");
    bool flag1=0;
    bool flag2=0;
    while(file>>ss.id,file.ignore(),getline(file,ss.doctors_name),getline(file,ss.degree),getline(file,ss.specialist),getline(file,ss.chamber),getline(file,ss.work_days),getline(file,ss.visiting_hour),file>>ss.phone)
    {
        if(ss.id!=kk)
        {
            f1<<ss.id;
            f1<<endl;
            f1<<ss.doctors_name;
            f1<<endl;
            f1<<ss.degree;
            f1<<endl;
            f1<<ss.specialist;
            f1<<endl;
            f1<<ss.chamber;
            f1<<endl;
            f1<<ss.work_days;
            f1<<endl;
            f1<<ss.visiting_hour;
            f1<<endl;
            f1<<ss.phone;
            f1<<endl;

        }
        else
        {
            flag1=1;
        }
        flag2=1;
    }
    file.close();
    f1.close();

    remove("./Doctors/doctors_list.txt");
    rename("./Doctors/n1.txt","./Doctors/doctors_list.txt");
    gotoxy(40,8);
    if(!flag2)
    {
        cout<<"Doctors list is empty."<<endl;
    }
    else if(!flag1)
    {
        cout<<"This id is not found in the list."<<endl;
    }
    else
    {
        cout<<"Doctors info. successfully deleted."<<endl;
    }
    gotoxy(40,10);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    admin_home();
}

void update_doctors_info()
{
    system("cls");
    gotoxy(40,10);
    cout<<"1.update doctors name.";
    gotoxy(40,11);
    cout<<"2.Update Degree.";
    gotoxy(40,12);
    cout<<"3.update Chamber.";
    gotoxy(40,13);
    cout<<"4.update working days.";
    gotoxy(40,14);
    cout<<"5.Update working hour.";
    gotoxy(40,15);
    cout<<"6.Update contact number.";
    gotoxy(40,16);
    cout<<"7.home.";
    gotoxy(40,17);
    cout<<"Press any number(1-7): ";
    char y;
    cin>>y;

    switch(y)
    {
    case '1':
    {
        system("cls");
        ifstream file2;
        string h1="./Doctors/doctors_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        doc ss;
        ofstream file3;
        string h2="./Doctors/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter doctor  ID whose name you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        ///while(file>>ss.id,file.ignore(),getline(file,ss.doctors_name),getline(file,ss.degree),getline(file,ss.specialist),getline(file,ss.chamber),getline(file,ss.work_days),getline(file,ss.visiting_hour),file>>ss.phone)
        while(file2>>ss.id,file2.ignore(),getline(file2,ss.doctors_name),getline(file2,ss.degree),getline(file2,ss.specialist),getline(file2,ss.chamber),getline(file2,ss.work_days),getline(file2,ss.visiting_hour),file2>>ss.phone)
        {
            if(q != ss.id)
            {
                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cin.ignore();
                cout<<("Enter new name : ");
                string r;
                getline(cin,r);

                file3<<ss.id;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!f)
        {
            cout<<"Patient with this ID is not found.";
        }
        else
        {

            cout<<"name successfully updated.";
        }
        remove("./Doctors/doctors_list.txt");
        rename("./Doctors/new.txt","./Doctors/doctors_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }
    case '2':
    {
        system("cls");
        ifstream file2;
        string h1="./Doctors/doctors_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        doc ss;
        ofstream file3;
        string h2="./Doctors/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter doctor  ID whose Degree you want to update: ";
        int q;
        cin>>q;
        bool mmm=0;

        while(file2>>ss.id,file2.ignore(),getline(file2,ss.doctors_name),getline(file2,ss.degree),getline(file2,ss.specialist),getline(file2,ss.chamber),getline(file2,ss.work_days),getline(file2,ss.visiting_hour),file2>>ss.phone)
        {
            if(q != ss.id)
            {
                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;
            }
            else
            {

                mmm=1;
                gotoxy(40,12);
                cin.ignore();
                cout<<("Enter Degree : ");
                string r;
                getline(cin,r);


                if(r.find("Medicine")!= string :: npos)
                {
                    ss.specialist="Medicine";
                }
                else if(r.find("Cardiologist")!= string :: npos)
                {
                    ss.specialist="Cardiologist";
                }
                else if(r.find("Paediatrics")!= string :: npos)
                {
                    ss.specialist="Paediatrics";
                }
                else if(r.find("Paulmonology")!= string :: npos)
                {
                    ss.specialist="Paulmonologist";
                }
                else if(r.find("Endocrinology")!= string :: npos)
                {
                    ss.specialist="Endocrinologist";
                }
                else if(r.find("Surgery")!= string :: npos)
                {
                    //cout<<"1";
                    //system("pause");
                    ss.specialist="Surgery";
                }
                else if(r.find("ENT")!= string :: npos)
                {
                    ss.specialist="ENT specialist";
                }
                else if(r.find("Eye")!= string :: npos)
                {
                    ss.specialist="Eye specialist";   ///"Medicine","Cardiologist","Paediatrics","Paulmonologist","Endocrinologist","Surgery","ENT specialist","Eye specialist","Orthopadic surgeon","USG specialist","Radiology and imaging specialist","Hepatologist","Gastroenterologist","Gynecologist",""Oncologist","Neurologist","Burn and plastic","Cardio-thoracic surgery","Neuro-sergery";
                }
                else if(r.find("Orthopaedics")!= string :: npos)
                {
                    ss.specialist="Orthopadic surgeon";
                }
                else if(r.find("USG")!= string :: npos)
                {
                    ss.specialist="USG specialist";
                }
                else if(r.find("Radiology and imaging")!= string :: npos)
                {
                    ss.specialist="Radiology and imaging specialist";
                }
                else if(r.find("Hepatology")!= string :: npos)
                {
                    ss.specialist="Hepatologist";
                }
                else if(r.find("Gastroent")!= string :: npos)
                {
                    ss.specialist="Gastroenterologist";
                }
                else if(r.find("gyne and obs.")!= string :: npos)
                {
                    ss.specialist="Gynecologist";
                }
                else if(r.find("Oncology")!= string :: npos)
                {
                    ss.specialist="Oncologist";
                }
                else if(r.find("Neurology")!= string :: npos)
                {
                    ss.specialist="Neurologist";
                }
                else if(r.find("Burn and plastic")!= string :: npos)
                {
                    ss.specialist="Burn and plastic surgery";
                }
                else if(r.find("Cardiothoracic surgery")!= string :: npos)
                {
                    ss.specialist="Cardio-thoracic surgery";
                }
                else if(r.find("Neuro-sergery") != string :: npos)
                {
                    ss.specialist="Neuro-sergery";
                }
                else
                {
                    gotoxy(40,14);

                    cout<<"Wrong Input!!Press Enter to continue: ";
                    file2.close();
                    file3.close();
                    cin.get();
                    cin.get();
                    admin_home();
                }
                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;

            }

        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!mmm)
        {
            cout<<"No Doctor found With this ID.";
        }
        else
        {
            cout<<"Degree successfully updated.";
        }
        remove("./Doctors/doctors_list.txt");
        rename("./Doctors/new.txt","./Doctors/doctors_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }

    case '3':
    {

        system("cls");
        ifstream file2;
        string h1="./Doctors/doctors_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        doc ss;
        ofstream file3;
        string h2="./Doctors/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter doctor  ID whose chamber you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        while(file2>>ss.id,file2.ignore(),getline(file2,ss.doctors_name),getline(file2,ss.degree),getline(file2,ss.specialist),getline(file2,ss.chamber),getline(file2,ss.work_days),getline(file2,ss.visiting_hour),file2>>ss.phone)
        {
            if(q != ss.id)
            {
                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cin.ignore();
                cout<<("Enter chamber : ");
                string r;
                getline(cin,r);

                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!f)
        {
            cout<<"Patient with this ID is not found.";
        }
        else
        {

            cout<<"Information successfully updated.";
        }
        remove("./Doctors/doctors_list.txt");
        rename("./Doctors/new.txt","./Doctors/doctors_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;

    }
    case '4':
    {

        system("cls");
        ifstream file2;
        string h1="./Doctors/doctors_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        doc ss;
        ofstream file3;
        string h2="./Doctors/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter doctor  ID whose information you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        while(file2>>ss.id,file2.ignore(),getline(file2,ss.doctors_name),getline(file2,ss.degree),getline(file2,ss.specialist),getline(file2,ss.chamber),getline(file2,ss.work_days),getline(file2,ss.visiting_hour),file2>>ss.phone)
        {
            if(q != ss.id)
            {
                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cin.ignore();
                cout<<("Enter Working days : ");
                string r;
                cin>>r;

                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!f)
        {
            cout<<"Doctor with this ID is not found.";
        }
        else
        {
            cout<<"Information successfully updated.";
        }
        remove("./Doctors/doctors_list.txt");
        rename("./Doctors/new.txt","./Doctors/doctors_list.txt");
        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }

    case '5':
    {

        system("cls");
        ifstream file2;
        string h1="./Doctors/doctors_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        doc ss;
        ofstream file3;
        string h2="./Doctors/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter doctor  ID whose information you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        while(file2>>ss.id,file2.ignore(),getline(file2,ss.doctors_name),getline(file2,ss.degree),getline(file2,ss.specialist),getline(file2,ss.chamber),getline(file2,ss.work_days),getline(file2,ss.visiting_hour),file2>>ss.phone)
        {
            if(q != ss.id)
            {
                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cin.ignore();
                cout<<("Enter Visiting hour : ");
                string r;
                cin>>r;

                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!f)
        {
            cout<<"Doctor with this ID is not found.";
        }
        else
        {
            cout<<"Information successfully updated.";
        }
        remove("./Doctors/doctors_list.txt");
        rename("./Doctors/new.txt","./Doctors/doctors_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }
    case '6':
    {

        system("cls");
        ifstream file2;
        string h1="./Doctors/doctors_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        doc ss;
        ofstream file3;
        string h2="./Doctors/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter doctor  ID whose information you want to update: ";
        int q;
        cin>>q;
        bool f=0;

        while(file2>>ss.id,file2.ignore(),getline(file2,ss.doctors_name),getline(file2,ss.degree),getline(file2,ss.specialist),getline(file2,ss.chamber),getline(file2,ss.work_days),getline(file2,ss.visiting_hour),file2>>ss.phone)
        {


            if(q != ss.id)
            {
                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<ss.phone;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cin.ignore();
                cout<<("Enter contact number : ");
                string r;
                cin>>r;

                file3<<ss.id;
                file3<<endl;
                file3<<ss.doctors_name;
                file3<<endl;
                file3<<ss.degree;
                file3<<endl;
                file3<<ss.specialist;
                file3<<endl;
                file3<<ss.chamber;
                file3<<endl;
                file3<<ss.work_days;
                file3<<endl;
                file3<<ss.visiting_hour;
                file3<<endl;
                file3<<r;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!f)
        {
            cout<<"Doctor with this ID is not found.";
        }
        else
        {
            cout<<"Information successfully updated.";
        }
        remove("./Doctors/doctors_list.txt");
        rename("./Doctors/new.txt","./Doctors/doctors_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }
    case '7':
        admin_home();
        break;
    default:
    {
        gotoxy(40,20);
        cout<<"Wrong choice!!Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();

    }

    }

}

void delete_ambulance_information()
{
    system("cls");
    gotoxy(40,5);
    cout<<"Enter Ambulance ID you want to delete: ";
    int kk;
    cin>>kk;
    string h1="./Ambulance/ambulance_list.txt";
    ifstream file;
    const char *path1=h1.c_str();
    file.open(path1);
    ambu k;
    ofstream f1;

    f1.open("./Ambulance/n1.txt");
    bool flag1=0;
    bool flag2=0;
    while(file>>k.id,file.ignore(),getline(file,k.org_name),file>>k.location>>k.phn_num)
    {
        if(k.id!=kk)
        {
            f1<<k.id;
            f1<<endl;
            f1<<k.org_name;
            f1<<endl;
            f1<<k.location;
            f1<<endl;
            f1<<k.phn_num;
            f1<<endl;
        }
        else
        {
            flag1=1;
        }
        flag2=1;
    }
    file.close();
    f1.close();

    remove("./Ambulance/ambulance_list.txt");
    rename("./Ambulance/n1.txt","./Ambulance/ambulance_list.txt");
    gotoxy(40,8);
    if(!flag2)
    {
        cout<<" list is empty."<<endl;
    }
    else if(!flag1)
    {
        cout<<"This id is not found in the list."<<endl;
    }
    else
    {
        cout<<"Ambulance info. deleted successfully."<<endl;
    }
    gotoxy(40,10);
    cout<<"Press Enter to continue: ";
    cin.get();
    cin.get();
    admin_home();

}
void update_ambulance_info()
{
    system("cls");
    gotoxy(40,10);
    cout<<"1.update organization name.";
    gotoxy(40,11);
    cout<<"2.Update contact number.";
    gotoxy(40,12);
    cout<<"3.update location.";
    gotoxy(40,13);
    cout<<"4.home.";
    gotoxy(40,15);
    cout<<"Press any number(1-4): ";
    char y;
    cin>>y;
    switch(y)
    {
    case '1':
    {
        system("cls");
        ifstream file2;
        string h1="./Ambulance/ambulance_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        ambu data;
        ofstream file3;
        string h2="./Ambulance/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter Ambulance ID which org. name you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        /// while(file>>ss.id,file.ignore(),getline(file,ss.org_name),getline(file,ss.location),file>>ss.phn_num)

        while(file2>>data.id,file2.ignore(),getline(file2,data.org_name),getline(file2,data.location),file2>>data.phn_num)
        {
            if(q != data.id)
            {

                file3<<data.id;
                file3<<endl;
                file3<<data.org_name;
                file3<<endl;
                file3<<data.location;
                file3<<endl;
                file3<<data.phn_num;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cin.ignore();
                cout<<("Enter org. name : ");
                string r;
                getline(cin,r);
                file3<<data.id;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<data.location;
                file3<<endl;
                file3<<data.phn_num;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!f)
        {
            cout<<"No Data found with this id.";
        }
        else
        {

            cout<<"Org.name successfully updated.";
        }
        remove("./Ambulance/ambulance_list.txt");
        rename("./Ambulance/new.txt","./Ambulance/ambulance_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }
    case '2':
    {

        system("cls");
        ifstream file2;
        string h1="./Ambulance/ambulance_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        ambu data;
        ofstream file3;
        string h2="./Ambulance/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter Ambulance ID which contact number info. you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        while(file2>>data.id,file2.ignore(),getline(file2,data.org_name),getline(file2,data.location),file2>>data.phn_num)
        {
            if(q != data.id)
            {

                file3<<data.id;
                file3<<endl;
                file3<<data.org_name;
                file3<<endl;
                file3<<data.location;
                file3<<endl;
                file3<<data.phn_num;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);
                cout<<("Enter contact number: ");
                string r;
                cin>>r;
                file3<<data.id;
                file3<<endl;
                file3<<data.org_name;
                file3<<endl;
                file3<<data.location;
                file3<<endl;
                file3<<r;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!f)
        {
            cout<<"No Data found with this id.";
        }
        else
        {

            cout<<"Contact number successfully updated.";
        }
        remove("./Ambulance/ambulance_list.txt");
        rename("./Ambulance/new.txt","./Ambulance/ambulance_list.txt");

        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;
    }
    case '3':

    {
        system("cls");
        ifstream file2;
        string h1="./Ambulance/ambulance_list.txt";
        const char *path1=h1.c_str();
        file2.open(path1);
        ambu data;
        ofstream file3;
        string h2="./Ambulance/new.txt";
        const char *path2=h2.c_str();

        file3.open(path2);

        gotoxy(40,10);
        cout<<"Enter Org. id which location you want to update: ";
        int q;
        cin>>q;
        bool f=0;
        while(file2>>data.id,file2.ignore(),getline(file2,data.org_name),getline(file2,data.location),file2>>data.phn_num)
        {
            if(q != data.id)
            {

                file3<<data.id;
                file3<<endl;
                file3<<data.org_name;
                file3<<endl;
                file3<<data.location;
                file3<<endl;
                file3<<data.phn_num;
                file3<<endl;
            }
            else
            {
                f=1;
                gotoxy(40,12);

                cout<<("Enter location : ");
                string r;
                cin>>r;
                file3<<data.id;
                file3<<endl;
                file3<<data.org_name;
                file3<<endl;
                file3<<r;
                file3<<endl;
                file3<<data.phn_num;
                file3<<endl;

            }
        }
        file2.close();
        file3.close();
        gotoxy(40,14);
        if(!f)
        {
            cout<<"No Data found with this id.";
        }
        else
        {
            cout<<"Data successfully updated.";
        }
        remove("./Ambulance/ambulance_list.txt");
        rename("./Ambulance/new.txt","./Ambulance/ambulance_list.txt");
        gotoxy(40,15);
        cout<<"Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();
        break;

    }
    case '4':
    {
        admin_home();
        break;
    }
    default:
    {
        gotoxy(40,17);
        cout<<"Wrong choice!Press Enter to continue: ";
        cin.get();
        cin.get();
        admin_home();

    }

    }
}

////////////////////////////////////////////////END///////////////////////////////////////////////////////////////////////////////


