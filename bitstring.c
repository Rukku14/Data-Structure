#include<stdio.h>
#include<string.h>
void uni(char*,char*,char*);
void intersection(char*,char*,char*);
void difference(char*,char*,char*);
void main()
{
	char s1[20],s2[20],s3[20];
	printf("Enter the First string:");
	scanf("%s",s1);

	printf("Enter the Second string:");
	scanf("%s",s2);

	uni(s1,s2,s3);
	printf("\nThe union of the string is %s\n",s3);
	
	intersection(s1,s2,s3);
	printf("\nThe intersection of the string is %s\n",s3);

	difference(s1,s2,s3);
	printf("\nThe difference of the string is %s\n",s3);
}

	void uni(char *s1,char *s2,char *s3)
	{
		int i,l;
		l=strlen(s1);
		for(i=0;i<l;i++)
			{
				if(s1[i]=='0'&& s2[i]=='0')
				s3[i]='0';
				else
				s3[i]='1';
			}
		s3[i]='\0';
	}

	
	void intersection(char *s1,char *s2,char *s3)
	{
		int i,l;
		l=strlen(s1);
		for(i=0;i<l;i++)
			{
				if(s1[i]=='1'&& s2[i]=='1')
				s3[i]='1';
				else
				s3[i]='0';
			}
		s3[i]='\0';
	}

	
	void difference(char *s1,char *s2,char *s3)
	{
		int i,l;
		l=strlen(s1);
		for(i=0;i<l;i++)
			{
				if(s1[i]=='1'&& s2[i]=='0')
				s3[i]='1';
				else
				s3[i]='0';
			}
		s3[i]='\0';
	}


