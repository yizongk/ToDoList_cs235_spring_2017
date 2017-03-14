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

Task* add() {
  Task* a = new Task;
  std::cout << "What type of task is this? [G: Generic, S: Shopping, E: Event, H: Homework]  	▹ " ;
  std::string type;
  std::getline(std::cin, type);

  while ((type.length() != 1) or (type !="G" and type != "g" and type != "S" and type != "s" and type != "E" and type != "e" and type != "H" and type != "h")) {
    std::cout << "Invalid input.........[G: Generic, S: Shopping, E: Event, H: Homework] (ʃ_⌣̀ )  Enter again  ▹ " ;
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
  
  std::cout << "When is this task due?..[In this format: month/day/year, xx/xx/xxxx]  		▹ " ;
  std::string dueDateString;
  std::getline(std::cin, dueDateString);

  while (dueDateString.length() != 10 or dueDateString[2] != '/' or dueDateString[5] != '/') { // ****************  ***NOTE*** I am assuming rest are numbers
    std::cout << "Unrecognized format...[In this format: month/day/year, xx/xx/xxxx] (ʃ_⌣̀ )  Enter again  ▹ " ;
    std::getline(std::cin, dueDateString);
  }
  Date tempDate;
  tempDate.stringToInt(dueDateString);
  a->setDueDate(tempDate); 


  if (type == "G" or type == "g") {
    std::cout << "How would you describe this task?   						▹ " ;
    std::string description;
    std::getline(std::cin, description); 

    while(description[0] == ' ') { 
	  description.erase( description.begin() );									//Delete leading white space.
    }
    
    while (description == "") {
      std::cout << "You haven't enter anything, how would you describe this task?   		▹ " ;
      std::getline(std::cin, description); 	
        while(description[0] == ' ') { 
	  description.erase( description.begin() );									//Delete leading white space.
        }
    }
  
    a->setDescription(description); 
    std::cout << "Generic Task added succesfully ✔" << std::endl;
  } 
  else {								//This else is here to prevent 'description' from being repeated twice.
    std::cout << "How would you describe this task?  						▹ " ;   
    std::string description;
    std::getline(std::cin, description);

    while(description[0] == ' ') { 
	  description.erase( description.begin() );									//Delete leading white space.
    }
    
    while (description == "") {
      std::cout << "You haven't enter anything, how would you describe this task?   		▹ " ;
      std::getline(std::cin, description); 	
        while(description[0] == ' ') { 
	  description.erase( description.begin() );									//Delete leading white space.
        }
  }
  
  a->setDescription(description); 
  }


  if (type == "S" or type == "s") {
    std::cout << "What items do you need to buy? [Type your item and press ENTER to add another item. Type DONE to complete the list.]" << std::endl;
    std::string *tempCommand = new std::string;
    std::cout << " ▹ ";
    std::getline(std::cin, *tempCommand);

    ShoppingTask* S_a = new ShoppingTask(*a);

    while (*tempCommand != "DONE" and *tempCommand != "Done" and *tempCommand != "done") {
      //CODES TO ADD TO THIS LIST*************DONE
      if(*tempCommand != "") {
        S_a->add_list(tempCommand);
      }

      tempCommand = new std::string;
      std::cout << " ▹ ";
      std::getline(std::cin, *tempCommand);
    }
    std::cout << "Shopping-list Task added successfully ✔" << std::endl; 
    delete tempCommand;  
    delete a;
    return S_a;
  }


  if (type == "E" or type == "e") {
    EventTask* E_a = new EventTask(*a);
    std::string tempCommandLoc = "";
    std::string tempCommandTime = "";    

    std::cout << "Where is this event taking place?  						▹ " ;
    //CODES TO ADD LOCATION
    std::getline(std::cin, tempCommandLoc);
    if (tempCommandLoc == "") {
      E_a->set_location("No location specified.");
    } else {
      E_a->set_location(tempCommandLoc);
    }

    std::cout << "When is this event taking place?...[Format: Hours:Min[AM/PM] , xx:xx[AM/PM] ]   ▹ ";
    //CODES TO ADD TIME
    std::getline(std::cin, tempCommandTime);
    if (tempCommandTime == "") {
      E_a->set_time("No time specified.");
    } else {
      E_a->set_time(tempCommandTime);
    }

    std::cout << "Event Task added successfully ✔" <<std::endl;
    delete a;
    return E_a;
  }


  if (type == "H" or type == "h") {
    HomeworkTask* H_a = new HomeworkTask(*a);
    std::string tempCommandSub = "";   

    std::cout << "What subject is this homework for?  						▹ ";
    //CODES TO ADD SUBJECT
    std::getline(std::cin, tempCommandSub);
    if (tempCommandSub == "") {
      H_a->set_subject("No subject specified.");
    } else {
      H_a->set_subject(tempCommandSub);
    }

    std::cout << "Homework Task added successfully ✔" <<std::endl;
    delete a;
    return H_a;
  }
  
  return a;
}
 
void print(SortedLinkedList<Task> &inventory) {
  if (inventory.list_count() == 0) {
    std::cout << "You have no outstanding tasks!" << std::endl;
    return;
  }

  inventory.print(false);
  return;
}

void detailed(SortedLinkedList<Task> &inventory) {
  if (inventory.list_count() == 0) {
    std::cout << "You have no outstanding tasks!" << std::endl;
    return;
  }

  inventory.print(true);
  return;
}

void remove(SortedLinkedList<Task> &inventory) {
  if(inventory.list_count() == 0) {
    std::cout<<"You have no outstanding tasks!"<<std::endl;
    return;
  }
  
  int input = 0;
  std::cout<<"Which task would you like to remove?: 						▹";
  std::cin>>input;
  while (!std::cin or input < 1 or unsigned(input) > inventory.list_count()) {
    std::cout<<"You have enter an invalid input, please re-enter: 				▹";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin>>input;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  inventory.remove(input);
  std::cout<<"Task removed successfully ✔"<<std::endl;
}

void complete(SortedLinkedList<Task> &source, SortedLinkedList<Task> &target) {
  if(source.list_count() == 0) {
    std::cout << "You have no outstanding tasks!" << std::endl;
    return;
  }

  std::cout<<"Which task would you like to complete? (Enter a number according to PRINT): 	▹";
  int input;
  std::cin >> input;
  while (std::cin.fail()) {
    std::cout<<"invalid input, please enter a number: 						▹";
    std::cin.clear();
    std::cin.ignore(260,'\n');
    std::cin >> input;
  }
  std::cin.clear();
  std::cin.ignore(260, '\n');

  if(input < 1 or unsigned(input) > source.list_count()) {
    std::cout << input << " is out of range. Task was NOT marked as 'complete' ✘" << std::endl;
    return;
  }

  source.transfer(target, input);

  std::cout << "Task marked as 'complete' successfully ✔" << std::endl;
  return;
}

void completed(SortedLinkedList<Task>& cominventory) {
  if (cominventory.list_count() == 0) {
    std::cout << "You have no completed tasks!" << std::endl;
    return;
  }

  cominventory.print(false);
  return;
}

void save(SortedLinkedList<Task>& inventory) {
  if (inventory.list_count() == 0) {
    std::cout << "You have no outstanding tasks!" << std::endl;
    return;
  }

  std::string filenameinput;
  std::cout << "Where would you like to save your outstanding tasks? (Format: './filename') 	▹" ;
  //chks, while input size is less than 3 (must be 3 or more), and first two char are "./"
  std::getline(std::cin, filenameinput);
  while (filenameinput.size() < 3 or filenameinput[0] != '.' or filenameinput[1] != '/') {
    std::cout<< "Invalid input, enter in this format './filename'				▹" ;
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

    myfile << temptype << "|" << itr->data->dueDate() << "|" <<itr->data->description();
    if (temptype == 'S') {
      ShoppingTask* derived = dynamic_cast<ShoppingTask*>(itr->data);
      for (node<std::string>* shoplistitr = derived->getlisthead(); shoplistitr != NULL; shoplistitr = shoplistitr->p_next)
        myfile << "|" << *shoplistitr->data;
    }
    if (temptype == 'E') {
      EventTask* derived = dynamic_cast<EventTask*>(itr->data);
      myfile << "|" << derived->location() << "|" << derived->time();
    }
    if (temptype == 'H') {
      HomeworkTask* derived = dynamic_cast<HomeworkTask*>(itr->data);
      myfile << "|" << derived->subject();
    }
    myfile << std::endl;
  }
  myfile.close();  
  std::cout << "Tasks saved successfully! ✔" << std::endl;

  return;
}

void load(SortedLinkedList<Task>& inventory) {

  //codes to construct task, make a special consturctor to make this easier
  std::string line;
  std::string filenameinput;

  std::cout << "What file would you like to load outstanding tasks from? (Note: All existing tasks will be deleted, format: './filename')	▹" ;
  std::getline(std::cin, filenameinput);
  while (filenameinput.size() < 3 or filenameinput[0] != '.' or filenameinput[1] != '/') {
    std::cout<< "Invalid input, enter in this format './filename'				▹" ;
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
    std::cout << "Unable to open file, perhaps filename doesn't exist. ✘" << std::endl;
    return;
  }

  std::cout << "Tasks loaded successfully! ✔" << std::endl;
  return;
}

void exit() {
  std::cout << "	  		  		Brought to you by 'FanTasking.co' Ⓒ" << std::endl;
  std::cout << "         	(╥﹏╥)◞❀  bye...	║▌║█║▌│║▌║▌█" << std::endl;
  std::cout << "		     			'We are the OxygenTask, you're gonna need it when life drowns you... get it?'" << std::endl << std::endl << std::endl;
}

void help() {
  //std::cout << "⬤  ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ●  ⬤" << std::endl;
  std::cout << "☢ A list of valid commands ☢" << std::endl << std::endl;
  //std::cout << "⬤  ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ● ⚫ ●  ⬤" << std::endl << std::endl;

  std::cout << "♦ 'Add' 	: creates a new task. All newly created tasks are considered 'outstanding' (not completed) to start." << std::endl;
  std::cout << "♦ 'Print' 	: displays all of the outstanding tasks in order of due date." << std::endl;
  std::cout << "♦ 'Detailed' 	: print command, that also displays any specialized task information." << std::endl;
  std::cout << "♦ 'Remove' 	: deletes an existing outstanding task. The user specifies the task number to remove, as that task appears in the lists of the PRINT/DETAILED commands." << std::endl;
  std::cout << "♦ 'Complete' 	: marks a specific outstanding task as complete. The user specifies the task number to mark as complete, as that task appears in the lists of the PRINT/DETAILED commands." << std::endl;
  std::cout << "♦ 'Completed' 	: displays all of the completed tasks." << std::endl;
  std::cout << "♦ 'Save' 	: saves all of the outstanding tasks to a file. The user specifies the name of the file to create." << std::endl;
  std::cout << "♦ 'Load' 	: loads all of the tasks from a file as outstanding tasks. (Note: All existing tasks will be deleted)" << std::endl;
  std::cout << "♦ 'Exit' 	: exit the program. 	❀◟(._. ) Awww you want to leave me? ( ._.)◞❀" << std::endl;
  std::cout << "♦ 'Help' 	: list valid commands." << std::endl << std::endl;

  std::cout << "☢ Note these command are not case sensitive. 'Add' == 'ADD' == 'add', all works. ☢" << std::endl;
}


