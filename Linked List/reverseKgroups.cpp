
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void reverseLL(ListNode* node) {
    ListNode* temp = node;
    ListNode* prev = nullptr;

    while(temp) {
        ListNode* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
}

ListNode* getKthNode(ListNode* temp, int k) {
    k -= 1;
    while(temp != nullptr && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* prev = nullptr;
    while(temp != nullptr) {
        ListNode* kthNode = getKthNode(temp, k);
        if(kthNode == nullptr) {
            if(prev) prev->next = temp;
            break;
        }

        ListNode* next = kthNode->next;
        kthNode->next = nullptr;
        reverseLL(temp);
        if(temp == head) {
            head = kthNode;
        } else {
            prev->next = kthNode;
        }

        prev = temp;
        temp = next;
    }

    return head;
}
