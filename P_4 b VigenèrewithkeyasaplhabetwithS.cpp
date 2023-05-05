#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
void encrypt(string s,string key)
{
	int tmp,temp1;
	int j=0;
	fflush(stdin);
 
	for(int i=0;i<s.length();i++)
	{
		tmp = s[i];
		if(j==key.length() && i!=s.length()){
			j=0;
		}		
		temp1 = key[j];
 
		if(tmp>=65 && tmp<=90)
		{
			s[i]= (((tmp-65)+(temp1-65))%26)+65;
//			cout << char(tmp) << " + " << char(temp1)  << " "; 
//			cout << (((tmp-65)+(temp1-65))%26)+65 << " \n";
		}
		else if(tmp>=97 && tmp<=122)
		{
			s[i]=(((tmp-97)+(temp1-97))%26)+97;
		}
 
		j++;
	}
	cout<<"\nCypher text is ";
	for(int i=0;i<s.length();i++)
	{
		cout<<s[i];
	}
}
void decrypt(string s,string key)
{
	int tmp,temp1;
	int j=0;
	fflush(stdin);
 
	for(int i=0;i<s.length();i++)
	{
		tmp=s[i];
		if(j==key.length() && i!=s.length()){
			j=0;
	    }
		temp1=key[j];
 
		if(tmp>=65 && tmp<=90)
		{
			if(((tmp-65)-(temp1-65))<0){
				s[i]=((((tmp-65)-(temp1-65))+26)%26)+65;
//				cout << char(tmp) << " + " << char(temp1)  << " "; 
//				cout << (((tmp-65)+(temp1-65))%26)+65 << " \n";
			}
			else{
				s[i]=(((tmp-65)-(temp1-65))%26)+65;
//				cout << char(tmp) << " + " << char(temp1)  << " "; 
//				cout << (((tmp-65)+(temp1-65))%26)+65 << " \n";
			}
		}
		else if(tmp>=97 &&tmp<=122)
		{
			if(((tmp-97)-(temp1-97))<0){
				s[i]=((((tmp-97)-(temp1-97))+26)%26)+97;
			}
			else{
				s[i]=(((tmp-97)-(temp1-97))%26)+97;
			}
		}
		j++;
	}
	cout<<"\nPlain text is ";
	for(int i=0;i<s.length();i++)
	{
		cout<<s[i];
	}
}
int main(){
	int n;
	cout<<"1.) Get Ciphertext text from plane text.\n\n";
	cout<<"2.) Get Plain text from cypher text.\n\n";
	cout<<"Enter your choice -> ";
	cin>>n;
	fflush(stdin);
	string s,key;
	if(n==1){
		cout<<"\nEnter plain text. ";
	    getline(cin,s);
	    cout<<"\nEnter key -> ";
	    getline(cin,key);
		encrypt(s,key);
	}
	else if(n==2)
	{
		cout<<"\nEnter cypher text. ";
        getline(cin,s);
        cout<<"\nEnter key -> ";
	    getline(cin,key);
    	decrypt(s,key);
	}
	return 0;
 
}
