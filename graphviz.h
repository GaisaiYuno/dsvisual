#include <cstring>
#include <tuple>
#include <vector>
class GraphViz{
    std::vector<std::string> labels;
    std::vector<std::tuple<int,int,std::string> >edges;
    public:
    GraphViz(int n){
        labels.resize(n+1);
    }
    void set_label(int x,std::string label){
        labels[x]=label;
    }
    std::string get_label(int x){
        return "\""+(labels[x]==""?std::to_string(x):labels[x])+"\"";
    }
    void add_edge(int from,int to,std::string label=""){
        edges.push_back(std::make_tuple(from,to,label));
    }
    std::string to_string(){
        std::string begin="digraph G {\n";
        std::string body="";
        for (int i=0;i<edges.size();++i){
            body+=get_label(std::get<0>(edges[i]));
            body+=" -> ";
            body+=get_label(std::get<1>(edges[i]));
            if (std::get<2>(edges[i])!="") body+=" [label=\""+std::get<2>(edges[i])+"\"]";
            body+="\n";
        }
        std::string end="}";
        return begin+body+end;
    }
};