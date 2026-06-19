    class LRUCache {
    private:
        class Node {
        public:
            int key, val;
            Node* next;
            Node* prev;

            Node(int _key, int _val) {
                key = _key;
                val = _val;

                next = nullptr;
                prev = nullptr;
            }
        };

        void addNode(Node* newNode) {
            Node* temp = head->next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
        }

        void deleteNode(Node* delNode) {
            Node* delPrev = delNode->prev;
            Node* delNext = delNode->next;
            delPrev->next = delNext;
            delNext->prev = delPrev;
        }

        int cap;
        Node *head{new Node(-1, -1)}, *tail{new Node(-1, -1)};
        unordered_map<int, Node*> m;

    public:
        LRUCache(int capacity) {
            cap = capacity;
            head->next = tail;
            tail->prev = head;
        }

        ~LRUCache() {
            Node* curr = head;
            while (curr != nullptr) {
                Node* nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
        }

        int get(int key_) {
            if (m.find(key_) != m.end()) {
                Node* resNode{m[key_]};
                deleteNode(resNode);
                addNode(resNode);
                return resNode->val;
            }
            return -1;
        }

        void put(int key_, int value) {
            if (m.find(key_) != m.end()) {
                Node* existingNode = m[key_];
                existingNode->val = value;
                deleteNode(existingNode);
                addNode(existingNode);
                return;
            }

            if (m.size() == cap) {
                Node* lruNode = tail->prev;
                m.erase(lruNode->key);
                deleteNode(lruNode);
                delete lruNode;
            }

            Node* newNode = new Node(key_, value);
            addNode(newNode);
            m[key_] = newNode;
        }
    };