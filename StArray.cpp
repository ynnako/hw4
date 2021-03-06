#include "StArray.h"
#include "Proj.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;



/*
  Function:     find_student_indx
  Description:  gets a sutdent's id and returns it's index in the array
  Parameters:   student_id - the student's id
                num_of_students - how many students are stored in the array
                student_db - the array of the sutdents
  Return value: if the student exists the return value would be his index in the array
                if the student dosent exist the retur value would be a number greater than the array's limits
*/
int find_student_indx (int student_id , int num_of_students, Student *student_db[])
{
    if (num_of_students >= MAX_STUDENT_NUM ) return MAX_STUDENT_NUM;
    for( int i = 0 ; i < num_of_students ; i++)
    {
		if (student_db[i] == NULL) continue;
        if (student_db[i]->getID() == student_id) return i; // found the wanted student
    }
    return MAX_STUDENT_NUM;
}

/*
  Function:     StArray
  Description:  initializes an object
  Parameters:
  Return value:
*/
StArray::StArray() :
	num_of_students(0)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		student_db[i] = NULL;
	}
}

/*
  Function: ~StArray
  Description: Destructor
  Parameters:
  Return value:
*/
StArray::~StArray()
{
  resetStArray();
}

/*
  Function: addStudent
  Description:  sets an studnet object with the id and name. places the object in the student_db array
  Parameters:   student_id 
                p_student_name
  Return value: true if student was added. false if not
*/
bool StArray::addStudent(int student_id, char* p_student_name)
{
    if (num_of_students >= MAX_STUDENT_NUM || p_student_name == NULL || find_student_indx(student_id , num_of_students , student_db) < MAX_STUDENT_NUM ) return false;
    Student *new_student = new Student(student_id , p_student_name);
    student_db[num_of_students] = new_student;
    num_of_students++;
    return true;
}

/*
  Function:     addEE_Course
  Description:  adds a course to the ee array in the student's object
  Parameters:   student_id
                course_num 
                p_course_name 
                num_of_exercises 
                exercise_weight
  Return value: true if scceeded, false if not.
*/
bool StArray::addEE_Course(int student_id, int course_num, char *p_course_name, int num_of_exercises, double exercise_weight)
{
    int student_indx = find_student_indx(student_id , num_of_students , student_db); // if student doesnt exist the index would be MAX_STUDENT_NUM
    if ( p_course_name == NULL || num_of_exercises < 0 || ( exercise_weight < 0 || exercise_weight > 1) || student_indx == MAX_STUDENT_NUM) return false; // if parameters are illegal 
    EE_Course new_course(course_num , p_course_name , num_of_exercises , exercise_weight);
    if ( student_db[student_indx]->addEE_Course(&new_course) == 0 ) return false;
    return true;
}

/*
  Function:     addCS_Course
  Description:  adds a course to the cs array in the student's object
  Parameters:   student_id 
                course_num 
                p_course_name 
                num_of_exercises  
                exercise_weight 
                takef 
                p_book_name
  Return value: true if scceeded, false if not.
*/
bool StArray::addCS_Course(int student_id, int course_num, char *p_course_name, int num_of_exercises, double exercise_weight, bool takef, char *p_book_name)
{
    int student_indx = find_student_indx(student_id , num_of_students , student_db); // if student doesnt exist the index would be MAX_STUDENT_NUM
    if ( p_course_name == NULL || num_of_exercises < 0 || ( exercise_weight < 0 || exercise_weight > 1) || p_book_name == NULL || student_indx == MAX_STUDENT_NUM) return false; // if parameters are illegal
    CS_Course new_course(course_num , p_course_name , num_of_exercises , exercise_weight , takef , p_book_name);
    if ( student_db[student_indx]->addCS_Course(&new_course) == 0 ) return false;
    return true;
}

/*
  Function:     setHwGrade
  Description:  sets home work grade inside course
  Parameters:   student_id 
                course_num 
                exercise_num 
                exercise_grade
  Return value: true if scceeded, false if not.
*/
bool StArray::setHwGrade(int student_id, int course_num, int exercise_num, int exercise_grade) {
	int student_indx = find_student_indx(student_id, num_of_students, student_db);
	
	if (student_indx == MAX_STUDENT_NUM) return 0;
	Course* p_course = student_db[student_indx]->getCS_Course(course_num);
	if (p_course == NULL) {
		p_course=student_db[student_indx]->getEE_Course(course_num);
		if (p_course == NULL)return 0;
	}
	if(p_course->setHwGrade(exercise_num, exercise_grade) == 0)return 0;
	return 1;
}

/*
  Function:     setExamGrade
  Description:  sets the student's exam grade in a given course  
  Parameters:   student_id 
                course_num 
                exam_grade
  Return value: true if scceeded, false if not.
*/
bool StArray::setExamGrade(int student_id, int course_num, int exam_grade) {
	int student_indx = find_student_indx(student_id, num_of_students, student_db);
	if (student_indx == MAX_STUDENT_NUM) return 0;
	Course* p_course = student_db[student_indx]->getCS_Course(course_num);
	if (p_course == 0) {
		p_course = student_db[student_indx]->getEE_Course(course_num);
		if (p_course == 0) return 0;
	}
	if (p_course->setExamGrade(exam_grade) == 0) return 0;
	return 1;
}

/*
  Function:     setFactor
  Description:  sets factor for ee course
  Parameters:   course_num
                factor_val
  Return value: true if scceeded, false if not.
*/
bool StArray::setFactor(int course_num, int factor_val) {
	int i;
	int num_students=0;
	EE_Course* p_ee_course = NULL;
	for (i = 0; i < num_of_students; i++) {
		p_ee_course = student_db[i]->getEE_Course(course_num);
		if (p_ee_course == NULL) continue;
		p_ee_course->setFactor(factor_val);
		num_students++;
	}
	return num_students > 0 ? 1 : 0;
}

/*
  Function:     printStudent
  Description:  prints student's details'
  Parameters:   student_id
  Return value: true if scceeded, false if not.
*/
bool StArray::printStudent(int student_id)  {

	int student_indx = find_student_indx(student_id, num_of_students, student_db);
	if (student_indx == MAX_STUDENT_NUM) return 0;
	if (student_db[student_indx] == NULL) return 0;
	student_db[student_indx]->print();
	return 1;
}

/*
  Function:     printAll
  Description:  prints everything
  Parameters:
  Return value:
*/
void StArray::printAll()  {
	int i;
	for (i = 0; i < num_of_students; i++) {
		if(student_db[i] != NULL) printStudent(student_db[i]->getID());
	}
}

/*
  Function:     resetStArray
  Description:  removes any allocated memory and delets all the objects
  Parameters:
  Return value:
*/
void StArray::resetStArray() {
  for (int i = 0; i < MAX_STUDENT_NUM; i++) {
	if(student_db[i] != NULL)
    {
      delete student_db[i];
      student_db[i] = NULL;
    }
  }
  num_of_students = 0;
}
