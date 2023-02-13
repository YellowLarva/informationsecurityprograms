#include <iostream>

using namespace std;

string encrypt(string pt,int key){

    for( int i = 0 ; i < pt.length() ; i++)  pt[i] = toupper(pt[i]);

    for( int i = 0 ; i < pt.length() ; i++){

        if ( int(pt[i]) <= (90-(key%26) ) ){
            pt[i] = int(pt[i]) + (key%26);
        }
        else {
            pt[i] = int (pt[i]) - (26-(key%26));
        }
    }
    
    return pt;
}

string decrypt(string pt,int key){

    for( int i = 0 ; i < pt.length() ; i++)  pt[i] = toupper(pt[i]);

    for( int i = 0 ; i < pt.length() ; i++){

        if ( int(pt[i]) <= (90 + (key%26) - 26 ) ){
            pt[i] = int(pt[i])-(key%26)+26;
        }
        else {
            pt[i] = int (pt[i]) -(key%26);
        }
    }
    
    return pt;
}

int main(){

    int key;
    cout << "Enter your Key length : ";
    cin  >> key;

    string pt;
    cout << "Enter your plain text : ";
    getline(cin >> ws,pt);

    cout << "Encrypted text : " + encrypt(pt,key);

    cout << "\nEnter your Cipher text : ";
    getline(cin >> ws ,pt);

    cout << "Decrypted text : " + decrypt(pt,key);

}
