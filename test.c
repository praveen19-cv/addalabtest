#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct club
{
	char name[20];
	int regno;
	char gen[7];
	float cgpa;
	int noao;
	int noap;
	char pos[20];
	int lvl;
};
void sort(float *a,int n)
{
	int i=0,j=0;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[i] > a[j])
			{
				float temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
}
int main()
{
	struct club c;
	
	FILE *fp,*fq;
	fp = fopen("club1.txt","w+");
	fq = fopen("club2.txt","w+");
	if(fp==NULL || fq==NULL)
	{
		printf("can't open the file\n");
	}
	float am[10],af[10],bm[10],bf[10];
	char ano='Y';
	int i=0,j=0;
	printf("club1:\n");
	while(ano=='Y')
	{
		printf("\nstudent-%d:\n",i+1+j);
		scanf("%s %d %s %f %d %d %s %d ",c.name,&c.regno,c.gen,&c.cgpa,&c.noao,&c.noap,c.pos,&c.lvl);
		fprintf(fp,"%s %d %s %f %d %d %s %d\n",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
		if(strcmp(c.gen,"male")==0)
		{
			am[i] = c.cgpa;
			i++;
		}
		else
		{
			af[j]=c.cgpa;
			j++;
		}
		printf("add another student(Y/N): ");
		scanf("%c",&ano);
		
	}
	i=0;j=0;
	ano = 'N';
	printf("\n");
	printf("club2:\n");
	while(ano=='Y')
	{
		printf("\nstudent-%d:\n",i+1+j);
		scanf("%s %d %s %f %d %d %s %d",c.name,&c.regno,c.gen,&c.cgpa,&c.noao,&c.noap,c.pos,&c.lvl);
		fprintf(fq,"%s %d %s %f %d %d %s %d\n",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
		if(strcmp(c.gen,"male")==0)
		{
			bm[i] = c.cgpa;
			i++;
		}
		else
		{
			bf[j]=c.cgpa;
			j++;
		}
		printf("add another student(Y/N): ");
		scanf("%c",&ano);
	}
	rewind(fp);
	rewind(fq);
	printf("awards for club1 candidates:\n");
	while(fscanf(fp,"%s %d %s %f %d %d %s %d",c.name,&c.regno,c.gen,&c.cgpa,&c.noao,&c.noap,c.pos,&c.lvl) != EOF)
	{
		if(c.cgpa>9 && c.noao>4 && c.lvl==1)
		{
			printf("%s - %d\n",c.name,c.regno);
		}
	}
	printf("awards for club2 candidates:\n");
	while(fscanf(fq,"%s %d %s %f %d %d %s %d",c.name,&c.regno,c.gen,&c.cgpa,&c.noao,&c.noap,c.pos,&c.lvl) != EOF)
	{
		if(c.cgpa>9 && c.noao>4 && c.lvl==1)
		{
			printf("%s - %d\n",c.name,c.regno);
		}
	}
	rewind(fp);
	rewind(fq);
	int n=sizeof(am)/sizeof(am[0]);
	sort(am,n);
	n=sizeof(af)/sizeof(af[0]);
	sort(af,n);
	n=sizeof(bm)/sizeof(bm[0]);
	sort(bm,n);
	n=sizeof(bf)/sizeof(bf[0]);
	sort(bf,n);
	printf("Top 2 boys and girls in club 1 :\n");
	while(fscanf(fp,"%s %d %s %f %d %d %s %d",c.name,&c.regno,c.gen,&c.cgpa,&c.noao,&c.noap,c.pos,&c.lvl) != EOF)
	{
		if(c.cgpa>9 && c.noao>4 && c.lvl==1 &&  strcmp(c.gen,"male")==0 && am[0] == c.cgpa)
			printf("boys :\n%s\n",c.name);
		else if(c.cgpa>9 && c.noao>4 && c.lvl==1 &&  strcmp(c.gen,"male")==0 && am[1] == c.cgpa)
			printf("%s\n",c.name);
		else if(c.cgpa>9 && c.noao>4 && c.lvl==1 &&  strcmp(c.gen,"female")==0 && af[0] == c.cgpa)
			printf("girls :\n%s\n ",c.name);
		else if(c.cgpa>9 && c.noao>4 && c.lvl==1 &&  strcmp(c.gen,"female")==0 && af[1] == c.cgpa)
			printf("%s\n ",c.name);
	
	}
	printf("Top 2 boys and girls in club 2 :\n");
	while(fscanf(fq,"%s %d %s %f %d %d %s %d",c.name,&c.regno,c.gen,&c.cgpa,&c.noao,&c.noap,c.pos,&c.lvl) != EOF)
	{
		if(c.cgpa>9 && c.noao>4 && c.lvl==1 &&  strcmp(c.gen,"male")==0 && bm[0] == c.cgpa)
			printf("boys :\n%s\n",c.name);
		else if(c.cgpa>9 && c.noao>4 && c.lvl==1 &&  strcmp(c.gen,"male")==0 && bm[1] == c.cgpa)
			printf("%s\n",c.name);
		else if(c.cgpa>9 && c.noao>4 && c.lvl==1 &&  strcmp(c.gen,"female")==0 && bf[0] == c.cgpa)
			printf("girls :\n%s\n ",c.name);
		else if(c.cgpa>9 && c.noao>4 && c.lvl==1 &&  strcmp(c.gen,"female")==0 && bf[1] == c.cgpa)
			printf("%s\n ",c.name);	
	}
	int m = (sizeof(am) + sizeof(af))/sizeof(am[0]);
	int f = (sizeof(bm) + sizeof(bf))/sizeof(bm[0]);
	float a[m],b[f];
	j=0;
	for(i=0;i<m;i++)
	{
		if(i < sizeof(am)/sizeof(am[0]))
			a[i] = am[i];
		else
		{
			a[i] = af[j];
			j++;
		}
	}
	sort(a,m);
	for(i=0;i<m;i++)
		printf("%f ",a[i]);
	printf("\n");
	j=0;
	for(i=0;i<m;i++)
	{
		if(i < sizeof(bm)/sizeof(bm[0]))
			b[i] = bm[i];
		else
		{
			b[i] = bf[j];
			j++;
		}
	}
	sort(b,f);
	fclose(fp);
	fclose(fq);
	fp = fopen("club1.txt","r+");
	while(fscanf(fp,"%s %d %s %f %d %d %s %d",c.name,&c.regno,c.gen,&c.cgpa,&c.noao,&c.noap,c.pos,&c.lvl) != EOF)
	{
		if(a[0] == c.cgpa)
		{
			char str[20];
			fseek(fp, -1 * (int)sizeof(c), SEEK_CUR);
			strcpy(str,"President");
			
			fprintf(fp,"%s %d %s %f %d %d %-20s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,str,c.lvl);	
			printf("club 1 - president modified!!\n");
		}
		if(a[1]==c.cgpa)
		{
			strcpy(c.pos,"Treasurer");
			fprintf(fp,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
			printf("club 1 - treasurer modified!!\n");
		}
		//fprintf(fp,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
	}
	while(fscanf(fq,"%s %d %s %f %d %d %s %d",c.name,&c.regno,c.gen,&c.cgpa,&c.noao,&c.noap,c.pos,&c.lvl) != EOF)
	{
		printf("\nreached\n");
		if(b[0] == c.cgpa)
		{
			strcpy(c.pos,"President");
			fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
			printf("club 2 - president modified!!\n");	
		}
		if(b[1]==c.cgpa)
		{
			strcpy(c.pos,"Treasurer");
			fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
			printf("club 2 - treasurer modified!!\n");
		}
		//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
		//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
			//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
			//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
				//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);	//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
					//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);	//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
						//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);	//fprintf(fq,"%s %d %s %f %d %d %s %d",c.name,c.regno,c.gen,c.cgpa,c.noao,c.noap,c.pos,c.lvl);
	}
	fclose(fp);
	fclose(fq);
	return 0;
}
