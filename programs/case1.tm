; This example program checks if the input string is in the form of $a_{i}b_{j}a_{i}b_{j}$
; Input: a string of a's and b's, e.g. 'abbabb'

; the finite set of states
#Q = {s0,accept,accept2,accept3,accept4,halt_accept,reject,reject2,reject3,reject4,reject5,halt_reject}

; the finite set of input symbols
#S = {a,b}

; the complete set of tape symbols
#G = {a,b,_,t,r,u,e,f,a,l,s}

; the start state
#q0 = s0

; the blank symbol
#B = _

; the set of final states
#F = {halt_accept}

; the number of tapes
#N = 2

; the transition functions

; State s0: start state
s0 a_ a_ ** mv_a
s0 b_ b_ ** reject
s0 __ __ ** reject ; the empty input should be rejected

; State mv_a: move a's in the beginning to the 2nd tape
mv_a a_ _a rr mv_a
mv_a b_ b_ ** mv_b

; State mv_b: move b's in the first half of the string to the 2nd tape
mv_b b_ _b rr mv_b
mv_b a_ __ rr reject

; State cmp: compare strings on two tapes
cmp aa __ rr cmp
cmp bb __ rr cmp
cmp ab __ ** reject todo
cmp ba __ ** reject todo
cmp __ __ ** accept

; State accept*: write 'true' on 1st tape
accept __ t_ r* accept2
accept2 __ r_ r* accept3
accept3 __ u_ r* accept4
accept4 __ e_ ** halt_accept

; State reject*: write 'false' on 1st tape
reject __ f_ r* reject2 todo
reject2 __ a_ r* reject3
reject3 __ l_ r* reject4
reject4 __ s_ r* reject5
reject5 __ e_ ** halt_reject
