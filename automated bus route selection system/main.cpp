#include "datamanager.h"
int main()
{
    datamanager dm;
    if (!dm.loadfromfile("data.txt")) {
        cout << "加载失败！检查文件格式\n";
        return 1;
    }
    cout << "共加载" << dm.alllines.size() << "条线路\n";
    cout << "共收集" << dm.allstations.size() << "个站点\n";
    cout << "邻接图节点数" << dm.adjgraph.size() << "\n\n";
    for (auto& p : dm.alllines) {
        cout << "线路" << p.first
            << "|首班" << p.second.firstbus
            << "末班" << p.second.lastbus
            << "|站点" << p.second.stations.size()
            << "|时长" << p.second.intervaltime.size() << "\n";
        for (auto& s : p.second.stations)
            cout << "   " << s.name << "\n";
    }
    return 0;
}