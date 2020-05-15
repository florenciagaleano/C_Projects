/*
 * arrayEmployees.c
 *
 *  Created on: 15 may. 2020
 *      Author: Florencia Galeano
 */
#include "arrayEmployees.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"


int initEmployees(eEmployee* vec, int len)
{
    int returnValue=-1;

    if(len>0&&vec!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            vec[i].isEmpty=1;
        }

        returnValue=0;
    }

    return returnValue;
}

int searchFreeSpace(eEmployee* vec, int len)
{
    int returnValue=-1;

    if(len>0&&vec!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            if(vec[i].isEmpty==1)
            {
                returnValue=i;
                break;
            }
        }
    }

    return returnValue;
}

int findEmployeeById(eEmployee* vec, int len,int id)
{
    int returnValue=-1;

    if(len>0&&vec!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            if(vec[i].id==id&&vec[i].isEmpty==0)
            {
                returnValue=i;
                break;
            }
        }
    }

    return returnValue;
}

//////////////////////OPTION 1///////////////////////////////////
int addEmployee(eEmployee* vec, int len, int id, char name[],char
lastName[],float salary,int sector)
{
    int index;
    int returnValue=-1;

    index=searchFreeSpace(vec,len);//looks for a free position in the array

    if(index!=-1&&len>0&&vec!=NULL)
    {
        vec[index].id=id;
        strcpy(vec[index].name,name);
        strcpy(vec[index].lastName,lastName);
        vec[index].salary=salary;
        vec[index].sector=sector;
        vec[index].isEmpty=0;

        printf("\n%s %s's ID is: %d\n\n",vec[index].name,vec[index].lastName,id);

        returnValue=0;
    }

    return returnValue;
}

//////////////////OPTION 2////////////////////////
int modifyEmployee(eEmployee* vec, int len,int id)
{
    int index;
    int returnValue=-1;
    char confirm;

    index=findEmployeeById(vec,len,id);

    if(len>0&&vec!=NULL)
    {
        if(index!=-1)
        {
            printf("\n");
            showEmployee(vec[index]);
            confirm=getCharTwoOptions("\nIs this the employee you  want to modify?","ERROR\nEnter y or n:",'y','n');
            if(confirm=='y')
            {
                switch(showMenuModify())
                {
                    case 'a':
                        getString(vec[index].name,sizeof(vec[index].name),"Enter name:","ERROR\nEnter name again:");
                        break;
                    case 'b':
                        getString(vec[index].lastName,sizeof(vec[index].lastName),"Enter last name:","ERROR\nEnter last name:");
                        break;
                    case 'c':
                        vec[index].salary=getFloat("Enter salary:","ERROR\nEnter salary again");
                        break;
                    case 'd':
                        vec[index].sector=getInt("Enter sector (number):","ERROR\nEnter sector again:");
                        break;
                    default:
                        printf("Invalid option\n\n");
                        break;
                }
                returnValue=1;
            }else
            {
                returnValue=0;
            }
        }
    }

    return returnValue;
}

char showMenuModify()
{
    char option;

    system("cls");
    printf("   ***MODIFICATION MENU***\n\n");
    printf("a. Modify name\nb.Modify last name\nc.Modify salary\nd.Modify sector\n");
    printf("_____________________\n\n");
    option=getChar("Choose an option:","ERROR\nChoose option again:");

    return option;
}

////////////////////OPTION 3//////////////////////
int removeEmployee(eEmployee* vec, int len, int id)
{
    int index;
    char confirm;
    int returnValue=-1;

    index=findEmployeeById(vec,len,id);

    if(index!=-1&&vec!=NULL&&len>0)
    {
        showEmployee(vec[index]);
        confirm=getCharTwoOptions("\nAre you sure you want to remove the employee? (y/n)","ERROR\nEnter y or n:",'y','n');
        if(confirm=='y')
        {
            vec[index].isEmpty=1;
            returnValue=1;
        }else
        {
            returnValue=0;
        }
    }

    return returnValue;
}

////////////OPTION 4//////////////
void report(eEmployee vec[],int len)
{
    char option;
    float totalSalaries;
    int quantityOfEmployees;
    int quantityEmployeesHighestSalaries;
    float averageSalary;
    int order;

    do
    {
        option=reportsMenu();

        switch(option)
        {
        case 'a':
            printf("\nIf you want the employees to be ordered in\ndown order enter 0, else enter 1\n");
            order=getIntTwoOptions("\nChoose the order:","ERROR\nEnter 1 or 0:",1,0);
            sortEmployees(vec,len,order);
            printEmployees(vec,len);
            break;
        case 'b':
            totalSalaries=addSalaries(vec,len);
            quantityOfEmployees=countEmployees(vec,len);
            averageSalary=totalSalaries/quantityOfEmployees;
            quantityEmployeesHighestSalaries=countEmployeesHighestSalary(vec,len,averageSalary);
            showSalariesReport(totalSalaries,averageSalary,quantityEmployeesHighestSalaries);
            break;
        case 'c':
            break;
        default:
            printf("Invalid option\n");
        }
        system("pause");
    }while(option!='c');

}

int printEmployees(eEmployee* vec, int len)
{
    system("cls");
    printf("           ***LIST OF EMPLOYEES***\n\n");
    printf("  ID         Name     Last name    Salary    Sector\n");
    for(int i=0;i<len;i++)
    {
        if(vec[i].isEmpty==0)
        {
            showEmployee(vec[i]);
        }
    }

    return 0;
}

void showEmployee(eEmployee employee)
{
    printf(" %4d | %10s | %10s |  %5.2f  | %1d\n",employee.id,employee.name,employee.lastName,employee.salary,employee.sector);
}

float addSalaries(eEmployee vec[],int len)
{
    int total=0;

    for(int i=0;i<len;i++)
    {
        if(vec[i].isEmpty==0)
        {
            total=total+vec[i].salary;
        }
    }

    return total;
}

int countEmployees(eEmployee vec[],int len)
{
    int counter=0;

    for(int i=0;i<len;i++)
    {
        if(vec[i].isEmpty==0)
        {
            counter++;
        }
    }

    return counter;
}

int countEmployeesHighestSalary(eEmployee vec[],int len,float averageSalary)
{
    int counter=0;

    for(int i=0;i<len;i++)
    {
        if(vec[i].isEmpty==0&&vec[i].salary>averageSalary)
        {
            counter++;
        }
    }

    return counter;
}

char reportsMenu()
{
    char option;

    system("cls");
    printf("   ***REPORTS MENU***\n\n");
    printf("a.List of the employees order by\nname and sector\n\n");
    printf("b.Total of all the salaries, average salary and number \nof employees that earn more than the average\n\n");
    printf("c.Exit\n");
    printf("__________________________________________________________\n\n");

    option=getChar("Choose an option:","ERROR\nChoose the option again:");

    return option;
}

void showSalariesReport(float totalSalaries,float averageSalaries,int employeesHighestPaid)
{
    system("cls");
    printf("   ***SALARIES REPORT***\n\n")  ;
    printf("Total salaries: %.3f\n\nAverage salary: %.3f\n\nQuantity of employees who earn more than the average: %d\n\n",totalSalaries,averageSalaries,employeesHighestPaid);
}

int sortEmployees(eEmployee* vec, int len, int order)
{
    eEmployee auxEmployee;
    int retorno=-1;

    if(len>0&&vec!=NULL)
    {
        for(int i=0;i<len-1;i++)
        {
            for(int j=i+1;j<len;j++)
            {
               if(vec[i].isEmpty==0&&vec[j].isEmpty==0)
               {
                   switch(order)
                    {
                    case 0:
                        if(vec[i].sector>vec[j].sector)
                        {
                            auxEmployee=vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxEmployee;
                        }else if(vec[i].sector==vec[j].sector&&stricmp(vec[i].name,vec[j].name)>0)
                        {
                            auxEmployee=vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxEmployee;
                        }
                        break;
                    case 1:
                        if(vec[i].sector<vec[j].sector)
                        {
                            auxEmployee=vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxEmployee;
                        }else if(vec[i].sector==vec[j].sector&&stricmp(vec[i].name,vec[j].name)<0)
                        {
                            auxEmployee=vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxEmployee;
                        }
                        break;
                }//fin del switch

                retorno=0;

               }

            }
        }
    }

    return retorno;
}

