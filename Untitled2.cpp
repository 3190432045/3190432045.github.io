#include "graphics.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#define Width 800            //分辨率 
#define Height 600           //分辨率
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
                          	 int Ow=Width/2;            //原点坐标x 
                          	 int Oh=Height/2+100;       //原点坐标y 
                          	 int i,j;
                          	 int scale=100;             //缩放规模 
                          	 int left=-60;int right=60;   //区间 
                          	 double p,q;
                          	 int step=0;
							 char key; 
                             initgraph(Width,Height);   // 初始化，显示一个窗口，这里和 TC 略有区别
                             while(1) 
                         {
                             DrawCoordinate(Ow,Oh,scale);
                             for(p=left;p<right;p+=0.001)
                             {
                             	q=sin(p);          //  函数在这里输入 
                                DrawFuncDouble(p,q,Ow,Oh,scale);
                             }
                             printf("输入：\n1-移动视图\n2-缩放图像\n3-设置区间\n4-定位原点\n");
                             key=getchar();
							 if(key=='1') 
							 {
							 	printf("移动视图：\nw-向上\na-向左\ns-向下\nd-向右\n");
							 	getchar();
							 	key=getchar();
							 	printf("输入长度(单位长度)：\n");
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
							 	printf("输入倍率：\n");
							 	scanf("%d",&scale);
							 	cleardevice();
							 	getchar();
							 } 
							 else if(key=='3')
							 {
							 	printf("左区间：\n");
							 	scanf("%d",&left);
							 	printf("右区间：\n");
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
                             getch();               // 暂停一下等待用户按键
                             closegraph();          // 关闭图形界面
                             return 0;
                          }
