#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class mystring {
private:
    string m_str;
public:
    mystring(string s) {
        m_str = s;
    }
};

class ReadClass {
public:
    void showclass() {
        ifstream file("main.cpp");
        if (!file.is_open()) {
            cout << "Failed to open file main.cpp" << endl;
            return;
        }

        string line;
        int classCount = 0;
        vector<string> classNames;

        while (getline(file, line)) {
            size_t pos = line.find("class ");
            if (pos != string::npos) {
                size_t start = pos + 6;
                size_t end = line.find_first_of(" {", start);
                if (end != string::npos) {
                    string className = line.substr(start, end - start);
                    classNames.push_back(className);
                    classCount++;
                }
            }
        }
        file.close();

        cout << classCount << " class" << (classCount > 1 ? "es" : "") << " in main.cpp" << endl;
        for (const string& className : classNames) {
            cout << "class " << className << endl;
        }
    }
};

int main() {
    ReadClass rfile;
    rfile.showclass();

    return 0;
}
