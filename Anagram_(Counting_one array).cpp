#include <bits/stdc++.h>
using namespace std;
string s;
int gcd(int a ,int b)
{
    if (a == 0 || b == 0)  
        return 0;  
    if (a == b)  
        return a;  
    if (a > b)  
        return gcd(a-b, b);  
    return gcd(a, b-a);  
}
int lcm(int a, int b)  
{  
    return (a*b)/gcd(a, b);  
}  
int main()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int alpha[26];
    memset(alpha,0,sizeof(alpha));
    for(int i=0;i<n;i++)
    {
        alpha[s[i][0]-97]++;
    }
    int no1=0;
    int no2=0;
    for(int i=0;i<26;i++)
        cout<<alpha[i]<<"  ";
    //for(int i=0;)
    for(int i=0;i<26;i++)
    {
        if(alpha[i] == 0)
            continue;
        else if(alpha[i] % 2 ==0)
        {
            no1+=((alpha[i]/2)*((alpha[i]/2)-1)/2);
            no2+=no1;
        }
        else
        {
            no1+=(((alpha[i]/2)+1)*(alpha[i]/2))/2;
           // cout<<no1<<" ldljb"<<endl;
            no2+=((alpha[i]/2)*((alpha[i]/2)-1)/2);
        }
    }
    cout<<no1+no2;

}