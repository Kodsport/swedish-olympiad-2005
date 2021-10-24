#include <stdio.h>

int main(){
  int tid, mogen[1002],antmogna,n,a,b;
  scanf("%d",&n);
  scanf("%d",&tid);
  /* Sätt alla tomater till omogna, lägg till en på varje sida för enkelhets skull */
  for(a=0;a<=n+1;a++) mogen[a]=-1;
  for(a=0;a<3;a++){
    scanf("%d",&b);
    /* Sätt tomaten till mogen dag 0 */
    mogen[b]=0;
  }
  antmogna=3;
  /* Loopa över antalet dagar */
  for(a=0;a<tid;a++)
    /* Loopa över antalet tomater */
    for(b=1;b<=n;b++)
      /* Om granntomaterna mognade igår, så markera tomaten som mogen idag */
      if(mogen[b]==-1 && (mogen[b-1]==a || mogen[b+1]==a)) {
        mogen[b]=a+1;
        antmogna++;
      }
  printf("%d\n", antmogna);
  return 0;
}
