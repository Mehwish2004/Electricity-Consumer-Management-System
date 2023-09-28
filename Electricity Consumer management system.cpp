//headerfile for cin and cout
#include<iostream>
//headerfile for ignore and getline functions
#include<iomanip>
using namespace std;
//global variables
string fname[100]={""},lname[100]={""},username[100]={""},password[100]={""},cnic[100]={""};
int rate_fridge[100]={-1},rate_ac[100]={-1},rate_motor[100]={-1},rate_bulb[100]={-1},rate_fan[100]={-1};
int no_fridge[100]={-1},no_motor[100]={-1},no_bulb[100]={-1},no_fan[100]={-1},no_ac[100]={-1};
int full=0;
int acc_index=0;
bool loggedin=false;
int total_price[100]={-1};
void view_specific()
{
    cout<<"----------------------"<<endl;
    cout<<"First Name: "<<fname[acc_index]<<endl;
    cout<<"Last Name: "<<lname[acc_index]<<endl;
    cout<<"CNIC: "<<cnic[acc_index]<<endl;
    cout<<"username: "<<username[acc_index]<<endl;
    cout<<"Password: "<<password[acc_index]<<endl;
    cout<<"Fridge Unit: "<<rate_fridge[acc_index]<<endl;
    cout<<"Number of Fridges: "<<no_fridge[acc_index]<<endl;
    cout<<"Motor Unit: "<<rate_fridge[acc_index]<<endl;
    cout<<"Number of Motors: "<<no_fridge[acc_index]<<endl;
    cout<<"AC Unit: "<<rate_fridge[acc_index]<<endl;
    cout<<"Number of ACs: "<<no_fridge[acc_index]<<endl;
    cout<<"Bulb Unit: "<<rate_fridge[acc_index]<<endl;
    cout<<"Number of Bulbs: "<<no_fridge[acc_index]<<endl;
    cout<<"Fan Unit: "<<rate_fridge[acc_index]<<endl;
    cout<<"Number of Fans: "<<no_fridge[acc_index]<<endl;
    cout<<"----------------------"<<endl;
}
//function used for AC and returns integer value
int ac()
{
    cout<<"Power Consumption of AC (in Kwatt): ";
    cin>>rate_ac[acc_index];
    cout<<"Number of AC: ";
    cin>>no_ac[acc_index];
    return no_ac[acc_index]*rate_ac[acc_index];
}
//function used for fridge and also returns an integer value
int fridge()
{
    cout<<"Power Consumption of fridge(in Kwatt): ";
    cin>>rate_fridge[acc_index];
    cout<<"Number of fridge: ";
    cin>>no_fridge[acc_index];
    return no_fridge[acc_index]*rate_fridge[acc_index];
}
//function used for motor and also returns an integer value
int motor()
{
    cout<<"Power Consumption of motor(in Kwatt): ";
    cin>>rate_motor[acc_index];
    cout<<"Number of motor: ";
    cin>>no_motor[acc_index];
    return no_motor[acc_index]*rate_motor[acc_index];
}
//function used for bulbs and also returns an integer value
int bulb()
{
    cout<<"Power Consumption of bulb(in Kwatt): ";
    cin>>rate_bulb[acc_index];
    cout<<"Number of bulb: ";
    cin>>no_bulb[acc_index];
    return no_bulb[acc_index]*rate_bulb[acc_index];
}
//function used for fans and also returns an integer value
int fan()
{
    cout<<"Power Consumption of fan(in Kwatt): ";
    cin>>rate_fan[acc_index];
    cout<<"Number of fan: ";
    cin>>no_fan[acc_index];
    return no_fan[acc_index]*rate_fan[acc_index];
}

//function returns nothing
void current_customer()
{
    int choice1;
    view_specific();
    while(true)
    {
        cout<<"Which Meter Connection you want to update: ";
        cout<<endl<<"1. Fridge\n2. Bulb\n3. Motor\n4. Fan\n5. AC\n6. End"<<endl;
        cout<<"Which Meter Connection you want to update: "<<endl;
        cout<<">>>> ";
        cin>>choice1;
        //Switch case is used for home appliances details
        switch(choice1)
        {
            case 1:
            {
                total_price[acc_index]=fridge();
                total_price[acc_index]+=rate_fan[acc_index]*no_fan[acc_index];
                total_price[acc_index]+=rate_bulb[acc_index]*no_bulb[acc_index];
                total_price[acc_index]+=rate_ac[acc_index]*no_ac[acc_index];
                total_price[acc_index]+=rate_motor[acc_index]*no_motor[acc_index];
                break;
            }
            case 2:
            {
                total_price[acc_index]=bulb();
                total_price[acc_index]+=rate_fan[acc_index]*no_fan[acc_index];
                total_price[acc_index]+=rate_fridge[acc_index]*no_fridge[acc_index];
                total_price[acc_index]+=rate_ac[acc_index]*no_ac[acc_index];
                total_price[acc_index]+=rate_motor[acc_index]*no_motor[acc_index];
                break;
            }
            case 3:
            {
                total_price[acc_index]=motor();
                total_price[acc_index]+=rate_fan[acc_index]*no_fan[acc_index];
                total_price[acc_index]+=rate_bulb[acc_index]*no_bulb[acc_index];
                total_price[acc_index]+=rate_ac[acc_index]*no_ac[acc_index];
                total_price[acc_index]+=rate_fridge[acc_index]*no_fridge[acc_index];
                
                break;
            }
            case 4:
            {
                total_price[acc_index]=fan();
                total_price[acc_index]+=rate_fridge[acc_index]*no_fridge[acc_index];
                total_price[acc_index]+=rate_bulb[acc_index]*no_bulb[acc_index];
                total_price[acc_index]+=rate_ac[acc_index]*no_ac[acc_index];
                total_price[acc_index]+=rate_motor[acc_index]*no_motor[acc_index];
                break;
            }
            case 5:
            {
                total_price[acc_index]=ac();
                total_price[acc_index]+=rate_fan[acc_index]*no_fan[acc_index];
                total_price[acc_index]+=rate_bulb[acc_index]*no_bulb[acc_index];
                total_price[acc_index]+=rate_fridge[acc_index]*no_fridge[acc_index];
                total_price[acc_index]+=rate_motor[acc_index]*no_motor[acc_index];
                break;
            }
            case 6:
            {
                goto loop;
            }
        }
    }
    loop: cout<<"Total: "<<total_price[acc_index]<<endl;
}

//function returns nothing
void new_customer()
{
    total_price[acc_index]+=fridge();
    total_price[acc_index]+=fan();
    total_price[acc_index]+=bulb();
    total_price[acc_index]+=motor();
    total_price[acc_index]+=ac();
    cout<<"Meter: "<<total_price[acc_index];
    int n;
    cin>>n;
}
//function returns nothing
void main_menu()
{
    int choice3;
    while(true)
    {
        cout<<"1. New Customer"<<endl;
        cout<<"2. Current Customer"<<endl;
        cout<<"3. View Customer Details"<<endl;
        cout<<"4. Log Out"<<endl;
        cout<<"Enter Choice: ";
        cin>>choice3;
        switch(choice3)
        {
            case 1:
            {
                new_customer();
                break;
            }
            case 2:
            {
                current_customer();
                break;
            }
            case 3:
            {
                view_specific();
                break;
            }
            case 4:
            {
                break;
            }
        break;
        }
        if(choice3==4)
            break;
    }
    line: cout<<"You have been logged out"<<endl;
    loggedin=false;
}

//function returns nothing
void view_details()
{
    for(int i=0;i<100;i++)
    {
        if(fname[i]!="")
        {
            cout<<"----------------------"<<endl;
            cout<<"First Name: "<<fname[i]<<endl;
            cout<<"Last Name: "<<lname[i]<<endl;
            cout<<"CNIC: "<<cnic[i]<<endl;
            cout<<"username: "<<username[i]<<endl;
            cout<<"Password: "<<password[i]<<endl;
            cout<<"Fridge Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of Fridges: "<<no_fridge[i]<<endl;
            cout<<"Motor Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of Motors: "<<no_fridge[i]<<endl;
            cout<<"AC Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of ACs: "<<no_fridge[i]<<endl;
            cout<<"Bulb Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of Bulbs: "<<no_fridge[i]<<endl;
            cout<<"Fan Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of Fans: "<<no_fridge[i]<<endl;
            cout<<"----------------------"<<endl;
        }
    }
}

//register user
//function returns nothing
void registeruser()
{
    int index=0;
    while(fname[index]!="")
    {
        index++;
    }
    full=index;
    cout<<"First Name: ";
    cin>>fname[full];
    cout<<"Last Name: ";
    cin>>lname[full];
    cout<<"CNIC: ";
    cin>>cnic[full];
    cout<<"Username: ";
    cin>>username[full];
    cout<<"Password: ";
    cin>>password[full];
    full++;
}

//login user
//function returns nothing
void loginuser()
{
    int attempts=0;
    int total_attemps=3;
    string userlogin,passlogin;
    while(true)
    {
        if(attempts<total_attemps)
        {
            cout<<"Enter Username: ";
            //clear buffer
            cin.ignore();
            //for string
            getline(cin,userlogin);
            cout<<"Enter Password: ";
            cin>>passlogin;
            for(acc_index=0;acc_index<100;acc_index++)
            {
                if(userlogin==username[acc_index] && passlogin==password[acc_index])
                {
                    cout<<"Successful Login"<<endl;
                    loggedin=true;
                    break;
                }
            }
            if(acc_index!=100)
                break;
            attempts++;
        }
        else
        {
            cout<<"Timeout, Please Login Again"<<endl;
            loggedin=false;
            break;
        }
    }
    
    if(loggedin==true)
    {
        main_menu();
    }
}
//returns integer
int admin_view_spec()
{
    int i=0;
    string userinput;
    cout<<"Enter Username: ";
    cin>>userinput;
    for(i=0;i<100;i++)
    {
        if(userinput==username[i])
        {
            cout<<"----------------------"<<endl;
            cout<<"First Name: "<<fname[i]<<endl;
            cout<<"Last Name: "<<lname[i]<<endl;
            cout<<"CNIC: "<<cnic[i]<<endl;
            cout<<"username: "<<username[i]<<endl;
            cout<<"Password: "<<password[i]<<endl;
            cout<<"Fridge Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of Fridges: "<<no_fridge[i]<<endl;
            cout<<"Motor Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of Motors: "<<no_fridge[i]<<endl;
            cout<<"AC Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of ACs: "<<no_fridge[i]<<endl;
            cout<<"Bulb Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of Bulbs: "<<no_fridge[i]<<endl;
            cout<<"Fan Unit: "<<rate_fridge[i]<<endl;
            cout<<"Number of Fans: "<<no_fridge[i]<<endl;
            cout<<"----------------------"<<endl;
        }
    }
    if(i==100)
    {
        cout<<"Username entered does not exist"<<endl;
        return -1;
    }
    else
    {
        return i;
    }
        
    
}
//function returns nothing
void update_info(string info,int loc)
{
    string input;
    cout<<"Enter New "<<info<<" :";
    cin>>input;
    if(info=="firstname")
    {
        fname[loc]=input;
    }
    else if(info=="lastname")
    {
        lname[loc]=input;
    }
    else if(info=="cnic")
    {
        cnic[loc]=input;
    }
    else if(info=="username")
    {
        username[loc]=input;
    }
    else if(info=="password")
    {
        password[loc]=input;
    }
}
//function returns nothing
void admin_update()
{
    int choice5;
    int index= admin_view_spec();
    while(true)
    {
        cout<<"1. First Name\n2. Last Name\n3. CNIC\n4. username\n5. Password\n6. Log Out\n";
        cout<<"Enter Your Choice: ";
        cin>>choice5;
        switch(choice5)
        {
            case 1:
            {
                update_info("firstname",index);
                break;
            }
            case 2:
            {
                update_info("lastname",index);
                break;
            }
            case 3:
            {
                update_info("cnic",index);
                break;
            }
            case 4:
            {
                update_info("username",index);
                break;
            }
            case 5:
            {
                update_info("passwordd",index);
                break;
            }
            case 6:
            {
                break;
            }
        break;
        }
        if(choice5==6)
            break;
    }
    
}
//function returns nothing
void admin_delete()
{
    char confirm;
    int location=admin_view_spec();
    cout<<"Are you Sure you want to delete information (Y/N): ";
    cin>>confirm;
    if((confirm=='Y' || confirm == 'y') || (confirm=='N' || confirm == 'n'))
    {
        fname[location]=lname[location]=cnic[location]=username[location]=password[location]="";
        rate_fridge[location]=rate_ac[location]=rate_motor[location]=rate_bulb[location]=rate_fan[location]=0;
        no_fridge[location]=no_motor[location]=no_bulb[location]=no_fan[location]=no_ac[location]=total_price[location]=0;
        full--;
    }
    
}
//function returns nothing
void adminpage()
{
    int choice4;
    string adminusername="root";
    string adminpass="adminpass";
    string useradmin,passadmin;
    cout<<"---------Admin page------------"<<endl;
    cout<<"Username: ";
    cin.ignore();
    getline(cin,useradmin);
    cout<<"Password: ";
    cin.ignore();
    getline(cin,passadmin);
    if(useradmin==adminusername && passadmin==adminpass)
    {
        while(true)
        {
            cout<<"Successful Admin Login"<<endl;
            cout<<"1. View all data"<<endl;
            cout<<"2. View Specific data"<<endl;
            cout<<"3. Update specific data"<<endl;
            cout<<"4. delete data"<<endl;
            cout<<"5. Log Out"<<endl;
            cout<<"Enter Choice: ";
            cin>>choice4;
            switch(choice4)
            {
                case 1:
                {
                    view_details();
                    break;
                }
                case 2:
                {
                    int v=admin_view_spec();
                    break;
                }
                case 3:
                {
                    admin_update();
                    break;
                }
                case 4:
                {
                    admin_delete();
                    break;
                }
                case 5:
                {
                    break;
                }
                default:
                {
                    break;
                }
                break;
            }
        }
        
    }
    else
    {
        cout<<"Incorrect username or password, enter valid credentials"<<endl;
    }
}
//starting of main function
//main function returns an integer value
int main()
{
    int choice;
    while(true)
    {
        cout<<"1. Register\n2. Login\n3. Admin"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                registeruser();  
                break;
            }
            case 2:
            {
                loginuser();
                break;
            }
            case 3:
            {
                adminpage();
                break;
            }
        }
    }
}