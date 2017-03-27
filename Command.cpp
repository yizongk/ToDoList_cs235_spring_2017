/***************************************************************
Title: To Do List
Author: Yi Zong Kuang
Date Created: mid feb 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 2 - To Do List
Description: The commands that the user will use are coded here
***************************************************************/

#include "Task.h"
#include <iostream>
#include <string>
#include <vector>
#include "Linkedlist.hxx"
#include "SortedLinkedList.hxx"
#include "TaskShopping.h"
#include "TaskEvent.h"
#include "TaskHomework.h"
#include <fstream>
#include <limits>
#include "colortext.h"

Task* add() {		//create different subclass object of Task depending on input from user, then return that object to an overhead function.
  Task* a = new Task;
  std::cout <<BOLDWHITE<< "What type of task is this? [G: Generic, S: Shopping, E: Event, H: Homework]  	▹ "<<RESET ;
  std::string type;
  std::getline(std::cin, type);

  while ((type.length() != 1) or (type !="G" and type != "g" and type != "S" and type != "s" and type != "E" and type != "e" and type != "H" and type != "h")) {
    std::cout <<BOLDRED<< "Invalid"<<RESET<<BOLDWHITE<<" input.........[G: Generic, S: Shopping, E: Event, H: Homework] "<<RESET<<GREEN<<"(ʃ_⌣̀ )"<<RESET<<BOLDWHITE<<"  Enter again  ▹ "<<RESET ;
    std::getline(std::cin, type);
  }

  if (type == "G" or type == "g") {
    a->setType("Generic");
  }
  if (type == "S" or type == "s") {
    a->setType("Shopping");
  }
  if (type == "E" or type == "e") {
    a->setType("Event");
  }
  if (type == "H" or type == "h") {
    a->setType("Homework");
  }
  
  std::cout <<BOLDWHITE<< "When is this task due?..[In this format: month/day/year, xx/xx/xxxx]  		▹ "<<RESET ;
  std::string dueDateString;
  std::getline(std::cin, dueDateString);

  while (dueDateString.length() != 10 or dueDateString[2] != '/' or dueDateString[5] != '/') { // ****************  ***NOTE*** I am assuming rest are numbers
    std::cout <<BOLDRED<< "Unrecognized format"<<RESET<<BOLDWHITE<<"...[In this format: month/day/year, xx/xx/xxxx] "<<RESET<<GREEN<<"(ʃ_⌣̀ )"<<RESET<<BOLDWHITE<<"  Enter again  ▹ "<<RESET ;
    std::getline(std::cin, dueDateString);
  }
  Date tempDate;
  tempDate.stringToInt(dueDateString);
  a->setDueDate(tempDate); 


  if (type == "G" or type == "g") {		//constructing a Generic task object
    std::cout <<BOLDWHITE<< "How would you describe this task?   						▹ "<<RESET ;
    std::string description;
    std::getline(std::cin, description); 

    while(description[0] == ' ') { 
	  description.erase( description.begin() );									//Delete leading white space.
    }
    
    while (description == "") {
      std::cout <<BOLDWHITE<< "You haven't enter anything, how would you describe this task?   		▹ "<<RESET ;
      std::getline(std::cin, description); 	
        while(description[0] == ' ') { 
	  description.erase( description.begin() );									//Delete leading white space.
        }
    }
  
    a->setDescription(description); 
    std::cout <<BOLDWHITE<< "Generic Task added succesfully "<<RESET<<BOLDGREEN<<"✔" <<RESET<< std::endl;
  } 
  else {								//This else is here to prevent 'description' from being repeated twice.
    std::cout <<BOLDWHITE<< "How would you describe this task?  						▹ "<<RESET ;   
    std::string description;
    std::getline(std::cin, description);

    while(description[0] == ' ') { 
	  description.erase( description.begin() );									//Delete leading white space.
    }
    
    while (description == "") {
      std::cout <<BOLDWHITE<< "You haven't enter anything, how would you describe this task?   		▹ "<<RESET ;
      std::getline(std::cin, description); 	
        while(description[0] == ' ') { 
	  description.erase( description.begin() );									//Delete leading white space.
        }
  }
  
  a->setDescription(description); 
  }


  if (type == "S" or type == "s") {		//constructing a Shopping task object
    std::cout <<BOLDWHITE<< "What items do you need to buy? [Type your item and press ENTER to add another item. Type DONE to complete the list.]" <<RESET<< std::endl;
    std::string *tempCommand = new std::string;
    std::cout <<BOLDWHITE<< " ▹ "<<RESET;
    std::getline(std::cin, *tempCommand);

    ShoppingTask* S_a = new ShoppingTask(*a);

    while (*tempCommand != "DONE" and *tempCommand != "Done" and *tempCommand != "done") {
      //CODES TO ADD TO THIS LIST
      if(*tempCommand != "") {
        S_a->add_list(tempCommand);
      }

      tempCommand = new std::string;
      std::cout <<BOLDWHITE<< " ▹ "<<RESET;
      std::getline(std::cin, *tempCommand);
    }
    std::cout <<BOLDWHITE<< "Shopping-list Task added successfully "<<RESET<<BOLDGREEN<<"✔" <<RESET<< std::endl; 
    delete tempCommand;  
    delete a;
    return S_a;
  }


  if (type == "E" or type == "e") {		//constructing a Event task object.
    EventTask* E_a = new EventTask(*a);
    std::string tempCommandLoc = "";
    std::string tempCommandTime = "";    

    std::cout <<BOLDWHITE<< "Where is this event taking place?  						▹ "<<RESET ;
    //CODES TO ADD LOCATION
    std::getline(std::cin, tempCommandLoc);
    if (tempCommandLoc == "") {
      E_a->set_location("No location specified.");
    } else {
      E_a->set_location(tempCommandLoc);
    }

    std::cout <<BOLDWHITE<< "When is this event taking place?...[Format: Hours:Min[AM/PM] , xx:xx[AM/PM] ]   ▹ "<<RESET;
    //CODES TO ADD TIME
    std::getline(std::cin, tempCommandTime);
    if (tempCommandTime == "") {
      E_a->set_time("No time specified.");
    } else {
      E_a->set_time(tempCommandTime);
    }

    std::cout <<BOLDWHITE<< "Event Task added successfully "<<RESET<<BOLDGREEN<<"✔" <<RESET<<std::endl;
    delete a;
    return E_a;
  }


  if (type == "H" or type == "h") {
    HomeworkTask* H_a = new HomeworkTask(*a);
    std::string tempCommandSub = "";   

    std::cout <<BOLDWHITE<< "What subject is this homework for?  						▹ "<<RESET;
    //CODES TO ADD SUBJECT
    std::getline(std::cin, tempCommandSub);
    if (tempCommandSub == "") {
      H_a->set_subject("No subject specified.");
    } else {
      H_a->set_subject(tempCommandSub);
    }

    std::cout <<BOLDWHITE<< "Homework Task added successfully "<<RESET<<BOLDGREEN<<"✔" <<RESET<<std::endl;
    delete a;
    return H_a;
  }
  
  return a;
}
 
void print(SortedLinkedList<Task> &inventory) {		//print outstanding task.
  if (inventory.list_count() == 0) {
    std::cout <<BOLDWHITE<< "You have no outstanding tasks!" <<RESET<< std::endl;
    return;
  }

  inventory.print(false);				//false means print, true means detailed print.
  return;
}

void detailed(SortedLinkedList<Task> &inventory) {
  if (inventory.list_count() == 0) {
    std::cout <<BOLDWHITE<< "You have no outstanding tasks!" <<RESET<< std::endl;
    return;
  }

  inventory.print(true);				//false means print, true means detailed print.
  return;
}

void remove(SortedLinkedList<Task> &inventory) {	//removes a outstanding task.
  if(inventory.list_count() == 0) {
    std::cout<<BOLDWHITE<<"You have no outstanding tasks!"<<RESET<<std::endl;
    return;
  }
  
  int input = 0;
  std::cout<<BOLDWHITE<<"Which task would you like to remove?: 						▹"<<RESET;
  std::cin>>input;
  while (!std::cin or input < 1 or unsigned(input) > inventory.list_count()) {	//chks for valid input.
    std::cout<<BOLDWHITE<<"You have enter an "<<RESET<<BOLDRED<<"invalid"<<RESET<<BOLDWHITE" input, please re-enter: 				▹"<<RESET;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin>>input;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  inventory.remove(input);
  std::cout<<BOLDWHITE<<"Task removed successfully "<<RESET<<BOLDGREEN<<"✔"<<RESET<<std::endl;
}

void complete(SortedLinkedList<Task> &source, SortedLinkedList<Task> &target) {		//There are two sortedlinklist, outstanding and completed, transfer a node from one to another.
  if(source.list_count() == 0) {
    std::cout <<BOLDWHITE<< "You have no outstanding tasks!" <<RESET<< std::endl;
    return;
  }

  std::cout<<BOLDWHITE<<"Which task would you like to complete? (Enter a number according to PRINT): 	▹"<<RESET;
  int input;
  std::cin >> input;
  while (std::cin.fail()) {
    std::cout<<BOLDRED<<"invalid"<<RESET<<BOLDWHITE" input, please enter a number: 						▹"<<RESET;
    std::cin.clear();
    std::cin.ignore(260,'\n');
    std::cin >> input;
  }
  std::cin.clear();
  std::cin.ignore(260, '\n');

  if(input < 1 or unsigned(input) > source.list_count()) {
    std::cout <<BOLDWHITE<< input << " is out of range. Task was NOT marked as 'complete' "<<RESET<<BOLDRED<<"✘" <<RESET<< std::endl;
    return;
  }

  source.transfer(target, input);

  std::cout <<BOLDWHITE<< "Task marked as 'complete' successfully "<<RESET<<BOLDGREEN<<"✔" <<RESET<< std::endl;
  return;
}

void completed(SortedLinkedList<Task>& cominventory) {			//print completed sorted link list.
  if (cominventory.list_count() == 0) {
    std::cout <<BOLDWHITE<< "You have no completed tasks!" <<RESET<< std::endl;
    return;
  }

  cominventory.print(false);					//false means print, true means detailed print
  return;
}

void save(SortedLinkedList<Task>& inventory) {			//saves outstanding list to a text file with a name that the user specify
  if (inventory.list_count() == 0) {
    std::cout <<BOLDWHITE<< "You have no outstanding tasks!" <<RESET<< std::endl;
    return;
  }

  std::string filenameinput;
  std::cout <<BOLDWHITE<< "Where would you like to save your outstanding tasks? (Format: './filename') 	▹"<<RESET ;
  //chks, while input size is less than 3 (must be 3 or more), and first two char are "./"
  std::getline(std::cin, filenameinput);
  while (filenameinput.size() < 3 or filenameinput[0] != '.' or filenameinput[1] != '/') {
    std::cout<<BOLDRED<< "Invalid"<<RESET<<BOLDWHITE" input, enter in this format './filename'				▹"<<RESET ;
    std::getline(std::cin, filenameinput);
  }
  filenameinput.erase(0,2);

  std::ofstream myfile;
  myfile.open(filenameinput);
  for (node<Task>* itr = inventory.get_node(1); itr != NULL; itr = itr->p_next ) {		//get the itr at the start of the list
    //writting to file
    char temptype;

    if(itr->data->type() == "Generic")
      temptype = 'G';
    else if (itr->data->type() == "Shopping")
      temptype = 'S';
    else if (itr->data->type() == "Event")
      temptype = 'E';
    else
      temptype = 'H'; 

    myfile << temptype << "|" << itr->data->dueDate() << "|" <<itr->data->description();		//set the delimiter
    if (temptype == 'S') {
      ShoppingTask* derived = dynamic_cast<ShoppingTask*>(itr->data);
      for (node<std::string>* shoplistitr = derived->getlisthead(); shoplistitr != NULL; shoplistitr = shoplistitr->p_next)
        myfile << "|" << *shoplistitr->data;
    }
    if (temptype == 'E') {
      EventTask* derived = dynamic_cast<EventTask*>(itr->data);						//dynamic cast to allow for proper formating of the output save file
      myfile << "|" << derived->location() << "|" << derived->time();
    }
    if (temptype == 'H') {
      HomeworkTask* derived = dynamic_cast<HomeworkTask*>(itr->data);
      myfile << "|" << derived->subject();
    }
    myfile << std::endl;
  }
  myfile.close();  
  std::cout <<BOLDWHITE<< "Tasks saved successfully! "<<RESET<<BOLDGREEN<<"✔" <<RESET<< std::endl;

  return;
}

void load(SortedLinkedList<Task>& inventory) {					//Read line by line from input file, as it read each line, it called the correct subclass's input_from_line().

  //codes to construct task
  std::string line;
  std::string filenameinput;

  std::cout <<BOLDWHITE<< "What file would you like to load outstanding tasks from? (Note: All existing tasks will be deleted, format: './filename')	▹"<<RESET ;
  std::getline(std::cin, filenameinput);
  while (filenameinput.size() < 3 or filenameinput[0] != '.' or filenameinput[1] != '/') {
    std::cout<<BOLDRED<< "Invalid"<<RESET<<BOLDWHITE<<" input, enter in this format './filename'				▹"<<RESET ;
    std::getline(std::cin, filenameinput);
  }
  filenameinput.erase(0,2);

  std::ifstream myfile (filenameinput);
  if (myfile.is_open()) {
    inventory.clear();				//codes to clear list

    while (getline(myfile, line)) { 
      //codes to check which type of task it is
      //delcare the correct task variable
      if (line[0] == 'G') {
        //declare Task a, call it's input_file_fct
        Task* a = new Task;
        a->input_from_line(line);				
        inventory.push_in(a);
      }
      if (line[0] == 'S') {
        //declare ShoppingTask a, call it's input_file_fct
        ShoppingTask* s_a = new ShoppingTask;	
        s_a->input_from_line(line);		
        Task*a = s_a;						
        inventory.push_in(a);
      }
      if (line[0] == 'E') {
        //declare EventTask a, call it's input_file_fct
        EventTask* e_a = new EventTask;		
        e_a->input_from_line(line);
        Task* a = e_a;						
        inventory.push_in(a);
      }
      if (line[0] == 'H') {
        //declare HomeworkTask a, call it's input_file_fct
        HomeworkTask* h_a = new HomeworkTask;	
        h_a->input_from_line(line);
        Task* a = h_a;						
        inventory.push_in(a);
      }
    }

    myfile.close();
  } else {
    std::cout <<BOLDWHITE<< "Unable to open file, perhaps filename "<<RESET<<BOLDRED<<"doesn't exist"<<RESET<<BOLDWHITE". "<<RESET<<BOLDRED<<"✘" <<RESET<< std::endl;
    return;
  }

  std::cout <<BOLDWHITE<< "Tasks loaded successfully! "<<RESET<<BOLDGREEN<<"✔" <<RESET<< std::endl;
  return;
}

void exit() {				//exit program
  std::cout <<BOLDGREEN<< "	  		  		Brought to you by 'FanTasking.co' Ⓒ" <<RESET<< std::endl;
  std::cout <<BOLDGREEN<< "         	(╥﹏╥)◞❀  bye...	"<<RESET<<BOLDBLACK<<"║▌║█║▌│║▌║▌█" <<RESET<< std::endl;
  std::cout <<BOLDGREEN<< "		     			'We are the OxygenTask, you're gonna need it when life drowns you... get it?'" <<RESET<< std::endl << std::endl << std::endl;
}

void help() {				//display all commands
  //std::cout << "⬤  ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ●  ⬤" << std::endl;
  std::cout <<BOLDGREEN<< "☢ A list of valid commands ☢" <<RESET<< std::endl << std::endl;
  //std::cout << "⬤  ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ●  ⬤" << std::endl << std::endl;

  std::cout <<BLUE<< "♦ 'Add' 	: creates a new task. All newly created tasks are considered 'outstanding' (not completed) to start." << std::endl;
  std::cout << "♦ 'Print' 	: displays all of the outstanding tasks in order of due date." << std::endl;
  std::cout << "♦ 'Detailed' 	: print command, that also displays any specialized task information." << std::endl;
  std::cout << "♦ 'Remove' 	: deletes an existing outstanding task. The user specifies the task number to remove, as that task appears in the lists of the PRINT/DETAILED commands." << std::endl;
  std::cout << "♦ 'Complete' 	: marks a specific outstanding task as complete. The user specifies the task number to mark as complete, as that task appears in the lists of the PRINT/DETAILED commands." << std::endl;
  std::cout << "♦ 'Completed' 	: displays all of the completed tasks." << std::endl;
  std::cout << "♦ 'Save' 	: saves all of the outstanding tasks to a file. The user specifies the name of the file to create." << std::endl;
  std::cout << "♦ 'Load' 	: loads all of the tasks from a file as outstanding tasks. (Note: All existing tasks will be deleted)" << std::endl;
  std::cout << "♦ 'Exit' 	: exit the program. 	❀◟(._. ) Awww you want to leave me? ( ._.)◞❀" << std::endl;
  std::cout << "♦ 'Help' 	: list valid commands." <<RESET<< std::endl << std::endl;

  std::cout <<BOLDWHITE<< "☢ Note these command are not case sensitive. 'Add' == 'ADD' == 'add', all works. ☢" <<RESET<< std::endl;
}



