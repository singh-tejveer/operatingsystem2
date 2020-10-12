#include<stdio.h>
#include<conio.h>


int replace(int a[],int n,int b[],int f,int i)
{
	int z,min=0,g=0,x,w;
	for(x=0;x<f;x++)
	{
		for(w=i+1;w<n;w++)
		{ 
			if(a[w]==b[x])
			{  
				if(min<w){
				
				min=w;
				z=x;}
				break;
			}
			if(w==n-1)
			{
				z=x;
				min=n+1;	
			}
		}
	}
	return z;
}
int main()
{
   int i,j,l,k,f,p=0,c=0,n,y=0;
   printf("Enter the length of reference string :");
   scanf("%d",&n);
   int a[n]; 
   printf("Enter the Frame size:");
   scanf("%d",&f);
   int b[f];
   printf("Enter the  string : ");
   for(i=0;i<n;i++)
   {
   scanf("%d",&a[i]);
   }
   for(i=0;i<f;i++)
   {
   	b[i]=-1;
   }
    
   for(i=0;i<n;i++)
   {   y=0;
       for(k=0;k<f;k++)
           {
              if(b[k]==a[i])
              {
              break;
              }
           }
           
        if(k==f && i<f)
          {
            b[i]=a[i];
            p++;
            y=1;
          }
        else if(k==f)
        {
        	l=replace(a,n,b,f,i);
        	b[l]=a[i];
            p++;
			y=1;	
		}
		
        for(j=0;j<f;j++)
        {
        printf("\t%d",b[j]);
        }
        if(y==1){
		
        printf("\tPage Fault No. %d",p);}
        printf("\n");
    }
printf("\n The number of Page Faults %d",p);
printf("\n The number of Page Hits %d",n-p);
return 0;
}
