#include "StArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

int find_student_indx (int student_id , int num_of_students, Student *student_db[])
{
    if (num_of_students >= MAX_STUDENT_NUM ) return MAX_STUDENT_NUM;
    for( int i = 0 ; i < num_of_students ; i++)
    {
        if (student_db[i]->getID == student_id) return i;
    }
    return MAX_STUDENT_NUM;
}

bool StArray::addStudent(int student_id, char* p_student_name)
{
    if (num_of_students >= MAX_STUDENT_NUM || p_student_name == nullptr || find_student_indx(student_id , num_of_students , student_db) < MAX_STUDENT_NUM ) return FALSE;
    Student* new_student = new Student(student_id , p_student_name);
    student_db[num_of_students] = new_student;
    num_of_students++;
    return TRUE;
}


bool StArray::addEE_Course(int student_id, int course_num, char *p_course_name, int num_of_exercises, double exercise_weight)
{
    int student_indx = find_student_indx(student_id , num_of_students , student_db);
    if ( p_course_name == nullptr || num_of_exercises < 0 || ( exercise_weight < 0 || exercise_weight > 1) || student_indx == MAX_STUDENT_NUM) return FALSE;
    EE_Course new_course(course_num , p_course_name , num_of_exercises , exercise_weight);
    if ( student_db[student_indx]->addEE_Course(&new_course) == 0 ) return FALSE;
    return TRUE;
}

bool StArray::addCS_Course(int student_id, int course_num, char *p_course_name, int num_of_exercises, double exercise_weight, bool takef, char *p_book_name)
{
    int student_indx = find_student_indx(student_id , num_of_students , student_db);
    if ( p_course_name == nullptr || num_of_exercises < 0 || ( exercise_weight < 0 || exercise_weight > 1) || p_book_name == nullptr || student_indx == MAX_STUDENT_NUM) return FALSE;
    CS_Course new_course(course_num , p_course_name , num_of_exercises , exercise_weight , takef , p_book_name);
    if ( student_db[student_indx]->addCS_Course(&new_course) == 0 ) return FALSE;
    return TRUE;
}

bool StArray::setHwGrade(int student_id, int course_num, int exercise_num, int exercise_grade) {
	int student_indx = find_student_indx(student_id, num_of_students, student_db);
	if (student_indx == MAX_STUDENT_NUM) return 0;
	Course* p_course = student_db[student_indx]->getCS_Course(course_num);
	if (p_course == 0) {
		p_course=student_db[student_indx]->getEE_Course(course_num);
		if (p_course == 0)return 0;
	}
	if(p_course->setHwGrade(exercise_num, exercise_grade)==0)return 0;
	return 1;
}
bool StArray::setExamGrade(int student_id, int course_num, int exam_grade) {
	int student_indx = find_student_indx(student_id, num_of_students, student_db);
	if (student_indx == MAX_STUDENT_NUM) return 0;
	Course* p_course = student_db[student_indx]->getCS_Course(course_num);
	if (p_course == 0) {
		p_course = student_db[student_indx]->getEE_Course(course_num);
		if (p_course == 0)return 0;
	}
	if (p_course->setExamGrade(exam_grade) == 0)return 0;
	return 1;
}

bool StArray::setFactor(int course_num, int factor_val) {
	int i;
	int num_students=0;
	EE_Course* p_ee_course;
	for (i = 0; i < num_of_students; i++) {
		p_ee_course = student_db[i]->getEE_Course(course_num);
		if (p_ee_course == nullptr) continue;
		p_ee_course->setFactor(factor_val);
		num_students++;/*ask yonatan*/
	}
	return num_students > 0 ? 1 : 0;
}
bool StArray::printStudent(int student_id)  {

	int student_indx = find_student_indx(student_id, num_of_students, student_db);
	if (student_indx == MAX_STUDENT_NUM) return 0;
	student_db[student_indx]->print;
	return 1;
}
void StArray::printAll()  {
	int i;
	for (i = 0; i < num_of_students; i++) {
		printStudent(student_db[i]->getID);
	}
}
void StArray::resetStArray() {
	int i;
	for (i = 0; i < num_of_students; i++) {
		delete[] student_db[i];
		student_db[i] = nullptr;/*need to check that*/
	}
	
}