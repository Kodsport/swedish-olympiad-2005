#include <stdio.h>
#include <math.h>

int ed[54][54],aed[54],comp[54],n;
double px[50],py[50],pr[50];

void add(int p,int q) {
  ed[p][aed[p]++]=q;
  ed[q][aed[q]++]=p;
}

void MLX(int now,int ncomp) {
  int p;
  comp[now]=ncomp;
  for(p=0;p<aed[now];p++) if(comp[ed[now][p]]==-1) {
    MLX(ed[now][p],ncomp);
  }
}

int solve(double rad) {
  int a,b,ncomp;
  double d;
  for(a=0;a<n+4;a++) {aed[a]=0; comp[a]=-1;}
  for(a=0;a<n;a++) {
    for(b=a+1;b<n;b++) {
      d=sqrt((px[a]-px[b])*(px[a]-px[b])+(py[a]-py[b])*(py[a]-py[b]))-pr[a]-pr[b]-2.0*rad;
      if(d<0.0) add(a,b);
    }
    if(px[a]-pr[a]-2.0*rad<0.0) add(a,n);
    if(px[a]+pr[a]+2.0*rad>1000.0) add(a,n+1);
    if(py[a]-pr[a]-2.0*rad<0.0) add(a,n+2);
    if(py[a]+pr[a]+2.0*rad>1000.0) add(a,n+3);
  }
  ncomp=0;
  for(a=0;a<n+4;a++) {
    if(comp[a]==-1) MLX(a,ncomp++);
    //printf("%d ",comp[a]);
  }
  return (comp[n]!=comp[n+1] && comp[n]!=comp[n+2] && comp[n]!=comp[n+3] && 
	  comp[n+1]!=comp[n+2] && comp[n+1]!=comp[n+3] && comp[n+2]!=comp[n+3]);
}	

int main() {
  double rad1,rad2;
  int a;
  scanf("%d",&n);
  for(a=0;a<n;a++) scanf("%lf %lf %lf\n",&px[a],&py[a],&pr[a]);
  rad1=0.0;
  rad2=1000.0;
  while(rad2-rad1>0.00000001) {
   // printf("%lf : ",(rad2+rad1)/2.0);
    if(solve((rad2+rad1)/2.0)) {
      //printf("YES\n");
      rad1=(rad2+rad1)/2.0;
    }
    else {
      //printf("NO\n");
      rad2=(rad2+rad1)/2.0;
    }
  }
  printf("%lf\n",rad1);
}
    
