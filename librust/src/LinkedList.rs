/*
 * ETIB PROJECT, 2023
 * LinkedLIst implementation in rust
 * File description:
 * Implementation of a linked list in rust
 */
extern crate va_list;
use va_list::VaList;

type constructor_t<T> = fn(VaList) -> T;
type destructor_t<T> = fn(T);

struct Node<T> {
    pub data: T,
    pub next: Option<Box<Node<T>>>,
    pub prev: Option<Box<Node<T>>>,
}

pub struct LinkedList<T> {
    pub head: Option<Box<Node<T>>>,
    pub tail: Option<Box<Node<T>>>,
    pub n_elem: usize,
    pub constructor: fn(VaList) -> T,
    pub destructor: fn(T),
}

pub impl Node<T> {
    pub fn new(data: T) -> Node<T> {
        Node {
            data: data,
            next: None,
            prev: None,
        }
    }

    pub fn getData(&self) -> T {
        self.data
    }

    pub fn getNext(&self) -> Option<Box<Node<T>>> {
        self.next
    }

    pub fn getPrev(&self) -> Option<Box<Node<T>>> {
        self.prev
    }

    pub fn setData(&mut self, data: T) {
        self.data = data;
    }

    pub fn setNext(&mut self, next: Option<Box<Node<T>>>) {
        self.next = next;
    }

    pub fn setPrev(&mut self, prev: Option<Box<Node<T>>>) {
        self.prev = prev;
    }

    pub fn pushFrontNode(&mut self, constructor: constructor_t<T>, args: VaList) {
    }

    pub fn pushBackNode(&mut self, constructor: constructor_t<T>, args: VaList) {
    }

    pub fn destroyNode(&mut self, destructor: destructor_t<T>) {
    }
}

pub impl LinkedList<T> {
    pub fn new(constructor: constructor_t<T>, destructor: destructor_t<T>) -> LinkedList<T> {
        LinkedList {
            head: None,
            tail: None,
            n_elem: 0,
            constructor: constructor,
            destructor: destructor,
        }
    }

    pub fn getHead(&self) -> Option<Box<Node<T>>> {
        self.head
    }

    pub fn getTail(&self) -> Option<Box<Node<T>>> {
        self.tail
    }

    pub fn getN_elem(&self) -> usize {
        self.n_elem
    }

    pub fn setHead(&mut self, head: Option<Box<Node<T>>>) {
        self.head = head;
    }

    pub fn setTail(&mut self, tail: Option<Box<Node<T>>>) {
        self.tail = tail;
    }

    pub fn setN_elem(&mut self, n_elem: usize) {
        self.n_elem = n_elem;
    }

    pub fn updateN_elem(&mut self, n_elem: usize) {
        self.n_elem += n_elem;
    }

    pub fn pushFrontList(&mut self, args: VaList) {
    }

    pub fn pushBackList(&mut self, args: VaList) {
    }

    pub fn destroyList(&mut self) {
    }
}
