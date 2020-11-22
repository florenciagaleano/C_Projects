#include "LinkedList.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#endif // CONTROLLER_H_INCLUDED

int controller_chargeTxt(LinkedList*pArray,char*path);
int controller_addStudent(LinkedList*pArray);
int controller_edit(LinkedList*pArray);
int controller_remove(LinkedList*pArray);
int controller_sortStudents(LinkedList*pArray);
int controller_listStudents(LinkedList* pArray);
int controller_insertStudent(LinkedList*pArray);
int controller_clearList(LinkedList*pArray);
int controller_backupFile(LinkedList*pArray,char*path);
int controller_saveAsTxt(LinkedList*pArray,char*path);
