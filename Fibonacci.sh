echo "Enter a Limit";
read n;
a=0;
b=1;
echo "Series =>"
echo "$a"
echo "$b"
for((i=2;i<n;i=i+1))
do
	((c=a+b));
	echo "$c"
	((a=b));
	((b=c));
done