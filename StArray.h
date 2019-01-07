#ifndef _STARRAY_H_
#define _STARRAY_H_
#include "Student.h"
#include "Proj.h"
class StArray
{
  private:
    Student *student_db[MAX_STUDENT_NUM];
    int num_of_students;

  public:
	StArray();
    ~StArray();
    bool addStudent(int student_id, char* p_student_name);
    bool addEE_Course(int student_id, int course_num, char *p_course_name, int num_of_exercises, double exercise_weight);
    bool addCS_Course(int student_id, int course_num, char *p_course_name, int num_of_exercises, double exercise_weight, bool takef, char *p_book_name);
    bool setHwGrade(int student_id, int course_num, int exercise_num, int exercise_grade);
    bool setExamGrade(int student_id, int course_num, int exam_grade);
    bool setFactor(int course_num, int factor_val);
    bool printStudent(int student_id) ;/*change to not const because find indx is not const*/
    void printAll() ;
    void resetStArray();
};
#endif