#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <process.h>
#include <iostream.h>
#include <string.h>
#include <ctype.h>
#include "SIDDARTH/PROJ_RE/P1.CPP"
//#include "SIDDARTH/PROJ/P2_N.CPP"
//#include "SIDDARTH/PROJ/MOUSE.CPP"

void upper(char val[15])
{
	for (int i=0; i<strlen(val); i++)
	{
		val[i] = toupper(val[i]);
	}
}
void dialog(int x1, int y1, int x2, int y2, char title[100])
{
	int midx, midy;
	midx=getmaxx()/2;
	midy=getmaxy()/2;

	setcolor(8);
	setfillstyle(1, 8);
	bar(midx+x1, midy+y1+5, midx+x2+5, midy+y2);
	setfillstyle(1, 7);
	bar(midx+x1, midy+y1, midx+x2, midy+y2);
	rectangle(midx+x1+10, midy-y1, midx+x2-10, midy-y2-20);

	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
	outtextxy(midx, midy-y1+20, title);
}
void main()
{
	int gdriver=DETECT, gmode, col;
	initgraph(&gdriver, &gmode, "../BGI");

	int midx, midy;
	midx=getmaxx()/2;
	midy=getmaxy()/2;

	char p1n[15], p2n[15];
	
	setbkcolor(0);
	setcolor(15);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
	settextjustify(1,1);
	delay(1700);
	cleardevice();
	delay(1200);
	outtextxy(midx, midy, "MENAHI SHAYAN");
	delay(2100);
	cleardevice();
	outtextxy(midx, midy, "OMRAAN ZAFAR");
	delay(1000);
	cleardevice();
	outtextxy(midx, midy, "SIDDARTH MENON");
	delay(1000);
	cleardevice();
	outtextxy(midx, midy-20, "AECS MMPS XI B");
	outtextxy(midx, midy+20, "2015");
	delay(1000);
	cleardevice();

B:  setcolor(15);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
	settextjustify(1,1);

	outtextxy(midx,75, "TIC TAC TOE");

	setfillstyle(1, 15);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
	setcolor(0);
		bar(midx-100, midy-100, midx+100, midy-40);
			outtextxy(midx, midy-75, "1 PLAYER (1)");
		bar(midx-100, midy-20, midx+100, midy+40);
			outtextxy(midx, midy+5, "2 PLAYER (2)");
		bar(midx-100, midy+60, midx+100, midy+120);
			outtextxy(midx, midy+85, "QUIT (ESC)");
	col=1;
L:  	do
	{
		setbkcolor(col);
		delay(800);
		if(col==6) col=1;
		else col++;
	}while(!kbhit());
	char c;
	c= getch();
	switch(c)
	{
		case '1': cleardevice();
				setcolor(15);
				goto G2;
		case '2':

				dialog(-200, 100, 200, -110,"Instructions");
				settextjustify(0, 1);

				outtextxy(midx-175, midy-50,"To play using the keyboard press the");
				outtextxy(midx-175, midy-30,"number of the respective box.");
				outtextxy(midx-175, midy+5,"To play using mouse, click the boxes.");
				outtextxy(midx-175, midy+40,"Press ESC or click \"Menu\" to return here.");
				outtextxy(midx-120, midy+70,"Back(TAB)\t\t\tContinue(ENTER)");
				c=getch();
				switch(c)
				{
					case 9:  cleardevice();
							 goto B;
					case 13: break;
				}
				cleardevice();

				settextjustify(1,1);
				dialog(-160, 65, 160, -75,"Enter Player Names");

				settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
				outtextxy(midx-100, midy-10, "Player X:");
				outtextxy(midx-100, midy+20, "Player O:");

				setfillstyle(1, 1);
				bar(midx-55, midy-15, midx+140, midy+2);
				bar(midx-55, midy+15, midx+140, midy+32);

				gotoxy(35,15);
				cin>>p1n;
				gotoxy(35,17);
				cin>>p2n;

				upper(p1n);
				upper(p2n);
				goto G1;


		case 27 : exit(0);
		default : goto L;
	}
G1:	P1_main(p1n, p2n);
	goto B;
G2:	P2_main();
	goto B;
}