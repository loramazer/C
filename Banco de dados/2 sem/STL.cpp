#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int main(){
    cout << "Pilhas, filas e filas de prioridade" << endl;
    stack <int> stack;
    queue <int> queue;
    priority_queue <int> pq;

    stack.push(10);
    stack.push(100);
    stack.push(50);
    stack.push(20);

    queue.push(10);
    queue.push(100);
    queue.push(50);
    queue.push(20);

    pq.push(10);
    pq.push(100);
    pq.push(50);
    pq.push(20);

    stack.top();
    pq.top();

    queue.front();

    stack.size();
    queue.size();
    pq.size();

    stack.pop();
    pq.pop();
    queue.pop();
    stack.pop();
    pq.pop();
    queue.pop();

    stack.top();
    pq.top();

    queue.front();

    stack.size();
    queue.size();
    pq.size();

    stack.pop();
    pq.pop();
    queue.pop();
    stack.pop();
    pq.pop();
    queue.pop();

    if(stack.empty()){
        cout << "Pilha vazia" << endl;
    } else cout<<"Pilha n esta vazia" << endl;
    if(queue.empty()){
        cout << "Fila vazia" << endl;
    } else cout << "Fila n esta vazia" << endl;
    if(pq.empty()){
        cout << "Prioridade vazia" << endl;
    } else cout<<"Prioridade n esta vazia"<< endl;

    cout << "Listas lineares usando vector" << endl;
    vector<int> lista;
    vector <int> :: iterator it;
    lista.push_back(10);
    lista.push_back(100);
    lista.push_back(50);
    lista.push_back(20);

    for (it = lista.begin(); it != lista.end(); it++)
        cout << *it << endl;

    sort(lista.begin(), lista.end());

    for (it = lista.begin(); it != lista.end(); it++)
        cout << *it << endl;

    cout<<"Árvores de busca binária balanceadas usando set (conjuntos)"<<endl;
    std::set<int> ABB;
    ABB.insert(10);
    ABB.insert(100);
    ABB.insert(50);
    ABB.insert(20);

    for (auto& str : ABB) {
        std::cout << str << ' ';
    }
}