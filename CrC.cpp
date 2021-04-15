#include <iostream>
#include <math.h>
using namespace std;
 
int main()
{
    //data bits
    int dc;
    cout<<"\nEnter number of bits in data to be sent:";
    cin>>dc;
     
    int data[20];
    int i;
    cout<<"\nEnter data:";
    for(i=0;i<dc;i++)
    {
        cin>>data[i];
    }
 
    //generator bits
    int gc;
    cout<<"\nEnter Generator bit size: ";
    cin>>gc;
     
    int g[20];
     
    cout<<"\n Enter Generator bits:";
    for(i=0;i<gc;i++)
    {
        cin>>g[i];
    }
 
   
 
    //add 0
    int rc=gc-1;
    cout<<"\nNumber of 0's to be added: "<<rc;
    for (i=dc;i<dc+rc;i++)
    {
        data[i]=0;
    }
 
    int temp[20];
    for(i=0;i<20;i++)
    {
        temp[i]=data[i];
    }
 
    cout<<"\nData after adding 0's :";
    for(i=0; i<dc+rc;i++)
    {
        cout<<temp[i];
    }
 	
    //Division
    int j,k;
    for(i=0;i<dc;i++)
    {
        j=0;
        k=i;
        //check divisibility
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gc;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    //crc bits
    int crc[15];
    for(i=0,j=dc;i<rc;i++,j++)
    {
        crc[i]=temp[j];
    }
 
    cout<<"\nCRC bits: ";
    for(i=0;i<rc;i++)
    {
        cout<<crc[i];
    }
 
    
    return 0;
}
