#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>

 class car                  //Details Of Cars are in this class
  {

   char cno[10], cname[50];
   long price;

   public:

       void add_car()                        //Adding A Car
	{
	 cout<<"\nNew Car Entry..."<<endl;
	 cout<<"\nEnter The Car's Registration No. : ";
	  cin>>cno;
	 cout<<"\n\nEnter The Car's Name : ";
	  gets(cname);
	 cout<<"\n\nEnter The Car's Price (On-Road) (In US$) : ";
	  cin>>price;
	 cout<<"\n\n\nNew Car Added Successfully!!!";
	}

	void show_car()                      //Showing The Cars List
	{
	 cout<<"\nCar's Registration No. : "<<cno;
	 cout<<"\nCar's Name : ";
	  puts(cname);
	 cout<<"\nCar's Price (On-Road) : "<<price;
	}

	void modify_car()                    /*Modifying Details Of
					     Already Registered Cars*/
	{
	 cout<<"\nCar's Registration No. : "<<cno;
	 cout<<"\nModify Car's Name : ";
	  gets(cname);
	 cout<<"\nModify Car's Price : ";
	  cin>>price;
	}

	char* retcno()
	{
	 return cno;
	}

	void report()                         //Shows All Details
	{
	 cout<<"\n"<<cno<<setw(30)<<cname<<setw(30)<<price<<setw(30)<<endl;
	}

  };

 class customer                //Details Of Customer Are In This Class
  {

   char custid[10], name[20], cucno[20];

    public:
	void add_cust()              //Add Customers
	{
	 clrscr();
	 cout<<"\nNew Customer Entry...\n";
	 cout<<"\nEnter The Customer's ID : ";
	  cin>>custid;
	 cout<<"\n\nEnter The Customer's Name : ";
	  gets(name);
	  cucno[0]='/0';
	 cout<<"\n\nCustomer Added!!!";
	}

	void show_cust()              //Show Customers
	{
	 cout<<"\nCustomer ID : "<<custid;
	 cout<<"\nCustomer's Name : ";
	  puts(name);
	}

	void modify_cust()           /* Modifying Details Of
					Already Registered Customers */
	{
	 cout<<"\nCustomer ID : "<<custid;
	 cout<<"\nModify Customer's Name : ";
	  gets(name);
	}

	char* retcid()
	{
	 return custid;
	}

	char* retcucno()
	{
	 return cucno;
	}

	void getcucno(char t[])
	{
	 strcpy(cucno,t);
	}

	void report()                    //Showing Details
	{
	 cout<<"\n\t\t"<<custid<<setw(40)<<name<<endl;
	}

  };

   fstream f1,f2;               //Global Objects Declaration
   car c;
   customer cu;

  void write_car()                //Calls [Adding A Car] Function
   {
     char ch;
       f1.open("car.dat",ios::out|ios::app);
	do
	{
	  clrscr();
	  c.add_car();
	   f1.write((char*)&c,sizeof(car));
	    cout<<"\n\nDo you want to add more cars...(y/n)? : ";
	     cin>>ch;
	}
	while(ch=='y'||ch=='Y');

	f1.close();

   }

  void write_cust()               //Calls [Adding A Customer] Function
   {
    char ch;
     f2.open("customer.dat",ios::out|ios::app);
      do
	{
	  cu.add_cust();
	   f2.write((char*)&cu,sizeof(customer));
	    cout<<"\n\nDo you want to add more customers...(y/n)? : ";
	     cin>>ch;
	}
	while(ch=='y'||ch=='Y');

	f2.close();

   }

  void display_spc(char n[])        //Displaying A Specific Car
   {
	cout<<"\nCar Details - \n";
	 int flag=0;
	  f1.open("car.dat",ios::in);
	   while(f1.read((char*)&c,sizeof(car)))
	    {
	     if(strcmpi(c.retcno(),n)==0)
		{
		  c.show_car();
		  flag=1;
		}
	    }

	f1.close();
	if(flag==0)
	   cout<<"\n\nNo Such Car Is Registered!";
	getch();
   }

  void display_spcu(char n[])        //Displaying A Specific Customer
   {
	cout<<"\nCustomer Details - \n";
	 int flag=0;
	  f2.open("customer.dat",ios::in);
	   while(f2.read((char*)&cu,sizeof(customer)))
	    {
	     if((strcmpi(cu.retcid(),n)==0))
	      {
		cu.show_cust();
		flag=1;
	      }
	    }

	f2.close();
	if(flag==0)
		cout<<"\n\nNo Such Customer Is Registered!";
	getch();
  }

 void modify_car()             //Calls [Modifying A Car] Function
  {
	char n[6];
	int found=0;
	clrscr();
	cout<<"\n\n\tModify Car Record... ";
	cout<<"\n\n\tEnter The Registration No. of the Car : ";
	cin>>n;
	f1.open("car.dat",ios::in|ios::out);
	while(f1.read((char*)&c,sizeof(car)) && found==0)
	{
		if(strcmpi(c.retcno(),n)==0)
		{
			c.show_car();
			cout<<"\nEnter The New Details of Car : "<<endl;
			c.modify_car();
			int pos=-1*sizeof(c);
			f1.seekp(pos,ios::cur);
			f1.write((char*)&c,sizeof(car));
			cout<<"\n\n\t Record Updated!!";
			found=1;
		}
	}

	f1.close();
	if(found==0)
		cout<<"\n\n Record Not Found! ";
	getch();
  }


  void modify_cust()             //Calls [Modifying A Customer] Function
  {
	char n[6];
	int found=0;
	clrscr();
	cout<<"\n\n\tModify A Customer Record... ";
	cout<<"\n\n\tEnter The Customer ID of the Customer : ";
	cin>>n;
	f2.open("customer.dat",ios::in|ios::out);
	while(f2.read((char*)&cu,sizeof(customer)) && found==0)
	{
		if(strcmpi(cu.retcid(),n)==0)
		{
			cu.show_cust();
			cout<<"\nEnter The New Details of Customer : "<<endl;
			cu.modify_cust();
			int pos=-1*sizeof(cu);
			f2.seekp(pos,ios::cur);
			f2.write((char*)&cu,sizeof(customer));
			cout<<"\n\n\t Record Updated!!";
			found=1;
		}
	}

	f2.close();
	if(found==0)
		cout<<"\n\n Record Not Found! ";
	getch();
  }

 void delete_cust()             //Deleting Customer Records
  {
	char n[6];
	int flag=0;
	clrscr();
	cout<<"\n\n\n\tDelete Customer...";
	cout<<"\n\nEnter The customer ID of the Customer You Want To Delete : ";
	cin>>n;
	f2.open("customer.dat",ios::in|ios::out);
	fstream f3;
	f3.open("Temp.dat",ios::out);
	f2.seekg(0,ios::beg);
	while(f2.read((char*)&cu,sizeof(customer)))
	{
		if(strcmpi(cu.retcid(),n)!=0)
			f3.write((char*)&cu,sizeof(customer));
		else
			flag=1;
	}

	f3.close();
	f2.close();
	remove("customer.dat");
	rename("Temp.dat","customer.dat");
	if(flag==1)
		cout<<"\n\n\tRecord Deleted!!";
	else
		cout<<"\n\nRecord not found!";
	getch();

  }

  void delete_car()               //Deleting Car Records
  {
	char n[6];
	clrscr();
	cout<<"\n\n\n\tDelete Car ...";
	cout<<"\n\nEnter The Registration no. of the Car You Want To Delete : ";
	cin>>n;
	f1.open("car.dat",ios::in|ios::out);
	fstream f4;
	f4.open("Temp.dat",ios::out);
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&c,sizeof(car)))
	{
		if(strcmpi(c.retcno(),n)!=0)
		{
			f4.write((char*)&c,sizeof(car));
		}
	}

	f4.close();
	f1.close();
	remove("car.dat");
	rename("Temp.dat","car.dat");
	cout<<"\n\n\tRecord Deleted!";
	getch();
  }

  void display_allcu()            //Displaying List Of All Customers
  {
	clrscr();
	f2.open("customer.dat",ios::in);

	if(!f2)
	{
	  cout<<"File Couldn't Be Opened!!! ";
	   getch();
	  return;
	}

	cout<<"\n\n\t\t\t\tCustomers List\n\n";
	cout<<"------------------------------------------------------------------------------\n";
	cout<<"\t\tCustomer ID"<<setw(34)<<"Name\n";
	cout<<"------------------------------------------------------------------------------\n";

	while(f2.read((char*)&cu,sizeof(customer)))
	{
	 cu.report();
	}

	f2.close();
	getch();
  }

   void display_allc()              //Displaying List Of All Cars
    {
	clrscr();
	f1.open("car.dat",ios::in);
	if(!f1)
	{
	   cout<<"File Couldn't Be Opened!!!";
	    getch();
	   return;
	}

	cout<<"\n\t\t\t\tCars List\n";
	cout<<"------------------------------------------------------------------------\n";
	cout<<"Registration No."<<setw(23)<<"Car Name"<<setw(30)<<"Price\n";
	cout<<"------------------------------------------------------------------------\n";

	while(f1.read((char*)&c,sizeof(car)))
	{
	 c.report();
	}

	f1.close();
	getch();
   }

  void car_buy()               //Buying A Car
   {
     char sn[6],bn[6];
	int found=0,flag=0;
	clrscr();
	cout<<"\n\nBuying A Car ...";
	cout<<"\n\n\tEnter The Customer's ID : ";
	cin>>sn;
	f2.open("customer.dat",ios::in|ios::out);
	f1.open("car.dat",ios::in|ios::out);
	while(f2.read((char*)&cu,sizeof(customer)) && found==0)
	{
		if(strcmpi(cu.retcid(),sn)==0)
		{
			found=1;
				cout<<"\n\n\tEnter the Car's Registration No. : ";
				cin>>bn;
				while(f1.read((char*)&c,sizeof(car))&& flag==0)
				{
					if(strcmpi(c.retcno(),bn)==0)
					{
						c.show_car();
						flag=1;
						cu.getcucno(c.retcno());
						int pos=-1*sizeof(cu);
						f2.seekp(pos,ios::cur);
						f2.write((char*)&cu,sizeof(customer));
						cout<<"\n\n\t Car Bought Successfully!!!\n\n";
					}
				}
				if(flag==0)
					cout<<"Wrong Car Registration No.";


		}
	}
	if(found==0)
		cout<<"Customer record does not exist...";
	getch();
	f1.close();
	f2.close();
  }

  void intro()                  //Introduction Page Function
   {
	clrscr();
	gotoxy(25,4);
	cout<<"^^^^^-----------------^^^^^";
	gotoxy(25,5);
	cout<<"CAR SALES MANAGEMENT SYSTEM";
	gotoxy(25,6);
	cout<<"*****-----------------*****\n\n\n";
	cout<<"Luxury Motors Pvt. Ltd is a corporation started in 1990 which deals with the sale and business of luxury vehicles from various highly-esteemed vehicle manufacturing companies. It had been established with a dream , a dream of creating a corporation which lets people choose freely, without any bias or any thought to make any kind of unnecessary, deliberate and intentional profit from the finest, most sophisticated, state-of-the-art and most powerful cars ever built. We have been following our tradition of serving the public ever since our inception, and we will be following it forever.";
	gotoxy(1,18);
	cout<<"\n\nMade By : Kshitij , Sameer And Khushi";
	cout<<"\n\nClass : XII - C";
	getch();
   }

  void admin_menu()                  //Administration Menu Function
   {
	clrscr();
	int ch2;
	cout<<"\n\n\n\tAdministration Menu";
	cout<<"\n\n\t1.  Add A Customer";
	cout<<"\n\n\t2.  Display All Customers";
	cout<<"\n\n\t3.  Display A Specific Customer";
	cout<<"\n\n\t4.  Modify A Customer's Records";
	cout<<"\n\n\t5.  Delete A Customer";
	cout<<"\n\n\t6.  Add A Car ";
	cout<<"\n\n\t7.  Display All Cars ";
	cout<<"\n\n\t8.  Display A Specific Car ";
	cout<<"\n\n\t9.  Modify A Car's Details ";
	cout<<"\n\n\t10. Delete A Car";
	cout<<"\n\n\t11. Return To Main Menu";
	cout<<"\n\n\tPlease Enter Your Choice (1-11) : ";
	cin>>ch2;
	switch(ch2)
	{
		case 1: clrscr();
			write_cust();break;
		case 2: display_allcu();break;
		case 3:
			char num[6];
			clrscr();
			cout<<"\n\n\tPlease Enter The Customer ID : ";
			cin>>num;
			display_spcu(num);
			break;
		case 4: modify_cust();break;
		case 5: delete_cust();break;
		case 6: clrscr();
			write_car();break;
		case 7: display_allc();break;
		case 8: {
			char num[6];
			clrscr();
			cout<<"\n\n\tPlease Enter The Car's Registration No. : ";
			cin>>num;
			display_spc(num);
			break;
			}
		case 9: modify_car();break;
		case 10: delete_car();break;
		case 11: return;
		default:cout<<"\a";
	}
	admin_menu();
  }

 void main()
  {
   int i;
    intro();
     do
      {
	clrscr();
	 cout<<"\n\n\n\tMain Menu - ";
	 cout<<"\n\n\t1. Buy A Car";
	 cout<<"\n\n\t2. Administration Menu";
	 cout<<"\n\n\t3. Exit";
	 cout<<"\n\n\tPlease Select Your Option (1-3) : ";
	  cin>>i;
	   switch(i)
	    {
		case 1  :clrscr();
			 car_buy();
			 break;
		case 2  :admin_menu();
			 break;
		case 3  :exit(0);
		default :cout<<"\a";
	   }

	}
	  while(i!=3);

 }

