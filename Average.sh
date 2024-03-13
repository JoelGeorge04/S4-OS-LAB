 echo "Enter a Limit";
read n;
i=0;
while((i<=n))
do
	((sum=sum+i))
	((i=i+1))
done
((avg=sum/n))
echo "sum=$sum"
echo "Average=$avg"
