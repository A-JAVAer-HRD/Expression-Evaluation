//
// Created by huangruidong on 2022/12/1.
//

#ifndef ALOGORITHM_NODE_H
#define ALOGORITHM_NODE_H
template <class Node_entry>
struct Node {
    //数据域
    Node_entry entry;//数值
    Node<Node_entry>* next;//next指针
    //构造方法
    Node();

    /*
     * 默认参数
     * 如果不传就用默认参数
     * 如果传了值就用下边的构造方法
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
