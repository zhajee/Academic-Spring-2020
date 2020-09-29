//HashMap.cpp

#include "HashMap.hpp"
#include <string>

//hashFunction
namespace 
{
    unsigned int hashf(const std::string k)
    {
        unsigned int sum = 0;
        for (int i = 0; i < k.size(); i++)
        {
            int position = 1;
            sum += position*int(k[i]);
            position++;
        }
        return sum;
    }
}

void HashMap::arrayCopy(Node** target, Node** source, unsigned int size)
{
    for (int i = 0; i < size; i++) 
    {
        if (source[i] != nullptr)
        {
            Node* newNode = new Node();
            *(newNode) = *(source[i]);
            target[i] = newNode;
        }
        else 
        {
            target[i] = nullptr;
        }
    }
}

// //deletes the linked list
void HashMap::deleteNodes(Node* n)
{
    if (n == nullptr)
    {
    }
    else if (n->next == nullptr)
    {
        delete n;
    }
    else
    {
        Node* current = n->next;
        delete n;
        deleteNodes(current);
    }

}

//constructor
HashMap::HashMap()
    : sz{0}, bucketNum{INITIAL_BUCKET_COUNT}, nodeArray{new Node*[bucketNum]}, hashFunction{hashf}
{
    initializeNullArray(nodeArray, bucketNum);
}

HashMap::HashMap(HashFunction hashFunction) //initialize with hashFunction
    : sz{0}, bucketNum{INITIAL_BUCKET_COUNT}, nodeArray{new Node*[bucketNum]}, hashFunction{hashFunction}
{
}

//big three
//copy constructor
HashMap::HashMap(const HashMap& hm) 
    : sz{hm.sz}, bucketNum{hm.bucketNum}, nodeArray{new Node*[hm.bucketNum]}, hashFunction{hm.hashFunction}
{
    arrayCopy(nodeArray, hm.nodeArray, bucketNum);
}

//destructor
HashMap::~HashMap() 
{
    //for loop, function to delete linked lists
    for (int i = 0; i < bucketNum; i++)
    {
        deleteNodes(nodeArray[i]);
    }
    delete[] nodeArray;
}

HashMap& HashMap::operator=(const HashMap& hm)
{
    if (this != &hm)
    {
        //creates new node array, initializes it, and copies the old one into it
        Node** newNodeArray = new Node*[hm.bucketNum];
        initializeNullArray(newNodeArray, hm.bucketNum);
        arrayCopy(newNodeArray, hm.nodeArray, hm.bucketNum);

        sz = hm.sz;
        bucketNum = hm.bucketNum;

        //for loop, function to delete linked lists
        for (int i = 0; i < bucketNum; i++)
        {
            deleteNodes(nodeArray[i]);
        }
        delete[] nodeArray;
        nodeArray = newNodeArray;
    }
    return *this;
}

unsigned int HashMap::getIndex(const std::string key) const
{
    unsigned int pos = hashFunction(key);
    int index = pos%bucketNum;
    return index;
}

void HashMap::initializeNullArray(Node** nodeArray, int bucketNum) 
{
    for (int i = 0; i < bucketNum; i++)
    {
        nodeArray[i] = nullptr;
    }
}

unsigned int HashMap::bucketCount() const
{
    return bucketNum;
}

unsigned int HashMap::size() const
{
    return sz;
}

double HashMap::loadFactor() const
{
    return (double)sz/bucketNum;
}

unsigned int HashMap::maxBucketSize() const
{
    unsigned int max = 0;
    for (unsigned int i = 0; i < bucketNum; i++)
    {
        
        Node* n = nodeArray[i];
        int count = 0;
        while(n != nullptr)
        {
            count = count + 1;
            n = n->next;
        }
        if (count > max)
        {
            max = count;
        }
    }
    return max;
}

void HashMap::clearArray()
{
    initializeNullArray(nodeArray, bucketNum);
    bucketNum = INITIAL_BUCKET_COUNT;
}


//linked list functions
//add node to linked list
HashMap::Node* HashMap::getNode(const std::string& key, const std::string& value)
{
    Node* newNode = new Node;

    newNode->key = key;
    newNode->value = value;
    newNode->next = nullptr;

    return newNode;
}

void HashMap::addNext(Node*& n, const std::string& key, const std::string& value)
{
    if (n == nullptr)
    {
       //Node* node = getNode(key, value);
        Node* newNode = new Node;

        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;
        n = newNode;   
    }
    else
    {
        addNext(n->next, key, value);
    }
}

void HashMap::add(const std::string& key, const std::string& value)
{

    //rehash if necessary
    double addLoadFactor = double(sz+1)/(double)bucketNum;
    if (addLoadFactor > MAX_LOAD_FACTOR)
    {
        rehash();
    }

    int index = getIndex(key);

    //addNode(key,value,index);
    if (contains(key) == false)
    {
        if (nodeArray[index] == nullptr)
        {
            nodeArray[index] = getNode(key, value);
        }
        else
        {
            addNext(nodeArray[index]->next, key, value);
        }
    }
    sz++;

}

bool HashMap::contains(const std::string& key) const
{
    //locate bucket using index, then iterate through nodes of linkedlist 
    bool b = false;
    int index = getIndex(key);
    
    HashMap::Node* current = nodeArray[index];
    while (current != nullptr)
    {
        if (current->key == key) {
            b = true;
        }
        current = current->next;
    }
    delete current;
    return b;
}

std::string HashMap::value(const std::string& key) const
{
    //locate bucket using index, then iterate through nodes of 
    //linkedlist and return value of matching key
    std::string retval;
    int index = getIndex(key);

    HashMap::Node* current = nodeArray[index];
    while (current != nullptr)
    {
        if (current->key == key) {
            retval = current->value;
        }
        current = current->next;
    }

    return retval;

}

bool HashMap::remove(const std::string& key){
    //determine if nodeArray contains the key.
    //if target key is not at the end, assign key and value to the next node's key and value.
    
    if (contains(key))
    {
        int index = getIndex(key);
        Node* temp = nodeArray[index]; //start of bucket
        Node* current = temp;
        while (temp != nullptr)
        {
            if (temp->key == key) //if head node
            {

                if (current->key == key) 
                {
                    nodeArray[index] = current->next; //set it as next node
                    delete current; //delete pointer to previous node
                }
                else
                {
                    current->next = temp->next; //set previous node equal to node after node to be removed
                    delete temp;
                }
                break;
            }
            else
            {
                //if key not found yet, increment nodes in linked list
                current = temp;
                temp = temp->next;
            }
        }
        sz--;
        return true;

    }
    else
    {
        return false;
    }
  
}

void HashMap::rehash()
{
    int cap = bucketNum;
    Node** temp = nodeArray;

    //make array with larger capacity and change bucketNum member variable
    nodeArray = new Node*[2*bucketNum+1];
    bucketNum = (bucketNum*2) + 1;
    initializeNullArray(nodeArray, bucketNum);

    for (int i = 0; i < cap; i++)
    {
        Node* current = temp[i];
        while(current != nullptr)
        {
            add(current->key, current->value);
            sz--; //subtract size because add function adds size
            current = current->next;
        }
    }

    for (int i = 0; i < cap; i++)
    {
        deleteNodes(temp[i]);
    }
    delete[] temp;

}