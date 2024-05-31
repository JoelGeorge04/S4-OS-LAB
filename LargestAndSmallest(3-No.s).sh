echo "Enter 3 Numbers";
read a;
read b;
read c;
if((a>b))
then
	if((a>c))
	then
		largest=$a
	else 
		largest=$c;
	fi
else
	if((b>c))
	then
		largest=$b
	else
		largest=$c
	fi
fi
if((a<b))
then
	if((a<c))
	then
		smallest=$a
	fi
else
	if((b<c))
	then
		smallest=$b
	else
		smallest=$c
	fi
fi
echo "$largest is the greatest"
echo "$smallest is the smallest"
