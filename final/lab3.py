from __future__ import annotations

from dataclasses import dataclass
from typing import Any, Callable, Dict, Generic, Iterable, Optional, Tuple, TypeVar


A = TypeVar("A")
B = TypeVar("B")
C = TypeVar("C")


# ============================================================
# 10-Question Consolidated Lab (Challenge)
# Sources: lab.py, linked_list_lambda_merge_sort.py, curry_howard_challenge.py
# ============================================================


# Q1
ChurchBool = Callable[[Any], Callable[[Any], Any]]


def church_true(x: Any) -> Callable[[Any], Any]:
    return lambda y: x


def church_false(x: Any) -> Callable[[Any], Any]:
    return lambda y: y


def church_not(b: ChurchBool) -> ChurchBool:
    """Q1: Implement Church boolean negation."""
    return lambda x: lambda y: b(y)(x)


def from_church_bool(b: ChurchBool) -> bool:
    return b(True)(False)


# Q2
def compose(f: Callable[[B], C], g: Callable[..., B]) -> Callable[..., C]:
    """Q2: Implement variadic composition: f(g(*args, **kwargs))."""
    return lambda *args, **kwargs: f(g(*args, **kwargs))


# Q3
def map_recursive(fn: Callable[[A], B], xs: list[A]) -> list[B]:
    """Q3: Implement recursive map without loops."""
    if xs == []:
        return []
    return [fn(xs[0])] + map_recursive(fn, xs[1:])


# Q4
def fix(f: Callable[[Callable[..., Any]], Callable[..., Any]]) -> Callable[..., Any]:
    """Q4: Implement eager fixed-point combinator (Z-style)."""
    return f(lambda *args: fix(f)(*args))


# Q5
class Type:
    pass


@dataclass(frozen=True)
class TInt(Type):
    pass


@dataclass(frozen=True)
class TBool(Type):
    pass


@dataclass(frozen=True)
class TFun(Type):
    arg: Type
    ret: Type


class Expr:
    pass


@dataclass(frozen=True)
class Var(Expr):
    name: str


@dataclass(frozen=True)
class Lam(Expr):
    param: str
    param_type: Type
    body: Expr


@dataclass(frozen=True)
class App(Expr):
    fn: Expr
    arg: Expr


@dataclass(frozen=True)
class IntLit(Expr):
    value: int


@dataclass(frozen=True)
class BoolLit(Expr):
    value: bool


@dataclass(frozen=True)
class If(Expr):
    cond: Expr
    then_branch: Expr
    else_branch: Expr


@dataclass(frozen=True)
class Add(Expr):
    left: Expr
    right: Expr


@dataclass(frozen=True)
class Sub(Expr):
    left: Expr
    right: Expr


@dataclass(frozen=True)
class Mod(Expr):
    left: Expr
    right: Expr


@dataclass(frozen=True)
class IsZero(Expr):
    value: Expr


TypeEnv = Dict[str, Type]


def type_of(expr: Expr, env: TypeEnv | None = None) -> Type:
    """Q5: Implement type checker for Expr including Add/Sub/Mod/IsZero."""
    if env is None:
        env = {}

    if isinstance(expr, IntLit):
        return TInt()

    if isinstance(expr, BoolLit):
        return TBool()

    if isinstance(expr, Var):
        if expr.name not in env:
            raise TypeError(f"Unbound variable: {expr.name}")
        return env[expr.name]

    if isinstance(expr, Lam):
        new_env = {**env, expr.param: expr.param_type}
        ret_type = type_of(expr.body, new_env)
        return TFun(expr.param_type, ret_type)

    if isinstance(expr, App):
        fn_type = type_of(expr.fn, env)
        arg_type = type_of(expr.arg, env)
        if not isinstance(fn_type, TFun):
            raise TypeError(f"Expected function type, got {fn_type}")
        if fn_type.arg != arg_type:
            raise TypeError(f"Argument type mismatch: expected {fn_type.arg}, got {arg_type}")
        return fn_type.ret

    if isinstance(expr, If):
        cond_type = type_of(expr.cond, env)
        if not isinstance(cond_type, TBool):
            raise TypeError(f"Condition must be Bool, got {cond_type}")
        then_type = type_of(expr.then_branch, env)
        else_type = type_of(expr.else_branch, env)
        if then_type != else_type:
            raise TypeError(f"Branch type mismatch: {then_type} vs {else_type}")
        return then_type

    if isinstance(expr, (Add, Sub, Mod)):
        left_type = type_of(expr.left, env)
        right_type = type_of(expr.right, env)
        if not isinstance(left_type, TInt):
            raise TypeError(f"Expected Int, got {left_type}")
        if not isinstance(right_type, TInt):
            raise TypeError(f"Expected Int, got {right_type}")
        return TInt()

    if isinstance(expr, IsZero):
        val_type = type_of(expr.value, env)
        if not isinstance(val_type, TInt):
            raise TypeError(f"Expected Int, got {val_type}")
        return TBool()

    raise TypeError(f"Unknown expression: {expr}")


# Q6 + Q7
@dataclass
class Node:
    value: int
    next: Node | None = None


def ll_from_iterable(values: Iterable[int]) -> Node | None:
    head: Node | None = None
    tail: Node | None = None
    for v in values:
        n = Node(v)
        if head is None:
            head = n
            tail = n
        else:
            tail.next = n
            tail = n
    return head


def ll_to_list(head: Node | None) -> list[int]:
    out: list[int] = []
    cur = head
    while cur is not None:
        out.append(cur.value)
        cur = cur.next
    return out


def merge_sorted_lists(a: Node | None, b: Node | None) -> Node | None:
    """Q6: Merge two already sorted linked lists."""
    if a is None:
        return b
    if b is None:
        return a
    if a.value <= b.value:
        a.next = merge_sorted_lists(a.next, b)
        return a
    else:
        b.next = merge_sorted_lists(a, b.next)
        return b


def merge_sort_linked(head: Node | None) -> Node | None:
    """Q7: Implement linked-list merge sort."""
    if head is None or head.next is None:
        return head

    slow = head
    fast = head.next
    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next

    mid = slow.next
    slow.next = None

    left = merge_sort_linked(head)
    right = merge_sort_linked(mid)

    return merge_sorted_lists(left, right)


# Q8 + Q9
@dataclass(frozen=True)
class Tree(Generic[A]):
    value: A
    left: Optional[Tree[A]] = None
    right: Optional[Tree[A]] = None


def foldl(fn: Callable[[B, A], B], init: B, xs: Iterable[A]) -> B:
    """Q8: Implement left fold for iterables."""
    acc = init
    for x in xs:
        acc = fn(acc, x)
    return acc


def fold_tree(leaf: B, node_fn: Callable[[A, B, B], B], t: Optional[Tree[A]]) -> B:
    """Q9: Implement structural fold over binary tree."""
    if t is None:
        return leaf
    left_result = fold_tree(leaf, node_fn, t.left)
    right_result = fold_tree(leaf, node_fn, t.right)
    return node_fn(t.value, left_result, right_result)


# Q10
def q5_curry(h: Callable[[Tuple[A, B]], C]) -> Callable[[A], Callable[[B], C]]:
    """Q10: Implement Curry-Howard currying: ((A,B)->C) -> A -> B -> C."""
    return lambda a: lambda b: h((a, b))