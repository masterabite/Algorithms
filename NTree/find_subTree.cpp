#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct node {
    int value;
    vector<int> childs;
    
    node(int _value) {
        value = _value;
        childs = vector<int>();
    }
    
};

struct ntree {
    vector<node*> nodes;  //узлы дерева
    
    //функция считывания дерево c клавиатуры
    void scan() {
        
        int n, m, child;
        cout << "Введите кол-во вершин: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            nodes.push_back(new node(i+1));
        }

        for (int i = 0; i < n; ++i) {
            printf("Введите кол-во дочерних вершин и сами вершины для %d'й вершины: ", i+1);
            cin >> m;
            for (int j = 0; j < m; ++j) {
                cin >> child;
                nodes[i]->childs.push_back(child-1);
            }
        }
    }
    
    //функция считывания дерево из файла "fname"
    void scan_from_file(string fname) {
        ifstream fin(fname);
        if (!fin.is_open()) {
            printf("Не удалось открыть файл \"%s\"\n", fname.c_str());
            return;
        }
        
        int n, m, child;
        fin >> n;
        for (int i = 0; i < n; ++i) {
            nodes.push_back(new node(i+1));
        }

        for (int i = 0; i < n; ++i) {
            fin >> m;
            for (int j = 0; j < m; ++j) {
                fin >> child;
                nodes[i]->childs.push_back(child-1);
            }
        }
    }
    
    //функция вывода всего дерева
    void print() {
        
        
        int n = int(nodes.size());
        if (n == 0) {       //если дерево пустое
            return;
        }
        
        
        //сначала нужно определить корень
        int* par = new int[n];
        for (int i = 0; i < n; ++i) {
            par[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            for (size_t j = 0; j < nodes[i]->childs.size(); ++j) {
                par[nodes[i]->childs[j]] = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (par[i] == -1) {
                print(i, 0);
                printf("\n");
                return;
            }
        }
        
        delete[] par; //очищаем память
    }
    
    //рекурсивная функция выводит поддерево с корнем вершиной с индексом ind
    void print(int ind, int cur_depth) {
        
        int sz = int(nodes[ind]->childs.size());
        
        
        for (int i = 0; i <= cur_depth; ++i) {
            cout << "|\t";
        }
        cout << '\n';
        
        //вывод правого поддерева
        for (int i = sz-1; i >= sz/2 + (sz%2); --i) {
            print(nodes[ind]->childs[i], cur_depth+1);
        }
        
        //вывод самого узла
        for (int i = 0; i < cur_depth; ++i) {
            cout << "|\t";
        }printf("|-------|%d\n", ind+1);

        //вывод левого поддерева
       for (int i = sz/2 + (sz%2)-1; i >= 0; --i) {
            print(nodes[ind]->childs[i], cur_depth+1);
        }

        for (int i = 0; i <= cur_depth; ++i) {
            cout << "|\t";
        }
        cout << '\n';
    }

    //функция проверяет все поддеревья дерева
    void check_all() {
        
        for (int i = 0; i < int(nodes.size()); ++i) {
            if (is_ok(i, 0)) {
                printf("\nПоддерево:\n");
                print(i, 0);
                printf("\n");
            }
            
        }
        
    }
    
    //рекурсивная функция проверяет условие задания
    //для поддерева с корнем в вершине с индексом ind, считая что расстояние от корня = depth 
    bool is_ok(int ind, int depth) {
        
        //проверяем, соответствуют ли все дочерние элементы условию задания
        for (int i = 0; i < int(nodes[ind]->childs.size()); ++i) {
            
            //если хотя бы одна вершина не соответствует, то все поддерево не
            if (!is_ok(nodes[ind]->childs[i], depth+1)) {
                return false;
            }
        }
        return (ind+1)%2 != depth%2;
    }   
    
    
    //функция очищения памяти дерева
    void clear() {
        for (int i = int(nodes.size())-1; i >= 0; --i) {
            delete nodes[i];
            nodes.pop_back();
        }
    }
    
};


int main()
{
    ntree t;
    
    //ввод дерева с клавиатуры или из файла "ntree.txt"
    int cmd;
    printf("0- ввод из файла\n");
    printf("1- ввод с клавиатуры\n");
    printf("введите команду: "); cin >> cmd;
    
    if (cmd == 0) {
        t.scan_from_file("ntree.txt");
    } else {
        t.scan();
    }

    //выводим полное дерево
    cout << "\nИсходное дерево:\n";
    t.print();
    
    //ищем поддеревья
    printf("Поддеревья, удовлетворяющие условие задания:\n");
    t.check_all();
    
    //очищаем память
    t.clear();
    return 0;
}
