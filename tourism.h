//
// Created by 黄文禹 on 2019-05-05.
// encoding "utf-8"
//

#ifndef GRAPHCPRO_TOURISM_H
#define GRAPHCPRO_TOURISM_H
void createGraph(struct Graph &m_graph);//读取文件
void getSpotInfo(struct Graph m_graph);//查询指定顶点信息
void travelPath(struct Graph m_graph);//旅游景点导航功能，并且显示
#endif //GRAPHCPRO_TOURISM_H
