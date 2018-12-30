
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Person.h"

Person ::Person(int person_id,*char p_person_name){
	person_id_(person_id),
	{
		strcpy(person_name_,p_person_name);
	}
}

int Person::getID()const {
	return person_id_;
}
char* Person::getName()const{
	
}