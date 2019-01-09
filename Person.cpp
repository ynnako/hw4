
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Person.h"

/*
  Function     : Person
  Description  : constructor , initial values for objects in Person class
  Parameters   : person_id	   - person id
				 p_person_name - pointer to person name
  Return value : None
*/
Person ::Person(int person_id,char* p_person_name):
	person_id_(person_id){
	if (p_person_name != NULL)
	{
		int len_person_name = strlen(p_person_name);
		char* p_2_person_name = new char[len_person_name + 1];
		strcpy(p_2_person_name, p_person_name);
		p_person_name_ = p_2_person_name;
	}
	else p_person_name_ = NULL;
	
}

/*
  Function     : ~Person
  Description  : destructor for Course class , free dynamic allocations of objects
  Parameters   : None
  Return value : None
*/
Person ::~Person() {
	if(p_person_name_ != NULL) delete[] p_person_name_;

}

/*
  Function     : getID
  Description  : return person id
  Parameters   : None
  Return value : person id
*/
int Person::getID()const {
	return person_id_;
}

/*
  Function	   : getName
  Description  : returns a pointer to a clone of the person's name
  Parameters   : None
  Return value : None
*/
char* Person::getName()const{
	int len_person_name = strlen(p_person_name_);
	char* p_2_person_name = new char[len_person_name + 1];
	strcpy(p_2_person_name, p_person_name_);
	return p_2_person_name;	
}