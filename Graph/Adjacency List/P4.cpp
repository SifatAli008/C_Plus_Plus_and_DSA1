//
// Created by Sifat Ali on 11/23/2023.
//
#include <iostream>
#include <list>

using namespace std;

class Edge{
public:

    int src;
    int dis;

    Edge(int src,int dis){
        this->src=src;
        this->dis=dis;
    }
};


void Display(list<Edge> Graph[],int v){
    for (int i = 0; i < v; i++) {
        cout<<"Vertix "<< i<<":";
        for ( Edge e:Graph[i]) {
            cout << "(" << e.src << "->" << e.dis << ")" ;
        }
        cout << endl;
    }
}



int main(){
    int v=4;
    list<Edge> Graph[v];

    Graph[0].push_back(Edge(0,2));

    Graph[1].push_back(Edge(1,2));
    Graph[1].push_back(Edge(1,3));

    Graph[2].push_back(Edge(2,0));
    Graph[2].push_back(Edge(2,1));
    Graph[2].push_back(Edge(2,3));

    Graph[3].push_back(Edge(1,0));
    Graph[3].push_back(Edge(1,3));

    Display(Graph,v);
}