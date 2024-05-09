#include <iostream>
using namespace std;

class Fueltank {
private:
    int m_FueltankCapacity;
    int m_Gas_grade;
public:
    Fueltank(int FueltankCapacity = 3000, int Gas = 98): m_FueltankCapacity(FueltankCapacity), m_Gas_grade(Gas) {}
    
    void fuel_up(int v, int gas) {
        if (v > m_FueltankCapacity) {
            cout << "Error: FueltankCapacity: 3000 but fuel up " << v << endl<<"fuel_up:"<<v<<" ";
        } else {
            cout << "fuel_up: " << v << endl; 
        }
        
        if (gas != 95) {
            cout <<"Error Gas_grade:"<<gas<<" "<< "Correct Gas_grade: 95" << endl;
        } else {
            cout << "Gas_grade = " << gas << endl;
        }
    }
    
    void set_Gas_grade(int Gas_grade) { 
        m_Gas_grade = Gas_grade;
        cout << "set_Gas_grade=" << Gas_grade << endl; 
    }
    
    int get_Gas_grade() {
        return m_Gas_grade;
    }
};

int main() {
    cout << "Constructing AUDI_Car" << endl;
    cout << "Audi: Gas_grade = 98" << endl;
    
    Fueltank audi;
    audi.set_Gas_grade(95);
    cout << "Audi: Gas_grade = " << audi.get_Gas_grade() << endl;
    audi.fuel_up(30000, 95);
    
    return 0;
}
