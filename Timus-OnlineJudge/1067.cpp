#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct catalog {
    string name;
    vector<catalog*> content;
    
    catalog(string name) {
        this->name = name;
        this->content = vector<catalog*>();
    }
};

string getNextString(string& s, int& pos) {
    string answer = "";
    while (s[pos] != '\\' && pos < int(s.size())) {
        answer += s[pos];
        ++pos;
    }
    return answer;
}

void add(catalog* c, string d) {
    for (int i = 0; i < int(d.size()); ++i) {
        string cname = getNextString(d, i);
        bool thereIs = false;
        for (catalog* cur: c->content) {
            if (cur->name == cname) {
                thereIs = true;
                c = cur;
                break;
            }
        }
        if (!thereIs) {
            catalog* newCatalog = new catalog(cname);
            c->content.push_back(newCatalog);
            c = newCatalog;
        }
    }
}

bool cmp(catalog* c1, catalog* c2) {
    for (int i = 0; i < int(c1->name.size()); ++i) {
        if (i >= int(c2->name.size())) {
            return true;
        }
        
        if (c1->name[i] < c2->name[i]) {
            return false;
        } else if (c1->name[i] > c2->name[i]) {
            return true;
        } 
    }
    return false;
}

void print(catalog* c, int depth) {
    
    for (int i = 0; i < int(c->content.size())-1; ++i) {
        for (int j = i+1; j < int(c->content.size()); ++j) {
            if (cmp(c->content[i], c->content[j])) {
                swap(c->content[i], c->content[j]);
            }
        }
    }
    
    
    for (int i = 0; i < depth; ++i) {
        cout << " ";
    }
    
    if (c->name != "") {
        cout << c->name << '\n';
    }
    
    for (catalog* cur: c->content) {
        print(cur, depth+1);
    }
}

int main()
{
    catalog* C = new catalog("");
    
    int n;
    string tempPath;
    cin >> n; 
    for (int i = 0; i < n; ++i) {
        cin >> tempPath;
        add(C, tempPath);
    }
    
    print(C, -1);
    
    return 0;
}
