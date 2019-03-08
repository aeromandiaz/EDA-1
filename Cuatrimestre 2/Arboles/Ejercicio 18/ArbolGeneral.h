//
//  ArbolGeneral.h
//  ProblemasEDA
//
//  Created by Mauri on 08/03/2019.
//  Copyright © 2019 Mauri. All rights reserved.
//

#ifndef ArbolGeneral_h
#define ArbolGeneral_h

#include <memory>
#include <vector>

template<class T>
class gTree {
protected:
    
    struct TreeNode;
    
    using Link = std::shared_ptr<TreeNode>;
    
    struct TreeNode {
        T elem;
        std::vector<Link> st;
        TreeNode (T const &e): elem(e) {};
        TreeNode(const T &e, std::vector<Link> v): elem(e), st(v) {};
    };
    
    Link raiz;
    
    gTree(Link const& r): raiz(r) {}
    
public:
    
    gTree(T const &e): raiz(std::make_shared<TreeNode>(e)){}
    
    gTree(T const &e, std::vector<gTree<T>> const &r): raiz(std::make_shared<TreeNode>(e)) {
        for (int i = 0; i < r.size(); ++i)
            raiz->st.push_back(r[i].raiz);
    }
    
    bool empty() const {
        return raiz->st.empty();
    }
    
    T const& root() const {
        return raiz->elem;
    }
    
    std::vector<gTree<T>> subtrees() const {
        std::vector<gTree<T>> gt;
        
        for (int i = 0; i < raiz->st.size(); ++i)
            gt.push_back(raiz.st[i]);
        
        return gt;
        
    }
    
};


#endif /* ArbolGeneral_h */
