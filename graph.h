//
// Created by 黄文禹 on 2019-05-05.
// encoding "utf-8"
//

#ifndef GRAPHCPRO_GRAPH_H
#define GRAPHCPRO_GRAPH_H

struct Vex{
    int id;//顶点编号
    char name[20];//顶点名字
    char desc[200];//景区介绍
};

struct Graph{
    int m_aAdjMatrix[20][20];//邻接矩阵
    Vex m_aVexs[20];//顶点数组
    int m_nVexNum;//顶点个数
};

struct Edge{
    int vex1,vex2;//顶点1和顶点2编号
    int length; //道路长度
};

void init(struct Graph &m_graph);//初始化图结构
int insertVex(Vex sVex, struct Graph &m_graph);//将顶点添加到顶点数组
int insertEdge(Edge sEdge,struct Graph &m_graph, int n);//将边保存到邻接矩阵
Vex getVex(int nVex,Graph m_graph);//查询指定顶点信息
int findEdge(int nVex, Edge aEdge[], Graph m_graph);//查询与指定顶点相连的边
int getVexnum(struct Graph m_graph);//获取当前顶点数



#endif //GRAPHCPRO_GRAPH_H
