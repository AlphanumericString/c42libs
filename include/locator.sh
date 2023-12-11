#!/bin/zsh

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

	awk \
	'{
		if ( /^[a-zA-Z]/ && !/^static/ )
		{
			line = $0
			while ( !/)$/ )
			{
				line =  line "\n"
				getline
				line =  line $0
			}
			print $line ";"
		}
	}' $1 >> $2
}

echo -e "\n" >> $output_file
echo -e "#ifndef $output_file\n# define $output_file\n" >> $output_file

# Loop through all C files in the specified directory
for file in $(find $search_dir -depth -name "*.c" | sort ); do
    echo -e "// $file\n" >> "$output_file"
	extract_functions $file "$output_file"
    # Add an empty line between files
    echo -e "\n" >> "$output_file"
done

echo -e "#endif /* $output_file */" >> $output_file

echo "Header file generated: $output_file"



#ifndef test.h
# define test.h

