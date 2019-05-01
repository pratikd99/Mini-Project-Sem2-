             SINE and COSINE SERIES

#include <iostream.h>
#include <conio.h>
#include <math.h>
float a,l,d,sum=0;

class inherit                   //Inheriting the Class
{
 public :
 void input_angle();
 void input_limit();
 void output_values();
 float conversion();
 int factorial(int n);
};

int inherit::factorial(int n)  //Assigning Factorial Function
  {
   int i,f=1;
   for(i=1;i<=n;i++)
    {
      f=f*i;
    }
   return f;
  }

class sine: public inherit
   {
     public:
     float b,c;
     void processing();

   };

void inherit::input_angle()            //Taking Inputs
   {
     cout<<"Enter any angle in degrees\n";
     cin>>a;
   }

void inherit::input_limit()           //Taking Limits for Accuracy
   {
     cout<<"Enter limit value for accuracy\n";
     cin>>l;
   }

float inherit::conversion ()    //Converting Angles in degrees to Radians
   {
     const float pi = 3.14;
     d=a*(pi/180);
     return d;
   }

void sine::processing ()
   {
    int i,j;
    for(i=1,j=2;i<=2*l;i=i+2,j++)
      {
       b=pow(d,i)/factorial(i);
       c=b*pow(-1,j);
       sum=sum+c;
      }
   }

void inherit::output_values()          //Printing Outputs
    {
     cout<<"The sine of given angle is: ";
     cout<<sum;
    }

class cosine : public inherit          //Assigning another Class
   {
     public:
       float b,c;
       void processing();

   };

void cosine::processing ()
  {
   int i,j;
   for(i=0,j=2;i<=2*l;i=i+2,j++)
     {
      b=pow(d,i)/factorial(i);
      c=b*pow(-1,j);
      sum=sum+c;
     }
   }


void main()
  {
   int a;
   clrscr();
     cout<<"Which value of given angle is required.."<<endl;
     cout<<"Press 1 for sine"<<endl;
     cout<<"Press 2 for cosine"<<endl;
   cin>>a;
     if (a==1)
       {
	sine m;                          //Calling sine class
	inherit n;
	n.input_angle();
	n.conversion();
	n.input_limit();
	m.processing();
	n.output_values();
       }
     if (a==2)
       {
	cosine m;                       //Calling cosine class
	inherit n;
	n.input_angle();
	n.conversion();
	n.input_limit();
	m.processing();
	n.output_values();
       }
     getch();
 }





 /*
 Output:-
1) Which value of given angle is required..
   Press 1 for sine
   Press 2 for cosine
   1
   Enter any angle in degrees
   60
   Enter limit value for accuracy
   4
   The sine of given angle is: 0.865756

2) Which value of given angle is required..
   Press 1 for sine
   Press 2 for cosine
   2
   Enter any angle in degrees
   45
   Enter limit value for accuracy
   4
   The cosine of given angle is: 0.707379
*/
