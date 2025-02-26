package allProgram;

import java.util.ArrayList;

public class Student {
	
private String name;
private String id;
private ArrayList<Course> courses=new ArrayList<Course>();
public Student(String aName, String anId)
{
	name=aName;
	id=anId;
}

public void addCourse(Course aCourse)
{
	
	courses.add(aCourse);
	
	
}
public void printInfo()
{
	
	System.out.println(name +" with id:"+ id  + " is enrolled in :");
	for(Course eachCourse:courses)
	{
		System.out.println(eachCourse.getName() + " with "+ eachCourse.getCredits()+" credits");
	}
	
}

public String getName() {
	return name;
}

public void setName(String aName) {
	name = aName;
}

public String getId() {
	return id;
}

public void setId(String anId) {
	id = anId;
}

public ArrayList<Course> getCourses() {
	return courses;
}


}
