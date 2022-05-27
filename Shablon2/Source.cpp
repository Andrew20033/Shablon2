#include<iostream>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;

struct item {
    long long int data;
    item* next;
};

item* head, * tail;
void add(long long int x);
void delete_(void);
void fromhead(void);
bool isnull(void) { return head == NULL; }

void add(long long int x) {
    item* p = new item;
    p->data = x; p->next = NULL;
    item* v = new item;
    item* p1 = new item;
    item* p2 = new item;
    int i = 0;
    if (isnull()) head = tail = p;
    else {
        p2 = head;
        p1 = head;
        while (p1 != NULL) {
            if (i == 1) {
                if (x >= p1->data) {
                    v->data = x;
                    v->next = p1;
                    p2->next = v;
                    return;
                }
                p2 = p2->next;
            }
            else {
                if (x >= p1->data) {
                    v->data = x;
                    v->next = p1;
                    head = v;
                    return;
                }
            }
            p1 = p1->next;
            i = 1;
        }
        if (p1 == NULL) {
            tail->next = p;
            tail = p;
        }
    }

}

void delete_() {
    item* p = head;
    head = head->next;
    delete p;
}

void fromhead() {
    cout << head->data << endl;
}

int main() {
    head = NULL; tail = NULL;
    long long int n, a; string s;
    ifstream in;
    in.open("input.txt");
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> s;
        if (s == "Insert") {
            in >> a;
            add(a);
        }
        if (s == "ExtractMax") {
            fromhead();
            delete_();
        }
    }
    in.close();

    return 0;
}
