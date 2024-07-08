

# 校园导航问题：

程序结构：分为主程序（main）、存储模块（StorageModules）、操作模块（OperationalModules）、导航模块（NavigationModule）、图形界面（Menu）。程序计算各个建筑物与道路的距离，如果从一个建筑物出发到另外一个建筑物，求最短路径距离和不同路径的总距离。本课题的目的是掌握有向图原理，采用邻接矩阵作为有向图的存储结构，利用迪杰斯特拉算法求解该实际问题。

文件路径:

├── Campus-Navigation

│   ├── .git

│   ├── cmake-build-debug

│   ├── EasyX

│   ├── README.md

│   ├── CMakeLists.txt

│   ├──Menu.h

│   ├──main.cpp

│   ├── Module

│    │   ├──CMakeLists.txt

│    │   ├──NavigationModule.cpp

│    │   ├──NavigationModule.h

│    │   ├──OperationalModule.cpp

│    │   ├──OperationalModule.h

│    │   ├──StorageModule.cpp

│    │   ├──StorageModule.h

│    │   ├──...

│   └── ...

1.主程序（main）：用于调用其他模块。
2.存储模块（StorageModules）：使用无向图存储节点信息和道路信息（要动态内存管理），节点信息要包括节点坐标、节点名称，道路信息要包括道路长度（利用两节点的坐标带入两点间距离公式求出）。
3.操作模块（OperationalModules）：进行向无向图进行插入节点、插入道路、删除节点、删除道路、修改节点名称等操作。
4.导航模块（NavigationModule）：输入起点和终点利用迪杰斯特拉算法求出最短路径
5.图形界面（Menu）：使用EasyX