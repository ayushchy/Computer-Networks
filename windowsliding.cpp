#include<iostream>
#include <bits/stdc++.h>

using namespace std;
void timeout()
{
    int r = rand()%50;
    _sleep(100*r);
}
// void sendFrame (char frame)
// {

// }
void simplest()
{
    //Sender Side
    char frame,data;
    cout<<"Enter the Char You want to send"<<endl;
    cin>>frame;// GetData() and makeFrame()
    data=frame;//SendFrame()
    //Wait 
    int r = rand()%50;
    _sleep(100*r);
    //Receiver Side
    frame=data; // getDatafromSender and makeFrame()
    cout<<"-----------------------------------------"<<endl;

    cout<<"Frame received"<<endl;
    cout<<frame<<endl;
    cout<<"-----------------------------------------"<<endl;



}
void stopwaitarq()
{
    cout<<"Stop And wait ARQ"<<endl;
    int choice;bool canSend = true;
    int ack = 0;char ipchar,data;
    bool frameLoss,ackLoss = false;
    do
    {
        cout<<"1. Send Data"<<endl;
        cout<<"2. Receive Data"<<endl;
        cout<<"3. Simulate Frame Loss"<<endl;
        cout<<"0. Enter 0 to go back to main menu"<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            cout<<endl;
                if(ack == 1){
                    canSend = true;
                }
                if (frameLoss == true && canSend==true)
                {
                    timeout();
                    cout<<"Sending message again(Frame Lost)"<<endl;
                    data = ipchar;                  //Send Frame
                    canSend = false;
                    cout<<"Data Sent"<<endl;
                    frameLoss = false;
                    break;
                }
                if (ackLoss == true && canSend==true)
                {
                    timeout();
                    cout<<"Sending message again(Ack Lost)"<<endl;
                    data = ipchar;                  //Send Frame
                    canSend = false;
                    cout<<"Data Sent"<<endl;
                    ackLoss = false;
                    break;
                }
                
                
                
                if (canSend==true)
                {
                    // timeout();
                    cout<<"Enter any char you want to send"<<endl;
                    cin>>ipchar;                    //Make Frame
                    data = ipchar;                  //Send Frame
                    canSend = false;
                    cout<<"Data Sent"<<endl;
                }
                else
                {
                    cout<<"Cannot Send message"<<endl;
                }
                
                
            break;
            case 2:
                timeout();
                cout<<endl;

                
                cout<<"-----------------------------------------"<<endl;
                cout<<"Frame received"<<endl;
                ipchar = data;//Receive Frame
                cout<<"Data : "<<ipchar<<endl;
                cout<<"-----------------------------------------"<<endl;

                ack=1;

            break;
            case 3:
            timeout();
            cout<<endl;

            cout<<"-----------------------------------------"<<endl;
            cout<<"Frame Lost"<<endl;
            cout<<"-----------------------------------------"<<endl;
            
            frameLoss = true;
            canSend = true;
            break;
            case 4:
            timeout();
            cout<<endl;

            cout<<"-----------------------------------------"<<endl;
            cout<<"Acknowledgement Lost"<<endl;
            cout<<"-----------------------------------------"<<endl;
            
            ackLoss = true;
            canSend = true;
            break;
            
        }
        
    } while (choice!=0);
}
void stopandwait()
{
    cout<<"Stop And wait"<<endl;
    int choice;bool canSend = true;
    int ack = 0;char ipchar,data;
    do
    {
        cout<<"1. Send Data"<<endl;
        cout<<"2. Receive Data"<<endl;
        cout<<"3. Simulate Frame Loss"<<endl;
        cout<<"0. Enter 0 to go back to main menu"<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                if(ack == 1){
                    canSend = true;
                }
                if (canSend==true)
                {
                    cout<<"Enter any char you want to send"<<endl;
                    cin>>ipchar;                    //Make Frame
                    data = ipchar;                  //Send Frame
                    canSend = false;
                }
                else
                {
                    cout<<"Cannot Send message"<<endl;
                }
                
                
            break;
            case 2:
                int r = rand()%50;
                _sleep(100*r);
                cout<<"-----------------------------------------"<<endl;
                cout<<"Frame received"<<endl;
                ipchar = data;//Receive Frame
                cout<<"Data : "<<ipchar<<endl;
                cout<<"-----------------------------------------"<<endl;

                ack=1;

            break;
            
        }
        
    } while (choice!=0);
    
}
void goback()
{
    cout<<"GO Back -N ARQ"<<endl;
    int noOfFrames,windowSize;
    int noOfTransm= 0;
    cout<<"Enter the number of Frames you want"<<endl;cin>>noOfFrames;
    cout<<"Enter the window size"<<endl;cin>>windowSize;
    if (windowSize>noOfFrames)
    {
        cout<<"Windows size exceeds the number of frames"<<endl;
    }
    int i = 1;
    while (i<=noOfFrames)
    {
        int ackCount = 0;
        for (int j = i; j < i+windowSize && j<=noOfFrames; j++)
        {
            cout<<"Frame No: "<<j<<" is sent"<<endl;
            noOfTransm++;
        }
        for (int j = i; j < i+windowSize && j<=noOfFrames; j++)
        {
            bool frameChoice;
            cout<<"Do you want to simulate frame loss.Enter 0(False) 1(True)"<<endl;cin>>frameChoice;
            if (frameChoice == 1)
            {
                cout<<"Frame Transmission Failed"<<endl;
                cout<<"Sending frame again"<<endl;break;
            }
            else
            {
                cout<<"Frame "<<j<<" received Successfully"<<endl;
                ackCount++;

            }
            
            
        }
        i=i+ackCount;
    }
    
    
    

}
void selective()
{
    cout<<"Selective Repeat ARQ"<<endl;
    int noOfFrames,windowSize;
    int noOfTransm= 0;
    cout<<"Enter the number of Frames you want"<<endl;cin>>noOfFrames;
    cout<<"Enter the window size"<<endl;cin>>windowSize;
    if (windowSize>noOfFrames)
    {
        cout<<"Windows size exceeds the number of frames"<<endl;
    }
    int i = 1;
    while (i<=noOfFrames)
    {
        int ackCount = 0;
        for (int j = i; j < i+windowSize && j<=noOfFrames; j++)
        {
            cout<<"Frame No: "<<j<<" is sent"<<endl;
            noOfTransm++;
        }
        for (int j = i; j < i+windowSize && j<=noOfFrames; j++)
        {
            bool frameChoice;
            cout<<"Do you want to simulate frame loss.Enter 0(False) 1(True)"<<endl;cin>>frameChoice;
            if (frameChoice == 1)
            {
                cout<<"Frame Transmission Failed"<<endl;
                cout<<"Sending frame again"<<endl;
                //Sending frame again 
                cout<<"Frame No: "<<j<<" is sent"<<endl;
                // noOfTransm++;
                ackCount++;


            }
            else
            {
                cout<<"Frame "<<j<<" received Successfully"<<endl;
                ackCount++;

            }
            
            
        }
        i=i+ackCount;
    }
}
int main()
{
    int option;
    cout<<"Noisy Channel Implementation"<<endl;
    do
    {
        cout<<"Please Choose any option "<<endl;    
        cout<<"1. Simplest protocol"<<endl;
        cout<<"2. Stop and Wait protocol"<<endl;
        cout<<"3. Stop and Wait ARQ protocol"<<endl;
        cout<<"4. Go Back-N ARQ Protocol"<<endl;
        cout<<"5. Selective repeat ARQ Protocol"<<endl;
        cout<<"0. Enter 0 Exit"<<endl;

        // cout<<"3.Enter Data"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            simplest();
            break;
        case 2:
            stopandwait();
            break;   
        case 3:
            stopwaitarq();
            break;
        case 4:
            goback();
            break;
        case 5:
            selective();
            break;
        
        default:
            break;
        }
    } while (option!=0);
    
}
