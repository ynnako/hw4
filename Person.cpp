
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Person.h"

Person ::Person(int person_id,char* p_person_name):
	person_id_(person_id){
	int len_person_name = strlen(p_person_name);
	char* p_2_person_name = new char[len_person_name + 1];
	strcpy(p_2_person_name, p_person_name);
	p_person_name_ = p_2_person_name;
}

Person ::~Person() {
	delete[] p_person_name_;
}

int Person::getID()const {
	return person_id_;
}
char* Person::getName()const{
	int len_person_name = strlen(p_person_name_);
	char* p_2_person_name = new char[len_person_name + 1];
	strcpy(p_2_person_name, p_person_name_);
	return p_2_person_name;	
}