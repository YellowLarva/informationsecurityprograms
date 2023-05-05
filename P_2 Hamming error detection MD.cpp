#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>

/*
Enter the size of Data Word : 6
Enter Data Word : 
1
1
0
0
1
1
Data Word : 1  1  0  0  1  1

Generating code word...
Code Word : 1  1  0  0  0  1  1  1  0  1
*/
using namespace std;
class Hamming
 {
	int *arr;
	int *red;
	int m, r, size;
	public:
		Hamming()
		{
			m=0;
			r=0;
			size=0;
		}
		void datainput()
		{
			cout<<"\nEnter the size of Data Word : ";
			cin>>m;								//taking size of data word
			arr=new int[m];
			cout<<"Enter Data Word : ";
			for(int i=0;i<m;i++)
			cin>>arr[i];						//storing dataword
			cout<<"Data Word : ";
			for(int i=0;i<m;i++)
			cout<<arr[i]<<"  ";
			cout<<endl;
		}
		void redundantbit()
		{
			for(int i=1;i<m;i++)
			{
				if(pow(2,i)>=m+i+1)
				{
					r=i;
					break;
				}
			}
			red=new int[r];
			for(int i=0;i<r;i++)
			{
				red[i] = 0;
			}
			cout<<endl;
		}

		Hamming hammingcode() 	
		{
			Hamming temp;
			int p=0;
			int k=m-1;
			temp.size=m+r;
			temp.arr=new int[size];
			for(int i=0;i<temp.size;i++)
			{
				if(i==pow(2,p)-1)
				{
					temp.arr[i]=0;
					p++;
				}
				else	
				{
					temp.arr[i]=arr[k];
					k--;
				}
			}
			cout<<"Generating code word... \n";
		//	cout<<"Intermediate code word : ";
		//	for(int i=temp.size-1;i>=0;i--)
		//		cout<<temp.arr[i]<<"  ";
		//	cout<<endl;
			return temp;
		}

		void red_gen(Hamming h2) 
		{
			for(int i=0;i<r;i++)
			{
				
				for(int j=0;j<h2.size;j++) //1 0 1 0 1 0 1 0 1 0    //rightshift for i=0 
																	//rightshift for i=1 
											//1 =0          	=0
											//2=10 =0       	=1
											//3=11=1        	=1
											//4=100=2(10)&1     =0
											//5=101 =10         =0
											//6 =110=11			=1
											//7  111=11         =1
											//8= 1000=100&1     =0
											//10 =1010=101&1    =1						
											
				{
					if((j+1)>>i&1)
					{
						red[i]^=h2.arr[j];			//finding values of redundant bits by XOR
					}
				}
			}
			int p=0,q=0;
			for(int i=0;i<h2.size;i++)
			{
				if(i==pow(2,q)-1) 
				{
					h2.arr[i]=red[p];				//placing redundant bits in codeword
					p++;
					q++;
				}
			}
			cout<<"Code Word : ";
        	for(int i=h2.size-1;i>=0;i--)
				cout<<h2.arr[i]<<"  ";
		}

		void error_gen()
		{
            int temp=rand()%(2*(size)-1);
            for(int i=0;i<(size-1);i++) 
			{
                if(i==temp) 
				{
                    if(arr[i]==0)
                        arr[i]=1;
                    else
                        arr[i]=0;
                }
            }
            cout<<"\n\nReceiving code word... "<<endl<<"Received Code word : ";
            for(int i=size-1;i>=0;i--)
			cout <<arr[i]<<"  ";
		}
    	void check(Hamming h2) 
		{
        	int c=0;
        	for(int i=0;i<r;i++)
            	red[i]=0;
        	for(int i=0;i<r;i++)
			{
				for(int j=0;j<h2.size;j++) 					
				{
					if((j+1)>>i&1) 
					{
						red[i]^=h2.arr[j];
					}
				}
			}
			for(int i=0;i<r;i++)
			{
            	if(red[i]==1)
                	c++;
			}
			if(c==0)
        	    cout<<"\nError not Detected.\n";
        	else
            	cout<<"\nError Detected.\n";
       		cout<<endl;

        //Finding which bit is incorrect
       		int x=0;
        	for(int i=0;i<r;i++) 
			{
            	if(red[i]==1)
				{
               		x+=pow(2,i);
            	}
        	}
        cout <<"\nError in bit:" <<x;
        	if(h2.arr[x-1]==0)
           		h2.arr[x-1]=1;
        	else
            	h2.arr[x-1]=0;
			cout<<"\nCorrect Code word : ";
            for(int i=h2.size-1;i>=0;i--)
			cout<<h2.arr[i]<<"  ";
    	}
};

int main()
{
    srand(time(0));
	Hamming h1, h2;
	h1.datainput();
	h1.redundantbit();
	h2 = h1.hammingcode();
	h1.red_gen(h2);
	h2.error_gen();
	h1.check(h2);
}
