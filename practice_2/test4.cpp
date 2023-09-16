#include <iostream>
#include <time.h>
using namespace std;


////���Ϊ1��n��n����Χ��һȦ���ӱ��Ϊ1���˿�ʼ����1��������ȥ��
////����m�����뿪����������µ�һ���ˣ�����Ƕ��٣�
//int main() {
//    int n, m;
//    while (cin >> n >> m) { // ע�� while ������ case
//
//        size_t begin = clock();
//        //����
//        int* arr = new int[n];
//        //��ʼ��
//        for (int i = 0; i < n; i++)
//        {
//            arr[i] = i ;
//        }
//
//        //����
//        int i = 0;
//        int num = 1;
//        int size = n;
//        while (size > 1)
//        {
//            if (arr[i] != -1)
//            {
//                i++;
//                if (i >= n) {
//                    i = 0;
//                }
//                num++;
//                if (num == m) {
//                    while (arr[i] == -1)
//                    {
//                        i++;
//                        if (i >= n)
//                        {
//                            i = 0;
//                        }
//                    }
//                    arr[i] = -1;
//                    size--;
//                    num = 1;
//                    i++;
//                    //if (size == 1)
//                    //{
//                    //    while (arr[i] == -1)
//                    //    {
//                    //        i++;
//                    //        if (i >= n)
//                    //        {
//                    //            i = 0;
//                    //        }
//                    //    }
//                    //    cout << arr[i] << endl;
//                    //    break;
//                    //}
//                }
//            }
//            else
//            {
//                i++;
//            }
//
//            if (i >= n) {
//                i = 0;
//            }
//        }
//
//
//        for (i = 0; i < n; i++)
//        {
//            if (arr[i] != -1)
//            {
//                cout << arr[i] << endl;
//            }
//        }
//        size_t end = clock();
//        cout << end - begin << endl;
//
//        delete[] arr;
//
//
//    }
//}


#include <iostream>
#include <time.h>
using namespace std;

//�㷨�Ż�2.0    ֮ǰʱ�临�Ӷ�O(N!)
//��������
#include <assert.h>
//����    cpp���װ,��ͷ,˫��,ѭ��

//template<class T>
typedef int T;
//�ڵ�
class ListNode {
    friend class List;
public:
    //���캯��  ��ʼ��
    ListNode()
        : _val(0)
        , _prev(nullptr)
        , _next(nullptr)
    {}

    //private:
    T _val;
    ListNode* _prev;
    ListNode* _next;
};

//����
//template<class T>
class List {
public:
    //���캯��  ��ʼ��
    List(ListNode* plist)
        : _phead(plist)
        , _size(0) {
        //_phead = (ListNode*)malloc(sizeof(ListNode));
        _phead->_next = _phead;
        _phead->_prev = _phead;
    }

    //��������  �ͷ���Դ
    ~List() {
        //ListNode* cur = _phead->_next;
        //while (cur != _phead)
        //{
        //  ListNode* next = cur->_next;
        //  free(cur);
        //  cur = next;     //ָ��next
        //}
        //free(_phead);
    }

    //pos֮ǰ����
    void PushInsert(T x, ListNode* pos) {
        //assert(pos);
        _size++;

        ListNode* newnode = BuyNode(x);
        ListNode* prev = pos->_prev;

        prev->_next = newnode;
        newnode->_next = pos;
        pos->_prev = newnode;
        newnode->_prev = prev;
    }

    ////pos֮�����
    //void PushAfter(const T x, ListNode* pos)
    //{
    //  //����
    //  PushInsert(x, pos->_next);
    //}

    //BUG�޸�:�߼��޸�,����ɾ��pos֮ǰ,��ɾ��pos��λ��
    void PopInsert(ListNode* pos) {
        //assert(pos);
        //assert(pos != _phead);
        _size--;

        ListNode* prev = pos->_prev;
        ListNode* next = pos->_next;
        //free(pos);
        prev->_next = next;
        next->_prev = prev;

    }

    //void PopAfter(ListNode* pos)
    //{
    //  //����
    //  PopInsert(pos->_next);
    //}

    void PushBack(const T x) {
        PushInsert(x, _phead);
    }

    //void PushFront(const T x)
    //{
    //  PushAfter(x, _phead);
    //}

    void PopBack() {
        PopInsert(_phead->_prev);
    }

    //void PopFront()
    //{
    //  PopAfter(_phead);
    //}

    //Ԫ�ظ���
    int Size() {
        //ListNode* cur = _phead->next;
        //int size = 0;
        //while (cur != _phead)
        //{
        //  size++;
        //  cur = cur->_next;
        //}
        return _size;
    }

    //�Ƿ�Ϊ��
    bool Empty() {
        return Size() == 0;
    }

    //ListNode* Find(const T x)
    //{
    //  ListNode* cur = _phead->_next;
    //  while (cur != _phead)
    //  {
    //      if (x == cur->_val)
    //      {
    //          return cur;
    //      }
    //      cur = cur->_next;
    //  }
    //  return nullptr;
    //}

    ////ListNode �з����޶�,����ֱ���޸�����,��Ҫ�ӿں���
    //void Change(const T x, ListNode* pos)
    //{
    //  pos->_val = x;
    //}

    void Print() {
        ListNode* cur = _phead->_next;
        while (cur != _phead) {
            cout << cur->_val << " ";
            cur = cur->_next;
        }
        cout << endl;
    }
protected:
    ListNode* BuyNode(T x) {
        //ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
        //if (nullptr == newnode)
        //{
        //  perror("BuyNode");
        //  exit(-1);
        //}

        ListNode* newnode = _phead + _size;

        newnode->_val = x;
        return newnode;
    }

    //private:
public:
    ListNode* _phead;
    int _size;
};

//int main() {
//    int n, m;
//    ListNode* plist = new ListNode[1000000 + 1];
//    List s(plist);
//
//    while (cin >> n >> m) { // ע�� while ������ case
//        //��ʼ��
//        //�Ż�,һ�ο��ٴ�ռ�,�ڴ��
//        s._size = 0;
//        for (int i = 0; i < n; i++) {
//            s.PushBack(i + 1);
//        }
//        //s.Print();
//
//
//        //ѭ���ж�
//        ListNode* cur = s._phead->_next;
//        int count = 1;
//        while (1) {
//            //�ҵ���m����ŵ���
//            while (count < m) {
//                cur = cur->_next;
//                count++;
//
//                //����ͷ�ڵ�
//                if (cur == s._phead) {
//                    if (!s.Empty()) {
//                        cur = cur->_next;
//                    }
//                    else {
//                        break;
//                    }
//                }
//            }
//
//            //ɱ����ŵ�m��
//            if (s.Size() > 1 && cur != s._phead) {
//                //s.Print();
//                ListNode* next = cur->_next;
//                s.PopInsert(cur);
//                cur = next;
//                //����ͷ�ڵ�
//                if (cur == s._phead && !s.Empty()) {
//                    cur = cur->_next;
//                }
//            }
//            count = 1;
//
//            //�ж��Ƿ�ֻʣһ����
//            if (s.Size() == 1) {
//                break;
//            }
//        }
//
//        //������
//        s.Print();
//        //cout << s._phead->_next->_val;
//
//    }
//
//    delete[] s._phead;
//}
////�Ż�,�ڴ��