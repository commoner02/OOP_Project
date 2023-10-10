// Title : Project File Submission System
// Roll : 2107116

#include <bits/stdc++.h>

using namespace std;

class Base // Class,Abstract Class
{
protected:
    int mark;

public:
    Base()
    {
        mark = 0;
    }
    virtual void showDetails() = 0;
};

class Student : public Base // Inheritance
{
    int roll; // Encapsulation
    string fileName;

public:
    Student(int r, string name) // Constructor
    {
        roll = r;
        fileName = name;
    }
    int getRoll()
    {
        return roll;
    }
    string getFile()
    {
        return fileName;
    }
    int getMark()
    {
        return mark;
    }
    void showDetails() // Polymorphism
    {
        cout << "Student Class " << endl;
    }
    friend void setMark(Student &, int);
    friend ostream &operator<<(ostream &, Student &);
};

ostream &operator<<(ostream &out, Student &Ob)
{ // Operator Overloading the '<<' operator
    out << left << setfill(' ') << setw(18) << Ob.roll << " " << left << setfill(' ') << setw(40) << Ob.fileName << " " << Ob.mark << endl;
    return out;
}

void setMark(Student &obj, int m)
{ // Friend Function to set Mark
    obj.mark = m;
}

int handleError() // Error Handleling using try throw catch ,Checks the input is integer or not
{
    int x;
    while (true)
    {
        try
        {
            cin >> x;
            if (cin.fail())
            {
                throw runtime_error("Invalid input. Please enter an integer : ");
            }
            break;
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return x;
}

void addFile(vector<Student> &VEC) // Fuction to add file to the vector
{
    int roll;
    string file;
    cout << "Enter Roll : ";
    roll = handleError();
    cout << "Enter Project Name : ";
    cin.ignore();
    getline(cin, file);
    if (file.empty())
    {
        cout << "Empty String! Enter Again :" << endl;
        getline(cin, file);
    }
    bool found = false;
    if (!VEC.empty()) // Checks if same roll entered again
    {
        for (int i = 0; i < VEC.size(); i++)
        {
            if (roll == VEC[i].getRoll())
            {
                VEC.erase(VEC.begin() + i);
                VEC.push_back(Student(roll, file));
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        VEC.push_back(Student(roll, file));
    }
}

void Mark(vector<Student> &Vec) // Fuction to do marking
{
    cout << "Enter Password : ";
    int pass;
    cin >> pass;
    if (pass == 0) // Password protection to log in only the authorized person
    {
        cout << "Password Matched " << endl;
        cout << "Total Mark : 10 " << endl;
        if (Vec.size() == 0) // Checks any files submitted or not
        {
            cout << "No Submission Yet." << endl;
        }
        else
        {
            cout << " Roll                  Project Name                        Mark " << endl;
            for (auto &f : Vec) // Takes files from vector and sets marks corresponding to the filename
            {
                if (f.getMark() == 0)
                {
                    cout << left << setfill(' ') << setw(18) << f.getRoll() << " " << left << setfill(' ') << setw(40) << f.getFile() << " ";
                    int m;
                    m = handleError();
                    setMark(f, m);
                }
                else
                {
                    cout << f;
                }
            }
        }
    }
    else
    {
        cout << "Wrong Password ! Access Denied ! " << endl;
    }
}

void DashBoard(vector<Student> &Vec) // See the stats of the submission
{
    cout << "Total Submission till now is : " << Vec.size() << endl;
    cout << "Enter Total Student No. : ";
    int total;
    while (true)
    {
        cin >> total;
        if (total < Vec.size())
        {
            cout << "Please Enter Correct Number : ";
        }
        else
        {
            break;
        }
    }
    cout << "\nSUBMISSION STATS : " << endl;
    cout << "Total Submitted : " << Vec.size() << " of " << total << " Students" << endl;
    cout << "Absent : " << total - Vec.size() << " Students " << endl;
    int tMark = 0;
    for (auto &m : Vec)
    {
        tMark += m.getMark();
    }
    if (tMark <= 0 || Vec.size() <= 0)
    {
        cout << "Average Mark : Not Marked Yet " << endl; // for total mark 10
    }
    else
    {
        float avgMark = ((1.0 * tMark) / Vec.size()) * 10;
        cout << "Average Mark : " << fixed << setprecision(2) << avgMark << " % " << endl;
    }
}

void Publish(vector<Student> &Vec) // Print the result in console
{
    if (Vec.size() == 0)
    {
        cout << "Not Marked Yet." << endl;
    }
    else
    {
        cout << " Roll                  Project Name                        Mark " << endl;
        for (auto &f : Vec)
        {
            cout << f;
        }
    }
}

void saveFile(vector<Student> &V) // File Management , Saves the file to PC as a txt file
{
    fstream myFile;
    myFile.open("SubmittedFiles.txt", ios::out);
    if (V.size() == 0)
    {
        myFile << "No Submission Yet." << endl;
    }
    else
    {
        myFile << " Roll                  Project Name                        Mark " << endl;
        for (auto &f : V)
        {
            myFile << left << setfill(' ') << setw(18) << f.getRoll() << " " << left << setfill(' ') << setw(40) << f.getFile() << " " << f.getMark() << endl;
        }
    }
}

void showOptions() // Console avaiable options
{
    cout << "\n--------------------------" << endl;
    cout << "Avaiable Options" << endl;
    cout << "1.Add Project" << endl;
    cout << "2.Do Marking" << endl;
    cout << "3.See DashBoard" << endl;
    cout << "4.Publish Mark" << endl;
    cout << "5.Save as File" << endl;
    cout << "6.Exit" << endl;
    cout << "---------------------------\n"
         << endl;
}

void option(vector<Student> &V) // Choose options menu
{
    while (true)
    {
        showOptions();
        cout << "Choose Option : ";
        int c = handleError();

        switch (c)
        {
        case 1:
            addFile(V);
            break;
        case 2:
            Mark(V);
            break;
        case 3:
            DashBoard(V);
            break;
        case 4:
            Publish(V);
            break;
        case 5:
            saveFile(V);
            break;
        case 6:
            cout << "Program Exit" << endl;
            return;
        default:
            cout << "Invalid Choice" << endl;
        }
    }
}

int main()
{
    cout << "\n-------------------------------" << endl;
    cout << "  PROJECT SUBMISSION MANAGER" << endl;
    cout << "-------------------------------\n"
         << endl;

    vector<Student> Vector; // Objects of Students type holded here in the vector , Use of STL
    option(Vector);

    return 0;
}
