package allProgram;

import java.util.ArrayList;

public class Course {
private String name;
private int credits;
private ArrayList<Student> students=new ArrayList<Student>();
private static int counter=0;
public Course(String aName,int aCredits)
{
	name=aName;
	credits=aCredits;
	counter++;
}
public String getName()
{
	return name;
}
public int getCredits()
{
	return credits;
}
public void setName(String aName) {
	name = aName;
}
public void setCredits(int aCredits) {
	credits = aCredits;
}

public void addStudent(Student aStudent)
{
	students.add(aStudent);
}
public ArrayList<Student> getStudents() {
	return students;
}

 public void printData()
 {
	 System.out.println("Course name:"+ name);
	 System.out.println("Students enrolled:");
	 for(Student eachStudent: students)
	 {
	
		
			 System.out.println(eachStudent.getName());
		 
		 
	 }
 }
 public static int getCounter()
 {
	 return counter;
 }
 public static void setCounter(int aInput)
 {
	 counter=aInput;
 }

}
