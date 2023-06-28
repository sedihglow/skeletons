#!/bin/bash

simple_optional()
{
	echo "Arguments passed to simple_optional()"
	echo "---> $@"

	while getopts "a:b::" opt; do
	  case "$opt" in
		a) 
			echo "IN A BLOCK - "
			echo $OPTARG
			;;

		b) 
			echo "IN B BLOCK - "
			echo $OPTARG
			;;
		:)
			echo "Option -$OPTARG requires an argument"
			;;
			
		\?)
			echo "Hit ?, Error of some sorts"
			;;
	  esac
	done

	shift $((OPTIND - 1))

	while [[ $# -gt 0 ]]; do
		remaining_args+=("$1")
		shift
	done

    # Iterate over the remaining arguments
	echo 'Remaining arguments:'
    for arg in "${remaining_args[@]}"; do
        echo "--> '$arg'"
    done

	OPTIND=1
}

simple_no_optional()
{
	while getopts "a:b:" opt; do
	  case "$opt" in
		a) 
			echo "IN A BLOCK - "
			echo $OPTARG
			;;

		b) 
			echo "IN B BLOCK - "
			echo $OPTARG
			;;
	  esac
	done

	echo 'Remaining arguments:'
	for arg; do
		echo "--> '$arg'"
	done
}

if [ $? -ne 0 ]; then
	echo 'Terminating...' >&2
	exit 1
fi

echo "---- simp call ----"
simple_optional $@

: << 'COMMENT'
echo "\n---- GLOBAL CODE EXEC ----"
while getopts "a:b::" opt; do
  case "$opt" in
	a) 
		echo "IN A BLOCK - "
		echo $OPTARG
		;;

	b) 
		echo "IN B BLOCK - "
		echo $OPTARG
		;;
  esac
done

echo '--- arguments before if statement ---'
echo "$arg"

echo 'Remaining arguments:'
for arg; do
	echo "--> '$arg'"
done
COMMENT
