#include <cstdlib>
#include <iostream>
#include <graphics.h> 
#include <time.h>
#include <conio.h>
using namespace std;

void tayeen_adad(int a,int b,int x,int y,int vx)
{
    int bar1,bar2,ballhorizantal,ballvertical,balldirection;
    if(a+40<225)
          bar1=0;
    else if(a+40<350)
          bar1=1;
    else if(a+40<475)
          bar1=2;
    else
          bar1=3;
        
    if(b+40<225)
           bar2=0;
    else if(b+40<350)
           bar2=1;
    else if(b+40<475)
           bar2=2;
    else
           bar2=3;
       
    if(x<225)
          ballhorizantal=0;
    else if(x<350)
          ballhorizantal=1;
    else if(x<475)
          ballhorizantal=2;
    else                          
          ballhorizantal=3;
              
    if(y<200)
          ballvertical=0;
    else if(y<300)
          ballvertical=1;
    else if(y<400)
          ballvertical=2;
    else
          ballvertical=3;         
    
    if(vx>0)
         balldirection=1;
    else 
         balldirection=0;

    int araye[5];
    araye[0]=bar1;
    araye[1]=bar2;
    araye[2]=ballhorizantal;
    araye[3]=ballvertical;
    araye[4]=balldirection;
    int mabna10;
    mabna10=(araye[0]+(araye[1]*4)+(araye[2]*4*4)+(araye[3]*4*4*4)+(araye[4]*256));
    // cout<<bar1<<"  "<<bar2<<"   "<<ballhorizantal<<"   "<<ballvertical<<"   "<<balldirection<<"   "<<mabna10<<endl;
}
int main(int argc, char *argv[])
{   
    srand(time(0)); 
	cout<<"If you want to play by time enter 1"<<endl<<"If you want to play by bumps enter 2"<<endl<<"If you want to play no walls enter 3"<<endl<<"If you want to play by score enter 4"<<endl<<"If you want to play endless enter 5"<<endl;  
	int h;
	for(;;)
	{
		cin>>h;
		if(h==1)
		{
            int r1=rand()%12,r2=rand()%16;  
			cout<<"Enter the game by pressing enter"<<endl;
			cout<<"Survive for 30 seconds to win!"<<endl;
			delay(2000);
			initwindow(700,700);	
			setfillstyle(0,15);
			floodfill(1,1,15);	
            setcolor(11);
			line(100,1,100,600);
			line(600,1,600,600);
			setcolor(2);
			line(100,600,600,600);
			setcolor(3);
			char ch=0;
			double x=310,y=200,z=590,t=580,vx=0,vy=0,g=0.02,a=100,b=560;
			bool flag=false;
			setcolor(14);
			setfillstyle(1,3);
			fillellipse(x,y,10,10);
			setfillstyle(1,10);
			bar(a,500,a+40,505);
			setfillstyle(1,10);
			bar(b,100,b+40,95);
			while(ch!=13)
				ch=getch();
			float da=0.8,db=-0.8;
			int start=time(0);
		    bool f=false;
		    while(f==false)
			{
				setcolor(11);
				line(100,1,100,600);
				line(600,1,600,600);
				setcolor(2);
				line(100,600,600,600);
			    setcolor(0);
				setfillstyle(1,0);
				fillellipse(x,y,23,23);
				setcolor(14);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,10);
				bar(a,500,a+40,505);	
			   	setfillstyle(1,10);
			    bar(b,100,b+40,95);
				delay(7);
				tayeen_adad(a,b,x,y,vx);
				if(kbhit())
				{
					char c=getch();
					if(c=='a' || c==75)
						vx-=1.1;
					if(c=='d' || c==77)
						vx+=1.1;
				}
				setcolor(0);
				setfillstyle(1,0);
				rectangle(a-1,499,a+41,506);
			    setfillstyle(1,0);
				rectangle(b-1,101,b+41,94);
				vy+=g;
				vx*=0.995;
				if(x>=z)
				{
					vx=-vx;
				}
				if(x<110)
				{
					vx=-vx;
				}
				if(y>=z)
				{
					vy=-vy;
				}
				x+=vx;
				y+=vy;
				if(x>=a-10 && x<a+50 && vy>0 && y>=490)
				{
					vy=-4.2;
				}
				if(x>=b-10 && x<b+50 && vy<0 && y<=110)
				{
			        vy=0.8;
		        }
		        if(vx>7)
                    vx=7;
                int now1=time(0);
			    if(y>=515 || y<=85)
				{
					setcolor(14);
					outtextxy(300,340,"You Lose!");
					cout<<"You survived for: "<<now1-start<<" seconds"<<endl;
					f=true;
				}
				if(a+40>=590)
				{
					da=-0.8;
				}
				else if(a<110)
				{
					da=0.8;
				}
				if(b<110)
				{
			        db=0.8;
			    }
		        else if(b+40>=590)
		        {
		            db=-0.8;
				}
				b+=db;
				a+=da;	
				int now2=time(0);
				if(now2-start>=30)
				{
					setcolor(14);
					outtextxy(300,350,"You Win!");
					cout<<"You Win!"<<endl;
					break;
				}	
			}
		}
		else if(h==2)
		{	
            int r1=rand()%12,r2=rand()%16;  
            cout<<"Enter the game by pressing enter"<<endl;
			cout<<"Bump 20 times to win!"<<endl;
			delay(2000);
			initwindow(700,700);	
			setfillstyle(0,15);
			floodfill(1,1,15);	
			setcolor(11);
			line(100,1,100,600);
			line(600,1,600,600);
			setcolor(2);
			line(100,600,600,600);
			setcolor(3);
			char ch=0;
			double x=310,y=200,z=590,t=580,vx=0,vy=0,g=0.02,a=100,b=560;
			bool flag=false;
			setcolor(14);
			setfillstyle(1,3);
			fillellipse(x,y,10,10);
			setfillstyle(1,10);
			bar(a,500,a+40,505);
			setfillstyle(1,10);
			bar(b,100,b+40,95);
			while(ch!=13)
				ch=getch();
			float da=0.8,db=-0.8,bump=0;
		    bool f=false;
		    while(f==false)
			{
				setcolor(11);
				line(100,1,100,600);
				line(600,1,600,600);
				setcolor(2);
				line(100,600,600,600);
		 	    setcolor(0);
				setfillstyle(1,0);
				fillellipse(x,y,23,23);
				setcolor(14);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,10);
				bar(a,500,a+40,505);	
		    	setfillstyle(1,10);
		     	bar(b,100,b+40,95);
				delay(7);
				tayeen_adad(a,b,x,y,vx);
				if(kbhit())				
                {
					char c=getch();
					if(c=='a' || c==75)
						vx-=1.1;
					if(c=='d' || c==77)
						vx+=1.1;
				}
				setcolor(0);
				setfillstyle(1,0);
				rectangle(a-1,499,a+41,506);
		        setfillstyle(1,0);
				rectangle(b-1,101,b+41,94);
				vy+=g;
				vx*=0.995;
				if(x>=z)
				{
					vx=-vx;
				}
				if(x<110)
				{
					vx=-vx;
				}
				if(y>=z)
				{
					vy=-vy;
				}
				x+=vx;
				y+=vy;
				if(x>=a-10 && x<a+50 && vy>0 && y>=490)
				{
					vy=-4.2;
					bump++;
				}
				if(x>=b-10 && x<b+50 && vy<0 && y<=110)
				{
		            vy=0.8;
		            bump++;
		        }
		        if(vx>7)
                    vx=7;
		        if(y>=515 || y<=85)
				{
					setcolor(14);
					outtextxy(300,340,"You Lose!");
					cout<<"You bumped "<<bump<<" times"<<endl;
					f=true;
				}
				if(a+40>=590)
				{
					da=-0.8;
				}
				else if(a<110)
				{
					da=0.8;
				}
				if(b<110)
				{
		            db=0.8;
		        }
		        else if(b+40>=590)
		        {
		            db=-0.8;
		        }	
				b+=db;
				a+=da;
				if(bump>=20)
				{
					setcolor(14);
					outtextxy(300,350,"You Win!");
					cout<<"You Win!"<<endl;
					break;
				}
			}
		}
		else if(h==3)
		{
            int r1=rand()%12,r2=rand()%16;              
            cout<<"Enter the game by pressing enter"<<endl;
			cout<<"Dont hit the walls and bump 10 times to win!"<<endl;
			delay(2000);
			initwindow(700,700);	
			setfillstyle(0,15);
			floodfill(1,1,15);
            setcolor(11);
			line(100,1,100,600);
			line(600,1,600,600);
			setcolor(2);
			line(100,600,600,600);
			setcolor(3);
			char ch=0;
			double x=310,y=200,z=590,t=580,vx=0,vy=0,g=0.02,a=100,b=560;
			bool flag=false;
			setcolor(14);
			setfillstyle(1,3);
			fillellipse(x,y,10,10);
			setfillstyle(1,10);
			bar(a,500,a+40,505);
			setfillstyle(1,10);
			bar(b,100,b+40,95);
			while(ch!=13)
				ch=getch();
			float da=0.8,db=-0.8,bump=0;
		    bool f=false;
		    while(f==false)
			{
				setcolor(11);
				line(100,1,100,600);
				line(600,1,600,600);
				setcolor(2);
				line(100,600,600,600);
		 	    setcolor(0);
				setfillstyle(1,0);
				fillellipse(x,y,23,23);
				setcolor(14);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,10);
				bar(a,500,a+40,505);	
		    	setfillstyle(1,10);
		     	bar(b,100,b+40,95);
				delay(7);
				tayeen_adad(a,b,x,y,vx);
				if(kbhit())				
                {
					char c=getch();
					if(c=='a' || c==75)
						vx-=1.1;
					if(c=='d' || c==77)
						vx+=1.1;
				}
				setcolor(0);
				setfillstyle(1,0);
				rectangle(a-1,499,a+41,506);
		        setfillstyle(1,0);
				rectangle(b-1,101,b+41,94);
				vy+=g;
				vx*=0.995;
				if(x>=z)
				{
					setcolor(14);
					outtextxy(300,340,"You Lose!");
					cout<<"You lost with "<<bump<<" bumps!"<<endl;
					f=true;
				}
				if(x<110)
				{
					setcolor(14);
					outtextxy(300,340,"You Lose!");
					cout<<"You lost with "<<bump<<" bumps!"<<endl;
					f=true;
				}
				if(y>=z)
				{
					vy=-vy;
				}
				x+=vx;
				y+=vy;
				if(x>=a-10 && x<a+50 && vy>0 && y>=490)
				{
					vy=-4.2;
					bump++;
				}
				if(x>=b-10 && x<b+50 && vy<0 && y<=110)
				{
		            vy=0.8;
    		        bump++;
		        }
		        if(vx>7)
                    vx=7;
		        if(y>=515 || y<=85)
				{
					setcolor(14);
					outtextxy(300,340,"You Lose!");
					cout<<"You lost with "<<bump<<" bumps!"<<endl;
					f=true;
				}
				if(a+40>=590)
				{
					da=-0.8;
				}
				else if(a<110)
				{
					da=0.8;
				}
				if(b<110)
				{
		            db=0.8;
		        }
		        else if(b+40>=590)
		        {
		            db=-0.8;
		        }	
				b+=db;
				a+=da;
				if(bump>10)
                {   
                    setcolor(14);
					outtextxy(300,340,"You win");
					cout<<"You Win"<<endl;
					break;
                }
            }
        }    
        else if(h==4)
        {
            int r1=rand()%12,r2=rand()%16;         
            cout<<"Enter the game by pressing enter"<<endl;
			cout<<"Achieve 100 points to win!"<<endl;
			delay(2000);
			initwindow(700,700);
			setfillstyle(0,15);
			floodfill(1,1,15);
			setcolor(11);
			line(100,1,100,600);
			line(600,1,600,600);
			setcolor(2);
			line(100,600,600,600);
			setcolor(3);
			char ch=0;
			double x=310,y=200,z=590,t=580,vx=0,vy=0,g=0.02,a=100,b=560,point=0;
			bool flag=false;
			setcolor(14);
			setfillstyle(1,3);
			fillellipse(x,y,10,10);
			setfillstyle(1,10);
			bar(a,500,a+40,505);
			setfillstyle(1,10);
			bar(b,100,b+40,95);
			while(ch!=13)
				ch=getch();
			float da=0.8,db=-0.8,bump=0;
		    bool f=false;
		    while(f==false)
			{
				setcolor(11);
				line(100,1,100,600);
				line(600,1,600,600);
				setcolor(2);
				line(100,600,600,600);
		 	    setcolor(0);
				setfillstyle(1,0);
				fillellipse(x,y,23,23);
				setcolor(14);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,10);
				bar(a,500,a+40,505);	
		    	setfillstyle(1,10);
		     	bar(b,100,b+40,95);
				delay(7);
				tayeen_adad(a,b,x,y,vx);
				if(kbhit())				
                {
					char c=getch();
					if(c=='a' || c==75)
						vx-=1.1;
					if(c=='d' || c==77)
						vx+=1.1;
				}
				setcolor(0);
				setfillstyle(1,0);
				rectangle(a-1,499,a+41,506);
		        setfillstyle(1,0);
				rectangle(b-1,101,b+41,94);
				vy+=g;
				vx*=0.995;
				if(x>=z)
				{
					vx=-vx;
					point-=4;
				}
				if(x<110)
				{
					vx=-vx;
					point-=4;
				}
				if(y>=z)
				{
					vy=-vy;
				}
				x+=vx;
				y+=vy;
				if(x>=a-10 && x<a+50 && vy>0 && y>=490)
				{
					vy=-4.2;
					point+=7;
				}
				if(x>=b-10 && x<b+50 && vy<0 && y<=110)
				{
		            vy=0.8;
    		        point+=7;
		        }
		        if(vx>7)
                    vx=7;
		        if(y>=515 || y<=85)
				{
					setcolor(14);
					outtextxy(300,340,"You Lose!");
					cout<<"You Lost with: "<<point<<" points!"<<endl;
					f=true;
				}
				if(a+40>=590)
				{
					da=-0.8;
				}
				else if(a<110)
				{
					da=0.8;
				}
				if(b<110)
				{
		            db=0.8;
		        }
		        else if(b+40>=590)
		        {
		            db=-0.8;
		        }	
				b+=db;
				a+=da;
				if(point>100)
                {   
                    setcolor(14);
					outtextxy(300,340,"You win");
					cout<<"You Win"<<endl;
					break;
                }
            }
        }
        else if(h==5)
		{      
            int r1=rand()%12,r2=rand()%16;      
            cout<<"Enter the game by pressing enter"<<endl;
			cout<<"This is endless you will NEVER win!"<<endl;
			delay(2000);
			initwindow(700,700);	
			setfillstyle(0,15);
			floodfill(1,1,15);
            setcolor(11);
			line(100,1,100,600);
			line(600,1,600,600);
			setcolor(2);
			line(100,600,600,600);
			setcolor(3);
			char ch=0;
			double x=310,y=200,z=590,t=580,vx=0,vy=0,g=0.02,a=100,b=560;
			bool flag=false;
			setcolor(14);
			setfillstyle(1,3);
			fillellipse(x,y,10,10);
			setfillstyle(1,10);
			bar(a,500,a+40,505);
			setfillstyle(1,10);
			bar(b,100,b+40,95);
			while(ch!=13)
				ch=getch();
			float da=0.99,db=-0.7;
			int score=0;
		    bool f=false;
		    while(f==false)
			{
				setcolor(11);
				line(100,1,100,600);
				line(600,1,600,600);
				setcolor(2);
				line(100,600,600,600);
			    setcolor(0);
				setfillstyle(1,0);
				fillellipse(x,y,23,23);
				setcolor(14);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,3);
				fillellipse(x,y,10,10);
				setfillstyle(1,10);
				bar(a,500,a+40,505);	
			   	setfillstyle(1,10);
			    bar(b,100,b+40,95);
				delay(7);
				tayeen_adad(a,b,x,y,vx);
				if(kbhit())
				{
					char c=getch();
					if(c=='a' || c==75)
						vx-=1.1;
					if(c=='d' || c==77)
						vx+=1.1;
				}
				setcolor(0);
				setfillstyle(1,0);
				rectangle(a-1,499,a+41,506);
			    setfillstyle(1,0);
				rectangle(b-1,101,b+41,94);
				vy+=g;
				vx*=0.995;
				if(x>=z)
				{
					vx=-vx;
					score-=4;
				}
				if(x<110)
				{
					vx=-vx;
					score-=4;
				}
				if(y>=z)
				{
					vy=-vy;
				}
				x+=vx;
				y+=vy;
				if(x>=a-10 && x<a+50 && vy>0 && y>=490)
				{
					vy=-4.2;
					score+=7;
				}
				if(x>=b-10 && x<b+50 && vy<0 && y<=110)
				{
			        vy=0.8;
			        score+=7;		        
		        }
		        if(vx>7)
                    vx=7;
			    if(y>=515 || y<=85)
				{
					setcolor(14);
					outtextxy(300,340,"You Lose!");
					cout<<"You lost with "<<score<<" points!"<<endl;
					f=true;
				}
				if(a+40>=590)
				{
					da=-0.99;
				}
				else if(a<110)
				{
					da=0.99;
				}
				if(b<110)
				{
			        db=0.7;
			    }
		        else if(b+40>=590)
		        {
		            db=-0.7;
				}
				b+=db;
				a+=da;	
				
			}
        }  
		else
		{
            cin>>h;
        }
        // Sleep(1000);	
		// closegraph();
	}
    return EXIT_SUCCESS;
}
