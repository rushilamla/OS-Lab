echo "Enter name:"
read file
if [ -f $file ]
then
echo "This is a file"
elif [ -d $file ]
then
echo "This is a directory"
else
echo "This is neither file nor directory"
fi
