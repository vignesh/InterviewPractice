Node  *mergeSortedLinkLists(Node *a, Node*b) {
	Node * result = NULL
	if (!a) {
		return b;
	}
	if (!b) {
		return a;
	}

	if (a->data <= b->data) {
		result = a;
		return mergeSortedLinkedList(a->next, b);
	}
	if (a->data > b->data) {
		result = b;
		return mergeSortedLinkedList(a, b->next);
	}
	return result;
}