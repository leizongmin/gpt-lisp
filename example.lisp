# Atom
a
x
hello

# List
(a b c)
(x y z)
((a) (b) (c))
(a (b) c)

# Nested list
(a (b (c d) e) f)
((a) (b (c (d e))))

# Quoted list
'(a b c)

# Empty list
()

# Invalid input
(a b )
a ( b c
() )

# Arithmetic
(+ 1 2)
(- 10 5)
(* 2 3)
(/ 15 3)

# Conditional
(if (> 3 2) a b)
(if (< 3 2) a b)

# Recursive
(fac 5)  ; 120
(fac 3)   ; 6
(define (fac n)
    (if (= n 1)
        1
        (* n (fac (- n 1)))))

# Lambda expression
((lambda (x) (+ x 1)) 2) ; 3