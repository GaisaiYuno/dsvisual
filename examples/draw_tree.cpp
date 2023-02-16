#include "graphviz.h"
#include <bits/stdc++.h>
using namespace std;
int main(){
    GraphViz G(7);
    G.add_edge(1,2,"edge");
    G.add_edge(2,4);
    G.add_edge(2,5);
    G.add_edge(1,3);
    G.add_edge(3,6);
    G.add_edge(3,7);
    G.set_label(1,"1(1)");
    cout<<G.to_string();
}