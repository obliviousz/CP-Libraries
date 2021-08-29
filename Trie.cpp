struct TrieNode{
    struct TrieNode* children[2];
    bool isEndOfWord;
};
struct TrieNode* getNode()
{
    struct TrieNode* pNode=new TrieNode;
    pNode->isEndOfWord=false;
    for(int i=0;i<2;i++)
    {
        pNode->children[i]=NULL;
    }
    return pNode;
}
void insert(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;
 
    for (int i = 0; i < key.length(); i++) {
        int index=key[i]-'0';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < 2; i++)
        if (root->children[i])
            return false;
    return true;
}
int cnt=0;
void find(struct TrieNode* root,string key)
{
    struct TrieNode* temp=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'0';
        if(!temp->children[index])
        {
            return;
        }
        else
        {
            cnt++;
            temp=temp->children[index];
        }
    }
}
