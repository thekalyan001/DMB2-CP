//https://www.prepbytes.com/blog/strings/minimum-characters-required-to-add-to-given-string-to-make-it-palindrome/#:~:text=5%29%20Finally%20the%20minimum%20number%20of%20characters%20needed,in%20between%20creating%20a%20new%20string%20i.e.%20%22codec%40cedoc%22.

#include<bits/stdc++.h>
using namespace std;

int main(){


    string a;
    cin>>a;

    int sizeOfString = a.length();

    //Concatenating reverse of string to string
    string b = a;
    reverse(b.begin(), b.end());
    a += a +'@' + b;

    //cout<<a<<endl;  abcabc@cba v   v                                        
    int lps[a.length()];

    //Creating lps array for the concatenated string
    lps[0] = 0; 
    int i = 1, len=0; 
    while (i < a.length()) 
    { 
        if (a[i] == a[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        { 
            if (len != 0) 
            { 
                len = lps[len-1]; 
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }
    for(int i=0;i<a.length();i++)
        cout<<lps[i]<<" ";cout<<endl;

    cout<<sizeOfString-lps[a.length()-1]<<endl;

}