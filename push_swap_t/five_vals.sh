echo "entre -2 et 3"

#essayer toutes les possibilités (il y en a 5! = 120) !

#python : itertools.permutations([-2 -1 0 1 2], 5)

COMB=("-2 -1 0 1 2" "-2 -1 0 2 1" "-2 -1 1 0 2" "-2 -1 1 2 0" "-2 -1 2 0 1" "-2 -1 2 1 0" "-2 0 -1 1 2" "-2 0 -1 2 1" "-2 0 1 -1 2" "-2 0 1 2 -1" "-2 0 2 -1 1" "-2 0 2 1 -1" "-2 1 -1 0 2" "-2 1 -1 2 0" "-2 1 0 -1 2" "-2 1 0 2 -1" "-2 1 2 -1 0" "-2 1 2 0 -1" "-2 2 -1 0 1" "-2 2 -1 1 0" "-2 2 0 -1 1" "-2 2 0 1 -1" "-2 2 1 -1 0" "-2 2 1 0 -1" "-1 -2 0 1 2" "-1 -2 0 2 1" "-1 -2 1 0 2" "-1 -2 1 2 0" "-1 -2 2 0 1" "-1 -2 2 1 0" "-1 0 -2 1 2" "-1 0 -2 2 1" "-1 0 1 -2 2" "-1 0 1 2 -2" "-1 0 2 -2 1" "-1 0 2 1 -2" "-1 1 -2 0 2" "-1 1 -2 2 0" "-1 1 0 -2 2" "-1 1 0 2 -2" "-1 1 2 -2 0" "-1 1 2 0 -2" "-1 2 -2 0 1" "-1 2 -2 1 0" "-1 2 0 -2 1" "-1 2 0 1 -2" "-1 2 1 -2 0" "-1 2 1 0 -2" "0 -2 -1 1 2" "0 -2 -1 2 1" "0 -2 1 -1 2" "0 -2 1 2 -1" "0 -2 2 -1 1" "0 -2 2 1 -1" "0 -1 -2 1 2" "0 -1 -2 2 1" "0 -1 1 -2 2" "0 -1 1 2 -2" "0 -1 2 -2 1" "0 -1 2 1 -2" "0 1 -2 -1 2" "0 1 -2 2 -1" "0 1 -1 -2 2" "0 1 -1 2 -2" "0 1 2 -2 -1" "0 1 2 -1 -2" "0 2 -2 -1 1" "0 2 -2 1 -1" "0 2 -1 -2 1" "0 2 -1 1 -2" "0 2 1 -2 -1" "0 2 1 -1 -2" "1 -2 -1 0 2" "1 -2 -1 2 0" "1 -2 0 -1 2" "1 -2 0 2 -1" "1 -2 2 -1 0" "1 -2 2 0 -1" "1 -1 -2 0 2" "1 -1 -2 2 0" "1 -1 0 -2 2" "1 -1 0 2 -2" "1 -1 2 -2 0" "1 -1 2 0 -2" "1 0 -2 -1 2" "1 0 -2 2 -1" "1 0 -1 -2 2" "1 0 -1 2 -2" "1 0 2 -2 -1" "1 0 2 -1 -2" "1 2 -2 -1 0" "1 2 -2 0 -1" "1 2 -1 -2 0" "1 2 -1 0 -2" "1 2 0 -2 -1" "1 2 0 -1 -2" "2 -2 -1 0 1" "2 -2 -1 1 0" "2 -2 0 -1 1" "2 -2 0 1 -1" "2 -2 1 -1 0" "2 -2 1 0 -1" "2 -1 -2 0 1" "2 -1 -2 1 0" "2 -1 0 -2 1" "2 -1 0 1 -2" "2 -1 1 -2 0" "2 -1 1 0 -2" "2 0 -2 -1 1" "2 0 -2 1 -1" "2 0 -1 -2 1" "2 0 -1 1 -2" "2 0 1 -2 -1" "2 0 1 -1 -2" "2 1 -2 -1 0" "2 1 -2 0 -1" "2 1 -1 -2 0" "2 1 -1 0 -2" "2 1 0 -2 -1" "2 1 0 -1 -2")
I=0
while [ $I -le 120 ]; do
	echo ${COMB[$I]}
	./push_swap ${COMB[$I]} | ./checker ${COMB[$I]}
	./push_swap ${COMB[$I]} | wc -l;
	I=$((I+1));
done

#13-09
#il reste

#1 -2 2 -1 0
#1 -2 2 0 -1
#-2 2 1 -1 0
#-2 2 1 0 -1
