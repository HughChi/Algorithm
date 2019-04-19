//链表末尾插入
struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
}
void AddToTail(ListNode** pHead,int value){
	ListNode* pNew=new ListNode();
	pNew->m_nValue=value;
	pNew->m_pNext=nullptr;

	if(*pHead==nullptr){
		*pHead=pNew;
	}
	else{
		ListNode* pNode=*pHead;
		while(pNode->m_pNext!=nullptr){
			pNode=pNode->m_pNext;
		}
		pNode->m_pNext=pNew;
	}

}
//删除节点
void RemoveNode(ListNode** pHead,int value){
	if(*pHead==nullptr||pHead==nullptr){
		return;
	}
	ListNode* pToBeDeleted=nullptr;
	if((*pHead)->m_pNext==value){
		pToBeDeleted=*pHead;
		*pHead=(*pHead)->m_pNext;
	}
	else{
		ListNode* pNode=*pHead;
		while(pNode->m_pNext!=nullptr && pNode->m_pNext->m_nValue!=value){
			pNode=pNode->m_pNext;
		}
		if(pNode->m_pNext!=nullptr && pNode->m_pNext->m_nValue==value){
			pToBeDeleted=pNode->m_pNext;
			pNode->m_pNext=pNode->m_pNext->m_pNext;
		}
	}
	if(pToBeDeleted!=nullptr){
		delete pToBeDeleted;
		pToBeDeleted=nullptr;
	}
}
//从尾到头打印链表
void PrintListReversingly_Iteratively(ListNode* pHead){
	std::stack<ListNode*> nodes;
	ListNode* pNode=pHead;
	while(pNode!=nullptr){
		nodes.push(pNode);
		pNode=pNode->m_pNext;
	}
	while(!nodes.empty()){
		pNode=nodes.top();
		printf("%d ",pNode->m_nValue);
		nodes.pop();
	}
}

//翻转链表
ListNode* ReverseList(ListNode* pHead){
	ListNode* pReversedHead=nullptr;
	ListNode* pNode=pHead;
	ListNode* pPrev=nullptr;
	while(pNode!=nullptr){
		ListNode* pNext=pNode->m_pNext;
		if(pNext==nullptr){
			pReversedHead=pNode;
		}
		pNode->m_pNext=pPrev;
		pPrev=pNode;
		pNode=pNext;
	}
	return pReversedHead;
}