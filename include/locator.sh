#!/bin/sh

#!/bin/bash

# Specify the directory to search for C files
search_dir=${1:-./src}

# Specify the output header file
output_file=${2:-output.h}

if [ -f "$output_file" ] ; then
	echo "override detected '$output_file' already exist."
	read -p "Do you want to proceed? [Y/n] " yn

	case $yn in 
		[nN] ) echo exiting...;
			exit 0 ;;
		* ) 
			echo "ok, we will proceed"
			rm -f $output_file ;;
	esac
fi

# Function to convert camel case to snake case
camel_to_snake() {
    echo "$1" | sed 's/\([a-z]\)\([A-Z]\)/\1_\2/g' | tr '[:upper:]' '[:lower:]'
}

extract_functions() {
    # Check if a file is provided
    if [ -z "$1" ]; then
        echo "Usage: extract_functions <filename>"
        return 1
    fi


	# check if the first char is a letter aka is this a function delc
	# then check if the last char is a ')' aka is this a one-liner
	#	print 
	# else 
	# 	print 2 lines
	awk '{
		if ( /^[a-zA-Z]/ && /)$/ )
		{
			print $0 ";"
		}
		else if ( /^[a-zA-Z]/ && !/)$/ )
		{
			print $0
			getline
			print $0 ";"
		}
	}' $1 >> $2
}

# Loop through all C files in the specified directory
for file in $(find $search_dir -depth -name "*.c" ); do

    echo -e "// $file\n" >> "$output_file"

	extract_functions $file "$output_file"
    
    # Add an empty line between files
    echo -e "\n" >> "$output_file"
done

echo "Header file generated: $output_file"
