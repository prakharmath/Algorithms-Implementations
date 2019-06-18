#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+9;
//This code determines the length of all the proper prefixes which are also the suffixes of the string//
//Here we are calculating the hash value of each substring in O(1) and comparing them one by one//
//The same can be done using the precomputation part of KMP Algorithm wherein we calculate the lps array//
//That procedure can be modified to get all the prefixes which are also suffixes without altering the complexity//
//We are hashing with respect to a large prime to avoid collisions as much as possible//
//Theoretically this process will obviously have some collisions and it's not fully correct 
//but its efficiency is pretty good //
int add(int a,int b){return (a%mod + b%mod)%mod;}
int mul(int a,int b){return (a%mod * b%mod)%mod;} //Copied from my original CP template
signed main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 string s;
	 cin>>s;
	 vector<int>positions;
	 int hashfront=0;
	 int hashback=0;
	 int n=s.length();
	 int power=1;
	 for(int i=0;i<n-1;i++)
	 {
           hashfront=add(s[i]-'a'+1,mul(26,hashfront));
           hashback=add(mul(power,s[n-1-i]-'a'+1),hashback);
           power=mul(power,26);
           if(hashfront==hashback)
           	positions.emplace_back(i);
      }
      for(auto x:positions)
      	cout<<x<<endl;
      return 0;
}
/* Test output
   abcdef-No x found
   queryqueryquery-4,9 (As can be seen query and queryquery are two proper prefixes which
   are also present as suffixes)
 */