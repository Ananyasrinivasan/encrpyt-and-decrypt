#include "sea1.h"
#include "root.h"
using namespace std;
#define MAX 1000
#define seed 1
int ri[MAX];
void start()
{
	ri[0] = seed;
  for (i=1; i<31; i++) 
  {
   	ri[i] = (16807LL * ri[i-1]) % 2147483647;
   	if (ri[i] < 0) 
   	{
   	  ri[i] += 2147483647;
   	}
  }
  for (i=31; i<34; i++) 
  {
   	ri[i] = ri[i-31];
  }
  for (i=34; i<344; i++) 
  {
  	ri[i] = ri[i-31] + ri[i-3];
  }
  for (i=344; i<MAX; i++) 
  {
   	ri[i] = ri[i-31] + ri[i-3];
  }
}
void mlogin()
{
	start();
	string name;
	cout<<"Enter User id: ";
	cin>>name;
	search32(name,ri);
	ifstream infile;
	infile.open("pass.txt");
	string pass;
	getline(infile,pass);
	string password;
	cout<<"Enter Password: ";
	cin>>password;
	if(password==pass)
	{
		if(name=="121")
		{
		cout<<"Success"<<endl;
		root(ri);
		}
		else
		{
			cout<<"wait"<<endl;
		}

	}
	else
	{
		cout<<"failure";
	}
	clear();
	cout<<endl;
}