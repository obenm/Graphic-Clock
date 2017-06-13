#include <graphics.h>
#include <process.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

class reloj_analogo
{
	public:
		void inicio() // metodo para iniciar graficos
		{
			int gdriver=DETECT, gmode, errorcode;
			initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
			errorcode=graphresult();
			if(errorcode != grOk)
			{
				cout<<" ERROR DE GRAFICOS "<<endl;
				getch();
				exit(1);
			}
		} // llave de fin de un metodo (inicializacion de graficos)

		void dibujar_reloj()
		{
			setfillstyle(SOLID_FILL, LIGHTGRAY);
			floodfill(320, 240, LIGHTGRAY);
			setcolor(DARKGRAY);
			circle(320, 240, 210);
			setfillstyle(SOLID_FILL, DARKGRAY);
			floodfill(320, 240, DARKGRAY);
			setcolor(WHITE);
			circle(320, 240, 200);
			setfillstyle(SOLID_FILL, WHITE);
			floodfill(320, 240, WHITE);

			setcolor(BLACK);
			for(int i=0; i<60; i++)
			{
				arc(320, 240, 90-(i*6), 91-(i*6), 190);
				arc(320, 240, 90-(i*6), 91-(i*6), 191);
				arc(320, 240, 90-(i*6), 91-(i*6), 189);
			}

			settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
			outtextxy(310, 45, "12");
			outtextxy(410, 70, "1");
			outtextxy(480, 135, "2");
			outtextxy(510, 235, "3");
			outtextxy(480, 330, "4");
			outtextxy(415, 400, "5");
			outtextxy(320, 430, "6");
			outtextxy(225, 405, "7");
			outtextxy(150, 335, "8");
			outtextxy(125, 240, "9");
			outtextxy(143, 143, "10");
			outtextxy(215, 70, "11");
		}

		void manecillas()
		{
			/*for(int h=0; h<24; h++)
			{
				for(int m=0; m<60; m++)
				{
					for(int s=0; s<=60; s++)
					{*/
						//if(getch() == 27) exit(1);
						int i = 0;
						while(i == 0)
						{
						int h, m, s;
						struct time t;
						gettime(&t);
						h = t.ti_hour;
						m = t.ti_min;
						s = t.ti_sec;
						setcolor(RED);
						struct arccoordstype arcinfo;
						int seg_arc_x, seg_arc_y, min_arc_x, min_arc_y, hor_arc_x, hor_arc_y;
						arc(320, 240, 90-(s*6), 91-(s*6), 180);
						getarccoords(&arcinfo);
						seg_arc_x = arcinfo.xend;
						seg_arc_y = arcinfo.yend;
						line(320, 240, seg_arc_x, seg_arc_y);

						setcolor(DARKGRAY);
						arc(320, 240, 90-(m*6), 91-(m*6), 185);
						getarccoords(&arcinfo);
						min_arc_x = arcinfo.xend;
						min_arc_y = arcinfo.yend;
						line(320, 240, min_arc_x, min_arc_y);
						line(319, 239, min_arc_x, min_arc_y);
						line(318, 238, min_arc_x, min_arc_y);
						line(321, 241, min_arc_x, min_arc_y);
						line(322, 242, min_arc_x, min_arc_y);

						setcolor(BLACK);
						arc(320, 240, 90-(h*30), 91-(h*30), 130);
						getarccoords(&arcinfo);
						hor_arc_x = arcinfo.xend;
						hor_arc_y = arcinfo.yend;
						line(320, 240, hor_arc_x, hor_arc_y);
						line(319, 239, hor_arc_x, hor_arc_y);
						line(318, 238, hor_arc_x, hor_arc_y);
						line(317, 237, hor_arc_x, hor_arc_y);
						line(316, 236, hor_arc_x, hor_arc_y);
						line(315, 235, hor_arc_x, hor_arc_y);
						line(321, 241, hor_arc_x, hor_arc_y);
						line(322, 242, hor_arc_x, hor_arc_y);
						line(323, 243, hor_arc_x, hor_arc_y);
						line(324, 244, hor_arc_x, hor_arc_y);
						line(325, 245, hor_arc_x, hor_arc_y);

						delay(500);
						setcolor(WHITE);
						line(320, 240, seg_arc_x, seg_arc_y);

						line(320, 240, min_arc_x, min_arc_y);
						line(319, 239, min_arc_x, min_arc_y);
						line(318, 238, min_arc_x, min_arc_y);
						line(321, 241, min_arc_x, min_arc_y);
						line(322, 242, min_arc_x, min_arc_y);

						line(320, 240, hor_arc_x, hor_arc_y);
						line(319, 239, hor_arc_x, hor_arc_y);
						line(318, 238, hor_arc_x, hor_arc_y);
						line(317, 237, hor_arc_x, hor_arc_y);
						line(316, 236, hor_arc_x, hor_arc_y);
						line(315, 235, hor_arc_x, hor_arc_y);
						line(321, 241, hor_arc_x, hor_arc_y);
						line(322, 242, hor_arc_x, hor_arc_y);
						line(323, 243, hor_arc_x, hor_arc_y);
						line(324, 244, hor_arc_x, hor_arc_y);
						line(325, 245, hor_arc_x, hor_arc_y);
						}
				 /*	}
				}
			}*/
		}
};

void main()
{
	reloj_analogo r;
	r.inicio();
	cleardevice();
	r.dibujar_reloj();
	r.manecillas();
	getch();
}