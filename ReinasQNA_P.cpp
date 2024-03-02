#include<stdlib.h>
#include<iostream>
#include<graphics.h>
#include<stdio.h>

using namespace std;
void SolReina(int);
bool Comprobar(int num, int lim);
void DibujarReina();
void Reina(int);
int posiciones[8];
int j=1;
	// FUNCION PRINCIPAL
	int main(){
		initwindow(1500, 1500,"REINAS QUE NO ATACAN");
		setbkcolor(RED);
		SolReina(0);
		system("pause");
		return 0;
	}
	void SolReina(int num){
		if(num==8){
			DibujarReina();		
			delay(800);
		}else{
			for(int i=0;i<8;i++){
				if(Comprobar(i,num)){
					posiciones[num]=i;
					SolReina(num+1);
					posiciones[num]=-1;
				}
			}
		}
	}
	//COMPRUEBA QUE NO HAYA REINAS QUE SE ATAQUEN ENTRE SI
	bool Comprobar(int num, int lim){
		for(int i=0; i<lim; i++){
			if(posiciones[i]==num || (i+posiciones[i])==(lim+num) || (i-posiciones[i])==(lim-num)){
			return false;
		}
	}
	return true;
} 
	// FUNCION QUE DIBUJA A LAS REINAS EN EL TABLERO
	void DibujarReina(){
		char str[300];
    	char num[10];
    	cleardevice();
    	setcolor(WHITE);
    	settextstyle(3,0,4);
    	outtextxy(750,0,"REINAS QUE NO ATACAN");
    	settextstyle(3,0,3);
    	sprintf(num, "%d", j);
    	outtextxy(800,40,"No. de Solucion Encontradas:");
    	outtextxy(1000,40,num);
    	j++;
    		for(int fil=0;fil<8;fil++){
        		for(int col=0;col<8;col++){
        	    setfillstyle(SOLID_FILL, (fil+col)%2 == 0 ? WHITE : BLACK);
            	bar(10+85*fil,10+85*col,10+85*(fil+1),10+85*(col+1));
        	}
       	Reina(fil);
   	}
}
	//FUNCION QUE HACE EL DIBUJO DE LAS REINAS EN MODO GRÁFICO
	void Reina(int i){
		int x=0, y=10;
		setcolor(YELLOW);
		setlinestyle(1, 0, 3);
		line(35+i*85, 77+posiciones[i]*85, 75+i*85, 77+posiciones[i]*85); // ABAJO ULTIMA
		line(35+i*85, 77+posiciones[i]*85, 35+i*85, 37+posiciones[i]*85); // IZQUIERDA
		line(75+i*85, 77+posiciones[i]*85, 75+i*85, 37+posiciones[i]*85); // DERECHA
		line(35+i*85, 67+posiciones[i]*85, 75+i*85, 67+posiciones[i]*85); // ENMEDIO
		line(35+i*85, 72+posiciones[i]*85, 75+i*85, 72+posiciones[i]*85); // ENMEDIO
		line(35+i*85, 37+posiciones[i]*85, 45+i*85, 52+posiciones[i]*85); // L1
		line(45+i*85, 52+posiciones[i]*85, 55+i*85, 37+posiciones[i]*85); // L2
		line(55+i*85, 37+posiciones[i]*85, 65+i*85, 52+posiciones[i]*85); // L3
		line(65+i*85, 52+posiciones[i]*85, 75+i*85, 37+posiciones[i]*85); // L4
		circle(55+i*85, 32+posiciones[i]*85, 5);
		circle(38+i*85, 32+posiciones[i]*85, 5);
		circle(73+i*85, 32+posiciones[i]*85, 5);
		setcolor(GREEN);
		circle(55+i*85, 62+posiciones[i]*85, 3);
		setcolor(RED);
		circle(43+i*85, 62+posiciones[i]*85, 3);
		setcolor(LIGHTCYAN);
		circle(69+i*85, 62+posiciones[i]*85, 3);
	}
	
