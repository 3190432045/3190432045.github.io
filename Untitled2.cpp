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
void Move(char dir,int step)
{
    cleardevice();             
}
                          int main()
                          {
                          	 int Ow=Width/2;            //ԭ������x 
                          	 int Oh=Height/2+100;       //ԭ������y 
                          	 int i,j;
                          	 int scale=100;             //���Ź�ģ 
                          	 int left=-60;int right=60;   //���� 
                          	 double p,q;
                          	 int step=0;
							 char key; 
                             initgraph(Width,Height);   // ��ʼ������ʾһ�����ڣ������ TC ��������
                             while(1) 
                         {
                             DrawCoordinate(Ow,Oh,scale);
                             for(p=left;p<right;p+=0.001)
                             {
                             	q=sin(p);          //  �������������� 
                                DrawFuncDouble(p,q,Ow,Oh,scale);
                             }
                             printf("���룺\n1-�ƶ���ͼ\n2-����ͼ��\n3-��������\n4-��λԭ��\n");
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
							  	closegraph();
							  	return 0;
							  } 
                         }
                             getch();               // ��ͣһ�µȴ��û�����
                             closegraph();          // �ر�ͼ�ν���
                             return 0;
                          }
