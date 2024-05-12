
// Doubly Linked List Funcitons C++
// Not all, only a few only more doubly linked lists

class Node {
   public:
      int data;
      Node* next;
      Node* prev;
      Node() {
         data = 0;
         next = nullptr;
         prev = nullptr;
      } 
};

class List {
   public:
      Node* head;
      Node* tail;
      List() {
         head = nullptr;
         tail = nullptr;
         }
      void ListAppend(Node *newNode);
      void ListPrepend(Node *newNode);
      void ListInsertAfter(Node *curNode, Node *newNode);
      void ListRemoveAfter(Node *curNode);
      Node *ListPeekFront();
      Node *ListPeekBack();
      Node *ListPopFront();
      Node *ListPopBack();
      void ListTraversePrint();
      void ListInsertionSortDoublyLinked();
};

void List::ListAppend(Node *newNode) {
   if (head == nullptr) {
      head = newNode;
      tail = newNode;
   }
   else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
   }
}

void List::ListPrepend(Node *newNode) {
   if (head == nullptr) {
      head = newNode;
      tail = newNode;
   }
   else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
   }
}

void List::ListInsertAfter(Node *curNode, Node *newNode) {
   if (head == nullptr) { // List empty
      head = newNode;
      tail = newNode;
   }
   else if (curNode == tail) { // Insert after tail
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
   }
   else {
      Node *sucNode = curNode->next;
      newNode->next = sucNode;
      newNode->prev = curNode;
      curNode->next = newNode;
      sucNode->prev = newNode;
   }
}

void List::ListRemoveAfter(Node *curNode) {
   Node *sucNode = curNode->next;
   Node *predNode = curNode->prev;

   if (sucNode != nullptr) {
      sucNode->prev = predNode;
   }

   if (predNode != nullptr) {
      predNode->next = sucNode;
   }

   if (curNode == head) { // Removed head
      head = sucNode;
   }

   if (curNode == tail) { // Removed tail
      tail = predNode;
   }
}

Node *List::ListPeekFront() {
   return head;
}

Node *List::ListPeekBack() {
   return tail;
}

Node *List::ListPopFront() {


}

Node *List::ListPopBack() {


}

void List::ListTraversePrint() {
   Node *curNode = head;// Start at head

   while (curNode != nullptr) { 
      // cout << curNode->data << " ";
      // or use print info function if defined     
      curNode = curNode->next;
   }
}

void List::ListInsertionSortDoublyLinked() {
   Node *curNode = head->next;
   while (curNode != nullptr) {
      Node *nextNode = curNode->next;
      Node *searchNode = curNode->prev;
      while (searchNode != nullptr and searchNode->data > curNode->data) {
         searchNode = searchNode->prev;
      }
      // Remove and re-insert curNode
      List::ListRemoveAfter(curNode);
      if (searchNode == nullptr) {
         curNode->prev = nullptr;
         ListPrepend(curNode);
      }
      else {
         ListInsertAfter(searchNode, curNode);
      }
      // Advance to next node
      curNode = nextNode;
   }
};