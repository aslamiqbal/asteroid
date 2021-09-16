/*This game is free for the C.S students of GIIT. Presented by IQBAL(C.S 2nd Bath)*/
/*Create date 2004-12-17*/
#include<stdlib.h>
#include<graphics.h>
#include <time.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define rx ran%640
#define ry ran%480
#define mxx x*2
#define mxy y*2
#define creatcircle for(i=1;i<20;i++){if(i<7) setcolor(4);else setcolor(5);circle(c,d,i);}
#define Presentation printf("\t\tWarning........");settextjustify(10,CENTER_TEXT);settextstyle(1/*style*/, HORIZ_DIR,3/*size*/);setcolor(4);outtextxy(50,y, "The Game is only for the student of GIIT."); getch(); //return 0;
gfont(int x,int y);
void main()
{  void *img;
int gd=DETECT,gm,x,y,i,c,d,k,life,ran,tmp,tmp2;
	char ch,scr;
	clock_t start, end;
char *fname[]={"Are you sure? Press Escape Again to Quit.",
	" Press 'H' for help.",
	" Pressing 'F1' Key you can also see the Instruction.",
	" Do not touch anithing without RED.",
	" Press any key to continue...",
	"Your score",
	"Game over.", //6
	"THE GAME IS PRESENTED BY..",
	"IQBAL. GIIT."};      //8
	int p[55],q[55],r,j,an,anm,gol,al; //enimy var
	long int s;
	int cl,cr,dd,du,exit0=10,mintm=0;
 clrscr();    randomize();
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");    //setbkcolor(1);
x=getmaxx()/2;
y=getmaxy()/2; Presentation;
 gfont(x,y);
cleardevice();
settextjustify(CENTER_TEXT, CENTER_TEXT);
for(j=1;j<5;j++) {
settextstyle(1/*style*/, HORIZ_DIR, 2/*size*/);
setcolor(j);
	 outtextxy(x,y, fname[j]);
	 y+=25;
	 }
ch=getche();
cleardevice();
if(ch=='h'||ch=='H')
{printf("\n\n\n Press 4 arrows to move at dirrection.\
 Del to Left & Down.\n Page Down to Right & Down.\n Escape two time to Quit.\
\n Press SPACE For PAUSE.\n Your mission is to hunt RED CIRCLE.\n");
getch();
cleardevice();
}
l2:
c=getmaxx()/2;
d=getmaxy()/2;
k=5;
s=0;
an=25;  anm=an-1-an/3;
gol=10;
life=8;
y=d=getmaxy()/2;
for(j=1;j<an;j++)       //enimy var array initialization
{
ran=rand();//ran=ran%640;
p[j]=rx-x;
ran=rand();//ran=ran%480;
q[j]=ry-y;
}
start = clock();
end = clock();
			// Main prg//

while(ch!=27) // Main loop
{ if(ch!=0)
{ ran=random(14);

	  //if(i==7)i=15;
	if(c>mxx-20)c=mxx-20;
	if(c<20)c=20; //retur X axis
	if(d>mxy-20)d=mxy-20;
	if(d<20)d=20; //return Y axis
	creatcircle;
}	//printf("%d %c.",ch,ch);
if(k<10)
if(kbhit())
k++; else if(k>0) k--;
while(!kbhit())  //enemy loop
 {
 gotoxy(5,1);
printf("SCORE %2ld",s*23);
gotoxy(5,2);
printf(" LIFE  %d",life-1);
gotoxy(68,2);
printf("TIME:%2d:%.2f",mintm ,(end - start) / CLK_TCK);
if((end-start)/CLK_TCK>=60)
{
start = clock();
end = clock();
mintm++;
}
 end = clock();   // time
anm=an-1-an/3;
 if(life>0)
 for(j=1;j<an;j++)
{
for(r=1;r<gol;r++)
	{
	setcolor(j+1);
	if(j%3==0)            //red
	  {
		setcolor(4);
		gol=7;
		r++;
	  }
	else gol=5;
	circle(p[j],q[j],r);	//printf("%d",p[j]);
	 }
 if(p[j]<-5&&anm>0)
 anm--;
 }
gotoxy(5,3);
printf(" ANIMY %d",anm);
	delay(10);//creat animy  end
if(anm<=0&&s*23>2000)
{
outtextxy(x,y,"YOU WIN");
delay(5111);
goto l;
}
if(ch==' ')     //pause
{gotoxy(35,10);printf("PAUSED.");sound(856);delay(200);nosound();
getch();sound(1256);delay(200);nosound();cleardevice(); //pause
}
 for(j=1;j<an;j++)
{  setcolor(0);
for(r=1;r<gol;r++)   //clear
	{
	circle(p[j],q[j],r);
	}
	p[j]+=2;       //animy move    1
	q[j]+=1;
	if(j%3==0)
	{
	p[j]+=1;
	if((j+1)%5==0)
	q[j]-=1;
	}
	if((j+1)%5==0)
	q[j]-=1;         //animy move  0
} //array
cl=c-20;
cr=c+20;
dd=d+20;
du=d-20;
for(j=1;j<an;j++)
if(cl<=(p[j])&&cr>=(p[j])&&du<=(q[j])&&dd>=(q[j]))
{  	creatcircle;
	ran=random(640);
	 if(j%3==0)
	{ p[j+1]=-x*8;
	p[j-1]=-x*8;
	p[j]+=320-ran;
	q[j]+=320-ran;
	if(j==3)
	p[1]=-5*x;
	sound(756);
	delay(150);
	nosound();
	s+=1;
	} //condition
	else
	{ p[j]+=65;
	sound(1356);
	delay(200);
	nosound();
	life--;
	}
if(life<=0)
	{  cleardevice();

	settextjustify(CENTER_TEXT, CENTER_TEXT);
settextstyle(1/*style*/, HORIZ_DIR, 8/*size*/);
setcolor(12);    //game over
	 outtextxy(x,y-100, fname[6]);

	 for(life=25;life>=15;life--)
	{
	sound(life*100-956);
	delay(200);
	nosound();
	}
	life=0;
gotoxy(5,2);
printf("NO LIFE...");
	delay(555);
	goto l;
	}
}  // con end
for(j=1;j<an;j++)    // move anm
{   ran=random(100);
	  if(p[j]>=mxx)
	  {
	  p[j]=50-ran;	q[j]+=(ran%51);
	  }

if(q[j]>=480)
q[j]=50-ran;
	if(q[j]<0)
	{
	  q[j]=480;
	  p[j]+=100+ran;
	}
 //extr edit
	if(j%7==0)
	{
	p[j]+=4;
	q[j]-=3;
	}
//ran=random(3);p[j]+=ran-2;q[j]+=ran-2;
}     //
 //condition
				} //while  //animy loop 0
if(ch==0)exit0=0;  // ALT F4 func key

ch=getche();   // main input
if(ch==108) exit(1);

if(exit0==0&&ch==107)
ch=27;
if(ch==0) //printf("\n\t%d&%c",ch,ch);
cleardevice();  //clear old graph
if(ch=='H')d=d-k;
if(ch=='K'||ch=='S')c=c-k;
if(ch=='M'||ch==81)c=c+k;
if(ch=='P'||ch=='S'||ch==81)d=d+k;
if(ch==27&&life>0)
	{
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(1/*style*/, HORIZ_DIR, 2/*size*/);
	setcolor(10);
	 outtextxy(x,y, fname[0]);
	//printf("\nAre you sure? \n\t\tPress Escape Again to Quit.");
	ch=getche(); //wait
	cleardevice();
	}
if(ch=='i')      //cheat 1
{
s+=100;
}  //
if(ch=='x')
k--;
if(ch==19)
k++;
if(ch==12)
life++;
	//cheat 0
	if(ch==59) //F1
	 {
	cleardevice();  gotoxy(5,5);
printf("\n\n\n Press 4 arrows to move at dirrection.\
 Del to Left & Down.\n Page Down to Right & Down.\n Escape two time to Quit.\
\n Press SPACE For PAUSE.\n Your mission is to hunt RED CIRCLE.\n");
	getch();
	cleardevice();
		}
}     // main loop;;;    Press Esc to quit.
l:
cleardevice();
gotoxy(32,5);
printf("Your score %ld.\n",s*23);
delay(2222);
delay(999);
setbkcolor(9);
settextjustify(CENTER_TEXT, CENTER_TEXT);
settextstyle(1/*style*/, HORIZ_DIR, 2/*size*/);
setcolor(14);
		outtextxy(x,100, fname[7]);
		delay(555);
		setcolor(13);
		setbkcolor(1);
		outtextxy(x,y-100, fname[8]);
		delay(1999);
cleardevice();
					l3:  //exit0
gotoxy(30,13);
printf("DO YOU WANT PLAY AGAIN?");
gotoxy(26,14);
printf("PRESS 'Y' TO PLAY OR 'N' TO EXIT.");
ch=getche();
	if(ch=='y'||ch=='Y')
	{
	cleardevice();
	setbkcolor(0);
	goto l2;
	}
	else if(ch=='n'||ch=='N'||ch==27)
closegraph();
else
goto l3;
}
//******************/FINISH MAIN FUNCTION//******************
gfont(int x,int y)
{
char *fname[] = { "ASLAM IQBAL.","GIIT.","LODDING PLEASE WAIT.","."};
	char c;
	int i,mx,my,clr,j;
  mx=0; my=0; i=0;  clr=1;
  settextjustify(CENTER_TEXT, CENTER_TEXT);

	while(!kbhit())
	{
	 cleardevice();
	 settextstyle(1/*style*/, HORIZ_DIR,5/*size*/);  /* output a message */
	 setcolor(10);
	 outtextxy(x,y, fname[1]);
	 setcolor(clr);
	 outtextxy(mx,my, fname[0]);
	 setcolor(clr+1);
	 outtextxy(x*2-mx,y*2-my, fname[0]);
	 setcolor(clr+2);
	 outtextxy(mx,y, fname[0]);
	 setcolor(clr+4);
	 outtextxy(x*2-mx,y, fname[0]);
	 if(i>160)
	 {mx=0;my=0;i=0;clr++;}
	 mx+=4; my+=3;
	 i++;
	 delay(15);
	 if(clr>=11)
	 clr=1;
	 if((x*2-mx)>=310&&(x*2-mx)<=311)
	 {
	 delay(333);
	 cleardevice();
	 delay(333);
	 }
	}  //
c=getche();
if(c==108)return 0;
cleardevice();
printf("\n\n\n Press 4 arrows to move at dirrection.\
 Del to Left & Down.\n Page Down to Right & Down.\n Escape two time to Quit.\
\n Press SPACE For PAUSE.\n Your mission is to hunt RED CIRCLE.\n");
settextjustify(10, CENTER_TEXT+50);
settextstyle(1/*style*/, HORIZ_DIR,3/*size*/);
setcolor(4);
outtextxy(x-50,y, fname[2]);
for(mx=50;mx<60;mx++)
{
outtextxy(x+75,y, fname[3]);
delay(9*mx);
x+=10;
}
l:
while(!kbhit())
{
	cleardevice();
	delay(99);
	gotoxy(30,20);
	printf("Press ENTER to continue...");
	delay(555);
}
	c=getche();
	if(c=='\r')
	return 0;
else
	goto l;
}