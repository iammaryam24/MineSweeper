#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 9
char vis[N][N]; int mine[N][N];


void init(){ srand(time(NULL)); for(int i=0;i<N;i++) for(int j=0;j<N;j++){ vis[i][j]=0; mine[i][j]=0; }
int placed=0; while(placed<10){ int r=rand()%N, c=rand()%N; if(!mine[r][c]){ mine[r][c]=1; placed++; }} }


int adjcount(int r,int c){ int cnt=0; for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){ int rr=r+i, cc=c+j; if(rr>=0&&rr<N&&cc>=0&&cc<N) cnt += mine[rr][cc]; } return cnt; }


void show(){ printf(" "); for(int j=0;j<N;j++) printf("%d", j); printf("
");
for(int i=0;i<N;i++){ printf("%d ", i); for(int j=0;j<N;j++){
if(vis[i][j]){ if(mine[i][j]) printf("*"); else printf("%d", adjcount(i,j)); }
else printf("#"); }
printf("
"); }
}


int main(){ init(); while(1){ show(); int r,c; printf("Row Col to open (-1 -1 to quit): "); scanf("%d %d", &r,&c); if(r==-1) break; if(r<0||r>=N||c<0||c>=N){ printf("Invalid
"); continue; }
if(mine[r][c]){ printf("BOOM! Game over
"); vis[r][c]=1; show(); break; }
vis[r][c]=1; // could expand zero-adj with recursion (omitted for brevity)
}
return 0;
}