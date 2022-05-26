#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class notes
{
private:
    string name;
    string msg;
    
public:
    void setname(string n)
    {   
        
            this->name = n;
        
    }
    string getname()
    {
        return this->name;
    }

    void set_msg(string msg)
    {
        this->msg = msg;
    }
    string get_msg()
    {
        return this->msg;
    }
    

    void inputfilename()
    {
        string n;
        cout<<"Enter file name : "<<endl;
        fflush(stdin);
        cin>>n;
        setname(n);
    }
    void msg_data()
    {
        string mesag;
        cout<<"Type your message : "<<endl;
        fflush(stdin);
        getline(cin, mesag);
        set_msg(mesag);
    }

    void msg_write()
    {
        string newline;
        newline = 10;
        char const *msgarr = msg.data();
        
        ofstream ptr1;
        ptr1.open(name.c_str(), ios::app);
        if(!ptr1)
        {
            cout<<"File creation failed"<<endl;
        }
        ptr1.write(msgarr, msg.length());
        ptr1<<newline;
        ptr1.close();
    }

    void msg_read()
    {
        string data;
        ifstream ptr3;
        ptr3.open(name.c_str() , ios::in);
        int l = name.length();
        //Ye loop data print kra ga read kr k or sender k no sa match kr k
        while (getline(ptr3, data))
        {

            string messag = data;
            cout<<data.erase(0,l+1)<<endl;            
        }
        ptr3.close();
    }
    notes()
    {
    }
    ~notes()
    {}
};


    

int main()
{
    notes ob1;
    ob1.inputfilename();
    ob1.msg_data();
    ob1.msg_write();
    ob1.msg_read();
    return 0;
}



// #include<iostream>
// #include<fstream>
// #include<string>
// using namespace std;
// class Notes 
// {

// private:
// 	string title;

// public
// 	void set_title(string title)
// 	{
// 		this-title = title;
// 	}
// 	string get_title()
// 	{
// 		return this-title;
// 	}
// 	void createfile()
// 	{
// 		char newline;
// 		newline = 10;
// 		string name;
// 		cout  Enter the name of the file    endl;
// 		getline(cin, name);
// 		set_title(name);
// 		string name = Untitled_ + to_string(i) + .txt;
// 		ofstream f1;
// 		f1.open(title.c_str(), iosout);
// 		if (!f1)
// 		{
// 			cout  File creation failed;
// 		}
// 		else
// 		{
// 			string notes = new string;
// 			getline(cin, notes);
// 			f1  title;
// 			f1  newline;
// 			f1  notes;
// 			f1.close();
// 		}
// 	}

// 	void readfile()
// 	{
// 		 Reading from file
// 		ifstream f2;

// 		f2.open(title.c_str(), iosin);
// 		string data;
// 		while (getline(f2, data))
// 		{
// 			cout  data;
// 			if (f2.eof())
// 			{
// 				break;
// 			}
// 		}
// 		f2.close();
// 	}
// 	Constructor
// 	Notes()
// 	{
// 	}
// 	Destructor
// 	~Notes()
// 	{}
// };
