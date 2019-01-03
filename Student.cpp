
#include "Student.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;

Student::Student(int person_id, char* p_person_name):
	Person(person_id, p_person_name), num_of_ee_courses_(0), num_of_cs_courses_(0), p_ee_course_array_{ nullptr }, p_cs_course_array_{ nullptr }{}

int Student::getCourseCnt() const{
	return num_of_ee_courses_ + num_of_cs_courses_;
}

bool Student::addEE_Course(EE_Course* p_ee_course) {
	int first_free_pointer_ = first_free_pointer((Course**)p_ee_course_array_);
	char* p_ee_course_name = p_ee_course->getName();
	if (p_ee_course == nullptr || course_already_exist(p_ee_course, (Course**)p_ee_course_array_) == 1 || first_free_pointer_==-1)return false;
	p_ee_course_array_[first_free_pointer_]=new EE_Course(p_ee_course->getNum(), p_ee_course_name, p_ee_course->getHwNum, p_ee_course->getHwWeigh);
	p_ee_course_array_[first_free_pointer_]->setExamGrade(p_ee_course->getExamGrade());/*exam grade*/
	p_ee_course_array_[first_free_pointer_]->setFactor(p_ee_course->getFctor());/*factor*/
	int i;
	for (i = 0; i < p_ee_course->getHwNum; i++) {
		p_ee_course_array_[first_free_pointer_]->setHwGrade(i, p_ee_course->getHwGrade(i));
	}

	delete[] p_ee_course_name;
	num_of_ee_courses_++;
	return true;
}

bool Student::addCS_Course(CS_Course* p_cs_course) {
	int first_free_pointer_ = first_free_pointer((Course**)p_cs_course_array_);
	char* p_cs_course_name = p_cs_course->getName;
	char* p_book_name = p_cs_course->getBook;
	if (p_cs_course == nullptr || course_already_exist(p_cs_course, (Course**)p_cs_course_array_) == 1 || first_free_pointer_ == -1) return false;
	p_cs_course_array_[first_free_pointer_] = new CS_Course(p_cs_course->getNum(), p_cs_course_name, p_cs_course->getHwNum, p_cs_course->getHwWeigh, p_cs_course->isTakef, p_book_name);
	p_cs_course_array_[first_free_pointer_]->setExamGrade(p_cs_course->getExamGrade());/*exam grade*/
	int i;
	for (i = 0; i < p_cs_course->getHwNum; i++) {
		p_cs_course_array_[first_free_pointer_]->setHwGrade(i, p_cs_course->getHwGrade(i));
	}
	delete[] p_cs_course_name;
	delete[] p_book_name;
	num_of_ee_courses_++;
	return true;
}


EE_Course* Student::getEE_Course(int ee_course_num) {
	int i;
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_ee_course_array_[i]->getNum == ee_course_num) return p_ee_course_array_[i];	
	}
	return nullptr;
}

CS_Course* Student::getCS_Course(int cs_course_num) {
	int i ;
	for(i=0;i<MAX_COURSE_NUM;i++) {
		if (p_cs_course_array_[i]->getNum == cs_course_num) return p_cs_course_array_[i];	
	}
	return nullptr;
}

int Student::getAvg()  const {
	int i,sum = 0,avg = 0;

	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_cs_course_array_[i] != nullptr) {
			sum += p_cs_course_array_[i]->getCourseGrade;
		}
		if (p_ee_course_array_[i] != nullptr) {
			sum += p_ee_course_array_[i]->getCourseGrade;
		}
	}
	avg = round(sum / getCourseCnt());
	return avg;
}
bool Student::rem_Course(int course_num) {
	int i;
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_cs_course_array_[i] != nullptr) {
			if (p_cs_course_array_[i]->getNum == course_num) {
				delete[] p_cs_course_array_[i];
				p_cs_course_array_[i] = nullptr;
				return 1;
			}
		}
		if (p_ee_course_array_[i] != nullptr) {
			if (p_ee_course_array_[i]->getNum == course_num) {
				delete[] p_ee_course_array_[i];
				p_ee_course_array_[i] = nullptr;
				return 1;
			}
		}
	}
	return 0;
}
void Student::print() const {
	char* p_student_name = getName();
	int i;
	cout << "Student name: " << *p_student_name << "\n";
	cout << "Student ID: " << getID << "\n";
	cout << "Average grade: " << getAvg  << "\n";
	cout << "EE course: " << "\n";
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_ee_course_array_[i] != nullptr) {
			char* p_course_name = p_ee_course_array_[i]->getName;
			cout << p_ee_course_array_[i]->getNum << " " << *p_course_name << " " << p_ee_course_array_[i]->getCourseGrade << "\n";
			delete[] p_course_name;
		}
	}
	cout << "CS course:" << "\n";
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if (p_cs_course_array_[i] != nullptr) {
			char* p_course_name = p_cs_course_array_[i]->getName;
			cout << p_cs_course_array_[i]->getNum << " " << *p_course_name << p_cs_course_array_[i]->getCourseGrade << "\n";
			delete[] p_course_name;
		}
	}
	delete[]p_student_name;
}

int course_already_exist(Course* p_new_course,Course* p_exist_cours[] ) {
	int i ;

	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if ((p_exist_cours[i] ) == nullptr) continue;
		if (p_new_course->getNum == p_exist_cours[i]->getNum) return 1;
	}
	return 0;

}

int first_free_pointer(Course* first_array_pointer[]) {
	int i ;
	for (i = 0; i < MAX_COURSE_NUM; i++) {
		if ((first_array_pointer[i]) == nullptr) return i;
	}
	return -1;
}

