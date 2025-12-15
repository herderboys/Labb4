// Alexander Herder

//  Trad.h
//  labb4_tree


#ifndef TRAD_H
#define TRAD_H

#include <iostream>

template <typename T>
class Trad
{
public:
    // default constructor
    Trad() : root(nullptr)
    {
    }

    // constructor with initialized data
    Trad(T data)
    {
        root = new Node(data);
    }

    // copy constructor
    Trad(const Trad& tree)
    {
        copy(tree);
    }

    // destructor
    ~Trad()
    {
        delete root;
    }


    // empty check
    bool empty() const
    {
        return !root;
    }

    // check what data root has
    T& value() const
    {
        check();
        return root->data;
    }


    // check which left children root has
    Trad& l_children() const
    {
        check();
        return *root->left;
    }

    // check which right children root has
    Trad& r_children() const
    {
        check();
        return *root->right;
    }


    // public insertion method
    void satt_in(T data)
    {
        insert(data);
    }

    // assignment operator
    Trad& operator=(const Trad& other)
    {
        // std::cout << "*** Trad::operator=\n";
        if (root != other.root)
        {
            delete root;
            copy(other);
        }
        return *this;
    }

    // equals operator
    bool operator==(const Trad& t) const
    {
        // std::cout << "*** Trad::operator==\n";
        return (empty() && t.empty()) ||
        (!empty() && !t.empty() && value() == t.value() &&
            l_children() == t.l_children() && r_children() == t.r_children());
    }


    // print out method
    void skriv_ut() const
    {
        // traversera igenom trädet rekursivt enligt principen "in-order"
        if (!empty())
        {
            l_children().skriv_ut();
            std::cout << value() << ' ';
            r_children().skriv_ut();
        }
    }


    // public search function
    T sok(T value)
    {
        return search(value);
    }

private:
    class Node
    {
        friend class Trad;
        T data;
        Trad *left, *right;


        // node constructor
        Node(T data) : data(data), left(new Trad), right(new Trad)
        {
        }

        // node destructor
        ~Node()
        {
            delete left;
            delete right;
        }
    }; // end class Nod


    Node* root;


    // private insertion function
    void insert(T data)
    {
        if (empty())
        {
            root = new Node(data);
            return;
        }

        // if (data == value())

        //     do nothing

        if (data < value())
        {
            l_children().insert(data);
        }
        if (data > value())
        {
            r_children().insert(data);
        }
    }


    // private search function
    T search(T target)
    {
        if (empty())
        {
            return 0;
        }
        if (value() == target)
        {
            return target;
        }
        if (value() > target)
        {
            return l_children().search(target);
        }
        return r_children().search(target);
    }


    // check if tree is empty
    void check() const
    {
        if (empty())
            throw std::range_error("Trad");
    }

    // copy method
    void copy(const Trad& t)
    {
        // std::cout << "*** Trad::kopiera\n";
        if (t.empty())
            root = 0;
        else
        {
            root = new Node(t.value());
            l_children().copy(t.l_children());
            r_children().copy(t.r_children());
        }
    }
};

#endif /* Trad_h */
