//
// Created by huangruidong on 2022/12/1.
//

#ifndef ALOGORITHM_NODE_H
#define ALOGORITHM_NODE_H
template <class Node_entry>
struct Node {
    //������
    Node_entry entry;//��ֵ
    Node<Node_entry>* next;//nextָ��
    //���췽��
    Node();

    /*
     * Ĭ�ϲ���
     * �����������Ĭ�ϲ���
     * �������ֵ�����±ߵĹ��췽��
     * */
    Node(Node_entry item, Node<Node_entry>* add_on = nullptr);
};

template <class Node_entry> Node<Node_entry>::Node() {
    next = nullptr;
}


template <class Node_entry> Node<Node_entry>::Node(Node_entry item, Node<Node_entry>* add_on) {
    entry = item;
    next = add_on;
}
#endif //ALOGORITHM_NODE_H
