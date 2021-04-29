//LinkLst.h
#ifndef _LINKLST_H_DEFINED

//*********************************************
//*********************************************
template <class T>
class LinkList
{
	public:
	struct ListNode
	{
		T DataItem;
		ListNode *Next;
		ListNode *Prev;
		DWORD UniqueID;
		DWORD DataItemGrossStorageSize;
	};


	LinkList()
	{
		pHead=0;
		pTail=0;
		NodeCount=0;
		DeleteDataItems=TRUE;
		UniqueIDCount=0;
		TotalGrossDataStorageBytes=0; //sum of all data items held by queue
	}
//	~LinkList() {printf("destructor invoked\n"); Release();}
	//------------------------------------------------------
	~LinkList()
	{
//		printf("destructor invoked\n");
		ReleaseAll();
	}
	//------------------------------------------------------
	void Prepend(T DataItem, DWORD DataItemGrossStorageSize)
	{
		Prepend(DataItem);
		pHead->DataItemGrossStorageSize=DataItemGrossStorageSize;
		TotalGrossDataStorageBytes+=DataItemGrossStorageSize; //sum of all data items held by queue
	}
	//------------------------------------------------------
	void DisableDataItemDelete(void)
	{
		DeleteDataItems=FALSE;
	}
	//------------------------------------------------------
	void IteratorReset(void)
	{
		pIteratorCurrent = pHead;
		pIteratorPrev=0;
		IteratorCurrentPos=0;
	}
	//------------------------------------------------------
	BOOL IteratorNext(T* RetDataItem)
	{
		if(IteratorCurrentPos<NodeCount)
		{
			if(RetDataItem)
				*RetDataItem = pIteratorCurrent->DataItem;
			pIteratorPrev=pIteratorCurrent;
			pIteratorCurrent = pIteratorCurrent->Next;
			IteratorCurrentPos++;
			return(TRUE);
		}
		else
		{
			return(FALSE);
		}
	}
	//------------------------------------------------------
	void IteratorDeleteReturnedNode(void)
	{
		ListNode* PrevNode;
		ListNode* NextNode;
		int NodeToDeletePos;

		if(!NodeCount)
			return;

		NodeToDeletePos=IteratorCurrentPos-1;//IteratorNext() advanced 1 beyond returned value, back up one

		if(NodeToDeletePos<0)
			return;

		if(!NodeToDeletePos)//Delete first node , must modify head ptr
		{
			//will delete current head (node 0), pIteratorCurrent=Node 1 , set head to node 1
			CppDeleteListNodePtr(pHead);

			pHead=pIteratorCurrent;
			if(NodeCount<=1)
				pTail=pHead;	//update tail pointer - only one item in list

			//special - back up one so IteratorNext() comes back to point to next element after deletion point
			//0 1 2 3 -> 1 2 3   Original List Nodes
			//^          (NULL)  pIteratorPrev (deletion point pointer)  set to NULL since invalid to point above top of list
			//  ^        ^    pIteratorCurrent (pointer to node)
			//  ^(1)     ^(0)  List index position 
			//Therefore:
			//Leave Current Pointer alone (pIteratorCurrent) still want to point to List item 1;
			pIteratorPrev=0; //SET TO INVALID since cant point above list top
			IteratorCurrentPos--; //set list position index back one (1)->(0)
		}
		else
		{
			if(NodeToDeletePos==NodeCount-1)
			{
				//deleting tail link, perform no link updates
				//:::::NOOP
				
				//set PrevNode to item 1
				PrevNode=pIteratorPrev;//added 1-15-00 wasn't initialized

				//delete the node and data
				CppDeleteListNodePtr(pIteratorPrev);


				//special - back up one so IteratorNext() comes back to point to next element after deletion point
				//0 1 2 (NULL) -> 0 1 (NULL)  Original List Nodes
				//    ^             ^        pIteratorPrev (deletion point pointer)
				//      ^              ^     pIteratorCurrent (pointer to node)
				//      ^(3)           ^(2)  List index position 
				//Therefore:

				//Leave Current Pointer alone (pIteratorCurrent) still want to point NULL list item
				pIteratorPrev=PrevNode; //SET the new current ptr to point to prev List node (0)
				pTail=PrevNode;	//update tail pointer since there is a new tail node
				IteratorCurrentPos--; //set list position index back one (2)->(1)
			}
			else
			{
				//not the first, and not the last so there is a prev and next
				PrevNode=pIteratorPrev->Prev;
				NextNode=pIteratorPrev->Next;
				//link prev to next
				PrevNode->Next=NextNode;
				//link next to prev
				NextNode->Prev=PrevNode;
			
				//delete the node and data
				CppDeleteListNodePtr(pIteratorPrev);

				//special - back up one so IteratorNext() comes back to point to next element after deletion point
				//0 1 2 3 -> 0 2 3   Original List Nodes
				//  ^        ^       pIteratorPrev (deletion point pointer)
				//    ^        ^     pIteratorCurrent (pointer to node)
				//    ^(2)     ^(1)  List index position 
				//Therefore:

				//Leave Current Pointer alone (pIteratorCurrent) still want to point to List item 2;
				pIteratorPrev=PrevNode; //SET the new current ptr to point to prev List node (0)
				//list head and tail pointers stay the same
				
				IteratorCurrentPos--; //set list position index back one (2)->(1)
			}
		}
	}		
	//------------------------------------------------------
	void DeleteTailNode(void)
	{
		//set up iterator starting params so iterator can be used to perform operation
		if(NodeCount)
		{
			IteratorCurrentPos=NodeCount;
			pIteratorPrev=pTail;
			pIteratorCurrent=pTail->Next;
			//update the tail
			pTail=pTail->Prev;
			//delete the node and data
			CppDeleteListNodePtr(pIteratorPrev);
		}
	}
	//------------------------------------------------------
	//function can be used to move a node to the head position to keep the list in most-recently-accessed order
	void IteratorSendReturnedNodeToHead(void)
	{
		ListNode* PrevNode;
		ListNode* NextNode;
		int NodeToDeletePos;

		if(!NodeCount)
			return;

		NodeToDeletePos=IteratorCurrentPos-1;//IteratorNext() advanced 1 beyond returned value, back up one

		if(NodeToDeletePos<0)
			return;

		if(!NodeToDeletePos)//Delete first node , must modify head ptr
		{
			//Node is already at head, no-op
		}
		else
		{
			if(NodeToDeletePos==NodeCount-1)
			{
				//moving tail link to head

				//remember original prev
				PrevNode=pIteratorPrev->Prev;

				//set forward link from new head to prev head
				pIteratorPrev->Next = pHead;
				//set reverse link from old head to new head
				pHead->Prev = pIteratorPrev;

				//0 1 2 (NULL) -> 2 0 1 (NULL)  Original List Nodes
				//    ^               ^       pIteratorPrev (deletion point pointer)
				//      ^               ^     pIteratorCurrent (pointer to node)
				//      ^(3)            ^(3)  List index position 

				pHead=pIteratorPrev;
				pTail=PrevNode;	//update tail pointer since there is a new tail node
				pIteratorPrev = pTail->Prev;
			}
			else
			{
				//not the first, and not the last so there is a prev and next
				PrevNode=pIteratorPrev->Prev;
				NextNode=pIteratorPrev->Next;

				//link prev to next
				PrevNode->Next=NextNode;
				//link next to prev
				NextNode->Prev=PrevNode;
			
				//move the specified node to new head
				//set forward link from new head to prev head
				pIteratorPrev->Next = pHead;
				//set reverse link from old head to new head
				pHead->Prev = pIteratorPrev;

				//special - back up one so IteratorNext() comes back to point to next element after deletion point
				//0 1 2 3 -> 1 0 2 3   Original List Nodes
				//  ^          ^       pIteratorPrev (deletion point pointer)
				//    ^          ^     pIteratorCurrent (pointer to node)
				//    ^(2)       ^(2)  List index position 
				//Therefore:
				pHead=pIteratorPrev; //new head is the transplanted node
				pIteratorPrev=PrevNode; //SET the new current ptr to point to prev List node (0)
			
			}
		}
	}		
	//------------------------------------------------------
	void Print(FILE* filehandle) //object is unchanged
	{
#if _DEBUG
		ListNode* temp=pHead;
		int LoopCount=0;	
		fprintf(filehandle,"\n PrintList\n");
		IteratorReset();
		if(NodeCount)
		{
			while(IteratorNext(NULL))
			{
				fprintf(filehandle,"Pos %d  NodeID %d",IteratorCurrentPos-1,pIteratorPrev->UniqueID);
				if(pIteratorPrev==pTail)
					fprintf(filehandle," (TAIL NODE %x %x)",pIteratorPrev,pTail);
				fprintf(filehandle,"\n");
				LoopCount++;
			}
		}
		else
				fprintf(filehandle,"<EMPTY LIST>\n");
/*		while(temp!=0)
		{
			printf("%c[%x] ->",temp->DataItem,temp->Next);
			temp=temp->Next;
		}
		printf("\n###\n");
*/
#endif
	}

	//------------------------------------------------------
	void ReleaseAll(void)
	{
		ListNode* temp;
		int nodes_deleted=0;		
		while(NodeCount>0)
		{
			temp=pHead;
			//Delete the current node
//			printf("Delete head node preCount %d Head->next=%x\n",NodeCount,pHead->Next);
			pHead=pHead->Next;
			CppDeleteListNodePtr(temp);

			nodes_deleted++;
		}
		pHead=0;
		pTail=0;
//		printf("ReleaseAll DeletedCount %d CurrentCount=%d\n",nodes_deleted,NodeCount);
	}
	//------------------------------------------------------
	void CppDeleteListNodePtr(ListNode* pNode)
	{
		//first delete any data (i.e. class) items
		if(DeleteDataItems)
		{
			TotalGrossDataStorageBytes -= pNode->DataItemGrossStorageSize; //rough size of any held resource held by node (i.e. GfxBuf)

			delete pNode->DataItem; //delete the data contained in list node
		}
		delete pNode; //delete the node ptr
		NodeCount--;
	}
	//------------------------------------------------------
	void GetHoldingStats(int *ItemCount, DWORD *DataHoldingSize)
	{
		*ItemCount=NodeCount;
		*DataHoldingSize=TotalGrossDataStorageBytes; //sum of all data items held by queue
	}
	//------------------------------------------------------
	private:
		ListNode* pHead;
		ListNode* pTail;
		ListNode* pIteratorCurrent;
		ListNode* pIteratorPrev;
		int IteratorCurrentPos;
		int NodeCount;
		DWORD UniqueIDCount;
		BOOL DeleteDataItems; //flag for list class to delete data (class) items
		DWORD TotalGrossDataStorageBytes; //sum of all data items held by queue


	//Private FN ------------------------------------------
	void Prepend(T DataItem)
	{
		ListNode* NewNode = new ListNode;
		ListNode* NextNode;
		NewNode->Next=pHead; //link to list
		NewNode->DataItem=DataItem;
		//set up reverse link if a node follows
		if(NodeCount)
		{
			NextNode=pHead;
			NextNode->Prev=NewNode;
		}
		pHead=NewNode; //update head of list
		NodeCount++;
		NewNode->DataItem->UniqueID=UniqueIDCount;
		NewNode->UniqueID=UniqueIDCount;
		UniqueIDCount++;
		if(NodeCount==1)
			pTail=NewNode;
		pHead->DataItemGrossStorageSize=0; //default
	}


};

/*
void main(void)
{
char *c[40];
//char c[40];
char *PeekDataPtr;
int i;
	for(i=0;i<8;i++)
	{
		c[i]=new char;
		*c[i]=(char)('A'+i);
	}	

	LinkList<char *> w(TRUE);

	w.Prepend(c[0]);
	w.Prepend(c[1]);
	w.Prepend(c[2]);
	w.Prepend(c[3]);
	w.Prepend(c[4]);
	w.Print();


	w.IteratorReset();
	while(w.IteratorNext(&PeekDataPtr))
	{
		printf("IteratorNext Data='%c'\n",*PeekDataPtr);
	}


	w.ReleaseAll();
	w.Prepend(c[5]);
	w.Prepend(c[6]);
	w.Print();

}
*/
/*

void main(void)
{
char c;
	LinkList<char> w;
	w.Prepend('A');
	w.Prepend('B');
	w.Prepend('C');
	w.Prepend('D');
	w.Print();


	w.IteratorReset();
	while(w.IteratorNext(&c))
	{
		printf("IteratorNext='%c'\n",c);
	}

	w.RemoveDataItemFromList('C');
	w.Print();
	w.RemoveDataItemFromList('A');
	w.Print();
	w.RemoveDataItemFromList('D');
	w.Print();

	w.ReleaseAll();
	w.Prepend('Z');
	w.Prepend('Y');
	w.Print();

	printf("Exiting inner block\n");
}
*/
//*********************************************
//*********************************************
//*********************************************
//*********************************************
//*********************************************
//*********************************************
//*********************************************
//*********************************************
//*********************************************
//*********************************************
//*********************************************
//*********************************************
#else
#endif