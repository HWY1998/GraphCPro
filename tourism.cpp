//
// Created by 黄文禹 on 2019-05-05.
// encoding "utf-8"
//

#include "stdafx.h"

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