//!Header Files

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// Including tree_order_statistics_node_update

using namespace __gnu_pbds;

// Declaration of tree-based container
template<
    // Key type
    typename Key,

    //Mapped - policy
    typename Mapped,

    // Key comparision functor
    typename Cmp_Fn = std::less<Key>,

    // Specifies which underlying data structure to use
    typename Tag = rb_tree_tag,

    template <
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_ >
    
    // A Policy for updating node invariants
    class Node_Update = null_node_update,

    // An allocator type
    typename Allocator = std::allocator<char> >

class Tree;

// !Declaration of policy type data structure
typedef Tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 

/*
    Tree Structures
    rb_tree_tag (Red - black tree)
    splay_tree_tag (splay tree)
    ov_tree_tag (ordered - vector tree)
*/

/*
    Settings in Ubuntu

    Settings in Windoes


*/
