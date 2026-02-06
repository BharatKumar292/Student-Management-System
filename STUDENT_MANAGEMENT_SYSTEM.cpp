#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    float marks[5];
    float percentage;
    char grade;
};

// Function to Save Data
void saveToFile(Student std[], int n) {
    ofstream file("student.txt", ios::app);

    for (int i = 0; i < n; i++) {
        file<< "ID: " << std[i].id << endl;
        file << "Name: " << std[i].name << endl;
        file << "Age: " << std[i].age << endl;

        file << "Marks: ";
        for (int j = 0; j < 5; j++)
            file << std[i].marks[j] << " ";
        file << endl;

        file<< "Percentage: " << std[i].percentage << endl;
        file<< "Grade: " << std[i].grade << endl;
       file<< "-----------------------------" << endl;
    }
 

    file.close();
    cout << "Data saved to file\n";
}


// LOADING DATA
int  loadFromFile(Student std[]){
    ifstream file("student.txt");

    if (!file) {
        cout << "\nNo data file found!\n";
        return 1;
    }

  int  countStudents = 0;
    string word;

    while (file >> word) {
        if (word == "ID:") {
            file >> std[countStudents].id;
        }

        file >> word; // Name:
        file.ignore();
        getline(file, std[countStudents].name);

        file >> word; // Age:
        file >> std[countStudents].age;

        file >> word; // Marks:
        for (int i = 0; i < 5; i++) {
            file >> std[countStudents].marks[i];
        }

        file >> word; // Percentage:
        file >> std[countStudents].percentage;

        file >> word; // Grade:
        file >> std[countStudents].grade;
        file >> word; 
        
        countStudents++;
    }
    file.close();
  return countStudents;
}


// DISPLAY ALL STUDENTS

void display(Student std[], int total) {
    cout << "----------------------------------------------\n";
    cout << "| ID\tName\tAge\tPercentage\tGrade|\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < total; i++) {
        cout <<"| "<<std[i].id << "\t"
             <<std[i].
             name << "\t"
             << std[i].age << "\t"
             << std[i].percentage << "\t\t"
             << std[i].grade<< "    | " << endl;
    }
      cout << "----------------------------------------------\n";
}

// SEARCH BY ID

void searchByID(Student std[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (std[i].id == id) {
            cout << "\nStudent Found:\n";
            cout << "ID: " << std[i].id << endl;
            cout << "Name: " << std[i].name << endl;
            cout << "Age: " << std[i].age << endl;
            cout << "Percentage: " << std[i].percentage << endl;
            cout << "Grade: " << std[i].grade << endl;
            return;
        }
    }
    cout << "Not found!\n";
}

// SEARCH BY NAME

void searchByName(Student std[], int total, string name) {
    int find=0;
    for (int i = 0; i < total; i++) {
        if (std[i].name.find(name) != string::npos) {
            find++;
            cout << "\nID: " << std[i].id;
            cout << "\nName: " << std[i].name;
            cout << "\nAge: " << std[i].age;
            cout << "\nPercentage: " << std[i].percentage;
            cout << "\nGrade: " << std[i].grade;
            cout << "\n-----------------------------\n";
        }
    }
    if (find==0) 
    cout << "No match found!\n";
}


// SEARCH BY GRADE
void searchByGrade(Student std[], int total, char grade) {
    int count=0;
    for (int i = 0; i < total; i++) {
        if (std[i].grade == grade) {
            count++;
            cout << "\nID: " << std[i].id;
            cout << "\nName: " << std[i].name;
            cout<<"\nAge: " <<std[i].age;
            cout << "\nPercentage: " << std[i].percentage;
            cout << "\n-----------------------------\n";
        }
    }
    if (count==0) cout << "No students with grade " << grade << endl;
}

// SORTING BY NAME
void sortByName(Student std[], int total) {
    for (int i = 0; i < total - 1; i++){
        int minIndex=i;
        for (int j = i + 1; j < total; j++){
            if (std[j].name < std[minIndex].name){
                minIndex=j;
             }
        }
             Student temp=std[i];
             std[i]=std[minIndex];
             std[minIndex]=temp;
    }
    
    cout << "Below is sorted information.\n";
    
     
    cout << "----------------------------------------------\n";
    cout << "| ID\tName\tAge\tPercentage\tGrade|\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < total; i++) {
        cout <<"| "<<std[i].id << "\t"
             <<std[i].
             name << "\t"
             << std[i].age << "\t"
             << std[i].percentage << "\t\t"
             << std[i].grade<< "    | " << endl;
    }
      cout << "----------------------------------------------\n";

}
// SORTING BY PERCENTAGE
void sortByPercentage(Student std[], int total) {
    for (int i = 0; i < total- 1; i++){
        int minIndex=i;
        for (int j = i + 1; j<total; j++){
            if (std[j].percentage > std[i].percentage){
                minIndex=j;
            }
        }
           Student  temp=std[i];
           std[i]=std[minIndex];
           std[minIndex]=temp;
        }
                
    cout << "Below is sorted information.\n";
    cout << "----------------------------------------------\n";
    cout << "| ID\tName\tAge\tPercentage\tGrade|\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < total; i++) {
        cout <<"| "<<std[i].id << "\t"
             <<std[i].
             name << "\t"
             << std[i].age << "\t"
             << std[i].percentage << "\t\t"
             << std[i].grade<< "    | " << endl;
    }
      cout << "----------------------------------------------\n";
    
}
// SORTING BY AGE
void sortByAge(Student std[], int total) {
    for (int i = 0; i < total- 1; i++){
        int minIndex=i;
        for (int j = i + 1; j < total; j++){
            if (std[j].age < std[i].age){
                minIndex=j;
            }
        }
            Student temp=std[i];
            std[i]=std[minIndex];
            
            std[minIndex]=temp;
        }
    cout << "Below is sorted information.\n";
    cout << "----------------------------------------------\n";
    cout << "| ID\tName\tAge\tPercentage\tGrade|\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < total; i++) {
        cout <<"| "<<std[i].id << "\t"
             <<std[i].
             name << "\t"
             << std[i].age << "\t"
             << std[i].percentage << "\t\t"
             << std[i].grade<< "    | " << endl;
    }
      cout << "----------------------------------------------\n";


}


//UPDATE STUDENT

void updateStudent(Student std[], int total) {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;
   // Updating New Information 
    for (int i = 0; i < total; i++) {
        if (std[i].id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, std[i].name);

            cout << "Enter new age: ";
            cin >> std[i].age;

            cout << "Enter new marks:\n";
            float total = 0;
            for (int j = 0; j < 5; j++) {
                cin >> std[i].marks[j];
                total += std[i].marks[j];
            }

            std[i].percentage =(total / 500.0)*100;
          // Finding Grade 
          if (  std[i].percentage>= 85)   
              std[i].grade =   'A';
          else if ( std[i].percentage  >= 70)
             std[i].grade = 'B';
          else if (  std[i].percentage >= 50)  
             std[i].grade =  'C';
          else   std[i].grade =  'F';
    

            cout << "Record updated!\n";
            return;
        }
    }
    cout << "ID not found!\n";
}


// REWRITE FILE AFTER UPDATING
void rewriteFile(Student std[], int total) {       ofstream file("student.txt");
     
    for (int i = 0; i < total; i++) {
        file << "ID: " << std[i].id << endl;
        file<< "Name: " << std[i].name << endl;
        file << "Age: " << std[i].age << endl;

        file << "Marks: ";
        for (int j = 0; j < 5; j++)
            file<< std[i].marks[j] << " ";
        file << endl;

        file<< "Percentage: " << std[i].percentage << endl;
        file << "Grade: " << std[i].grade << endl;
        file<< "-----------------------------" << endl;
    }

    file.close();
    cout << "File rewritten.\n";
}


// DELETE STUDENT
int deleteStudent(Student std[], int total) {
    int id;
    cout << "Enter ID to delete: ";
    
    cin >> id;

    int index = -1;// declaration of index=-1 b/c to delete the id on this index..
    for (int i = 0; i < total; i++)
        if (std[i].id == id)
            index = i;

    if (index == -1) {
        cout << "Not found.\n";
        return total;
    }

    for (int i = index; i < total - 1; i++)
        std[i] = std[i + 1];  // id on index=i , becomes to next student this removes on the index's id information...'

    cout << "Record deleted!\n";
    return total - 1; // now now total students decrease by 1.
}


// Main Function
int main() { 

    Student std[100];
    int n=0;
     int choice;
    
    while (true) {
        int totalStd;
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Enter Students\n";
     cout << "2. Save to File\n";
        cout << "3. Load from File\n";
        cout << "4. Search\n";
        cout << "5. Sort\n";
        cout << "6. Update Student\n";
        cout << "7. Delete Student\n";
        cout << "8. Display Table\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "How many students? ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "\nEnter ID: ";
                cin >> std[i].id;

                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, std[i].name);

                cout << "Enter Age: ";
                cin >> std[i].age;

                float total = 0;
                cout << "Enter 5 marks: ";
                for (int j = 0; j < 5; j++) {
                    cin >> std[i].marks[j];
                    total += std[i].marks[j];
                }

            std[i].percentage =( total / 500.0)*100;
                  // FINDING GRADE
          if ( std[i].percentage>= 85)   
              std[i].grade =   'A';
          else if ( std[i].percentage  >= 70)
             std[i].grade = 'B';
          else if (  std[i].percentage >= 50)  
             std[i].grade =  'C';
          else   std[i].grade =  'F';
            }

            cout << "Data entry completed.\n";
        }

        else if (choice == 2) {
            saveToFile(std, n);
        }

        else if (choice == 3) {
             totalStd= loadFromFile(std);
            cout << "Data loaded successfully.\n";
        }

        else if (choice == 4) {
            int opt;
            cout << "\n1. Search by ID.\n";
            cout<<"2. Search by Name.\n";
            cout<<"3. Search by Grade\n";
            cout<<"Select Option: ";
            cin >> opt;

            if (opt == 1) {
                int id;
                cout << "Enter ID: ";
                cin >> id;
                 totalStd= loadFromFile(std);
                searchByID(std, totalStd, id);
            }
            else if (opt == 2) {
                string name;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                 totalStd= loadFromFile(std);
                searchByName(std, totalStd, name);
            }
            else if (opt == 3) {
                char g;
                cout << "Enter grade: ";
                cin >> g;
                totalStd= loadFromFile(std);
                searchByGrade(std, totalStd, g);
            }
        }

        else if (choice == 5) {
            int option;
            cout << "\n1. Sort by Name.\n";
            cout<<"2. Sort by Percentage.\n";
            cout<<"3. Sort by Age\n";
            cout<<"Select Option: ";
            cin >> option;
         

            if (option == 1) {
              totalStd= loadFromFile(std);
              sortByName(std, totalStd);
            }
            else if (option == 2){
              totalStd= loadFromFile(std);
              sortByPercentage(std, totalStd);
            }
            else if (option == 3){
               totalStd= loadFromFile(std);
               sortByAge(std, totalStd);
            }
        }

        else if (choice == 6) {
            totalStd= loadFromFile(std);
            updateStudent(std, totalStd);
            rewriteFile(std, totalStd);
        }

        else if (choice == 7) {
            totalStd= loadFromFile(std);
            totalStd= deleteStudent(std, totalStd);
            rewriteFile(std, totalStd);
        }

        else if (choice == 8) {
             totalStd= loadFromFile(std);
            display(std, totalStd);
        }

        else if (choice == 9) {
            cout << "Program Finished.\n";
            break;
        }
    }

    return 0;
    
}