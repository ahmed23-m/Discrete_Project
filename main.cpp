#include "iostream"
#include "cmath"
#include "string"
using namespace std;

bool is_tautology();
bool is_contradiction();
bool is_contengency();
bool is_equivilant();
int opnum;
bool a,b,c;
bool ar[4];
bool taut=false;
bool cont=false;
void Check()
{

    cout<<"\nWhat Do You Want To Check ?"<<endl;
    cout<<"[1]tautology\t[2]contradiction\n[3]contengency\t[4]equlivant"<<endl;
    operation:
    cout<<"Your Choice is:";
    cin>>opnum;
    switch (opnum)
    {
        case 1:
            is_tautology();
            break;
        case 2:
            is_contradiction();
            break;
        case 3:
            is_contengency();
            break;
        case 4:
            is_equivilant();
            break;
        default:
            cout<<"Please Enter A Valid Number!"<<endl;
            goto operation;
    }
}
void CheckFor()
{
    string str;
    cout<<"You Want To Check For:"<<endl;
    cout<<"[A - B - A.B - A+B - !A - !B - A->B - A<->B]"<<endl;
    Choice:
    cin>>str;
    if (str=="A") {
        for (int i = 0; i <= 3; i++) {
            a = (i / 2 == 0) ? false : true;
            b = (i % 2 == 0) ? false : true;
            ::ar[i] = a;
        }
    }else if(str=="B") {
        for (int i = 0; i <= 3; i++) {
            a = (i / 2 == 0) ? false : true;
            b = (i % 2 == 0) ? false : true;
            ::ar[i] = b;
        }
    }else if (str=="A.B") {
        for (int i = 0; i <= 3; i++) {
            a = (i / 2 == 0) ? false : true;
            b = (i % 2 == 0) ? false : true;
            ::ar[i] = (a && b);
        }
    }else if (str=="A+B") {
        for (int i = 0; i <= 3; i++) {
            a = (i / 2 == 0) ? false : true;
            b = (i % 2 == 0) ? false : true;
            ::ar[i] = (a || b);
        }
    }else if (str=="!A") {
        for (int i = 0; i <= 3; i++) {
            a = (i / 2 == 0) ? false : true;
            b = (i % 2 == 0) ? false : true;
            ::ar[i] = !a;
        }
    }else if (str=="!B") {
        for (int i = 0; i <= 3; i++) {
            a = (i / 2 == 0) ? false : true;
            b = (i % 2 == 0) ? false : true;
            ::ar[i] = !b;
        }
    }else if (str=="A->B") {
        for (int i = 0; i <= 3; i++) {
            a = (i / 2 == 0) ? false : true;
            b = (i % 2 == 0) ? false : true;
            ::ar[i] = (!a || b);
        }
    }else if (str=="A<->B")
    {
        for(int i = 0; i <= 3; i++)
        {
            a = (i / 2==0)? false: true;
            b = (i % 2==0)?false: true;
            ::ar[i]= ((!a||b)&&(!b||a));
        }
    }else
    {
        cout<<"Please Enter A Valid Choice!"<<endl;
        goto Choice;
    }
}
int main()
{
        int vnum=0;
        cout<<"Enter Number of Truth Table Variables (2/3) :";
        cin>>vnum;
        int lnum= pow(2,vnum);
        switch (vnum)
        {
            case 2:
                {
                    cout<<("\t\tTruth Table\n\n");
                    cout<<("A\tB\tA.B\tA+B\t!A\t!B\tA->B\tA<->B\n");
                    bool ar[4];
                    for(int i = 0; i <= 3; i++)
                    {
                        a = (i / 2==0)? false: true;
                        b = (i % 2==0)?false: true;
                        cout<<a<<"\t"<<b<<"\t"<<(a&&b)<<"\t"<<(a||b)<<"\t"<<(!a)<<"\t"<<(!b)<<"\t"<<(!a||b)<<"\t"<<((!a||b)&&(!b||a))<<endl;
                    }
                    Check();
                    break;
                }
            case 3:
                {
                    cout << ("\t\t\t\t\t\t[Truth Table]\n\n");
                    cout << ("A\tB\tC\tA.B\tA.C\tB.C\tA+B\tA+C\tB+C\t!A\t!B\t!C\tA->B\tA->C\tA<->B\n");
                    for (int i = 0; i < lnum; i++) {
                        a = (i / 4 == 0) ? false : true;
                        b = (i / 2 == 0) || (i / 2 == 2) ? false : true;
                        c = (i % 2 == 0) ? false : true;
                        cout << a << "\t" << b << "\t" << c << "\t" << (a && b) << "\t" << (a&&c) <<"\t"<<(b&&c)<<"\t"<< (a || b) <<"\t"<<(a||c)<<"\t"<<(b||c)
                             << "\t" << !a << "\t" << !b
                             << "\t" << !c << "\t" << (!a || b) << "\t" << (!a || c) <<"\t"<< ((!a || b) && (!b || a)) << endl;
                        //::ar[i]= ;

                    }
                    //Check();
                    break;
                }
            default:
                cout<<"Please Enter A Valid Number !"<<endl;
        }
    return 0;
}
bool is_tautology()
{
    CheckFor();
    for(int i = 0; i <= 3; i++)
    {
        if(ar[i])
        {
            taut=true;

        }
        else
        {
            taut=false;
            cout<<"not tautology"<<endl;
            break;
        }

    }
    if(taut)
        cout<<"tautology"<<endl;
    return false;
};
bool is_contradiction()
{
    CheckFor();
    for(int i = 0; i <= 3; i++)
    {
        if(!ar[i])
        {
            cont=true;

        }
        else
        {
            cont=false;
            cout<<"not contradiction"<<endl;;
            break;
        }

    }
    if(cont)
        cout<<"contradiction"<<endl;
    return false;
};
bool is_contengency()
{
    CheckFor();
    if(!taut&&!cont)
    {
        cout<<"contengency"<<endl;
    }else
    {
        cout<<"not contengency"<<endl;
    }

    return false;
};
bool is_equivilant()
{
    string str1,str2;
    cout<<"Enter First obj To Compare :"<<endl;
    cin>>str1;
    cout<<"Enter Second obj To Compare :"<<endl;
    cin>>str2;
    if(str1==str2)
    {
        cout<<"Equivilant"<<endl;
    }else
    {
        cout<<"not equivilant"<<endl;
    }

    return false;
};