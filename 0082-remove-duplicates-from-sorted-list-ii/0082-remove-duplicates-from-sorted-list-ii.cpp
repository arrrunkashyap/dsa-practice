class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head != nullptr) {

            // Skip the entire duplicate group
            while (head->next != nullptr &&
                   head->val == head->next->val) {
                head = head->next;
            }

            // No duplicate: keep this node
            if (prev->next == head) {
                prev = prev->next;
            }
            // Duplicate found: remove the entire group
            else {
                prev->next = head->next;
            }

            head = head->next;
        }

        return dummy.next;
    }
};