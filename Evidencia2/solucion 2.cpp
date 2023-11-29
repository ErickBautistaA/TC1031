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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(); 
        // Cabeza ficticia para facilitar el manejo de la lista
        ListNode* current = dummyHead;
        // carry es una variable que almacena el digito que se lleva al siguiente nodo.
        int carry = 0;
        /*
        Este ciclo recorre las listas mientras alguna tenga elementos.
        x se inicializa con el valor actual de l1
        y se inicializa con el valor actual de l2
        */
        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;

            //crea los nodos para poner valores del residuo de la suma
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        /* 
        si carry queda con un valor mayor a 0 despues del bucle
        se crea un nuevo nodo con el valor y se agrega a la lista.
        */
        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        return dummyHead->next; // La verdadera cabeza de la lista
    }
};