//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
void parentMap(Node* root,unordered_map<Node*,Node*>& mp){
    if(!root) return;
    if(root->left) mp[root->left] = root;
    if(root->right) mp[root->right] = root;
    parentMap(root->left,mp);
    parentMap(root->right,mp);
}

int anc(Node* node, Node* root,int k, unordered_map<Node*,Node*>& mp){
    if(!k) return node->data;
    if(node==root){
        if(k>=1) return -1;
        return root->data;
    }
    return anc(mp[node],root,k-1,mp);
}

Node* temp;

void search(Node* dummy,int node){
    if(!dummy) return;
    if(dummy->data==node) {
        temp = dummy;
        return;
    }
    search(dummy->left,node);
    search(dummy->right,node);
}

int kthAncestor(Node *root, int k, int node)
{
    unordered_map<Node*,Node*> mp;
    parentMap(root,mp);
    Node* dummy = root;
    search(dummy,node);
   // if(!anc(temp,root,k,mp)) return -1;
    return anc(temp,root,k,mp);
    
}
