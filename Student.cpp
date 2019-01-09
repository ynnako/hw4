
#include "Student.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;


/*
  Function     : Student
  Description  : constructor , for Student class, initial values for objects in at Student class
  Parameters   : person_id     - person id
				 p_person_name - pointer to student name
  Return value :
*/
Student::Student(int person_id, char* p_person_name):
	Person(person_id, p_person_name), num_of_ee_courses_(0), num_of_cs_courses_(0)
	{
		int i ;
		for (i = 0 ; i < MAX_COURSE_NUM ; i++)
		{
			p_ee_course_array_[i] = NULL;
			p_cs_course_array_[i] = NULL;
		}
	}

/*
  Function	   : getCourseCnt
  Description  : return number of courses from 2 faculty : EE,CS
  Parameters   : None
  Return value : number of courses from 2 faculty : EE,CS
*/
int Student::getCourseCnt() const{
	return num_of_ee_courses_ + num_of_cs_courses_;
}

/*
  Function     : course_already_exist
  Description  : check if course is already exist in the coyrse array of the student
  Parameters   : p_new_course  - pointer to the new course
				 p_exist_cours - pointer for array course of the student
  Return value : '1' if the course already exist else 0;
*/
int course_already_exist(Course* p_new_course,Course* p_exist_cours[] ) {
	int i ;

	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if ((p_exist_cours[i] ) == NULL) continue;
		if (p_new_course->getNum() == p_exist_cours[i]->getNum()) return 1;
	}
	return 0;

}

/*
  Function     : first_free_pointer
  Description  : find the first index in array that in this index the value is NULL
  Parameters   :  first_array_pointer - pointer to array
  Return value : if array is full return -1 else return the index 
*/
int first_free_pointer(Course* first_array_pointer[]) {
	int i ;
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if ((first_array_pointer[i]) == NULL) return i;
	}
	return -1;
}

/*
  Function     : addEE_Course
  Description  : add EE_Course for a student
  Parameters   : p_ee_course -pointer for EE_Course class
  Return value : '1' if succssed to add the course else '0' 
*/
bool Student::addEE_Course(EE_Course* p_ee_course) {
	if (p_ee_course == NULL) return 0;
	int first_free_pointer_ = first_free_pointer((Course**)p_ee_course_array_);
	if ( course_already_exist(p_ee_course, (Course**)p_ee_course_array_) == 1 || first_free_pointer_==-1)return false;
	char* p_ee_course_name = p_ee_course->getName();
	p_ee_course_array_[first_free_pointer_]=new EE_Course(p_ee_course->getNum(), p_ee_course_name, p_ee_course->getHwNum(), p_ee_course->getHwWeigh());
	p_ee_course_array_[first_free_pointer_]->setExamGrade(p_ee_course->getExamGrade());/*exam grade*/
	p_ee_course_array_[first_free_pointer_]->setFactor(p_ee_course->getFctor());/*factor*/
	int i;
	for (i = 0; i < p_ee_course->getHwNum(); i++) {
		p_ee_course_array_[first_free_pointer_]->setHwGrade(i, p_ee_course->getHwGrade(i));
	}

	delete[] p_ee_course_name;
	num_of_ee_courses_++;
	return true;
}

/*
  Function     : addCS_Course
  Description  : add CS_Course for a student
  Parameters   : p_cs_course -pointer for CS_Course class
  Return value : '1' if succssed to add the course else '0'
*/
bool Student::addCS_Course(CS_Course* p_cs_course) {
	if (p_cs_course == NULL) return 0;
	int first_free_pointer_ = first_free_pointer((Course**)p_cs_course_array_);
	if ( course_already_exist(p_cs_course, (Course**)p_cs_course_array_) == 1 || first_free_pointer_ == -1) return false;
	char* p_cs_course_name = p_cs_course->getName();
	char* p_book_name = p_cs_course->getBook();
	p_cs_course_array_[first_free_pointer_] = new CS_Course(p_cs_course->getNum(), p_cs_course_name, p_cs_course->getHwNum(), p_cs_course->getHwWeigh(), p_cs_course->isTakef(), p_book_name);
	p_cs_course_array_[first_free_pointer_]->setExamGrade(p_cs_course->getExamGrade());/*exam grade*/
	int i;
	for (i = 0; i < p_cs_course->getHwNum(); i++) {
		p_cs_course_array_[first_free_pointer_]->setHwGrade(i, p_cs_course->getHwGrade(i));
	}
	delete[] p_cs_course_name;
	delete[] p_book_name;
	num_of_ee_courses_++;
	return true;
}

/*
  Function     : getEE_Course
  Description  : get a pointer for specific  EE_Course according to parameter 
  Parameters   : ee_course_num- course number
  Return value : return the pointer if the course exist else NULL
*/
EE_Course* Student::getEE_Course(int ee_course_num) {
	int i;
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_ee_course_array_[i] == NULL) continue;
		if (p_ee_course_array_[i]->getNum() == ee_course_num) return p_ee_course_array_[i];
	}
	return NULL;
}

/*
  Function     : getCS_Course
  Description  : get a pointer for specific  CS_Course according to parameter
  Parameters   : cs_course_num- course number
  Return value : return the pointer if the course exist else NULL
*/
CS_Course* Student::getCS_Course(int cs_course_num) {
	int i ;
	for(i=0;i<MAX_COURSE_NUM;i++) {
		if (p_cs_course_array_[i] == NULL) continue;
		if (p_cs_course_array_[i]->getNum() == cs_course_num) return p_cs_course_array_[i];
	}
	return NULL;
}

/*
  Function    : getAvg
  Description : return the total student avarage(includes cs courses and ee courses) 
  Parameters  : None
  Return value: srtudent avarage , value between 0-100
*/
int Student::getAvg()  const {
	int i;
	double avg = 0,sum = 0;
	if (getCourseCnt() == 0)return avg;
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_cs_course_array_[i] != NULL) {
			sum += p_cs_course_array_[i]->getCourseGrade();	
		}
		if (p_ee_course_array_[i] != NULL) {
			sum += p_ee_course_array_[i]->getCourseGrade();
		}
	}
	avg = 0.5+(sum / getCourseCnt());
	return (int)avg;
}

/*
  Function     : rem_Course
  Description  : remove a specific course from the list of student's course
  Parameters   : course_num - course number to remove
  Return value : '1' if succsses to remove else '0'
*/
bool Student::rem_Course(int course_num) {
	int i;
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_cs_course_array_[i] != NULL) {
			if (p_cs_course_array_[i]->getNum() == course_num) {
				delete p_cs_course_array_[i];
				p_cs_course_array_[i] = NULL;
				num_of_cs_courses_--;
				return 1;
			}
		}
		if (p_ee_course_array_[i] != NULL) {
			if (p_ee_course_array_[i]->getNum() == course_num) {
				delete p_ee_course_array_[i];
				p_ee_course_array_[i] = NULL;
				num_of_cs_courses_--;
				return 1;
			}
		}
	}
	return 0;
}

/*
  Function     : print
  Description  : print information about a student grades and courses
  Parameters   : None
  Return value : None
*/
void Student::print() const {
	char* p_student_name = getName();
	int i;
	cout << "Student name: " << p_student_name << "\n";
	cout << "Student ID: " << getID() << "\n";
	cout << "Average grade: " << getAvg()  << "\n";
	cout << "\n";
	cout << "EE courses:" << "\n";
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_ee_course_array_[i] != NULL) {
			char* p_course_name = p_ee_course_array_[i]->getName();
			cout << p_ee_course_array_[i]->getNum() << " " << p_course_name <<": " << p_ee_course_array_[i]->getCourseGrade() << "\n";
			delete[] p_course_name;
		}
	}
	cout << "\n";
	cout << "CS courses:" << "\n";
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_cs_course_array_[i] != NULL) {
			char* p_course_name = p_cs_course_array_[i]->getName();
			cout << p_cs_course_array_[i]->getNum() << " " << p_course_name << ": " <<  p_cs_course_array_[i]->getCourseGrade() << "\n";
			delete[] p_course_name;
		}
	}
	cout << "\n";
	delete[]p_student_name;
}





/*
  Function     : ~Student
  Description  : destructor ,remove all the allocated courses 
  Parameters   : None
  Return value : None
*/
Student::~Student()
{
	int i ;
	for (i = 0 ; i < MAX_COURSE_NUM ; i++)
	{
		if (p_ee_course_array_[i] != NULL)
		{
			rem_Course(p_ee_course_array_[i]->getNum());
		}
		if (p_cs_course_array_[i] != NULL)
		{
			rem_Course(p_cs_course_array_[i]->getNum());
		}
	}
}


