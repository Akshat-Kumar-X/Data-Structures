22BCE0472 >> First: {'S': {'a', 'b'}, 'A': {'a', 'b'}, 'B': {'a', 'b'}, 'a': set(), 'b': set()}
22BCE0472 >> Follow: {'S': {'$', 'a', 'b'}, 'A': {'$', 'a', 'b'}, 'B': {'$', 'a', 'b'}}
22BCE0472 >> Last: {'S': {'a', 'b'}, 'A': {'a', 'b'}, 'B': {'a', 'b'}}

22BCE0472 >>  State     Input     Next State
22BCE0472 >> ------------------------------
22BCE0472 >>    q0        a         q1        
22BCE0472 >>    q0        b         q2        
22BCE0472 >>    q1        a         q1        
22BCE0472 >>    q1        b         q2        
22BCE0472 >>    q2        b         q2        
22BCE0472 >>    q2        a         q1        

22BCE0472 >> DFA Acceptance Results: {'a': True, 'aa': True, 'ab': False, 'ba': True, 'bb': False, 'bba': True}