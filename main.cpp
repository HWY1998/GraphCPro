//
// Created by 黄文禹 on 2019-05-05.
// encoding "utf-8"
//

#include "stdafx.h"
struct Graph m_graph;
int main() {
    while(true) {
        showMenu();
        int order;
        cin >> order;
        switch (order) {
            case 1:
                createGraph(m_graph);
                break;
            case 2:
                getSpotInfo(m_graph);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                return 0;
                break;
            default:
                cout << "order wrong" << endl;
        }
    }
}