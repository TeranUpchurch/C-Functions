
// Doubly Linked List Funcitons C++
// Very Errory, needs lots of fixes


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
      void ListPrepend(Node *newNode);
      void ListInsertAfter(Node *curNode, Node *newNode);
      void ListRemove(Node *curNode);
      void ListTraverse();
      void ListInsertionSortDoublyLinked();
      void ListInsertionSortSinglyLinked();
};

void List::ListPrepend(Node *newNode) {
   if (head == nullptr) {

   }
   else {
      
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

void List::ListRemove(Node *curNode) {
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

void List::ListTraverse() {
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
      List::ListRemove(curNode);
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
}

void List::ListInsertionSortSinglyLinked() {
   Node *prevNode = head;
   Node *curNode = head->next;
   while (curNode != nullptr) {
      curNode = curNode->next;
      position = ListFindInsertionPosition(List, curNode->data);

      if (position == beforeCurrent) {
         beforeCurrent = curNode;
      }
      else {
         ListRemoveAfter(beforeCurrent);
         if (position == nullptr) {
            ListPrepend(curNode);
         }
         else {
            ListInsertAfter(position, curNode);
         }
      } 
        curNode = curNode->next;
    }
}