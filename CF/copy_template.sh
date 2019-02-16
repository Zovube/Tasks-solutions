
mkdir rounds/$1
for dir in A B C D E F G H I J K L M
do
	mkdir rounds/$1/$dir
	scp templateDir/* rounds/$1/$dir
done

