#include<stdlib.h>
int ** input(int **a,int **cur){
	printf("\nEnter top-right coordinate of plane(Dimension of Grid):");
	scanf("%d %d",&p.x,&p.y);
	if(p.x<0 || p.y<0) {
		printf("Coordinates must be positive !!!\n");
		exit (1);
	}
	printf("Enter initial positions of robots:");
	puts("\nR1(horizontal bot):");
	scanf("%d %d",&cur[1][0],&cur[1][1]);
	puts("R2(vertical bot):");
	scanf("%d %d",&cur[2][0],&cur[2][1]);
	puts("R3(diagonal bot):");
	scanf("%d %d",&cur[3][0],&cur[3][1]);
	puts("R4(diagonal bot):");
	scanf("%d %d",&cur[4][0],&cur[4][1]);
	printf("Location of Object:\n");
	scanf("%d %d",&t.x,&t.y);
	int k=0;
	int k2=0;
	for(k=1;k<=4;k++){
			if(cur[k][0]<0 || cur[k][0]>p.x || cur[k][1]<0 || cur[k][1]>p.y){
				printf("Wrong position of Robots\n");
				exit (1);
			}
	}

	a=(int**)calloc((p.x+1),sizeof(int *));
	for(k=0;k<p.x+1;k++){
		a[k]=(int *)calloc((p.y+1),sizeof(int ));
	}
	a[cur[1][0]][cur[1][1]]=1;
	a[cur[2][0]][cur[2][1]]=2;
	a[cur[3][0]][cur[3][1]]=3;
	a[cur[4][0]][cur[4][1]]=4;
	if((t.x>=0 && t.x<=p.x) && (t.y>=0 && t.y<=p.y)) a[t.x][t.y]=5;
	return a;
}
