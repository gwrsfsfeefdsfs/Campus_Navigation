//
// Created by Apollyon on 24-7-2.
//
#include "StorageModule.h"
#include <cmath>
#include <iostream>

// ���캯������ʼ����������
StorageModule::StorageModule() {
    generateTestData();
}

// ����ڵ�
void StorageModule::insertNode(const std::string& name, double x, double y, int type) {
    nodes[name] = {name, static_cast<short>(x), static_cast<short>(y), type};
}
void StorageModule::insertNode_building( const std::string& name,const std::string& imgepath2){
    nodes[name].imagepath = imgepath2;
    nodes[name].imagetext = name;
}
// �����·�����㲢�洢���ڵ��ľ���
void StorageModule::insertRoad(const std::string& from, const std::string& to) {
    if (nodes.find(from) != nodes.end() && nodes.find(to) != nodes.end()) {
        double distance = sqrt(pow(nodes[from].x - nodes[to].x, 2) + pow(nodes[from].y - nodes[to].y, 2));
        adjMatrix[from][to] = distance;
        adjMatrix[to][from] = distance; // ����ͼ
    }
}

// ɾ���ڵ㼰����صĵ�·��Ϣ
void StorageModule::deleteNode(const std::string& name) {
    nodes.erase(name);
    adjMatrix.erase(name);
    for (auto& pair : adjMatrix) {
        pair.second.erase(name);
    }
}

// ɾ����·��Ϣ
void StorageModule::deleteRoad(const std::string& from, const std::string& to) {
    adjMatrix[from].erase(to);
    adjMatrix[to].erase(from);
}

// �޸Ľڵ�����
void StorageModule::modifyNodeName(const std::string& oldName, const std::string& newName) {
    if (nodes.find(oldName) != nodes.end()) {
        Node node = nodes[oldName];
        node.name = newName;
        nodes.erase(oldName);
        nodes[newName] = node;

        adjMatrix[newName] = adjMatrix[oldName];
        adjMatrix.erase(oldName);

        for (auto& pair : adjMatrix) {
            if (pair.second.find(oldName) != pair.second.end()) {
                pair.second[newName] = pair.second[oldName];
                pair.second.erase(oldName);
            }
        }
    }
}

// ��ȡ�ڵ��б�
const std::unordered_map<std::string, Node>& StorageModule::getNodes() const {
    return nodes;
}

// ��ȡ�ڽӾ���
const std::unordered_map<std::string, std::unordered_map<std::string, double>>& StorageModule::getAdjMatrix() const {
    return adjMatrix;
}
void StorageModule::reClear(){
  nodes.clear();
    adjMatrix.clear();


};
// ��ʼ������
void StorageModule::generateTestData() {
//�ʺ���·��
    insertNode("�ʺ������", 153, 562, 1);
    insertNode("�ʺ�������ѧ·����1", 136, 538,1);
    insertNode("�ʺ�������ѧ·����2", 121, 502,1);
    insertNode("�ʺ�������ѧ·����", 128, 481,1);
    insertNode("�ʺ����յ�1", 168, 456,1);
    insertNode("�ʺ�����Ȱѧ·����", 210, 431,1);
    insertNode("�ʺ������ѧ·����", 248, 390,1);
    insertNode("�ʺ��������۴������", 279, 319,1);
    insertNode("�ʺ����벩ѧ·����", 282, 249,1);
    insertNode("�ʺ���������·���㣨����ʳ�ã�", 350, 182,1);
    insertNode("�ʺ�������ѧ·�ͺ�ѧ·����", 438, 154,1);
    insertNode("�ʺ����յ�2��˼������", 269, 361,1);
    insertNode("�ʺ����յ�3�����򳡣�", 276, 284,1);
    insertNode("�ʺ����յ�4���Ĵ����ģ�", 313, 209,1);
    insertNode("�ʺ����յ�5��������ѧ¥��", 395, 168,1);
    insertNode("�ʺ����յ�6����԰��", 490, 134,1);
    insertNode("�ʺ�������԰·����", 513, 111,1);
    insertNode("�ʺ����յ㣨�����ţ�", 531, 77,1);
//------

    //�����۹�����
    insertNode("�����۹�����",73,520,1);
    insertNode("�����۹����У������۹�����",92,560,1);
    insertNode("�����۹�����",106,580,1);
    insertNode("�����۹�����",68,597,1);
    insertNode("�����۹�����",38,542,1);
    insertNode("�����۹�����",97,508,1);
//------

    //��ѧ����ѧ��Ȱѧ·����
    insertNode("��ѧ·�յ�1��͡Է��",75,444,2);
    insertNode("��ѧ·����ѧ·����",79,423,1);
    insertNode("��ѧ·�յ�1",70,398,2);
    insertNode("��ѧ·��Ȱѧ·����",142,356,1);
    insertNode("Ȱѧ·�����۴�����㣨��԰������",138,339,1);
    insertNode("Ȱѧ·�յ�1����Է��",171,394,2);
//--------

//�Ͼ�·����
    insertNode("�Ͼ�·�����۴�����㣨��Է��",98,339,1);
    insertNode("�Ͼ�·�յ�1",126,268,2);
    insertNode("�Ͼ�·�յ�2",171,236,2);
    insertNode("�Ͼ�·�յ�3",212,206,2);
    insertNode("�Ͼ�·����ѧ·����",235,204,1);
    //-----

//��ѧ·����
    insertNode("��ѧ·�벩ѧ·����",232,222,1);
    insertNode("��ѧ·�յ���2",207,254,2);
    insertNode("��ѧ·�յ���1",186,284,2);
    insertNode("��ѧ·�յ���1",249,177,2);
    insertNode("��ѧ·�յ���2",276,159,2);
    insertNode("��ѧ·�����۴������",184,334,1);
    insertNode("��ѧ·������·����ѧ·����",312,153,1);
//-----

    //��ѧ·����
    insertNode("��ѧ·�յ�1��͡Է��",323,132,2);
    insertNode("��ѧ·�յ�2",320,100,2);
    insertNode("��ѧ·�յ�3����Է��",327,78,2);
    insertNode("��ѧ·�յ�4",340,68,2);
    insertNode("��ѧ·�յ�5",370,64,2);
    insertNode("��ѧ·�յ�6",396,73,2);
    insertNode("��ѧ·�յ�7�������˶�����",404,91,2);
    insertNode("��ѧ·�յ�8",408,120,2);
    insertNode("��ѧ·����̹�¥",463,112,3);
    insertNode_building("��ѧ·����̹�¥" ,"../GUET_Photos/testImage.png" );
    insertNode("��Է",408,65,3);
    //insertNode_building("��Է" ,"../GUET_Photos/.png" ,"��Է");
    insertNode("����",337,52,3);
    //insertNode_building("����" ,"../GUET_Photos/.png" ,"����");
//-----

//��԰·����
    insertNode("��԰·������·����",548,175,1);
    insertNode("��԰·�յ�1��ƥ���򳡣�",568,215,2);
    insertNode("��԰·�����۴������",574,244,1);
    insertNode("��԰·�յ�2",576,285,2);
    insertNode("��԰·�յ�3",572,326,2);
    insertNode("��԰·�յ�4",561,364,2);
    insertNode("��԰·�յ�5",539,398,2);
    insertNode("��԰·�յ�6",498,435,2);
    insertNode("��԰·������·����",445,461,1);
    insertNode("��1��",443,542,3);
    //insertNode_building("��1��" ,"../GUET_Photos/.png" ,"��1��");
//-----
    //��ѧ·����
    insertNode("��ѧ·������·����",443,403,1);
    insertNode("��ѧ·�յ�1������ʵѵ¥��",480,375,2);
    insertNode("��ѧ·�յ�2��˼ó����",504,337,2);
    insertNode("��ѧ·�յ�3������¥��",513,309,2);
    insertNode("��ѧ·�����۴������",516,279,2);
    insertNode("��ѧ·�յ�4����˼����",510,247,2);
    insertNode("��ѧ·������·����",490,210,1);
    insertNode("��ѧ·�յ�5",470,181,2);
    insertNode("��ʮ�Ľ�",405,414,1);
    insertNode("��ѧ·�յ���2",336,401,2);
    insertNode("��ѧ·�յ���3",301,405,2);
//-----

    //����·����
    insertNode("����·�����۴������",370,298,1);
    insertNode("����·�յ�1�����˼����ѧԺ��",367,280,1);
    insertNode("����·�յ�2�����̣�",372,256,1);
    insertNode("����·�յ�3����̣�",390,235,1);
    insertNode("����·����ѧ·����",407,220,1);
    insertNode("����·�յ�4����Ϣ��ͨ��ѧԺ��",445,213,1);
    insertNode("����·�յ�5",472,214,2);
    insertNode("����·�յ�6",526,197,2);
//-----

//���۴������
    insertNode("11��",394,293,1);
    insertNode("�������ĺͰ칫¥",485,296,1);
    insertNode("���۴��������·����",445,299,1);
    insertNode("���۴���յ�1",550,263,2);
    insertNode("˼Ԯ��",318,309,1);
    insertNode("���۴����Ǳѧ·����",423,294,1);
//-----

    //Ǳѧ·����
    insertNode("Ǳѧ·���ѧ·����ѧ·����",361,403,1);
    insertNode("Ǳѧ·�յ�1",421,331,1);
    insertNode("Ǳѧ·�յ�2��ʮ���̣�",394,341,1);
    insertNode("Ǳѧ·�յ�3��ʮ�߽̣�",385,369,1);
//-----
    //��ѧ·����
    insertNode("��ѧ·���ѧ·����",345,434,1);
    insertNode("��ѧ·����ѧ·����",327,467,1);
    insertNode("��2��",345,526,3);
    //insertNode_building("��2��" ,"../GUET_Photos/.png" ,"��2��");
//-----
//��ѧ·����ѧ·����
    insertNode("��ѧ·�յ�1�����������ѧԺ��",397,462,1);
    insertNode("��ѧ·�յ�2����ʮ��̣�",363,456,1);
    insertNode("��ѧ·�յ�3����ѧ�㳡��",305,443,1);
    insertNode("��ѧ·����ѧ·���㣨��԰������",278,453,1);
    insertNode("��ѧ·��ڣ���Է��",263,444,1);
    insertNode("��ѧ��·",235,446,1);
    insertNode("��ѧ��·",250,424,1);
    insertNode("��ѧ��·��ʺ�������",233,412,1);
//-----

    //������㼰��·
    insertNode("��Է",250,46,3);
    //insertNode_building("��Է" ,"../GUET_Photos/.png" ,"��Է");
    insertNode("��Է",275,118,3);
    //insertNode_building("��Է" ,"../GUET_Photos/.png" ,"��Է");
    insertNode("����԰",138,100,3);
    //insertNode_building("����԰" ,"../GUET_Photos/.png" ,"����԰");
    insertNode("�����˶���",378,103,3);
    //insertNode_building("�����˶���" ,"../GUET_Photos/.png" ,"�����˶���");
    insertNode("˼Ԯ���˶���",250,289,3);
    //insertNode_building("˼Ԯ���˶���" ,"../GUET_Photos/.png" ,"˼Ԯ���˶���");
    insertNode("˼����˶���",366,508,3);
    //insertNode_building("˼����˶���" ,"../GUET_Photos/.png" ,"˼����˶���");
    insertNode("��ҵ��",383,139,3);
    //insertNode_building("��ҵ��" ,"../GUET_Photos/.png" ,"��ҵ��");
    insertNode("����ʳ��",360,152,3);
    //insertNode_building("����ʳ��" ,"../GUET_Photos/.png" ,"����ʳ��");
    insertNode("�Ĵ�����",269,210,3);
    //insertNode_building("�Ĵ�����" ,"../GUET_Photos/.png" ,"�Ĵ�����");
    insertNode("��Է",51,309,3);
    //insertNode_building("��Է ,"../GUET_Photos/.png" ,"��Է");
    insertNode("͡Է",57,468,3);
    //insertNode_building("͡Է" ,"../GUET_Photos/.png" ,"͡Է");
    insertNode("��Է",129,419,3);
    //insertNode_building("��Է" ,"../GUET_Photos/.png" ,"��Է");
    insertNode("��Է",248,484,3);
    //insertNode_building("��Է" ,"../GUET_Photos/.png" ,"��Է");
    insertNode("˼����",313,357,3);
    //insertNode_building("˼����" ,"../GUET_Photos/.png" ,"˼����");
    insertNode("˼Ԯ��2",311,271,3);
    //insertNode_building("˼Ԯ��2" ,"../GUET_Photos/.png" ,"˼Ԯ��2");
    insertNode("˼�ͺ�",467,360,3);
    //insertNode_building("˼�ͺ�" ,"../GUET_Photos/.png" ,"˼�ͺ�");
    insertNode("��˼��",484,258,3);
    //insertNode_building("��˼��" ,"../GUET_Photos/.png" ,"��˼��");
    insertNode("˼���",412,508,3);
    //insertNode_building("˼���" ,"../GUET_Photos/.png" ,"˼���");
    insertNode("��԰",502,163,3);
    //insertNode_building("��԰" ,"../GUET_Photos/.png" ,"��԰");
    insertNode("��԰����",135,309,3);
    //insertNode_building("��԰����" ,"../GUET_Photos/.png" ,"��԰����");
    insertNode("��԰����",281,432,3);
    //insertNode_building("��԰����" ,"../GUET_Photos/.png" ,"��԰����");
    insertNode("11��13��14��ѧ¥",373,327,3);
    //insertNode_building("11��13��14��ѧ¥" ,"../GUET_Photos/.png" ,"11��13��14��ѧ¥");
    insertNode("15��16��ѧ¥",413,360,3);
    //insertNode_building("15��16��ѧ¥" ,"../GUET_Photos/.png" ,"15��16��ѧ¥");
    insertNode("1��2��3��ѧ¥",418,181,3);
    //insertNode_building("1��2��3��ѧ¥" ,"../GUET_Photos/.png" ,"1��2��3��ѧ¥");
    insertNode("44��43��42��ѧ¥",399,441,3);
    //insertNode_building("44��43��42��ѧ¥" ,"../GUET_Photos/.png" ,"44��43��42��ѧ¥");
    insertNode("4��5��6��ѧ¥",364,227,3);
    //insertNode_building("4��5��6��ѧ¥" ,"../GUET_Photos/.png" ,"4��5��6��ѧ¥");
    insertNode("7��8��ѧ¥",347,274,3);
    //insertNode_building("7��8��ѧ¥" ,"../GUET_Photos/.png" ,"7��8��ѧ¥");
    insertNode("ͼ���",412,257,3);
    //insertNode_building("ͼ���" ,"../GUET_Photos/.png" ,"ͼ���");
    insertNode("�����뽻ͨ���̺ͻ��繤��ѧԺ",534,334,3);
    //insertNode_building("�����뽻ͨ���̺ͻ��繤��ѧԺ" ,"../GUET_Photos/.png" ,"�����뽻ͨ���̺ͻ��繤��ѧԺ");
    insertNode("����ʵѵ��¥",516,376,3);
    //insertNode_building("����ʵѵ��¥" ,"../GUET_Photos/.png" ,"����ʵѵ��¥");
    insertNode("��Ϣ��ͨ��ѧԺ",445,203,3);
    //insertNode_building("��Ϣ��ͨ��ѧԺ" ,"../GUET_Photos/.png" ,"��Ϣ��ͨ��ѧԺ");


    insertNode("���۴���������1",237,328,1);
    insertNode("�Ͼ�·�������1",109,303,1);
    insertNode("��ѧ·�������1",179,311,1);
    insertNode("��ѧ·�������2",194,267,1);
    insertNode("��ѧ·�������1",84,479,1);
    insertNode("��ѧ·�������1",102,451,1);
    insertNode("��ѧ·�������1",272,400,1);


    insertRoad("���۴���������1","��ѧ·�����۴������");
    insertRoad("���۴���������1","�ʺ��������۴������");

    insertRoad("�Ͼ�·�������1","�Ͼ�·�����۴�����㣨��Է��");
    insertRoad("�Ͼ�·�������1","�Ͼ�·�յ�1");

    insertRoad("��ѧ·�������1","��ѧ·�յ���1");
    insertRoad("��ѧ·�������1","��ѧ·�����۴������");
    insertRoad("��ѧ·�������2","��ѧ·�յ���1");
    insertRoad("��ѧ·�������2","��ѧ·�յ���2");

    insertRoad("��ѧ·�������1","�����۹�����");
    insertRoad("��ѧ·�������1","��ѧ·�յ�1��͡Է��");

    insertRoad("��ѧ·�������1","��ѧ·����ѧ·����");
    insertRoad("��ѧ·�������1","�ʺ�������ѧ·����");

    insertRoad("��ѧ·�������1","��ѧ·�յ���3");
    insertRoad("��ѧ·�������1","�ʺ������ѧ·����");

    //-----

    //����·������������
    insertRoad("��ѧ·������·����","���۴��������·����");
    insertRoad("���۴��������·����","����·�յ�4����Ϣ��ͨ��ѧԺ��");

//-----
    insertRoad("Ȱѧ·�����۴�����㣨��԰������","��ѧ·�����۴������");

    insertRoad("�ʺ������","�ʺ�������ѧ·����1");
    insertRoad("�ʺ�������ѧ·����1","�ʺ�������ѧ·����2");
    insertRoad("�ʺ�������ѧ·����2","�ʺ�������ѧ·����");
    insertRoad("�ʺ�������ѧ·����","�ʺ����յ�1");
    insertRoad("�ʺ����յ�1","�ʺ�����Ȱѧ·����");
    insertRoad("�ʺ�����Ȱѧ·����","��ѧ��·��ʺ�������");
    insertRoad("��ѧ��·��ʺ�������","�ʺ������ѧ·����");
    insertRoad("�ʺ������ѧ·����","�ʺ����յ�2��˼������");
    insertRoad("�ʺ����յ�2��˼������","�ʺ��������۴������");
    insertRoad("�ʺ��������۴������","�ʺ����յ�3�����򳡣�");
    insertRoad("�ʺ����յ�3�����򳡣�","�ʺ����벩ѧ·����");
    insertRoad("�ʺ����벩ѧ·����","�ʺ����յ�4���Ĵ����ģ�");
    insertRoad("�ʺ����յ�4���Ĵ����ģ�","�ʺ���������·���㣨����ʳ�ã�");
    insertRoad("�ʺ���������·���㣨����ʳ�ã�","�ʺ����յ�5��������ѧ¥��");
    insertRoad("�ʺ����յ�5��������ѧ¥��","�ʺ�������ѧ·�ͺ�ѧ·����");
    insertRoad("�ʺ�������ѧ·�ͺ�ѧ·����","�ʺ����յ�6����԰��");
    insertRoad("�ʺ����յ�6����԰��","�ʺ�������԰·����");
    insertRoad("�ʺ�������԰·����","�ʺ����յ㣨�����ţ�");

    insertRoad("�ʺ������","�����۹�����");
    insertRoad("�ʺ�������ѧ·����1","�����۹����У������۹�����");
    insertRoad("�ʺ�������ѧ·����2","�����۹�����");
    insertRoad("�����۹�����","�����۹�����");
    insertRoad("�����۹�����","�����۹�����");
    insertRoad("�����۹�����","�����۹�����");
    insertRoad("�����۹�����","�����۹�����");
    insertRoad("�����۹�����","�����۹����У������۹�����");
    insertRoad("�����۹����У������۹�����","�����۹�����");

    //insertRoad("�����۹�����","��ѧ·�յ�1��͡Է��");
    insertRoad("��ѧ·�յ�1��͡Է��","��ѧ·����ѧ·����");
    insertRoad("��ѧ·����ѧ·����","��ѧ·�յ�1");
    insertRoad("��ѧ·�յ�1","��ѧ·��Ȱѧ·����");
    //insertRoad("��ѧ·����ѧ·����","�ʺ�������ѧ·����");
    insertRoad("Ȱѧ·�����۴�����㣨��԰������","��ѧ·��Ȱѧ·����");
    insertRoad("��ѧ·��Ȱѧ·����","Ȱѧ·�յ�1����Է��");
    insertRoad("Ȱѧ·�յ�1����Է��","�ʺ�����Ȱѧ·����");

    insertRoad("�Ͼ�·�����۴�����㣨��Է��","Ȱѧ·�����۴�����㣨��԰������");
    //insertRoad("�Ͼ�·�����۴�����㣨��Է��","�Ͼ�·�յ�1");
    insertRoad("�Ͼ�·�յ�1","�Ͼ�·�յ�2");
    insertRoad("�Ͼ�·�յ�2","�Ͼ�·�յ�3");
    insertRoad("�Ͼ�·�յ�3","�Ͼ�·����ѧ·����");
    insertRoad("Ȱѧ·�����۴�����㣨��԰������","��ѧ·�����۴������");

    insertRoad("��ѧ·�벩ѧ·����","��ѧ·�յ���2");
    //insertRoad("��ѧ·�յ���1","��ѧ·�յ���2");
    //insertRoad("��ѧ·�յ���1","��ѧ·�����۴������");
    insertRoad("��ѧ·�벩ѧ·����","�ʺ����벩ѧ·����");
    insertRoad("��ѧ·�벩ѧ·����","�Ͼ�·����ѧ·����");
    insertRoad("�Ͼ�·����ѧ·����","��ѧ·�յ���1");
    insertRoad("��ѧ·�յ���1","��ѧ·�յ���2");
    insertRoad("��ѧ·�յ���2","��ѧ·������·����ѧ·����");
    //insertRoad("��ѧ·�����۴������","�ʺ��������۴������");

    insertRoad("��ѧ·������·����ѧ·����","�ʺ���������·���㣨����ʳ�ã�");
    insertRoad("��ѧ·������·����ѧ·����","��ѧ·�յ�1��͡Է��");
    insertRoad("��ѧ·�յ�1��͡Է��","��ѧ·�յ�2");
    insertRoad("��ѧ·�յ�2","��ѧ·�յ�3����Է��");
    insertRoad("��ѧ·�յ�3����Է��","��ѧ·�յ�4");
    insertRoad("��ѧ·�յ�4","����");
    insertRoad("��ѧ·�յ�4","��ѧ·�յ�5");
    insertRoad("��ѧ·�յ�5","��ѧ·�յ�6");
    insertRoad("��ѧ·�յ�6","��Է");
    insertRoad("��ѧ·�յ�6","��ѧ·�յ�7�������˶�����");
    insertRoad("��ѧ·�յ�7�������˶�����","��ѧ·�յ�8");
    insertRoad("��ѧ·�յ�8","��ѧ·����̹�¥");
    insertRoad("��ѧ·�յ�8","�ʺ�������ѧ·�ͺ�ѧ·����");

    insertRoad("��ѧ·������·����","��԰·������·����");
    insertRoad("��ѧ·������·����","��ѧ·�յ�1������ʵѵ¥��");
    insertRoad("��ѧ·�յ�1������ʵѵ¥��","��ѧ·�յ�2��˼ó����");
    insertRoad("��ѧ·�յ�2��˼ó����","��ѧ·�յ�3������¥��");
    insertRoad("��ѧ·�յ�3������¥��","��ѧ·�����۴������");
    insertRoad("��ѧ·�����۴������","��ѧ·�յ�4����˼����");
    insertRoad("��ѧ·�յ�4����˼����","��ѧ·������·����");
    insertRoad("��ѧ·������·����","��ѧ·�յ�5");
    insertRoad("��ѧ·�յ�5","�ʺ�������ѧ·�ͺ�ѧ·����");
    insertRoad("��ѧ·������·����","��ʮ�Ľ�");
    insertRoad("��ʮ�Ľ�","Ǳѧ·���ѧ·����ѧ·����");
    insertRoad("Ǳѧ·���ѧ·����ѧ·����","��ѧ·�յ���2");
    insertRoad("��ѧ·�յ���2","��ѧ·�յ���3");
    //insertRoad("��ѧ·�յ���3","�ʺ������ѧ·����");

    insertRoad("����·����ѧ·����","�ʺ���������·���㣨����ʳ�ã�");
    insertRoad("����·�����۴������","����·�յ�1�����˼����ѧԺ��");
    insertRoad("����·�յ�1�����˼����ѧԺ��","����·�յ�2�����̣�");
    insertRoad("����·�յ�2�����̣�","����·�յ�3����̣�");
    insertRoad("����·�յ�3����̣�","����·����ѧ·����");
    insertRoad("����·����ѧ·����","����·�յ�4����Ϣ��ͨ��ѧԺ��");
    insertRoad("����·�յ�4����Ϣ��ͨ��ѧԺ��","����·�յ�5");
    insertRoad("����·�յ�5","��ѧ·������·����");
    insertRoad("��ѧ·������·����","����·�յ�6");
    insertRoad("����·�յ�6","��԰·������·����");

    insertRoad("�ʺ��������۴������","˼Ԯ��");
    insertRoad("˼Ԯ��","����·�����۴������");
    insertRoad("����·�����۴������","11��");
    insertRoad("11��","���۴����Ǳѧ·����");
    insertRoad("���۴����Ǳѧ·����","���۴��������·����");
    insertRoad("���۴��������·����","�������ĺͰ칫¥");
    insertRoad("�������ĺͰ칫¥","��ѧ·�����۴������");
    insertRoad("��ѧ·�����۴������","���۴���յ�1");
    insertRoad("���۴���յ�1","��԰·�����۴������");

    insertRoad("Ǳѧ·���ѧ·����ѧ·����","Ǳѧ·�յ�3��ʮ�߽̣�");
    insertRoad("Ǳѧ·�յ�3��ʮ�߽̣�","Ǳѧ·�յ�2��ʮ���̣�");
    insertRoad("Ǳѧ·�յ�2��ʮ���̣�","Ǳѧ·�յ�1");
    insertRoad("Ǳѧ·�յ�1","���۴����Ǳѧ·����");

    insertRoad("Ǳѧ·���ѧ·����ѧ·����","��ѧ·���ѧ·����");
    insertRoad("��ѧ·���ѧ·����","��ѧ·����ѧ·����");
    insertRoad("��ѧ·����ѧ·����","��2��");

    insertRoad("��԰·������·����","��ѧ·�յ�1�����������ѧԺ��");
    insertRoad("��ѧ·�յ�1�����������ѧԺ��","��ѧ·�յ�2����ʮ��̣�");
    insertRoad("��ѧ·�յ�2����ʮ��̣�","��ѧ·���ѧ·����");
    insertRoad("��ѧ·���ѧ·����","��ѧ·�յ�3����ѧ�㳡��");
    insertRoad("��ѧ·�յ�3����ѧ�㳡��","��ѧ·����ѧ·���㣨��԰������");
    insertRoad("��ѧ·����ѧ·���㣨��԰������","��ѧ·����ѧ·����");
    insertRoad("��ѧ·����ѧ·���㣨��԰������","��ѧ·��ڣ���Է��");
    insertRoad("��ѧ·��ڣ���Է��","��ѧ��·");
    insertRoad("��ѧ��·","��ѧ��·��ʺ�������");
    insertRoad("��ѧ·��ڣ���Է��","��ѧ��·");
    insertRoad("��ѧ��·","�ʺ�����Ȱѧ·����");

    insertRoad("�ʺ�������԰·����","��԰·������·����");
    insertRoad("��԰·������·����","��԰·�յ�1��ƥ���򳡣�");
    insertRoad("��԰·�յ�1��ƥ���򳡣�","��԰·�����۴������");
    insertRoad("��԰·�����۴������","��԰·�յ�2");
    insertRoad("��԰·�յ�2","��԰·�յ�3");
    insertRoad("��԰·�յ�3","��԰·�յ�4");
    insertRoad("��԰·�յ�4","��԰·�յ�5");
    insertRoad("��԰·�յ�5","��԰·�յ�6");
    insertRoad("��԰·�յ�6","��԰·������·����");
    insertRoad("��԰·������·����","��1��");
}
