#include <iostream> //basic input output file
#include <fstream>  // handle  files
// #include <iomanip>  //used to manipulate output or showing floating point values
#include <windows.h>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;
    // p-->product
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

void shopping::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t _____________________________________ \n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|_________Supermarket mainmenu________|\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|                                     |\n";
    cout << "\t\t\t\t|_____________________________________|\n";
    cout << "\t\t\t\t                                       \n";
    cout << "\t\t\t\t ________________________ \n";
    cout << "\t\t\t\t|                        |\n";
    cout << "\t\t\t\t|  1. Administrator      |\n";
    cout << "\t\t\t\t|                        |\n";
    cout << "\t\t\t\t|  2. Buyer              |\n";
    cout << "\t\t\t\t|                        |\n";
    cout << "\t\t\t\t|  3. Exit               |\n";
    cout << "\t\t\t\t|________________________|\n";

    cout << "\n\t\t\t Please select!";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email:  ";
        cin >> email;
        cout<<"\n" ;
        cout << "\t\t\t Password:    ";
        cin >> password;

        if (email == "itsrm301@gmail.com" && password == "RR@123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email/ password !!\n\n";
        }
        break;
    }
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
        break;
    }
    default:
    {
        cout << "please select from the given option!\n\n";
    }
    }
    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu";
    cout << "\n\t\t\t ____________________________ ";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|     1. Add the product     |";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|     2. Modify the product  |";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|     3. Delete the product  |";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|     4. Back to main menu   |";
    cout << "\n\t\t\t|____________________________|";

    cout << "\n\n\t Please Enter your choice: \n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid choice!!";
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t           Buyer          \n";
    cout << "\t\t\t _________________________\n";
    cout << "\t\t\t|                         |\n";
    cout << "\t\t\t|                         |\n";
    cout << "\t\t\t|      1. Buy Product     |\n";
    cout << "\t\t\t|                         |\n";
    cout << "\t\t\t|      2. Go back         |\n";
    cout << "\t\t\t|                         |\n";
    cout << "\t\t\t|_________________________|\n";
    cout << "\n\t\t\t Enter your choice : \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        cout << "Invalid choice !!\n";
    }
    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t product code of product: ";
    cin >> pcode;
    cout << "\n\n\t Name of the product: ";
    cin >> pname;
    cout << "\n\n\t Price of the product: ";
    cin >> price;
    cout << "\n\n\t Discount on the product: ";
    cin >> discount;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        // eof --> end of file function
        //  while loop make sure to check every file in data.
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
                break;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1)
    {
        cout << "\n\n Product with this ID already exists.Please use another id to add the product\n";
        goto m;
    }
    else
    {

        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    cout << "\n\n\t\t Product Added succesfully !\n";
}

void shopping::edit()
{
    fstream data1, data2;
    int pkey;
    int token = 0;
    int c;
    float p, d;
    string n;
    cout << "\n\t\t\t Modify the product\n";
    cout << "\n\t\t\t Product code: ";
    cin >> pkey;
    data1.open("database.txt", ios::in);
    if (!data1)
    {
        cout << "\n\n Please first add product to modify them\n";
    }
    else
    {
        data2.open("database2.txt", ios::app | ios::out);
        data1 >> pcode >> pname >> price >> discount;
        while (!data1.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new Code :";
                cin >> c;
                cout << "\n\t\t Product new Name :";
                cin >> n;
                cout << "\n\t\t Product new price :";
                cin >> p;
                cout << "\n\t\t Product new discount :";
                cin >> d;
                data2 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Product modified succesfully !!\n";
                token++;
            }
            else
            {
                data2<< pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data1 >> pcode >> pname >> price >> discount;
        }
        data1.close();
        data2.close();
        remove("database.txt");
        rename("database2.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n Product with provided ID is not found !!\n";
        }
    }
}
void shopping::rem()
{
    fstream data1, data2;
    int pkey;
    int token;
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Enter Product code :";
    data1.open("database.txt", ios::in);
    if (!data1)
    {
        cout << "\n\n Please first add produt to delete them\n";
    }
    else
    {
        data2.open("database2.txt", ios::app | ios::out);
        data1 >> pcode >> pname >> price >> discount;
        while (!data1.eof())
        {
            if (pcode == pkey)
            {
                // cout<<"\n\n The product for Product ID "<<pkey<<" is:\n";
                // cout<<"\n code: "<<pcode;
                // cout<<"\n name: "<<pname;
                // cout<<"\n price: "<<price;
                // cout<<"\n discount: "<<discount;
                // k:
                // cout<<"\n\n Are you sure you want to delete above product:(Y/N)";
                // char deleteconfirmtaion;
                // cin>>deleteconfirmtaion;
                // tolower(deleteconfirmtaion);
                // switch(deleteconfirmtaion){
                //     case 'y':
                //         cout<<"Product deleted successfully!!";
                //         token++;
                //         break;
                //     case 'n':
                //     default:
                //         cout<<"Enter right choice:";
                //         goto k;
                // }
                cout << "Product deleted successfully \n";
            }
            else
            {
                data2 << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data1 >> pcode >> pname >> price >> discount;
        }
        data2.close();
        remove("database.txt");
        rename("database2.txt","database.txt");
        if(token==0){
            cout<<"\n\n Product with provided ID is not found\n";
        }
    }
}

void shopping:: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n ____________________________________\n";
    cout<<"|ProNo.\t\tName\t\tPrice\t\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof()){
        // string k;
        // k = to_string(price);
        // int t = 8-k.length();
        cout<<"|"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        // while(t--)cout<<" ";
        // cout<<"|/n";
        data >> pcode >> pname >> price >> discount;
    }
    data.close();
}

void shopping:: receipt(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float di = 0;
    float total =0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        "\n\n Empty DataBase";
    }else{
        data.close();
        list();
        cout<<"\n ________________________________________";
        cout<<"\n|                                        |";
        cout<<"\n|                                        |";
        cout<<"\n|           Please Place Order           |";
        cout<<"\n|                                        |";
        cout<<"\n|________________________________________|";

        do
        {
            m:
            cout<<"\n\nEnter the product code :";
            cin>>arrc[c];
            cout<<"\nEnter the product quantity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[i]==arrc[c]){
                    cout<<"Product with this code is added already,Please try again\n";
                    goto m;
                }
            }
            c++;
            cout<<"\n\nDo you want to another product?(Y/N)";
            cin>>choice;
            tolower(choice);
        }
            while(choice=='y');

            cout<<"\n\n\t\t\t_____________________RECEIPT_______________________\n";
            cout<<"\n Product No.\t Product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";
            for(int i=0;i<c;i++)
            {
                data.open("database.txt",ios::in);
                data>>pcode>>pname>>price>>discount;
                while(!data.eof())
                {
                    if(pcode==arrc[i]){
                        amount = price * arrq[i];
                        di = amount - (amount*discount)/100 ;
                        total = total + di;
                        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<di<<"\n";
                    }
                    data>>pcode>>pname>>price>>discount;
                }
                data.close();
            }
        cout<<"\n ________________________________________";
        cout<<"\n|                                        |";
        cout<<"\n|                                        |";
        cout<<"\n|           Total Amount "<<total<<"      ";
        cout<<"\n|                                        |";
        cout<<"\n|________________________________________|";
        
        }
    
}

int main()
{

    cout << "Jai Gau MAA::::\n";
    shopping s;
    s.menu();
}