#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include "SIDDARTH/PROJ_RE/MOUSE.CPP"

char b[10], val;
int col=1, moves=0, f_col=6;
int midx, midy;

void draw_grid()
{
	int left, top, right, bottom;
	left=150; right=260; top=75; bottom=185;
	settextstyle(SANS_SERIF_FONT,0,1);
	setcolor(col);
	char label[100];
	int ll=1;
	for(int i=1;i<=3;i++)
	{
		for(int j=1; j<=3; j++)
		{
			if(i==3) rectangle(left, top-3, right, bottom);
			else rectangle(left, top, right, bottom);
			sprintf(label, "%d", ll);
			outtextxy(left+10, top+10, label);
			ll++;
			left=right+5;
			right+=115;
		}
		top+=110+(i*6);
		bottom+=115+(i*4);
		left=150;
		right=260;
	}
}
char validate(char plr)
{
	val=plr;

	//Horizontal
	if(b[1]==plr && b[2]==plr && b[3]==plr);
	else if(b[4]==plr && b[5]==plr && b[6]==plr);
	else if(b[7]==plr && b[8]==plr && b[9]==plr);

	//Vertical
	else if(b[1]==plr && b[4]==plr && b[7]==plr);
	else if(b[2]==plr && b[5]==plr && b[8]==plr);
	else if(b[3]==plr && b[6]==plr && b[9]==plr);

	//Diagonal
	else if(b[1]==plr && b[5]==plr && b[9]==plr);
	else if(b[3]==plr && b[5]==plr && b[7]==plr);

	else val='N';
	return val;
}
void change_color()
{
	if(col==6)
	{
		col=8;
		f_col=7;
	}
	else if(col>=8 && col<15 || col==2)
	{
		f_col=0;
		col++;
	}
	else if(col==15)
	{
		col=1;
		f_col=7;
	}
	else
	{
		col++;
		f_col=7;
	}
	setcolor(col);
	setbkcolor(f_col);
}
void music()
{
	sound(250);
	delay(150);
	nosound();
	delay(100);
	sound(250);
	delay(300);
	sound(500);
	delay(150);
	sound(750);
	delay(400);
	nosound();
}
void keytone()
{
	sound(400);
	delay(150);
	nosound();
}
void reset(char result[100])
{
	//int midx, midy;
	delay(200);
	setfillstyle(1, col);
	bar(midx-101, midy-51, midx+105, midy+55);
	setfillstyle(1, f_col);
	bar(midx-100, midy-50, midx+100, midy+50);
	setcolor(col);
	rectangle(midx-90, midy-40, midx+90, midy+40);
	outtextxy(midx,midy, result);
	//delay(2000);
	music();
	moves=0;
	cleardevice();
	change_color();
}
int defend()
{
	int r_move, fill=0;

	if(::b[1]=='X')
	{
		if(::b[2]=='X')			fill=3;
		else if(::b[5]=='X')	fill=9;
		else if(::b[4]=='X')	fill=7;
		else if(::b[3]=='X')	fill=2;
		else if(::b[9]=='X')	fill=5;
		else if(::b[7]=='X')	fill=4;
		else goto Re;
	}
	if(::b[2]=='X')
	{
		if(::b[1]=='X')			fill=3;
		else if(::b[5]=='X')	fill=8;
		else if(::b[3]=='X')	fill=1;
		else if(::b[8]=='X')	fill=5;
		else goto Re;
	}
	if(::b[3]=='X')
	{
		if(::b[2]=='X')			fill=1;
		else if(::b[5]=='X')	fill=7;
		else if(::b[6]=='X')	fill=9;
		else if(::b[1]=='X')	fill=2;
		else if(::b[7]=='X')	fill=5;
		else if(::b[9]=='X')	fill=6;
		else goto Re;
	}
	if(::b[4]=='X')
	{
		if(::b[1]=='X')			fill=7;
		else if(::b[5]=='X')	fill=6;
		else if(::b[7]=='X')	fill=1;
		else if(::b[6]=='X')	fill=5;
		else goto Re;
	}
	if(::b[5]=='X')
	{
		if(moves==1)
		{
			Re4: int d_rand=rand()%5;
			if(d_rand!=2) fill=(2*d_rand)+1;
			else goto Re4;
		}
		else if(::b[1]=='X')	fill=9;
		else if(::b[2]=='X')	fill=8;
		else if(::b[3]=='X')	fill=7;
		else if(::b[4]=='X')	fill=6;
		else if(::b[6]=='X')	fill=4;
		else if(::b[7]=='X')	fill=3;
		else if(::b[8]=='X')	fill=2;
		else if(::b[9]=='X')	fill=1;
		else goto Re;
	}
	if(::b[6]=='X')
	{
		if(::b[3]=='X')			fill=9;
		else if(::b[5]=='X')	fill=4;
		else if(::b[9]=='X')	fill=3;
		else if(::b[4]=='X')	fill=5;
		else goto Re;
	}
	if(::b[7]=='X')
	{
		if(::b[8]=='X')			fill=9;
		else if(::b[5]=='X')	fill=3;
		else if(::b[4]=='X')	fill=1;
		else if(::b[9]=='X')	fill=8;
		else if(::b[3]=='X')	fill=5;
		else if(::b[1]=='X')	fill=4;
		else goto Re;
	}
	if(::b[8]=='X')
	{
		if(::b[7]=='X')			fill=9;
		else if(::b[5]=='X')	fill=2;
		else if(::b[3]=='X')	fill=1;
		else if(::b[8]=='X')	fill=5;
		else goto Re;
	}
	if(::b[9]=='X')
	{
		if(::b[8]=='X')			fill=7;
		else if(::b[5]=='X')	fill=1;
		else if(::b[6]=='X')	fill=3;
		else if(::b[1]=='X')	fill=5;
		else if(::b[7]=='X')	fill=8;
		else if(::b[3]=='X')	fill=6;
		else goto Re;
	}

	if(::b[fill]=='E') return fill;

	Re: r_move=(rand()%9)+1;
	if(::b[r_move]=='E') return r_move;
	else goto Re;

}
int attack()
{
	int r_move, fill=0;

	if(::b[1]=='O')
	{
		if(::b[2]=='O')		fill=3;
		else if(::b[5]=='O')	fill=9;
		else if(::b[4]=='O')	fill=7;
		else if(::b[3]=='O')	fill=2;
		else if(::b[9]=='O')	fill=5;
		else if(::b[7]=='O')	fill=4;
		//else defend();
	}
	if(::b[2]=='O')
	{
		if(::b[1]=='O')			fill=3;
		else if(::b[5]=='O')	fill=8;
		else if(::b[3]=='O')	fill=1;
		else if(::b[8]=='O')	fill=5;
		//else defend();
	}
	if(::b[3]=='O')
	{
		if(::b[2]=='O')			fill=1;
		else if(::b[5]=='O')	fill=7;
		else if(::b[6]=='O')	fill=9;
		else if(::b[1]=='O')	fill=2;
		else if(::b[7]=='O')	fill=5;
		else if(::b[9]=='O')	fill=6;
		//else defend();
	}
	if(::b[4]=='O')
	{
		if(::b[1]=='O')			fill=7;
		else if(::b[5]=='O')	fill=6;
		else if(::b[7]=='O')	fill=1;
		else if(::b[6]=='O')	fill=5;
		//else defend();
	}
	if(::b[5]=='O')
	{
		if(::b[1]=='O')			fill=9;
		else if(::b[2]=='O')	fill=8;
		else if(::b[3]=='O')	fill=7;
		else if(::b[4]=='O')	fill=6;
		else if(::b[6]=='O')	fill=4;
		else if(::b[7]=='O')	fill=3;
		else if(::b[8]=='O')	fill=2;
		else if(::b[9]=='O')	fill=1;
		//else defend();
	}
	if(::b[6]=='O')
	{
		if(::b[3]=='O')			fill=9;
		else if(::b[5]=='O')	fill=4;
		else if(::b[9]=='O')	fill=3;
		else if(::b[4]=='O')	fill=5;
		//else defend();
	}
	if(::b[7]=='O')
	{
		if(::b[8]=='O')			fill=9;
		else if(::b[5]=='O')	fill=3;
		else if(::b[4]=='O')	fill=1;
		else if(::b[9]=='O')	fill=8;
		else if(::b[3]=='O')	fill=5;
		else if(::b[1]=='O')	fill=4;
		//else defend();
	}
	if(::b[8]=='O')
	{
		if(::b[7]=='O')			fill=9;
		else if(::b[5]=='O')	fill=2;
		else if(::b[3]=='O')	fill=1;
		else if(::b[8]=='O')	fill=5;
		//else defend();
	}
	if(::b[9]=='O')
	{
		if(::b[8]=='O')			fill=7;
		else if(::b[5]=='O')	fill=1;
		else if(::b[6]=='O')	fill=3;
		else if(::b[1]=='O')	fill=5;
		else if(::b[7]=='O')	fill=8;
		else if(::b[3]=='O')	fill=6;
		//else defend();
	}

	if(::b[fill]=='E') return fill;
	else defend();
}
void P2_main()
{
	randomize();
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "../BGI");


	midx=getmaxx()/2;
	midy=getmaxy()/2;

	int x,y,cl,a,b;
	a=midx;
	b=midy;
	setposi(a,b);
	callmouse();

	int p1=0, p2=0, move=2, m_func;
	char p1_card[30], p2_card[30], _p1_card[5], _p2_card[5], input;

	f_col=7;
	setbkcolor(f_col);

	settextjustify(CENTER_TEXT, CENTER_TEXT);

	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setcolor(col);

C:	sprintf(p1_card, "YOU: %d", p1);
	sprintf(p2_card, "COMP: %d", p2);
	outtextxy(80, 20, p1_card);
	outtextxy(getmaxx()-90, 20, p2_card);
	outtextxy(midx, 20, "MENU");

	draw_grid();
	for(int i=1; i<=9; i++)
	{
		::b[i]='E';
	}

	outtextxy(midx-50, (midy*2)-30, "CHANCE:");

L:	if(move%2==0)
	{
		setfillstyle(1,col);
		bar(midx+5, (midy*2)-40, midx+25, (midy*2)-15);
		setcolor(f_col);
		outtextxy(midx+15, (midy*2)-30, "X");
		setfillstyle(1,f_col);
		bar(midx+40, (midy*2)-40, midx+60, (midy*2)-15);
		setcolor(col);
		outtextxy(midx+50, (midy*2)-30, "O");
		m_func=mou_main();
		keytone();
	}
	else
	{
		setfillstyle(1,f_col);
		bar(midx+5, (midy*2)-40, midx+25, (midy*2)-15);
		setcolor(col);
		outtextxy(midx+15, (midy*2)-30, "X");
		setfillstyle(1,col);
		bar(midx+40, (midy*2)-40, midx+60, (midy*2)-15);
		setcolor(f_col);
		outtextxy(midx+50, (midy*2)-30, "O");
		delay(200);
		m_func=attack();
	}

	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 10);
	setbkcolor(f_col);
	setcolor(col);

	//char m_x[50], m_y[50];
	//settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

	//a=x; b=y;
	//setposi(a,b);

	switch(m_func)
	{
		case 1: goto M1;
		case 2: goto M2;
		case 3: goto M3;
		case 4: goto M4;
		case 5: goto M5;
		case 6: goto M6;
		case 7: goto M7;
		case 8: goto M8;
		case 9: goto M9;
		case 0: cleardevice(); hidemouse(); return;
	}

In:	input=getch();
	switch(input)
	{
		case '1': M1: if(::b[1]=='E')
						{

							if(move%2==0)
							{
								outtextxy(213,108, "X");
								move++;
								moves++;
								::b[1]='X';
								break;
							}
							else
							{
								outtextxy(213,108, "O");
								move++;
								moves++;
								::b[1]='O';
								break;
							}
						}
						else break;
		case '2':M2:  if(::b[2]=='E')
						{

							if(move%2==0)
							{
								outtextxy(midx+7,108, "X");
								move++;
								moves++;
								::b[2]='X';
								break;
							}
							else
							{
								outtextxy(midx+7,108, "O");
								move++;
								moves++;
								::b[2]='O';
								break;
							}
						}
						else break;
		case '3': M3: if(::b[3]=='E')
						{

							if(move%2==0)
							{
								outtextxy(440,108, "X");
								move++;
								moves++;
								::b[3]='X';
								break;
							}
							else
							{
								outtextxy(440,108, "O");
								move++;
								moves++;
								::b[3]='O';
								break;
							}
						}
						else break;
		case '4':M4:  if(::b[4]=='E')
						{

							if(move%2==0)
							{
								outtextxy(213,midy-15, "X");
								move++;
								moves++;
								::b[4]='X';
								break;
							}
							else
							{
								outtextxy(213,midy-15, "O");
								move++;
								moves++;
								::b[4]='O';
								break;
							}
						}
						else break;
		case '5': M5: if(::b[5]=='E')
						{

							if(move%2==0)
							{
								outtextxy(midx+7,midy-15, "X");
								move++;
								moves++;
								::b[5]='X';
								break;
							}
							else
							{
								outtextxy(midx+7,midy-15, "O");
								move++;
								moves++;
								::b[5]='O';
								break;
							}
						}
						else break;
		case '6': M6: if(::b[6]=='E')
						{

							if(move%2==0)
							{
								outtextxy(440,midy-15, "X");
								move++;
								moves++;
								::b[6]='X';
								break;
							}
							else
							{
								outtextxy(440,midy-15, "O");
								move++;
								moves++;
								::b[6]='O';
								break;
							}
						}
						else break;
		case '7': M7: if(::b[7]=='E')
						{

							if(move%2==0)
							{
								outtextxy(213,346, "X");
								move++;
								moves++;
								::b[7]='X';
								break;
							}
							else
							{
								outtextxy(213,346, "O");
								move++;
								moves++;
								::b[7]='O';
								break;
							}
						}
						else break;
		case '8':M8:  if(::b[8]=='E')
						{

							if(move%2==0)
							{
								outtextxy(midx+7,346, "X");
								move++;
								moves++;
								::b[8]='X';
								break;
							}
							else
							{
								outtextxy(midx+7,346, "O");
								move++;
								moves++;
								::b[8]='O';
								break;
							}
						}
						else break;
		case '9':M9:  if(::b[9]=='E')
						{

							if(move%2==0)
							{
								outtextxy(440,346, "X");
								move++;
								moves++;
								::b[9]='X';
								break;
							}
							else
							{
								outtextxy(440,346, "O");
								move++;
								moves++;
								::b[9]='O';
								break;
							}
						}
						else break;
		case 27: cleardevice(); return;
	}
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	validate('X');
	if(val=='X')
	{
		p1++;
		reset("X Wins.");
		goto C;
	}
	else	validate('O');
	if(val=='O')
	{
		p2++;
		reset("O Wins.");
		goto C;
	}
	else if(moves>=9)
	{
		reset("Draw.");
		goto C;
	}
	else goto L;
}
void P1_main(char p1n[15], char p2n[15])
{
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode, "../BGI");


	midx=getmaxx()/2;
	midy=getmaxy()/2;

	int x,y,cl,a,b;
	a=midx;
	b=midy;
	setposi(a,b);
	callmouse();

	int p1=0, p2=0, move=2;
	char p1_card[30], p2_card[30], _p1_card[5], _p2_card[5], input;

	f_col=7;
	setbkcolor(f_col);

	settextjustify(CENTER_TEXT, CENTER_TEXT);

	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setcolor(col);

    /*	draw_box();
	setfillstyle(1, f_col);
	bar(midx+70, midy+50, midx-70, midy+30);  */

C:	sprintf(p1_card, "%s", p1n);
	sprintf(p2_card, "%s", p2n);
	sprintf(_p1_card, ": %d", p1);
	sprintf(_p2_card, ": %d", p2);
	outtextxy(80, 20, p1_card);
	outtextxy(80+textwidth(p1_card), 20, _p1_card);
	outtextxy(getmaxx()-90, 20, p2_card);
	outtextxy(getmaxx()-90+textwidth(p2_card), 20, _p2_card);
	outtextxy(midx, 20, "MENU");

	draw_grid();
	for(int i=1; i<=9; i++)
	{
		::b[i]='E';
	}

	outtextxy(midx-50, (midy*2)-30, "CHANCE:");

L:	if(move%2==0)
	{
		setfillstyle(1,col);
		bar(midx+5, (midy*2)-40, midx+25, (midy*2)-15);
		setcolor(f_col);
		outtextxy(midx+15, (midy*2)-30, "X");
		setfillstyle(1,f_col);
		bar(midx+40, (midy*2)-40, midx+60, (midy*2)-15);
		setcolor(col);
		outtextxy(midx+50, (midy*2)-30, "O");
	}
	else
	{
		setfillstyle(1,f_col);
		bar(midx+5, (midy*2)-40, midx+25, (midy*2)-15);
		setcolor(col);
		outtextxy(midx+15, (midy*2)-30, "X");
		setfillstyle(1,col);
		bar(midx+40, (midy*2)-40, midx+60, (midy*2)-15);
		setcolor(f_col);
		outtextxy(midx+50, (midy*2)-30, "O");
	}

	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 10);
	setbkcolor(f_col);
	setcolor(col);

	//char m_x[50], m_y[50];
	//settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

   /*	do
	{
		mouseposi(x,y,cl);

		if(cl==1)
		{
			if(x<=(midx+25) && x>=(midx-25) && y<=25 && y>=0)
			{
				exit(0);
			}
			else if(x<=260 && x>=150 && y<=180 && y>=75)
			{
				goto M1;
			}
			else if(x<=375 && x>=265 && y<=180 && y>=75)
			{
				goto M2;
			}
			else if(x<=490 && x>=380 && y<=180 && y>=75)
			{
				goto M3;
			}
			else if(x<=260 && x>=150 && y<=300 && y>=190)
			{
				goto M4;
			}
			else if(x<=375 && x>=265 && y<=300 && y>=190)
			{
				goto M5;
			}
			else if(x<=490 && x>=380 && y<=300 && y>=190)
			{
				goto M6;
			}
			else if(x<=260 && x>=150 && y<=430 && y>=310)
			{
				goto M7;
			}
			else if(x<=375 && x>=265 && y<=430 && y>=310)
			{
				goto M8;
			}
			else if(x<=490 && x>=380 && y<=430 && y>=310)
			{
				goto M9;
			}
		}
	}while(!kbhit()); */
	//a=x; b=y;
	//setposi(a,b);
	int m_func=mou_main();
	switch(m_func)
	{
		case 1: goto M1;
		case 2: goto M2;
		case 3: goto M3;
		case 4: goto M4;
		case 5: goto M5;
		case 6: goto M6;
		case 7: goto M7;
		case 8: goto M8;
		case 9: goto M9;
		case 0: cleardevice(); hidemouse(); return;
	}

In:	input=getch();
    /*	if(input!=27)
	{
		if(::b[input]=='E')
		{
			move++;
			moves++;
			keytone();

			if(move%2==0)
			{
				::b[input]='X';
				switch(input)
				{
					case '1':	outtextxy(213,108, "X");	break;
					case '2':	outtextxy(midx+7,108, "X");	break;
					case '3':	outtextxy(440,108, "X");	break;
					case '4':	outtextxy(213,midy-15, "X");	break;
					case '5':	outtextxy(midx+7,midy-15, "X");	break;
					case '6':	outtextxy(440,midy-15, "X");	break;
					case '7':	outtextxy(213,346, "X");	break;
					case '8':	outtextxy(midx+7,346, "X");	break;
					case '9':	outtextxy(440,346, "X");	break;
				}
			}
			else
			{
				::b[input]='O';
				switch(input)
				{
					case '1':	outtextxy(213,108, "O");	break;
					case '2':	outtextxy(midx+7,108, "O");	break;
					case '3':	outtextxy(440,108, "O");	break;
					case '4':	outtextxy(213,midy-15, "O");	break;
					case '5':	outtextxy(midx+7,midy-15, "O");	break;
					case '6':	outtextxy(440,midy-15, "O");	break;
					case '7':	outtextxy(213,346, "O");	break;
					case '8':	outtextxy(midx+7,346, "O");	break;
					case '9':	outtextxy(440,346, "O");	break;
				}
			}
		}
		else goto In;
	}
	else
	{
		cleardevice();
		return;
	}
	
	*/switch(input)
	{
		case '1': M1: if(::b[1]=='E')
						{
							keytone();
							if(move%2==0)
							{
								outtextxy(213,108, "X");
								move++;
								moves++;
								::b[1]='X';
								break;
							}
							else
							{
								outtextxy(213,108, "O");
								move++;
								moves++;
								::b[1]='O';
								break;
							}
						}
						else break;
		case '2':M2:  if(::b[2]=='E')
						{
							keytone();
							if(move%2==0)
							{
								outtextxy(midx+7,108, "X");
								move++;
								moves++;
								::b[2]='X';
								break;
							}
							else
							{
								outtextxy(midx+7,108, "O");
								move++;
								moves++;
								::b[2]='O';
								break;
							}
						}
						else break;
		case '3': M3: if(::b[3]=='E')
						{
							keytone();
							if(move%2==0)
							{
								outtextxy(440,108, "X");
								move++;
								moves++;
								::b[3]='X';
								break;
							}
							else
							{
								outtextxy(440,108, "O");
								move++;
								moves++;
								::b[3]='O';
								break;
							}
						}
						else break;
		case '4':M4:  if(::b[4]=='E')
						{
							keytone();
							if(move%2==0)
							{
								outtextxy(213,midy-15, "X");
								move++;
								moves++;
								::b[4]='X';
								break;
							}
							else
							{
								outtextxy(213,midy-15, "O");
								move++;
								moves++;
								::b[4]='O';
								break;
							}
						}
						else break;
		case '5': M5: if(::b[5]=='E')
						{
							keytone();
							if(move%2==0)
							{
								outtextxy(midx+7,midy-15, "X");
								move++;
								moves++;
								::b[5]='X';
								break;
							}
							else
							{
								outtextxy(midx+7,midy-15, "O");
								move++;
								moves++;
								::b[5]='O';
								break;
							}
						}
						else break;
		case '6': M6: if(::b[6]=='E')
						{
							keytone();
							if(move%2==0)
							{
								outtextxy(440,midy-15, "X");
								move++;
								moves++;
								::b[6]='X';
								break;
							}
							else
							{
								outtextxy(440,midy-15, "O");
								move++;
								moves++;
								::b[6]='O';
								break;
							}
						}
						else break;
		case '7': M7: if(::b[7]=='E')
						{
							keytone();
							if(move%2==0)
							{
								outtextxy(213,346, "X");
								move++;
								moves++;
								::b[7]='X';
								break;
							}
							else
							{
								outtextxy(213,346, "O");
								move++;
								moves++;
								::b[7]='O';
								break;
							}
						}
						else break;
		case '8':M8:  if(::b[8]=='E')
						{
							keytone();
							if(move%2==0)
							{
								outtextxy(midx+7,346, "X");
								move++;
								moves++;
								::b[8]='X';
								break;
							}
							else
							{
								outtextxy(midx+7,346, "O");
								move++;
								moves++;
								::b[8]='O';
								break;
							}
						}
						else break;
		case '9':M9:  if(::b[9]=='E')
						{
							keytone();
							if(move%2==0)
							{
								outtextxy(440,346, "X");
								move++;
								moves++;
								::b[9]='X';
								break;
							}
							else
							{
								outtextxy(440,346, "O");
								move++;
								moves++;
								::b[9]='O';
								break;
							}
						}
						else break;
		case 27: cleardevice(); return;
	}
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	validate('X');
	if(val=='X')
	{
		p1++;
		reset("X Wins.");
		goto C;
	}
	else	validate('O');
	if(val=='O')
	{
		p2++;
		reset("O Wins.");
		goto C;
	}
	else if(moves>=9)
	{
		reset("Draw.");
		goto C;
	}
	else goto L;
}