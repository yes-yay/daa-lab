//sri rama jayam 
#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

int maximumSubsequence(string text1,string text2 )
{
    if(text1.length()==0||text2.length()==0)
        return 0;
    int length1=text1.length();
    int length2=text2.length();

    for(int i=0;i<length1;i++)
    {
        for(int j=0;j<length2;j++)
        {
            if(text1[i]==text2[j])
                return maximumSubsequence(text1.substr(i+1,length1-i-1),text2.substr(j+1,length2-j-1))+1;
            else if(text1[i]!=text2[j])
                return max(maximumSubsequence(text1.substr(i+1,length1-i-1),text2),maximumSubsequence(text1,text2.substr(j+1,length2-j-1)));
        } 
    }

}

int main()
{
    string t1="aditya";
    string t2="adi";
    cout<<maximumSubsequence(t1,t2)<<endl;
}