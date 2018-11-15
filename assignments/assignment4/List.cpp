#include "List.h"

// 列表节点的相关实现
ListNode * ListNode::insertAsPrev(int const &e) {
    ListNodePosi x = new ListNode(e, prev, this);
    // prev -> x -> this
    prev->next = x;
    prev = x;
    return x;
}

ListNode * ListNode::insertAsNext(int const &e) {
    ListNodePosi x = new ListNode(e, this, next);
    // this -> x -> next
    next->prev = x;
    next = x;
    return x;
}

// 列表的相关实现
void CPPList::init() {
    header = new ListNode;
    trailer = new ListNode;
    header->next = trailer; header->prev = NULL;
    trailer->prev = header; trailer->next = NULL;
    _size = 0;
}

void CPPList::copyNodes( ListNodePosi p, int n) {
    init();//创造新的头尾哨兵节点并初始化
    while ( n-- ) {
        insertAsLast( p->data );
        p = p->next; //将自p起的n个节点作为尾节点插入
    }
}

CPPList::CPPList() {
    init();
}

int& CPPList::operator[](Rank r) const {
    ListNodePosi p = first();
    while( 0 < r-- ) p = p->next;//顺着数r个节点即可
    return p->data;
}

ListNode * CPPList::insertAsFirst(int const &e) {
    _size++;
    return header->insertAsNext(e);
}

ListNode * CPPList::insertAsLast(int const &e) {
    _size++;
    return trailer->insertAsPrev(e);
}

ListNode * CPPList::insertAsNext(ListNode *p, int const &e) {
    _size++;
    return p->insertAsNext(e);
}

ListNode * CPPList::insertAsPrev(ListNode *p, int const &e) {
    _size++;
    return p->insertAsPrev(e);
}

ListNode * CPPList::insert(CPPList::Iterator t, int const &e) {
    _size++;
    return t._ptr->insertAsPrev(e);
}

ListNode * CPPList::push_back(int const &e) {
    return insertAsLast(e);
}

int CPPList::remove(ListNode *p) {
    if(p == NULL)
        return -1;
    int e = p->data;
    // 重新连接P的前驱和后继
    p->prev->next = p->next;
    p->next->prev = p->prev;
    // 内存操作
    delete p;
    _size --;
    return e;
}

int CPPList::remove(CPPList::Iterator t) {
    return remove( t._ptr );
}

void CPPList::clear() {
    while ( 0 < _size ) remove( header->next ); //反复删除首节点，直到列表变空
}

CPPList::Iterator CPPList::begin() const {
    Iterator ret;
    ret._ptr = header->next;
    return ret;
}

CPPList::Iterator CPPList::end() const {
    Iterator ret;
    ret._ptr = trailer;
    return ret;
}