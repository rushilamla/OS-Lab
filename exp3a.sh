echo "enter file:"
read file
if [ -f $file ]
then
tr '[a-z]' '[A-Z]' <$file >temp_file.txt
mv temp_file.txt $file
else
echo "file does not exist"
fi

