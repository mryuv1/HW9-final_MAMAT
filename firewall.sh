
#!/bin/bash	


filtered=$(cat "$1"  | grep -E -o '^(([^#]))*' | tr -d ' ')  

final=""

for line in $filtered; do
	
	#rulles=$(echo "$line" | sed -e 's/,/ /');
	#echo "$line";
	one=$(sed 's/,/ /'<<<$line)
	two=$(sed 's/,/ /'<<<$one)
	three=$(sed 's/,/ /'<<<$two)

	read -a fields <<< $three
	

	
	while read pack; do
		
		#echo $pack;
		final+=`echo -e "$pack" | ./firewall.exe  "${fields[0]}" 2>/dev/null | \
			./firewall.exe  "${fields[1]}" 2>/dev/null | ./firewall.exe  "${fields[2]}"  2>/dev/null | \
			./firewall.exe  "${fields[3]}" 2>/dev/null `
		#check+="\n"
		#check=`echo -e "$check" | uniq -c `
		#check+=`echo -e "$pack" | ./firewall.exe  "${fields[1]}"  2>/dev/null`
		#check+="\n"
		#check=`echo -e "$check" | uniq -c `
		#echo -e "$check" | uniq -c 
		#check+=`echo -e "$pack" | ./firewall.exe  "${fields[2]}"  2>/dev/null`
		#check+="\n"
		#check=`echo -e "$check" | uniq -c `
		#echo -e "$check" | uniq -c 
		#check+=`echo -e "$pack" | ./firewall.exe  "${fields[3]}"  2>/dev/null`
		#check+="\n"
		#check=`echo -e "$check" | uniq -c `
		#echo "${fields[1]}"
		#echo "${fields[2]}"
		#echo "${fields[3]}"
		#final+=`echo -e "$check"` #`echo -e "$check" | uniq -c | grep -E  '(      4 )' | sed 's/4//' | tr -d ' '`
		final+="\n"
	done< "$2"
	#while IFS= read -r line;
	#echo $pack	
	#all=""
	#	for rull in $three;do
			
	#		all+=$(./firewall.exe "$rull" < $pack );
			#all+=$(echo -e '\n');
			#all+="\n";
	#		all+=$(echo -e '\v');
			
	##	done;	
	#echo "$all" | uniq -c
	
	#done<test3-pkts.in
done

echo -ne $final | tr -d ' ' | sed '/^$/d' | sort

#while IFS= read -r line;
#do
#	read -a rulles <<< "$line"
	
#	echo ${rulles[1]}

	#read -a fields <<< "$line"
	#fullpack+=echo "./firewall.exe ${fields[0]} < test2-pkts.in"
	#fullpack+=$("./firewall.exe ${fields[1]}")
	#fullpack+=$("./firewall.exe ${fields[2]}")
	#fullpack+=$("./firewall.exe ${fields[2]}")

#done<fields

