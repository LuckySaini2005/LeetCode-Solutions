class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* lef = head;

        for (int i = 1; i < left - 1; i++) {
            lef = lef->next;
        }

        ListNode* rig = head;

        for (int i = 0; i < right; i++) {
            rig = rig->next;
        }

        ListNode* temp = head;

        for (int i = 0; i < right - 1; i++) {
            temp = temp->next;
        }

        temp->next = NULL;

        ListNode* rev;

        if (left == 1) {
            rev = reverseList(lef);
            head = rev;
        }
        else {
            rev = reverseList(lef->next);
            lef->next = rev;
        }

        
        ListNode* last = rev;

        while (last->next != NULL) {
            last = last->next;
        }

        last->next = rig;

        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna