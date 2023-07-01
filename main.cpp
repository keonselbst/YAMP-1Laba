#include "list1.h"

using namespace std;

void input(TList& head) {
    int n, x;
    Node* p = head;
    bool flag = 1;
    while (flag) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Enter int n value: ";
        cin >> n;
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else {
            flag = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        flag = 1;
        while (flag)
        {
            cout << "Enter int x value: ";
            cin >> x;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
            }
            else {
                flag = 0;
            }
        }
        if (p == 0)
        {
            addToHead(p, x);
            head = p;
        }
        else
        {
            addAfterNode(p, x);
            p = p->next;
        }
    }
}

void output(TList& head) {
    Node* p = head;
    while (p != 0)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//void init_listX(Node*& headX)
//{
//    headX = NULL;
//}
//
//void init_listY(Node*& headY)
//{
//    headY = NULL;
//}
//
//bool included(int X, Node* headY)
//{
//    bool b = false;
//    Node* pY = new Node;
//    pY = headY;
//    while (pY != NULL && b == false) {
//
//        //std::cout « pY->data « ' ';
//        if (pY->data == X) b = true;
//        pY = pY->next;
//    }
//    //std::cout « '\n';
//    return b;
//}
//
//
//Node* head_of_max_entries(Node* headX, Node* headY, int& c)
//{
//    int max = 0;
//    int count = 0;
//    Node* pX = new Node;
//    pX = headX;
//    Node* pcur = new Node;
//    Node* pmax = new Node;
//    while (pX != NULL) {
//        int X = pX->data;
//        if (included(X, headY) == true)
//
//            count++;
//        else count = 0;
//        if (count == 1)
//            pcur = pX;
//        if (count > max) {
//            max = count;
//
//            pmax = pcur;
//
//        }
//
//
//        pX = pX->next;
//        std::cout << count << '\n';
//    }
//    c = max;
//    return pmax;
//}
//
//
//
//void print_posledovatelnost(Node* pX, Node* headY, int c)
//{
//    Node* pNode = new Node;
//    pNode = pX;
//    int cc = c;
//    if (cc == 0) std::cout << "NO";
//    else
//        while (cc != 0 && pNode != nullptr)
//        {
//            std::cout << pNode->data << ' ';
//            pNode = pNode->next;
//            cc--;
//        }
//}

//void init_listX(Node*& headX)
//{
//    headX = NULL;
//}
//
//void init_listY(Node*& headY)
//{
//    headY = NULL;
//}
//
//bool included(TData X, Node* headY)
//{
//    bool b = false;
//    Node* pY = new Node;
//    pY = headY;
//    while (pY != NULL && b == false) {
//
//        //std::cout « pY->data « ' ';
//        if (pY->data == X) b = true;
//        pY = pY->next;
//    }
//    //std::cout « '\n';
//    return b;
//}


//Node* head_of_max_entries(Node* headX, Node* headY, int& c)
//{
//    int max = 0;
//    int count = 0;
//    Node* pX = new Node;
//    pX = headX;
//    Node* pcur = new Node;
//    Node* pmax = new Node;
//    while (pX != NULL) {
//        int X = pX->data;
//        if (included(X, headY) == true)
//
//            count++;
//        else count = 0;
//        if (count == 1)
//            pcur = pX;
//        if (count > max) {
//            max = count;
//
//            pmax = pcur;
//
//        }
//
//
//        pX = pX->next;
//        std::cout << count << '\n';
//    }
//    c = max;
//    return pmax;
//}

void findFunck(Node* headx, Node* heady, Node*& heado) {
    Node* px = headx;
    Node* py = heady;
    Node* po = heado;
    Node* tmp = py;
    int k = 0, kmax = -1;
    while (px != 0) {
        while (py != 0) {
            if (px->data == py->data) {
                if (kmax == -1) {
                    kmax = 0;
                    addToHead(po, px->data);
                    heado = po;
                    py = py->next;
                }
                else {
                    addAfterNode(po, px->data);
                    py = py->next;
                    po = po->next;
                }
            }
            else {
                py = py->next;
            }
        }
        py = tmp;
        px = px->next;
    }
    
}



int main()
{
    ////TData x = 3;
    Node* Xs, * Ys, * Out;
    initList(Xs);
    input(Xs);
    output(Xs);
    initList(Ys);
    input(Ys);
    output(Ys);
    initList(Out);
    findFunck(Xs, Ys, Out);
   //head_of_max_entries(Xs, Ys, );
    //print_posledovatelnost(Xs, 5);
    output(Out);
    ////deleteAfterElement(Xs, x);
    ////deleteAllZnach(Xs, x);
    //output(Xs);
//    init_listX(Xs);
//    input(Xs);
//    output(Xs);
//    init_listY(Ys);
//    input(Ys);
//    output(Ys);
//    initList(Out);
//    findFunck(Xs, Ys, Out);
//    output(Out);
//
}