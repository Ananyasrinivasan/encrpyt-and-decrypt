
using namespace std;
string name;
string password;
string id;
int y[30];
ofstream outfile;
ifstream infile;
void encp(int r[])
{
	
  	int i;
  	for(i=0;i<password.length();i++)
  	{
  
  		y[i]=password.at(i)+r[i];
  		outfile<<y[i]<<" ";
  	}
  	outfile<<endl;
}
int search()
{
  string search;
  ifstream inFile;
  string line;
  inFile.open("users.txt");
  int p=0;
  if(!inFile)
  {
    cout << "Unable to open file" << endl;
  }
  /*cout << "Enter word to search for: ";
  cin >>search;*/
  
  while(inFile.good())
  {
    size_t pos;
        getline(inFile,line); 
        pos=line.find(id); 
        if(pos!=string::npos) 
        {
             cout <<"Not Unique Id.Found It !!";
             p=1;
             break;
        }
  }
    return p;
    inFile.close();
}
void add(int r[])
{
	int y,u=1;
  cout<<"Do you Wish to add new User<Yes/No><1/0>!!"<<endl;
  cin>>u;
	while(u==1)
	{
		cout<<"Enter Username:";
		cin>>name;
		cout<<"Enter password:";
		cin>>password;
	  cout<<"Enter ID:";
    cin>>id;
    y=search();
    if(y==1)
    {
      break;
    }
    cout<<"If you wish you to add more press 1 else 0: ";
    cin>>u;
    outfile<<id<<endl;
    encp(r);
    outfile<<name<<endl;
    outfile<<endl;
    outfile<<endl;
    name="";
    password="";
  }
}
void root(int r[])
{
	outfile.open("users.txt",ios::app);
	cout<<"Root Mode Activated!!"<<endl;
	add(r);
  outfile.close();
}
				