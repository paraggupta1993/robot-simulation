void print(int **a){
	int i,j;
	char ch;
	scanf("%c",&ch);
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


