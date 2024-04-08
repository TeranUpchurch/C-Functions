
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
      void ListInsertAfter(Node &curNode, Node &newNode);
      void ListRemove(List &list, Node &curNode);

};

void List::ListInsertAfter(Node &curNode, Node &newNode) {
   if (List->head == nullptr) { // List empty
      List->head = newNode;
      List->tail = newNode;
   }
   else if (curNode == List->tail) { // Insert after tail
      List->tail->next = newNode;
      newNode->prev = List->tail;
      List->tail = newNode;
   }
   else {
      Node sucNode = curNode->next;
      newNode->next = sucNode;
      newNode->prev = curNode;
      curNode->next = newNode;
      sucNode->prev = newNode;
   }
}

void List::ListRemove(List &List, Node &curNode) {
   Node sucNode = curNode->next;
   Node predNode = curNode->prev;

   if (sucNode != nullptr) {
      sucNode->prev = predNode;
   }

   if (predNode != nullptr) {
      predNode->next = sucNode;
   }

   if (curNode == List->head) { // Removed head
      List->head = sucNode;
   }

   if (curNode == List->tail) { // Removed tail
      List->tail = predNode;
   }
}

void List::ListTraverse(List &List) {
   curNode = List->head;// Start at head

   while (curNode != nullptr) { 
      cout << curNode.data << " ";       
      curNode = curNode->next;
   }
}

void List::ListInsertionSortDoublyLinked(List &List) {
   Node curNode = List->head->next;
   while (curNode != nullptr) {
      Node nextNode = curNode->next;
      Node searchNode = curNode->prev;
      while (searchNode != nullptr and searchNode->data > curNode->data) {
         searchNode = searchNode->prev;
      }
      // Remove and re-insert curNode
      ListRemove(List, curNode);
      if (searchNode == nullptr) {
         curNode->prev = nullptr;
         ListPrepend(List, curNode);
      }
      else {
         ListInsertAfter(List, searchNode, curNode);
      }
      // Advance to next node
      curNode = nextNode;
   }
}

void List::ListInsertionSortSinglyLinked(List &List) {
    Node prevNode = List->head;
    Node curNode = List->head->next;
    while (curNode != nullptr) {
        next = curNode->next;
        position = ListFindInsertionPosition(List, curNode->data);

        if (position == beforeCurrent) {
            beforeCurrent = curNode;
        }
        else {
            ListRemoveAfter(List, beforeCurrent);
            if (position == nullptr);
                ListPrepend(List, curNode);
            else
                ListInsertAfter(List, position, curNode);
        }

        curNode = curNode->next;
    }
}