; This program checks if the input string is in the form of $a_{i}b_{j}a_{i}b_{j}$
; Input: a string of a's and b's, e.g., 'abbabb'

; the finite set of states
#Q = {s0,mv_a,mv_b,reset,cmp,accept,accept2,accept3,accept4,halt_accept,reject,reject2,reject3,reject4,reject5,halt_reject}

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
s0 a_ a_ ** mv_a   ; start moving half of the string
s0 b_ b_ ** reject ; the string starts with b, reject
s0 __ __ ** reject ; the empty input should be rejected

; State mv_a: move a's in the beginning to the 2nd tape
mv_a a_ _a rr mv_a   ; continue moving a
mv_a __ __ *l reject ; there's no b
mv_a b_ b_ ** mv_b   ; start moving b

; State mv_b: move b's in the first half of the string to the 2nd tape
mv_b b_ _b rr mv_b
mv_b a_ a_ *l reset
mv_b __ __ *l reject ; there's no a after b

; State reset: move the head of tape2 to the left end
reset a_ a_ *r cmp   ; start comparing the two strings
reset aa aa *l reset ; keep moving the head to the left
reset ab ab *l reset

; State cmp: compare strings on two tapes
cmp aa __ rr cmp
cmp bb __ rr cmp
cmp ab __ rr reject
cmp ba __ rr reject
cmp _a __ *r reject
cmp _b __ *r reject
cmp a_ __ r* reject
cmp b_ __ r* reject
cmp __ __ ** accept

; State accept*: write 'true' on 1st tape
accept __ t_ r* accept2
accept2 __ r_ r* accept3
accept3 __ u_ r* accept4
accept4 __ e_ ** halt_accept

; State reject*: write 'false' on 1st tape
reject a_ __ r* reject   ; clean the 1st tape
reject b_ __ r* reject
reject _a __ *r reject
reject _b __ *r reject
reject aa __ rr reject
reject ab __ rr reject
reject ba __ rr reject
reject bb __ rr reject
reject __ f_ r* reject2
reject2 __ a_ r* reject3
reject3 __ l_ r* reject4
reject4 __ s_ r* reject5
reject5 __ e_ ** halt_reject
