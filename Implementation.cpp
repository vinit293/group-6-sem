#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string, string> studentData = {{"student1", "pass123"}, {"student2",
"pass456"}};
map<string, string> teacherData = {{"teacher1", "teach123"}};
map<string, string> adminData = {{"admin", "admin123"}};
vector<pair<string, string>> questions = {
{"What is the capital of France?", "Paris"},
{"What is 2 + 2?", "4"},
{"Who wrote 'Hamlet'?", "Shakespeare"},
{"What is the largest planet in our solar system?", "Jupiter"}};
map<string, int> results;
bool authenticate(string role, string username, string password)
{
if (role == "student" && studentData.find(username) != studentData.end()
&& studentData[username] == password)
return true;
if (role == "teacher" && teacherData.find(username) != teacherData.end()
&& teacherData[username] == password)
return true;
if (role == "admin" && adminData.find(username) != adminData.end() &&
adminData[username] == password)
return true;
return false;
}
void addQuestion()
{
string question, answer;
cout << "Enter the question: ";
cin.ignore();
getline(cin, question);
cout << "Enter the correct answer: ";
getline(cin, answer);
questions.push_back(make_pair(question, answer));
cout << "Question added successfully!\n";
}
void takeExam(string student)
{
if (questions.empty())
{
cout << "No questions available yet!\n";
return;
}
int score = 0;
string studentAnswer;
cout << "Starting the exam...\n";
for (int i = 0; i < questions.size(); ++i)
{
cout << "Q" << i + 1 << ": " << questions[i].first << endl;
cout << "Your answer: ";
getline(cin, studentAnswer);
if (studentAnswer == questions[i].second)
{
score++;
}
}
results[student] = score;
cout << "Exam completed! Your score is: " << score << "/" <<
questions.size() << endl;
}
void displayResults(string student)
{
if (results.find(student) != results.end())
{
cout << "Your score: " << results[student] << "/" << questions.size()
<< endl;
}
else
{
cout << "No results found. Please complete the exam.\n";
}
}
void adminMenu()
{
int choice;
do
{
cout << "\nAdmin Menu\n1. Add Question\n2. View All Students\n3.
Logout\nChoice: ";
cin >> choice;
cin.ignore();
switch (choice)
{
case 1:
addQuestion();
break;
case 2:
cout << "Students Registered:\n";
for (auto &s : studentData)
{
cout << " - " << s.first << endl;
}
break;
case 3:
cout << "Logging out...\n";
return;
}
} while (choice != 3);
}
void teacherMenu()
{
int choice;
do
{
cout << "\nTeacher Menu\n1. Add Question\n2. Logout\nChoice: ";
cin >> choice;
cin.ignore();
switch (choice)
{
case 1:
addQuestion();
break;
case 2:
cout << "Logging out...\n";
return;
}
} while (choice != 2);
}
void studentMenu(string student)
{
int choice;
do
{
cout << "\nStudent Menu\n1. Take Exam\n2. View Results\n3.
Logout\nChoice: ";
cin >> choice;
cin.ignore();
switch (choice)
{
case 1:
takeExam(student);
break;
case 2:
displayResults(student);
break;
case 3:
cout << "Logging out...\n";
return;
}
} while (choice != 3);
}
int main()
{
string role, username, password;
cout << "Welcome to the Online Examination System\n";
cout << "Select your role (student/teacher/admin): ";
cin >> role;
cout << "Enter username: ";
cin >> username;
cout << "Enter password: ";
cin >> password;
if (!authenticate(role, username, password))
{
cout << "Invalid login credentials!\n";
return 0;
}
cout << "Login successful!\n";
if (role == "admin")
{
adminMenu();
}
else if (role == "teacher")
{
teacherMenu();
}
else if (role == "student")
{
studentMenu(username);
}
return 0;
}
