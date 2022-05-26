#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class message
{
private:
    string cell_no_sender, cell_no_reciever;
    string msg;
    
public:
    // void set_sender_ID(int id)
    // {
    //     this->ID_sender = id;
    // }
    // int get_sender_ID()
    // {
    //     return this->ID_sender;
    // }
    void set_sender_cellno(string cellno)
    {   
        int count = 0;
        for (int i = 0; i < cellno.length(); i++)
        {
            count++;
        }
        
        if(count != 11)
        {
            cout<<"Invalid Number!"<<endl;
            cout<<"PLease enter again"<<endl;
            cin>>cellno;
            set_sender_cellno(cellno);
        }
        else
        {
            this->cell_no_sender = cellno;
        }
    }
    string get_sender_cellno()
    {
        return this->cell_no_sender;
    }

    // void set_reciever_ID(int id)
    // {
    //     this->ID_reciever = id;
    // }
    // int get_reciever_ID()
    // {
    //     return this->ID_reciever;
    // }
    void set_reciever_cellno(string cellno)
    {   
        int count = 0;
        for (int i = 0; i < cellno.length(); i++)
        {
            count++;
        }
        
        if(count != 11)
        {
            cout<<"Invalid Number!"<<endl;
            cout<<"PLease enter again"<<endl;
            cin>>cellno;
            set_reciever_cellno(cellno);
        }
        else
        {
            this->cell_no_reciever = cellno;
        }
    }
    string get_reciever_cellno()
    {
        return this->cell_no_reciever;
    }
    void set_msg(string msg)
    {
        this->msg = msg;
    }
    string get_msg()
    {
        return this->msg;
    }
    

    void senders_data()
    {
        string cellno;
        cout<<"Enter sender's mobile number : "<<endl;
        fflush(stdin);
        cin>>cellno;
        set_sender_cellno(cellno);
    }
    void msg_data()
    {
        string mesag;
        cout<<"Type your message : "<<endl;
        fflush(stdin);
        getline(cin, mesag);
        set_msg(mesag);
    }
    void recievers_data()
    {
        string cellno, mesag;
        cout<<"Enter reciever's mobile number : "<<endl;
        fflush(stdin);
        cin>>cellno;
        set_reciever_cellno(cellno);
    }

    void msg_write_sender(message ob)
    {
        string newline;
        newline = 10;
        char const *msgarr = msg.data();
        
        ofstream ptr1;
        ptr1.open(cell_no_sender.c_str(), ios::app);
        if(!ptr1)
        {
            cout<<"File creation failed"<<endl;
        }
       // ptr1<<ID_sender;
        ptr1<<cell_no_reciever;
        ptr1.seekp(2, ios::cur);
        ptr1.write("*", 1);
        //ptr1.seekp(2, ios::cur);
        ptr1.write(msgarr, msg.length());
        ptr1<<newline;
        ptr1.close();
        msg_write_reciever();
    }

    void msg_write_reciever()
    {
        string newline;
        newline = 10;
        char const *msgarr = msg.data();
        ofstream ptr2;
        ptr2.open(cell_no_reciever.c_str(), ios::app);
        //ptr2.open(cell_no_reciever.c_str(), ios::app);
        if(!ptr2)
        {
            cout<<"File creation failed"<<endl;
        }
        ptr2<<cell_no_sender;
        ptr2.seekp(2, ios::cur);
        ptr2.write("#", 1);
        //ptr2.seekp(2, ios::cur);
        ptr2.write(msgarr, msg.length());
        ptr2<<newline;
        ptr2.close();
    }

    void msg_read_reciever()
    {
        string data;
        ifstream ptr3;
        ptr3.open(cell_no_reciever.c_str() , ios::in);
        //Ye loop data print kra ga read kr k or sender k no sa match kr k
        while (getline(ptr3, data))
        {

            string messag = data;
            string chk_sender = messag.substr(0,11);
            if (cell_no_sender == chk_sender)
            {
                cout<<data.erase(0,12)<<endl;
            }
            
        }
        ptr3.close();
    }
    message()
    {
    }
    ~message()
    {}
};


    

int main()
{
    message ob1;
    ob1.senders_data();
    ob1.recievers_data();
    ob1.msg_data();
    ob1.msg_write_sender(ob1);
    ob1.msg_read_reciever();

    return 0;
}