/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseLL(ListNode *root)
    {
        ListNode *pre = NULL, *cur = root;
        while (cur != NULL)
        {
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = pre;
            pre = tmp;
        }

        return pre;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *rPre = NULL, *r = NULL, *l = head, *lPre = NULL;

        if (left == 1)
        {
            while (l != NULL && right--)
            {
                lPre = l;
                l = l->next;
            }

            lPre->next = NULL;
            head = reverseLL(head);
            lPre = head;
            while (lPre != NULL && lPre->next != NULL)
            {
                lPre = lPre->next;
            }

            lPre->next = l;
            return head;
        }
        else
        {
            while (l != NULL && --left)
            {
                right--;
                lPre = l;
                l = l->next;
            }

            lPre->next = NULL;

            right++;
            r = l;
            while (r != NULL && --right)
            {
                rPre = r;
                r = r->next;
            }

            if (right)
            {
                lPre->next = reverseLL(l);
            }
            else
            {
                rPre->next = NULL;
                l = reverseLL(l);
                lPre->next = l;

                while (lPre->next != NULL)
                    lPre = lPre->next;

                lPre->next = r;
            }
        }

        return head;
    }
};