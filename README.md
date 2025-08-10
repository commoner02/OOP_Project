# **📂 Project Submission System**  

A **C++** program for managing student project submissions and grading, built using **Object-Oriented Programming (OOP)** concepts.  

## **🚀 Features**  
- Add student submissions (roll number + project name)  
- Password-protected marking system (default password: `0`)  
- View submission statistics (dashboard)  
- Publish and display results  
- Save data to `SubmittedFiles.txt`  

## **🛠 OOP Concepts Used**  
✔ **Inheritance** (`Student` → `Base`)  
✔ **Polymorphism** (virtual `showDetails()`)  
✔ **Encapsulation** (private data members)  
✔ **Friend Function** (`setMark()`)  
✔ **Operator Overloading** (`<<` for `Student` objects)  
✔ **Abstract Class** (`Base` with pure virtual function)  

## **📥 Installation & Usage**  
1. **Compile:**  
   ```bash
   g++ 2107116_ProjectSubmissionSystem.cpp -o ProjectSubmissionSystem
   ```
2. **Run:**  
   ```bash
   ./ProjectSubmissionSystem
   ```
3. **Menu Options:**  
   - `1`: Add project  
   - `2`: Grade submissions (password: `0`)  
   - `3`: View dashboard (stats)  
   - `4`: Publish marks  
   - `5`: Save to file  
   - `6`: Exit  

## **📜 Output File**  
Results are saved in `SubmittedFiles.txt` with the format:  
```
Roll    Project Name                  Mark
2107116 MyAwesomeProject             8
```

## **📝 Notes**  
- Input validation ensures only integers are accepted for marks/roll.  
- Re-submissions by the same roll number overwrite previous entries.  
