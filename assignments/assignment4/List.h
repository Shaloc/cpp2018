#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>

// 循秩访问
typedef int Rank;
// 列表节点位置
#define ListNodePosi ListNode*
// 声明类
class CPPListIterator;
class CPPList;

// 列表节点类
struct ListNode {
    // 成员
    int data;//数值
    ListNodePosi prev;//前驱（也写作pred）
    ListNodePosi next;//后驱（也写作succ）
    // 构造函数
    ListNode() { } //头尾哨兵节点的构造函数
    ListNode(int e, ListNodePosi p=NULL, ListNodePosi s=NULL) :
        data(e), prev(p), next(s) {} //默认构造函数
    // 操作接口
    ListNodePosi insertAsPrev(int const& e);//紧靠当前节点之前插入新节点
    ListNodePosi insertAsNext(int const& e);//紧靠当前节点之后插入新节点
};

// 列表类
class CPPList {
private:
    int _size;//规模
    ListNodePosi header;//头哨兵，在第一个节点前
    ListNodePosi trailer;//尾哨兵，在最后一个节点后

protected:
    void init();//初始化
    void copyNodes(ListNodePosi p, int n);//复制列表中自位置p起的n项

public:
    typedef CPPListIterator Iterator;//声明迭代器
    typedef CPPListIterator ConstIterator;//声明整形迭代器--你已经足够成熟了！可以完全用整形了！
    // 构造函数
    CPPList();//默认构造函数，仅做初始化处理
    CPPList( const CPPList& rhs ) { copyNodes( rhs.first(), rhs._size); }//拷贝构造函数，用于最后一问
    // 析构函数
    ~CPPList() { clear(); delete header; delete trailer; } //析构函数
    // 操作函数
    // 只读访问接口
    Rank size() const { return _size; }
    ListNodePosi first() const { return header->next; } //首节点
    ListNodePosi last() const { return trailer->prev; } //尾节点
    bool valid( ListNodePosi p ) { return p && (trailer!=p) && (header!=p); } //将哨兵视为NULL
    int& operator[](Rank r) const; //允许循秩访问，但是效率低，因为规模不大所以无所谓
    // 可写访问接口
    ListNodePosi insertAsFirst( int const& e );//插入
    ListNodePosi insertAsLast ( int const& e );
    ListNodePosi insertAsPrev ( ListNodePosi p, int const& e);
    ListNodePosi insertAsNext ( ListNodePosi p, int const& e);
    ListNodePosi push_back( int const& e);
    ListNodePosi insert( Iterator t, int const& e);
    int remove ( ListNodePosi p );//删除合法节点p处的节点
    int remove ( Iterator t );//删除迭代器对应的节点
    void clear();//逐一删除并释放全部节点
    // 迭代器接口
    CPPList::Iterator begin() const;
    CPPList::Iterator end() const;
};

// 列表迭代器类
class CPPListIterator {
public:
    friend class CPPList;   //声明为CPPList的友元以便访问CPPList中的变量
    ListNodePosi _ptr;      //迭代量
public:
    // 构造函数
    CPPListIterator() { _ptr = NULL; }
    CPPListIterator( ListNodePosi p ) { _ptr = p; }
    // 只读访问接口
    bool operator==( CPPListIterator rhs ) const { return ( _ptr == rhs._ptr); }
    bool operator!=( CPPListIterator rhs ) const { return (_ptr != rhs._ptr); }
    int &operator*() const { return (*_ptr).data; }
    ListNodePosi operator->() const { return _ptr; }
    // 可写访问接口
    // ++i
    CPPListIterator& operator++() { _ptr = _ptr->next; return (*this); }
    // i++
    const CPPListIterator operator++(int) {
        CPPListIterator temp = *this;
        ++(*this);
        return temp;
    }
    // i = j
    CPPListIterator& operator=(const CPPListIterator& rhs) {
        if( &rhs == this ) return *this;
        _ptr = rhs._ptr;
        return *this;
    }
};



#endif // __LIST_H__