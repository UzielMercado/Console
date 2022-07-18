#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

string saving;
bool first_timer;

void line()
{
    ofstream line_file;
    string separator(120, '='); 
    line_file.open("tester.txt", std::ios_base::app);
    line_file << '\n' << separator << '\n';
    line_file.close();

}

void line(string file)
{
    ofstream line_file;
    string separator(120, '='); 
    line_file.open(file, std::ios_base::app);
    line_file << '\n' << separator << '\n';
    line_file.close();

}

void line(char sep)
{
    ofstream line_file;
    string separator(120, sep); 
    line_file.open("tester.txt", std::ios_base::app);
    line_file << '\n' << separator << '\n';
    line_file.close();

}

void line(string file, char sep)
{
    ofstream line_file;
    string separator(120, sep); 
    line_file.open(file, std::ios_base::app);
    line_file << '\n' << separator << '\n';
    line_file.close();

}

void jump()
{
    ofstream jump_file; 
    jump_file.open("tester.txt", std::ios_base::app);
    jump_file << '\n' << '\n';
    jump_file.close();

}

void jump(string file)
{
    ofstream jump_file; 
    jump_file.open(file, std::ios_base::app);
    jump_file << '\n' << '\n';
    jump_file.close();

}

void writer(bool first_timer)
{
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%H-%M-%S-%MS %d-%b-%Y");
    auto str = oss.str();
    
    if (first_timer == true)
    {
        ofstream time_file; 
        time_file.open("tester.txt", std::ios_base::app);
        time_file << str << " ";
        time_file.close(); 
    }

    ofstream write_file; 
    write_file.open("tester.txt", std::ios_base::app);
    write_file << saving;
    write_file.close();
}

void writer(string file, bool first_timer)
{
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%H-%M-%S-%MS %d-%b-%Y");
    auto str = oss.str();
    
    if (first_timer == true)
    {
        ofstream time_file; 
        time_file.open("tester.txt", std::ios_base::app);
        time_file << str << " ";
        time_file.close(); 
    }

    ofstream write_file; 
    write_file.open(file, std::ios_base::app);
    write_file << saving;
    write_file.close();
}

void writer(string text2, string file1, bool first_timer)
{
    auto t = time(nullptr);
    auto tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%H-%M-%S-%MS %d-%b-%Y");
    auto str = oss.str();
    
    if (first_timer == true)
    {
        ofstream time_file; 
        time_file.open("tester.txt", std::ios_base::app);
        time_file << str << " ";
        time_file.close(); 
    }

    ofstream write_file; 
    write_file.open(file1, std::ios_base::app);
    write_file << text2;
    write_file.close();
}

int main(void)
{
    char new_sep;
    bool want_time;

    cout << "Write test: ";
    cin >> saving;
    writer(0);

    cout << "Jump test\n";
    jump();

    cout << "Write test 2: ";
    cin >> saving;
    writer(1);

    cout << "Line test\n";
    line();

    cout << "Write test 3: ";
    cin >> saving;
    writer(1);

    cout << "Line test 2\n";
    cout << "new separator: ";
    cin >> new_sep;
    line(new_sep);

    return 0;
}