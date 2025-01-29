#include <iostream>
#include <map>
#include <set>

using namespace std;
 
struct man {
    string name, cityName;
    long long money;
    man(string _name, string _cityName, long long _money) {
        name = _name;
        cityName = _cityName;
        money = _money;
    }
};
 
struct city {
    string name;
    long long money;
    int top;
    city(string _name) {
        name = _name;
        money = 0;
        top = 0;
    }
    city(string _name, long long _money) {
        name = _name;
        money = _money;
        top = 0;
    }
    
    void add(long long _money) {
        money += _money;
    }
};

struct economy {
    map <string, city*> cityByName = map <string, city*>();
    map <string, man*> manByName = map <string, man*>();
    map <long long, set<city*>> cityMapByMoney = map <long long, set<city*>>();
    
    void manMove(string manName, string cityName, bool in) {
        
        if (cityByName.count(cityName) == 0) {
            cityByName.insert(make_pair(cityName, new city(cityName)));
        }
        
        city* ct = cityByName[cityName];
        
        if (cityMapByMoney.count(ct->money) > 0) {
            cityMapByMoney[ct->money].erase(ct);
            if (cityMapByMoney[ct->money].empty()) {
                cityMapByMoney.erase(ct->money);
            }
        }
        
        ct->add((in?manByName[manName]->money:-manByName[manName]->money));
        
        if (ct->money != 0) {
            cityMapByMoney[ct->money].insert(ct);
        } 
    }
    
    void addMan(string manName, string cityName, long long money) {
        manByName.insert(make_pair(manName, new man(manName, cityName, money)));
        manMove(manName, cityName, true);
    }
    
    void manFlight(string manName, string cityName) {
        manMove(manName, manByName[manName]->cityName, false);
        manMove(manName, cityName, true);
        manByName[manName]->cityName = cityName;
    }
    
    bool oneTop() {
        return(int(cityMapByMoney.rbegin()->second.size()) == 1);
    }
    
    void updateTop(int value) {
        if (oneTop()) {
            city* ct = *(cityMapByMoney.rbegin()->second.begin());
            //cout << ct->name << "#: " << ct->top <<  "+=" << value << "\n";
            ct->top += value;
        }
    }
    
    void printTop() {
        for (pair<string, city*> i: cityByName) {
            if (i.second->top > 0) {
                cout << i.first << ' ' << i.second->top << '\n';
            }
        }
    }
    
    void print() {
        cout << "\n____________________\n";
        for (pair<string, city*> i: cityByName) {
            cout << i.first;
            for (int j = int(i.first.size()); j < 20; ++j) {
                cout << ' ';
            }
            cout << i.second->money << ' ' << i.second->top << '\n';
        }
        
        cout << "-------------------\n";
        for (pair<long long, set<city*>> i: cityMapByMoney) {
            cout << "(" << i.first << "; " << i.second.size() << ");\n";
        }
        cout << "___________________________\n";
    }
    
};
 
int main() {
    int n;
    cin >> n;
    
    string manName, cityName;
    long long money;
    economy e = economy();
    
    for (int i = 0; i < n; ++i) {
        cin >> manName >> cityName >> money;
        e.addMan(manName, cityName, money);
    }
    
    int days, lastDay = 0, flights, day = 0;
    cin >> days >> flights;
    
    for (int i = 0; i < flights;) {
        if (i == 0) {
            cin >> day >> manName >> cityName;
        }
        
        //e.print();
        e.updateTop(day-lastDay);
        
        lastDay = day;
        
        while (i < flights && day == lastDay) {
            e.manFlight(manName, cityName);
            cin >> day >> manName >> cityName;
            ++i;
        }
    }
    
    e.updateTop(days-day);
    
    e.printTop();
    
    return 0;
}
