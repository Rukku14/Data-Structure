#include<stdio.h>
void main()
{
int a[20],b[20],c[40],n1,n2,m,i,j,k;
printf("Enter the size of the 1st array:");
scanf("%d",&n1);
printf("Enter the 1st array element:");
for (i=0;i<n1;i++)
scanf("%d",&a[i]);
printf("Enter the size of the second array:");
scanf("%d",&n2);
printf("Enter the second array elements:");
for(j=0;j<n2;j++)
{
scanf("%d",&b[j]);
}
i=0;j=0;k=0;
m=n1+n2;
while(i<n1&&j<n2)
{
if(a[i]<=b[j])
{
c[k]=a[i];
i++;
k++;
}
else if(a[i]>b[j])
{
c[k]=b[j];
j++;
k++;
}
else
{
c[k]=a[i];
i++;
j++;
k++;
}
}
while(i<n1)
{
c[k]=a[i];
i++;
k++;
}
while(j<n2)
{
c[k]=b[j];
j++;
k++;
}
printf("Merged sorted=\t ");
for(i=0;i<k;i++)
printf("%d\n",c[i]);
}

