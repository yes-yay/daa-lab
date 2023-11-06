//sri rama jayam 
#include<iostream>
#include<stack>
#include<string.h>
#include<cstring>
using namespace std;

bool isPalindrome(string text)
{
    int length=text.length();
    for(int i=0;i<length/2;i++)
    {
        if(text[i]!=text[length-1-i])
            return false;
    }
    return true;
}

int minPalindromicPartitions(string text)
{
    int count=0;

    stack<char> charStack;
    int length=text.length();
    for(int i=0;i<length-1;i++)
    {
        char character=text[i];
        for(int j=i+1;j<length-1;j++)
        {
            if(text[j]==character)
                charStack.push(j);
        }
        int currentIndex=charStack.pop();
        if(isPalindrome(substr(i,currentIndex-i+1)))
            count++;
    }
}




int main()
{
    string text;
    cout<<"enter text: "<<endl;
    cin>>text;

    cout<<"minimum partitions required is "<<minPalindromicPartitions(text)<<endl;


}