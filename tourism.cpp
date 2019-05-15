//
// Created by 黄文禹 on 2019-05-05.
// encoding "utf-8"
//

#include "stdafx.h"
#include "tourism.h"


void createGraph(struct Graph &m_graph){
    char vexFile[200];
    char edgeFile[200];
    cout<<"input filename of vex:";
    cin>>vexFile;
    cout<<"input filename of edge:";
    cin>>edgeFile;
    FILE * file_vex = fopen(vexFile,"r");
    FILE * file_edge = fopen(edgeFile,"r");
    if(file_vex == NULL){
        cout<<"file of vex doesn't exist"<<endl;
        return;
    }
    if(file_edge == NULL){
        cout<<"file of edge doesn't exist"<<endl;
        return;
    }
    init(m_graph);
    Vex sVex;
    int num;
    fscanf(file_vex,"%d",&num);
    for(int i = 0; i<num; i++){
        fscanf(file_vex,"%d %s %s",&sVex.id,sVex.name,sVex.desc);
        insertVex(sVex,m_graph);
    }

    Edge sEdge;
    int n = 0;
    while(!feof(file_edge)){
        fscanf(file_edge,"%d %d %d",&sEdge.vex1,&sEdge.vex2,&sEdge.length);
        n = insertEdge(sEdge,m_graph,n);
    }
    if(getVexnum(m_graph) && n){
        cout<<"Number of vertices:"<<num<<endl;
        cout<<"----Vex----"<<endl;
        for(int i = 0; i<num; i++){
            cout<<m_graph.m_aVexs[i].id<<"-"<<m_graph.m_aVexs[i].name<<endl;
        }
        cout<<"----Edge----"<<endl;
        for(int i = 0; i<num; i++){
            for(int j = i; j<num; j++){
                if(m_graph.m_aAdjMatrix[i][j]){
                    cout<<"<v"<<i<<",v"<<j<<"> "<<m_graph.m_aAdjMatrix[i][j]<<"m"<<endl;
                }
            }
        }
    }else{
        cout<<"failure"<<endl;
    }
}

void getSpotInfo(struct Graph m_graph){
    cout<<"----Query information----"<<endl;
    int num = getVexnum(m_graph);
    for(int i = 0; i<num; i++){
        cout<<m_graph.m_aVexs[i].id<<"-"<<m_graph.m_aVexs[i].name<<endl;
    }
    int order;
    cout<<"input order:";
    cin>>order;
    Vex sVex = getVex(order,m_graph);
    cout<<sVex.name<<endl<<sVex.desc<<endl;
    cout<<"----Surrounding scenic spot----"<<endl;
    Edge aEdge[100];
    int l = findEdge(order,aEdge,m_graph);
    for(int i = 0; i<l; i++){
        int index = 0;
        for(int j = 0; j<num; j++){
            if(m_graph.m_aVexs[j].id == aEdge[i].vex2){
                index = j;
                break;
            }
        }
        cout<<sVex.name<<"->"<<m_graph.m_aVexs[index].name<<" "<<aEdge[i].length<<"m"<<endl;
    }
}

void travelPath(struct Graph m_graph) {
    cout<<"----tourist attraction navigation----"<<endl;
    int num = getVexnum(m_graph);
    for(int i = 0; i<num; i++){
        cout<<m_graph.m_aVexs[i].id<<"-"<<m_graph.m_aVexs[i].name<<endl;
    }
    cout<<"enter a starting point number:";
    int n;
    cin>>n;
    cout<<"navigation route:"<<endl;
    PathList pList = NULL;
    dfsTraverse(n,pList,m_graph);
    PathList p1 = pList->next;
    int count = 1;
    while(p1 != NULL){
        cout<<"route "<<count++<<":";
        for(int i = 0; i<num; i++){
            if(i != num-1){
                cout<<m_graph.m_aVexs[p1->vexs[i]].name<<"->";
            }
            else{
                cout<<m_graph.m_aVexs[p1->vexs[i]].name<<endl;
            }
        }
        p1 = p1->next;
    }
}

void findShortPath(struct Graph m_graph) {
    cout<<"----search shortest path----"<<endl;
    int num = getVexnum(m_graph);
    for(int i = 0; i<num; i++){
        cout<<m_graph.m_aVexs[i].id<<"-"<<m_graph.m_aVexs[i].name<<endl;
    }
    int start,end;
    cout<<"enter the starting point number:";
    cin>>start;
    cout<<"enter the ending point number:";
    cin>>end;
    Edge path[100]={};
    int len = searchShortPath(start,end,path,m_graph);
    cout<<"the shortest path:";
    int sum = 0;
    cout<<m_graph.m_aVexs[path[len].vex1].name;
    for(int i = len; i>=0; i--){
        cout<<"->"<<m_graph.m_aVexs[path[i].vex2].name;
        sum += path[i].length;
    }
    cout<<endl;
    cout<<"the shortest distance:"<<sum<<endl;
}

void designPath(struct Graph m_graph) {

}


