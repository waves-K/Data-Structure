#include "SequenceList.hpp"

void SeqListTest() {
    SeqList<int> sl;

    sl.PushBack(1);
    sl.PushBack(2);
    sl.PushBack(3);
    sl.PushBack(4);
    sl.Print();

    sl.PopBack();
    sl.PopBack();
    sl.Print();

    sl.PushFront(0);
    sl.PushFront(-1);
    sl.Print();

    sl.PopFront();
    sl.Print();

    sl.Insert(2, 6);
    sl.Insert(2, 4);
    sl.Insert(2, 4);
    sl.Insert(2, 4);
    sl.Insert(1, 4);
    sl.Insert(3, 6);
    sl.Insert(2, 4);
    sl.Insert(2, 4);
    sl.Insert(2, 4);
    sl.Print();

    sl.Erase(5);
    sl.Erase(5);
    sl.Print();

    cout << sl.Find(4) << endl;

    sl.Modify(2, 5);
    sl.Modify(4, 6);
    sl.Print();

    sl.Remove(4);
    sl.Print();

    cout << sl.Binaryfind(5) << endl;

    sl.PushFront(4);
    sl.PushBack(4);
    sl.Print();

    sl.RemoveAll(4);
    sl.Print();
}

int main() {
    SeqListTest();
    return 0;
}
