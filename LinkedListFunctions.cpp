//Go over Linked List Funcitons from class
//Upload to GitHub


class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node() {
            data = 0;
            next = NULL;
            prev = NULL;
        } 
};

class List {
    public:
        Node* head;
        Node* tail;
        List() {
            head = NULL;
            tail = NULL;
        }
};

void ListInsertAfter(List &list, Node &curNode, Node &newNode) {
   if (list->head == NULL) { // List empty
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

void ListRemove(List &list, Node &curNode) {
   Node sucNode = curNode->next;
   Node predNode = curNode->prev;

   if (sucNode is not null) {
      sucNode->prev = predNode;
   }

   if (predNode is not null) {
      predNode->next = sucNode;
   }

   if (curNode == list->head) { // Removed head
      list->head = sucNode;
   }

   if (curNode == list->tail) { // Removed tail
      list->tail = predNode;
   }
}

void ListTraverse(List &list) {
   curNode = list->head // Start at head

   while (curNode is not null) { 
      Print curNode's data        
      curNode = curNode->next
   }
}

void ListInsertionSortDoublyLinked(List &list) {
   Node curNode = list->head->next
   while (curNode != null) {
      Node nextNode = curNode->next
      Node searchNode = curNode->prev
      while (searchNode != null and searchNode->data > curNode->data) {
         searchNode = searchNode->prev
      }
      // Remove and re-insert curNode
      ListRemove(list, curNode)
      if (searchNode == null) {
         curNode->prev = null
         ListPrepend(list, curNode)
      }
      else {
         ListInsertAfter(list, searchNode, curNode)
      }
      // Advance to next node
      curNode = nextNode
   }
}

void ListInsertionSortSinglyLinked(List &list) {
    beforeCurrent = list->head;
    curNode = list->head->next;
    while (curNode != null) {
        next = curNode->next;
        position = ListFindInsertionPosition(list, curNode->data)

        if (position == beforeCurrent) {
            beforeCurrent = curNode;
        }
        else {
            ListRemoveAfter(list, beforeCurrent);
            if (position == null);
                ListPrepend(list, curNode);
            else
                ListInsertAfter(list, position, curNode);
        }

        curNode = curNode->next;
    }
}