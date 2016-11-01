#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
union REGS in,out;

int callmouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	return 1;
}
int hidemouse()
{
	in.x.ax=2;
	int86(51,&in,&out);
	return 0;
}
void mouseposi(int &xpos,int &ypos,int &click)
{
	in.x.ax=3;
	int86(51,&in,&out);
	click=out.x.bx;
	xpos=out.x.cx;
	ypos=out.x.dx;
}

void setposi(int &xpos,int &ypos)
{
	in.x.ax=4;
	in.x.cx=xpos;
	in.x.dx=ypos;
	int86(51,&in,&out);
}

int mou_main()
{
	int x,y,cl;//,a,b;
	
	int midx, midy;
	midx=getmaxx()/2;
	midy=getmaxy()/2;
	
	//a=midx;
	//b=midy;
	//setposi(a,b);
	callmouse();
				 
	do
	{
		mouseposi(x,y,cl);

		if(cl==1)
		{
			if(x<=(midx+25) && x>=(midx-25) && y<=25 && y>=0)
			{
				return 0;
			}
			else if(x<=260 && x>=150 && y<=180 && y>=75)
			{
				return 1;
			}
			else if(x<=375 && x>=265 && y<=180 && y>=75)
			{
				return 2;
			}
			else if(x<=490 && x>=380 && y<=180 && y>=75)
			{
				return 3;
			}
			else if(x<=260 && x>=150 && y<=300 && y>=190)
			{
				return 4;
			}
			else if(x<=375 && x>=265 && y<=300 && y>=190)
			{
				return 5;
			}
			else if(x<=490 && x>=380 && y<=300 && y>=190)
			{
				return 6;
			}
			else if(x<=260 && x>=150 && y<=430 && y>=310)
			{
				return 7;
			}
			else if(x<=375 && x>=265 && y<=430 && y>=310)
			{
				return 8;
			}
			else if(x<=490 && x>=380 && y<=430 && y>=310)
			{
				return 9;
			}
		}
	}while(!kbhit());
	getch();

	return -1;
}
