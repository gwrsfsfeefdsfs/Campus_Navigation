//
// Created by Monster on 24-7-2.
//
#ifndef OPERATIONAL_MODULE_H
#define OPERATIONAL_MODULE_H

#include "StorageModule.h"

class OperationalModule {
private:
    StorageModule& storage;

public:
    // 构造函数
    OperationalModule(StorageModule& storage);

    // 其他操作函数，如插入节点、插入道路、删除节点、删除道路、修改节点名称等的接口
};

#endif // OPERATIONAL_MODULE_H