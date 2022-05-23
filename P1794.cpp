//纯纯的暴力枚举，直接百度抄了
#include<stdio.h>
#include<stdlib.h>
 
 int main(){
     int minSize,maxSize,n;
     scanf("%d%d%d",&minSize,&maxSize,&n);
     int fishSize[n];
     for(int i=0;i<n;i++)
         scanf("%d",&fishSize[i]);
     int res=0;
     for(int k=minSize;k<=maxSize;k++){//k是从最小到最大 用if判断能否放入 
         bool flag=true;
         for(int i=0;i<n;i++){
             if(k>=fishSize[i]*2 && k<=fishSize[i]*10){// k会吃掉 fishSize[i]
                 flag=false;
                 break;
             }
             if(fishSize[i]<=k*10 && fishSize[i]>=k*2){//fishSize[i] 会吃掉 k 
                 flag=false;
                 break;
             }
         }
         if(flag==true){
             res++;
         } 
     }
     printf("%d",res);
     return 0;
 }
