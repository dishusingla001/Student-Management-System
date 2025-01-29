#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student{
    public:
    int roll;
    char name[20],classes[20];

    student() {}

    student(int roll,char name[],char classes[])
    {
        this->roll=roll;
        strcpy(this->name,name);
        strcpy(this->classes,classes);
    }

    void display()
    {
        cout<<"My Name is "<<name<<endl;
        cout<<"My Roll Number is "<<roll<<endl;
        cout<<"My class is "<<classes<<endl;
    }

    student input(student s,int n)
    {
        if(n==1)
        {
            cout<<"Enter Roll Number:";
            cin>>s.roll;
        
            return s;
        }
            cout<<"Enter Name:";
            cin>>s.name;
            cout<<"Enter Class:";
            cin>>s.classes;
            return s;
    }
};

void write()
{
    int roll;
    char name[20],classes[20];
    string o;

    ofstream fout("switch.dat");
        do{
            cout<<"Enter Name:";
            cin>>name;
            cout<<"Enter Roll Number:";
            cin>>roll;
            cout<<"Enter Class:";
            cin>>classes;

            student s1(roll,name,classes);

            fout.write((char*)&s1,sizeof(s1));
            
            cout<<"Enter Option yes or no:";
            cin>>o;
        }
        while(o=="yes");
    fout.close();
}

void read()
{
    ifstream fin("switch.dat");
    student s1;
    while(fin.read((char*)&s1,sizeof(s1)))
    {
        s1.display();
    }
    fin.close();
}

void copy()
{
    student s1;
    ifstream fin("switch.dat");
    ofstream fout("copy.dat");
    while(fin.read((char*)&s1,sizeof(s1)))
    {
        fout.write((char*)&s1,sizeof(s1));
        s1.display();
    }
    remove("switch.dat");
    rename("copy.dat","switch.dat");
}

int search(int roll)
{
    int c=0;

    student s1;
    ifstream fin("switch.dat");
    while(fin.read((char*)&s1,sizeof(s1)))
    {
        if(roll==s1.roll)
        {
            c=1;
            return 1; 
        }
    }
    if(c==0)
    {
        return 0;
    }
    fin.close();
}

void insert()
{
    student s;
    s=s.input(s,1);
    int ins;

    ins=search(s.roll);
    if(ins==1)
    {
        cout<<"This Roll Number is Exist Already";
        return;
    }
    else
    {
        student s1;
        ifstream fin("switch.dat");
        ofstream fout("copy.dat");
        while(fin.read((char*)&s1,sizeof(s1)))
        {
            fout.write((char*)&s1,sizeof(s1));
        }
        s=s.input(s,0);
        fout.write((char*)&s,sizeof(s));
        fout.close(); 
        fin.close();

        remove("switch.dat");
        rename("copy.dat","switch.dat");   
    }
}

void del()
{
    student s;
    int sea;
    s=s.input(s,1);

    sea=search(s.roll);
    
    if(sea!=1)
    {
        cout<<"This Roll did not exist";
    }
    else
    {
        student s1;
        ifstream fin("switch.dat");
        ofstream fout("copy.dat");
        while(fin.read((char*)&s1,sizeof(s1)))
        {
            if(s.roll!=s1.roll)
            {
                fout.write((char*)&s1,sizeof(s1));
            }
        }
        fout.close();
        fin.close();

        remove("switch.dat");
        rename("copy.dat","switch.dat");
    }
}

void update()
{
    student s;
    int sea;
    s=s.input(s,1);

    sea=search(s.roll);
    
    if(sea!=1)
    {
        cout<<"This Roll did not exist";
    }
    else
    {
        student s1;
        ifstream fin("switch.dat");
        ofstream fout("copy.dat");
        while(fin.read((char*)&s1,sizeof(s1)))
        {
            if(s.roll==s1.roll)
            {
                s=s.input(s,0);
                fout.write((char*)&s,sizeof(s));
            }
            else
            {
                fout.write((char*)&s1,sizeof(s1));
            }
        }
        fout.close();
        fin.close();
        remove("switch.dat");
        rename("copy.dat","switch.dat");
    }

}
main()
{
    char name[20],classes[20];
    int roll,r;
    char option;
    string o;

    int a;
    do{
        cout<<"\nEnter Option:";
        cin>>option;

        switch (option)
        {
        
            case 'w':
                write();
                break;
            
            case 'r':
                read();
                break;
            
            case 'c':
                copy();
                break;
            
            case 's':
            {
                cout<<"Enter Roll Number:";
                cin>>r;
                a=search(r);
                if(a==1)
                {
                    cout<<"Yes,this roll number is exist in the list";
                }
                else{
                    cout<<"No,this roll number is not exist in the list";
                }
                break;
            }
        
            case 'i':
                insert();
                break;
        
            case 'd':
                del();
                break;
        
            case 'u':
                update();
                break;
        
            default:
                break;
            }

            cout<<"\nYou Want More Option(yes or no):";
            cin>>o;
        }
        while(o=="yes");
}