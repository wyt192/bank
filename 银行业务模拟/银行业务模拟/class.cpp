#include"class.h"

client::client(string name, int* phone, bool kind, string id, int arrtime, int reqtime)
	: Name(name), Kind(kind), Id(id), Arrtime(arrtime), Reqtime(reqtime) {
	for (int i = 0; i < 11; i++) {
		Phone[i] = phone[i];
	}
}

client::client(const client& c) {
	this->Arrtime = c.Arrtime;
	this->Id = c.Id;
	this->Kind = c.Kind;
	this->Name = c.Name;
	this->Reqtime = c.Reqtime;
	for (int i = 0; i < 11; i++) {
		this->Phone[i] = c.Phone[i];
	}
}

void client::infomation(client& c) {
	c.Arrtime = this->Arrtime;
	c.Id = this->Id;
	c.Kind = this->Kind;
	c.Name = this->Name;
	c.Reqtime = this->Reqtime;
	for (int i = 0; i < 11; i++) {
		c.Phone[i] = this->Phone[i];
	}
}

windows::windows(int number, bool kind) :Number(number), Kind(kind) {}

void windows::conduct(const client& c) {
	Customer = c;
	Available = 1;
}

node::node(const client& c, node* next) :Next(next) {
	C = c;
}

node::node(const client& c) {
	C = c;
}

bool queue::empty() {
	return Tail - Head;
}

void queue::enqueue(const client& c) {
	if (empty()) {
		node newnode(c);
		Head = &newnode;
		Tail = &newnode;
	}
	else {
		node newnode(c, Tail->Next);
		Tail = &newnode;
	}
}

void queue::dequeue(client& c) {
	Head->C.infomation(c);
	node* p = Head;
	Head = Head->Next;
	free(p);
}