#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"
#include <time.h>


int main(){
    initgraph(720,720,"kontrolnaya");
    setbkcolor(BLACK);
    cleardevice();
    int str=1;
    int free=0;
    int ryki=0;
    int x=40;
    int y=40;
while(1){
    cleardevice();
    if (free==0 && ryki==0){
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
    outtextxy(270,250,"МЕНЮ");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(200,320,"СВОБОДНОЕ ДВИЖЕНИЕ");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(210,360,"УПРАВЛЯТЬ ВРУЧНУЮ");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(320,400,"В Ы Х О Д");
    int key=getch();
     switch(key){
        case 65362:if (str>=1){ str-=1;
                    break;
                    }else{
                    break;
                    }
        case 65364:if (str<=1) {str+=1;
                    break;
                    }else{
                    break;
                    }
    }
    if (str==0){
        cleardevice();
        setcolor(RED);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(200,320,"СВОБОДНОЕ ДВИЖЕНИЕ");
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
        outtextxy(270,250,"МЕНЮ");
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(210,360,"УПРАВЛЯТЬ ВРУЧНУЮ");
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
        outtextxy(320,400,"В Ы Х О Д");
        delay(200);
        if (key==65293){
                         free=1;
                    }
    } else if(str==1){
        setcolor(RED);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(210,360,"УПРАВЛЯТЬ ВРУЧНУЮ");
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
        outtextxy(270,250,"МЕНЮ");
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(200,320,"СВОБОДНОЕ ДВИЖЕНИЕ");
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
        outtextxy(320,400,"В Ы Х О Д");
        delay(200);
        if (key==65293){
                        ryki=1;
                    }
    } else if(str==2){
        setcolor(RED);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
        outtextxy(320,400,"В Ы Х О Д");
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
        outtextxy(270,250,"МЕНЮ");
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(210,360,"УПРАВЛЯТЬ ВРУЧНУЮ");
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(200,320,"СВОБОДНОЕ ДВИЖЕНИЕ");
        delay(200);
        if (key==65293){
                         closegraph();
                    }
        }
        delay(300);
       }else if(free==0 && ryki==1){
            setbkcolor(BLACK);
            cleardevice();
            int s=5;
             setcolor(WHITE);
            circle(x,y,25);
            circle(x-30,y-3,5);
            circle(x+30,y-3,5);
            circle(x-10,y-3,5);
            circle(x+10,y-3,5);
            line(x,y-10,x,y+6);
            arc(x,y+7,360,180,10);
            flush();
            delay(30);
            if (kbhit()) {
                int key = getch();
                    switch(key){
                        case 65293:{
                            closegraph();
                        }
                        case 65364:{
                            if(y<=670){
                            y+=s;
                            }else{
                            y-=10;
                            }
                        break;
                    }
                        case 65362:{
                            if(y>=40){
                            y-=s;
                            }else{
                            y+=10;
                            }
                        break;
                    } 
                        case 65361:{
                            if (x>40){
                            x-=s;
                            }else{
                            x+=10;
                            }
                        break;
                    }
                        case 65363:{
                            if(x<680){
                            x+=s;
                            }else{
                            x-=10;
                            }
                        break;
                    }
                }
                flush();
                delay(13);
            }
        }else if(free==1 && ryki==0){
            setbkcolor(BLACK);
            cleardevice();
            srand(time(NULL)); 
            setcolor(WHITE);
            circle(x,y,25);
            circle(x-30,y-3,5);
            circle(x+30,y-3,5);
            circle(x-10,y-3,5);
            circle(x+10,y-3,5);
            line(x,y-10,x,y+6);
            arc(x,y+7,360,180,10);
            flush();
            delay(30);
            int s=5;
            int tact=rand()%2;
            switch(tact){
                case 0:
                if(x<=660 && y<=60){
                    x+=s;
                }else if(x>=660 && y<=640){
                    y+=s;
                }else if(x>=60 && y>=640){
                    x-=s;
                }else if(x<=60 && y>=60){
                    y-=s;
                } 
                break;

                case 1:
                if(x<=60 && y<=640){
                    y+=s;
                }else if(x<660 && y<=640){
                    x-=s;
                }else if(x>660 && y>=60){
                    y-=s;
                }else if(x>=60 && y<=60){
                    x-=s;
                }else if(x<=660 && y>=60){
                    x+=s;
                }
                break;
                flush();
                delay(13);
            }
        }
    }
    return 0;
}
//gcc kontr.c graphics.c $(pkg-config --cflags --libs cairo x11) -lm