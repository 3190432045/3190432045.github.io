#include "graphics.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#define Width 800            //�ֱ��� 
#define Height 600           //�ֱ���
void DrawCDw(int h)
{
	int i;
    for(i=0;i<=Width;i++)
    putpixel(i,h,RED);
}
void DrawCDh(int w)
{
	int i;
    for(i=0;i<=Height;i++)
    putpixel(w,i,RED);	
}
void DrawCoordinate(int w,int h,int scale)
{
	int i;
    for(i=0;i<=Width;i++)
    putpixel(i,h,WHITE);
    for(i=0;i<=Height;i++)
    putpixel(w,i,WHITE); 
	for(i=h+scale;i<=Height;i+=scale)
    DrawCDw(i);	    
	for(i=h-scale;i>=0;i-=scale)
    DrawCDw(i);
	for(i=w+scale;i<=Width;i+=scale)
    DrawCDh(i);	
	for(i=w-scale;i>=0;i-=scale)
    DrawCDh(i);		                  
}
void DrawFuncDot(int w,int h,int Ow,int Oh,int scale)
{
	w*=scale;h*=scale;
    putpixel(Ow+w,Oh-h,WHITE);                   
}
void DrawFunc(int w,int h,int Ow,int Oh)
{
    putpixel(Ow+w,Oh-h,WHITE);                  
}
void DrawFuncDouble(double w,double h,int Ow,int Oh,int scale)
{
	w*=scale;h*=scale;
    putpixel(Ow+w,Oh-h,WHITE);                  
}
void DrawFuncAuto(int type,int Ow,int Oh,int left, int right,int scale)
{
double p,q;
if(type==0)
for(p=left;p<right;p+=0.001)
{
    q=sin(p);
    DrawFuncDouble(p,q,Ow,Oh,scale);
}
else if(type==1)
for(p=left;p<right;p+=0.001)
{
    q=pow(2.72,p);        
    DrawFuncDouble(p,q,Ow,Oh,scale);
}
if(type==2)
for(p=0;p<right;p+=0.001)
{
    q=1;
    DrawFuncDouble(p,q,Ow,Oh,scale);
} 
if(type==3)
for(p=left;p<right;p+=0.001)
{
    q=pow(2.72,p)*cos(10*p);        
    DrawFuncDouble(p,q,Ow,Oh,scale);
}             
}
void DrawButton(int w,int h,int sizew,int sizeh,char str[])
{                                                                //setfillcolor(RED); 
    bar3d(w-sizew/2,h-sizeh/2,w+sizew/2,h+sizeh/2,3,1);
	setfont(25, 0,"΢���ź�");
    outtextrect(w-sizew/2.8,h-sizeh/4,w+sizew/4,h+sizeh/4,str);            
}
int MouseClick()
{
mouse_msg msg = {0};	
for ( ; is_run(); delay_fps(60))
	{
		//��ȡ�����Ϣ�����������ȴ����ȴ�������ϢΪֹ
		while (mousemsg())
		{
			msg = getmouse();
		} 
		if((int)msg.is_down()==1&&(int)msg.is_left()==1)
        {
            int mouse_x,mouse_y;
            mousepos(&mouse_x, &mouse_y);
            if(mouse_x>=10&&mouse_x<=90&&mouse_y>=520&&mouse_y<=570)
                return 0;
            if(mouse_x>=108&&mouse_x<=188&&mouse_y>=520&&mouse_y<=570)
                return 1;
            if(mouse_x>=200&&mouse_x<=360&&mouse_y>=520&&mouse_y<=570)
                return 2;
            if(mouse_x>=0&&mouse_x<=0&&mouse_y>=0&&mouse_y<=0)
                return 3;
            else
                return 4;
        }
	}
}
void Menu(int type,int &Ow,int &Oh,int &scale,int &left,int & right)
{
	                         int i,j;
                          	 double p,q;
                          	 int step=0;
							 char key;
					        while(1) 
                         {
                         	 cleardevice();
                             DrawCoordinate(Ow,Oh,scale);
                             DrawFuncAuto(type,Ow,Oh,left,right,scale);
	printf("���룺\n1-�ƶ���ͼ\n2-����ͼ��\n3-��������\n4-��λԭ��\n���������˳�\n");
                             key=getchar();
							 if(key=='1') 
							 {
							 	printf("�ƶ���ͼ��\nw-����\na-����\ns-����\nd-����\n");
							 	getchar();
							 	key=getchar();
							 	printf("���볤��(��λ����)��\n");
							 	scanf("%d",&step);
							 	step*=scale;
							 	if(key=='w')
							 	Oh-=step;
							 	if(key=='a')
							 	Ow-=step;
							 	if(key=='s')
							 	Oh+=step;
							 	if(key=='d')
							 	Ow+=step;
							 	cleardevice();
							 	getchar();
							 }
							 else if(key=='2')
							 {
							 	printf("���뱶�ʣ�\n");
							 	scanf("%d",&scale);
							 	cleardevice();
							 	getchar();
							 } 
							 else if(key=='3')
							 {
							 	printf("�����䣺\n");
							 	scanf("%d",&left);
							 	printf("�����䣺\n");
							 	scanf("%d",&right);
							 	cleardevice();
							 	getchar();
							 } 
							 else if(key=='4')
							 {
							 	Ow=Width/2;
							 	Oh=Height/2;
							 	cleardevice();
							 	getchar();
							 } 
							 else
							  {
							  	getchar();
							  	return;
							  } 
					    } 
}
                          int main()
                          {
                          	 int Ow=Width/2;            //ԭ������x 
                          	 int Oh=Height/2+100;       //ԭ������y 
                          	 int i,j;
                          	 int scale=50;             //���Ź�ģ 
                          	 int left=-10;int right=10;   //���� 
                          	 double p,q;
                          	 int step=0;
                          	 int type=0;
                          	 int mouse;
							 char key;
							 char text1[]="��һ��";char text2[]="��һ��";char text3[]=" ����";
                             initgraph(Width,Height);   // ��ʼ������ʾһ�����ڣ������ TC ��������                             
                             while(1) 
                         {
                         	 cleardevice();
                             DrawCoordinate(Ow,Oh,scale);
                             DrawFuncAuto(type,Ow,Oh,left,right,scale);
                             DrawButton(Width/16,Height/1.1,80,50,text1);
                             DrawButton(Width/5.4,Height/1.1,80,50,text2);
							 DrawButton(Width/3.2,Height/1.1,80,50,text3);
							 mouse=MouseClick();
                             if(mouse==2)
                             {
                              Menu(type,Ow,Oh,scale,left,right);	
							 }
							 else if(mouse==1)
                             {
                              type++;
							 }
							 else if(mouse==0)
                             {
                              type--;
							 }
							 if(type>3)
							 type=0;
							 else if(type<0)
							 type=3;
                         }
                             getch();               // ��ͣһ�µȴ��û�����
                             closegraph();          // �ر�ͼ�ν���
                             return 0;
                          }
