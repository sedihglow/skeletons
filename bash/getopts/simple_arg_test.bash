#!/usr/bin/env bash

getopts_parse()
{
	echo "Arguments passed to getopts_parse()"
	echo "---> $@"

	while getopts "a:b::" opt; do
	  case "$opt" in
		a) 
			echo "IN A BLOCK - "
			arg_file=$OPTARG
			echo -e "optarg: $OPTARG\n"\
				 "\barg_file: $arg_file\n"\
				 "\bThird time through"
			;;

		b) 
			echo "IN B BLOCK - "
			echo $OPTARG
			;;
		:)
			echo "Option -$OPTARG requires an argument"
			;;
			
		\?)
			echo "Error: Invalid option passed: -$OPTARG"
			;;
	  esac
	done

	shift $((OPTIND - 1))

    # Iterate over the remaining arguments
	echo 'Remaining arguments:'
    for arg; do
        echo "--> '$arg'"
    done

	# Resetting OPTIND because it does not get reset when the function exits
	# and when getopts potentially gets called again outside of this function.
	OPTIND=1
}

if [ $? -ne 0 ]; then
	echo 'Terminating...' >&2
	exit 1
fi

getopts_parse $@

echo "\n---- START GLOBAL CODE EXEC ----"

echo "Arguments from \$@ after inside_function is called with \$@"
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
		echo "Error: Invalid option passed: -$OPTARG"
		;;
  esac
done

shift $((OPTIND - 1))

# Iterate over the remaining arguments
echo 'Remaining arguments:'
for arg; do
	echo "--> '$arg'"
done

OPTIND=1


# random notes and stuff prolly not tested or even real 

: << 'COMMENT' OPTIONAL ARG FOR OPTION R 
# No : after R
while getopts "hd:R" arg; do
  case $arg in
  (...)
  R)
    # Check next positional parameter
    eval nextopt=\${$OPTIND}
    # existing or starting with dash?
    if [[ -n $nextopt && $nextopt != -* ]] ; then
      OPTIND=$((OPTIND + 1))
      level=$nextopt
    else
      level=1
    fi
    ;;
  (...)
  esac
done
COMMENT

