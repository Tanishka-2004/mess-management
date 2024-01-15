#include"conio.h"

#include"stdio.h"

#include"stdlib.h"

#include "windows.h"

#include "process.h"

#include"string.h"

typedef struct menu

{

	char itemname[100];

	float itemprice;

};

typedef struct student

{

	char name[100];

	int reg;

	char gen;

	char phno[20];

	float due;

};

struct student s1[100];

struct menu m1[100];

int i,n,r,z,pass;

char x,y,ch,k;

float s;

FILE *fp,*fs,*f1,*f2;

void gotoxy(int, int);

void password();

void pos();

void menu();

void searchmenu();

void newmenu();

void acceptmenu();

void updatemenu();

void deletemenu();

void displaymenu();

//////////////////////////////////////////////////////////////

void student();

void addstudent();

void searchstudent();

void updatestudent();

void displaystudent();

void deletestudent();

//////////////////////////////////////////////////////////////

void order();

void bill();

void duepayment();




void main()
{

  char a;

  do
  {
  system("cls");
  printf("\n\n\t\t\t TAMTAN MESS MANAGEMENT SYSTEM");
  printf("\n\t\t\t ^^^^^^ ^^^^ ^^^^^^^^^^ ^^^^^^");
  printf("\n\n Enter Your Choice -");
  printf("\n\n 1.Menu");
  printf("\n\n 2.Student Record");
  printf("\n\n 3.Order");
  printf("\n\n 4.Exit");
  printf("\n\n Enter Your Choice :- ");
  fflush(stdin);
  scanf("%c",&a);
  if(a=='1')
  {
	  menu();
  }
  else if(a=='2')
  {
	  student();
  }
  else if(a=='3')
  {
	order();
  }
  else if(a=='4')
  {
  exit(0);
  }
  else
  {
  printf("\n\n You have entered a wrong choice");
  getch();
  }
  }while(1);
}





void gotoxy(int x, int y)
{
  HANDLE hConsoleOutput;
  COORD dwCursorPosition;
  fflush(stdin);
  dwCursorPosition.X = x;
  dwCursorPosition.Y = y;
  hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
void menu()
{
  char a;
  do
  {
  system("cls");
  printf("\n\n 1.Enter New Items in Menu");
  printf("\n\n 2.Update Menu");
  printf("\n\n 3.Delete Menu");
  printf("\n\n 4.Display Menu");
  printf("\n\n 5.Search any Item in the Menu");
  printf("\n\n 6.Exit from Menu Database");
  printf("\n\n Enter Your Choice :- ");
  fflush(stdin);
  scanf("%c",&a);
  if(a=='1')
  {
	  acceptmenu();
  }
  else if(a=='2')
  {
	  updatemenu();
  }
  else if(a=='3')
  {
	  deletemenu();
  }
  else if(a=='4')
  {
  displaymenu();
  }
  else if(a=='5')
  {
  searchmenu();
  }
  else if(a=='6')
  {
	break;
  }
  else
  {
  printf("\n\n You have entered a wrong choice");
  getch();
  }
  }while(1);
}
void acceptmenu()
{
	int n,j,k,r,o;
	fs=fopen("noe.txt","r");
	if(fs!=NULL)
	{
	fscanf(fs,"%d",&n);
	fclose(fs);
	remove("noe.txt");
	}
	else
	n=0;
	fp=fopen("PROJECT.txt","a+");
	fs=fopen("noe.txt","w");
	printf("\n\n Enter the number of Elements you want to Enter in the Menu - \n");
	scanf("%d",&j);
	for (k=n+1;k<=j+n;k++)
	{
		i=k;
		x4:
		system("cls");
		pos();
		printf("\n\n %d%c%c Item Name : ",k,x,y);
		fflush(stdin);
		gets(m1[k].itemname);
		r=0;
		r=strlen(m1[k].itemname);
		for(o=0;o<r;o++)
		{
		if(((m1[k].itemname[o]>='A')&&(m1[k].itemname[o]<='Z'))||((m1[k].itemname[o]>='a')&&(m1[k].itemname[o]<='z'))||(m1[k].itemname[o]==' '))
		{
		}
		else
		{
		printf("\n\n ERROR !!! You have entered any other character in name... ");
		getch();
		goto x4;
		}
		}
		printf("\n\n\t Price : ");
		r=scanf("%f",&m1[k].itemprice);
		if(r==0)
		{
		printf("\n\n ERROR !!! You have not entered a number... ");
		getch();
		goto x4;
		}
		fwrite(&m1,sizeof(m1),1,fp);
		getch();
	}
	fprintf(fs,"%d",n+j);
	fclose(fs);
	fclose(fp);
}
void updatemenu()
{
	int n1,c=0;
	int p,r,o;
	system("cls");
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r+");
	if((fp!=NULL)&&(fs!=NULL))
	{
	printf("\n\n Enter the item number you want to update -");
	scanf("%d",&n1);
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
		x5:
		fread(&m1,sizeof(m1),1,fp);
		pos();
		if(i==n1)
		{
		system("cls");
		printf("\n\n Old Details -");
		printf("\n ^^^ ^^^^^^^");
		printf("\n\n  %d%c%c Item Name : %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price : %.2f",m1[i].itemprice);
		p=sizeof(m1);
		fseek(fp,-p,SEEK_CUR);
		printf("\n\n Enter New Details -");
		printf("\n\n  %d%c%c Item Name : ",i,x,y);
		fflush(stdin);
		gets(m1[i].itemname);
		r=0;
		r=strlen(m1[i].itemname);
		for(o=0;o<r;o++)
		{
		if(((m1[i].itemname[o]>='A')&&(m1[i].itemname[o]<='Z'))||((m1[i].itemname[o]>='a')&&(m1[i].itemname[o]<='z'))||(m1[i].itemname[o]==' '))
		{
		}
		else
		{
		printf("\n\n ERROR !!! You have entered any other character in name... ");
		getch();
		goto x5;
		}
		}
		printf("\n  Price : ");
		r=scanf("%f",&m1[i].itemprice);
		if(r==0)
		{
		printf("\n\n ERROR !!! You have not entered a number... ");
		getch();
		goto x5;
		}
		c++;
		fwrite(&m1,p,1,fp);
		}
	}
	if(c==0)
	{
		printf("\n\n Item doesn't Exist in the Menu ");
		getch();
	}
	else
	printf("\n\n  Menu Updated....");
	fclose(fp);
	fclose(fs);
	}
	else
	printf("\n\n Menu doesn't exist");
	getch();
}
void searchmenu()
{
	int n1,c=0;
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	system("cls");
	if((fp!=NULL)&&(fs!=NULL))
	{
	printf("\n\n\n Enter the Item Number You Want to Search - ");
	scanf("%d",&n1);
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&m1,sizeof(m1),1,fp);
		pos();
		if(i==n1)
		{
		printf("\n\n Item Details -");
		printf("\n ^^^^ ^^^^^^^");
		if(i<10)
		{
		printf("\n\n  %d%c%c Item Name : %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price : %.2f",m1[i].itemprice);
		}
		else
		{
		printf("\n\n  %d%c%c Item Name : %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price : %.2f",m1[i].itemprice);
		}
		c++;
		}
	}
	if(c==0)
	{
		printf("\n\n Item doesn't Exist in the Menu ");
	}
	fclose(fp);
	fclose(fs);
	}
	else
	printf("\n\n Menu doesn't exist");
	getch();
}
void deletemenu()
{
	int x;
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	system("cls");
	if((fp!=NULL)&&(fs!=NULL))
	{
	printf("\n\n Menu Deleted....");
	x=1;
	}
	else
	printf("\n\n Menu doesn't exist");
	if(x==1)
	{
	fclose(fs);
	fclose(fp);
	remove("PROJECT.txt");
	remove("noe.txt");
	}
	getch();
}
void displaymenu()
{
	system("cls");
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	if((fp!=NULL)&&(fs!=NULL))
	{
	fscanf(fs,"%d",&n);
	printf("\n\n\n ====================================MENU===================================");
	for(i=1;i<=n;i++)
	{
	fread(&m1,sizeof(m1),1,fp);
	pos();
	if(i<10)
	{
	gotoxy(2,4+i);
	printf("%d%c%c  Item Name : %s",i,x,y,m1[i].itemname);
	}
	else
	{
	gotoxy(2,4+i);
	printf("%d%c%c Item Name : %s",i,x,y,m1[i].itemname);
	}
	if(m1[i].itemprice<10)
	{
	gotoxy(62,4+i);
	printf("Price :  %.2f",m1[i].itemprice);
	}
	else
	{
	gotoxy(62,4+i);
	printf("Price : %.2f",m1[i].itemprice);
	}
	}
	fclose(fp);
	fclose(fs);
	}
	else
	printf("\n\n Menu doesn't exist");
	getch();
}
void pos()
{
	if(i%10==1&&i!=11)
	{
		x='s';
		y='t';
	}
	else if(i%10==2&&i!=12)
	{
		x='n';
		y='d';
	}
	else if(i%10==3&&i!=13)
	{
		x='r';
		y='d';
	}
	else
	{
		x='t';
		y='h';
	}
}






void order()
{
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	if((fp!=NULL)&&(fs!=NULL))
	{
	do
	{
	system("cls");
	printf("\n\n Enter your choice :-");
	printf("\n\n 1.Student");
	printf("\n\n 2.Outsider");
	printf("\n\n 3.Exit to Main Menu ");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='1')
	{
		f2=fopen("nos.txt","r");
		f1=fopen("STUDENT.txt","r");
		if((f1!=NULL)&&(f2!=NULL))
		{
		searchstudent();
		if(z==0)
		{
		printf("\n\n Do you want to purchase any Item (y/any key) ? ");
		fflush(stdin);
		scanf("%c",&k);
		if((k=='y')||(k=='Y'))
		{
		bill();
		}
		else
		s=0;
		duepayment();
		fclose(f1);
		fclose(f2);
		}
		}
		else
		{
		system("cls");
		printf("\n\n Student record doesn't exist");
		getch();
		}
	}
	else if(ch=='2')
	{
		bill();
	}
	else if(ch=='3')
	{
		fclose(fp);
		fclose(fs);
		break;
	}
	else
	{
	printf("\n\n You have entered a wrong choice");
	getch();
	}
	}while(1);
	fclose(fp);
	fclose(fs);
	}
	else
	{
	system("cls");
	printf("\n\n Menu doesn't exist");
	getch();
	}
}
void bill()
{
	int df=0,o=0,t,j,c=0,a[100],q[100];
	s=0;
	system("cls");
	displaymenu();
	printf("\n\n Enter the total no. of Items you want to purchase - ");
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
	system("cls");
	displaymenu();
	i=j;
	c=0;
	pos();
	printf("\n\n  %d%c%c Item No. = ",j,x,y);
	scanf("%d",&a[j]);
	printf("\n\n  Quantity = ");
	scanf("%d",&q[j]);
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&m1,sizeof(m1),1,fp);
		pos();
		if(i==a[j])
		{
		printf("\n\n  Item Details -");
		printf("\n  ^^^^^^^^^^^^");
		if(i<10)
		{
		printf("\n\n  %d%c%c Item Name - %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price - %.2f",m1[i].itemprice);
		s+=m1[i].itemprice*q[j];
		}
		else
		{
		printf("\n\n  %d%c%c Item Name - %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price - %.2f",m1[i].itemprice);
		s+=m1[i].itemprice*q[j];
		}
		c=1;
		df++;
		getch();
		}
	}
	if(c==0)
	{
		printf("\n\n Item doesn't Exist in the Menu ");
		getch();
	}
	}
	fclose(fs);
	fclose(fp);
	if(df!=0)
	{
	system("cls");
	printf("\n ********************************* Cash Memo **********************************");
	printf("\n ********************************* ^^^^ ^^^^ **********************************");
	printf("\n================================================================================");
	gotoxy(2,7);
	printf("Serial Number");
	gotoxy(2,8);
	printf("^^^^^^ ^^^^^^");
	gotoxy(20,7);
	printf("Item Name");
	gotoxy(20,8);
	printf("^^^^ ^^^^");
	gotoxy(42,7);
	printf("Quantity");
	gotoxy(42,8);
	printf("^^^^^^^^");
	gotoxy(60,7);
	printf("Price");
	gotoxy(60,8);
	printf("^^^^^");
	for(j=1;j<=t;j++)
	{
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
	fread(&m1,sizeof(m1),1,fp);
	if(i==a[j])
	{
	++o;
	gotoxy(2,9+j);
	printf("%d",o);
	gotoxy(20,9+j);
	printf("%s",m1[i].itemname);
	gotoxy(45,9+j);
	printf("%d",q[j]);
	gotoxy(60,9+j);
	printf("%.2f",m1[i].itemprice*q[j]);
	}
	}
	}
	gotoxy(1,45);
	printf("===============================================================================");
	gotoxy(50,46);
	printf(" Total Payment = %.2f",s);
	gotoxy(1,47);
	printf("===============================================================================");
	getch();
	system("cls");
	fclose(fs);
	fclose(fp);
}}
void duepayment()
{
	int n=0,x,rt;
	float d,a;
	system("cls");
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r");
	fscanf(f2,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&s1,sizeof(s1),1,f1);
		if((s1[i].reg)==r)
		{
			system("cls");
			printf("\n\n Student Details - ");
			printf("\n ^^^^^^^ ^^^^^^^");
			printf("\n\n Registration no: %d",s1[i].reg);
			printf("\n\n Name: %s",s1[i].name);
			printf("\n\n Gender: %c",s1[i].gen);
			printf("\n\n Phone number: %s",s1[i].phno);
			printf("\n\n Due payment = %.2f",s1[i].due);
			d=s1[i].due;
		}
	}
	fclose(f1);
	fclose(f2);
	printf("\n\n Current Payment = %.2f",s);
	printf("\n\n Total Payment = %.2f",s+d);
	if((k=='y')||(k=='Y'))
	{
	z:
	printf("\n\n Enter the amounnt,you want to pay now = ");
	fflush(stdin);
	rt=scanf("%f",&a);
	if(rt==0)
	{
	printf("\n\n ERROR !!! You have not entered a number... ");
	getch();
	goto z;
	}
	}
	else
	{
	if(d!=0)
	{
	fr:
	printf("\n\n Enter the amounnt,you want to pay now = ");
	fflush(stdin);
	rt=scanf("%f",&a);
	if(rt==0)
	{
	printf("\n\n ERROR !!! You have not entered a number... ");
	getch();
	goto fr;
	}
	}
	else
	a=0;
	}
	printf("\n\n Remaining Balance = %.2f",s+d-a);
	d=s+d-a;
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r+");
	fscanf(f2,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&s1,sizeof(s1),1,f1);
		if((s1[i].reg)==r)
		{
			x=sizeof(s1);
			fseek(f1,-x,SEEK_CUR);
			s1[i].due=d;
			fwrite(&s1,x,1,f1);
		}
	}
	fclose(f1);
	fclose(f2);
	getch();
}




void password()
{
int k;
char p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;
for(k=3;k>0;k--)
{
system("cls");
printf("\n\n\n  Enter your Password:-");
p1=getch();
printf("*");
p2=getch();
printf("*");
p3=getch();
printf("*");
p4=getch();
printf("*");
p5=getch();
printf("*");
p6=getch();
printf("*");
p7=getch();
printf("*");
p8=getch();
printf("*");
p9=getch();
printf("*");
p10=getch();
printf("*");
p11=getch();
printf("*");
if(((p1=='m')||(p1=='M'))&&((p2=='e')||(p2=='E'))&&((p3=='s')||(p3=='S'))&&((p4=='s')||(p4=='S'))&&(p5=='@')&&((p6=='h')||(p6=='H'))&&((p7=='m')||(p7=='M'))&&((p8=='r')||(p8=='R'))&&((p9=='i')||(p9=='I'))&&((p10=='t')||(p10=='T'))&&((p11=='m')||(p11=='M')))
{
printf("\n\n\n\n  Correct Password......Press any key to continue");
getch();
pass=1;
break;
}
else
{
printf("\n\n\n\n  Incorrect Password......Press any key");
printf("\n\n  Trials Remaining:- %d",k-1);
getch();
pass=0;
}
}
}








void student()
{
char ch;
do
{
system("cls");
printf("\n\n 1.Add New Student");
printf("\n\n 2.Search Student Information");
printf("\n\n 3.Update Student Information");
printf("\n\n 4.Display All Information");
printf("\n\n 5.Remove All Data");
printf("\n\n 6.Exit from Student Database");
printf("\n\n Enter your choice :- ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='1')
{
addstudent();
}
else if(ch=='2')
{
searchstudent();
}
else if(ch=='3')
{
updatestudent();
}
else if(ch=='4')
{
displaystudent();
}
else if(ch=='5')
{
deletestudent();
}
else if(ch=='6')
{
	break;
}
else
{
printf("\n\n You have entered a wrong choice");
getch();
}
}while(1);
}
void addstudent()
{
int i,po,j,k,r,o;
f2=fopen("nos.txt","r");
if(f2!=NULL)
{
fscanf(f2,"%d",&i);
fclose(f2);
remove("nos.txt");
}
else
i=0;
f1=fopen("STUDENT.txt","a+");
f2=fopen("nos.txt","w");
printf("\n\n How many records do you want to enter now ?");
scanf("%d",&j);
for (k=i+1;k<=j+i;k++)
{
x:
system("cls");
printf("\nEnter the registration no: ");
fflush(stdin);     // To prevent infinite Loop....
r=scanf("%d",&s1[k].reg);
if(r==0)
{
	printf("\n\n ERROR !!! You have not entered a number... ");
	getch();
	goto x;
}
for(po=0;po<=i;po++)
{
	fread(&s1,sizeof(s1),1,f1);
	if(s1[k].reg==s1[po].reg)
	{
	printf("\n\n ERROR !!! Registration Number Already Exists... ");
	getch();
	goto x;

	}
}
printf("\nEnter the name: ");
fflush(stdin);
gets(s1[k].name);
r=0;
r=strlen(s1[k].name);
for(o=0;o<r;o++)
{
	if(((s1[k].name[o]>='A')&&(s1[k].name[o]<='Z'))||((s1[k].name[o]>='a')&&(s1[k].name[o]<='z'))||(s1[k].name[o]==' '))
	{
	}
	else
	{
		printf("\n\n ERROR !!! You have entered any other character in name... ");
		getch();
		goto x;
	}
}
printf("\nEnter the gender (M/F) : ");
fflush(stdin);
scanf("%c",&s1[k].gen);
if((s1[k].gen!='M')&&(s1[k].gen!='F'))
{
	printf("\n\n ERROR !!! Enter ony M or F .... ");
	getch();
	goto x;
}
printf("\nEnter the phone number: ");
fflush(stdin);
gets(s1[k].phno);
r=0;
r=strlen(s1[k].phno);
for(o=0;o<r;o++)
{
	if((s1[k].phno[o]>='0')&&(s1[k].phno[o]<='9'))
	{
	}
	else
	{
		printf("\n\n ERROR !!! Enter only Numbers .... ");
		getch();
		goto x;
	}
}
printf("\n\nRecord Entered Successfully........!!!!!!");
fwrite(&s1,sizeof(s1),1,f1);
getch();
}
fprintf(f2,"%d",i+j);
fclose(f2);
fclose(f1);
getch();
}
void searchstudent()
{
	int n1,n=0,c=0;
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r");
	system("cls");
	if((f1!=NULL)&&(f2!=NULL))
	{
	printf("\n\n\n Enter the Registration Number of the Student - ");
	scanf("%d",&n1);
	fscanf(f2,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&s1,sizeof(s1),1,f1);
		if((s1[i].reg)==n1)
		{
			z=0;
			system("cls");
			if(ch=='1')
			{
			r=n1;
			}
			printf("\n\n Student Details - ");
			printf("\n ^^^^^^^ ^^^^^^^");
			printf("\n\n Registration no: %d",s1[i].reg);
			printf("\n\n Name: %s",s1[i].name);
			printf("\n\n Gender: %c",s1[i].gen);
			printf("\n\n Phone number: %s",s1[i].phno);
			printf("\n\n Due payment = %.2f",s1[i].due);
			c++;
		}
	}
	if(c==0)
	{
		printf("\n\n No student exists with this registration number in the record");
		z=1;
	}
	fclose(f1);
	fclose(f2);
	}
	else
	printf("\n\n Student record doesn't exist");
	getch();
}
void updatestudent()
{
	int n1,r,o,n=0,c=0;
	int x;
	system("cls");
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r+");
	if((f1!=NULL)&&(f2!=NULL))
	{
	printf("\n\n\n Enter the Registration Number of the Student whose details you want to update- ");
	scanf("%d",&n1);
	fscanf(f2,"%d",&n);
	for(i=1;i<=n;i++)
	{
		y:
		fread(&s1,sizeof(s1),1,f1);
		if((s1[i].reg)==n1)
		{
			system("cls");
			printf("\n\n Old Details - ");
			printf("\n ^^^ ^^^^^^^");
			printf("\n\n Registration no: %d",s1[i].reg);
			printf("\n\n Name: %s",s1[i].name);
			printf("\n\n Gender: %c",s1[i].gen);
			printf("\n\n Phone number: %s",s1[i].phno);
			x=sizeof(s1);
			fseek(f1,-x,SEEK_CUR);
			printf("\n\n Enter New Details-");
			printf("\n ^^^^^ ^^^ ^^^^^^^");
			printf("\n\n Enter the name: ");
			fflush(stdin);
			gets(s1[i].name);
			r=0;
			r=strlen(s1[i].name);
			for(o=0;o<r;o++)
			{
			if(((s1[i].name[o]>='A')&&(s1[i].name[o]<='Z'))||((s1[i].name[o]>='a')&&(s1[i].name[o]<='z'))||(s1[i].name[o]==' '))
			{
			}
			else
			{
			printf("\n\n ERROR !!! You have entered any other character in name... ");
			getch();
			goto y;
			}
			}
			printf("\n Enter the gender (M/F) : ");
			fflush(stdin);
			scanf("%c",&s1[i].gen);
			if((s1[i].gen!='M')&&(s1[i].gen!='F'))
			{
				printf("\n\n ERROR !!! Enter ony M or F .... ");
				getch();
				goto y;
			}
			printf("\n Enter the phone number: ");
			fflush(stdin);
			gets(s1[i].phno);
			r=0;
			r=strlen(s1[i].phno);
			for(o=0;o<r;o++)
			{
				if((s1[i].phno[o]>='0')&&(s1[i].phno[o]<='9'))
				{
				}
				else
				{
					printf("\n\n ERROR !!! Enter only Numbers .... ");
					getch();
					goto y;
				}
			}
			printf("\n\n Record Updated Successfully........!!!!!!");
			fwrite(&s1,x,1,f1);
			c++;
		}
	}
	if(c==0)
	{
		printf("\n\n No student exists with this registration number in the record");
		getch();
	}
	else
	fclose(f1);
	fclose(f2);
	}else
	printf("\n\n Student record doesn't exist");
	getch();
}
void displaystudent()
{
	int i;
	system("cls");
    f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r");
	if((f1!=NULL)&&(f2!=NULL))
	{
	fscanf(f2,"%d",&n);
	printf("\n\n Student Details - ");
	printf("\n ======= =======");
	gotoxy(2,5);
	printf("Registration");
	gotoxy(2,6);
	printf("^^^^^^^^^^^^");
	gotoxy(2,7);
	printf("Number");
	gotoxy(2,8);
	printf("^^^^^^");
	gotoxy(18,5);
	printf("Name");
	gotoxy(18,6);
	printf("^^^^");
	gotoxy(42,5);
	printf("Gender");
	gotoxy(42,6);
	printf("^^^^^^");
	gotoxy(50,5);
	printf("Phone Number");
	gotoxy(50,6);
	printf("^^^^^ ^^^^^^");
	gotoxy(67,5);
	printf("Due Payment");
	gotoxy(67,6);
	printf("^^^ ^^^^^^^");
	for(i=1;i<=n;i++)
	{
	fread(&s1,sizeof(s1),1,f1);
	gotoxy(2,8+i);
	printf("%d",s1[i].reg);
	gotoxy(18,8+i);
	printf("%s",s1[i].name);
	gotoxy(45,8+i);
	printf("%c",s1[i].gen);
	gotoxy(50,8+i);
	printf("%s",s1[i].phno);
	gotoxy(67,8+i);
	printf("%.2f",s1[i].due);
	}
	fclose(f1);
	fclose(f2);
	}
	else
	printf("\n\n Student record doesn't exist");
	getch();
}
void deletestudent()
{
	int x;
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r");
	system("cls");
	if((f1!=NULL)&&(f2!=NULL))
	{
	printf("\n\nAll Student Data Deleted........");
	x=1;
	}
	else
	printf("\n\n Student record doesn't exist");
	if(x==1)
	{
	fclose(f2);
	fclose(f1);
	remove("STUDENT.txt");
	remove("nos.txt");
	}
	getch();
}
