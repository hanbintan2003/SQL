#ifndef PAIR_H
#define PAIR_H
#include <iostream>
using namespace std;

template <typename K, typename V>
struct Pair{
    K key;
    V value;

    Pair(const K& k = K(), const V& v = V()): key(k), value(v){}
    friend std::ostream& operator<<(std::ostream& outs, const Pair<K, V>& print_me){
        outs << print_me.key << ":" << print_me.value << endl;
        return outs;
    }
    friend bool operator==(const Pair<K, V>& lhs, const Pair<K, V>& rhs) { return lhs.key == rhs.key; }
    friend bool operator<(const Pair<K, V>& lhs, const Pair<K, V>& rhs) { return lhs.key < rhs.key; }
    friend bool operator>(const Pair<K, V>& lhs, const Pair<K, V>& rhs) { return lhs.key > rhs.key; }
    friend bool operator<=(const Pair<K, V>& lhs, const Pair<K, V>& rhs) { return lhs.key <= rhs.key; }
    friend Pair<K, V> operator+(const Pair<K, V>& lhs, const Pair<K, V>& rhs){
        K temp_key = lhs.key + rhs.key;
        V temp_val = lhs.value + rhs.value;
        Pair<K, V> pair(temp_key, temp_val);
        return pair;
    }
};

#endif // PAIR_H