while((ch!=5))
do
echo "Enter your choice"
echo "1.Area of circle echo "
echo "2.Cirumfreance of circle" 
echo "3.Area of rectangle" 
echo "4.Area of square"
echo "5.exit"
read ch
case $ch in 
	 1)
	 echo "Enter Radius"
		  read radius
		  ((red=22/7*$radius*$radius))
		  echo "Area =$red "
		  ;;
	2)
	 echo "Enter radius"
		read radius
		((per=2*(22/7)*$radius))
		echo "Perimeter =$per"
		;;
	3)
	 echo "Enter length and breadth"
		  read length
		  read breadth
		  ((are=$length*$breadth))
		  echo "Area =$are "
		  ;;
	4)
	 echo "Enter side"
		read side
		((area=$side*$side))
		echo "Area =$area"
		;;
	*)
	echo "Error"
	;;
esac	
done

