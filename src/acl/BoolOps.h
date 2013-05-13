#ifndef SQUID_ACL_LOGIC_H
#define SQUID_ACL_LOGIC_H

#include "acl/InnerNode.h"

/* ACLs defined here are used internally to construct an ACL expression tree.
 * They cannot be specified directly in squid.conf because squid.conf ACLs are
 * more complex than (and are implemented using) these operator-like classes.*/

namespace Acl {

/// Implements the "not" or "!" operator.
class NotNode: public InnerNode
{
public:
    MEMPROXY_CLASS(NotNode);

    explicit NotNode(ACL *acl);

private:
    /* ACL API */
    virtual char const *typeString() const;
    virtual ACL *clone() const;
    virtual void parse();
    virtual wordlist *dump() const;

    /* Acl::InnerNode API */
    virtual int doMatch(ACLChecklist *checklist, Nodes::const_iterator start) const;
};
MEMPROXY_CLASS_INLINE(Acl::NotNode);


/// An inner ACL expression tree node representing a boolean conjuction (AND)
/// operator applied to a list of child tree nodes.
/// For example, conditions expressed on a single http_access line are ORed.
class AndNode: public InnerNode
{
public:
    MEMPROXY_CLASS(AndNode);

    /* ACL API */
    virtual char const *typeString() const;
    virtual ACL *clone() const;
    virtual void parse();

private:
    virtual int doMatch(ACLChecklist *checklist, Nodes::const_iterator start) const;
};
MEMPROXY_CLASS_INLINE(Acl::AndNode);

/// An inner ACL expression tree node representing a boolean disjuction (OR)
/// operator applied to a list of child tree nodes.
/// For example, conditions expressed by multiple http_access lines are ORed.
class OrNode: public InnerNode
{
public:
    MEMPROXY_CLASS(OrNode);

    /* ACL API */
    virtual char const *typeString() const;
    virtual ACL *clone() const;
    virtual void parse();

protected:
    mutable Nodes::const_iterator lastMatch_;

private:
    virtual int doMatch(ACLChecklist *checklist, Nodes::const_iterator start) const;
};
MEMPROXY_CLASS_INLINE(Acl::OrNode);


} // namespace Acl

#endif /* SQUID_ACL_LOGIC_H */
