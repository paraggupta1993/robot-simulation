#include<stdio.h>
#include<stdlib.h>
 
#define FLU fflush(stdout)
typedef struct point{
	int x;
	int y;
}point;
point p,t;  //cordinates of grid and object

void print(int **a);

int addh=0,addv=0,flagh=0,flagv=0,happen=0;
int flagdh=1,flagdv=1,daddv,daddh;
int flagdh2=1,flagdv2=1,daddv2,daddh2;
#include"input.h"                          
#include"moves.h"
#include"diag1_spe.h"
#include"diag2_spe.h"
main(){
	int **a;
	int k;
	int **cur;
	cur=(int **)malloc(5*sizeof(int *));
	for(k=0;k<5;k++){
		cur[k]=(int *)malloc(2*sizeof(int));
	}
	a=input(a,cur);
	diagonal1_specifications(a,cur,3);
	diagonal2_specifications(a,cur,4);
	print(a);
	if(cur[1][1]==p.y){
		addh--;
	}
	else addh++;
	if(cur[2][0]==p.x){
		addv--;
	}
	else addv++;
	if(cur[1][0]==0){
		flagh++;
	}
	if(cur[2][1]==0){
		flagv++;
	}
	mov(a,cur);
	return 0;
}
int mov(int **a,int** cur){
	int steps[5]={0};
	int flagy[5]={1,1,1,1,1};
	int k;
	while(flagy[1]!=0 || flagy[2]!=0 || flagy[3]!=0 || flagy[4]!=0){
		if(flagy[1]){
			if(flagh){
				flagy[1]=movr(a,cur,1,steps);
			}else flagy[1]=movl(a,cur,1,steps);
		}
		if(flagy[2]){
			if(flagv){
				flagy[2]=movup(a,cur,2,steps);
			}else flagy[2]=movdown(a,cur,2,steps);
		}
		if(flagy[3]){
			flagy[3]=movdia1(a,cur,3,steps);
		}
		if(flagy[4]){
			flagy[4]=movdia2(a,cur,4,steps);
		}
		print(a);
		for(k=1;k<5;k++){
			printf("R%d=%d\n",k,steps[k]);
		}
	}
}

void print(int **a){
	int i,j;
	char ch;
	system("sleep 1");
	system("clear");
	for(j=p.y;j>=0;j--){
		for(i=0;i<=p.x;i++){
		  	if(a[i][j]==0) printf("_ ");
			else if(a[i][j]==5) printf("@ ");
			else printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}


