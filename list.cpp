


class Node{
    public:
        Node* next;
        Node* prev;
        Node():next(NULL), prev(NULL)
        {

        }
};

class List{
    public:
        List():head(NULL),tail(NULL)
        {

        }

        void push_back(Node* node){
            if(node != NULL){
                if(tail != NULL){
                    tail -> next = node;
                    node -> prev = tail;
                    node -> next = NULL;
                    tail = node;
                }
                else{
                    head = node;
                    node -> prev = tail;
                    node -> next = NULL;
                    tail = node;
                }
            }
        }

        void remove(Node* node){
            if(node == NULL)
                return;
            Node* cur = head;    
            while(cur != NULL){
                if(cur == node){
                    if(cur -> next != NULL && cur -> prev != NULL){
                        Node* tmpPrev = cur -> prev;
                        Node* tmpNext = cur -> next;
                        tmpPrev -> next = tmpNext;
                        tmpNext -> prev = tmpPrev;
                    }
                    else if(cur -> next != NULL){
                        head = cur -> next;
                        head -> prev = NULL;
                    }
                    else if(cur -> prev != NULL){
                        tail = cur -> prev;
                        tail -> next = NULL;
                    }
                    else{
                        head = NULL;
                        tail = NULL;
                    }
                    cur -> next = NULL;
                    cur -> prev = NULL;
                    break;
                }
                cur = cur -> next;
            }
        }
    private:
        Node* head;
        Node* tail;
};

