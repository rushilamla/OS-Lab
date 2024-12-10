echo "Enter filename:"
read f
echo "enter word:"
read w
echo "File before deleting wrord:"
cat $f
grep -vi $w $f> temp.txt
mv temp.txt $f
echo "File after deleting word:"
cat $f
