echo "enter filename:"
read f
echo "enter starting line"
read s
echo "enter ending line"
read e
sed -n $s,$e\p $f

