while((ch!=6))
do
echo "Enter your choice"
echo "1.ADD "
echo "2.SUB" 
echo "3.MULTI" 
echo "4.DIV"
echo "5.MOD"
echo "6.Exit"
read ch
case $ch in 
	 1)
	 echo "Addition"
	 echo "Enter 2 numbers"
		  read a
		  read b
		  ((sum=$a+$b))
		  echo "Resut=$sum "
		  ;;
	2)
	  echo "Substraction"
	 echo "Enter 2 numbers"
		  read a
		  read b
		  ((sum=$a-$b))
		  echo "Resut=$sum "
		  ;;
	3)
	  echo "Multiplication"
	 echo "Enter 2 numbers"
		  read a
		  read b
		  ((sum=$a*$b))
		  echo "Resut=$sum "
		  ;;
	4)
	  echo "Division"
	 echo "Enter 2 numbers"
		  read a
		  read b
		  ((sum=$a+$b))
		  echo "Resut=$sum "
		  ;;
	 5)
	 echo "Modulus"
	 echo "Enter 2 numbers"
		  read a
		  read b
		  ((sum=$a%$b))
		  echo "Resut=$sum "
		  ;;
	*)
	echo "Error"
	;;
esac	
done