int movr(int **a,int **cur,int r,int *steps){
	if(cur[r][0]==t.x && cur[r][1]==t.y) {
		a[cur[r][0]][cur[r][1]]=5;
		return 0;
	}
	if(cur[r][0]+1<=p.x){
		a[cur[r][0]][cur[r][1]]=0;
		cur[r][0]++;
		a[cur[r][0]][cur[r][1]]=r;
		steps[r]++;
		return 1;
	}
	else if(happen==0){
		happen=1;
		int ret;
		if(addh==-1){
			ret=movdown(a,cur,r,steps);
		}else{
			ret=movup(a,cur,r,steps);
		}
		happen=0;
		if(ret==0){steps[r]=-1;
			return 0;
		}else{
			flagh=0;
			return 1;
		}
	}
	else {
		steps[r]=-1;
		return 0;
	}
}
int movup(int **a,int **cur,int r,int *steps){
	if(cur[r][0]==t.x && cur[r][1]==t.y){
		a[cur[r][0]][cur[r][1]]=5;
		return 0;
	}
	if(cur[r][1]+1<=p.y){
		a[cur[r][0]][cur[r][1]]=0;
		cur[r][1]++;
		a[cur[r][0]][cur[r][1]]=r;
		steps[r]++;
		return 1;
	}
	else if(happen==0){
		int ret;
		happen=1;
		if(addv==-1){
			ret=movl(a,cur,r,steps);
		}else{
			ret=movr(a,cur,r,steps);
		}
		happen=0;
		if(ret==0){
			steps[r]=-1;
			return 0;
		}else{
			flagv=0;
			return 1;
		}
	}
	else {
		steps[r]=-1;
		return 0;
	}
}
int movl(int **a,int **cur,int r,int *steps){
	if(cur[r][0]==t.x && cur[r][1]==t.y){
		a[cur[r][0]][cur[r][1]]=5;
		return 0;
	}
	if(cur[r][0]-1>=0){
		a[cur[r][0]][cur[r][1]]=0;
		cur[r][0]--;
		a[cur[r][0]][cur[r][1]]=r;
		steps[r]++;
		return 1;
	}
	else if(happen==0){
		happen=1;
		int ret;
		if(addh==-1){
			ret=movdown(a,cur,r,steps);
		}else{
			ret=movup(a,cur,r,steps);
		}
		happen=0;
		if(ret==0){
			steps[r]=-1;
			return 0;
		}else{
			flagh=1;
			return 1;
		}
	}
	else{
		steps[r]=-1;
		return 0;
	}
}
int movdown(int **a,int **cur,int r,int *steps){
	if(cur[r][0]==t.x && cur[r][1]==t.y){
		a[cur[r][0]][cur[r][1]]=5;
		return 0;
	}
	if(cur[r][1]-1>=0){
		a[cur[r][0]][cur[r][1]]=0;
		cur[r][1]--;
		a[cur[r][0]][cur[r][1]]=r;
		steps[r]++;
		return 1;
	}
	else if(happen==0){
		int ret;
		happen=1;
		if(addv==-1){
			ret=movl(a,cur,r,steps);
		}else{
			ret=movr(a,cur,r,steps);
		}
		happen=0;
		if(ret==0){
			steps[r]=-1;
			return 0;
		}else{
			flagv=1;
			return 1;
		}
	}
	else{
		steps[r]=-1;
	}
		return 0;
}

