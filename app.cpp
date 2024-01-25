#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;
//-----------GLOBAL VARIABILES FOR THE CSV FILE---------------
ifstream inputFile;
std::ofstream out;

//---------------RSA ENCRYPTION----------------------
//find gcd
int gcd(int a, int b){
    int t;
    while(1){
        t=a%b;
        if(t==0)return b;
        a=b;
        b=t;
    }
}
string RSAencrypt(string x){
    string y;
    for(int i=0;i<x.size();i++){
        auto message = double(x[i]);
        double c = pow(message, 7); //encrypt the message
        c = fmod(c, 13*11);
        if(c==44)c=c+1;
        y.push_back(char(c));
    }
    return y;
}


//-----------------CLASS USER----------------------
class User{
    
    public:
       void addUser(string username, string password, string mail){
            out<<username<<","<<password<<','<<mail<<endl;
        };
        int login(string username, string password){
                inputFile.open("users.csv");
                string line="";
                while(getline(inputFile,line)){
                    string name;
                    string pass;
                    string mail;

                    stringstream inputString(line);
                    getline(inputString, name, ',');
                    getline(inputString, pass, ',');
                    getline(inputString, mail);
                    line="";

                    if(name==username)
                        if(pass!=password)throw "incorrect password";
                        else return 1;
                }
                inputFile.close();
            throw "No matching username found.";
        }
        int verifyMail(string mail){
            char arr[mail.length()+1];
            string names[4]={"yahoo.com","gmail.com","outlook.com","icloud.com"};
            strcpy(arr,mail.c_str());
            string aux;
            int i;
            char *p=strtok(arr,"@");
            if(p!=NULL){
                p=strtok(NULL," ");
                aux=p;
                for(i=0;i<=3;i++)
                    if(p==names[i])return 1;
            }
            throw "Incorrect e-mail format.";
            return 0;
        }
        void strongPass(string password){
            string lowLet[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
            string uppLet[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
            string num[10]={"0","1","2","3","4","5","6","7","8","9"};
            string specCar[30]={"~","`","!","@","#","$","%","^","&","*","(",")","_","-","+","=","{","[","}","]","|",":",";","'","<",",",">",".","?","/"};
            int OK=0,i;
            size_t found;
            for(i=0;i<25;i++){
                found=password.find(lowLet[i]);
                if(found != string::npos){
                    OK=1;
                    break;
                }
            }
            for(i=0;i<25;i++){
                found=password.find(uppLet[i]);
                if(found != string::npos){
                    OK=2;
                    break;
                }
            }
            for(i=0;i<=9;i++){
                found=password.find(num[i]);
                if(found != string::npos){
                    OK=3;
                    break;
                }
            }
            for(i=0;i<=29;i++){
                found=password.find(specCar[i]);
                if(found != string::npos){
                    OK=4;
                    break;
                }
            }
            if(OK!=4)throw "Unsafe password";
        }
        void searchStart(string searchSt){
            ifstream in;
            int count=0;
            in.open("routes.csv");
            string line="";
            while(getline(in,line)){
                string start;
                string dest;
                string ID;
                int year, month, day, hour, minute;
                string tempString;

                stringstream inputString(line);

                getline(inputString, start, ',');
                getline(inputString, dest, ',');
                getline(inputString,tempString,',');
                year=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                month=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                day=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                hour=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                minute=atoi(tempString.c_str());
                getline(inputString,ID);
                line="";
                
                if(start==searchSt){
                    cout<<start<<'-'<<dest<<" leaving on "<<day<<'.'<<month<<'.'<<year<<" at "<<hour<<':'<<minute<<" train ID: "<<ID<<endl;
                    count++;
                }
            }   
            in.close();
            if(count==0)throw "No routes found";
        }
        void searchStartDest(string searchStart, string searchDest){
            ifstream in;
            int count=0;
            in.open("routes.csv");
            string line="";
            while(getline(in,line)){
                string start;
                string dest;
                string ID;
                int year, month, day, hour, minute;
                string tempString;

                stringstream inputString(line);

                getline(inputString, start, ',');
                getline(inputString, dest, ',');
                getline(inputString,tempString,',');
                year=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                month=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                day=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                hour=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                minute=atoi(tempString.c_str());
                getline(inputString,ID);
                line="";
                
                if(start==searchStart && dest==searchDest){
                    cout<<start<<'-'<<dest<<" leaving on "<<day<<'.'<<month<<'.'<<year<<" at "<<hour<<':'<<minute<<" train ID: "<<ID<<endl;
                    count++;
                }
            }   
            in.close();
            if(count==0)throw "No routes found";
        }
        void searchID(string schId){
            ifstream in;
            int count=0;
            in.open("routes.csv");
            string line="";
            cout<<"\t\t\tAvailable trains: "<<endl;
            while(getline(in,line)){
                string start;
                string dest;
                string ID;
                int year, month, day, hour, minute;
                string tempString;

                stringstream inputString(line);

                getline(inputString, start, ',');
                getline(inputString, dest, ',');
                getline(inputString,tempString,',');
                year=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                month=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                day=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                hour=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                minute=atoi(tempString.c_str());
                getline(inputString,ID);
                line="";
                
                if(ID==schId){
                    cout<<"\t\t"<<start<<'-'<<dest<<" leaving on "<<day<<'.'<<month<<'.'<<year<<" at "<<hour<<':'<<minute<<" train ID: "<<ID<<endl;
                    count++;
                }
            }   
            in.close();
            if(count==0)throw "No routes found";
        }
        int verifyID(string verId){
            ifstream in;
            int count=0;
            in.open("routes.csv");
            string line="";
            while(getline(in,line)){
                string start;
                string dest;
                string ID;
                int year, month, day, hour, minute;
                string tempString;

                stringstream inputString(line);

                getline(inputString, start, ',');
                getline(inputString, dest, ',');
                getline(inputString,tempString,',');
                year=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                month=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                day=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                hour=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                minute=atoi(tempString.c_str());
                getline(inputString,ID);
                line="";
                
                if(ID==verId){
                    cout<<endl<<endl<<"\t\t-------------TICKET SUCCESFULLY PURCHASED"<<endl;
                    cout<<"\t\t for train from "<<start<<" to "<<dest<<endl;
                    cout<<"leaving on "<<day<<'.'<<month<<'.'<<year<<" at "<<hour<<':'<<minute<<endl;
                    return 1;
                }
            }   
            in.close();
            if(count==0)throw "Invalid ID";
            return 0;
        }
    };

//-----------CLASS OPERATOR----------------------
class Operator{
    public:
        int login(string username, string password){
            inputFile.open("operators.csv");
                string line="";
                while(getline(inputFile,line)){
                    string name;
                    string pass;

                    stringstream inputString(line);
                    getline(inputString, name, ',');
                    getline(inputString, pass);
                    line="";

                    if(name==username)
                        if(pass!=password)throw "incorrect password";
                        else return 1;
                }
                inputFile.close();
            throw "No matching username found.";
        }
        void verifyTown(string town){
            int i, OK=1;
            size_t found;
            string specCar[29]={"~","`","!","@","#","$","%","^","&","*","(",")","_","+","=","{","[","}","]","|",":",";","'","<",",",">",".","?","/"};
            for(i=0;i<=29;i++){
                found=town.find(specCar[i]);
                if(found != string::npos){
                    OK=0;
                    break;
                }
            }
            if(OK==0)throw "eroare:Caractere neexistente in numele oraselor!";
        }
        int verifyDate(int year, char tempYear[], int month, char tempMonth[], int day, char tempDay[], int hour, char tempHour[], int minute, char tempMinute[]){
            int currYear;
            currYear=atoi(tempYear);
            int currMonth;
            currMonth=atoi(tempMonth);
            int currDay;
            currDay=atoi(tempDay);
            int currHour;
            currHour = atoi(tempHour);
            int currMinute;
            currMinute = atoi(tempMinute);
            if(month < 1 || month > 12)throw "Wrong month format";
            if(day<1 || day > 31)throw "Wrong day format";
            if(hour < 0 || hour > 23) throw "Wrong hour format";
            if(minute < 0 || minute > 59 ) throw "Wrong minute format";

            if(year >= currYear)
                if(month >= currMonth)
                    if(day >= currDay) 
                        if(hour >= currHour)
                            if(minute >= currMinute)return 1;
                            else   
                                if(hour > currHour)return 1;
                                    else throw "Minute in the past";
                        else
                            if(day > currDay)return 1;
                            else throw "Hour in the past";
                    else
                        if(month > currMonth)return 1;
                        else throw "Day in the past";
                else   
                    if(year > currYear)return 1;
                    else throw "Month in the past";    
                            
            else throw "Year in the past";
        }
        void addRoute(string start, string dest, int year, int month, int day, int hour, int minute, string ID){ 
            out<<start<<","<<dest<<","<<year<<","<<month<<","<<day<<","<<hour<<","<<minute<<","<<ID<<endl;
        }
        void deleteRoute(string delStart, string delDest, int delYear, int delMonth, int delDay, int delHour, int delMinute, string delID){
            ifstream in;
            ofstream out;
            int count=0;
            in.open("routes.csv");
            out.open("routesnew.csv");
            string line="";
            while(getline(in,line)){
                string start;
                string dest;
                string ID;
                int year, month, day, hour, minute;
                string tempString;

                stringstream inputString(line);

                getline(inputString, start, ',');
                getline(inputString, dest, ',');
                getline(inputString,tempString,',');
                year=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                month=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                day=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                hour=atoi(tempString.c_str());
                getline(inputString,tempString,',');
                minute=atoi(tempString.c_str());
                getline(inputString,ID);
                line="";
                
                //check if we have to delete the record
                if(start!=delStart || dest!= delDest || year!=delYear || month!=delMonth || day!=delDay || hour!=delHour || minute!=delMinute || ID!=delID){
                    //add record to new csv
                    out<<start<<","<<dest<<","<<year<<","<<month<<","<<day<<","<<hour<<","<<minute<<","<<ID<<endl;
                }
                else count=1;
            }
            in.close();
                out.close();
                remove("routes.csv");
                rename("routesnew.csv","routes.csv");
                if(count==0)throw "Route not found";
        }
    };
//---------------------MAIN----------------------
int main(){

   //------DECLARATII---------
    int d,OK,e;
    char c;
    User user;
    Operator oper;
    string username, password, aux, email;
    string start, dest, ID;
    int year, month, day, hour, minute;
    //---------WHO ARE YOU?------------
    cout<<"\t\t\t________________________________________\n\n\n";
    cout<<"\t\t\t           Who are you?                  \n\n\n";
    cout<<"\t\t\t__________[u]:Utilizator__________________\n\n\n";
    cout<<"\t\t\t__________[o]:Operator_____________________\n\n";
    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>c;
    system("CLS");
    cout<<flush;
    switch(c){
        case 'u':
            //----------LOGIN INTERFACE-------
            cout<<"\t\t\t_________________________________________________\n\n\n";
            cout<<"\t\t\t            Welcome to the Login page             \n\n\n";  
            cout<<"\t\t\t__________________ MENU ___________________________\n\n";
            cout<<"                                                          \n\n";
            cout<<"\t| Press 1 to LOGIN                    |"<<endl;
            cout<<"\t| Press 2 to REGISTER                 |"<<endl;
            cout<<"\t| Press 3 to EXIT                     |"<<endl;
            cout<<"\n\t\t\t Please enter your choice : ";
            cin>>d;
            cout<<endl;
            cin.get();
            system("CLS");
            cout<<flush;
            //-------SWITCH CASES--------------
            switch(d){

                //---------LOGIN-------------
                case 1:
                    cout<<"\t\t\t------------LOGIN PAGE----------------\n\n";
                    cout<<"\t\tUsername: ";
                    cin>>username;
                    cout<<"\t\tPassword: ";
                    cin>>password;
                    aux=RSAencrypt(password);
                    password=aux;
                    system("CLS");
                    cout<<flush;
                    try{
                        OK=user.login(username, password);
                        cout<<"\t\t\t-------Login succesful!----------";
                    }catch(const char *msg){
                        cerr<<msg<<endl;
                        system("PAUSE");
                        return 0;
                    }
                    break;
                    
                //-----------ADD USER----------
                case 2:
                    cout<<"\t\t\t--------CREATE ACCOUNT--------\n\n";
                    cout<<"\t\tUsername: ";
                    cin>>username;
                    cout<<"\t\tPassword: ";
                    cin>>password;
                    cout<<"\t\tConfirm password: ";
                    try{
                        cin>>aux;
                        if(aux!=password)throw "The password doesn't match";
                        user.strongPass(password);
                        aux=RSAencrypt(password);
                        password=aux;
                        cout<<"\t\tE-mail: ";
                        cin>>email;
                        OK=user.verifyMail(email);
                        out.open("users.csv", std::ios::app);
                        user.addUser(username, password, email);
                        cout<<"\n\n\t\t\t User added succesfully, logged in.";
                        OK=1;
                        out.close();
                        
                        
                    }catch(const char *msg){
                        cerr<<msg<<endl;
                        cout<<"\t\t\t---Try again later.";
                        system("PAUSE");
                        return 0;
                    }
                    break;

                //--------------EXIT-----------
                case 3:
                    cout<<"\t\t\t Thank You! See you soon! \n\n";
                    system("PAUSE");
                    return 0;
            
                }
            if(OK==1){
                system("CLS");
                cout<<flush;
                char e,g;
                cout<<"\t\t\t_________________________________________________\n\n\n";
                cout<<"                                                          \n\n";
                cout<<"\tPress s to search for train routes : ";
                cin>>e;
                system("CLS");
                cout<<flush;
                if(e=='s'){
                    int f;
                    string searchSt, searchDest, schID;
                    cout<<"\t\t\t_________________________________________________\n\n\n";
                    cout<<"\t\t\t__________________ MENU ___________________________\n\n";
                    cout<<"                                                          \n\n";
                    cout<<"\t| Press 4 to see all trains leaving from a starting point                                      |"<<endl;
                    cout<<"\t| Press 5 to see all trains leaving from a starting point and arriving to a certain destination|"<<endl;
                    cout<<"\t| Press 6 to search train using train ID                                                       |"<<endl;
                    cout<<"\t| Press 7 to EXIT                                                      |"<<endl;
                    cout<<"\n\t\t\t Please enter your choice : ";
                    cin>>f;
                    cout<<endl<<endl;
                    switch(f){
                        case 4:
                            cout<<"\t\t\tType your starting point: ";
                            cin>>searchSt;
                            cout<<endl<<endl;
                            try{
                            user.searchStart(searchSt);
                            }catch(const char* msg){
                                cout<<msg<<endl;
                                system("PAUSE");
                                return 0;
                            }
                            break;
                        case 5:
                            cout<<"\t\t\tType your starting point: ";
                            cin>>searchSt;
                            cout<<"\t\t\tType your destination: ";
                            cin>>searchDest;
                            try{
                                user.searchStartDest(searchSt,searchDest);
                            }catch(const char* msg){
                                cout<<msg<<endl;
                                system("PAUSE");
                                return 0;
                            }
                            break;
                        case 6:
                            cout<<"\t\t\tType the train's ID: ";
                            cin>>schID;
                            try{
                                user.searchID(schID);
                            }catch(const char* msg){
                                cout<<msg<<endl;
                                system("PAUSE");
                                return 0;
                            }
                            break;
                        case 7:
                            cout<<"\t\t\t Thank You! See you soon! \n\n";
                            system("PAUSE");
                            return 0;
                    }
                    cout<<endl<<endl;
                    cout<<"\t\t\tWould you like to buy a ticket? (y/n)";
                    cin>>g;
                    cout<<endl;
                    if(g=='y'){
                        string buyTrain;
                        cout<<"\t\t\tPlease enter the train id:";
                        cin>>buyTrain;
                        try{
                        OK=user.verifyID(buyTrain);
                        cout<<endl;
                        cout<<"\t\t\tThank you for your purchase!";
                        system("PAUSE");
                        }catch(const char* msg){
                            cout<<msg<<endl;
                            system("PAUSE");
                            return 0;
                        }
                    }
                    else cout<<"\t\t\tSorry we couldn't help. See you soon!";
                    
                }
                system("PAUSE");
                return 0;
            }
        case 'o': 
            cout<<"\t\t\t_________________________________________________\n\n\n";
            cout<<"\t\t\t            Welcome to the Login page             \n\n\n"; 
            cout<<"                                                         \n\n";
            cout<<"\t\tPlease enter your operator credentials: ";
            cout<<endl;
            cout<<"\t\tUsername: ";
            cin>>username;
            cout<<"\t\tPassword: ";
            cin>>password;
            aux=RSAencrypt(password);
            password=aux;
            try{
                OK=oper.login(username, password);
                cout<<"\n\n\t\t\t------Login succesful!--------";
            }catch(const char *msg){
                cerr<<msg<<endl;
                system("PAUSE");
                return 0;
            }
            system("CLS");
            cout<<flush;
            if(OK==1){
                cout<<"\t\t\t__________________ MENU ___________________________\n\n";
                cout<<"                                                          \n\n";
                cout<<"\t| Press 1 to ADD route                |"<<endl;
                cout<<"\t| Press 2 to DELETE route             |"<<endl;
                cout<<"\t| Press 3 to EXIT                     |"<<endl;
                cout<<"\n\t\t\t Please enter your choice : ";
                cin>>e;
                switch(e){
                    case 1:
                        time_t curr_time;
                        tm * curr_tm;
                        char currYear[10], currMonth[10], currDay[10], currHour[10], currMinute[10];
                        cout<<"\t\tFrom: ";
                        cin>>start;
                        cout<<"\t\tTo: ";
                        cin>>dest;
                        try{
                            oper.verifyTown(start);
                            oper.verifyTown(dest);
                            time(&curr_time);
                            curr_tm=localtime(&curr_time);
                            strftime(currYear,50,"%Y", curr_tm);
                            strftime(currMonth,50,"%m", curr_tm);
                            strftime(currDay,50,"%d", curr_tm);
                            strftime(currHour,50,"%H", curr_tm);
                            strftime(currMinute,50,"%M", curr_tm);
                            cout<<"\t\tYear: ";
                            cin>>year;
                            cout<<"\t\tMonth: ";
                            cin>>month;
                            cout<<"\t\tDay: ";
                            cin>>day;
                            cout<<"\t\tHour: ";
                            cin>>hour;
                            cout<<"\t\tMinute: ";
                            cin>>minute;
                            cout<<"\t\tTrain ID:";
                            cin>>ID;
                            OK=oper.verifyDate(year, currYear, month, currMonth, day, currDay, hour, currHour, minute, currMinute);
                            out.open("routes.csv", std::ios::app);
                            oper.addRoute(start, dest, year, month, day, hour, minute, ID);
                            out.close();
                            cout<<"\n\n\t\t\t--------Route added succesfully"<<endl;

                        }catch(const char* msg){
                            cout<<msg<<endl;
                            cout<<"\t\t\t--------Try again later!"<<endl;
                        }
                        
                        system("PAUSE");
                        return 0;
                    case 2:
                        cout<<"\t\t\tWhich route do you wish to delete?\n\n";
                        cout<<"\t\tStart: ";
                        cin>>start;
                        cout<<"\t\tDest: ";
                        cin>>dest;
                        cout<<"\t\tYear: ";
                        cin>>year;
                        cout<<"\t\tMonth: ";
                        cin>>month;
                        cout<<"\t\tDay: ";
                        cin>>day;
                        cout<<"\t\tHour: ";
                        cin>>hour;
                        cout<<"\t\tMinute: ";
                        cin>>minute;
                        cout<<"\t\tID: ";
                        cin>>ID;
                        try{
                            oper.deleteRoute(start, dest, year, month, day, hour, minute,ID);
                            cout<<"Route deleted succesfully"<<endl;
                        }catch(const char* msg){
                            cout<<msg<<endl;
                            cout<<"Try again later."<<endl;
                        }
                        system("PAUSE");
                        return 0;
                    case 3:
                        cout<<"\t\t\t Thank You! See you soon! \n\n";
                        system("PAUSE");
                        return 0;
                }
            }
        }

return 0;
}
