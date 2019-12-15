

#include<iostream>
#include<fstream>
#include<vector>
#include <sstream>

using namespace std;

class File_IO //File IO class
{
   string name;
   string SizeCup;
   
   public: //three constructors
   
   File_IO(string n,string s)
   {
		name=n;
		SizeCup=s;
   }
   
   string FetchCupSize()
   {
		return SizeCup;
   }
   
   string FetchName()
   {
	   return name;
   }
   
};

class chili //chili class
{
   vector<File_IO> data;
   int batch;
   
   public: //have five contructors in this class
      
       chili()
       {
           batch=0;
       }
	   
       void ScanBatch() //setting batch number
	   {
			int batches;
			cout<<"How may batches of of your famous chili are you making today? ";
			cin>>batches;
			batch=batch+batches*2;
       }
	   
       void ReadFile() //reads the customer.txt file
	   {
           ifstream file;
           string line;
           file.open("customer.txt");
           while(getline(file,line))
            {
			   stringstream linestream(line);
			   
               string value,firstName,SizeCup;
               int temp=0;
			   
			   while(getline(linestream,value,','))
			   {
				   if(temp==0)
				   {
				   firstName = value;
				   temp=1;
				   }else{
					   SizeCup = value;
					   File_IO tempObj(firstName,SizeCup);
					   data.push_back(tempObj);
					   temp=0;
				    }
			    }
		    }
       }
	   
       void StartServing()
	   {
           string choice;
           int CupCount;
		   
           cout<<"\n---Welcome Louise---\n";
           cout<<"Checking today\'s customers...";
		   
           ReadFile();
		   
           cout<<"done!"<<endl<<endl;
           ScanBatch();
		   cout<<endl;
           cout<<"Starting orders..."<<endl;
           
           for(int i=0;i<data.size();i++) //for loop to continue and break input user for fetching chili based on cup size
		   {
               cout<<"\n--Customer "<<i+1<<":"<<data[i].FetchName()<<"'s order is "<<data[i].FetchCupSize()<<endl;
               CupCount = FetchCupQuantity(data[i].FetchCupSize());
               
               if(CupCount<=batch)
			   {
                   batch -= CupCount;
				   
				   if(batch>=1)
				   {
				   cout<<"Order served. Still got lots of chili!"<<endl<<endl;
				   }
				   else
				   {
					   cout<<"Order served.Not much chili left!\n\n";
				   }
                }

			   else
			   {
					cout<<"Sorry, not enough chili. Would you like to make another batch or quit?\n";
					cin>>choice;
				   if(choice.compare("quit")==0)
				   {
						cout<<endl;
						  exit(0);
				   }
				   
				   else
				   {
					   ScanBatch();
				   }
			   }
			   
               cout<<"Continue with orders or take a break?"<<endl;
               cin>>choice;
			   if(choice.compare("break")==0)
			   {
				   cout<<"OK. Press enter to continue when you are finished with your break."<<endl;
				   getchar();
				   getchar();
			   }
           }
       }
	   
       
       int FetchCupQuantity(string SizeCup)//update cupsizes
	   {
           if(SizeCup.compare("Venti")==0)
		   {
               return 4;
           }
		   
		   else if(SizeCup.compare("Grande")==0)
		   {
               return 3;   
           }
		   
		   else if(SizeCup.compare("Tall")==0)
		   {
               return 2;
           }
		   
		   else
		   {
               return 1; 
           }
       }
};


int main(void)
{
   
   chili object; //declaring chili object
   object.StartServing(); //accessing startserving() function through chili object
   
}

