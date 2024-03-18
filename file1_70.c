#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[20];
    int reg;
    char prog[20];
    char sch[20];
    float cgpa;
    int rank;
};

int main()
{
    FILE *fp, *nf;
    int n, i, j;
    printf("21MIC0070 -- C V Praveen Kumar\n");

    printf("Enter no of students: ");
    scanf("%d", &n);
	float a[n];
    struct student s[n];

    fp = fopen("student_70.txt", "w+");
    if (fp == NULL)
    {
        printf("Can't open the file");
        exit(1);
    }

    printf("Enter name, regno, program, school, CGPA of the students:\n");

    for (i = 0; i < n; i++)
    {
        printf("Student - %d:\n", i + 1);
        scanf("%s %d %s %s %f", s[i].name, &s[i].reg, s[i].prog, s[i].sch, &s[i].cgpa);

        a[i] = s[i].cgpa;
        s[i].rank = 0;

        fprintf(fp, "%s %d %s %s %f %d\n", s[i].name, s[i].reg, s[i].prog, s[i].sch, s[i].cgpa, s[i].rank);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int ran = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i] == s[j].cgpa)
            {
                s[j].rank = ran;
            }
        }
        ran++;
    }

    rewind(fp);  

    for (i = 0; i < n; i++)
    {

        fprintf(fp, "%s %d %s %s %f %d\n", s[i].name, s[i].reg, s[i].prog, s[i].sch, s[i].cgpa,s[i].rank);
    }

    printf("Student details:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s %d %s %s %.2f %d\n", s[i].name, s[i].reg, s[i].prog, s[i].sch, s[i].cgpa, s[i].rank);
    }

    fclose(fp);

    nf = fopen("monitor_70.txt", "w");
    if (nf == NULL)
    {
        printf("Can't open the file");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        if (s[i].cgpa < 4)
        {
            fprintf(nf, "%d %s\n", s[i].reg, s[i].name);
        }
    }

    fclose(nf);

    return 0;
}