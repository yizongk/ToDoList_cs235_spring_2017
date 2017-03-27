Build Instruction:
	1. In terminal, go to file directory.
 	2. type in "make" , without the quotation marks.
	3. type in "./test" to run program, without the quotation marks.

Parts complete:
	All parts of the project are completed.

Known bugs:
	* During the command "complete", if you type in "23dflko", it will read it as a valid input and take the leading interger "23" as the input and dump the "dflko".
	* When entering the due date for any task, if you enter a character or negative number, it will read it as a valid input.
	* When entering the due date for any task, it does not check whether the day, month or even year as valid, ex. 22/22/2222 is considered a valid date in current state of the program.
	* Will not alert you if the due date entered is in the past.
	* Task will not auto expire when present time go past the task's due date.
	
Program structure:
	Data type: 	Date, Task(contains Date), ShoppingTask(inherites Task, have linklist<string> private member), EventTask(inherites Task, have string private members), 
			HomeworkTask(inherites Task, have string private members).

  	Storage type: 	node, linkedlist, sortedlinkedlist(wrapper around linkedlist).
 	
	Aesthetic:	Colortext.h for colored text, and ascii symbols.

	General functions: Command.h/cpp, mainloop.h/cpp, main.h/cpp

	General program mindset:
		1. main.cpp will be in continous loop calling a function in mainloop.cpp, if mainloop.cpp return false, program terminates.
		2. mainloop.cpp will manage all commands to be entered by the user, calling the correct functions following each command inputed by user, will return true, unless 'exit' is inputed
		   from user, in which case, it will return false.
		3. command.cpp will the interface to interact with the data structures/storage in this program, namely sorted linked list, linkedlist, date object, task object etc.
 		4. most actual functions will be coded inside of each class (some trivial exceptions), command.cpp will merely acts as a bridge to connect all the data/storage class.
		5. there are two sorted linked list, one for completed task, and one for outstanding task, these are in the scope of main.cpp and are passed around as reference.

	Some specification of the algorithms used:
		1. Sortedlinkedlist merely go through the existing list and compare each value to find the right index to insert into, and insert at that index.
		2. Date class's private member are int, but have functions inside the class to convert string into int value, assuming the string is valid.
		3. Date class have a function to convert month and years into day (by *30 or *365, respectivaly), so to allow for easier comparison of different due date. 
		4. Moving task from outstanding to completed sortedlinkedlist are done by passing pointer round, not copying value.
		5. Node class uses a pointer to store data, because of the need to type_cast.
