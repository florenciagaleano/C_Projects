/*
 ============================================================================
 Name        : tp2.c
 Author      : Florencia Galeano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "validaciones.h"

#define QTY_EMPLOYEES 1000

/** \brief Shows the options of the menu and returns the option that the user chose
 *
 * \return The chosen option
 *
 */
int showMenu();

int main(void) {

	setbuf(stdout, NULL);

		eEmployee list[QTY_EMPLOYEES];
	    int id=1000;
	    char name[50];
	    char lastName[50];
	    float salary;
	    int sector;
	    int flagOption1=0;
	    char confirm='n';
	    int option;
	    int idParam;//this variable saves the id that the user enters to modify or remove an employee

	    if(!initEmployees(list,QTY_EMPLOYEES))
	    {
	        printf("Initialized screen");
	    }

	    do
	    {
	        system("cls");
	        option=showMenu();
	        system("cls");//system cls again for the menu to dissappear

	        switch(option)
	        {
	            case 1:
	            if(searchFreeSpace(list,QTY_EMPLOYEES)!=-1)//if the system is full the program will directly show a message to the user
	            {
	                printf("   ***ADD EMPLOYEE***\n\n");
	                getString(name,sizeof(name),"Enter name:","ERROR\nEnter name again:");
	                getString(lastName,sizeof(lastName),"Enter last name:","ERROR\nEnter last name again:");
	                salary=getFloat("Enter salary:","ERROR\nEnter salary again");
	                sector=getInt("Enter sector(number):","ERROR\nEnter sector:");

	                if(addEmployee(list,QTY_EMPLOYEES,id,name,lastName,salary,sector)!=-1)
	                {
	                    printf("\nThe employee has been added\n\n");
	                    id++;
	                    flagOption1=1;
	                }
	                else
	                {
	                    printf("\nSorry, can not add the employee\n\n");;
	                }
	            }
	            break;
	        case 2:
	            if(flagOption1)
	            {
	                printf("   ***MODIFY EMPLOYEE***\n\n");
	                idParam=getInt("Enter the ID of the employee you want to modify:","ERROR\nEnter ID again:");
	                switch(modifyEmployee(list,QTY_EMPLOYEES,idParam))
	                {
	                    case -1:
	                        printf("\nSorry,can not find the employee\n\n");
	                        break;
	                    case 0:
	                        printf("\nOperation cancelled\n\n");//the user didn't confirm
	                        break;
	                    default:
	                        printf("\nThe employee has been modified\n\n");
	                        break;
	                }
	            }
	            else
	            {
	                printf("\nFirst you have to charge an employee\n\n");
	            }
	            break;
	        case 3:
	            if(flagOption1)
	            {
	                printf("   ***REMOVE EMPLOYEE***\n\n");
	                idParam=getInt("Enter the ID of the employee you want want to modify:","ERROR\nEnter the ID again:");
	                switch(removeEmployee(list,QTY_EMPLOYEES,idParam))
	                {
	                    case -1:
	                        printf("\nSorry,can not find the employee\n\n");
	                        break;
	                    case 0:
	                        printf("\nOperation cancelled\n\n");//the user didn't confirm
	                        break;
	                    default:
	                        printf("\nThe employee has been removed\n\n");
	                        break;
	                }
	            }
	            else
	            {
	                printf("\nFirst you have to charge an employee\n\n");
	            }
	            break;
	        case 4:
	            if(flagOption1)
	            {
	                report(list,QTY_EMPLOYEES);
	            }else
	            {
	                printf("\nFirst you have to charge an employee\n\n");
	            }
	            break;
	        case 5:
	            confirm=getCharTwoOptions("Are you sure you want to exit? (y/n)","ERROR\nEnter y or n:",'y','n');
	            break;
	        default:
	            printf("Invalid option\n\n");
	            break;
	        }

	        system("pause");

	    }while(confirm=='n');

	    system("cls");//if the user chose exit the console is cleaned

	return EXIT_SUCCESS;
}

int showMenu()
{
    int option;

    printf("    ***EMPLOYEE MANAGEMENT***\n\n");
    printf("1.Add employee\n2.Modify employee\n3.Remove employee\n4.Reports\n5.Leave\n\n");
    printf("------------------------------------\n\n");
    option=getInt("Choose an option: ","\nERROR\nChoose a valid option: ");

    return option;
}
