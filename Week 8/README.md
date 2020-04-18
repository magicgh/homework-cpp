# Task 1
## Contents
&emsp;&emsp;Define the public base class Person, which derives from the Teacher class and Cadre class, and define the TeacherCadre class, which derives from these two classes by means of multi-inheritance.
## Requirements
1. The public base class includes member variables such as name, age, gender, address, telephone, salary and the member function Show for output.
2. Teacher class has an extra member variable title, and Cadre class has an extra member variable position. Both classes have a member function Show for output.
3. Declare member functions in the class and implement them outside the class.
4. In order to avoid ambiguity in inheritance,  the public base class should be set as a virtual base class.
# Task 2
&emsp;&emsp;Define two interface classes IShape (containing pure virtual function area), IAction (containing pure virtual function run), a Bird class publicly inherits from two interface classes and overrides two pure virtual functions (the functions should print "I used the interface IShape/我用了接口IShape" and "I used the interface IAtion/我用了接口IAtion").  
&emsp;&emsp;Declare a bird object in main function, and then try to call the two functions respectively.