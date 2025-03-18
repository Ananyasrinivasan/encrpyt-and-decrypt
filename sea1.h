int i;
int kui[100];
int c[20];
int iii;
int d;
char mess1[30];
using namespace std;
void decry1(int r[])
{
  
  for(int i=0;i<d-1;i++)
  {
      mess1[i]=c[i+1]-r[i];
  }
}
void join(int r[])
{
	int h=0;
	int k;
	d=0;
	for (int i = 0; i < iii+1; ++i)
	{
		if(kui[i]==-16)
		{
			k=i;
			break;
		}
	}
	for (int i = k-1,q=1; i>h; i--,q=q*10)
	{
		c[0]+=kui[i]*q;
	}
	d++;
	for(i=1;i<iii+1;i++)
	{
		if(kui[i]==-16)
		{
			k=i;
		for (int j = k-1,q=1; j>h; j--,q=q*10)
		{
			c[d]+=kui[j]*q;
		}
		d++;
		}
		h=k;
	}
	decry1(r);
}
void clear()
{
  ofstream outfile;
  outfile.open("pass.txt");
  outfile.close();
    
}
void search32(string search,int r[])
{
  ifstream inFile;
	string line;
	;
	inFile.open("users.txt");
	if(!inFile)
	{
		cout << "Unable to open file" << endl;
	}
	
	while(inFile.good())
	{
		size_t pos;
    getline(inFile,line); 
    pos=line.find(search); 
    if(pos!=string::npos) 
    {
      break;
   	}
   }
  getline(inFile,line);
  iii=line.length();
  kui[0]=-16;
  kui[iii]=-16;
  for(i=0;i<iii;i++)
  {
   	kui[i+1]=line.at(i)-48;
  }
  
  	
  ofstream outfile;
  outfile.open("pass.txt");
  join(r);
  for(int i=0;i<d-1;i++)
  {
    mess1[i]=c[i+1]-r[i];
    outfile<<mess1[i];
  }
  outfile.close();

}