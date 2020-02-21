#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};
void printLevelByLevel(TreeNode *root){
    if(root==NULL)
        return;
    cout<<"\nPrint level by level "<<endl;
    queue<TreeNode *> Q;
    TreeNode *t=NULL;
    Q.push(root);
    Q.push(t);
    while(!Q.empty()){
        TreeNode *temp = Q.front();
        Q.pop();
        if(temp){
            cout<<temp->data<<" ";
            if(temp->left){
                Q.push(temp->left);
            }
            if(temp->right){
                Q.push(temp->right);
            }
        }
        else{

            cout<<endl;
            if(!Q.empty()){
                Q.push(t);
            }
        }
    }
}
TreeNode* takeInputLevelWise(){
    queue<TreeNode*> Q;
    TreeNode *root=NULL;
    cout<<"Enter root data ";
    int data;
    cin>>data;
    if(data!=-1){
        root = new TreeNode(data);
        Q.push(root);
        while(!Q.empty()){
            TreeNode* temp = Q.front();
            Q.pop();
            int left,right;
            cout<<"Enter children of "<<temp->data<<" -  ";
            cin>>left>>right;
            if(left!=-1){
                temp->left = new TreeNode(left);
                Q.push(temp->left);
            }
            if(right!=-1){
                temp->right = new TreeNode(right);
                Q.push(temp->right);
            }
        }
    }
    return root;
}
TreeNode* insertInBST(TreeNode *root,int d){
    if(root==NULL){
        TreeNode *t = new TreeNode(d);
        root = t;
        return root;
    }else{
        if(d <= root->data){
            root->left = insertInBST(root->left,d);
        }else{
            root->right = insertInBST(root->right,d);
        }
    }
    return root;
}
TreeNode* takeInput(){
    TreeNode* root = NULL;
    int data;
    cin>>data;

    while(data!=-1){
        root = insertInBST(root,data);
        cin>>data;
    }
    return root;
}
istream& operator>>(istream& is,TreeNode*&root){
    root=takeInput();
    return is;
}
ostream& operator<<(ostream& os,TreeNode* root){
    printLevelByLevel(root);
    return os;
}
TreeNode* search(TreeNode* root,int data){
    if(root == NULL)
        return root;
    if(root->data == data)
        return root;
    else if(root->data > data){
        return search(root->left,data);
    }else
        return search(root->right,data);
}
void printElementInRange(TreeNode *root,int k1,int k2){
    if(root == NULL)
        return;
    ///root lies btw
    if(root->data >=k1 && root->data<=k2){
        cout<<root->data<<" ";
        printElementInRange(root->left,k1,k2);
        printElementInRange(root->right,k1,k2);
    }else if(root->data < k1){
        printElementInRange(root->right,k1,k2);
    }else{
        printElementInRange(root->left,k1,k2);
    }
}
class LL{
public:
    TreeNode *head;
    TreeNode *tail;
};
LL tree2LL(TreeNode *root){
    LL l;
    if(root==NULL){
        l.head = NULL;
        l.tail = NULL;
        return l;
    }
    else if(root->left==NULL && root->right==NULL){
        l.head = root;
        l.tail = root;
    }
    else if(root->left!=NULL && root->right==NULL){
        LL leftLL = tree2LL(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
    }else if(root->right!=NULL && root->left==NULL){
        LL rightLL = tree2LL(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail=rightLL.tail;
    }else{
        LL leftLL = tree2LL(root->left);
        LL rightLL = tree2LL(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
}
pair<TreeNode*,TreeNode*> tree2LLP(TreeNode *root){
    pair<TreeNode*,TreeNode*> l;
    if(root == NULL){
        l.first=NULL;
        l.second=NULL;
        return l;
    }
    else if(root->left==NULL && root->right==NULL){
        l.first=root;
        l.second=root;
    }else if(root->left!=NULL && root->right==NULL){
        pair<TreeNode*,TreeNode*> leftLL = tree2LLP(root->left);
        leftLL.second->right = root;
        l.first = leftLL.first;
        l.second = root;
    }else if(root->left==NULL && root->right!=NULL){
        pair<TreeNode*,TreeNode*> rightLL = tree2LLP(root->right);
        root->right = rightLL.first;
        l.first = root;
        l.second = rightLL.second;
    }else{
        pair<TreeNode*,TreeNode*> rightLL = tree2LLP(root->right);
        pair<TreeNode*,TreeNode*> leftLL = tree2LLP(root->left);

        leftLL.second->right = root;
        root->right = rightLL.first;

        l.first = leftLL.first;
        l.second = rightLL.second;
    }
    return l;
}
pair<TreeNode*,TreeNode*> tree2LLp(TreeNode *root){
    pair<TreeNode*,TreeNode*> l;
    if(root == NULL){
        l.first=NULL;
        l.second=NULL;
        return l;
    }
    else if(root->left==NULL && root->right==NULL){
        l.first=root;
        l.second=root;
        //root->left = NULL;
    }else if(root->left!=NULL && root->right==NULL){
        pair<TreeNode*,TreeNode*> leftLL = tree2LLp(root->left);
        leftLL.second->right = root;
        //root->left=NULL;
        l.first = leftLL.first;
        l.second = root;
    }else if(root->left==NULL && root->right!=NULL){
        pair<TreeNode*,TreeNode*> rightLL = tree2LLp(root->right);
        root->right = rightLL.first;
        l.first = root;
        //root->left =NULL;
        l.second = rightLL.second;
    }else{
        pair<TreeNode*,TreeNode*> rightLL = tree2LLp(root->right);
        pair<TreeNode*,TreeNode*> leftLL = tree2LLp(root->left);

        leftLL.second->right = root;
        root->right = rightLL.first;
        //root->left = NULL;
        l.first = leftLL.first;
        l.second = rightLL.second;
    }
    return l;
}
LL BSTtoDLL(TreeNode *root){
    LL l;
    if(root == NULL){
        l.head = NULL;
        l.tail = NULL;
        return l;
    }
    else if(root->left ==NULL && root->right == NULL){
        l.head = root;
        l.tail = root;
        l.head->left = NULL;
        l.tail->right = NULL;
    }else if(root->left != NULL && root->right == NULL){
        LL leftLL = BSTtoDLL(root->left);
        leftLL.tail->right = root;
        root->left = leftLL.tail;
        root->right=NULL;
        l.head = leftLL.head;
        l.tail = root;
    }else if(root->left==NULL && root->right!=NULL){
        LL rightLL = BSTtoDLL(root->right);
        root->right = rightLL.head;
        rightLL.head->left = root;
        root->left = NULL;

        l.head = root;
        l.tail = rightLL.tail;
    }else{
        LL leftLL = BSTtoDLL(root->left);
        LL rightLL = BSTtoDLL(root->right);

        leftLL.tail->right = root;
        root->left = leftLL.tail;

        root->right = rightLL.head;
        rightLL.head->left = root;
    }
    return l;
}
///https://aonecode.com/getArticle/202
int main(){
    TreeNode *root = NULL;
    cin>>root;
    cout<<root;
    ///8 6 9 6 5 7 11 10 -1
    //8 10 14 13 3 1 6 4 7 -1
    //printElementInRange(root,1,4);
    LL myList = tree2LL(root);
    TreeNode *temp1 = myList.head;
    TreeNode *temp2 = myList.tail;
    //printLevelByLevel(temp1);
    cout<<"Linked List in Sorted Order "<<endl;
    while(temp1!=NULL){
        cout<<temp1->data<<"-->";
        temp1 = temp1->right;
    }
    cout<<"\nLinked List in reverse Sorted Order "<<endl;
    while(temp2!=NULL){
        cout<<temp2->data<<"-->";
        temp2 = temp2->left;
    }
    /*
    cout<<"\nEnter linked list again "<<endl;
    TreeNode *r = NULL;
    cin>>r;
    cout<<r;
    cout<<"\n Linked list via pair"<<endl;
    pair<TreeNode*,TreeNode*> t = tree2LLp(r);
    TreeNode* h = t.first;
    printLevelByLevel(h);

    while(h!=NULL){
        h->left=NULL;
        cout<<h->data<<"-->";
        h=h->right;
    }
    */
    return 0;
}
