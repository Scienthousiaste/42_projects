echo "entre -8 et -3"

I=1;
while [ $I -le 10 ]; do
	ARG=`ruby -e "puts (-8..-4).to_a.shuffle.join(' ')"`;
	./push_swap $ARG | wc -l;
	I=$((I+1));
done

echo "entre -2 et 3"

I=1;
while [ $I -le 10 ]; do
	ARG=`ruby -e "puts (-2..2).to_a.shuffle.join(' ')"`;
	./push_swap $ARG | wc -l;
	I=$((I+1));
done

echo "entre -50 et 50"

I=1;
while [ $I -le 10 ]; do
	ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`;
	./push_swap $ARG | wc -l;
	I=$((I+1));
done

echo "entre -250 et 250"

I=1;
while [ $I -le 10 ]; do
	ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`;
	./push_swap $ARG | wc -l;
	I=$((I+1));
done

#avec 5 arguments, il faut 12 instructions max
#avec 100 arguments, il en faut 700 max
#avec 500 arguments, il en faut 5500 max
