//
// Created by 黄文禹 on 2019-05-05.
// encoding "utf-8"
//

#include "stdafx.h"
#include "graph.h"

int path[100];
void init(struct Graph &m_graph){
    memset(m_graph.m_aAdjMatrix,0,sizeof(m_graph.m_aAdjMatrix));
    memset(m_graph.m_aVexs,0,sizeof(m_graph.m_aVexs));
}

int insertVex(Vex sVex, struct Graph &m_graph){
    m_graph.m_aVexs[m_graph.m_nVexNum] = sVex;
    m_graph.m_nVexNum++;
    return m_graph.m_nVexNum;
}

int insertEdge(Edge sEdge, struct Graph &m_graph, int n){
    m_graph.m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = m_graph.m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.length;
    n++;
    return n;
}

Vex getVex(int nVex, struct Graph m_graph){
    for(int i = 0; i <m_graph.m_nVexNum; i++){
        if(nVex == m_graph.m_aVexs[i].id)
            return m_graph.m_aVexs[i];
    }
}

int findEdge(int nVex, Edge aEdge[], Graph m_graph){
    int n = 0;
    for(int i = 0; i< m_graph.m_nVexNum; i++){
       if(m_graph.m_aAdjMatrix[nVex][i]){
           Edge temp_E;
           temp_E.length = m_graph.m_aAdjMatrix[nVex][i];
           temp_E.vex1 = nVex;
           temp_E.vex2 = i;
           aEdge[n++] = temp_E;
       }
    }
    return n;
}

int getVexnum(struct Graph m_graph){
    return m_graph.m_nVexNum;
}

void dfsTraverse(int nVex, PathList &pList, Graph m_graph) {
    bool visited[20];
    memset(visited,0,sizeof(visited));
    int nIndex = 0;
    PathList head = pList = (PathList)malloc(sizeof(Path));
    dfs(nVex,visited,nIndex,pList,m_graph);
    pList = head;
}

void dfs(int nVex, bool *visited, int &nIndex, PathList &pList, Graph m_graph) {
    visited[nVex] = true;
    path[nIndex++] = nVex;
    if(nIndex == getVexnum(m_graph)){
        PathList p1 = (PathList)malloc(sizeof(Path));
        for(int i = 0; i < nIndex; i++){
            p1->vexs[i] = path[i];
        }
        p1->next = NULL;
        if(pList == NULL){
            pList = p1;
        }else{
            pList->next = p1;
            pList = p1;
        }

    }else{

        for(int i = 0; i<getVexnum(m_graph); i++){
            if(!visited[i] && m_graph.m_aAdjMatrix[nVex][i]){
                dfs(i,visited,nIndex,pList,m_graph);
            }
        }
    }
    nIndex--;
    visited[nVex] = false;
    return;
}


