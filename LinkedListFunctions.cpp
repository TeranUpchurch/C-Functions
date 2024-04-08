
// Doubly Linked List Funcitons
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
};

void List::List::ListInsertAfter(Node &curNode, Node &newNode) {
   if (list->head == nullptr) { // List empty
      list->head = newNode;
      list->tail = newNode;
   }
   else if (curNode == list->tail) { // Insert after tail
      list->tail->next = newNode;
      newNode->prev = list->tail;
      list->tail = newNode;
   }
   else {
      Node sucNode = curNode->next;
      newNode->next = sucNode;
      newNode->prev = curNode;
      curNode->next = newNode;
      sucNode->prev = newNode;
   }
}

void List::ListRemove(List &list, Node &curNode) {
   Node sucNode = curNode->next;
   Node predNode = curNode->prev;

   if (sucNode != nullptr) {
      sucNode->prev = predNode;
   }

   if (predNode != nullptr) {
      predNode->next = sucNode;
   }

   if (curNode == list->head) { // Removed head
      list->head = sucNode;
   }

   if (curNode == list->tail) { // Removed tail
      list->tail = predNode;
   }
}

void List::ListTraverse(List &list) {
   curNode = list->head;// Start at head

   while (curNode != nullptr) { 
      cout << curNode.data << " ";       
      curNode = curNode->next;
   }
}

void List::ListInsertionSortDoublyLinked(List &list) {
   Node curNode = list->head->next;
   while (curNode != nullptr) {
      Node nextNode = curNode->next;
      Node searchNode = curNode->prev;
      while (searchNode != nullptr and searchNode->data > curNode->data) {
         searchNode = searchNode->prev;
      }
      // Remove and re-insert curNode
      ListRemove(list, curNode);
      if (searchNode == nullptr) {
         curNode->prev = nullptr;
         ListPrepend(list, curNode);
      }
      else {
         ListInsertAfter(list, searchNode, curNode);
      }
      // Advance to next node
      curNode = nextNode;
   }
}

void List::ListInsertionSortSinglyLinked(List &list) {
    Node prevNode = list->head;
    Node curNode = list->head->next;
    while (curNode != nullptr) {
        next = curNode->next;
        position = ListFindInsertionPosition(list, curNode->data);

        if (position == beforeCurrent) {
            beforeCurrent = curNode;
        }
        else {
            ListRemoveAfter(list, beforeCurrent);
            if (position == nullptr);
                ListPrepend(list, curNode);
            else
                ListInsertAfter(list, position, curNode);
        }

        curNode = curNode->next;
    }
}