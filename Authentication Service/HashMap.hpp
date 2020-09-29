// HashMap.hpp
//
// ICS 45C Spring 2020
// Project #3: Maps and Legends
//
// This header file contains a declaration for a "well-behaved" HashMap
// class, which is a separately-chained hash table implementation of a
// map/dictionary data structure (i.e., a collection of key/value pairs),
// where the keys and values are strings.
//
// This HashMap consists of a dynamically-allocated array of "buckets,"
// each of which is a pointer to the first node in a linked list of
// key/value pairs that have hashed to that bucket.
//
// You may not make changes to the public members of this class the way
// they're declared now, since we will be running unit tests against
// your class that will expect these declarations not to have changed
// (and that its member functions are implemented as specified in the
// comments below).  However, you are free to add whatever additional
// members you feel are necessary, including new member variables or
// member functions (public or private).

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <functional>
#include <string>



class HashMap
{
public:
    // type alias for hash function
    using HashFunction = std::function<unsigned int(const std::string&)>;

    static constexpr unsigned int INITIAL_BUCKET_COUNT = 10;
    static constexpr double MAX_LOAD_FACTOR = 0.80;


public:
    // This constructor initializes the HashMap to use whatever default
    // hash function you'd like it to use.  A little research online will
    // yield some good ideas about how to write a good hash function for
    // strings; don't just return zero or, say, the length of the string.
    HashMap();

    // This constructor instead initializes the HashMap to use a particular
    // hash function instead of the default.  (We'll use this in our unit
    // tests to control the scenarios more carefully.)
    HashMap(HashFunction hashFunction);

    // The "Big Three" need to be implemented appropriately, so that HashMaps
    // can be created, destroyed, copied, and assigned without leaking
    // resources, interfering with one another, or causing crashes or
    // undefined behavior.
    HashMap(const HashMap& hm);
    ~HashMap();
    HashMap& operator=(const HashMap& hm);

    // add() takes a key and a value.  If the key is not already stored in
    // this HashMap, the key/value pair is added; if the key is already
    // stored, the function has no effect.
    //
    // If adding the new key/value pair will cause the load factor of this
    // HashMap to exceed 0.8, the number of buckets increases and the pairs
    // are rehashed

    void add(const std::string& key, const std::string& value);

    //not sure where to put:
    void addNode(const std::string& key, const std::string& value, int index);

    void rehash();

    // remove() takes a key and removes it (and its associated value) from
    // this HashMap if it is already present; if not, nothing is changed.
    // The function returns true if the key was removed, false if nothing
    // was removed.
    bool remove(const std::string& key);

    unsigned int getIndex(const std::string key) const;

    // contains() returns true if the given key is in this HashMap, false
    // if not.
    bool contains(const std::string& key) const;

    // value() returns the value associated with the given key in this HashMap
    // if the key is stored in this HashMap; if not, the empty string is
    // returned.
    std::string value(const std::string& key) const;

    // size() returns the number of key/value pairs stored in this HashMap.
    unsigned int size() const;

    // bucketCount() returns the number of buckets currently allocated in
    // this HashMap.
    unsigned int bucketCount() const;

    // loadFactor() returns the proportion of the number of key/value pairs
    // to the number of buckets, a measurement of how "full" the HashMap is.
    // For example, if there are 20 key/value pairs and 50 buckets, we would
    // say that the load factor is 20/50 = 0.4.
    double loadFactor() const;

    // maxBucketSize() returns the number of key/value pairs stored in this
    // HashMap's largest bucket.
    unsigned int maxBucketSize() const;

    void clearArray();




private:
    // This structure describes the nodes that make up the linked lists in
    // each of this HashMap's buckets.
    struct Node
    {
        std::string key;
        std::string value;
        Node* next;
    };

    int sz; //number of key value pairs
    int bucketNum; //capacity of HashMap
    Node** nodeArray;

    //creates a new node
    Node* getNode(const std::string& key, const std::string& value);

    //recursively adds the key/value pair to the next node if the current one is not null
    void addNext(Node*& n, const std::string& key, const std::string& value);
    
    //initializeNullArray() initializes all the buckets in the array to nullptrs
    void initializeNullArray(Node** nodeArray, int bucketNum);
    void arrayCopy(Node** target, Node** source, unsigned int size);
    void deleteNodes(Node* n);

    HashFunction hashFunction;
};



#endif // HASHMAP_HPP

