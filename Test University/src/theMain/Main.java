package theMain;

import java.util.ArrayList;

import allProgram.Course;
import allProgram.GraduateStudent;
import allProgram.Read;
import allProgram.Student;

public class Main {

	public static void main(String[] args) {
		
		ArrayList<Student> students=new ArrayList<Student>();
		ArrayList<Course> courses=new ArrayList<Course>();
		Read read=new Read();
		read.readData(students,courses);
		
		for(Student eachStudent:students)
		{
			eachStudent.printInfo();
		}
		
		for(Course eachCourse:courses)
		{
			eachCourse.printData();
		}
		
		
		

	}

}
