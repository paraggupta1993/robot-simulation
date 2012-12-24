void diagonal1_specifications(int **a,int **cur,int r){
	if(p.x>=p.y){
		if(cur[3][0]<p.x/2){
			flagdh=1;daddh=1;
		}
		else{
			flagdh=-1;
			daddh=-1;
		}
		if(cur[3][1]<p.y/2){
			flagdv=-1;
			daddv=1;
		}

		else {
			flagdv=1;
			daddv=-1;
		}
	}
	else{
		if(cur[3][1]<p.y/2){
			flagdv=1;
			daddv=1;
		}
		else{
			daddv=-1;
			flagdv =-1;
		}
		if(cur[3][0]<p.x/2){
			flagdh=-1;
			daddh=1;
		}
		else{
			flagdh=1;
			daddh=-1;
		}
	}
}
int diagonal_change(int **a,int **cur,int r,int *steps,int changev){
	if(changev) { 
			if(cur[r][1]+flagdv>=0 && cur[r][1]+flagdv<=p.y){//	PRI;
			a[cur[r][0]][cur[r][1]]=0;
			cur[r][1]=cur[r][1]+flagdv;
			a[cur[r][0]][cur[r][1]]=r;
			daddv=daddv*(-1);
			daddh=daddh*(-1);
			steps++;
			return 1;
			}
			else {
				steps[r]=-1;
				return 0;
			}
	}
	else {
		if(cur[r][0]+flagdh>=0 && cur[r][0]+flagdh<=p.x){
			a[cur[r][0]][cur[r][1]]=0;
			cur[r][0]=cur[r][0]+flagdh;
			a[cur[r][0]][cur[r][1]]=r;
			daddv=daddv*(-1);
			daddh=daddh*(-1);
			steps++;
			return 1;
		}
		else {
			steps[r]=-1;
			return 0;
		}
	}
}
int movdia1(int **a,int **cur,int r,int *steps){
	if(cur[r][0]==t.x && cur[r][1]==t.y) {
		a[cur[r][0]][cur[r][1]]=5;
		return 0;
	}
	if(daddh+cur[r][0]<0 || daddh+cur[r][0]>p.x) {
		return(diagonal_change(a,cur,r,steps,1));
	}
	else	if(daddv+cur[r][1]<0 ||daddv+cur[r][1]>p.y){ 
		return(diagonal_change(a,cur,r,steps,0));
	}
	else{
		a[cur[r][0]][cur[r][1]]=0;
		cur[r][0]=cur[r][0]+daddh;
		cur[r][1]=cur[r][1]+daddv;
		a[cur[r][0]][cur[r][1]]=r;
		steps[r]++;
		return 1;
	}
}
