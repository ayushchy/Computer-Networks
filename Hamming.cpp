#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    int m;
    int r=0;
    int str[20];
     //get value of m
    cout<<"Enter value of m: ";
    cin>>m;
     
    int i,j,k;
     //take input for data bits by sender
    cout<<"Enter input string :";
    for (i=0;i<m;i++)
    {
        cin>>str[i];
    }
 	
 	//finding no. of redundant bits
    while(pow (2,r) < m + r + 1){
        r++;
    }
    
     
    
    cout<<"\n Input Data by sender :\n ";
    for(i=0;i<m;i++)
    {
        cout<<str[i]<<" ";
    }
 
    
    int tmp[20];
    for (i=m-1,j=0;i>=0;i--,j++)
    {
        tmp[j]=str[i];
    }
    for (i=0;i<m;i++)
    {
        str[i]=tmp[i];
    }
 
    
    int c=0;      
    int rb[8];      
 
    
    int l=0;        
    int df[30];     
 
    
    k=1;
    for(i=1,j=0;j<m;i++)
    {
        //If it is location of redundancy bit
        if(i==k)
        {
            df[i]=-1;
            k=k*2;
            c++;
        }
        //If it is location of data bit
        else
        {
            df[i]=str[j];
            j++;
        }
        l++;
    }
 
    cout<<"\n";
    cout<<"\n Frame after introducing redundancy bits :\n -1 is R\n ";
    for(i=l;i>0;i--)
    {
        cout<<df[i]<<" ";
    }
 
    int i1,i2,i3,i4,i5,i6,i7;
    int a1[4],a2[4];
     
    i5=0;       
 
    
    for(i1=1;i1<=l;i1++)
    {
        //check if it is redundancy bit which is to be calculated
        if(df[i1]==-1)
        {
            
            i4 = -1;    
             
            //Converting redundancy bit position into binary form and get position of 1
            i7=i1;
            while (i7>0)
            {
                i4++;
                if(i7==1)
                {
                    break;
                }
                else
                {
                    i7=i7/2;
                }
            }
 				
            i3=0; // Consider even parity
 
            
            for(i2=1;i2<=l;i2++)
            {
                
                for(i6=0;i6<4;i6++)
                {
                    a1[i6]=-1;
                }
 
                
                i7=i2;
                i6=0;
                while(i7>0)
                {
                    if(i7==1)
                    {
                        a1[i6]=1;
                        break;
                    }
                    else if(i7==0)
                    {
                        a1[i6]=0;
                    }
                    else
                    {
                        a1[i6]=i7%2;
                        i7=i7/2;
                    }
                    i6++;
                }
 
                
                 
                if(a1[i4]==1)
                {
                    if(df[i2]==1)
                    {
                        i3++;
                    }
                }
                 
            }
 
          
            //odd parity 1  even parity: 0
 
            if(i3%2==0)
            {
                df[i1]=0;
                rb[i5]=0;
            }
            else
            {
                df[i1]=1;
                rb[i5]=1;
            }
            i5++;
 
           
        }
     
    }
    cout<<"\n"<<"Hamming string";
 	for(i2=l;i2>0;i2--)
            {
                cout<<" "<<df[i2];
            }
    return 0;
}

