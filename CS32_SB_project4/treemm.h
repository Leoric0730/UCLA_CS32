#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED
#include <queue>
#include <stack>
#include <iostream>
template <typename KeyType, typename ValueType>

class TreeMultimap
{
private:
    struct pair
    {
        KeyType key;
        std::vector<ValueType> val;
//        KeyType getKey() {return key;}
//        ValueType getVal() {return val;}
        pair(const KeyType& okey, const std::vector<ValueType>& ovalue) {
            key = okey; val = ovalue;
        }
    };
    struct node{
        pair data;
        node* left;
        node* right;
        
        pair getPair() {return data;}
        node(pair anyData, node* anyLeft, node* anyRight):data(anyData), left(anyLeft), right(anyRight){}
    };
    node* root;
    
        void insertHelp(const KeyType& key, const ValueType& value, node*& t){
            
            if (t == nullptr) {
                std::vector<ValueType> v;
                v.push_back(value);
                t = new node(pair(key, v), nullptr, nullptr);
            }
            //std::cout << t->data.key << std::endl;
            else if ((t->data).key < key) { insertHelp(key, value, t-> right);}
            else if ((t->data).key > key) { insertHelp(key, value, t-> left);}
            else
                (t->data).val.push_back(value);
            
        }
    
        
    
    
    void makeEmpty(node* t){
        if(t == nullptr) {return;}
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    
public:
    class Iterator
    {
    public:
        Iterator()
        {
            state = false; // Replace this line with correct code.
            index = 0;
        }
        
        Iterator(Iterator& ref){
            nptr = ref.nptr;
            state = ref.state;
            index = ref.index;
        }
        Iterator(node* anyNodePtr, bool anyState, int anyIndex):nptr(anyNodePtr), state(anyState), index(anyIndex){}
        
        ValueType& get_value() const
        {
            
            return (nptr->data).val[index];  // Replace this line with correct code.
            
        }
        
        bool is_valid() const
        {
            return state;  // Replace this line with correct code.
        }
        
        void advance()
        {
            index++;
            if(index == (nptr->data.val.size())){state = false; return;}
        }
        
    private:
       
        
        node* nptr;
        bool state;
        int index;
    };
    
    TreeMultimap()
    {
        root = nullptr;
    }
    
    ~TreeMultimap()
    {
        makeEmpty(root);
        
    }
    
    void insert(const KeyType& key, const ValueType& value)
        {
        insertHelp(key,value,root);
        }
    
    
    Iterator find(const KeyType& key) const
    {
        node* n = root;
        while(n != nullptr){
            if (n -> data.key < key) {n = n -> right;}
            else if (n -> data.key > key) {n = n -> left;}
            //if (n ->data.key == key)
            else
            {
                Iterator x(n,true,0);
                return x;} // Replace this line with correct code.
        }
        Iterator y(nullptr,false,0); return y;
    }
};


#endif // TREEMULTIMAP_INCLUDED
