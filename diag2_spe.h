void diagonal2_specifications(int **a,int **cur,int r){
	if(p.x>=p.y){
		if(cur[r][0]<p.x/2){
			flagdh2=-1;daddh2=1;
		}
		else{
			flagdh2=1;
			daddh2=-1;
		}
		if(cur[r][1]<p.y/2){
			flagdv2=1;
			daddv2=1;
		}

		else {
			flagdv2=-1;
			daddv2=-1;
		}
	}
	else{
		if(cur[r][1]<p.y/2){
			flagdv2=-1;
			daddv2=1;
		}
		else{
			daddv2=-1;
			flagdv2 =1;
		}
		if(cur[r][0]<p.x/2){
			flagdh2=1;
			daddh2=1;
		}
		else{
			flagdh2=-1;
			daddh2=-1;
		}
	}
}
int diagonal2_change(int **a,int **cur,int r,int *steps,int changev){
	if(changev) { 
			if(cur[r][1]+flagdv2>=0 && cur[r][1]+flagdv2<=p.y){	
			a[cur[r][0]][cur[r][1]]=0;
			cur[r][1]=cur[r][1]+flagdv2;
			a[cur[r][0]][cur[r][1]]=r;
			daddv2=daddv2*(-1);
			daddh2=daddh2*(-1);
			steps++;
			return 1;
			}
			else {
				steps[r]=-1;
				return 0;
			}
	}
	else {
		if(cur[r][0]+flagdh2>=0 && cur[r][0]+flagdh2<=p.x){
			a[cur[r][0]][cur[r][1]]=0;
			cur[r][0]=cur[r][0]+flagdh2;
			a[cur[r][0]][cur[r][1]]=r;
			daddv2=daddv2*(-1);
			daddh2=daddh2*(-1);
			steps++;
			return 1;
		}
		else{
			steps[r]=-1;
			return 0;
		}
	}
}
int movdia2(int **a,int **cur,int r,int *steps){
	if(cur[r][0]==t.x && cur[r][1]==t.y){
		a[cur[r][0]][cur[r][1]]=5;
		return 0;
	}
	
	if(daddv2+cur[r][1]<0 ||daddv2+cur[r][1]>p.y){ 
		return(diagonal2_change(a,cur,r,steps,0));
	}
		else if(daddh2+cur[r][0]<0 || daddh2+cur[r][0]>p.x) {
		return(diagonal2_change(a,cur,r,steps,1));
	}
	else{
		a[cur[r][0]][cur[r][1]]=0;
		cur[r][0]=cur[r][0]+daddh2;
		cur[r][1]=cur[r][1]+daddv2;
		a[cur[r][0]][cur[r][1]]=r;
		steps[r]++;
		return 1;
	}
}
