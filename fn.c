#include<stdio.h>
inline int inpu()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;)
{
p=getchar_unlocked();
};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}

return noRead;
};
inline long long int linpu()
{
long long  int noRead=0;
char p=getchar_unlocked();
for(;p<33;)
{
p=getchar_unlocked(); 
};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();

};
return noRead;
}



long long int func(long long int a[],long long int b[],int l,int h,int i)
  {
     int mid=0;
     if(l==h)
     {
       b[i]=a[h];
       return b[i];
     }
     mid=l+(h-l)/2;
    b[i]=func(a,b,l,mid,2*i+1)+func(a,b,mid+1,h,2*i+2);
     return b[i];
  }
  long long int getsum(long long int b[],int l,int h,int q,int r,int i)
 {
   int m;
    if(l>=q&&h<=r)
     {
       //printf("%lld(%d)\t",b[i],i);
       return b[i];
      }
    if(h<q||l>r)
     return 0;
    m=l+(h-l)/2;
    return (getsum(b,l,m,q,r,2*i+1)+getsum(b,m+1,h,q,r,2*i+2));
 }
void update(long long int b[],int l,int h,int q,int i,long long int t)
 {
   int mid;   
     
    if(q<l||q>h)
      return;
     if(q==l&&q==h)
      { 
         b[i]=b[i]+t;
         printf("%lld\t",b[i]);
         return;
      }
     if(q>l&&q<h)
      {
         b[i]=b[i]+t;
         printf("%lld\t",b[i]);
       }
       mid=l+(h-l)/2;
         update(b,l,mid,q,2*i+1,t);
         update(b,mid+1,h,q,2*i+2,t);
       
  }

int main()
{
  int t,m,n,x,y,p,q,r,i,j;
  
long long int a[100002],b[100002],ans=0,temp;
   long long int f;
int l[100002],h[100002];
  n=inpu();
 
  for(i=0;i<n;i++)
  {
     a[i]=linpu();
     
  }
  temp=func(a,b,0,n-1,0);
  
  for(i=0;i<n;i++)
  {
     l[i]=inpu();
     h[i]=inpu();
     //f[i]=getsum(b,0,n-1,l-1,h-1,0);
     //printf("%lld\t",f[i]);
     
   }

   t=inpu();
	
  while(t--)
  {
      ans=0;
      p=inpu();
      q=inpu();
      r=inpu();
      if(p==1)
     {
         
        temp=r-a[q-1];
        a[q-1]=r;
        
        update(b,0,n-1,q-1,0,temp);   
        
        
      }
       else
     {
          for(j=q;j<=r;j++)
          {
             f=getsum(b,0,n-1,l[j-1]-1,h[j-1]-1,0);
             ans=ans+f;
          }
          printf("%lld\n",ans);
     }
   }
  return 0;
}



