#Q = {q_1,q_rej,q_rej1,q_acc,q_acc1,q_a1,q_a2,q_2,q_b1,q_b2}

#S = {a,b}

#G = {a,b,_,T,F}

#q0 = q_1

#B = _

#F = {q_acc1}

#N = 1

q_1 _ _ r q_acc
q_1 a _ r q_a1
q_1 b _ r q_b1

q_a1 _ _ l q_a2
q_a1 a a r q_a1
q_a1 b b r q_a1

q_a2 _ _ r q_rej
q_a2 a _ l q_2
q_a2 b _ l q_rej

q_2 _ _ r q_1
q_2 a a l q_2
q_2 b b l q_2

q_b1 _ _ l q_b2
q_b1 a a r q_b1
q_b1 b b r q_b1

q_b2 _ _ r q_b2
q_b2 a _ l q_rej
q_b2 b _ l q_2

q_acc _ T r q_acc1

q_rej _ F r q_rej1
q_rej a _ l q_rej
q_rej b _ l q_rej