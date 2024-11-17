#include <iostream>
#include <string>
using namespace std;

class ItemNode {
private:
	string item;
	ItemNode* nextNodeRef;

public:
	// Constructor
	ItemNode();

	// Constructor                                                                                     
	ItemNode(string itemInit);

	// Constructor        
   	ItemNode(string itemInit, ItemNode *nextLoc);

	// Insert node after this node.     
    void InsertAfter(ItemNode &nodeLoc);

	// TODO: Declare the InsertAtEnd() member function that inserts a parameter ItemNode
	//       to the end of the linked list  
    void InsertAtEnd(ItemNode*);


	// Get location pointed by nextNodeRef                                                             
	ItemNode* GetNext();

	// Print data of this node
	void PrintNodeData();

	// Get data of this node
	string GetNodeItem();
};

// Constructor
ItemNode::ItemNode() {
    item = "";
    nextNodeRef = NULL;
}

// Constructor                                                                                     
ItemNode::ItemNode(string itemInit) {
    item = itemInit;
    nextNodeRef = NULL;
}

// Constructor        
ItemNode::ItemNode(string itemInit, ItemNode *nextLoc) {
    item = itemInit;
    nextNodeRef = nextLoc;
}

// Insert node after this node.     
void ItemNode::InsertAfter(ItemNode &nodeLoc) {
    ItemNode* tmpNext;
    
    tmpNext = nextNodeRef;
    nextNodeRef = &nodeLoc;
    nodeLoc.nextNodeRef = tmpNext;
}

// TODO: Define the InsertAtEnd() member function that inserts a parameter ItemNode
//       to the end of the linked list
void ItemNode::InsertAtEnd(ItemNode* currNode) {
    ItemNode* tmpNode;
    
    tmpNode = nextNodeRef;
    nextNodeRef = currNode;
    currNode->nextNodeRef = tmpNode;
}


// Get location pointed by nextNodeRef                                                             
ItemNode* ItemNode::GetNext() {
    return nextNodeRef;
}

// Print data of this node
void ItemNode::PrintNodeData() {
    cout << item << endl;
}

// Get data of this node
string ItemNode::GetNodeItem() {
    return item;
}

int main() {
	ItemNode *headNode;  // Create intNode objects                                                   
	ItemNode *currNode;
	ItemNode *lastNode;

	string item;
	int i;
	int input;

	// Front of nodes list                                                                         
	headNode = new ItemNode();
	lastNode = headNode;

	cin >> input;

	for (i = 0; i < input; i++) {
		cin >> item;
		currNode = new ItemNode(item);
		lastNode->InsertAtEnd(currNode);

		lastNode = currNode;
	}

	// Print linked list                                                                           
	currNode = headNode->GetNext();
	while (currNode != nullptr) {
		currNode->PrintNodeData();
		currNode = currNode->GetNext();
	}
}