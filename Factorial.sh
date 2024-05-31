echo "Enter a limit";
read n;
a=1
for((i=1;i<=n;i=i+1))
do
	
	((a=a*i));
done
echo "Factorial = $a"
