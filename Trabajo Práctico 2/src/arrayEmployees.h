/*
 * arrayEmployees.h
 *
 *  Created on: 15 may. 2020
 *      Author: Florencia Galeano
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;


#endif /* ARRAYEMPLOYEES_H_ */

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee
* \param len int Array length
* \return int Return (-1) if Error [Invalid length] - (0) if Ok
*
*/
int initEmployees(eEmployee* vec, int len);

/** \brief Searchs for a free space in the array (isEmpty=1)
 *
 * \param vec The array
 * \param len The size of the array
 * \return The index if there are any free positions or -1 if there aren't
 *
 */
int searchFreeSpace(eEmployee* vec, int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param vec employee
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployee(eEmployee* vec, int len, int id, char name[],char
lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee* vec, int len,int id);

/** \brief Modifies an employee (name,last name, sector or salary) and returns -1,1 or 0
 *
 * \param
 * \param
 * \param
 * \return 1 if the employee was removed, 0 if the user cancelled the modification
and -1 if id not found, invalid length or NULL pointer
 *
 */
int modifyEmployee(eEmployee* vec, int len,int id);

/** \brief Shows the options of the fields to modify and returns the chosen option
 *
 * \return The chosen option
 *
 */
char showMenuModify();

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or if can't find a employee] - (0)
if the user didn't confirm and 1 if OK
*
*/
int removeEmployee(eEmployee* vec, int len, int id);

/** \brief Shows the options of the report menu and returns the chosen option
 *
 * \return The chosen option
 *
 */
char reportsMenu();

/** \brief Shows an employee
 *
 * \param employee The employee to show
 *
 */
void showEmployee(eEmployee employee);

/** \brief
 *
 * \param vec Array of employees
 * \param len Size of the array
 * \return int
 *
 */
int printEmployees(eEmployee* vec, int len);

/** \brief Allows the user to know more about salaries and the employees
 *
 * \param vec Array of employees
 * \param len Size of the array
 *
 */
void report(eEmployee vec[],int len);

/** \brief Adds all the salaries of the employees
 *
 * \param vec Array of the employees
 * \param len Size of the array
 * \return The addition of all the salaries
 *
 */
float addSalaries(eEmployee vec[],int len);

/** \brief Counts the quantity of employees
 *
 * \param vec Array of the employees
 * \param len Size of the array
 * \return The quantity of employees
 *
 */
int countEmployees(eEmployee vec[],int len);

/** \brief Counts the quantity of employees that earn more money than the average
 *
 * \param vec Array of the employees
 * \param len Size of the array
 * \param averageSalary que average of all the salaries
 * \return The quantity of employees who earn more money than the average
 *
 */
int countEmployeesHighestSalary(eEmployee vec[],int len,float averageSalary);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee* vec, int len, int order);

/** \brief Shows the reports about the salaries of the employees
*
* \param list Employee
* \param the addition of all the salaries
* \param the average salary
* \param the quantity of employees that earn more than the average
*
*/
void showSalariesReport(float totalSalaries,float averageSalaries,int employeesHighestPaid);
