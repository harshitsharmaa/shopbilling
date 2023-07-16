#include<iostream>
#include<fstream>

using namespace std;

class shopping{
    private:
    int pcode;
    float price;
    float dis;
    string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t__________________________________\n";
    cout << "\t\t\t                                  \n";
    cout << "\t\t\t       Supermaket Main Menu       \n";
    cout << "\t\t\t__________________________________\n";
    cout << "\t\t\t                                  \n\n";
    cout << "\t\t\t|  1) Administrator              |\n";
    cout << "\t\t\t|                                |\n";
    cout << "\t\t\t|  2) Buyer                      |\n";
    cout << "\t\t\t|                                |\n";
    cout << "\t\t\t|  3) Exit                       |\n";
    cout << "\t\t\t|                                |\n";
    cout << "\n\t\t Please Select : ";
    cin >> choice;

    switch(choice){
        case 1:
        cout<<"\n\t\t\t Please Login  \n\n";
        cout<<"\t\t\t Enter Email : ";
        cin >> email;
        cout << "\t\t\t Password : ";
        cin>>password;

        if(email == "w" && password == "e"){
            administrator();
        }
        else{
            cout<<"\n\t\t\t Invalid Email/Password\n\n\n";
        }
        break;
    
    case 2:
        {
            buyer();
        }
    case 3:
        {
            exit(0);
        }

        default:
        {
            cout << "\t\tPlease select again from the given options";
        }

}
goto m;
}
void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\t\t\t     Administrator  Menu \n";
    cout<<"\t\t\t     ------------------- \n";
    //cout<<"\t\t\t____________________________";
    cout<<"\n\t\t\t|____1) Add the product____|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___2) Modify the product__|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___3) Delete the product__|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___4) Back to main menu___|";

    cout<<"\n\n\t\t Please enter your choice : ";
    cin >> choice;

    switch(choice){
        case 1:
        {
            add();
            break;
        }
        case 2: 
        {
            edit();
            break;
        }
        case 3:
        {
            rem();
            break;
        }
        case 4:
        {
            menu();
            break;
        }
        default :
        {
            cout << "\n\t\tInvalid choice!!\n";
        }
    }
    goto m; 
}

void shopping :: buyer(){
    m:
    int choice;
    cout<<"\n\n\t\t\t         Buyer      \n";
    cout<<"\t\t\t  ------------------\n";
    cout<<"\t\t\t                  \n";
    cout<<"\t\t\t  1) Buy product  \n";
    cout<<"\t\t\t                  \n";
    cout<<"\t\t\t  2) Go back      \n";
    cout<<"\t\t\t                  \n";
    cout<<"\t\t  Enter your choice : ";
    cin>>choice;

    switch(choice){
        case 1:
        receipt();
        break;

        case 2:
            menu();

        default :
        cout << "\t\t\t Invalid choice";
    }
    goto m; 
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\t\t Enter details of the new product : ";
    cout<<"\n\n\t\t Product code : ";
    cin>>pcode;
    cout<<"\n\t\t Name : ";
    cin>>pname;
    cout<<"\n\t\t Price : ";
    cin>>price;
    cout<<"\n\t\t Discount : ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    
    if(token==1){
        goto m;
    }
    
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
        }
    }
    cout << "\n\t\t Record inserted !";

}
void shopping :: edit(){
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t Enter the details to modify the record\n";
    cout<<"\n\t\t Product code : ";
    cin >> pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n\t\tFile does not exist ";
    }
    else{
        data1.open("database1.txt", ios :: app|ios :: out);
        data >> pcode >>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t New product code : ";
                cin>>c;
                cout<<"\n\t\t New Name : ";
                cin>>n;
                cout<<"\n\t\t New Price : ";
                cin>>p;
                cout<<"\n\t\t New Discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\t\t Record not found, sorry !!\n";
        }
    }
}
void shopping :: rem(){
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\t\t Enter details of the product to be deleted";
    cout<<"\n\n\t\t Product code : ";
    cin >> pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<< "\t\tFile does not exist";
    }

    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t\t Product deleted succesfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\n\t\t Record not found !!\n";
        }
    }
}
void shopping :: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout << "\n\t\t\t|____________________________________|\n";
    cout<<"\t\t\t ProNo\t\tName\t\tPrice\n";
    cout << "\t\t\t|____________________________________|\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<"\t\t\t  "<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping::receipt() {
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t        RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty database";
    } else {
        data.close();
        list();
        cout << "\t\t\t____________________________________";
        cout << "\n\t\t\t|                                   |";
        cout << "\n\t\t\t|       Please place the order      |";
        cout << "\n\t\t\t|___________________________________|\n";
        do {
            m:
            cout << "\n\n\t\t\t Enter product code : ";
            cin >> arrc[c];
            cout << "\n\n\t\t\t Enter product quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n\t\t\t Duplicate Product code. Please try again !";
                    goto m;
                }
            }
            c++;
            cout << "\n\n\t\t\t Do yo want to buy another product? if yes the enter y else n : ";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t__________________________________________RECEIPT____________________________________________\n";
        cout << "\n\t\t\tProduct NO\tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount with discount\n";

        data.open("database.txt", ios::in);
        while (data >> pcode >> pname >> price >> dis) {
            for (int i = 0; i < c; i++) {
                if (pcode == arrc[i]) {
                    float amount = price * arrq[i];
                    float discountedAmount = amount - (amount * dis / 100);
                    total += discountedAmount;
                    cout << "\n\t\t\t" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t\t" << price << "\t" << amount << "\t" << discountedAmount;
                }
            }
        }
        data.close();
    }
    cout << "\n\n\t\t\t_____________________________________________________________________________________________";
    cout << "\n\t\t\t Total Amount : " << total;
}
int main(){
    shopping s;
    s.menu();
}